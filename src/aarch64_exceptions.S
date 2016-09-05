/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : Exception Handler
 *	File            : aarch64_exceptions.S
 *	Description     :
 *	Author          : Firware Team
 *	History         : 2016.09.04 Hans Create
 */

#include "context.h"
#include "lib_aarch64.h"


/* -----------------------------------------------------
 * Save Secure/Normal world context and jump to
 * BL1 SMC handler.
 * -----------------------------------------------------
 */
smc_handler64:

/* ----------------------------------------------
 * Detect if this is a RUN_IMAGE or other SMC.
 * ----------------------------------------------
 */
	mov     x30, #BL1_SMC_RUN_IMAGE
	cmp     x30, x0
	b.ne    smc_handler

/* ------------------------------------------------
 * Make sure only Secure world reaches here.
 * ------------------------------------------------
 */
	mrs     x30, scr_el3
	tst     x30, #SCR_NS_BIT
	b.ne    unexpected_sync_exception

/* ----------------------------------------------
 * Handling RUN_IMAGE SMC. First switch back to
 * SP_EL0 for the C runtime stack.
 * ----------------------------------------------
 */
	ldr     x30, [sp, #CTX_EL3STATE_OFFSET + CTX_RUNTIME_SP]
	msr     spsel, #0
	mov     sp, x30

/* ---------------------------------------------------------------------
 * Pass EL3 control to BL31.
 * Here it expects X1 with the address of a entry_point_info_t
 * structure describing the BL31 entrypoint.
 * ---------------------------------------------------------------------
 */
	mov     x20, x1

//	mov     x0, x20
//	bl      bl1_print_bl31_ep_info

	ldp     x0, x1, [x20, #ENTRY_POINT_INFO_PC_OFFSET]
	msr     elr_el3, x0
	msr     spsr_el3, x1
	ubfx    x0, x1, #MODE_EL_SHIFT, #2
	cmp     x0, #MODE_EL3
	b.ne    unexpected_sync_exception

	bl      disable_mmu_icache_el3
	tlbi    alle3

	ldp     x6, x7, [x20, #(ENTRY_POINT_INFO_ARGS_OFFSET + 0x30)]
	ldp     x4, x5, [x20, #(ENTRY_POINT_INFO_ARGS_OFFSET + 0x20)]
	ldp     x2, x3, [x20, #(ENTRY_POINT_INFO_ARGS_OFFSET + 0x10)]
	ldp     x0, x1, [x20, #(ENTRY_POINT_INFO_ARGS_OFFSET + 0x0)]
	eret

//endfunc smc_handler64
unexpected_sync_exception:
	mov     x0, #SYNC_EXCEPTION_AARCH64
	bl      plat_report_exception
	b       unexpected_sync_exception

disable_mmu_icache_el3:
	mov     x1, #(SCTLR_M_BIT | SCTLR_C_BIT | SCTLR_I_BIT)
	mrs     x0, sctlr_el3
	bic     x0, x0, x1
	msr     sctlr_el3, x0
	isb                             // ensure MMU is off
	dsb     sy
	ret

/* -----------------------------------------------------
 * Save Secure/Normal world context and jump to
 * BL1 SMC handler.
 * -----------------------------------------------------
 */
smc_handler:
/* -----------------------------------------------------
 * Save the GP registers x0-x29.
 * TODO: Revisit to store only SMCC specified registers.
 * -----------------------------------------------------
 */
	/* -----------------------------------------------------
	 * The following functions are used to save and restore
	 * all the general purpose registers. Ideally we would
	 * only save and restore the callee saved registers when
	 * a world switch occurs but that type of implementation
	 * is more complex. So currently we will always save and
	 * restore these registers on entry and exit of EL3.
	 * These are not macros to ensure their invocation fits
	 * within the 32 instructions per exception vector.
	 * clobbers: x18
	 * -----------------------------------------------------
	 */
//save_gp_registers:
	stp     x0, x1, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X0]
	stp     x2, x3, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X2]
	stp     x4, x5, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X4]
	stp     x6, x7, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X6]
	stp     x8, x9, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X8]
	stp     x10, x11, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X10]
	stp     x12, x13, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X12]
	stp     x14, x15, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X14]
	stp     x16, x17, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X16]
	stp     x18, x19, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X18]
	stp     x20, x21, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X20]
	stp     x22, x23, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X22]
	stp     x24, x25, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X24]
	stp     x26, x27, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X26]
	stp     x28, x29, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X28]
	mrs     x18, sp_el0
	str     x18, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_SP_EL0]

