////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2009 Nexell Co., Ltd All Rights Reserved
// Nexell Co. Proprietary & Confidential
// 
// Nexell informs that this code and information is provided "as is" base
// and without warranty of any kind, either expressed or implied, including
// but not limited to the implied warranties of merchantability and/or
// fitness for a particular puporse.
// 
// Module		:
// File		: iROMBOOT.c
// Description	:
// Author		: Hans
// History		:
//		2014-01-12	Hans create
//		2016-08-09	Hans modified for NXP5540
////////////////////////////////////////////////////////////////////////////////
#include <nx_etacarinae.h>
#include "nx_etacarinae_bootoption.h"
#include "nx_etacarinae_bootheader.h"
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

#include "libarm.h"
#include "lib_aarch64.h"

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
void EnterLowLevel(unsigned int *EL1Start, unsigned int rSPSR);
void buildinfo(void);
void Dcache_flush_range(U64 addr, U64 size);
//------------------------------------------------------------------------------
void iROMBOOT(U32 OrgBootOption)
{
	CBOOL Result = CFALSE;
	U32 option = OrgBootOption & 0x1FF;
	U32 eBootOption;

#ifdef NXP5430
	//--------------------------------------------------------------------------
	// Power Management Control
	//--------------------------------------------------------------------------
	// Enable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 1;

	pALIVEReg->VDDCTRLSETREG	= 0x00000003;	// need pad retention off

	// Disable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 0;

	while (!(pECIDReg->EC[2] & 1 << 15))	// wait efuse ready
		;
//	option |= 1 << DECRYPT;		// just for temporary test.
#endif

#ifdef NXP5540
	while( !(pECIDReg->EC[2] & 1 << 16) ) {
		pECIDReg->EC[2];
	}	// wait efuse ready

	CBOOL IsSecure = !!(pECIDReg->SJTAG[0] | pECIDReg->SJTAG[1] |
			pECIDReg->SJTAG[2] | pECIDReg->SJTAG[3]);

	if (IsSecure) {
		option |= 1 << DECRYPT;

		// copy secure jtag hash to aes secure key for secure boot decrypt.
		pECIDReg->CRAESKEY[0] = pECIDReg->SJTAG[0];
		pECIDReg->CRAESKEY[1] = pECIDReg->SJTAG[1];
		pECIDReg->CRAESKEY[2] = pECIDReg->SJTAG[2];
		pECIDReg->CRAESKEY[3] = pECIDReg->SJTAG[3];
	}
#endif


#ifdef NXP5430
#if 0
	U32 eRSTCFG = 1 << BOOTCFGUSE | 0 << VALIDFIELD | 0 << BOOTHALT |
		0 << NOBOOTMSG | 0 << USE_SDFS | 1 << NEXTTRYPORT |
		0 << PORTNUMBER | 0 << BOOTMODE;
#else
	U32 eRSTCFG = *(volatile U32 *)0x4FFFFE54;
#endif
#endif
#ifdef NXP5540
	U32 eRSTCFG = pECIDReg->RSTCFG;
#endif

	// check low boot config written and valid
	if ((eRSTCFG & 0x3 << VALIDFIELD) == 0x2 << VALIDFIELD) {
		eBootOption = eRSTCFG & 0x3FFF;
		option = (option & 1 << DECRYPT) | eBootOption;
	} else {
		// check high boot config and valid
		eRSTCFG >>= 16;
		if ((eRSTCFG & 0x3 << VALIDFIELD) == 0x2 << VALIDFIELD) {
			eBootOption = eRSTCFG & 0x3FFF;
			option = (option & 1 << DECRYPT) | eBootOption;
		} else {
			// any efuse value does not written.
			// ext rstcfg has no next port information.
			eBootOption = 0x3 << NEXTTRYPORT;	// 3: no next try
			option |= eBootOption;
		}
	}


	SetBootOption(option);	// save boot option to system register.

//--------------------------------------------------------------------------
// Debug Console
//--------------------------------------------------------------------------
	DebugInit(3);

	buildinfo();

	// mmu is enabled when you have some problem, you must check table addr.
	enable_mmu_el3((option & 1 << ICACHE)? 1 << 0 : 0);

	printf("Boot Option: %02X(%X,%X)\r\n", option, OrgBootOption, eRSTCFG);

	// external usb boot is top priority, always first checked.
	if ((OrgBootOption & 0x7 << BOOTMODE) == 1) {
		SetBootOption(option);	// save boot option to system register.
		goto lastboot;
	}

	if (option & 1 << BOOTHALT)
		while (1)
			__asm__ __volatile__ ("wfi");

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
			printf("no support mode(%x)\r\n", option);
		case USBBOOT:
			break;
		case SDBOOT :	// iSDHCBOOT (SD/MMC/eSD/eMMC)
		case EMMCBOOT :
			Result = iSDXCBOOT(option);
			break;
		case NANDECBOOT :
			Result = iNANDBOOTEC(option);
			break;
		case GMACBOOT:
			break;
		}

		if (CTRUE == Result)
			break;

		U32 next_port = (option >> NEXTTRYPORT) & 0x3;
		if (3 == next_port)
			goto lastboot;

		option = OrgBootOption & ~0x7UL;
		option = OrgBootOption & ~(0x3UL << PORTNUMBER);
		option |= next_port << PORTNUMBER;

		if (option & 1 << USE_SDFS)
			Result = iSDXCFSBOOT(option);
		else
			Result = iSDXCBOOT(option);

		if (CTRUE == Result)
			break;

lastboot:
		iUSBBOOT(option);
	} while (0);


	struct nx_bootheader *pbh = (struct nx_bootheader *)BASEADDR_SRAM;

	Dcache_flush_range((U64)pbh, pbh->bi.LoadSize +
					sizeof(struct nx_bootheader));

	printf("Launch to aarch%d secure %s mode 0x%X\r\n",
			(pbh->bi.sel_arch == 1) ? 32 : 64,
			(pbh->bi.sel_arch == 1) ? "svc" : "EL1",
			pbh->bi.StartAddr);

	U32 scr_el3 = GetSCR_EL3();
	scr_el3 &= ~(SCR_NS_BIT | SCR_RW_BIT | SCR_FIQ_BIT | SCR_IRQ_BIT |
			SCR_ST_BIT | SCR_HCE_BIT);
	U32 spsr_el3;
	if (pbh->bi.sel_arch == 0) {
		scr_el3 |= SCR_RW_BIT;	// low level is aarch64
		spsr_el3 = SPSR_64(MODE_EL1, MODE_SP_ELX, DISABLE_ALL_EXCEPTIONS);
	} else {
		spsr_el3 = SPSR_MODE32(MODE32_svc, SPSR_T_ARM,
				SPSR_E_LITTLE,
				DAIF_FIQ_BIT |
				DAIF_IRQ_BIT |
				DAIF_ABT_BIT);
	}

	SetSCR_EL3(scr_el3);

	if (pbh->bi.sel_arch == 0xFF) {
		void (*pLaunch)(void) = (void(*)(void))pbh->bi.StartAddr;
		pLaunch();
	} else
		EnterLowLevel((U32*)pbh->bi.StartAddr, spsr_el3);
}
