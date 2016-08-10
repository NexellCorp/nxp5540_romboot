#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

/* Data type */
#define	U32	unsigned int
#define	S32	int
#define	U8	unsigned char
#define	S8	char
#define	DEBUG   

/* fixed size */
#define SRAMSIZE		(204*1024)
#define SECONDBOOT_STACK	0x1000
#define MAXNANDBOOTPAGE		16

/*--------------------------------------------------------------------------
// BCH variables:
//--------------------------------------------------------------------------
//  k : number of information
//  m : dimension of Galois field.
//  t : number of error that can be corrected.
//  n : length of codeword = 2^m - 1
//  r : number of parity bit = m * t
//------------------------------------------------------------------------*/
#define NX_BCH_SECTOR_MAX	1024	/* sector size 512 or 1024 */
#define NX_BCH_VAR_K		(1024 * 8)	/* sector size * 8 sector size by bit */
#define NX_BCH_VAR_M		(14)	/* if sector size is 512 then 13, 1024 then 14 */
#define NX_BCH_VAR_T		(60)	/* error correction number */
/* you just change above field when test. */
#define NX_BCH_VAR_N	(((1 << NX_BCH_VAR_M) - 1))
#define NX_BCH_VAR_R	(NX_BCH_VAR_M * NX_BCH_VAR_T)

#define NX_BCH_VAR_TMAX	(60)
#define NX_BCH_VAR_RMAX	(NX_BCH_VAR_M * NX_BCH_VAR_TMAX)

#define NX_BCH_VAR_R32		((NX_BCH_VAR_R    + 31) / 32)
#define NX_BCH_VAR_RMAX32	((NX_BCH_VAR_RMAX + 31) / 32)

#define mm_max		14	/* Dimension of Galoise Field */
#define nn_max		32768	/* Length of codeword, n = 2**m - 1 */
#define tt_max		60	/* Number of errors that can be corrected */
#define kk_max		32768	/* Length of information bit, kk = nn - rr  */
#define rr_max		1024	/* Number of parity checks, rr = deg[g(x)] */
#define parallel_max	32	/* Number of parallel encoding/syndrome computations */

unsigned int alpha_to[nn_max], index_of[nn_max];	/* Galois field */
int gg[rr_max];						/* Generator polynomial */
int T_G[rr_max][rr_max], T_G_R[rr_max][rr_max];		/* Parallel lookahead table */
int T_G_R_Temp[rr_max][rr_max];
int gen_roots[32769], gen_roots_true[32769];		/* Roots of generator polynomial */
int Parallel = 8;

//----------------------
unsigned int iSectorSize;
unsigned int iPageSize;
//-----------------------
unsigned int iNX_BCH_VAR_K; /* (512 * 8) or (1024 * 8) */
unsigned int iNX_BCH_VAR_M; /* 13 or 14 */
unsigned int iNX_BCH_VAR_T; /* 24 or 60 */
unsigned int iNX_BCH_VAR_N;
unsigned int iNX_BCH_VAR_R;

unsigned int iNX_BCH_VAR_TMAX;
unsigned int iNX_BCH_VAR_RMAX;

unsigned int iNX_BCH_VAR_R32;
unsigned int iNX_BCH_VAR_RMAX32;

unsigned int iNX_BCH_OFFSET;


/*------------------------------------------------------------------------------
// this is fixed code. don't touch
//----------------------------------------------------------------------------*/
void generate_gf()
/* Generate GF(2**mm) from the primitive polynomial p(X) in p[0]..p[mm]
   The lookup table looks like:
   index -> polynomial form:   alpha_to[ ] contains j = alpha**i;
   polynomial form -> index form:  index_of[j = alpha**i] = i
   alpha_to[1] = 2 is the primitive element of GF(2**mm)
 */
{
	U32 i, mask, p;
	/* Primitive polynomials */
	/* mm = 2^? */
	if (iNX_BCH_VAR_M == 13)  p = 0x25AF;
	if (iNX_BCH_VAR_M == 14)  p = 0x41D5;

	/* Galois field implementation with shift registers */
	/* Ref: L&C, Chapter 6.7, pp. 217 */
	mask = 1;
	alpha_to[iNX_BCH_VAR_M] = 0;

	for (i = 0; i < iNX_BCH_VAR_M; i++) {
		alpha_to[i] = mask;
		index_of[alpha_to[i]] = i;

		if (((p >> i) & 0x1) != 0)
			alpha_to[iNX_BCH_VAR_M] ^= mask;

		mask <<= 1;
	}

	index_of[alpha_to[iNX_BCH_VAR_M]] = iNX_BCH_VAR_M;
	mask >>= 1;

	for (i = iNX_BCH_VAR_M + 1; i < (iNX_BCH_VAR_N); i++) {
		if (alpha_to[i - 1] >= mask)
			alpha_to[i] = alpha_to[iNX_BCH_VAR_M] ^
					((alpha_to[i - 1] ^ mask) << 1);
		else
			alpha_to[i] = alpha_to[i - 1] << 1;

		index_of[alpha_to[i]] = i;
	}
	index_of[0] = -1;
}

