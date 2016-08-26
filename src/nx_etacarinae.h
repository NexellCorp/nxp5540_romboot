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
#define A_Bit			(1 << 8)	//; when A bit is set, Abort is disabled
#define I_Bit			(1 << 7)	//; when I bit is set, IRQ is disabled
#define F_Bit			(1 << 6)	//; when F bit is set, FIQ is disabled
#endif

#ifdef aarch64
#define AArch64_EL3_SP3		0x0D		// EL3h
#define AArch64_EL3_SP0		0x0C		// EL3t
#define AArch64_EL2_SP2		0x09		// EL2h
#define AArch64_EL2_SP0		0x08		// EL2t
#define AArch64_EL1_SP1		0x05		// EL1h
#define AArch64_EL1_SP0		0x04		// EL1t
#define AArch64_EL0_SP0		0x00

#define A_Bit			(1 << 2)	//; when A bit is set, Abort is disabled
#define I_Bit			(1 << 1)	//; when I bit is set, IRQ is disabled
#define F_Bit			(1 << 0)	//; when F bit is set, FIQ is disabled

#define SCTLR_M_BIT		(1 << 0)
#define SCTLR_A_BIT		(1 << 1)
#define SCTLR_C_BIT		(1 << 2)
#define SCTLR_SA_BIT		(1 << 3)
#define SCTLR_I_BIT		(1 << 12)
#define SCTLR_WXN_BIT		(1 << 19)
#define SCTLR_EE_BIT		(1 << 25)

#define CPACR_EL1_FPEN(x)	(x << 20)
#define CPACR_EL1_FP_TRAP_EL0	0x1
#define CPACR_EL1_FP_TRAP_ALL	0x2
#define CPACR_EL1_FP_TRAP_NONE	0x3

#define SCR_RES1_BITS		((1 << 4) | (1 << 5))
#define SCR_TWE_BIT		(1 << 13)
#define SCR_TWI_BIT		(1 << 12)
#define SCR_ST_BIT		(1 << 11)
#define SCR_RW_BIT		(1 << 10)
#define SCR_SIF_BIT		(1 << 9)
#define SCR_HCE_BIT		(1 << 8)
#define SCR_SMD_BIT		(1 << 7)
#define SCR_EA_BIT		(1 << 3)
#define SCR_FIQ_BIT		(1 << 2)
#define SCR_IRQ_BIT		(1 << 1)
#define SCR_NS_BIT		(1 << 0)
#define SCR_VALID_BIT_MASK	0x2f8f

#define TCPAC_BIT               (1 << 31)
#define TTA_BIT                 (1 << 20)
#define TFP_BIT                 (1 << 10)

#define HCR_RW_BIT		(1ull << 31)
#define HCR_AMO_BIT		(1 << 5)
#define HCR_IMO_BIT		(1 << 4)
#define HCR_FMO_BIT		(1 << 3)

#define TCR_EL3_RES1		((1UL << 31) | (1UL << 23))
#define TCR_EL1_IPS_SHIFT	32
#define TCR_EL3_PS_SHIFT	16

#define TCR_PS_BITS_4GB		(0x0)
#define TCR_PS_BITS_64GB	(0x1)
#define TCR_PS_BITS_1TB		(0x2)
#define TCR_PS_BITS_4TB		(0x3)
#define TCR_PS_BITS_16TB	(0x4)
#define TCR_PS_BITS_256TB	(0x5)

#define ADDR_MASK_48_TO_63	0xFFFF000000000000UL
#define ADDR_MASK_44_TO_47	0x0000F00000000000UL
#define ADDR_MASK_42_TO_43	0x00000C0000000000UL
#define ADDR_MASK_40_TO_41	0x0000030000000000UL
#define ADDR_MASK_36_TO_39	0x000000F000000000UL
#define ADDR_MASK_32_TO_35	0x0000000F00000000UL

#define TCR_RGN_INNER_NC	(0x0 << 8)
#define TCR_RGN_INNER_WBA	(0x1 << 8)
#define TCR_RGN_INNER_WT	(0x2 << 8)
#define TCR_RGN_INNER_WBNA	(0x3 << 8)

#define TCR_RGN_OUTER_NC	(0x0 << 10)
#define TCR_RGN_OUTER_WBA	(0x1 << 10)
#define TCR_RGN_OUTER_WT	(0x2 << 10)
#define TCR_RGN_OUTER_WBNA	(0x3 << 10)

#define TCR_SH_NON_SHAREABLE	(0x0 << 12)
#define TCR_SH_OUTER_SHAREABLE	(0x2 << 12)
#define TCR_SH_INNER_SHAREABLE	(0x3 << 12)

#define MODE_SP_SHIFT		0x0
#define MODE_SP_MASK		0x1
#define MODE_SP_EL0		0x0
#define MODE_SP_ELX		0x1

#define MODE_RW_SHIFT		0x4
#define MODE_RW_MASK		0x1
#define MODE_RW_64		0x0
#define MODE_RW_32		0x1

#define MODE_EL_SHIFT		0x2
#define MODE_EL_MASK		0x3
#define MODE_EL3		0x3
#define MODE_EL2		0x2
#define MODE_EL1		0x1
#define MODE_EL0		0x0
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

#define USBD_VID		0x2375
#define USBD_PID		0x5540

#define GPIO_GROUP_A		0
#define GPIO_GROUP_B		1
#define GPIO_GROUP_C		2
#define GPIO_GROUP_D		3
#define GPIO_GROUP_E		4
#define GPIO_GROUP_F		5

//#define POLY 0xEDB88320L
#define POLY			0x04C11DB7L    //reverse

#ifdef NXP5430
#define BASEADDR_SRAM		(0x60000000)
#endif
#ifdef NXP5540
#define BASEADDR_SRAM		(0x10000000)
#endif
#define INTERNAL_SRAM_SIZE	(208*1024)      // 208KB
#define SECONDBOOT_FSIZENCRC	(64*1024)
#define SECONDBOOT_FSIZE	(SECONDBOOT_FSIZENCRC-(128/8))
#define SECONDBOOT_STACK	0x1000

#define BASEADDR_NFMEM		(0x0C000000)
#define BASEADDR_DDRSDRAM	(0x40000000)

#endif	/* NX_ETACARINAE_H */
