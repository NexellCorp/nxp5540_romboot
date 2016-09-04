/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : Base
 *	File            : mmu_aarch64.c
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.29 Hans create
 */


#include "nx_type.h"
//#include "nx_etacarinae.h"
#include "lib_aarch64.h"
#include "atf_mmu_aarch64.h"
#include "printf.h"


#define UNSET_DESC      ~0ul

#define ADDR_SPACE_SIZE                 (1ull << 32)
#define NUM_L1_ENTRIES	(ADDR_SPACE_SIZE >> L1_XLAT_ADDRESS_SHIFT)

//#define GEN_PG

#ifdef GEN_PG
static uint64_t l1_xlation_table[NUM_L1_ENTRIES]
			__aligned(NUM_L1_ENTRIES * sizeof(uint64_t));
static uint64_t xlat_tables[MAX_XLAT_TABLES][XLAT_TABLE_ENTRIES]
			__aligned(XLAT_TABLE_SIZE);

static unsigned next_xlat;
static unsigned long max_pa;
static unsigned long max_va;
static unsigned long tcr_ps_bits;

/*
 * Array of all memory regions stored in order of ascending base address.
 * The list is terminated by the first entry with size == 0.
 */
static mmap_region_t mmap[MAX_MMAP_REGIONS + 1];


static void print_mmap(void)
{
	printf("mmap:\n");
	mmap_region_t *mm = mmap;
	while (mm->size) {
		printf(" %016x %016x %16x %x\n", mm->base_va,
				mm->base_pa, mm->size, mm->attr);
		++mm;
	};
	printf("\n");
}
/*
 *  * Copy @len bytes from @src to @dst
 *   */
void *memcpy(void *dst, const void *src, size_t len)
{
	const char *s = src;
	char *d = dst;

	while (len--)
		*d++ = *s++;

	return dst;
}
/*
 *  * Move @len bytes from @src to @dst
 *   */
void *memmove(void *dst, const void *src, size_t len)
{
	/*
	 * The following test makes use of unsigned arithmetic overflow to
	 * more efficiently test the condition !(src <= dst && dst < str+len).
	 * It also avoids the situation where the more explicit test would give
	 * incorrect results were the calculation str+len to overflow (though
	 * that issue is probably moot as such usage is probably undefined
	 * behaviour and a bug anyway.
	 */
	if ((size_t)dst - (size_t)src >= len) {
		/* destination not in source data, so can safely use memcpy */
		return memcpy(dst, src, len);
	} else {
		/* copy backwards... */
		const char *end = dst;
		const char *s = (const char *)src + len;
		char *d = (char *)dst + len;
		while (d != end)
			*--d = *--s;
	}
	return dst;
}

void mmap_add_region(unsigned long base_pa, unsigned long base_va,
		unsigned long size, unsigned attr)
{
	mmap_region_t *mm = mmap;
	mmap_region_t *mm_last = mm + ARRAY_SIZE(mmap) - 1;
	unsigned long pa_end = base_pa + size - 1;
	unsigned long va_end = base_va + size - 1;

	if (!size)
		return;

	/* Find correct place in mmap to insert new region */
	while (mm->base_va < base_va && mm->size)
		++mm;

	/* Make room for new region by moving other regions up by one place */
	memmove(mm + 1, mm, (uintptr_t)mm_last - (uintptr_t)mm);

	mm->base_pa = base_pa;
	mm->base_va = base_va;
	mm->size = size;
	mm->attr = attr;

	if (pa_end > max_pa)
		max_pa = pa_end;
	if (va_end > max_va)
		max_va = va_end;
}

void mmap_add(const mmap_region_t *mm)
{
	while (mm->size) {
		mmap_add_region(mm->base_pa, mm->base_va, mm->size, mm->attr);
		++mm;
	}
}
static unsigned long mmap_desc(
	unsigned attr,
	unsigned long addr_pa,
	unsigned level)
{
	unsigned long desc = addr_pa;

	desc |= level == 3 ? TABLE_DESC : BLOCK_DESC;

	desc |= attr & MT_NS ? LOWER_ATTRS(NS) : 0;

	desc |= attr & MT_RW ? LOWER_ATTRS(AP_RW) : LOWER_ATTRS(AP_RO);

	desc |= LOWER_ATTRS(ACCESS_FLAG);

	if (attr & MT_MEMORY) {
		desc |= LOWER_ATTRS(ATTR_IWBWA_OWBWA_NTR_INDEX | ISH);
		if (attr & MT_RW)
			desc |= UPPER_ATTRS(XN);
	} else {
		desc |= LOWER_ATTRS(ATTR_DEVICE_INDEX | OSH);
		desc |= UPPER_ATTRS(XN);
	}

	printf(attr & MT_MEMORY ? "MEM" : "DEV");
	printf(attr & MT_RW ? "-RW" : "-RO");
	printf(attr & MT_NS ? "-NS" : "-S");
	printf(desc & UPPER_ATTRS(XN) ? "-XN" : "-EX");

	return desc;
}
static int mmap_region_attr(
	mmap_region_t *mm,
	unsigned long base_va,
	unsigned long size)
{
	int attr = mm->attr;

	for (;;) {
		++mm;

		if (!mm->size)
			return attr; /* Reached end of list */

		if (mm->base_va >= base_va + size)
			return attr; /* Next region is after area so end */

		if (mm->base_va + mm->size <= base_va)
			continue; /* Next region has already been overtaken */

		if ((mm->attr & attr) == attr)
			continue; /* Region doesn't override attribs so skip */

		attr &= mm->attr;

		if (mm->base_va > base_va ||
				mm->base_va + mm->size < base_va + size)
			return -1; /* Region doesn't fully cover our area */
	}
}

