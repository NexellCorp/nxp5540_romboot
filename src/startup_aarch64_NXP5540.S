/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          :
 *	File            : startup_aarch64.S
 *	Description     :
 *	Author          : Hans
 *	History         : 2013.01.10	Hans create
 *			  2014.09.03	Hans Modify for NXP5430
 *			  2015.05.04	Hans Change to support AArch64
 *			  2016.08.23	Hans support to NXP5540 romboot
 */
#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"

#include "aarch64_Vectors.inc"

	.align 9, 0	// 2^9 = 512 bytes sector size

//;==================================================================
//; Vectors
//;==================================================================
.global Startup
Startup:
	mrs	x0, SCTLR_EL3
	bic	x0, x0, #(SCTLR_EE_BIT)
	msr	SCTLR_EL3, x0

	mrs	x0, MPIDR_EL1
	and	x0, x0, #0xFFFF
	cmp	x0, xzr
	b.eq	primary_cold_start
99:
	WFI
	b	99b

primary_cold_start:

	msr	DAIFSet, #(I_Bit|F_Bit|A_Bit)	//; disable interrupt & fast interrupt and Abort


	bl	remap_vectors


//;=============================================================================
//; Get Boot Config
//;=============================================================================
	MOV	x0, #0x027C
	MOVK	x0, #0x2001, lsl #16	//; syscon address
	LDR	w29, [x0]		//; Get Boot Config

//;=============================================================================
//; Set Cache EMA for Each Core Voltage
//;=============================================================================
	MOV	x0, xzr
	MOVK	x0, #0x202C, lsl #16	//; tie-off reg base address

	MOV	x2, #(18 * 4)
	LDR	w1, [x0]		//; Get CPU0 EMA

	BIC	w1, w1, #(7<<17)	//; clear CPU0 EMA
	BIC	w1, w1, #(7<<23)	//; clear CPU0 L2EMA

	TST	w29, #(1<<COREVOLTAGE)	//; 0: 1.0 volt	3 apply		1: 1.1 volt 1 apply - reset config
	MOV	w3, #0
	b.eq	1f
	MOV	w3, #1<<17		//; 1 ==> 1.1 volt
	ORR	w3, w3, #1<<23
	b	2f
1:
	MOV	w3, #3<<17		//; 0 ==> 1.0 volt
	ORR	w3, w3, #3<<23
