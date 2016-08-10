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
#include <nx_debug2.h>

#include <nx_chip.h>

#include <nx_clkpwr.h>
#include <nx_alive.h>
#include <nx_gpio.h>

struct NX_GPIO_RegisterSet (* const pGPIOReg)[1] =
	(struct NX_GPIO_RegisterSet (*)[])PHY_BASEADDR_GPIOA_MODULE;
struct NX_ALIVE_RegisterSet * const pALIVEReg =
	(struct NX_ALIVE_RegisterSet *)PHY_BASEADDR_ALIVE_MODULE;

//------------------------------------------------------------------------------
void iROMBOOT(U32 OrgBootOption)
{
	void (*pLaunch)(void) = (void(*)(void))BASEADDR_SRAM;
	CBOOL Result = CFALSE;
	U32 BootState = 0;
	U32 option = OrgBootOption;

	//--------------------------------------------------------------------------
	// Power Management Control
	//--------------------------------------------------------------------------
	// Enable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 1;

	pALIVEReg->VDDCTRLSETREG	= 0x00000003;

	// Disable writing data to ALIVE registers.
	pALIVEReg->ALIVEPWRGATEREG 	= 0;

	//--------------------------------------------------------------------------
	// Debug Console
	//--------------------------------------------------------------------------
	#if defined(NX_DEBUG)
	DebugInit();

	DebugPutString( "\n\n" );
	DebugPutString( "--------------------------------------------------------------------------------\n" );
	DebugPutString( " iROMBOOT by Nexell Co. : Built on " );
	DebugPutString( __DATE__ );
	DebugPutString( " " );
	DebugPutString( __TIME__ );
	DebugPutString( "\n" );
	DebugPutString( "--------------------------------------------------------------------------------\n\n" );
	#endif	// NX_DEBUG


	do {
		//--------------------------------------------------------------------------
		// iROMBOOT mode : option [2:0]
		//--------------------------------------------------------------------------
		switch ((option >> BOOTMODE) & 0x7) {
		case SDFSBOOT :	// iSDHCFSBOOT (SD/MMC/eSD/eMMC)
		{
			extern CBOOL iSDXCFSBOOT(U32 option);
			Result = iSDXCFSBOOT(option);
			break;
		}
		default:
		case USBBOOT :	// iUSBBOOT
		{
			extern CBOOL iUSBBOOT(U32 option);
			Result = iUSBBOOT(option);
			break;
		}
		case SPIBOOT :	// iSPIBOOT (Serial Flash memory)
		{
			extern CBOOL iSPIBOOT(U32 option);
			Result = iSPIBOOT(option);
			break;
		}
		case SDBOOT :	// iSDHCBOOT (SD/MMC/eSD/eMMC)
		case EMMCBOOT :	// iSDHCBOOT (SD/MMC/eSD/eMMC)
		{
			extern CBOOL iSDXCBOOT(U32 option);
			Result = iSDXCBOOT(option);
			break;
		}
		case NANDECBOOT :	// iNANDBOOT with Error Correction
		{
			extern CBOOL iNANDBOOTEC(U32 option);

			Result = iNANDBOOTEC(option);
			break;
		}
		}

		if (Result)
			break;

		option = OrgBootOption & ~0x7UL;
		if (BootState == 0) {
			BootState = 1;
			if (option & 1<<NEXTTRY) {
				if (((OrgBootOption & 0x7) == SDBOOT) ||
					((OrgBootOption & 0x7) == SDFSBOOT)) {
					if (OrgBootOption & 1 << PORTNUMBER1) {// port 2 or 2 High speed
						option &= ~(1 << PORTNUMBER1);
						if (option & 1 << NEXTPORT)
							option &= ~(1 << PORTNUMBER);		// 2 or 3 => 0
						else
							option |= 1 << PORTNUMBER;		// 2 or 3 => 1
					} else {
						if (OrgBootOption & 1 << PORTNUMBER) {		// port 1
							if (option & 1 << NEXTPORT)
								option |= 1<<PORTNUMBER1;	// 1 => 2
							option &= ~(1 << PORTNUMBER); 	// 1 => 0
						} else {		// port 0
							if (option & 1 << NEXTPORT)
								option |= 1 << PORTNUMBER;	// 0 => 1
							else
								option |= 1 << PORTNUMBER1;	// 0 => 2
						}
					}
				} else {
					if ((OrgBootOption & 0x7) != NANDECBOOT)
						option &= ~(1 << PORTNUMBER1);
					if (option & 1 << NEXTPORT) {
						option ^= 1 << PORTNUMBER;
					}
				}

				if (option & 1 << USE_FS)
					option |= SDFSBOOT;
				else
					option |= SDBOOT;
			}
		} else {
			option |= USBBOOT;
		}

	} while(1);


	pLaunch();
}