static mmap_region_t *init_xlation_table(
		mmap_region_t *mm,
		unsigned long base_va,
		unsigned long *table, unsigned level)
{
	unsigned level_size_shift = L1_XLAT_ADDRESS_SHIFT - (level - 1) *
		XLAT_TABLE_ENTRIES_SHIFT;
	unsigned level_size = 1 << level_size_shift;
	unsigned long level_index_mask = XLAT_TABLE_ENTRIES_MASK << level_size_shift;

	printf("New xlat table:\r\n");

	do  {
		unsigned long desc = UNSET_DESC;

		if (mm->base_va + mm->size <= base_va) {
			/* Area now after the region so skip it */
			++mm;
			continue;
		}

		printf("      %016x %8x " + 6 - 2 * level, base_va,
				level_size);

		if (mm->base_va >= base_va + level_size) {
			/* Next region is after area so nothing to map yet */
			desc = INVALID_DESC;
		} else if (mm->base_va <= base_va && mm->base_va + mm->size >=
				base_va + level_size) {
			/* Next region covers all of area */
			int attr = mmap_region_attr(mm, base_va, level_size);
			if (attr >= 0)
				desc = mmap_desc(attr,
						base_va - mm->base_va + mm->base_pa,
						level);
		}
		/* else Next region only partially covers area, so need */

		printf("\r\n");
		if (desc == UNSET_DESC) {
			/* Area not covered by a region so need finer table */
			unsigned long *new_table = xlat_tables[next_xlat++];
			desc = TABLE_DESC | (unsigned long)new_table;

			/* Recurse to fill in new table */
			mm = init_xlation_table(mm, base_va,
					new_table, level + 1);
		}


		*table++ = desc;
		base_va += level_size;
	} while (mm->size && (base_va & level_index_mask));

	return mm;
}
static unsigned int calc_physical_addr_size_bits(unsigned long max_addr)
{
	/* Physical address can't exceed 48 bits */
//	assert((max_addr & ADDR_MASK_48_TO_63) == 0);

	/* 48 bits address */
	if (max_addr & ADDR_MASK_44_TO_47)
		return TCR_PS_BITS_256TB;

	/* 44 bits address */
	if (max_addr & ADDR_MASK_42_TO_43)
		return TCR_PS_BITS_16TB;

	/* 42 bits address */
	if (max_addr & ADDR_MASK_40_TO_41)
		return TCR_PS_BITS_4TB;

	/* 40 bits address */
	if (max_addr & ADDR_MASK_36_TO_39)
		return TCR_PS_BITS_1TB;

	/* 36 bits address */
	if (max_addr & ADDR_MASK_32_TO_35)
		return TCR_PS_BITS_64GB;

	return TCR_PS_BITS_4GB;
}
#endif	// #ifdef GEN_PG

#ifdef NXP5430
extern const U64 l2t0[], l2t1[];
const U64 l1t[4] __attribute__((__aligned__(0x20))) = {
	0x0000000000000000,
//	((U64)l2t0) | 0x3,
	0x0000000050008003, 
	0x0000000000000000, 
//	((U64)l2t1) | 0x3
	0x0000000050007003 
};
#endif
#ifdef NXP5540
extern const U64 l2t0[], l2t1[];
const U64 l1t[4] __attribute__((__aligned__(0x20))) = {
	0x0000000000006003,	/* <============== must be checked by last */
//	((U64)l2t0) | 0x3,
	0x0000000000000000, 
	0x0000000000000000, 
	0x0000000000000000 
};
#endif

