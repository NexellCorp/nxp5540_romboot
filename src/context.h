/*
 * Copyright (c) 2013-2014, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

/*******************************************************************************
 * Constants that allow assembler code to access members of and the 'gp_regs'
 * structure at their correct offsets.
 ******************************************************************************/
#define CTX_GPREGS_OFFSET       0x0
#define CTX_GPREG_X0            0x0
#define CTX_GPREG_X1            0x8
#define CTX_GPREG_X2            0x10
#define CTX_GPREG_X3            0x18
#define CTX_GPREG_X4            0x20
#define CTX_GPREG_X5            0x28
#define CTX_GPREG_X6            0x30
#define CTX_GPREG_X7            0x38
#define CTX_GPREG_X8            0x40
#define CTX_GPREG_X9            0x48
#define CTX_GPREG_X10           0x50
#define CTX_GPREG_X11           0x58
#define CTX_GPREG_X12           0x60
#define CTX_GPREG_X13           0x68
#define CTX_GPREG_X14           0x70
#define CTX_GPREG_X15           0x78
#define CTX_GPREG_X16           0x80
#define CTX_GPREG_X17           0x88
#define CTX_GPREG_X18           0x90
#define CTX_GPREG_X19           0x98
#define CTX_GPREG_X20           0xa0
#define CTX_GPREG_X21           0xa8
#define CTX_GPREG_X22           0xb0
#define CTX_GPREG_X23           0xb8
#define CTX_GPREG_X24           0xc0
#define CTX_GPREG_X25           0xc8
#define CTX_GPREG_X26           0xd0
#define CTX_GPREG_X27           0xd8
#define CTX_GPREG_X28           0xe0
#define CTX_GPREG_X29           0xe8
#define CTX_GPREG_LR            0xf0
#define CTX_GPREG_SP_EL0        0xf8
#define CTX_GPREGS_END          0x100

/*******************************************************************************
 * Constants that allow assembler code to access members of and the 'el3_state'
 * structure at their correct offsets. Note that some of the registers are only
 * 32-bits wide but are stored as 64-bit values for convenience
 ******************************************************************************/
#define CTX_EL3STATE_OFFSET     (CTX_GPREGS_OFFSET + CTX_GPREGS_END)
#define CTX_SCR_EL3             0x0
#define CTX_RUNTIME_SP          0x8
#define CTX_SPSR_EL3            0x10
#define CTX_ELR_EL3             0x18
#define CTX_EL3STATE_END        0x20

/*******************************************************************************
 * Constants that allow assembler code to access members of and the
 * 'el1_sys_regs' structure at their correct offsets. Note that some of the
 * registers are only 32-bits wide but are stored as 64-bit values for
 * convenience
 ******************************************************************************/
#define CTX_SYSREGS_OFFSET      (CTX_EL3STATE_OFFSET + CTX_EL3STATE_END)
#define CTX_SPSR_EL1            0x0
#define CTX_ELR_EL1             0x8
#define CTX_SPSR_ABT            0x10
#define CTX_SPSR_UND            0x18
#define CTX_SPSR_IRQ            0x20
#define CTX_SPSR_FIQ            0x28
#define CTX_SCTLR_EL1           0x30
#define CTX_ACTLR_EL1           0x38
#define CTX_CPACR_EL1           0x40
#define CTX_CSSELR_EL1          0x48
#define CTX_SP_EL1              0x50
#define CTX_ESR_EL1             0x58
#define CTX_TTBR0_EL1           0x60
#define CTX_TTBR1_EL1           0x68
#define CTX_MAIR_EL1            0x70
#define CTX_AMAIR_EL1           0x78
#define CTX_TCR_EL1             0x80
#define CTX_TPIDR_EL1           0x88
#define CTX_TPIDR_EL0           0x90
#define CTX_TPIDRRO_EL0         0x98
#define CTX_DACR32_EL2          0xa0
#define CTX_IFSR32_EL2          0xa8
#define CTX_PAR_EL1             0xb0
#define CTX_FAR_EL1             0xb8
#define CTX_AFSR0_EL1           0xc0
#define CTX_AFSR1_EL1           0xc8
#define CTX_CONTEXTIDR_EL1      0xd0
#define CTX_VBAR_EL1            0xd8

#endif
