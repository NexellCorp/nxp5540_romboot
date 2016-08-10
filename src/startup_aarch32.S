//;==================================================================
//; cortex A57 V7 compatable
//;==================================================================
#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"


		.align 8

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
//; Get CPU and Core ID	CPU0 & Core0 ID is 0, CPU1 & Core3 ID is 7
//;=============================================================================
	MRC	P15, 0, R12, C0, C0, 5	//; Get our cpu id
	TST	R12, #0x4400		//; check processor affinity
	ORRNE	R12, R12, #4			//; mark cpu0 or cpu1
	AND	R12, R12, #0xF		//; Save CPU id

	CMP	R12, #PRIMARY_CPU
	BNE	CacheInit		//; CPU 1, 2, 3, 4, 5, 6, 7 goes to Wait For Interrupt Loop

//;=============================================================================
//; boot delay for cache auto initialize 10000ns
//;=============================================================================
	MOV	R0, #0x20000000
	ORR	R0, R0, #0x002C0000	//; ARM efuse status register address
EfuseInitRecheck:
	LDR	R1, [R0, #(1*4)]
	AND	R1, R1, #(1<<24)	//; 16: ARMTOP Efuse Initial Done, 17: ARMTOP_P1 Efuse Initial Done
	CMP	R1, #(1<<24)
	BNE	EfuseInitRecheck

//;=============================================================================
//; Get Boot Config
//;=============================================================================
	MOV	R0, #0x20000000
	ORR	R0, R0, #0x00010000	//; syscon address
	LDR	R11, [R0, #0x27C]	//; Get Boot Config

//;=============================================================================
//; Set Cache EMA for Each Core Voltage
//;=============================================================================
	MOV	R0, #0x20000000		//;
	ORR	R0, R0, #0x002C0000	//; tie-off reg base address

	LDR	R1, [R0, #(18*4)]	//;	Get CPU0 EMA
//;	LDR	R2, [R0, #(111*4)]	//;	Get CPU1 EMA

	BIC	R1, R1, #(7<<17)	//;	clear CPU0 EMA
	BIC	R1, R1, #(7<<23)	//; clear CPU0 L2EMA
//;	BIC	R2, R2, #(7<<17)	//;	clear CPU1 EMA
//;	BIC	R2, R2, #(7<<23)	//; clear CPU1 L2EMA

	TST	R11, #1<<COREVOLTAGE	//; 0: 1.0 volt	3 apply		1: 1.1 volt 1 apply - reset config
	MOV	R3, #0
	MOVNE	R3, #1<<17		//; 1 ==> 1.1 volt
	ORRNE	R3, R3, #1<<23
	MOVEQ	R3, #3<<17		//; 0 ==> 1.0 volt
	ORREQ	R3, R3, #3<<23

	ORR	R1, R1, R3		//; apply CPU0 EMA
//;	ORR	R2, R2, R3		//; apply CPU1 EMA

	STR	R1, [R0, #(18*4)]	//;	Set CPU0 EMA
//;	STR	R2, [R0, #(111*4)]	//; Set CPU1 EMA

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
//; Set SMP Start Address to Invalid
//;=============================================================================
	MOV	R0, #0x20000000		//; peri base
	ORR	R0, R0, #0x00010000	//; clk N pwr offset
	MOV	R1, #0xFFFFFFFF		//; mark to invalid address
	STR	R1, [R0, #0x230]	//; set invalid jump address

//;=============================================================================
//; Enable caches and branch prediction
//;=============================================================================
	MOV	R0, R11
	TST	R0, #(0x1 << ICACHE )	//; if selsdex==0 check sd-icache bit

	MRCNE	P15, 0, R1, C1, C0, 0	//; Read System Control Register
	ORRNE	R1, R1, #(BIT1_I)	//; Set I bit 12 to enable I Cache
	MCRNE	P15, 0, R1, C1, C0, 0	//; Write System Control Register

//;=============================================================================
//; Reset Release for Access to SRAM
//;=============================================================================
        MOV	R1, #0x20000000
	ORR	R1, R1, #0x00100000	//; cmu sys base
        LDR	R2, [R1, #0x40C]	//; release cmu coda reset
        ORR	R2, #0x00000010		//; cmu sys coda reset release
        STR	R2, [R1, #0x40C]	//; release cmu coda reset

//;	MOV	R1, #0x20000000
//;	ORR	R1, R1, #0x00100000	//; cmu sys base
	ORR	R1, R1, #0x00008000	//; cmu sys coda reset offset
        LDR	R2, [R1, #0x0]		//; release cmu coda reset
        ORR	R2, #0x40000000		//; cmu sys coda reset release
        STR	R2, [R1, #0x0]		//; release cmu coda reset

	MOV	R1, #0x20000000
	ORR	R1, R1, #0x00210000	//; cmu coda base
        LDR	R2, [R1, #0x408]	//; release axi sram reset
        ORR	R2, #0x00000001		//; axi sram reset release
        STR	R2, [R1, #0x408]	//; release axi sram reset

//;	MOV	R1, #0x20000000
//;	ORR	R1, R1, #0x00210000	//; cmu coda base
	ORR	R1, R1, #0x00008000	//; cmu coda sram offset
        LDR	R2, [R1, #0x0]		//; release axi sram reset
        ORR	R2, #0x00000060		//; axi sram reset release
        STR	R2, [R1, #0x0]		//; release axi sram reset

//;=============================================================================
//; Clear SRAM
//;=============================================================================
//;	MOV	R1, #0x10000000
//;	ADD	R1, R1, #(INTERNAL_SRAM_SIZE/2)
//;	ADD	R2, R1, #(INTERNAL_SRAM_SIZE/2)
//;	MOV	R3, #0
//;	MOV	R4, #0
//;	MOV	R5, #0
//;	MOV	R6, #0
//;	MOV	R7, #0
//;	MOV	R8, #0
//;	MOV	R9, #0
//;	MOV	R10, #0
//;clearsram:
//;	STM	R1!, {R3-R10}
//;	CMP	R1, R2
//;	BLT	clearsram

//;=============================================================================
//; Setup stacks
//;=============================================================================
	MOV	SP, #0x10000000
	ADD	SP, SP, #INTERNAL_SRAM_SIZE	//; PHY_BASEADDR_SRAM 0x10000000 + INTERNAL_SRAM_SIZE

	BL	iROMBOOT			//; save this in register for possible long jump

        BX      R0				//; jump to R0
	MOV	PC, #0				//; Never Get Here

//;=============================================================================
//; End of startup.s
//;=============================================================================