/* -----------------------------------------------------
 * Populate the parameters for the SMC handler. We
 * already have x0-x4 in place. x5 will point to a
 * cookie (not used now). x6 will point to the context
 * structure (SP_EL3) and x7 will contain flags we need
 * to pass to the handler.
 * -----------------------------------------------------
 */
	mov     x5, xzr
	mov     x6, sp

/* -----------------------------------------------------
 * Restore the saved C runtime stack value which will
 * become the new SP_EL0 i.e. EL3 runtime stack. It was
 * saved in the 'cpu_context' structure prior to the last
 * ERET from EL3.
 * -----------------------------------------------------
 */
	ldr     x12, [x6, #CTX_EL3STATE_OFFSET + CTX_RUNTIME_SP]

/* ---------------------------------------------
 * Switch back to SP_EL0 for the C runtime stack.
 * ---------------------------------------------
 */
	msr     spsel, #0
	mov     sp, x12

/* -----------------------------------------------------
 * Save the SPSR_EL3, ELR_EL3, & SCR_EL3 in case there
 * is a world switch during SMC handling.
 * -----------------------------------------------------
 */
	mrs     x16, spsr_el3
	mrs     x17, elr_el3
	mrs     x18, scr_el3
	stp     x16, x17, [x6, #CTX_EL3STATE_OFFSET + CTX_SPSR_EL3]
	str     x18, [x6, #CTX_EL3STATE_OFFSET + CTX_SCR_EL3]

	/* Copy SCR_EL3.NS bit to the flag to indicate caller's security */
	bfi     x7, x18, #0, #1
/* -----------------------------------------------------
 * Go to BL1 SMC handler.
 * -----------------------------------------------------
 */
//	bl      bl1_smc_handler

/* -----------------------------------------------------
 * Do the transition to next BL image.
 * -----------------------------------------------------
 */

/* -----------------------------------------------------
 * This routine assumes that the SP_EL3 is pointing to
 * a valid context structure from where the gp regs and
 * other special registers can be retrieved.
 * -----------------------------------------------------
 */
//	func el3_exit
el3_exit:
/* -----------------------------------------------------
 * Save the current SP_EL0 i.e. the EL3 runtime stack
 * which will be used for handling the next SMC. Then
 * switch to SP_EL3
 * -----------------------------------------------------
 */
	mov     x17, sp
	msr     spsel, #1
	str     x17, [sp, #CTX_EL3STATE_OFFSET + CTX_RUNTIME_SP]

/* -----------------------------------------------------
 * Restore SPSR_EL3, ELR_EL3 and SCR_EL3 prior to ERET
 * -----------------------------------------------------
 */
	ldr     x18, [sp, #CTX_EL3STATE_OFFSET + CTX_SCR_EL3]
	ldp     x16, x17, [sp, #CTX_EL3STATE_OFFSET + CTX_SPSR_EL3]
	msr     scr_el3, x18
	msr     spsr_el3, x16
	msr     elr_el3, x17

	/* Restore saved general purpose registers and return */
	ldp     x0, x1, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X0]
	ldp     x2, x3, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X2]
	ldp	x4, x5, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X4]
	ldp	x6, x7, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X6]
	ldp	x8, x9, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X8]
	ldp	x10, x11, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X10]
	ldp	x12, x13, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X12]
	ldp	x14, x15, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X14]
	ldp	x18, x19, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X18]
	ldp	x20, x21, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X20]
	ldp	x22, x23, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X22]
	ldp	x24, x25, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X24]
	ldp	x26, x27, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X26]
	ldp	x28, x29, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X28]
	ldp	x30, x17, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_LR]
	msr	sp_el0, x17
	ldp	x16, x17, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X16]
	eret