2:

	ORR	w1, w1, w3		//; apply CPU0 EMA

	STR	w1, [x0, #(18*4)]	//; Set CPU0 EMA

//;=============================================================================
//; Reset Release for Access to SRAM
//;=============================================================================
	MOV	x1, #0x040C		//; release cmu coda reset
	MOVK	x1, #0x2010, lsl #16	//; cmu sys base
	LDR	w2, [x1]	
	ORR	w2, w2, #0x00000010	//; cmu sys coda reset release
	STR	w2, [x1]		//; release cmu coda reset

	MOV	x1, #0x8000		//; cmu sys coda reset offset
	MOVK	x1, #0x2010, lsl #16	//; cmu sys base
	LDR	w2, [x1]		//; release cmu coda reset
	ORR	w2, w2, #0x40000000	//; cmu sys coda reset release
	STR	w2, [x1]		//; release cmu coda reset

	MOV	x1, #0x0408
	MOVK	x1, #0x2021, lsl #16	//; cmu coda base
	LDR	w2, [x1]		//; release axi sram reset
	ORR	w2, w2, #0x00000001	//; axi sram reset release
	STR	w2, [x1]		//; release axi sram reset

	MOV	x1, #0x8000		//; cmu coda sram offset
	MOVK	x1, #0x2021, lsl #16	//; cmu coda base
	LDR	w2, [x1, #0x0]		//; release axi sram reset
	ORR	w2, w2, #0x00000060	//; axi sram reset release
	STR	w2, [x1, #0x0]		//; release axi sram reset

//;==================================================================
//; Setup System Coprocessor
//;==================================================================
	mrs	x0, SCR_EL3
//;	orr	x0, x0, #(1<<12)		// trap WFI
	orr	x0, x0, #(1<<10)		// RW: 0: aarch32, 1:aarch64
	bic	x0, x0, #(1<<8)			// disable HVC. to be NOP
	bic	x0, x0, #(1<<7)			// 0: SMC is enabled at EL1, EL2, or EL3    1: SMC is undefined at all exception level
	orr	x0, x0, #(3<<4)			// RES1
	orr	x0, x0, #(1<<2)			// 1: route fiq to EL3
	bic	x0, x0, #(1<<0)			// 0: secure mode
	msr	SCR_EL3, x0

	msr	CPTR_EL3, xzr			//; not traped FP, SIMD

	mrs	x0, S3_1_c15_c2_1
	orr	x0, x0, #(1<<6)			// [6] SMPEN
	msr	S3_1_c15_c2_1, x0
	isb

	mrs	x0, CPACR_EL1			//; printf use fpu, neon register. so for test, exception trap must be disabled.
	orr	x0, x0, #(3<<20)		//; access fpu is not traped EL0, EL1
	msr	CPACR_EL1, x0

//;	mrs	x0, CPTR_EL2
	mov	x0, #0x33FF			//; RES1
//;	bic	x0, x0, #(1<<31)		//; TCPAC
//;	bic	x0, x0, #(1<<20)		//; TTA
//;	bic	x0, x0, #(1<<10)		//; TFP
	msr	CPTR_EL2, x0

	mrs	x0, SCTLR_EL3
	orr	x0, x0, #(1<<29 | 1<<28)	//; SBO
	orr	x0, x0, #(1<<23 | 1<<22)	//; SBO
	bic	x0, x0, #(1<<12)		//; icache disable
	orr	x0, x0, #(1<<11)		//; SBO
	msr	SCTLR_EL3, x0

//;=============================================================================
//; boot delay for cache auto initialize 10000ns
//;=============================================================================
	MOV	x0, xzr
	MOVK	x0, #0x202C, lsl #16	//; ARM efuse status register address
EfuseInitRecheck:
	LDR	x1, [x0, #(1*4)]
	AND	x1, x1, #(1<<24)	//; 16: ARMTOP Efuse Initial Done, 17: ARMTOP_P1 Efuse Initial Done
	CMP	x1, xzr
	B.eq	EfuseInitRecheck

	ic	ialluis				//; invalidate icache all
	isb	sy
	mrs	x0, SCTLR_EL3
	orr	x0, x0, #(1<<12)
	msr	SCTLR_EL3, x0			//; icache enable

#if 0	// need lds file modify
//;==================================================================
//; Clear SRAM
//;==================================================================
	//; Clear area of global data.
	ldr	x1, =__bss_start__		// this is auto-relocated!
	ldr	x2, =__bss_end__		// this is auto-relocated!
clbss_l:
	cmp	x1, x2				// while not at end of BSS
	b.hs	clbss_e				// higher or same
	str	xzr, [x1], #8			// clear 64-bit BSS word
	b.lo	clbss_l
clbss_e:
#endif

//;==================================================================
//; Setup stacks
//;==================================================================
	mov	x0, #BASEADDR_SRAM
	add	x0, x0, #INTERNAL_SRAM_SIZE

	mov	sp, x0

	mov	w0, w29		//; restore boot config

	bl	iROMBOOT	//; save this in register for possible long jump
	b	.

	.ltorg

//.global sync_asm_handler_EL3
	.align 4
.global synchrorous_vector_jump
synchrorous_vector_jump:
	adr     x0, sync_vector_value
	ldr     w0, [x0]
	br      x0
sync_vector_value:
	.long    sync_asm_handler_EL3

.global    remap_vectors
// void remap_vectors(U32 cpuid, U32 *synchrorous_vector_jump, void temp, U32 *__bss_end__);
remap_vectors:
	ldr	x3, =__bss_end__
	add	x3, x3, #0x7FF
	bic	x3, x3, #0x7FF

	ldr	x1, =synchrorous_vector_jump
	ldr	x2, [x1], #8
//;	str	x2, [x3, #0x000]	//; current Exception level with SP_EL0
	str	x2, [x3, #0x200]	//; current Exception level with SP_ELx, x>0
	str	x2, [x3, #0x400]	//; Lower Exception level with aarch64
	str	x2, [x3, #0x600]	//; Lower Exception level with aarch32
	ldr	x2, [x1], #8
//;	str	x2, [x3, #0x008]	//; current Exception level with SP_EL0
	str	x2, [x3, #0x208]	//; current Exception level with SP_ELx, x>0
	str	x2, [x3, #0x408]	//; Lower Exception level with aarch64
	str	x2, [x3, #0x608]	//; Lower Exception level with aarch32

        msr	VBAR_EL3, x3			//; reset exception vector
	isb

	ret

	.ltorg
//==================================================================
// Exception Handler entry
//==================================================================
	.align 3
	.global sync_asm_handler_EL3
sync_asm_handler_EL3:
	PUSH_HANDLER_FRAME
	bl	sync_c_handler_EL3
	POP_HANDLER_FRAME
	msr	elr_el3, x30                        //; lr
	eret

//;==================================================================
//; End of startup.s
//;==================================================================
