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
 */
#include "nx_etacarinae.h"
#include "lib_aarch64.h"
#include "nx_etacarinae_bootoption.h"


.global exception_vectors

	.align 9, 0	// 2^9 = 512 bytes sector size

//;==================================================================
//; Vectors
//;==================================================================
.global Startup
Startup:
//	b	.
#if 0
	mov	x0, xzr
	mov	x1, xzr
	mov	x2, xzr
	mov	x3, xzr
	mov	x4, xzr
	mov	x5, xzr
	mov	x6, xzr
	mov	x7, xzr
	mov	x8, xzr
	mov	x9, xzr
	mov	x10, xzr
	mov	x11, xzr
	mov	x12, xzr
	mov	x13, xzr
	mov	x14, xzr
	mov	x15, xzr
	mov	x16, xzr
	mov	x17, xzr
	mov	x18, xzr
	mov	x19, xzr
	mov	x20, xzr
	mov	x21, xzr
	mov	x22, xzr
	mov	x23, xzr
	mov	x24, xzr
	mov	x25, xzr
	mov	x26, xzr
	mov	x27, xzr
	mov	x28, xzr
	mov	x29, xzr
	mov	x30, xzr
#endif

	mrs	x0, SCTLR_EL3
	bic	x1, x0, #(SCTLR_EE_BIT)		//; little endian
	msr	SCTLR_EL3, x1

	mrs	x2, MPIDR_EL1			//; Get our cpu id
	and	x3, x2, #0xFFFF
	cmp	x3, xzr
	b.eq	primary_cold_start
99:
	WFI				//; secondary cpu
	b	99b

primary_cold_start:
	//; disable interrupt & fast interrupt and Abort
	msr	DAIFSet, #(I_Bit|F_Bit|A_Bit)
//	plat_reset_handler
	/* In juno, it sets the latency of L2 Data and Tag. How about nexell? */
	/* Do anything just after reset. At here, do we need? */
//	plat_reset_handler

	MOV	x4, #(SCTLR_A_BIT | SCTLR_SA_BIT)
	mrs	x5, SCTLR_EL3
	orr	x6, x5, x4
	msr	SCTLR_EL3, x6
	isb

	adr	x7, exception_vectors
	msr	VBAR_EL3, x7
	isb

	msr	DAIFClr, #(A_Bit)	//; Enable Abort

	mrs	x8, CPTR_EL3
	bic	w9, w8, #TCPAC_BIT
	bic	w10, w9, #TTA_BIT
	bic	w11, w10, #TFP_BIT
	msr	CPTR_EL3, x11

#ifdef NXP5540
//;=============================================================================
//; pad retention off
//;=============================================================================
//;	MOV	X0, #0x089c		//; alive pad retention reg
//;	MOVK	X0, #0x2001, lsl #16
//;	MOV	X1, #0x3FF
//;	STR	X1, [x0]		//; pad retention off

//;=============================================================================
//; Get Boot Config
//;=============================================================================
	MOV	x12, #0x027C
	MOVK	x12, #0x2001, lsl #16	//; syscon address
	LDR	w29, [x12]		//; Get Boot Config
#endif

#ifdef NXP5430
//;==================================================================
//; Get Boot Config
//;==================================================================
	MOV	x12, #0xFE50		//; nsih virtual register address
	MOVk	x12, #0x4FFF, lsl #16	//; syscon address
	LDR	w29, [x12]		//; Get Boot Config
#endif

#ifdef NXP5540
//;=============================================================================
//; Set Cache EMA for Each Core Voltage
//;=============================================================================
	MOV	x12, xzr
	MOVK	x12, #0x202C, lsl #16	//; tie-off reg base address

	LDR	w13, [x12]		//; Get CPU0 EMA

	BIC	w16, w13, #(7<<17)	//; clear CPU0 EMA
	BIC	w17, w16, #(7<<23)	//; clear CPU0 L2EMA

	//; 0: 1.0 volt	3 apply		1: 1.1 volt 1 apply - reset config
	TST	w29, #(1<<COREVOLTAGE)
	b.eq	1f
	MOV	w14, #1<<17		//; 1 ==> 1.1 volt
	ORR	w15, w14, #1<<23
	b	2f
1:
	MOV	w14, #3<<17		//; 0 ==> 1.0 volt
	ORR	w15, w14, #3<<23
