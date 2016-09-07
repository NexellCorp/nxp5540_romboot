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


/* ========================= rst cfg =====================*/
#define BOOTMODE		0

#define EMMCBOOT		0
#define USBBOOT			1
#define SDFSBOOT		2
#define SDBOOT			3
#define NANDECBOOT		4
#define SPIBOOT			5
#define GMACBOOT		6
#define STATIC			7


#define PORTNUMBER		5

#define SERIALFLASHADDR		3	// 0: 3 step 1: 4 step
#define SERIALFLASHSPEED	4	// 0: 1MHz, 1: 16MHz
#define SELSPIPORT		5	// 0, 1, 2

#define eMMCBOOTMODE		3	// 0: cmd line low, 1: boot cmd(0xFFFFFFFA)
#define SDXCPARTITION		4	//
#define SELSDPORT		5	// 0, 1, 2: port number, 3: hispeed p 0

#define NANDADDRSTEP		3	// small: 0:3, 1:4, large: 0:4, 1:5
#define NANDTYPE		4	// 0: small, 1: large
#define NANDPAGE		5	// 0: 2k, 1:4K, 2:8K, 3:16K ~

#define ICACHE			7	// rstcfg only. 0: disable, 1: enable
#define COREVOLTAGE		8	// rstcfg only. 0: 1.0V, 1:1.1V


/* ========================= efuse =====================*/

#define USE_SDFS		9	// 0: sector read, 1: file read

#define NEXTTRYPORT		10	// 0, 1, 2: port number, 3: not try


#define NOBOOTMSG		12	// 0: boot message, 1: no boot message
#define BOOTHALT		13	// must be zero
#define VALIDFIELD		14	// 0: valid, 1: invalid
#define BOOTCFGUSE		15	// 0: not use, 1: use

#define DECRYPT			16	// virtual flag bit.

#endif
