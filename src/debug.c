//------------------------------------------------------------------------------
/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module		:
 *	File		: debug.c
 *	Description	:
 *	Author		: Hans
 *	History		: 
 *
 */
#include <nx_uart.h>
#include "libarm.h"
#include "libplat.h"

#ifdef NXP5430
#include <nx_chip.h>
#include <nx_tieoff.h>
#include <nx_clkgen.h>
#endif

#ifdef NXP5540
#include "cpuif_regmap_framework.h"
#include <nx_chip_iomux.h>
#include <nx_chip_sfr.h>
#include <nx_clockcontrol_def.h>
#include <nx_resetcontrol_def.h>
#endif

#define NX_CLKSRC_UART 1
#define SOURCE_DIVID	(4UL)
#define BAUD_RATE	(115200)


#ifdef NXP5430
const U32 UARTBASEADDR[] =
{
	PHY_BASEADDR_UART0_MODULE,
	PHY_BASEADDR_pl01115_Uart_modem_MODULE,
	PHY_BASEADDR_UART1_MODULE,
	PHY_BASEADDR_pl01115_Uart_nodma0_MODULE,
	PHY_BASEADDR_pl01115_Uart_nodma1_MODULE,
	PHY_BASEADDR_pl01115_Uart_nodma2_MODULE
};
const U32 UARTCLKGENADDR[] =
{
	PHY_BASEADDR_CLKGEN22_MODULE,
	PHY_BASEADDR_CLKGEN24_MODULE,
	PHY_BASEADDR_CLKGEN23_MODULE,
	PHY_BASEADDR_CLKGEN25_MODULE,
	PHY_BASEADDR_CLKGEN26_MODULE,
	PHY_BASEADDR_CLKGEN27_MODULE
};
const U8 RESETNUM[] =
{
	RESETINDEX_OF_UART0_MODULE_nUARTRST,
	RESETINDEX_OF_pl01115_Uart_modem_MODULE_nUARTRST,
	RESETINDEX_OF_UART1_MODULE_nUARTRST,
	RESETINDEX_OF_pl01115_Uart_nodma0_MODULE_nUARTRST,
	RESETINDEX_OF_pl01115_Uart_nodma1_MODULE_nUARTRST,
	RESETINDEX_OF_pl01115_Uart_nodma2_MODULE_nUARTRST
};
const U32 GPIOALTNUM[] =
{
	PADINDEX_OF_UART0_UARTRXD,
	PADINDEX_OF_UART0_UARTTXD,
	PADINDEX_OF_pl01115_Uart_modem_UARTRXD,
	PADINDEX_OF_pl01115_Uart_modem_UARTTXD,
	PADINDEX_OF_UART1_UARTRXD,
	PADINDEX_OF_UART1_UARTTXD,
	PADINDEX_OF_pl01115_Uart_nodma0_UARTRXD,
	PADINDEX_OF_pl01115_Uart_nodma0_UARTTXD,
	PADINDEX_OF_pl01115_Uart_nodma1_UARTRXD,
	PADINDEX_OF_pl01115_Uart_nodma1_UARTTXD,
	PADINDEX_OF_pl01115_Uart_nodma2_UARTRXD,
	PADINDEX_OF_pl01115_Uart_nodma2_UARTTXD
};
const U32 UARTSMC[] =
{
	TIEOFFINDEX_OF_UART0_USESMC,
	TIEOFFINDEX_OF_UART0_SMCTXENB,
	TIEOFFINDEX_OF_UART0_SMCRXENB,
	TIEOFFINDEX_OF_UART2_USESMC,
	TIEOFFINDEX_OF_UART2_SMCTXENB,
	TIEOFFINDEX_OF_UART2_SMCRXENB,
	TIEOFFINDEX_OF_UART1_USESMC,
	TIEOFFINDEX_OF_UART1_SMCTXENB,
	TIEOFFINDEX_OF_UART1_SMCRXENB,
	TIEOFFINDEX_OF_UART3_USESMC,
	TIEOFFINDEX_OF_UART3_SMCTXENB,
	TIEOFFINDEX_OF_UART3_SMCRXENB,
	TIEOFFINDEX_OF_UART4_USESMC,
	TIEOFFINDEX_OF_UART4_SMCTXENB,
	TIEOFFINDEX_OF_UART4_SMCRXENB,
	TIEOFFINDEX_OF_UART5_USESMC,
	TIEOFFINDEX_OF_UART5_SMCTXENB,
	TIEOFFINDEX_OF_UART5_SMCRXENB
};
#endif

#ifdef NXP5430
static struct NX_TIEOFF_RegisterSet * const pReg_Tieoff =
	(struct NX_TIEOFF_RegisterSet *)PHY_BASEADDR_TIEOFF_MODULE;
static struct NX_UART_RegisterSet * pReg_Uart;
#endif

#ifdef NXP5540
#define PADI_UART0_TXD			((1 << 16) | (4 << 8) | (24 << 3) | 1)
static struct NX_UART_RegisterSet * const pReg_Uart =
		(struct NX_UART_RegisterSet *)PHY_BASEADDR_UART0_MODULE;
#endif
//------------------------------------------------------------------------------