/* -----------------------------------------------------------------------------
 * start of exception vectors
 * -----------------------------------------------------------------------------
 */
	.globl  exception_vectors

	/*
	 * This macro verifies that the a given vector doesn't exceed the
	 * architectural limit of 32 instructions. This is meant to be placed
	 * immedately after the last instruction in the vector. It takes the
	 * vector entry as the parameter
	 */
	.macro check_vector_size since
		.if (. - \since) > (32 * 4)
			.error "Vector exceeds 32 instructions"
		.endif
	.endm

	.section .vectors, "ax"; .align 11

/* -----------------------------------------------------
 * Very simple stackless exception handlers used by BL1.
 * -----------------------------------------------------
 */
exception_vectors:
/* -----------------------------------------------------
 * Current EL with SP0 : 0x0 - 0x200
 * -----------------------------------------------------
 */
	.align  7
SynchronousExceptionSP0:
	mov	x0, #SYNC_EXCEPTION_SP_EL0
	bl	plat_report_exception
1:
	wfi
	b	1b	
	check_vector_size SynchronousExceptionSP0

	.align  7
IrqSP0:
	mov     x0, #IRQ_SP_EL0
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size IrqSP0

	.align  7
FiqSP0:
	mov     x0, #FIQ_SP_EL0
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size FiqSP0

	.align  7
SErrorSP0:
	mov	x0, #SERROR_SP_EL0
	bl	plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SErrorSP0
/* -----------------------------------------------------
 * Current EL with SPx: 0x200 - 0x400
 * -----------------------------------------------------
 */
	.align  7
SynchronousExceptionSPx:
	mov     x0, #SYNC_EXCEPTION_SP_ELX
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SynchronousExceptionSPx

	.align  7
IrqSPx:
	mov     x0, #IRQ_SP_ELX
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size IrqSPx

	.align  7
FiqSPx:
	mov     x0, #FIQ_SP_ELX
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size FiqSPx

	.align  7
SErrorSPx:
	mov     x0, #SERROR_SP_ELX
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SErrorSPx

/* -----------------------------------------------------
 * Lower EL using AArch64 : 0x400 - 0x600
 * -----------------------------------------------------
 */
	.align  7
SynchronousExceptionA64:
	/* Enable the SError interrupt */
	msr     daifclr, #DAIF_ABT_BIT

	str     x30, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_LR]

	/* Expect only SMC exceptions */
	mrs     x30, esr_el3
	ubfx    x30, x30, #ESR_EC_SHIFT, #ESR_EC_LENGTH
	cmp     x30, #EC_AARCH64_SMC
	b.ne    unexpected_sync_exception

	b       smc_handler64
	check_vector_size SynchronousExceptionA64

	.align  7
IrqA64:
	mov     x0, #IRQ_AARCH64
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size IrqA64

	.align  7
FiqA64:
	mov     x0, #FIQ_AARCH64
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size FiqA64

	.align  7
SErrorA64:
	mov     x0, #SERROR_AARCH64
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SErrorA64

/* -----------------------------------------------------
 * Lower EL using AArch32 : 0x600 - 0x800
 * -----------------------------------------------------
 */
	.align  7
SynchronousExceptionA32:
	mov     x0, #SYNC_EXCEPTION_AARCH32
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SynchronousExceptionA32

	.align  7
IrqA32:
	mov     x0, #IRQ_AARCH32
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size IrqA32

	.align  7
FiqA32:
	mov     x0, #FIQ_AARCH32
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size FiqA32

	.align  7
SErrorA32:
	mov     x0, #SERROR_AARCH32
	bl      plat_report_exception
1:
	wfi
	b	1b
	check_vector_size SErrorA32