2:

	ORR	w18, w17, w15		//; apply CPU0 EMA

	STR	w18, [x12, #(18*4)]	//; Set CPU0 EMA
//;=============================================================================
//; Reset Release for Access to SRAM
//;=============================================================================
	MOV	x19, #0x040C		//; release cmu coda reset
	MOVK	x19, #0x2010, lsl #16	//; cmu sys base
	LDR	w20, [x19]
	ORR	w21, w20, #0x00000010	//; cmu sys coda reset release
	STR	w21, [x19]		//; release cmu coda reset

	MOV	x22, #0x8000		//; cmu sys coda reset offset
	MOVK	x22, #0x2010, lsl #16	//; cmu sys base
	LDR	w23, [x22]		//; release cmu coda reset
	ORR	w24, w23, #0x40000000	//; cmu sys coda reset release
	STR	w24, [x22]		//; release cmu coda reset

	MOV	x25, #0x0408
	MOVK	x25, #0x2021, lsl #16	//; cmu coda base
	LDR	w26, [x25]		//; release axi sram reset
	ORR	w27, w26, #0x00000001	//; axi sram reset release
	STR	w27, [x25]		//; release axi sram reset

	MOV	x28, #0x8000		//; cmu coda sram offset
	MOVK	x28, #0x2021, lsl #16	//; cmu coda base
	LDR	w30, [x28, #0x0]	//; release axi sram reset
	ORR	w30, w30, #0x00000060	//; axi sram reset release
	STR	w30, [x28, #0x0]	//; release axi sram reset
#endif

//;==================================================================
//; Setup System Coprocessor
//;==================================================================

	mrs	x13, SCR_EL3
	orr	x14, x13, #(1<<10)		// RW: 0: aarch32, 1:aarch64
	bic	x15, x14, #(1<<8)			// disable HVC. to be NOP
	bic	x16, x15, #(1<<7)			// 0: SMC is enabled at EL1, EL2, or EL3    1: SMC is undefined at all exception level
	orr	x17, x16, #(3<<4)			// RES1
//;	orr	x0, x0, #(1<<2)			// 1: route fiq to EL3
	bic	x18, x17, #(1<<0)			// 0: secure mode
	msr	SCR_EL3, x18

	mrs	x19, S3_1_c15_c2_1
	orr	x20, x19, #(1<<6)			// [6] SMPEN
	msr	S3_1_c15_c2_1, x20
	isb

	mrs	x21, CPACR_EL1			//; printf use fpu, neon register. so for test, exception trap must be disabled.
	orr	x22, x21, #(3<<20)		//; access fpu is not traped EL0, EL1
	msr	CPACR_EL1, x22


//;=============================================================================
//; boot delay for cache auto initialize 10000ns
//;=============================================================================
#ifdef NXP5430
	MOV	x23, 0x113C
	MOVK	x23, #0xC001, lsl #16	//; ARM efuse status register address
	MOV	x24, #0x3<<16
1:
	LDR	w25, [x23]
	AND	w25, w25, w24	//; 16: ARMTOP Efuse Initial Done, 17: ARMTOP_P1 Efuse Initial Done
	CMP	w25, w24
	B.ne	1b
#endif
#ifdef NXP5540
	MOV	x0, xzr
	MOVK	x0, #0x202C, lsl #16	//; ARM efuse status register address
1:
	LDR	w1, [x0, #(1*4)]
	AND	w1, w1, #(1<<24)	//; 24: ARMTOP Efuse Initial Done
	CMP	w1, wzr
	B.eq	1b
#endif

	ic	ialluis				//; invalidate icache all
	isb	sy
	mrs	x26, SCTLR_EL3
	mov	x27, #(SCTLR_SA_BIT | SCTLR_A_BIT)
	orr	x28, x26, x27
	and	x2, x29, #(1 << ICACHE)
	cmp	x2, xzr
	b.ne	2f
	orr	x28, x28, SCTLR_I_BIT
2:
	msr	SCTLR_EL3, x28			//; icache enable

#if 0
	ldr	x0, = __bss_start__
	ldr	x1, = __bss_end__
	bl	Dcache_flush_range
#endif

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
//;==================================================================
//; Setup stacks
//;==================================================================
	mov	x30, #BASEADDR_SRAM
	add	x30, x30, #INTERNAL_SRAM_SIZE
	mov	sp, x30

	mov	w0, w29		//; restore boot config

	bl	iROMBOOT		//; save this in register for possible long jump
	b	.

	.ltorg

//;==================================================================
//; End of startup.s
//;==================================================================
