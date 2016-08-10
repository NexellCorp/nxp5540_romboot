//------------------------------------------------------------------------------
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	NEXELL Co. Proprietary & Confidential
//
//	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//	FOR A PARTICULAR PURPOSE.
//
//	Module		: iROMBOOT
//	File		: iNANDBOOT.c
//	Description	: Bootloader for NAND flash memory with H/W BCH error detection.
//	Author		: Goofy
//	History		:
//		2016-08-08	Hans	Add for MLC & TLC NAND
//		2013-08-24	Hans	Error Correction Auto mode add
//		2010-12-08	matin	simulation
//		2010-10-15	Hans	Add 24bit Error Correction.
//		2008-10-23	Goofy	Get reset configuration from option argument
//		2008-08-20	Goofy	Create
//------------------------------------------------------------------------------
//#undef NX_DEBUG

#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"
#include <nx_debug2.h>
#include <nx_type.h>

#include <nx_chip.h>

#include <nx_gpio.h>
#include <nx_mcus.h>
#include "nx_etacarinae_bootheader.h"

#define ROW_START			(0)

#define PENDDELAY			0x10000000

//------------------------------------------------------------------------------
// Register Bits
#define NX_NFCTRL_NCSENB		(1U<<31)
#define NX_NFCTRL_AUTORESET		(1U<<30)
#define NX_NFCTRL_ECCMODE		(7U<<27)
#define NX_NFCTRL_ECCMODE_S24		(5U<<27)
#define NX_NFCTRL_ECCMODE_60		(7U<<27)
#define NX_NFCTRL_IRQPEND		(1U<<15)
#define NX_NFCTRL_ECCRST		(1U<<11)
#define NX_NFCTRL_RNB			(1U<< 9)
#define NX_NFCTRL_IRQENB		(1U<< 8)
#define NX_NFCTRL_HWBOOT_W		(1U<< 6)
#define NX_NFCTRL_EXSEL_R		(1U<< 6)
#define NX_NFCTRL_EXSEL_W		(1U<< 5)
#define NX_NFCTRL_NFTYPE		(3U<< 3)
#define NX_NFCTRL_BANK			(3U<< 0)

#define NX_NFACTRL_SYN			(1U<< 1)	// 0: auto mode 1: cpu mode
#define NX_NFACTRL_ELP			(1U<< 0)	// 0: auto mode 1: cpu mode

#define NX_NFECCSTATUS_ELPERR		(0x3FU<< 16)	// 6bit (16, 17, 18, 19, 20, 21)
#define NX_NFECCSTATUS_CHIENERR		(0x7FU<<  4)	// 7bit (4, 5, 6, 7, 8, 9, 10)
#define NX_NFECCSTATUS_ERROR		(1U<<  3)
#define NX_NFECCSTATUS_BUSY		(1U<<  2)
#define NX_NFECCSTATUS_DECDONE		(1U<<  1)

#define NX_NFECCCTRL_RUNECC_W		28	// ecc start
#define NX_NFECCCTRL_DECMODE_R		28
#define NX_NFECCCTRL_ELPLOAD		27	// set after elp registers
#define NX_NFECCCTRL_DECMODE_W		26	// 0: encoder 1: decoder
	#define NX_NF_ENCODE			0
	#define NX_NF_DECODE			1
#define NX_NFECCCTRL_ELPNUM		18	// number of elp (0x7F)
#define NX_NFECCCTRL_PDATACNT		10	// number of parity bit (0xFF)
#define NX_NFECCCTRL_DATACNT		0	// nand data count value(write) (0x3FF)

//------------------------------------------------------------------------------
// NAND Command
#define NAND_CMD_READ_1ST		(0x00)
#define NAND_CMD_READ_2ND		(0x30)
#define NAND_CMD_READ_ID		(0x90)
#define NAND_CMD_RESET			(0xFF)

//------------------------------------------------------------------------------
// Registers
struct  NX_NAND_RegisterSet
{
	volatile U32 NAND_DATA;		///< 00h
	volatile U32 __Reserved0[3];	///< 04h ~ 0Ch	: Reserved for future use.
	volatile U8  NAND_CMD;		///< 10h
	volatile U8  __Reserved1[7];	///< 11h ~ 17h	: Reserved for future use.
	volatile U8  NAND_ADDR;		///< 18h
	volatile U8  __Reserved2[7];	///< 19h ~ 1Fh	: Reserved for future use.
};