CBOOL DebugInit(U32 port)
{
	U32 SOURCE_CLOCK = 147456000;
#ifdef NXP5430
	pReg_Uart = (struct NX_UART_RegisterSet *)((MPTRS)UARTBASEADDR[port]);
	struct NX_CLKGEN_RegisterSet * const pReg_UartClkGen =
		(struct NX_CLKGEN_RegisterSet * const)((MPTRS)UARTCLKGENADDR[port]);
	U32 reset_number = RESETNUM[port];
	U32 GPIO_TXD = GPIOALTNUM[port * 2 + 1];

	GPIOSetAltFunction(GPIO_TXD);

	pReg_Tieoff->TIEOFFREG[((UARTSMC[port * 3 + 0]) & 0xFFFF) >> 5] &=
				(~(1 << ((UARTSMC[port * 3 + 0]) & 0x1F)));
	pReg_Tieoff->TIEOFFREG[((UARTSMC[port * 3 + 1]) & 0xFFFF) >> 5] &=
				(~(1 << ((UARTSMC[port * 3 + 1]) & 0x1F)));
	pReg_Tieoff->TIEOFFREG[((UARTSMC[port * 3 + 2]) & 0xFFFF) >> 5] &=
				(~(1 << ((UARTSMC[port * 3 + 2]) & 0x1F)));

	ResetCon(reset_number, CTRUE);	// reset on
	ResetCon(reset_number, CFALSE); // reset negate

	pReg_UartClkGen->CLKENB = (1 << 3);	// PCLKMODE : always, Clock Gen Disable
	pReg_UartClkGen->CLKGEN[0] = ((SOURCE_DIVID - 1) << 5) |
					(NX_CLKSRC_UART << 2);
#endif
#ifdef NXP5540
	U32 regval;
	port = port;
	static const union nxpad uartpad = {PADI_UART0_TXD};
	GPIOSetAltFunction((struct nxpadi *)&uartpad, CTRUE);

	nx_cpuif_reg_write_one(CMUI_UART_0_CORE_grp_clk_src, NX_CLKSRC_UART);
	// sdmmc core clock divider value
	nx_cpuif_reg_write_one(CMUI_UART_0_CORE_dy_div_val, (SOURCE_DIVID - 1));
	while (1 == nx_cpuif_reg_read_one(CMUI_UART_0_CORE_dy_div_busy_st, &regval));

	// UART clock disable
	nx_cpuif_reg_write_one(CMUI_UART_0_CORE_clk_enb, 0);
	nx_cpuif_reg_write_one(CMUI_UART_0_APB_clk_enb , 0);

	// UART reset mode config
	nx_cpuif_reg_write_one(RSTM_uart_0_core_rst, 1);
	nx_cpuif_reg_write_one(RSTM_uart_0_apb_rst , 1);

	// UART reset release
	nx_cpuif_reg_write_one(RSTI_uart_0_core_rst, 1);
	nx_cpuif_reg_write_one(RSTI_uart_0_apb_rst , 1);

	// UART clock enable
	nx_cpuif_reg_write_one(CMUI_UART_0_CORE_clk_enb, 1);
	nx_cpuif_reg_write_one(CMUI_UART_0_APB_clk_enb , 1);
#endif

	//--------------------------------------------------------------------------
	pReg_Uart->LCON 	= 0x3;

	pReg_Uart->UCON 	= 0x113340;

	pReg_Uart->FCON 	= 0x441;

	pReg_Uart->MCON 	= 0x00;

	pReg_Uart->BRDR 	= getquotient(
					getquotient(SOURCE_CLOCK, SOURCE_DIVID),
					((BAUD_RATE / 1) * 16)) - 1;
	pReg_Uart->FRACVAL	= getquotient(
					((getremainder(
						getquotient(SOURCE_CLOCK,
							SOURCE_DIVID),
						((BAUD_RATE / 1) * 16)) + 32) * 16),
					((BAUD_RATE / 1) * 16));

#ifdef NXP5430
	// PCLKMODE : always, Clock Gen Enable
	pReg_UartClkGen->CLKENB = (1 << 3) | (1 << 2);
#endif
#ifdef NXP5540
//	nx_cpuif_reg_write_one(CMUI_UART_0_CORE_clk_enb, 1);
#endif


	pReg_Uart->UCON 	= 0x113345;
	//--------------------------------------------------------------------------

	return CTRUE;
}

void	DebugPutch(S8 ch)
{
	const U32 TX_FIFO_FULL = 1 << 24;
#ifdef NXP5430
	while (pReg_Uart->FSTATUS & TX_FIFO_FULL)	{ ; }
#endif
#ifdef NXP5540
	while (pReg_Uart->FSTATUS & TX_FIFO_FULL) {
		pReg_Uart->FSTATUS;
	}
#endif
	pReg_Uart->THR = (U32)ch;
}

CBOOL	DebugIsUartTxDone(void)
{
	const U32 TX_TRANS_EMPTY = 1 << 2;
	if ((pReg_Uart->FSTATUS >> 16) & 0xFF)
		return (CBOOL)CFALSE;
	else
		return (CBOOL)(pReg_Uart->USTATUS & TX_TRANS_EMPTY) ?
				CTRUE : CFALSE;
}

CBOOL	DebugIsTXEmpty(void)
{
	return (CBOOL)((pReg_Uart->FSTATUS >> 16) & 0xFF) ? CFALSE : CTRUE;
}

CBOOL	DebugIsBusy(void)
{
	const U32 TX_TRANS_EMPTY = 1 << 2;
	return (CBOOL)(pReg_Uart->USTATUS & TX_TRANS_EMPTY) ? CTRUE : CFALSE;
}

S8	DebugGetch(void)
{
	const U32 RX_FIFO_EMPTY	= 1 << 4;
	while (pReg_Uart->FSTATUS & RX_FIFO_EMPTY)	{ ; }
	return (S8)pReg_Uart->RBR;
}
