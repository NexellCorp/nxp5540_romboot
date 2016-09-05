/* Exception Syndrome register bits and bobs */
#define ESR_EC_SHIFT                    26
#define ESR_EC_MASK                     0x3f
#define ESR_EC_LENGTH                   6
#define EC_UNKNOWN                      0x0
#define EC_WFE_WFI                      0x1
#define EC_AARCH32_CP15_MRC_MCR         0x3
#define EC_AARCH32_CP15_MRRC_MCRR       0x4
#define EC_AARCH32_CP14_MRC_MCR         0x5
#define EC_AARCH32_CP14_LDC_STC         0x6
#define EC_FP_SIMD                      0x7
#define EC_AARCH32_CP10_MRC             0x8
#define EC_AARCH32_CP14_MRRC_MCRR       0xc
#define EC_ILLEGAL                      0xe
#define EC_AARCH32_SVC                  0x11
#define EC_AARCH32_HVC                  0x12
#define EC_AARCH32_SMC                  0x13
#define EC_AARCH64_SVC                  0x15
#define EC_AARCH64_HVC                  0x16
#define EC_AARCH64_SMC                  0x17
#define EC_AARCH64_SYS                  0x18
#define EC_IABORT_LOWER_EL              0x20
#define EC_IABORT_CUR_EL                0x21
#define EC_PC_ALIGN                     0x22
#define EC_DABORT_LOWER_EL              0x24
#define EC_DABORT_CUR_EL                0x25
#define EC_SP_ALIGN                     0x26
#define EC_AARCH32_FP                   0x28
#define EC_AARCH64_FP                   0x2c
#define EC_SERROR                       0x2f

/*******************************************************************************
 * Constants to indicate type of exception to the common exception handler.
 ******************************************************************************/
#define SYNC_EXCEPTION_SP_EL0		0x0
#define IRQ_SP_EL0			0x1
#define FIQ_SP_EL0			0x2
#define SERROR_SP_EL0			0x3
#define SYNC_EXCEPTION_SP_ELX		0x4
#define IRQ_SP_ELX			0x5
#define FIQ_SP_ELX			0x6
#define SERROR_SP_ELX			0x7
#define SYNC_EXCEPTION_AARCH64		0x8
#define IRQ_AARCH64			0x9
#define FIQ_AARCH64			0xa
#define SERROR_AARCH64			0xb
#define SYNC_EXCEPTION_AARCH32		0xc
#define IRQ_AARCH32			0xd
#define FIQ_AARCH32			0xe
#define SERROR_AARCH32			0xf

/*******************************************************************************
 * Constants that allow assembler code to access members of and the
 * 'entry_point_info' structure at their correct offsets.
 ******************************************************************************/
#define ENTRY_POINT_INFO_PC_OFFSET      0x08
#define ENTRY_POINT_INFO_ARGS_OFFSET    0x18

/*
 * Corresponds to the function ID of the SMC that
 * the BL1 exception handler service to execute BL31.
 */
#define BL1_SMC_RUN_IMAGE               0x4


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

/* CPSR/SPSR definitions */
#define DAIF_FIQ_BIT		(1 << 0)
#define DAIF_IRQ_BIT		(1 << 1)
#define DAIF_ABT_BIT		(1 << 2)
#define DAIF_DBG_BIT		(1 << 3)
#define SPSR_DAIF_SHIFT		6
#define SPSR_DAIF_MASK		0xf

#define SPSR_AIF_SHIFT		6
#define SPSR_AIF_MASK		0x7

#define SPSR_E_SHIFT		9
#define SPSR_E_MASK		0x1
#define SPSR_E_LITTLE		0x0
#define SPSR_E_BIG		0x1

#define SPSR_T_SHIFT		5
#define SPSR_T_MASK		0x1
#define SPSR_T_ARM		0x0
#define SPSR_T_THUMB		0x1

#define DISABLE_ALL_EXCEPTIONS \
		(DAIF_FIQ_BIT | DAIF_IRQ_BIT | DAIF_ABT_BIT | DAIF_DBG_BIT)

#define HCR_RW_BIT		(1ull << 31)
#define HCR_AMO_BIT		(1 << 5)
#define HCR_IMO_BIT		(1 << 4)
#define HCR_FMO_BIT		(1 << 3)

#define TCR_EL3_RES1		((1UL << 31) | (1UL << 23))
#define TCR_EL1_IPS_SHIFT	32
#define TCR_EL3_PS_SHIFT	16


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

#define SPSR_64(el, sp, daif)				\
	(MODE_RW_64 << MODE_RW_SHIFT |			\
	((el) & MODE_EL_MASK) << MODE_EL_SHIFT |	\
	((sp) & MODE_SP_MASK) << MODE_SP_SHIFT |	\
	((daif) & SPSR_DAIF_MASK) << SPSR_DAIF_SHIFT)

#define SPSR_MODE32(mode, isa, endian, aif)		\
	(MODE_RW_32 << MODE_RW_SHIFT |			\
	((mode) & MODE32_MASK) << MODE32_SHIFT |	\
	((isa) & SPSR_T_MASK) << SPSR_T_SHIFT |		\
	((endian) & SPSR_E_MASK) << SPSR_E_SHIFT |	\
	((aif) & SPSR_AIF_MASK) << SPSR_AIF_SHIFT)

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
