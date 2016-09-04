/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : romboot
 *	File            : lib_plat.S
 *	Description     :
 *	Author          : Firware Team
 *	History         : 2016.09.04 Hans Create
 */

#ifdef NXP5430
#define UART0_BASE		0xC00A1000
#define UART1_BASE		0xC00A0000
#define UART2_BASE		0xC00A2000
#define UART3_BASE		0xC00A3000

#define PLAT_UART_BASE		UART3_BASE
#endif

#ifdef NXP5540
#define UART0_BASE		0x21880000

#define PLAT_UART_BASE		UART0_BASE
#endif
/* NX_UART Registers */
#define UARTFSTATUS		0x18 /* FIFO Status */
#define UARTTXH			0x20 /* Transmit Buffer */

#define NX_UARTFR_TXFF		(1 << 5) /* Transmit FIFO full */

#define NX_UARTFSTATUS_TXFF_BIT 24
				/* Transmit FIFO full bit in UARTFR register */

/* The offset to add to get ascii for numerals '0 - 9' */
#define ASCII_OFFSET_NUM        0x30

/* ---------------------------------------------
 * int plat_crash_console_putc(int c)
 * Function to print a character on the crash
 * console without a C Runtime.
 * Clobber list : x1, x2
 * ---------------------------------------------
 */
plat_crash_console_putc:
	mov	x1, #(PLAT_UART_BASE & 0xFFFF)
	movk	x1, #(PLAT_UART_BASE >> 16), lsl #16

	/* Check the input parameter */
	cbz     x1, putc_error
	/* Prepend '\r' to '\n' */
	cmp     w0, #0xA
	b.ne    2f
1:
	/* Check if the transmit FIFO is full */
	ldr     w2, [x1, #UARTFSTATUS]
	tbnz    w2, #NX_UARTFSTATUS_TXFF_BIT, 1b
	mov     w2, #0xD
	str     w2, [x1, #UARTTXH]
2:
	/* Check if the transmit FIFO is full */
	ldr     w2, [x1, #UARTFSTATUS]
	tbnz    w2, #NX_UARTFSTATUS_TXFF_BIT, 2b
	str     w0, [x1, #UARTTXH]
	ret
putc_error:
	mov     w0, #-1
	ret

/*
 * This function prints a string from address in x4.
 * In: x4 = pointer to string.
 * Clobber: x30, x0, x1, x2, x3
 */
.global asm_print_str
asm_print_str:
	mov     x3, x30
3:
	ldrb    w0, [x4], #0x1
	cbz     x0, 4f
	bl      plat_crash_console_putc
	b       3b
4:
	ret     x3
	/*
	 * This function prints a hexadecimal number in x4.
	 * In: x4 = the hexadecimal to print.
	 * Clobber: x30, x0, x5, x1, x2, x3
	 */
asm_print_hex:
	mov     x3, x30
	mov     x5, #64  /* No of bits to convert to ascii */
1:
	sub     x5, x5, #4
	lsrv    x0, x4, x5
	and     x0, x0, #0xf
	cmp     x0, #0xA
	b.lo    2f
	/* Add by 0x27 in addition to ASCII_OFFSET_NUM
	 * to get ascii for characters 'a - f'.
	 */
	add     x0, x0, #0x27
2:
	add     x0, x0, #ASCII_OFFSET_NUM
	bl      plat_crash_console_putc
	cbnz    x5, 1b
	ret     x3

.global plat_report_exception
plat_report_exception:
	mov     x8, x30

	adr     x4, plat_err_str
	bl      asm_print_str

	adr     x4, esr_el3_str
	bl      asm_print_str

	mrs     x4, esr_el3
	bl      asm_print_hex

	adr     x4, elr_el3_str
	bl      asm_print_str

	mrs     x4, elr_el3
	bl      asm_print_hex

	mov     x30, x8
	ret
.section .rodata.rev_err_str, "aS"
plat_err_str:
	.asciz "\nPlatform exception reporting:"
esr_el3_str:
	.asciz "\nESR_EL3: "
elr_el3_str:
	.asciz "\nELR_EL3: "