/*------------------------------------------------------------------------------
// this is fixed code. don't touch
//----------------------------------------------------------------------------*/
void gen_poly()
/* Compute generator polynomial of the tt-error correcting Binary BCH code
 * g(x) = LCM{M_1(x), M_2(x), ..., M_2t(x)},
 * where M_i(x) is the minimal polynomial of alpha^i by cyclotomic cosets
 */
{
	S32 i, j, iii, jjj, Temp;
	S32 rr, kk;

	/* Initialization of gen_roots */
	for (i = 0; i <= (iNX_BCH_VAR_N); i++) {
		gen_roots_true[i] = 0;
		gen_roots[i] = 0;
	}

	/* Cyclotomic cosets of gen_roots */
	for (i = 1; i <= 2 * iNX_BCH_VAR_T; i++) {
		for (j = 0; j < iNX_BCH_VAR_M; j++) {
			Temp = ((1 << j) * i) % iNX_BCH_VAR_N;
			gen_roots_true[Temp] = 1;
		}
	}

	rr = 0;   /* Count the number of parity check bits */
	for (i = 0; i < iNX_BCH_VAR_N; i++) {
		if (gen_roots_true[i] == 1) {
			rr++;
			gen_roots[rr] = i;
		}
	}
	kk = (iNX_BCH_VAR_N) - rr;

	/* Compute generator polynomial based on its roots */
	gg[0] = 2; /* g(x) = (X + alpha) initially */
	gg[1] = 1;
	for (i = 2; i <= rr; i++) {
		gg[i] = 1;
		for (j = i - 1; j > 0; j--) {
			if (gg[j] != 0)
				gg[j] = gg[j-1] ^ alpha_to[(index_of[gg[j]] +
					index_of[alpha_to[gen_roots[i]]]) %
					(iNX_BCH_VAR_N)];
			else
				gg[j] = gg[j-1];
		}
		gg[0] = alpha_to[(index_of[gg[0]] +
				index_of[alpha_to[gen_roots[i]]]) %
				(iNX_BCH_VAR_N)];
	}

	/* for parallel encoding and syndrome computation */
	/* Max parallalism is rr */
	if (Parallel > rr)
		Parallel = rr;

	/* Construct parallel lookahead matrix T_g, and T_g**r from gg(x) */
	/* Ref: Parallel CRC, Shieh, 2001 */
	for (i = 0; i < rr; i++)
		for (j = 0; j < rr; j++)
			T_G[i][j] = 0;

	for (i = 1; i < rr; i++)
		T_G[i][i-1] = 1;

	for (i = 0; i < rr; i++)
		T_G[i][rr - 1] = gg[i];

	for (i = 0; i < rr; i++)
		for (j = 0; j < rr; j++)
			T_G_R[i][j] = T_G[i][j];

	/* Compute T_G**R Matrix */
	for (iii = 1; iii < Parallel; iii++) {
		for (i = 0; i < rr; i++)
			for (j = 0; j < rr; j++) {
				Temp = 0;
				for (jjj = 0; jjj < rr; jjj++)
					Temp = Temp ^
						T_G_R[i][jjj] *
						T_G[jjj][j];

				T_G_R_Temp[i][j] = Temp;
			}

		for (i = 0; i < rr; i++)
			for (j = 0; j < rr; j++)
				T_G_R[i][j] = T_G_R_Temp[i][j];
	}
}

