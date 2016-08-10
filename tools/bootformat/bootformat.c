#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#include "secondboot.h"

#define U32 unsigned int
#define S32 int
#define U8 unsigned char
#define S8 char

// Nexell System Information Header
//------------------------------------------------------------------------------
S32 ProcessNSIH(const S8 *pfilename, U8 *pOutData)
{
	FILE  *fp;
	S8 ch;
	S32 writesize, skipline, line, bytesize, i;
	U32 writeval;

	printf("%s processing\r\n", pfilename);

	fp = fopen(pfilename, "rb");
	if (!fp) {
		printf("ProcessNSIH : ERROR - Failed to open %s file.\r\n",
				pfilename);
		return 0;
	}

	bytesize = 0;
	writeval = 0;
	writesize = 0;
	skipline = 0;
	line = 0;

	while (0 == feof(fp)) {
		ch = fgetc(fp);

		if (skipline == 0) {
			if (ch >= '0' && ch <= '9') {
				writeval = writeval * 16 + ch - '0';
				writesize += 4;
			}
			else if (ch >= 'a' && ch <= 'f') {
				writeval = writeval * 16 + ch - 'a' + 10;
				writesize += 4;
			}
			else if (ch >= 'A' && ch <= 'F') {
				writeval = writeval * 16 + ch - 'A' + 10;
				writesize += 4;
			}
			else {
				if (writesize == 8 ||
					writesize == 16 ||
					writesize == 32) {
					for (i = 0; i < writesize / 8; i++) {
						pOutData[bytesize++] =
							(U8)(writeval & 0xFF);
						writeval >>= 8;
					}
				}
				else {
					if (writesize != 0)
						printf("ProcessNSIH : Error at %d line.\r\n",
							line + 1);
				}

				writesize = 0;
				skipline = 1;
			}
		}

		if (ch == '\n') {
			line++;
			skipline = 0;
			writeval = 0;
		}
	}

	printf("ProcessNSIH : %d line processed.\r\n", line + 1);
	printf("ProcessNSIH : %d bytes generated.\r\n", bytesize);

	fclose(fp);

	return bytesize;
}

static U32 get_fcs(U32 fcs, U8 data)
{
	register S32 i;
	fcs ^= (U32)data;
	for (i = 0; i < 8; i++) {
		if (fcs & 0x01)
			fcs = (fcs >> 1) ^ POLY; 
		fcs >>= 1;
	}
	return fcs;
}


static inline U32 __calc_crc(void *addr, S32 len)
{
	U8 *c = (U8*)addr;
	U32 crc = 0;
	S32 i;
	for (i = 0; len > i; i++, c++) {
		crc = get_fcs(crc, *c);
	}
	return crc;
}

/* How to use Help */ 
static void usage(void)
{
	printf("\r\n  NXP5430 boot binary file Generater\r\n" );
	printf("  Usage:\r\n" );
	printf("   -h                       : show this message\r\n");
	printf("   -i [file name]           : [input ] binary file name\r\n");      //file format, default file name
	printf("   -o [file name]           : [output] boot file name\r\n");
	printf("   -n [file name]           : [NSIH  ] Text file name\r\n");      
	printf("   -f [bin format number]   : 0:USB, 1:SPI, 2:SDMMC, 3:UART\r\n");
	printf("\r\n"); 
	printf(" example: ");
	printf(" #>./bootformat -i 2ndboot.bin -o 2ndboot.bin.boot -n NSIH.txt -f 1\r\n" );
	printf("\r\n");
}

char *devicename[4]=
{
	"USB", "SPI", "SDMMC", "UART"
};