//------------------------------------------------------------------------------
typedef struct tag_NANDBOOTECSTATUS
{
	U32	iNX_BCH_VAR_K;
	U32	iNX_BCH_VAR_M;

	U32	iNX_BCH_VAR_T;		// 4, 8, 12, 16, 24, 40, 60

	U32	iNX_BCH_VAR_RMAX;

	U32	dwSectorSize;

	S32	iSectorsPerPage;
	U32	dwNFType;

	U32	dwRowCur;
	S32	iECCLeft;
	S32	iSectorLeft;
	U32	ECC[1024/4];
} NANDBOOTECSTATUS;


extern struct NX_GPIO_RegisterSet (* const pGPIOReg)[1];
static struct NX_MCUS_RegisterSet * const pNandControl =
	(struct NX_MCUS_RegisterSet *)PHY_BASEADDR_MCUSTOP_MODULE;
static struct NX_NAND_RegisterSet * const pNandAccess =
	(struct NX_NAND_RegisterSet *)BASEADDR_NFMEM;

//------------------------------------------------------------------------------
// BCH variables:
//------------------------------------------------------------------------------
//	k : number of information
//	m : dimension of Galois field.
//	t : number of error that can be corrected.
//	n : length of codeword = 2^m - 1
//	r : number of parity bit = m * t
//------------------------------------------------------------------------------
#define NX_BCH_VAR_K		(1024 * 8)	// 512*8, 1024*8
#define NX_BCH_VAR_M		(14)		// 13, 14

#define NX_BCH_VAR_T		(60)		// 4, 8, 12, 16, 24, 40, 60

#define NX_BCH_VAR_N		(((1<<NX_BCH_VAR_M)-1))
#define NX_BCH_VAR_R		(NX_BCH_VAR_M * NX_BCH_VAR_T)

#define NX_BCH_VAR_TMAX		(60)
#define NX_BCH_VAR_RMAX		(NX_BCH_VAR_M * NX_BCH_VAR_TMAX)

#define NX_BCH_VAR_R32		((NX_BCH_VAR_R		+31)/32)
#define NX_BCH_VAR_RMAX32	((NX_BCH_VAR_RMAX	+31)/32)


//------------------------------------------------------------------------------
static S32 NX_NAND_GetErrorLocation(U32 *pLocation)
{
	U32 i, ErrorCount = (pNandControl->NFECCSTATUS &
				NX_NFECCSTATUS_CHIENERR) >> 4;
	volatile U32 *pRegErrLoc = pNandControl->NFERRLOCATION;

	if (((pNandControl->NFECCSTATUS & NX_NFECCSTATUS_CHIENERR)>>4) !=
		((pNandControl->NFECCSTATUS & NX_NFECCSTATUS_ELPERR)>>16))
		return -1;

	for (i = 0; i < ErrorCount / 2; i++) {
		register U32 regvalue = *pRegErrLoc++;
		*pLocation++ = (regvalue >> 0  & 0x3FFF) ^ 0x7;
		*pLocation++ = (regvalue >> 14 & 0x3FFF) ^ 0x7;
	}

	return ErrorCount;
}

//------------------------------------------------------------------------------
static CBOOL CorrectErrors(NANDBOOTECSTATUS *pBootStatus, U32 *pData)
{
	U32 Loc[NX_BCH_VAR_T];
	S32 errors, i;

	errors = NX_NAND_GetErrorLocation(&Loc[0]);
	if (0 > errors) {
		NX_DEBUG_MSG("\t\t ERROR -> Failed to correct errors.\n\n");
		return CFALSE;
	}

	//NX_DEBUG_MSG( "\t" );
	NX_DEBUG_DEC(errors);
	NX_DEBUG_MSG(" error(s) found : ");

	for (i = 0; i < errors; i++) {
		//NX_DEBUG_MSG("\t ERROR ");
		//NX_DEBUG_DEC(i);
		//NX_DEBUG_MSG(" : ");
		NX_DEBUG_DEC(Loc[i]);
		//NX_DEBUG_MSG("\n");
		NX_DEBUG_MSG(", ");

		if (pBootStatus->iNX_BCH_VAR_K > Loc[i]) {
			pData[Loc[i] / 32] ^= 1U << (Loc[i] % 32);
		}
	}

	NX_DEBUG_MSG("\n");
	//NX_DEBUG_MSG( "-> Successful to correct errors.\n" );

	return CTRUE;
}

