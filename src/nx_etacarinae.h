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


//; Standard definitions of mode bits and interrupt (I & F) flags in PSRs

#define Mode_USR	0x10
#define Mode_FIQ	0x11
#define Mode_IRQ	0x12
#define Mode_SVC	0x13
#define Mode_MON	0x16
#define Mode_ABT	0x17
#define Mode_HYP	0x1A
#define Mode_UNDEF	0x1B
#define Mode_SYS	0x1F

#ifdef aarch32
#define A_Bit               (1<<8)              //; when A bit is set, Abort is disabled
#define I_Bit               (1<<7)              //; when I bit is set, IRQ is disabled
#define F_Bit               (1<<6)              //; when F bit is set, FIQ is disabled
#endif

#ifdef aarch64
#define AArch64_EL3_SP3     0x0D    // EL3h
#define AArch64_EL3_SP0     0x0C    // EL3t
#define AArch64_EL2_SP2     0x09    // EL2h
#define AArch64_EL2_SP0     0x08    // EL2t
#define AArch64_EL1_SP1     0x05    // EL1h
#define AArch64_EL1_SP0     0x04    // EL1t
#define AArch64_EL0_SP0     0x00

#define A_Bit               (1<<2)              //; when A bit is set, Abort is disabled
#define I_Bit               (1<<1)              //; when I bit is set, IRQ is disabled
#define F_Bit               (1<<0)              //; when F bit is set, FIQ is disabled
#endif


//;-------------------------------------------------------------------------------
//; Control register 1 format bit definition
//;-------------------------------------------------------------------------------
#define BIT1_XP		(1 << 23)	//; Subpage AP
#define BIT1_U		(1 << 22)	//; Enables unaligned data access
#define BIT1_L4		(1 << 15)	//; for ARM4V architecture
#define BIT1_RR		(1 << 14)	//; Replacement strategy for ICache & DCache
#define BIT1_V		(1 << 13)	//; Loaction of exception vectors
#define BIT1_I		(1 << 12)	//; ICache enable/disable
#define BIT1_Z		(1 << 11)	//; Branch prediction
#define BIT1_R		(1 <<  9)	//; ROM protection
#define BIT1_S		(1 <<  8)	//; system protection
#define BIT1_B		(1 <<  7)	//; Endianness(Bin/Little : 1/0)
#define BIT1_C		(1 <<  2)	//; DCache enable/disable
#define BIT1_A		(1 <<  1)	//; Alignment fault enable/disable
#define BIT1_M		(1 <<  0)	//; MMU enable/disable

#define PRIMARY_CPU 0
//;==================================================================
//; Porting defines
//;==================================================================
#define NX_CLKSRCPLL0_FREQ	(550000000UL)
#define NX_CLKSRCPLL1_FREQ	(147456000UL)
#define NX_CLKSRCPLL2_FREQ	( 96000000UL)
#define NX_CLKSRCPLL3_FREQ	(125000000UL)

#define USBD_VID	0x2375
#define USBD_PID	0x5540

#define GPIO_GROUP_A	0
#define GPIO_GROUP_B	1
#define GPIO_GROUP_C	2
#define GPIO_GROUP_D	3
#define GPIO_GROUP_E	4
#define GPIO_GROUP_F	5

//#define POLY 0xEDB88320L
#define POLY	0x04C11DB7L    //reverse

//#define BASEADDR_SRAM		(0xFFFF0000)
//#define INTERNAL_SRAM_SIZE	(64*1024)       // 64KB
#define BASEADDR_SRAM		(0x10000000)
#define INTERNAL_SRAM_SIZE	(208*1024)      // 208KB
#define SECONDBOOT_FSIZENCRC	(16*1024)
#define SECONDBOOT_FSIZE	(SECONDBOOT_FSIZENCRC-(128/8))
#define SECONDBOOT_STACK	0x1000

#define BASEADDR_NFMEM		(0x0C000000)
#define BASEADDR_DDRSDRAM	(0x40000000)

#endif	/* NX_ETACARINAE_H */
