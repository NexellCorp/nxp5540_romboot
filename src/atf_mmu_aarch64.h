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
 *	File            : mmu_aarch64.h
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.29 Hans create
 */
#ifndef __XLAT_TABLES_H__
#define __XLAT_TABLES_H__

#ifndef __ASSEMBLY__

typedef __signed char           __int8_t;
typedef unsigned char           __uint8_t;
typedef short                   __int16_t;
typedef unsigned short          __uint16_t;
typedef int                     __int32_t;
typedef unsigned int            __uint32_t;
typedef long                    __int64_t;
typedef unsigned long           __uint64_t;

typedef __uint64_t      __uintptr_t;

typedef __uint32_t              uint32_t;
typedef __uint64_t              uint64_t;
typedef __uintptr_t             uintptr_t;

typedef __uint64_t      __size_t;               /* sizeof() */
typedef __size_t        size_t;

#define __aligned(x)    __attribute__((__aligned__(x)))

#define INVALID_DESC            0x0
#define BLOCK_DESC              0x1
#define TABLE_DESC              0x3

#define XN                      (1ull << 2)

#define UPPER_ATTRS(x)          (x & 0x7) << 52
#define ACCESS_FLAG             (1 << 8)
#define OSH                     (0x2 << 6)
#define ISH                     (0x3 << 6)

#define AP_RO                   (0x1 << 5)
#define AP_RW                   (0x0 << 5)
#define NS                              (0x1 << 3)
#define ATTR_DEVICE_INDEX               0x1
#define ATTR_IWBWA_OWBWA_NTR_INDEX      0x0
#define LOWER_ATTRS(x)                  (((x) & 0xfff) << 2)
#define ATTR_DEVICE                     (0x4)
#define ATTR_IWBWA_OWBWA_NTR            (0xff)
#define MAIR_ATTR_SET(attr, index)      (attr << (index << 3))

#define FOUR_KB_SHIFT           12
#define XLAT_ENTRY_SIZE_SHIFT   3 /* Each MMU table entry is 8 bytes (1 << 3) */

#define PAGE_SIZE_SHIFT         FOUR_KB_SHIFT

#define XLAT_TABLE_SIZE_SHIFT   PAGE_SIZE_SHIFT
#define XLAT_TABLE_SIZE         (1 << XLAT_TABLE_SIZE_SHIFT)

#define XLAT_TABLE_ENTRIES_SHIFT (XLAT_TABLE_SIZE_SHIFT - XLAT_ENTRY_SIZE_SHIFT)
#define XLAT_TABLE_ENTRIES      (1 << XLAT_TABLE_ENTRIES_SHIFT)
#define XLAT_TABLE_ENTRIES_MASK (XLAT_TABLE_ENTRIES - 1)

/* Values to convert a memory address to an index into a translation table */
#define L3_XLAT_ADDRESS_SHIFT   PAGE_SIZE_SHIFT
#define L2_XLAT_ADDRESS_SHIFT   (L3_XLAT_ADDRESS_SHIFT + XLAT_TABLE_ENTRIES_SHIFT)
#define L1_XLAT_ADDRESS_SHIFT   (L2_XLAT_ADDRESS_SHIFT + XLAT_TABLE_ENTRIES_SHIFT)

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof((a)[0]))
/*
 * Flags to override default values used to program system registers while
 * enabling the MMU.
 */
#define DISABLE_DCACHE          (1 << 0)

#define _DEFINE_SYSREG_READ_FUNC(_name, _reg_name)		\
static inline uint64_t read_ ## _name(void)			\
{								\
	uint64_t v;						\
	__asm__ volatile ("mrs %0, " #_reg_name : "=r" (v));	\
	return v;						\
}

#define _DEFINE_SYSREG_WRITE_FUNC(_name, _reg_name)			\
static inline void write_ ## _name(uint64_t v)				\
{									\
	__asm__ volatile ("msr " #_reg_name ", %0" : : "r" (v));	\
}
#define DEFINE_SYSREG_RW_FUNCS(_name)			\
	_DEFINE_SYSREG_READ_FUNC(_name, _name)		\
	_DEFINE_SYSREG_WRITE_FUNC(_name, _name)

#define DEFINE_SYSOP_FUNC(_op)				\
static inline void _op(void)				\
{							\
	__asm__ (#_op);					\
}
#define DEFINE_SYSOP_TYPE_FUNC(_op, _type)		\
static inline void _op ## _type(void)			\
{							\
	__asm__ (#_op " " #_type);			\
}
#define DEFINE_SYSOP_TYPE_PARAM_FUNC(_op, _type)	\
static inline void _op ## _type(uint64_t v)		\
{							\
	__asm__ (#_op " " #_type ", %0" : : "r" (v));	\
}
DEFINE_SYSREG_RW_FUNCS(tcr_el3)
DEFINE_SYSREG_RW_FUNCS(sctlr_el3)
DEFINE_SYSREG_RW_FUNCS(mair_el3)
DEFINE_SYSREG_RW_FUNCS(ttbr0_el3)
DEFINE_SYSOP_TYPE_FUNC(tlbi, alle3)
DEFINE_SYSOP_TYPE_FUNC(dsb, sy)
DEFINE_SYSOP_FUNC(isb)

#define dsb()                   dsbsy()

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

/* Helper macro to define entries for mmap_region_t. It creates
 * identity mappings for each region.
 */
#define MAP_REGION_FLAT(adr, sz, attr) MAP_REGION(adr, adr, sz, attr)

/* Helper macro to define entries for mmap_region_t. It allows to
 *  * re-map address mappings from 'pa' to 'va' for each region.
 *   */
#define MAP_REGION(pa, va, sz, attr) {(pa), (va), (sz), (attr)}

/*
 * Flags for building up memory mapping attributes.
 * These are organised so that a clear bit gives a more restrictive  mapping
 * that a set bit, that way a bitwise-and two sets of attributes will never give
 * an attribute which has greater access rights that any of the original
 * attributes.
 */
typedef enum  {
	MT_DEVICE       = 0 << 0,
	MT_MEMORY       = 1 << 0,

	MT_RO           = 0 << 1,
	MT_RW           = 1 << 1,

	MT_SECURE       = 0 << 2,
	MT_NS           = 1 << 2
} mmap_attr_t;

/*
 * Structure for specifying a single region of memory.
 */
typedef struct mmap_region {
	unsigned long   base_pa;
	unsigned long   base_va;
	unsigned long   size;
	mmap_attr_t     attr;
} mmap_region_t;

#define MAX_XLAT_TABLES			4
#define MAX_MMAP_REGIONS		16

void mmap_add_region(unsigned long base_pa, unsigned long base_va,
		unsigned long size, unsigned attr);
void mmap_add(const mmap_region_t *mm);

void init_xlat_tables(void);

void enable_mmu_el3(uint32_t flags);

#endif /*__ASSEMBLY__*/
#endif /* __XLAT_TABLES_H__ */
