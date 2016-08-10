//------------------------------------------------------------------------------
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//	AND	WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//	FOR A PARTICULAR PURPOSE.
//
//	Module		:
//	File		:
//	Description	:
//	Author		:
//	Export		:
//	History		:
//
//------------------------------------------------------------------------------
#include <nx_peridot.h>
#include <debug.h>

#if defined(NX_DEBUG)
#include <nx_chip.h>

#include <nx_gpio.h>
#include <nx_CLKGEN.h>
#include <nx_uart.h>

#define SOURCE_CLOCK	NX_CLKSRCPLL1_FREQ
#define SOURCE_DIVID	(10UL)				// 147456000/10 = 14745600
#define BAUD_RATE		(115200)

#define BAUD_RATE		(115200)

void ResetCon(U32 devicenum, CBOOL en);
void GPIOSetAltFunction(U32 AltFunc);
U32 get_fcs(U32 fcs, U8 data);

#if DIRECT_IO
extern struct NX_GPIO_RegisterSet (* const pGPIOReg)[1];
#endif
static struct NX_CLKGEN_RegisterSet * const pUartClkGenReg =
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN22_MODULE;
static struct NX_UART_RegisterSet * const pUARTReg =
	(struct NX_UART_RegisterSet *)PHY_BASEADDR_UART0_MODULE;

//------------------------------------------------------------------------------

CBOOL DebugInit(void)
{
#if DIRECT_IO
	register U32 *pGPIOxReg =
		(U32 *)&pGPIOReg[(PADINDEX_OF_UART0_UARTRXD >> 8) & 0x7]->GPIOxALTFN[(PADINDEX_OF_UART0_UARTRXD >> 6) & 0x1];
	*pGPIOxReg = (*pGPIOxReg & ~0x30000000) | 0x10000000;
#else
	 GPIOSetAltFunction(PADINDEX_OF_UART0_UARTRXD);
#endif
	ResetCon(RESETINDEX_OF_UART0_MODULE_nUARTRST, CTRUE);	// reset on
	ResetCon(RESETINDEX_OF_UART0_MODULE_nUARTRST, CFALSE);	// reset negate

	pUartClkGenReg->CLKENB	= (1 << 3);			// PCLKMODE : always, Clock Gen Disable
	pUartClkGenReg->CLKGEN[0]	= ((SOURCE_DIVID - 1) << 5) | (1 << 2);	// UARTCLK = PLL1 / 10 = 147,456,000 / 10 = 14,745,600 Hz

	//--------------------------------------------------------------------------
	pUARTReg->LCR_H	= 0x0070;	// 8 bit, none parity, stop 1, normal mode
	pUARTReg->CR	= 0x0200;	// rx enable

	pUARTReg->IBRD	= (U16)(SOURCE_CLOCK/SOURCE_DIVID / ((BAUD_RATE / 1) * 16));	// IBRD = 8, 115200bps
	pUARTReg->FBRD	= (U16)(SOURCE_CLOCK/SOURCE_DIVID % ((BAUD_RATE / 1) * 16));	// FBRD = 0,

	pUartClkGenReg->CLKENB	= (1 << 3) | (1 << 2);		// PCLKMODE : always, Clock Gen Enable

	return CTRUE;
}

void DebugPutch(S8 ch)
{
	const U16 TX_FIFO_FULL	= 1 << 5;
	while (pUARTReg->FR & TX_FIFO_FULL)	{ ; }
	pUARTReg->DR = (U32)ch;
}

S8 DebugGetch(void)
{
	const U16 RX_FIFO_EMPTY	= 1 << 4;
	while (pUARTReg->FR & RX_FIFO_EMPTY)	{ ; }
	return (S8)pUARTReg->DR;
}

//------------------------------------------------------------------------------

void DebugPutString(const S8* const String)
{
	const S8 *pString;

	pString = (const S8 *)String;
	while (CNULL != *pString)
		DebugPutch(*pString++);
}

S32 DebugGetString(S8* const pStringBuffer)
{
	S8	*pString = pStringBuffer;
	S8	buf;
	S32		iSize	= 0;

	while (1) {
		/* get character */
		buf = DebugGetch();

		/* backspace */
		if (buf == 0x08) {
			if (iSize > 0) {
				DebugPutch(buf);
				DebugPutch(' ');
				DebugPutch(buf);

				pString--;
				iSize--;
			}
			continue;
		}

		/* print character */
		DebugPutch(buf);

		if (buf == '\r')	break;

		/* increase string index */
		*pString++ = buf;
		iSize++;
	}

	*pString++ = '\0';

	return iSize;
}

//------------------------------------------------------------------------------
void DebugPutDec(S32 value)
{
	S8 ch[16];
	U32 data;
	S32	i, chsize;

	data = (value < 0) ? (U32)(-value) : (U32)value;

	chsize = 0;
	do {
		ch[chsize++] = (data % 10) + '0';
		data /= 10;
	} while (data != 0);

	if (value < 0)
		DebugPutch('-');

	for (i = 0; i < chsize; i++)
		DebugPutch(ch[chsize - i - 1]);
}

//------------------------------------------------------------------------------
void	DebugPutHex(S32 value)
{
	S8 ch;
	U32 data;
	S32	i;

	data = (U32)value;

	DebugPutch('0');
	DebugPutch('x');

	for( i=0 ; i<8 ; i++ )
	{
		ch = (S8)(( data >> (28 - i*4) ) & 0xF);
		ch = (ch > 9 ) ? (ch - 10 + 'A') : (ch + '0');
		DebugPutch( ch );
	}
}

//------------------------------------------------------------------------------
void	DebugPutByte( S8 value )
{
	S8 ch;
	U32 data;
	S32	i;

	data = (U32)value;

	for( i=0 ; i<2 ; i++ )
	{
		ch = (S8)(( data >> (4 - i*4) ) & 0xF);
		ch = (ch > 9 ) ? (ch - 10 + 'A') : (ch + '0');
		DebugPutch( ch );
	}
}

//------------------------------------------------------------------------------
void	DebugPutWord( S16 value )
{
	S8 ch;
	U32 data;
	S32	i;

	data = (U32)value;

	for( i=0 ; i<4 ; i++ )
	{
		ch = (S8)(( data >> (12 - i*4) ) & 0xF);
		ch = (ch > 9 ) ? (ch - 10 + 'A') : (ch + '0');
		DebugPutch( ch );
	}
}

//------------------------------------------------------------------------------
void	DebugPutDWord( S32 value )
{
	S8 ch;
	U32 data;
	S32	i;

	data = (U32)value;

	for( i=0 ; i<8 ; i++ )
	{
		ch = (S8)(( data >> (28 - i*4) ) & 0xF);
		ch = (ch > 9 ) ? (ch - 10 + 'A') : (ch + '0');
		DebugPutch( ch );
	}
}

#endif	// NX_DEBUG
