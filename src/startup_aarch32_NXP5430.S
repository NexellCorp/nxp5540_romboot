/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : bl0
 *	File            : startup_aarch32.S
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.10	Hans first draft
 */

//;==================================================================
//; cortex A57 V7 compatable
//;==================================================================
#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"


		.align 4

//;==================================================================
//; Vectors
//;==================================================================
.global Vectors
Vectors:
	LDR	PC, ResetV	//; 00 - Reset
	LDR	PC, UndefV	//; 04 - Undefined instructions
	LDR	PC, SWIV	//; 08 - SWI instructions
	LDR	PC, PAbortV	//; 0C - Instruction fetch aborts
	LDR	PC, DAbortV	//; 10 - Data access aborts
	LDR	PC, UnusedV	//; 14 - Reserved (was address exception)
	LDR	PC, IRQV	//; 18 - IRQ interrupts
	LDR	PC, FIQV	//; 1C - FIQ interrupts

ResetV:
	.word	Reset_Handler
UndefV:
	.word	(BASEADDR_SRAM + 0x04)	//; 04 - undef
SWIV:
	.word	(BASEADDR_SRAM + 0x08)	//; 08 - software interrupt
PAbortV:
	.word	(BASEADDR_SRAM + 0x0C)	//; 0C - prefectch abort
DAbortV:
	.word	(BASEADDR_SRAM + 0x10)	//; 10 - data abort
UnusedV:
	.word	0			//; 14 - will reset if called...
IRQV:
	.word	(BASEADDR_SRAM + 0x18)	//; 18 - IRQ
FIQV:
	.word	(BASEADDR_SRAM + 0x1C)	//; 1C - FIQ

//;=============================================================================
//; Imports
//;=============================================================================

.global iROMBOOT

//;=============================================================================
//; Reset Handler - Generic initialization, run by all CPUs
//;=============================================================================

Reset_Handler:
	//; if MMU/MPU enabled - disable (useful for ARMulator tests)
//;=============================================================================
//; Disable caches, MMU and branch prediction in case they were left enabled
//; from an earlier run
//; This does not need to be done from a cold reset
//;=============================================================================
	MRC	P15, 0, R0, C1, C0, 0		//; Read CP15 System Control register
	BIC	R0, R0, #(BIT1_V|BIT1_I|BIT1_Z)	//; Clear V:13, I:12, Z:11 bit to disable High Vector, I-Cache, Branch Prediction
	BIC	R0, R0, #(BIT1_C|BIT1_M)	//; Clear C:2, M:0 bit to disable D Cache, MMU
	MCR	P15, 0, R0, C1, C0, 0		//; Write value back to CP15 System Control register

	MSR	CPSR_c, #(Mode_MON|I_Bit|F_Bit)	//; Set CPU to SVC32 Mode

//;=============================================================================
//; Get Boot Config
//;=============================================================================
	MOV	R0, #0
	MOVT	R0, #0xC001		//; syscon address
	LDR	R11, [R0, #0x27C]	//; Get Boot Config


CacheInit:
//;=============================================================================
//; Set Vector Base Address Register (VBAR) to point to this application's vector table
//;=============================================================================
	LDR	R0, =Vectors
	MCR	P15, 0, R0, C12, C0, 0	//; Write Secure or Non-secure Vector Base Address
	MRC	P15, 0, R0, C1, C0, 0	//; Read SCTLR
	BIC	R0, #(1<<13)	        //; Clear V-bit
	MCR	P15, 0, R0, C1, C0, 0	//; Write SCTLR

//;=============================================================================
//; Invalidate entire branch predictor
//;=============================================================================
	MOV	R0, #0
	MCR     P15, 0, R0, C7, C5, 0	//; invalidate all instruction caches
	MCR	P15, 0, R0, C7, C5, 6	//; BPIALL - Invalidate entire branch predictor array


//;=============================================================================
//; Enable caches and branch prediction
//;=============================================================================
	MOV	R0, R11
	TST	R0, #(0x1 << ICACHE )	//; if selsdex==0 check sd-icache bit

	MRCNE	P15, 0, R1, C1, C0, 0	//; Read System Control Register
	ORRNE	R1, R1, #(BIT1_I)	//; Set I bit 12 to enable I Cache
	MCRNE	P15, 0, R1, C1, C0, 0	//; Write System Control Register


//;=============================================================================
//; Setup stacks
//;=============================================================================
	MOV	SP, #0x60000000
	ADD	SP, SP, #INTERNAL_SRAM_SIZE	//; PHY_BASEADDR_SRAM 0x10000000 + INTERNAL_SRAM_SIZE

	BL	iROMBOOT			//; save this in register for possible long jump

        BX      R0				//; jump to R0
	MOV	PC, #0				//; Never Get Here

//;=============================================================================
//; End of startup.s
//;=============================================================================
