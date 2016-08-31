////////////////////////////////////////////////////////////////////////////////
//
//	Copyright (C) 2009 Nexell Co., Ltd All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	Nexell informs that this code and information is provided "as is" base
//	and without warranty of any kind, either expressed or implied, including
//	but not limited to the implied warranties of merchantability and/or fitness
//	for a particular puporse.
//
//
//	Module		:
//	File		: iROMBOOT.c
//	Description	:
//	Author		: Hans
//	History		:
//		2014-01-12	Hans create
//		2016-08-09	Hans modified for NXP5540
////////////////////////////////////////////////////////////////////////////////
#include <nx_etacarinae.h>
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include "debug.h"

#ifdef NXP5430
#include <nx_chip.h>

#endif
#ifdef NXP5540
#include <nx_chip_sfr.h>
#endif
#include <nx_clkpwr.h>
#include <nx_alive.h>
#include <nx_gpio.h>
#include <nx_ecid.h>

#include "printf.h"

#ifdef NXP5430
struct NX_GPIO_RegisterSet (* const pGPIOReg)[1] =
	(struct NX_GPIO_RegisterSet (*)[])PHY_BASEADDR_GPIOA_MODULE;
#endif
#ifdef NXP5540
struct NX_GPIO_RegisterSet (* const pGPIOReg)[1] =
	(struct NX_GPIO_RegisterSet (*)[])PHY_BASEADDR_GPIO1_MODULE;
#endif
struct NX_ALIVE_RegisterSet * const pALIVEReg =
	(struct NX_ALIVE_RegisterSet *)PHY_BASEADDR_ALIVE_MODULE;

struct NX_ECID_RegisterSet * const pECIDReg =
	(struct NX_ECID_RegisterSet *)PHY_BASEADDR_ECID_MODULE;

extern CBOOL iSDXCFSBOOT(U32 option);
extern CBOOL iUSBBOOT(U32 option);
extern CBOOL iSPIBOOT(U32 option);
extern CBOOL iSDXCBOOT(U32 option);
extern CBOOL iNANDBOOTEC(U32 option);
void enable_mmu_el3(U32);
//------------------------------------------------------------------------------
void iROMBOOT(U32 OrgBootOption)
{
	void (*pLaunch)(void) = (void(*)(void))BASEADDR_SRAM;
	CBOOL Result = CFALSE;
	U32 option = OrgBootOption;

#ifdef NXP5430
	//--------------------------------------------------------------------------
	// Power Management Control
	//--------------------------------------------------------------------------
	// Enable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 1;

	pALIVEReg->VDDCTRLSETREG	= 0x00000003;

	// Disable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 0;
#endif
#ifdef NXP5540

#endif
#if 0
	SetMMUTableDefault();
	StartMMUnCache(CTRUE, CTRUE, CTRUE);
#endif

	//--------------------------------------------------------------------------
	// Debug Console
	//--------------------------------------------------------------------------
	DebugInit(3);

	printf("\r\n\n iROMBOOT by Nexell Co. : Built on %s %s\r\n",
			__DATE__, __TIME__);

	enable_mmu_el3(0);
	printf("pad Boot Option: %02X\r\n", option);

	if (((option >> BOOTMODE) & 0x7) == 1)
		goto lastboot;

#ifdef NXP5540
	CBOOL IsSecure = !!(pECIDReg->SJTAG[0] | pECIDReg->SJTAG[1] |
			pECIDReg->SJTAG[2] | pECIDReg->SJTAG[3]);

	// copy secure jtag hash to aes secure key for secure boot decrypt.
	pECIDReg->CRAESKEY[0] = pECIDReg->SJTAG[0];
	pECIDReg->CRAESKEY[1] = pECIDReg->SJTAG[1];
	pECIDReg->CRAESKEY[2] = pECIDReg->SJTAG[2];
	pECIDReg->CRAESKEY[3] = pECIDReg->SJTAG[3];

	U32 eRSTCFG = pECIDReg->RSTCFG;

	if (eRSTCFG & 1 << 15)		// check boot config written
		if ((eRSTCFG & 1 << 14) == 0) {	// check invalid mark
			OrgBootOption = eRSTCFG & 0x3FFF;
		} else {
			eRSTCFG >>= 16;
			if (eRSTCFG & 1 << 15)	// check boot config backup
				if ((eRSTCFG & 1 << 14) == 0)	// check invalid mark
					OrgBootOption = eRSTCFG & 0x3FFF;
		}
	
	printf("efuse Boot Option: %02X\r\n", option);
#endif


	do {
//--------------------------------------------------------------------------
// iROMBOOT mode : option [2:0]
//--------------------------------------------------------------------------
		switch ((option >> BOOTMODE) & 0x7) {
		case SDFSBOOT :	// iSDHCFSBOOT (SD/MMC/eSD/eMMC)
			Result = iSDXCFSBOOT(option);
			break;
		case SPIBOOT :	// iSPIBOOT (Serial Flash memory)
			Result = iSPIBOOT(option);
			break;
		default:
		case SDBOOT :	// iSDHCBOOT (SD/MMC/eSD/eMMC)
		case EMMCBOOT :
			Result = iSDXCBOOT(option);
			break;
		case NANDECBOOT :
			Result = iNANDBOOTEC(option);
			break;
		}

		if (CTRUE == Result)
			break;

		if (option & 1 << NEXTTRY) {

			option = OrgBootOption & ~0x7UL;
			option = OrgBootOption & ~(0x2UL << PORTNUMBER);

			if (option & 1 << USE_FS)
				Result = iSDXCFSBOOT(option);
			else
				Result = iSDXCBOOT(option);
			if (Result)
				break;
		}

		option = OrgBootOption & ~0x7UL;
		option |= USBBOOT;
lastboot:
		iUSBBOOT(option);
	} while (0);


	pLaunch();
}
