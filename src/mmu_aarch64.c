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
 *	File            : mmu_aarch64.c
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.28 Hans create
 */
#include "nx_type.h"
#include "libarm.h"
#include "mmu_aarch64.h"

						
#define TTBR0_EL3_L0	0x70000000
#define TTBR0_EL3_L1	0x70010000
#define TTBR0_EL3_L2	0x70020000
#define TTBR0_EL3_L3	0x70030000

static inline U64 GetTT_Base(U32 table_level)
{
	U64 llp_ttbr = CNULL;

	switch (table_level) {
	case 0: llp_ttbr = (U64)TTBR0_EL3_L0; break;
	case 1: llp_ttbr = (U64)TTBR0_EL3_L1; break;
	case 2: llp_ttbr = (U64)TTBR0_EL3_L2; break;
	case 3: llp_ttbr = (U64)TTBR0_EL3_L3; break;
	}

	while(llp_ttbr==CNULL);

	return llp_ttbr;
}

static inline U32 GetTT_GranuleSize(void)
{
	U32 u_gsize = (GetTCR_EL3() >> 14) & 0x3;

	/* TG0[15:14]  =b00  granule size. b00 4KB, b01 64KB, b10 16KB */
	switch (u_gsize) {
	case 0: u_gsize = 0x1000; break;	/* 4KB */
	case 1: u_gsize = 0x10000; break;	/* 64KB */
	case 2: u_gsize = 0x4000; break;	/* 16KB */		
	default: break;
	}

	return u_gsize;
}

static inline void SetTCR_default(void)
{
	U64 ll_tempTCR = 0;
	ll_tempTCR |= (0L<<20); // TIB0 - Top byte not ignored
	ll_tempTCR |= (1L<<16); // PS - 36bit/64G
	ll_tempTCR |= (0L<<14); // TG0 - 4KB granule size
	ll_tempTCR |= (3L<<12); // SH0 - Inner shareable table walk
	ll_tempTCR |= (1L<<10); // OGRN0 - Outer WriteBack WriteAlloc Cacheable
	ll_tempTCR |= (1L<<8);  // IGRN0 - Inner WriteBack WriteAlloc Cacheable
	ll_tempTCR |= (28L<<0); // T0SZ - 2^(64-28) region size (36bit addressing)
	SetTCR_EL3(ll_tempTCR);
}

/*****************************************************************************
* AArch64 entry size for each granule size
* ---------------
* 4KB Granule
* L0 - VA[47:39] Pointer to L1 table (no block entry)
* L1 - VA[38:30] Pointer to L2 table / Base address of 1GB Block (IPA)
* L2 - VA[29:21] Pointer to L3 table / Base address of 2MB Block (IPA)
* L3 - VA[20:12] Base address of 4KB Block (IPA)
* ---------------
* 16KB Granule
* L0 - VA[47]    Pointer to L1 table (no block entry)
* L1 - VA[46:36] Pointer to L2 table / Base address of 64GB Block (IPA)
* L2 - VA[35:25] Pointer to L3 table / Base address of 32MB Block (IPA)
* L3 - VA[24:14] Base address of 16KB Block (IPA)
* ---------------
* 64KB Granule
* L0 -           No Level 0
* L1 - VA[47:42] Pointer to L2 table (no block entry)
* L2 - VA[41:29] Pointer to L3 table / Base address of 512MB Block (IPA)
* L3 - VA[28:16] Base address of 64KB Block (IPA)
*****************************************************************************/

static inline U32 GetTT_BlockSize(U32 table_level)
{
	U32 n_entry, gn, u_size;	

	gn = GetTT_GranuleSize();
	n_entry = (gn >> 3); /* divide by 8(64bit) */

	switch (table_level) {
	case 1: u_size = gn;                 break;
	case 2: u_size = gn*n_entry;         break;
	case 3: u_size = gn*n_entry*n_entry; break;
	default:  break;
	}
	return u_size;
}


