//;-------------------------------------------------------------------------------
//;
//; Copyright (C) 2009 Nexell Co., All Rights Reserved
//; Nexell Co. Proprietary & Confidential
//;
//; NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//; AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//; BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//; FOR A PARTICULAR PURPOSE.
//;
//; Module      :
//; File        :
//; Description : core define
//; Author      : Hans
//; History     :
//;     2014-01-12  Hans, for peridot
//;	2016-08-10  Hans, for etacarinae
//;-------------------------------------------------------------------------------

#ifndef NX_ETACARINAE_H
#define NX_ETACARINAE_H



#define PRIMARY_CPU 0
//;==================================================================
//; Porting defines
//;==================================================================
#define NX_CLKSRCPLL0_FREQ	(550000000UL)
#define NX_CLKSRCPLL1_FREQ	(147456000UL)
#define NX_CLKSRCPLL2_FREQ	( 96000000UL)
#define NX_CLKSRCPLL3_FREQ	(125000000UL)

#define USBD_VID		0x2375
#ifdef NXP5430
#define USBD_PID		0x5430
#endif
#ifdef NXP5540
#define USBD_PID		0x5540
#endif

#define GPIO_GROUP_A		0
#define GPIO_GROUP_B		1
#define GPIO_GROUP_C		2
#define GPIO_GROUP_D		3
#define GPIO_GROUP_E		4
#define GPIO_GROUP_F		5

#define POLY 0xEDB88320L
//#define POLY			0x04C11DB7L    //reverse

#ifdef NXP5430
#define BASEADDR_SRAM		(0x60000000)
#endif
#ifdef NXP5540
#define BASEADDR_SRAM		(0x10000000)
#endif
#define INTERNAL_SRAM_SIZE	(208*1024)      // 208KB
#define SECONDBOOT_FSIZENCRC	(64*1024)
#define SECONDBOOT_FSIZE	(SECONDBOOT_FSIZENCRC-(128/8))
#define SECONDBOOT_STACK	0x2000

#define BASEADDR_NFMEM		(0x0C000000)
#define BASEADDR_DDRSDRAM	(0x40000000)

#endif	/* NX_ETACARINAE_H */