//------------------------------------------------------------------------------
static void NANDFlash_SetOriECC(NANDBOOTECSTATUS *pBootStatus, U32 *pECC)
{
	register U32 i, iNX_BCH_VAR_RMAX32 =
			((pBootStatus->iNX_BCH_VAR_RMAX	+ 31) / 32);
	volatile U32 *pRegOrgECC = pNandControl->NFORGECC;

	for (i = 0; i < iNX_BCH_VAR_RMAX32; i++) {
		*pRegOrgECC++ = *pECC++;
	}
}

//------------------------------------------------------------------------------
static CBOOL NANDFlash_Open(NANDBOOTECSTATUS *pBootStatus, U32 option)
{
	register U32 nftype, pagesize;
	register volatile U32 temp;

	temp = pNandControl->NFCONTROL;
	temp &= ~ (NX_NFCTRL_ECCMODE | NX_NFCTRL_EXSEL_W);
	temp |= ((temp & NX_NFCTRL_EXSEL_R)>>1);
	temp &= ~ (NX_NFCTRL_HWBOOT_W);

	nftype = (option >> NANDTYPE) & 0x3;	// 0:small 3 step, 1:small 4 step, 2:large 4 step, 3:large 5 step

	if (option & 1 << NANDPAGE0)	// 0: 2KB, 1:4KB, 2:8KB, 3:16KB and above
		pagesize = 0x1;
	if (option & 1 << NANDPAGE1)
		pagesize += 0x2;

	// for large block
	if (nftype & 2) {
		pBootStatus->dwSectorSize	= 1024;
		pBootStatus->iNX_BCH_VAR_K	= 1024 * 8;
		pBootStatus->iNX_BCH_VAR_M	= 14;
		pBootStatus->iNX_BCH_VAR_T	= 60;
		pBootStatus->iSectorsPerPage 	= 1 << (pagesize + 1);
		temp |=	NX_NFCTRL_NCSENB |
			NX_NFCTRL_ECCMODE_60 |
			NX_NFCTRL_IRQENB;
	} else {
		pBootStatus->dwSectorSize	= 512;
		pBootStatus->iNX_BCH_VAR_K	= 512 * 8;
		pBootStatus->iNX_BCH_VAR_M	= 13;
		pBootStatus->iNX_BCH_VAR_T	= 24;
		pBootStatus->iSectorsPerPage 	= 1;
		temp |=	NX_NFCTRL_NCSENB |
			NX_NFCTRL_ECCMODE_S24 |
			NX_NFCTRL_IRQENB;
	}
	pBootStatus->iNX_BCH_VAR_RMAX =
		(pBootStatus->iNX_BCH_VAR_M * pBootStatus->iNX_BCH_VAR_T);


	//--------------------------------------------------------------------------
	pBootStatus->dwNFType	= nftype;
	pBootStatus->dwRowCur 	= ROW_START;	// base page address of NAND flash memory

	pBootStatus->iSectorLeft	= 0;
	pBootStatus->iECCLeft		= 0;

	//--------------------------------------------------------------------------
	// Set NAND flash memory controller
	//--------------------------------------------------------------------------
	// 1) Get NFTYPE from CfgNFType
	// 2) Set NX_NFCTRL_BANK	as '0'
	// 3) Enable an interrupt to use NX_NFCTRL_IRQPEND for checking ready status of NAND flash memory.
	// 4) Set 16-bit ECC mode
	//--------------------------------------------------------------------------
	pNandControl->NFCONTROL = temp;

	// Wait until RnB is 1
	temp = PENDDELAY;
	while (0 == (pNandControl->NFCONTROL & NX_NFCTRL_RNB)  && temp--);
	if (temp == (U32)-1)
		return CFALSE;

	//--------------------------------------------------------------------------
	// Reset NAND flash memory for Micron device.
	//--------------------------------------------------------------------------
	temp = pNandControl->NFCONTROL;
	temp &= ~ (NX_NFCTRL_EXSEL_W);
	temp |= (((temp & NX_NFCTRL_EXSEL_R) >> 1) | NX_NFCTRL_IRQPEND);		// Clear NX_NFCTRL_IRQPEND
	temp &= ~ (NX_NFCTRL_HWBOOT_W);
	pNandControl->NFCONTROL = temp;

	pNandAccess->NAND_CMD = NAND_CMD_RESET;

	temp = PENDDELAY;
	// Wait until ready by using NX_NFCTRL_IRQPEND which is set at rising edge of RnB.
	while (0 == (pNandControl->NFCONTROL & NX_NFCTRL_IRQPEND) && temp--);
	if (temp == (U32)-1)
		return CFALSE;

	return CTRUE;
}