#ifdef GEN_PG
void init_xlat_tables(void)
{
	print_mmap();
	init_xlation_table(mmap, 0, l1_xlation_table, 1);
#ifdef NXP5430
	l1t[1] = ((U64)l2t0) | 0x3;
	l1t[3] = ((U64)l2t1) | 0x3;
	printf("pt l2t0: %x, l2t1: %x\r\n", l2t0, l2t1);
#endif
#ifdef NXP5540
	l1t[0] = ((U64)l2t0) | 0x3;
	printf("pt l2t0: %x\r\n", l2t0);
#endif
	printf("max_pa: %x\r\n", max_pa);
	tcr_ps_bits = calc_physical_addr_size_bits(max_pa);
}
#if def NXP5430
#define PREI_MAP_DEVICE		MAP_REGION_FLAT(		\
				0xC0000000,			\
				0x3FE00000,			\
				MT_DEVICE | MT_RW | MT_SECURE)
const mmap_region_t plat_arm_mmap[] = {
	PREI_MAP_DEVICE,
	{0}
};
#endif
#if def NXP5540
#define ROM_MAP_MEMORY		MAP_REGION_FLAT(		\
				0x00000000,			\
				0x00200000,			\
				MT_MEMORY | MT_RO | MT_SECURE)
#define SRAM_MAP_MEMORY		MAP_REGION_FLAT(		\
				0x10000000,			\
				0x00200000,			\
				MT_MEMORY | MT_RW | MT_SECURE)
#define PREI_MAP_DEVICE		MAP_REGION_FLAT(		\
				0x20000000,			\
				0x08000000,			\
				MT_DEVICE | MT_RW | MT_SECURE)
const mmap_region_t plat_arm_mmap[] = {
	ROM_MAP_MEMORY,
	SRAM_MAP_MEMORY,
	PREI_MAP_DEVICE,
	{0}
};
#endif
#endif
void enable_mmu_el3(uint32_t flags)
{
	uint64_t mair, tcr, ttbr;
	uint32_t sctlr;

	/* Set attributes in the right indices of the MAIR */
	mair = MAIR_ATTR_SET(ATTR_DEVICE, ATTR_DEVICE_INDEX);
	mair |= MAIR_ATTR_SET(ATTR_IWBWA_OWBWA_NTR,
			ATTR_IWBWA_OWBWA_NTR_INDEX);
	write_mair_el3(mair);

	/* Invalidate TLBs at the current exception level */
	tlbialle3();

	/* Set TCR bits as well. */
	/* Inner & outer WBWA & shareable + T0SZ = 32 */
	tcr = TCR_SH_INNER_SHAREABLE | TCR_RGN_OUTER_WBA |
	TCR_RGN_INNER_WBA | (64 - __builtin_ctzl(ADDR_SPACE_SIZE));
	tcr |= TCR_EL3_RES1 | (TCR_PS_BITS_4GB << TCR_EL3_PS_SHIFT);
	write_tcr_el3(tcr);

	/* Set TTBR bits as well */
//	ttbr = (uint64_t) l1_xlation_table;
	ttbr = (uint64_t) l1t;
	write_ttbr0_el3(ttbr);

	/* Ensure all translation table writes have drained */
	/* into memory, the TLB invalidation is complete, */
	/* and translation register writes are committed */
	/* before enabling the MMU */
	dsb();
	isb();

	sctlr = read_sctlr_el3();
	sctlr |= SCTLR_WXN_BIT | SCTLR_M_BIT;

	if (flags & DISABLE_DCACHE)
		sctlr &= ~SCTLR_C_BIT;
	else
		sctlr |= SCTLR_C_BIT;

	write_sctlr_el3(sctlr);

	/* Ensure the MMU enable takes effect immediately */
	isb();
}
#ifdef GEN_PG
void arm_configure_mmu_el3(unsigned long total_base,
			unsigned long total_size,
			unsigned long ro_start,
			unsigned long ro_limit)
{
	int i, j;
	next_xlat = 0;
	max_pa = 0;
	max_va = 0;
	tcr_ps_bits = 0;

	for (i = 0; i < NUM_L1_ENTRIES; i++)
		l1_xlation_table[i] = 0;

	for (i = 0; i < MAX_XLAT_TABLES; i++)
		for (j = 0; j < XLAT_TABLE_ENTRIES; j++)
			xlat_tables[i][j] = 0;

	for (i = 0; i < MAX_MMAP_REGIONS; i++) {
		mmap[i].base_pa = 0;
		mmap[i].base_va = 0;
		mmap[i].size = 0;
		mmap[i].attr = 0;
	}
	mmap_add_region(total_base, total_base,
			total_size,
			MT_MEMORY | MT_RW | MT_SECURE);
	mmap_add_region(ro_start, ro_start,
			ro_limit - ro_start,
			MT_MEMORY | MT_RO | MT_SECURE);
	mmap_add(plat_arm_mmap);
	init_xlat_tables();

	enable_mmu_el3(0);
}

#endif

