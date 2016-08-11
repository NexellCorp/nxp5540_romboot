//;-------------------------------------------------------------------------------
//;
//;	Copyright (C) 2009 Nexell Co., All Rights Reserved
//;	Nexell Co. Proprietary & Confidential
//;
//;	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//;	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//;	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//;	FOR A PARTICULAR PURPOSE.
//;
//;	Module		:
//;	File		:
//;	Description	: core define
//;	Author		: Hans
//;	History		:
//;		2013-01-10	Hans, for NXP5430
//;		2016-08-10	Hans, for NXP5540
//;-------------------------------------------------------------------------------

#ifndef NX_BOOTOPTION_H
#define NX_BOOTOPTION_H

#define EMMCBOOT            0
#define eMMCBOOT			0
#define	USBBOOT             1
#define	SDFSBOOT            2
//#define USBHOST             2
#define	SDBOOT              3
#define	NANDECBOOT          4
#define	SPIBOOT             5
#define UARTBOOT            6

#define PORTNUMBER	        5
#define PORTNUMBER1	        6

#define SELSPIPORT			PORTNUMBER
#define SELSPIPORT1			PORTNUMBER1
#define SERIALFLASHADDR		3
#define SERIALFLASHSPEED	4

#define SELUARTPORT			PORTNUMBER
#define UARTBAUD			6

#define SELSDPORT			PORTNUMBER
#define SELSDPORT1			PORTNUMBER1
#define eMMCBOOTMODE		3
#define SDXCPARTITION		4


#define BOOTMODE			0

//#define SELCS				PORTNUMBER
#define NANDTYPE			3
#define NANDPAGE0			5
#define NANDPAGE1			6

#define NEXTTRY				16
#define USE_FS				20
#define NEXTPORT			18

//#define OTG_VBUS_CHECK		17

#define DECRYPT				14
#define ICACHE				15

//#define COREVOLTAGE			23
#define COREVOLTAGE         8

#endif