//------------------------------------------------------------------------------
static void NANDFlash_Close(void)
{
	register U32 temp;

	temp = pNandControl->NFCONTROL;
	temp &= ~(NX_NFCTRL_IRQENB | NX_NFCTRL_NCSENB | NX_NFCTRL_EXSEL_W);
	temp |= (((temp & NX_NFCTRL_EXSEL_R) >> 1) | NX_NFCTRL_IRQPEND);
	temp &= ~ (NX_NFCTRL_HWBOOT_W);
	pNandControl->NFCONTROL = temp;
}

//------------------------------------------------------------------------------
static CBOOL NANDFlash_SetAddr(NANDBOOTECSTATUS *pBootStatus)
{
	register volatile U32 temp;
	// check for changing page
	if (pBootStatus->iSectorLeft == 0) {
		U32 row		= pBootStatus->dwRowCur;
		U32 nftype	= pBootStatus->dwNFType;

		temp = pNandControl->NFCONTROL;
		temp &= ~ (NX_NFCTRL_EXSEL_W);
		temp |= (((temp & NX_NFCTRL_EXSEL_R)>>1) | NX_NFCTRL_IRQPEND);		// Clear NX_NFCTRL_IRQPEND
		temp &= ~ (NX_NFCTRL_HWBOOT_W);
		pNandControl->NFCONTROL = temp;

		pNandAccess->NAND_CMD = NAND_CMD_READ_1ST;

		// +------------------------+-------+-------+
		// |		NFTYPE			| COL	| ROW	|
		// +------------------------+-------+-------+
		// | 2'b00 : Small 3 addr	|	1	|	2	|
		// | 2'b01 : Small 4 addr	|	1	|	3	|
		// | 2'b10 : Large 4 addr	|	2	|	2	|
		// | 2'b11 : Large 5 addr	|	2	|	3	|
		// +------------------------+-------+-------+
			pNandAccess->NAND_ADDR = 0;			// COL 1st
		if (nftype & 0x2)
			pNandAccess->NAND_ADDR = 0;			// COL 2nd
			pNandAccess->NAND_ADDR = (U8)(row >>  0);	// ROW 1st
			pNandAccess->NAND_ADDR = (U8)(row >>  8);	// ROW 2nd
		if (nftype & 0x1)
			pNandAccess->NAND_ADDR = (U8)(row >> 16);	// ROW 3rd

		if (nftype & 0x2)	// Large block
			pNandAccess->NAND_CMD = NAND_CMD_READ_2ND;

		// Wait until ready by using NX_NFCTRL_IRQPEND which is set at rising edge of RnB.
		temp = PENDDELAY;
		while (0 == (pNandControl->NFCONTROL & NX_NFCTRL_IRQPEND) && temp--);
		if (temp == (U32)-1)
			return CFALSE;

		pBootStatus->iSectorLeft = pBootStatus->iSectorsPerPage;
		pBootStatus->dwRowCur++;
	}
	return CTRUE;
}

//------------------------------------------------------------------------------
static void NANDFlash_ReadData(NANDBOOTECSTATUS *pBootStatus, U32 *pData)
{
	register U32 temp;

	// run ecc
	pNandControl->NFECCCTRL =	1 << NX_NFECCCTRL_RUNECC_W   |	   // run ecc
					0 << NX_NFECCCTRL_ELPLOAD|
			NX_NF_DECODE << NX_NFECCCTRL_DECMODE_W |
	(pBootStatus->iNX_BCH_VAR_T & 0x7F) << NX_NFECCCTRL_ELPNUM |
	((pBootStatus->iNX_BCH_VAR_M *
	  pBootStatus->iNX_BCH_VAR_T / 8 - 1) & 0xFF) << NX_NFECCCTRL_PDATACNT |
	 ((pBootStatus->dwSectorSize - 1) & 0x3FF) << NX_NFECCCTRL_DATACNT;

	// Read data from NAND flash memory to SRAM
	temp = pBootStatus->dwSectorSize / (4 * 8);
	while (temp--) {
		pData[0] = pNandAccess->NAND_DATA;
		pData[1] = pNandAccess->NAND_DATA;
		pData[2] = pNandAccess->NAND_DATA;
		pData[3] = pNandAccess->NAND_DATA;

		pData[4] = pNandAccess->NAND_DATA;
		pData[5] = pNandAccess->NAND_DATA;
		pData[6] = pNandAccess->NAND_DATA;
		pData[7] = pNandAccess->NAND_DATA;

		pData += 8;
	}

	pBootStatus->iSectorLeft--;
}

