/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : romboot
 *	File            : mmu.h
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.28 Hans create
 */

#define TT_S1_TABLE		0x0000000000000003		// NSTable=0, PXNTable=0, UXNTable=0, APTable=0
#define TT_BLOCK		0x0000000000000001

#define MAIR_EL3_ATTR	0x000000000000FF44

#define TT_S1_NON_SHARED	(0 << 8)		// Non-shareable
#define TT_S1_INNER_SHARED	(3 << 8)		// Inner-shareable
#define TT_S1_OUTER_SHARED	(2 << 8)		// Outer-shareable

#define TT_S1_PRIV_RW	(0x0)
#define TT_S1_PRIV_RO	(0x2 << 6)
#define TT_S1_USER_RW	(0x1 << 6)
#define TT_S1_USER_RO	(0x3 << 6)

#define TT_S1_UXN	(1L<<54)	// UXN:Unprivileged Execute-never(stage 1 of EL1&0), XN:Execlute-never
#define TT_S1_PXN	(1L<<53)	// privileged Execute-never (used only for stage 1 of EL1&0)
#define TT_S1_nG	(1L<<11)	// the not global bit. Determines whether the TLB entry applies to all ASID values or only to the current ASID. (valid only for EL1&0)
#define TT_S1_NS	(1L<<5)		// Non-secure bit

#define TT_S1_FAULT		0x0000000000000000
#define TT_S1_NORMAL_NO_CACHE	0x0000000000000401		// Index[4:2] = 0, AF[10]=1
#define TT_S1_NORMAL_WBWA	0x0000000000000405		// Index[4:2] = 1, AF[10]=1
#define TT_S1_DEVICE_nGnRnE	0x0000000000000409		// Index[4:2] = 2, AF[10]=1

#define TT_FLASH	(TT_S1_NORMAL_WBWA|TT_S1_INNER_SHARED|TT_S1_PRIV_RO)
#define TT_RAM		(TT_S1_NORMAL_WBWA|TT_S1_INNER_SHARED|TT_S1_PRIV_RW)
#define TT_NC_RAM	(TT_S1_NORMAL_NO_CACHE|TT_S1_NON_SHARED|TT_S1_PRIV_RW)
#define TT_PERIPHERAL	(TT_S1_DEVICE_nGnRnE|TT_S1_PXN|TT_S1_UXN|TT_S1_PRIV_RW)

enum MMU_AARCH64_LEVEL
{
	MMU_AARCH64_LEVEL_0 = 0,
	MMU_AARCH64_LEVEL_1 = 1,
	MMU_AARCH64_LEVEL_2 = 2,
	MMU_AARCH64_LEVEL_3 = 3
};

