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

.global SetNS
//; void SetNS(CBOOL bEnable, U32 tmp);
SetNS:
	mrs	x1, SCR_EL3
	bic	x1, x1, #1<<0
	orr	x1, x1, x0
	msr	SCR_EL3, x1
	ret

.global EnterLowLevel
//; void EnterLowLevel(unsigned int *EL1Start, unsigned int rSPSR);
EnterLowLevel:
	msr	ELR_EL3, x0		//; ELx start address
	msr	SPSR_EL3, x1		//; ELx status
	mov	x0, xzr
	mov	x1, #5540
	dsb	sy
	ERET