//------------------------------------------------------------------------------
static CBOOL NANDFlash_ReadSector(NANDBOOTECSTATUS *pBootStatus, U32 *pData)
{
	register volatile U32 temp;
	//--------------------------------------------------------------------------
	// Copy ECCs from SRAM to H/W BCH decoder
	if (pBootStatus->iECCLeft == 0) {
		if (CFALSE == NANDFlash_SetAddr(pBootStatus))
			return CFALSE;
		NANDFlash_ReadData(pBootStatus, (U32 *)pBootStatus->ECC);
		pBootStatus->iECCLeft = 7;
	}

	//--------------------------------------------------------------------------
	// Reset H/W BCH decoder.
	temp = pNandControl->NFCONTROL;
	temp &= ~ (NX_NFCTRL_EXSEL_W);
	temp |= (((temp & NX_NFCTRL_EXSEL_R)>>1) | NX_NFCTRL_ECCRST);
	temp &= ~ (NX_NFCTRL_HWBOOT_W);
	pNandControl->NFCONTROL = temp;

	pNandControl->NFECCAUTOMODE =
		(pNandControl->NFECCAUTOMODE & ~(NX_NFACTRL_ELP)) |
			NX_NFACTRL_SYN;	// disconnect syndrome path

	// Read Data with ECC
	NANDFlash_SetAddr(pBootStatus);

	// Set original ECCs.
	NANDFlash_SetOriECC(pBootStatus,
			(U32 *)((U32)pBootStatus->ECC +
				(8 - pBootStatus->iECCLeft) *
				pBootStatus->dwSectorSize / 8));
	pBootStatus->iECCLeft--;


	NANDFlash_ReadData(pBootStatus, pData);

	//--------------------------------------------------------------------------
	// Determines whether or not there's an error in data by using H/W BCH decoder.
	// Wait until H/W BCH decoder has been finished.
	temp = PENDDELAY;
	while ((0==(pNandControl->NFECCSTATUS & NX_NFECCSTATUS_DECDONE)) &&
			temp--);
	if (temp == (U32)-1)
		return CFALSE;

	pNandControl->NFECCAUTOMODE =
		(pNandControl->NFECCAUTOMODE &
		 ~(NX_NFACTRL_ELP | NX_NFACTRL_SYN));	// connect syndrome path

	// Check an error status of H/W BCH decoder.
	if (pNandControl->NFECCSTATUS & NX_NFECCSTATUS_ERROR) {
		NX_DEBUG_MSG("-> ");
		NX_DEBUG_DEC(pBootStatus->dwRowCur - 1);
		NX_DEBUG_MSG(" page, ");
		NX_DEBUG_DEC(pBootStatus->iSectorsPerPage -
				pBootStatus->iSectorLeft - 1);
		NX_DEBUG_MSG(" sector : ");

		// load elp
		pNandControl->NFECCCTRL = 
			0 << NX_NFECCCTRL_RUNECC_W |
			1 << NX_NFECCCTRL_ELPLOAD |	   // load elp
			NX_NF_DECODE << NX_NFECCCTRL_DECMODE_W |
			(pBootStatus->iNX_BCH_VAR_T & 0x7F) << NX_NFECCCTRL_ELPNUM |
			((pBootStatus->iNX_BCH_VAR_M *
			  pBootStatus->iNX_BCH_VAR_T / 8 - 1) & 0xFF) <<
				NX_NFECCCTRL_PDATACNT |
			((pBootStatus->dwSectorSize - 1) & 0x3FF) <<
				NX_NFECCCTRL_DATACNT;

		temp = PENDDELAY;
		while ((pNandControl->NFECCSTATUS & NX_NFECCSTATUS_BUSY) &&
				temp--);
		if (temp == (U32)-1)
			return CFALSE;

		return CorrectErrors(pBootStatus, pData);
	}

	return CTRUE;
}
/*
RnB0   b 14 0 gpio:2 reset:0	RnB1   b 14 1 gpio:2 reset:0
nNFOE0 b 16 0 gpio:2 reset:0	nNFOE1 b 16 1 gpio:2 reset:0
nNFWE0 b 18 0 gpio:2 reset:0	nNFWE1 b 18 1 gpio:2 reset:0
sd 0   b 13 0 gpio:1 reset:0	sdex 0 a 30 2 gpio:0 reset:0
sd 1   b 15 0 gpio:1 reset:0	sdex 1 b  0 2 gpio:0 reset:0
sd 2   b 17 0 gpio:1 reset:0	sdex 2 b  2 2 gpio:0 reset:0
sd 3   b 19 0 gpio:1 reset:0	sdex 3 b  4 2 gpio:0 reset:0
sd 4   b 20 0 gpio:1 reset:0	sdex 4 b  6 2 gpio:0 reset:0
sd 5   b 21 0 gpio:1 reset:0	sdex 5 b  8 2 gpio:0 reset:0
sd 6   b 22 0 gpio:1 reset:0	sdex 6 b  9 2 gpio:0 reset:0
sd 7   b 23 0 gpio:1 reset:0	sdex 7 b 10 2 gpio:0 reset:0
*/
void Decrypt(U32 *SrcAddr, U32 *DestAddr, U32 Size);
//------------------------------------------------------------------------------
CBOOL iNANDBOOTEC(U32 option)
{
	CBOOL Result = CTRUE;
	NANDBOOTECSTATUS BootStatus, *pBootStatus;
	struct NX_SecondBootInfo *pSBI;

	pSBI = (struct NX_SecondBootInfo *)BASEADDR_SRAM;
	pBootStatus = &BootStatus;

	register U32 regtemp = 0x77;		// nNSCS0, nNSCS1 bus timing set
	pNandControl->NFTACS = regtemp;
	pNandControl->NFTCOS = regtemp;
	pNandControl->NFTACC = 0xF0F;
	pNandControl->NFTOCH = regtemp;
	pNandControl->NFTCAH = regtemp;

    
	pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[0] =
		(pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[0] & ~0x00000300) |
		0x00000300;		        // C  4     ALT3
	pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1] =
		(pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1] & ~0x3FC00000) |
		0x2BC00000;		        // C 30, 29 ALT2, 28, 27 ALT3
	pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[0] =
		(pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[0] & ~0x0000000F) |
		0x0000000F;		        // D  1,  0 ALT3

	pNandControl->NFCONTROL = (pNandControl->NFCONTROL &
			~(NX_NFCTRL_BANK | NX_NFCTRL_HWBOOT_W | NX_NFCTRL_EXSEL_W))
			| 0x00;	// nNSCS0

	pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[0] =
		(pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[0] & ~0xC0000000) |
		0xC0000000;		        // C 15 ALT3
	pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1] =
		(pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1] & ~0xC000FFFF) |
		0xC000FFFF;	// C 31, 23, 22, 21, 20, 19, 18, 17, 16 ALT3, C 30 ALT2

	if (NANDFlash_Open(pBootStatus, option)) {
		if (NANDFlash_ReadSector(pBootStatus, (U32 *)pSBI)) {
			if (option & 1<< DECRYPT)
				Decrypt((U32*)pSBI, (U32*)pSBI,
						pBootStatus->dwSectorSize);

			if (pSBI->SIGNATURE == HEADER_ID) {
				U32 dwBinAddr, dwBinAddr_Save, BootSize;
				S32 iBinSecLeft;
				BootSize = pSBI->LOADSIZE;

				if (BootSize >
					INTERNAL_SRAM_SIZE - SECONDBOOT_STACK)
					BootSize =
						INTERNAL_SRAM_SIZE -
						SECONDBOOT_STACK;

				/* already read 512 byte when header load. */
				if (pBootStatus->dwSectorSize > 512)
					BootSize -= 512;

				iBinSecLeft = getquotient(BootSize +
						(pBootStatus->dwSectorSize - 1),
						pBootStatus->dwSectorSize);

				dwBinAddr_Save =
					dwBinAddr =
					(U32)BASEADDR_SRAM +
					pBootStatus->dwSectorSize;
				while (iBinSecLeft--) {
					if (NANDFlash_ReadSector(pBootStatus,
								(U32 *)dwBinAddr)) {
						dwBinAddr +=
							pBootStatus->dwSectorSize;
					} else {
						Result = CFALSE;
						break;
					}
				}
				if (option & 1<< DECRYPT)
					Decrypt((U32*)dwBinAddr_Save,
							(U32*)dwBinAddr_Save,
							BootSize);
			} else
				Result = CFALSE;
		} else
			Result = CFALSE;
	} else
		Result = CFALSE;

	NANDFlash_Close();

	pNandControl->NFCONTROL =
		(pNandControl->NFCONTROL &
		 ~(NX_NFCTRL_BANK | NX_NFCTRL_HWBOOT_W | NX_NFCTRL_EXSEL_W)) |
		0x00;	// nNSCS0, Select SD bus


	return Result;
}