/*======================================================================
// ====================> ECC generation function =======================
//====================================================================*/
void parallel_encode_bch(U32 *pData32, U32 *pECC)
/* Parallel computation of n - k parity check bits.
 * Use lookahead matrix T_G_R.
 * The incoming streams are fed into registers from the right hand
 */
{
	U32 i, j, iii, Temp, bb_temp[rr_max];
	U32 loop_count;
	U32 bb[rr_max / 32];

	/* Determine the number of loops required for parallelism. */
	loop_count = iSectorSize;

	/* Initialize the parity bits. */
	for (i = 0; i < rr_max / 32; i++)
		bb[i] = 0;

	/* Compute parity checks
	// S(t) = T_G_R [ S(t-1) + M(t) ]
	// Ref: Parallel CRC, Shieh, 2001 */

	for (iii = 0; iii < loop_count; iii++) {
		for (i = 0; i < iNX_BCH_VAR_R; i++)
			bb_temp[i] = (bb[i >> 5] >> (i & 0x1F)) & 0x00000001;

		for (i = 0; i < Parallel; i++) /* 8bit */
			bb_temp[iNX_BCH_VAR_R - Parallel + i] ^=
				(pData32[iii >> 2] >> (i + (iii << 3))) &
					0x00000001;

		for (i = 0; i < iNX_BCH_VAR_R; i++) {
			Temp = 0;
			for (j = 0; j < iNX_BCH_VAR_R; j++)
				Temp ^= (bb_temp[j] * T_G_R[i][j]);

			if (Temp)
				bb[i >> 5] |=  Temp << (i & 0x1F);
			else
				bb[i >> 5] &=  ~(1 << (i & 0x1F));
		}
	}

	iii = ((iNX_BCH_VAR_R + (32 - 1)) >> 5);

	for (i = 0; i < iii; i++) {
		/* reverse each bit every 32 bit and reverse byte endian */
		Temp = bb[i];
		temp = ((temp & 0xaaaaaaaa) >> 1) | ((temp & 0x55555555) << 1);
		temp = ((temp & 0xcccccccc) >> 2) | ((temp & 0x33333333) << 2);
		temp = ((temp & 0xf0f0f0f0) >> 4) | ((temp & 0x0f0f0f0f) << 4);
		*pECC++ = Temp;
	}
}

/*======================================================================
// ============> ECC relocation function for using Romboot =============
//====================================================================*/
S32 MakeECCChunk( U32 *pdwSrcAddr, U32 *pdwDstAddr, S32 SrcSize)
/* SrcSize = 512*7 or 1024*7 */
{
	S32 iSector, iSecCount;

	iSecCount = (SrcSize + (iSectorSize - 1)) / iSectorSize;
	/* only use 8 pages per block */
	if (iSecCount > 7) {
		printf("Warning - size(%d) must be less than or equal to %d\r\n",
						SrcSize, 7 * iSectorSize);
		iSecCount = 7;
	}

	/*----------------------------------------------*/
	for (iSector = 0; iSector < iSecCount; iSector++) {
		memcpy((void *)(pdwDstAddr + ((iSector + 1) * (iSectorSize / 4))),
			(const void *)(pdwSrcAddr + (iSector * (iSectorSize / 4))),
			iSectorSize);
		parallel_encode_bch((pdwDstAddr + ((iSector + 1) * (iSectorSize / 4))),
				pdwDstAddr + ((iSector + 1) * (iSectorSize / 8 / 4)));  
		printf(".");
	}
	printf("\n"); 
	return ((iSecCount + 1) * iSectorSize);
}

/* How to use Help */ 
static void usage(void)
{
	printf(
"\r\n"
"  NAND boot binary ECC file Generater\r\n"
"  Usage:\r\n"
"   -h                       : show this message\r\n"
"   -i [file name]           : [input ] binary file name\r\n"
"   -o [file name]           : [output] ECC file name\r\n"
"   -p 512, 2, 4, 8, 16, 32  : Page size(512 is 512B others are KB unit\r\n"
"\r\n" 
" example: "
" #>./nandboot_bingen -i 2ndboot.bin -o 2ndboot.bin.ecc -p 4\r\n"
"\r\n"
	);
}

