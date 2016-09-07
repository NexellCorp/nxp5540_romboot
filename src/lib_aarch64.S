/*                                                                              
 *      Copyright (C) 2012 Nexell Co., All Rights Reserved                      
 *      Nexell Co. Proprietary & Confidential                                   
 *                                                                              
 *      NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE  
 *      AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *      BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
 *      FOR A PARTICULAR PURPOSE.                                               
 *                                                                              
 *      Module          : ARM
 *      File            : lib_aarch64.S
 *      Description     : 
 *      Author          : Hans
 *      History         :
 *			2016.08.10 Hans first draft
 */
#include "nx_etacarinae.h"

	.align 3

.global xget_fcs
//; unsigned int xget_fcs(unsigned int fcs, unsigned long data);
xget_fcs:
	crc32x	w0, w0, x1
	ret

.global iget_fcs
//; unsigned int iget_fcs(unsigned int fcs, unsigned int data);
iget_fcs:
	crc32w	w0, w0, w1
	ret

.global sget_fcs
//; unsigned int sget_fcs(unsigned int fcs, unsigned short data);
sget_fcs:
	crc32h	w0, w0, w1
	ret

.global get_fcs
//; unsigned int get_fcs(unsigned int fcs, unsigned char data);
get_fcs:
	crc32b	w0, w0, w1
	ret

.global GetSaveAArchMode
//;
GetSaveAArchMode:
	mrs	x0, SPSR_EL3
	ubfx	w0, w0, #4, #1			//; nRW bit 0: AArch64, 1: AArch32
	ret

.global GetCPUID
//; unsigned int GetCPUID(void);
GetCPUID:
	mrs	x0, MPIDR_EL1			//; Get our cpu id
	and	x1, x0, #0x3			//; cpu id
	lsr	x0, x0, #8
	and	x0, x0, #0x0F			//; check processor affinity
	orr	x0, x1, x0			//; mark cpu group 0 or 1
	ret

.global GetSCR_EL3
//; unsigned int GetSCR_EL3(void);
GetSCR_EL3:
	mrs	x0, SCR_EL3
	ret

.global SetSCR_EL3
//; void SetSCR_EL3(unsigned int rSCR);
SetSCR_EL3:
	msr	SCR_EL3, x0
	ret

.global SetNS
//; void SetNS(CBOOL bEnable, U32 tmp);
SetNS:
	mrs	x1, SCR_EL3
	bic	x1, x1, #1<<0
	orr	x1, x1, x0
	msr	SCR_EL3, x1
	ret
		
.global GetESR_EL3
//; unsigned int GetESR_EL3(void);
GetESR_EL3:
	mrs	x0, ESR_EL3
	ret

.global GetISR_EL1
//; U32 GetISR_EL1(void);
GetISR_EL1:
	mrs	x0, ISR_EL1
	ret

.global GetSavedAArchMode
//; boot GetSavedAArchMode(void);
GetSavedAArchMode:
	mrs	x0, SPSR_EL3
	ubfx	w0, w0, #4, #1		//; nRW bit 0: AArch64, 1: AArch32
	ret

.global GetSMCCodeFromAArch32
//; unsigned int GetSMCCodeFromAArch32(void);
GetSMCCodeFromAArch32:
	mrs	x0, ELR_EL3
	ldr	w0, [x0, #-4]		//; get smc instruction
	and	w0, w0, 0xf		//; get imm4 [3:0]
	ret

.global GetSMCCodeFromAArch64
//; unsigned int GetSMCCodeFromAArch64(void);
GetSMCCodeFromAArch64:
	mrs	x0, ELR_EL3
	ldr	w0, [x0, #-4]		//; get smc instruction
	ubfx	w0, w0, #5, #16		//; aarch64 smc get imm16 [20:5]
	ret

.global SetMAIR_EL3
SetMAIR_EL3:
	msr	MAIR_EL3, x0
	ret

.global SetSCTLR_EL3
SetSCTLR_EL3:
	b	.
	MSR     SCTLR_EL3, x0
	isb	sy
	RET

.global GetSCTLR_EL3
GetSCTLR_EL3:
	MRS     x0, SCTLR_EL3
	RET

.global SetTCR_EL3
SetTCR_EL3:
	MSR     TCR_EL3, x0
	RET

.global GetTCR_EL3
GetTCR_EL3:
	MRS     x0, TCR_EL3
	RET

.global SetTTBR0_EL3
SetTTBR0_EL3:
	MSR     TTBR0_EL3, x0
	RET

.global InvalidateTLB_All
InvalidateTLB_All:
	TLBI    ALLE3		// All stage 1 TLB at EL1
	MOV     x0, #0
	TLBI    VAE3, x0
	TLBI    VAE3IS, x0
	RET

.global InvalidateIcache_All
InvalidateIcache_All:
	IC      IALLU
	isb     sy
	RET

.global GetBootOption
GetBootOption:
	MRS	x0, TPIDR_EL3
	RET

.global SetBootOption
SetBootOption:
	MSR	TPIDR_EL3, x0
	RET

.global SendFunctionPTR
SendFunctionPTR:
	MSR	TPIDR_EL1, x0
	RET

.global EnterLowLevel
//; void EnterLowLevel(unsigned int *EL1Start, unsigned int rSPSR);
EnterLowLevel:
	msr	ELR_EL3, x0		//; ELx start address
	msr	SPSR_EL3, x1		//; ELx status
	mov	x0, xzr
	mov	x1, #5540
	dsb	sy
	ERET
#if 1
GetILineSize:
	mrs	x2, ctr_el0
	and	x2, x3, #0xF
	mov	x2, #4
	lsl	x2, x2, x3
	ret

GetDLineSize:
	mrs	x3, ctr_el0
	ubfx	x3, x1, #16, #4
	mov	x2, #4
	lsl	x2, x2, x3
	ret

.global	Dcache_flush_range
//; void Dcache_flush_range(U64 addr, U64 size);
Dcache_flush_range:
	mov	x19, x30
	bl	GetDLineSize
	add	x1, x0, x1
	sub	x3, x2, #1
	bic	x0, x0, x3
1:
	dc	cvac, x0	//; flush:civac, clean:cvac, invalidate:ivac
	add	x0, x0, x2
	cmp	x0, x1
	b.lo	1b
	dsb	sy
	mov	x30, x19
	ret
#endif