int main(int argc, char **argv)
{
	FILE *inFile_fd, *outFile_fd;
	unsigned char *input_name, *output_name, *nsih_name;

	unsigned int inputSize, outputSize, nsihSize;	/* file  size variables */
	unsigned int BinFileSize, SubFileSize, SrcReadSize;	/* etc variables */
	struct NX_SecondBootInfo *pSecondInfo;

	int gBinFormat, ret = 0;

	unsigned char *pdwSrcData, *pdwDstData, *nsihData;
	int param_opt, Calculate, i;

	/* Default Value */
	nsihSize = NSIHSIZE;
	gBinFormat = SPI;

	if (argc <= 1) {
		usage();
		return -1;
	}
	/* option for the loop */
	while (-1 != (param_opt = getopt(argc, argv, "hi:o:n:f:"))) {
		switch (param_opt) {
		case 'h':
			usage();
			return -1;
		case 'i':
			input_name = strdup(optarg);
			break;
		case 'o':
			output_name = strdup(optarg);
			break;
		case 'n':
			nsih_name = strdup(optarg);
			break;
		case 'f':
			gBinFormat = atoi(optarg);
			break;
		default:
			printf("warning: unknown option parameter\r\n");
			usage();
			return -1;
			break;
		}
	}

	printf("generate file for %s\r\n", devicename[gBinFormat]);
	/* File open */
	inFile_fd = fopen(input_name, "r");

	/* File open Check */
	if (!inFile_fd) {
		printf("error: input file open failed. \r\n");
		printf("please, use it to help options. \r\n");
		printf("./bootformat -h \r\n");
		return -1;
	}
	outFile_fd = fopen(output_name, "w");

	/* Binary size check */
	fseek(inFile_fd, 0, SEEK_END);
	BinFileSize = ftell (inFile_fd);
	fseek(inFile_fd, 0, SEEK_SET);

	/* Output size fixed. */
	if ((BinFileSize > MAX_FILESIZE)) {
		printf("input binary file size: %d(%X) \r\n",
				inputSize, inputSize);
		printf( "warning : \"%s\" is too big for Second boot image,"
			"only will used first %d bytes.\n",
					input_name, MAX_FILESIZE );
		outputSize = MAX_FILESIZE;
	} else {
		outputSize = BinFileSize + NSIHSIZE;
		printf("Binary file size: %d(%X) \r\n",
				BinFileSize, BinFileSize);
	}

	/* Memory Allocation */
	pdwSrcData = malloc(BinFileSize);
	pdwDstData = malloc(outputSize);
	nsihData   = malloc(NSIHSIZE);
	memset((void *)pdwSrcData, 0xFF, BinFileSize);	// Initialized with 0xFF as the page size.
	memset((void *)pdwDstData, 0xFF, outputSize);

	/* File Option Selected */
	fread((void *)pdwSrcData, 1, BinFileSize, inFile_fd);
	memcpy((void *)(pdwDstData + nsihSize), pdwSrcData, BinFileSize);
	pSecondInfo = (struct NX_SecondBootInfo *)pdwDstData;
//------------------------------------------------------------------------------
	/* NSIH Data Generation */
	if (NSIHSIZE != ProcessNSIH(nsih_name, nsihData)) {
		// translate text file to 512 Byte binary
		printf("error : failed to process NSIH(%s). Failed Size(%d).\n",
				nsih_name, nsihSize);
		ret = -1;
		goto error;
	} else
		printf("msg: NSIH code is generated. \r\n");
	memcpy((void *)pdwDstData, nsihData, nsihSize);

//------------------------------------------------------------------------------
	/* CRC Code Calcurate  */
	if ((gBinFormat == SPI) || (gBinFormat == UART)) {
		pSecondInfo->DBI.SPIBI.CRC32 =
			__calc_crc((void*)pdwSrcData, BinFileSize);
		printf("CRC32 is 0x%08X\r\n", pSecondInfo->DBI.SPIBI.CRC32);
	}

	pSecondInfo->LOADSIZE = BinFileSize;  //Load Size
	pSecondInfo->SIGNATURE = HEADER_ID;
//------------------------------------------------------------------------------
	printf("output file size is %d(%X)\r\n", outputSize, outputSize);
	fwrite(pdwDstData, 1, outputSize, outFile_fd);

error:
	fclose(inFile_fd);
	fclose(outFile_fd);
	free(pdwSrcData);
	free(pdwDstData);
	free(nsihData);
	return ret;
}