S32 main(int argc, char *argv[])
{
	FILE *inFile_fd, *outFile_fd; 
	S32 param_opt, ret = 0;
	U8 *input_name, *output_name;
	/* file  size variables */
	U32 nandwriteposition, remainsize, pagesize, processsize;

	U32 *pdwSrcData, *pdwDstData;
	U8 emptysector[1024];

	printf("\r\n");
	/* option for the loop */
	while (-1 !=(param_opt = getopt(argc, argv, "hi:o:p:"))) {
		switch (param_opt) {
		case 'h':	/* show usage */
			usage();
			return -1;
		case 'i':	/* [input ] binary file name */
			input_name = strdup(optarg);
			break;
		case 'o':	/* [output] binary file name */
			output_name = strdup(optarg);
			break;
		case 'p':	/* 512B, 2K, 4K, 8K, 16K, 32K : Page size */
			pagesize = atoi(optarg);
			if (((pagesize >= 2) && (pagesize <= 32))) {
				printf("target nand page size is %d KByte.\r\n",
						pagesize);
			}
			else if(pagesize == 512) {
				printf("target nand page size is %d Byte.\r\n",
						pagesize);
			} else {
				printf("error: please, choose your page size."
					       " ( 512, 2, 4, 8, 16, 32 )\r\n");
				return -1;
			}
			break;
		default:
			printf("warning: unknown option parameter.\r\n");
			usage();
			return -1;
		}
	}
/*----------------------------------------------------------------------------*/
	if ((pagesize >= 2) && (pagesize <= 32)) {
		iNX_BCH_VAR_T   = 60;	/* error correctable bit. can be 4, 8, 12, 16 */
		iNX_BCH_VAR_M   = 14;
		iPageSize = pagesize * 1024;
		iSectorSize = 1024;
	} else if (pagesize == 512) {
		iNX_BCH_VAR_T   = 24;	/* error correctable bit. can be 24, 40 */
		iNX_BCH_VAR_M   = 13;
		iPageSize = pagesize;
		iSectorSize = 512;
	}
/*----------------------------------------------------------------------------*/
	/* File open */
	inFile_fd  = fopen(input_name, "r");

	/* File open Check */
	if (!inFile_fd) { 
		printf("error: input file open failed.\r\n"); 
		printf("please, use it to help options.\r\n"); 
		printf("./nandboot_bingen -h\r\n"); 
		return -1; 
	} 
	outFile_fd = fopen(output_name, "w");

	/* Binary size check */
	fseek(inFile_fd, 0, SEEK_END);
	remainsize = ftell (inFile_fd);
	fseek(inFile_fd, 0, SEEK_SET);

	/* Output size fixed. */
	if (remainsize  > SRAMSIZE - SECONDBOOT_STACK) {
		printf("input binary file size: %d \r\n", remainsize);
		printf("warning : \"%s\" is too big for Second boot image,"
			       " only will used first %d bytes.\n",
				input_name, SRAMSIZE - SECONDBOOT_STACK);
		remainsize = SRAMSIZE - SECONDBOOT_STACK;
	} else {
		printf("%s Size is %d(%x) \r\n",
				input_name, remainsize, remainsize);
	}

	pdwSrcData = (U32*)malloc(7 * 1024);
	pdwDstData = (U32*)malloc(8 * 1024);

	memset((void *)pdwSrcData, 0xFF, 7 * 1024);
	memset((void *)pdwDstData, 0xFF, 8 * 1024);
	memset((void *)emptysector, 0xFF, 1024);
/*----------------------------------------------------------------------------*/

/*;---------------------------------------------------------------------------*/
	iNX_BCH_VAR_K   = (iSectorSize * 8);

	iNX_BCH_VAR_N   = (((1 << iNX_BCH_VAR_M) - 1));
	iNX_BCH_VAR_R   = (iNX_BCH_VAR_M * iNX_BCH_VAR_T);

	iNX_BCH_VAR_TMAX  = (60);
	iNX_BCH_VAR_RMAX  = (iNX_BCH_VAR_M * iNX_BCH_VAR_TMAX);

	iNX_BCH_VAR_R32   = ((iNX_BCH_VAR_R + 31) / 32);
	iNX_BCH_VAR_RMAX32  = ((iNX_BCH_VAR_RMAX + 31) / 32);

	iNX_BCH_OFFSET    = 8;

/*----------------------------------------------------------------------------*/
	/* Encoding */
	printf("Make Encoding data table. Wait!!\r\n");
	/* generate the Galois Field GF(2**mm) */
	generate_gf();
	/* Compute the generator polynomial and lookahead matrix for BCH code */
	gen_poly();

	/* make nand boot code format. please refer datasheet. */
	printf("generating %s\r\n", output_name);
	nandwriteposition = 0;
	while (1) {
		U32 writesize;
		if (remainsize) {
			printf("remain size is %d(%x)\r\n",
					remainsize, remainsize);
			if (remainsize >= 7 * iSectorSize)
				processsize = 7 * iSectorSize;
			else
				processsize = remainsize;
			printf("next process size is %d(%x)\r\n",
					processsize, processsize);
			remainsize -= processsize;
			fread(pdwSrcData, 1, processsize, inFile_fd);
		} else
			break;
		writesize = MakeECCChunk( pdwSrcData, pdwDstData, processsize);
		printf("ecc chunk size is %d(%x)\r\n", writesize, writesize);
		/* Write file page by page */
		fwrite(pdwDstData, 1, writesize, outFile_fd);

		nandwriteposition += writesize;

		memset((void *)pdwSrcData, 0xFF, 7 * 1024);
		memset((void *)pdwDstData, 0xFF, 8 * 1024);

		if (iPageSize > MAXNANDBOOTPAGE * 1024 &&
				nandwriteposition >= MAXNANDBOOTPAGE * 1024 &&
				remainsize > 0) {
			U32 i, fillcount = iPageSize / iSectorSize -
						MAXNANDBOOTPAGE;
			printf("nand page size is over romboot process page size\r\n");
			printf("fill %d KBytes to 0xFF\r\n", fillcount);
			for (i = 0; i < fillcount; i++)
				/* Write file page by sector */
				fwrite(emptysector, 1, 1024, outFile_fd);
			nandwriteposition = 0;
		}
	}

error:
	/* Normal Return */
	fclose(inFile_fd);
	fclose(outFile_fd);
	free(pdwSrcData);
	free(pdwDstData);
	return ret;
}
