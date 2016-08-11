/*==============================================================================
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	Nexell informs that this code and information is provided "as is" base
//	and without warranty of any kind, either expressed or implied, including
//	but not limited to the implied warranties of merchantability and/or
//	fitness for a particular puporse.
//
//	Module		:
//	File		:
//	Description	:
//	Author		: Hans
//	History		: 2013.02.06 First implementation
//
==============================================================================*/
#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include <nx_debug2.h>

#include <nx_chip.h>

#include <fatfs.h>

#include <iSDHCBOOT.h>
#include "nx_etacarinae_bootheader.h"

void ResetCon(U32 devicenum, CBOOL en);
void Decrypt(U32 *SrcAddr, U32 *DestAddr, U32 Size);
void GPIOSetAltFunction(U32 AltFunc);


extern struct NX_CLKGEN_RegisterSet * const pgSDClkGenReg[3];
extern struct NX_SDMMC_RegisterSet * const pgSDXCReg[3];

CBOOL ProcessNSIH(FIL *file, U8 *pOutData, U32 option)
{
	S32 writesize = 0, skipline = 0, bytesize = 0, line = 0;
	U32 writeval = 0, FSize = file->fsize;

	NX_DEBUG_MSG("file size: ");
	NX_DEBUG_DEC(file->fsize);
	NX_DEBUG_MSG("\r\n");

	while (FSize) {
		U32 RSize;
		S8 txtbuffer[512];

		if (f_read(file, (void*)txtbuffer, 512, &RSize) == FR_OK) {
			U32 chcnt = 0;
			FSize -= RSize;

			if (option & 1 << DECRYPT)
				Decrypt((U32*)txtbuffer, (U32*)txtbuffer, RSize);

			while (RSize > chcnt) {
				S8 ch = txtbuffer[chcnt++];

				if (skipline == 0) {
					if (ch >= '0' && ch <= '9') {
						writeval = writeval * 16 + ch - '0';
						writesize += 4;
					} else if (ch >= 'a' && ch <= 'f') {
						writeval = writeval * 16 + ch - 'a' + 10;
						writesize += 4;
					} else if (ch >= 'A' && ch <= 'F') {
						writeval = writeval * 16 + ch - 'A' + 10;
						writesize += 4;
					} else {
						if (writesize == 8 ||
							writesize == 16 ||
							writesize == 32) {
							S32 i;
							for (i=0; i<writesize/8; i++) {
								pOutData[bytesize++] = (U8)(writeval & 0xFF);
								writeval >>= 8;
							}
						} else {
							if (writesize != 0) {
								NX_DEBUG_MSG("ProcessNSIH : Error at ");
								NX_DEBUG_DEC(line + 1);
								NX_DEBUG_MSG(" line.\r\n");
								return CFALSE;
							}
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
		} else
			return CFALSE;
	}

	NX_DEBUG_MSG("ProcessNSIH : ");
	NX_DEBUG_DEC(line + 1);
	NX_DEBUG_MSG(" line, ");
	NX_DEBUG_DEC(bytesize);
	NX_DEBUG_MSG(" bytes generated.\r\n");

	return bytesize;
}

static CBOOL FSBoot(U32 option)
{
	CBOOL Ret = CFALSE;
	FATFS FATFS;	/* Pointer to the file system objects (logical drives) */
	struct NX_SecondBootInfo *pSBI =
		(struct NX_SecondBootInfo *)BASEADDR_SRAM;
	const char *diskname = "0:";

	NX_DEBUG_MSG("mount to disk 0\r\n");
	FATFS.fs_type = 0;
	FATFS.id = 0;
	if (FR_OK == f_mount(&diskname, &FATFS, 0)) {
		const char *headerfilename = "NXBTINFO.SBH";
		FIL hfile;

		if (FR_OK == f_open(&hfile, headerfilename, FA_READ, &FATFS)) {
			if (CFALSE != ProcessNSIH(&hfile, (U8*)pSBI, option)) {
				if (pSBI->SIGNATURE == HEADER_ID) {
					const char *loaderfilename = "NXDATA.SBL";
					FIL lfile;

					if(FR_OK == f_open(&lfile, loaderfilename, FA_READ, &FATFS)) {
						U32 RSize, BootSize = lfile.fsize;

						if (BootSize > INTERNAL_SRAM_SIZE - SECONDBOOT_STACK)
							BootSize = INTERNAL_SRAM_SIZE - SECONDBOOT_STACK;

						if (FR_OK == f_read(&lfile, (void*)(BASEADDR_SRAM + sizeof(struct NX_SecondBootInfo)),
									BootSize, &RSize))
						{
							if (option & 1<< DECRYPT)
								Decrypt((U32*)(BASEADDR_SRAM + sizeof(struct NX_SecondBootInfo)),
									(U32*)(BASEADDR_SRAM + sizeof(struct NX_SecondBootInfo)),
									BootSize);
							Ret = CTRUE;
						}
						f_close(&lfile);
					}
				}
			}
			f_close(&hfile);
		}
	}
	return Ret;
}

//------------------------------------------------------------------------------
static CBOOL SDMMCFSBOOT(SDXCBOOTSTATUS *pSDXCBootStatus, U32 option)
{
	CBOOL result = CFALSE;
	struct NX_SDMMC_RegisterSet * const pSDXCReg =
				pgSDXCReg[pSDXCBootStatus->SDPort];

	if (CTRUE == NX_SDMMC_Open(pSDXCBootStatus, option)) {
		if (0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY)) {
			volatile U32 tempcount = 0x100000;
			NX_DEBUG_MSG("FIFO Reset!!!\n");
			pSDXCReg->CTRL = NX_SDXC_CTRL_FIFORST;	/* Reset the FIFO. */
			/* Wait until the FIFO reset is completed. */
			while ((pSDXCReg->CTRL & NX_SDXC_CTRL_FIFORST) && tempcount--);
		}

		result = FSBoot(option);
	}
	NX_SDMMC_Close(pSDXCBootStatus);

	return result;
}

//------------------------------------------------------------------------------
U32 iSDXCFSBOOT(U32 option)
{
	CBOOL	result = CFALSE;
	SDXCBOOTSTATUS SDXCBootStatus, *pSDXCBootStatus, **pgSDXCBootStatus;

	pgSDXCBootStatus = (SDXCBOOTSTATUS**)(BASEADDR_SRAM + INTERNAL_SRAM_SIZE - sizeof(U32));
	*pgSDXCBootStatus = pSDXCBootStatus = &SDXCBootStatus;

	pSDXCBootStatus->SDPort = ((option >> SELSDPORT) & 0x1);
	if (option & 1UL << SELSDPORT1)
		pSDXCBootStatus->SDPort += 2;

	if (pSDXCBootStatus->SDPort >= 3) {
		pSDXCBootStatus->SDPort = 2;
		pSDXCBootStatus->bHighSpeed = CTRUE;
	} else
		pSDXCBootStatus->bHighSpeed = CFALSE;

	NX_SDPADSetALT(pSDXCBootStatus->SDPort);

	/*--------------------------------------------------------------------*/
	/* Normal SD(eSD)/MMC ver 4.2 boot */

	NX_SDMMC_Init(pSDXCBootStatus);
	result = SDMMCFSBOOT(pSDXCBootStatus, option);
	NX_SDMMC_Terminate(pSDXCBootStatus);

	NX_SDPADSetGPIO(pSDXCBootStatus->SDPort);

	return result;
}