static void BuildTransTable(U64 VaStart, U64 VaEnd, U64 PaBase, U64 Attr)
{
	register volatile U64* pTT;
	register U64 ll_vs, ll_ve, ll_pb;
	register U32 i, NumofEntry;
	register U32 L2BlkSize;//, GrSize;
	register U64 AttrIdx;

	L2BlkSize = GetTT_BlockSize(MMU_AARCH64_LEVEL_2);

	ll_vs = (VaStart/L2BlkSize)*L2BlkSize;		// align to block size
	ll_ve = (VaEnd  /L2BlkSize)*L2BlkSize;		// align to block size
	ll_pb = (PaBase /L2BlkSize)*L2BlkSize;		// align to block size

	NumofEntry = (ll_ve-ll_vs)/L2BlkSize;

	if(VaEnd % L2BlkSize)
		NumofEntry++;

	pTT = (U64*)GetTT_Base(MMU_AARCH64_LEVEL_2) + (ll_vs/L2BlkSize);

	AttrIdx = Attr;
	for(i = 0; i < NumofEntry; i++)
		*pTT++ = (ll_pb + (L2BlkSize * i)) | AttrIdx;
}
void SetMMUTableDefault(void)
{
	register U32 i, tablecount, granulesize;
	register U64* ll_ttb_l1, *ll_ttb_l2;

	SetMAIR_EL3(0xFF44);

	SetTCR_default();

	granulesize = GetTT_GranuleSize();

	ll_ttb_l1 = (U64*)GetTT_Base(MMU_AARCH64_LEVEL_1);
	while (0 != (U64)ll_ttb_l1 % granulesize)
		;

	ll_ttb_l2 = (U64*)GetTT_Base(MMU_AARCH64_LEVEL_2);
	while (0 != (U64)ll_ttb_l2 % granulesize)
		;

	tablecount = granulesize / sizeof(U64);
	for (i = 0; i < tablecount; i++)
		ll_ttb_l1[i] = 0;

	for (i = 0; i < 8; i++)	// EL3 Level 1 4KB Block Size (each table cover 1GB)
		ll_ttb_l1[i] = ((U64)ll_ttb_l2 + i * granulesize) | TT_S1_TABLE;

	//	while(1);
#ifdef NXP5430
	BuildTransTable((U64)0x00000000, (U64)0xFFFFFFFF, (U64)0x00000000, (U64)TT_S1_FAULT);
	BuildTransTable((U64)0x50000000, (U64)0x500FFFFF, (U64)0x50000000, (U64)TT_FLASH);

	BuildTransTable((U64)0x60000000, (U64)0x600FFFFF, (U64)0x60000000, (U64)TT_RAM);
	BuildTransTable((U64)0x70000000, (U64)0x700FFFFF, (U64)0x70000000, (U64)TT_RAM);
	BuildTransTable((U64)0x40000000, (U64)0x4FFFFFFF, (U64)0x40000000, (U64)TT_PERIPHERAL);
	BuildTransTable((U64)0xC0000000, (U64)0xFFDFFFFF, (U64)0xC0000000, (U64)TT_PERIPHERAL);
#endif
#ifdef NXP5540
	BuildTransTable((U64)0x00000000, (U64)0xFFFFFFFF, (U64)0x00000000, (U64)TT_S1_FAULT);
	BuildTransTable((U64)0x00000000, (U64)0x000FFFFF, (U64)0x00000000, (U64)TT_FLASH);

	BuildTransTable((U64)0x10000000, (U64)0x100FFFFF, (U64)0x10000000, (U64)TT_RAM);
	BuildTransTable((U64)0x20000000, (U64)0x3FFFFFFF, (U64)0x20000000, (U64)TT_PERIPHERAL);
#endif
}


void StartMMUnCache(CBOOL mmu, CBOOL icache, CBOOL dcache)
{
	volatile U64 ll_sctlr;

	SetTTBR0_EL3(GetTT_Base(MMU_AARCH64_LEVEL_1));

	__asm__ __volatile__ ("DSB sy");
	__asm__ __volatile__ ("ISB sy");

	InvalidateTLB_All();
	InvalidateIcache_All();

	ll_sctlr = GetSCTLR_EL3();

	if (icache)	ll_sctlr |=  (1L<<12);
	else		ll_sctlr &= ~(1L<<12);
	if (dcache)	ll_sctlr |=  (1L<<2);
	else		ll_sctlr &= ~(1L<<2);
	if (mmu)	ll_sctlr |=  (1L<<0);
	else		ll_sctlr &= ~(1L<<0);

	SetSCTLR_EL3(ll_sctlr);
}

