/*==============================================================================
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	Nexell informs that this code and information is provided "as is" base
//	and without warranty of any kind, either expressed or implied, including
//	but not limited to the implied warranties of merchantability and/or
//	fitness for a particular puporse.
//
//	Module		: iSPIBOOT.c
//	File		:
//	Description	:
//	Author		: Hans
//	History		:
//			Hans: 2014.01.12 First implementation
//			Hans: 2016.08.16 modify for nxp5430
==============================================================================*/
#include <nx_etacarinae.h>
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include <nx_debug2.h>


#include <nx_gpio.h>

#ifdef NXP5430
#include <nx_chip.h>
#include <nx_clkgen.h>
#endif
#include <nx_ssp.h>
#include "nx_etacarinae_bootheader.h"

#ifdef NXP5540
#include <nx_resetcontrol_def.h>
#include <nx_clockcontrol_def.h>
#include "cpuif_regmap_framework.h"
#include <nx_chip_sfr.h>
#include <nx_chip_iomux.h>
#endif

#include "libarm.h"
#include "libplat.h"

/*----------------------------------------------------------------------------*/

#define SER_WREN	0x06	/* Set Write Enable Latch */
#define SER_WRDI	0x04	/* Reset Write Enable Latch */
#define SER_RDSR	0x05	/* Read Status Register */
#define SER_WRSR	0x01	/* Write Status Register */
#define SER_READ	0x03	/* Read Data from Memory Array */
#define SER_WRITE	0x02	/* Write Data to Memory Array */

#define SER_SR_READY	(1 << 0)	/* Ready bit */
#define SER_SR_WEN	(1 << 1)	/* Write Enable indicate 0:not write enabled 1:write enabled */
#define SER_SR_BPx	(3 << 2)	/* Block Write Protect bits */
#define SER_SR_WPEN	(1 << 7)	/* Write Protect Enable bit */


/*#define SPI_SOURCE_CLOCK	NX_CLKSRCPLL2_FREQ */
#define SPI_SOURCE_DIVIDOVER	(8UL)		/* 550000000/8/2 = 34.375MHz */
#define SPI_SOURCE_DIVIDHIGH	(18UL)		/* 550000000/18/2 = 15.277778MHz */
#define SPI_SOURCE_DIVIDLOW	(48UL)		/* 96000000/48/2 = 1.000000MHz */

/*
spi 0
clk c 29 1 gpio:0
frm c 30 1 gpio:0
txd c 31 1 gpio:0
rxd d 0  1 gpio:0

spi 1
clk e 14 2 gpio:0
frm e 15 2 gpio:0
rxd e 18 2 gpio:0
txd e 19 2 gpio:0

spi 2
clk c 9  2 gpio:1 default 0
frm c 10 2 gpio:1 default 0
rxd c 11 2 gpio:1 default 0
txd c 12 2 gpio:1 default 0
*/
//------------------------------------------------------------------------------
extern struct NX_GPIO_RegisterSet (* const pGPIOReg)[1];
#ifdef NXP5430
static struct NX_SSP_RegisterSet * const pgSSPSPIReg[3] =
{
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SSP0_MODULE,
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SSP1_MODULE,
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SSP2_MODULE
};
static struct NX_CLKGEN_RegisterSet * const pgSSPClkGenReg[3] =
{
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN37_MODULE,
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN38_MODULE,
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN39_MODULE
};


static U32 const SPIResetNum[6] =
{
	RESETINDEX_OF_SSP0_MODULE_PRESETn,
	RESETINDEX_OF_SSP0_MODULE_nSSPRST,
	RESETINDEX_OF_SSP1_MODULE_PRESETn,
	RESETINDEX_OF_SSP1_MODULE_nSSPRST,
	RESETINDEX_OF_SSP2_MODULE_PRESETn,
	RESETINDEX_OF_SSP2_MODULE_nSSPRST
};
#endif
#ifdef NXP5540
static struct NX_SSP_RegisterSet * const pgSSPSPIReg[3] =
{
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SPI0_MODULE,
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SPI1_MODULE,
	(struct NX_SSP_RegisterSet *)PHY_BASEADDR_SPI2_MODULE
};
static const union nxpad spipad[3][4] = {
{
	{PADI_SSP0_MISO},
	{PADI_SSP0_MOSI},
	{PADI_SSP0_SSPCLK_IO},
	{PADI_SSP0_SSPFSS}
},
{
	{PADI_SSP1_MISO},
	{PADI_SSP1_MOSI},
	{PADI_SSP1_SSPCLK_IO},
	{PADI_SSP1_SSPFSS}
},
{
	{PADI_SSP2_MISO},
	{PADI_SSP2_MOSI},
	{PADI_SSP2_SSPCLK_IO},
	{PADI_SSP2_SSPFSS}
}};

#endif
void SPIPortInit(U32 SPIPort)
{
#ifdef NXP5430
	if (SPIPort == 0) {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_F];
		pGPIOxReg->GPIOx_ALTFN[0] =
			(pGPIOxReg->GPIOx_ALTFN[0] & ~0xF0000000) | 0x50000000; // spi 0 gpio f 15 alt 1, 14 alt 1
		pGPIOxReg->GPIOx_ALTFN[1] =
			(pGPIOxReg->GPIOx_ALTFN[1] & ~0x0000000F) | 0x00000005;	// spi 0 gpio f 17 alt 1, 16 alt 1

		pGPIOxReg->GPIOx_SLEW &= ~(1<<17 | 1<<16 | 1<<14);                                  // txd, clk, frm
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_DRV0 |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_DRV1 |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_PULLSEL |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<17 | 1<<16 | 1<<14);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<17 | 1<<16 | 1<<14);
	} else if (SPIPort == 1) {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_F];
		pGPIOxReg->GPIOx_ALTFN[1] =
			(pGPIOxReg->GPIOx_ALTFN[1] & ~0x00000FF0) | 0x00000550;	// spi 1 gpio f 21 alt 1, 20 alt 1, 19 alt 1, 18 alt 1

		pGPIOxReg->GPIOx_SLEW &= ~(1<<21 | 1<<20 | 1<<18);                                  // txd, clk, frm
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_DRV0 |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_DRV1 |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_PULLSEL |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<21 | 1<<20 | 1<<18);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<21 | 1<<20 | 1<<18);
	} else {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_F];
		pGPIOxReg->GPIOx_ALTFN[1] =
			(pGPIOxReg->GPIOx_ALTFN[1] & ~0x000FF000) | 0x00055000; // spi2 gpio f 25 alt 1, 24 alt 1, 23 alt 1, 22 alt 1

		pGPIOxReg->GPIOx_SLEW &= ~(1<<25 | 1<<24 | 1<<22);							        // txd, clk, frm
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_DRV0 |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_DRV1 |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_PULLSEL |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<25 | 1<<24 | 1<<22);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<25 | 1<<24 | 1<<22);
	}
#endif

#ifdef NXP5540
	U32 i;
	for (i = 0; i < 4; i++) {
		GPIOSetAltFunction(&spipad[SPIPort][i].padi, CTRUE);
		GPIOSetDrvSt(&spipad[SPIPort][i].padi, NX_GPIO_DRVSTRENGTH_3);
		GPIOSetPullup(&spipad[SPIPort][i].padi, NX_GPIO_PULL_OFF);
	}
#endif
}
void SPIPortDeinit(U32 SPIPort)
{
#ifdef NXP5430
	if (SPIPort == 0) {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_C];

		pGPIOxReg->GPIOx_OUT |= 0x40000000;
		pGPIOxReg->GPIOx_OUTENB &= ~0x40000000;
		pGPIOxReg->GPIOx_ALTFN[1] &= ~0xFC000000;	// spi 0 gpio c 29 alt 0, 30 alt 0, 31 alt 0

		pGPIOxReg->GPIOx_SLEW |= (1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_DRV0 &= ~(1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_DRV1 &= ~(1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_PULLSEL &= ~(1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<31 | 1<<30 | 1<<29);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<31 | 1<<30 | 1<<29);

		pGPIOxReg = (struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_D];
		pGPIOxReg->GPIOx_ALTFN[0] &= ~0x00000003;	// spi 0 gpio d 0 alt 0
	} else if (SPIPort == 1) {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_E];

		pGPIOxReg->GPIOx_OUT |= 0x00008000;
		pGPIOxReg->GPIOx_OUTENB &= ~0x00008000;
		pGPIOxReg->GPIOx_ALTFN[0] &= ~0xF0000000;	// spi 1 gpio e 14 alt 0, 15 alt 0

		pGPIOxReg->GPIOx_ALTFN[1] &= ~0x000000F0;	// spi 1 gpio e 18 alt 0, 19 alt 0

		pGPIOxReg->GPIOx_SLEW |= (1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_DRV0 &= ~(1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_DRV1 &= ~(1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_PULLSEL &= ~(1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<19 | 1<<15 | 1<<14);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<19 | 1<<15 | 1<<14);
	} else {
		register struct NX_GPIO_RegisterSet * pGPIOxReg =
			(struct NX_GPIO_RegisterSet *)&pGPIOReg[GPIO_GROUP_C];

		pGPIOxReg->GPIOx_OUT |= 0x00000400;
		pGPIOxReg->GPIOx_OUTENB &= ~0x00000400;
		pGPIOxReg->GPIOx_ALTFN[0] &= ~(3<<(12*2) | 3<<(11*2) | 3<<(10*2) | 3<<(9*2));	// spi 2 gpio c 9, 10, 11, 12 alt 2

		pGPIOxReg->GPIOx_SLEW |= (1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_SLEW_DISABLE_DEFAULT |= (1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_DRV0 &= ~(1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_DRV0_DISABLE_DEFAULT |= (1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_DRV1 &= ~(1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_DRV1_DISABLE_DEFAULT |= (1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_PULLSEL &= ~(1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_PULLSEL_DISABLE_DEFAULT |= (1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_PULLENB &= ~(1<<12 | 1<<10 | 1<<9);
		pGPIOxReg->GPIOx_PULLENB_DISABLE_DEFAULT |= (1<<12 | 1<<10 | 1<<9);
	}
#endif

#ifdef NXP5540
	for (i = 0; i < 4; i++) {
		GPIOSetAltFunction(&spipad[SPIPort][i].padi, CFALSE);
		GPIOSetDrvSt(&spipad[SPIPort][i].padi, NX_GPIO_DRVSTRENGTH_3);
		GPIOSetPullup(&spipad[SPIPort][i].padi, NX_GPIO_PULL_OFF);
	}
#endif
}

void SPIInit(U32 SPIPort, U32 option)
{
	register struct NX_SSP_RegisterSet * const pSSPSPIReg =
						pgSSPSPIReg[SPIPort];
#ifdef NXP5540
	if (SPIPort == 0) {
		U32 regval;
		//nx_cpuif_reg_write_one(CMUI_SPI_0_CORE_group_clock_source, 0);                                // clock source
		nx_cpuif_reg_write_one(CMUI_SPI_0_CORE_dy_div_val,
				(SPI_SOURCE_DIVIDOVER - 1));      // clock divider value
		while (1 == nx_cpuif_reg_read_one(CMUI_SPI_0_CORE_dy_div_busy_st, &regval));
		nx_cpuif_reg_write_one(CMUI_SPI_0_CORE_clk_enb, 1);                                      // clock enable

		/////////////////////////////////////////////////////
		// @modified by choiyk 2016.08.25 pm0400. 
		// S/W stop-and-go for SPI reset 
		//---------------------------------------------------
		// [original code]
		// nx_cpuif_reg_write_one(CMUI_SPI_0_APB_clk_enb, 1);                                       // clock enable
		// nx_cpuif_reg_write_one(RSTI_spi_0_apb_rst, 1);                                           // reset enable
		//---------------------------------------------------
		//
		// sw code must be 
		//
		// clock off -> reset mode 1 -> reset on -> clock on		
		//
		//---------------------------------------------------
		nx_cpuif_reg_write_one(CMUI_SPI_0_APB_clk_enb , 0); // clock disable
		nx_cpuif_reg_write_one(CMUI_SPI_0_CORE_clk_enb, 0); // clock disable

		nx_cpuif_reg_write_one(RSTM_spi_0_apb_rst, 1); // reset mode must be 1 
		nx_cpuif_reg_write_one(RSTI_spi_0_apb_rst, 1); // reset enable

		nx_cpuif_reg_write_one(CMUI_SPI_0_APB_clk_enb , 1); // clock enable
		nx_cpuif_reg_write_one(CMUI_SPI_0_CORE_clk_enb, 1); // clock enable
		/////////////////////////////////////////////////////
	} else if (SPIPort == 1) {
		U32 regval;
		//nx_cpuif_reg_write_one(CMUI_SPI_1_CORE_group_clock_source, 0);                                // clock source
		nx_cpuif_reg_write_one(CMUI_SPI_1_CORE_dy_div_val,
				(SPI_SOURCE_DIVIDOVER - 1));      // clock divider value
		while (1 == nx_cpuif_reg_read_one(CMUI_SPI_1_CORE_dy_div_busy_st, &regval));
		nx_cpuif_reg_write_one(CMUI_SPI_1_CORE_clk_enb, 1);                                      // clock enable

		//nx_cpuif_reg_write_one(CMUI_SPI_1_APB_clk_enb, 1);                                       // clock enable
		//nx_cpuif_reg_write_one(RSTI_spi_1_apb_rst, 1);                                                   // reset enable

		nx_cpuif_reg_write_one(CMUI_SPI_1_APB_clk_enb , 0); // clock disable
		nx_cpuif_reg_write_one(CMUI_SPI_1_CORE_clk_enb, 0); // clock disable

		nx_cpuif_reg_write_one(RSTM_spi_1_apb_rst, 1); // reset mode must be 1 
		nx_cpuif_reg_write_one(RSTI_spi_1_apb_rst, 1); // reset enable

		nx_cpuif_reg_write_one(CMUI_SPI_1_APB_clk_enb , 1); // clock enable
		nx_cpuif_reg_write_one(CMUI_SPI_1_CORE_clk_enb, 1); // clock enable
	} else {
		U32 regval;
		//nx_cpuif_reg_write_one( CMUI_SPI_2_CORE_group_clock_source, 0 );                                // clock source
		nx_cpuif_reg_write_one(CMUI_SPI_2_CORE_dy_div_val,
				(SPI_SOURCE_DIVIDOVER - 1));      // clock divider value
		while (1 == nx_cpuif_reg_read_one(CMUI_SPI_2_CORE_dy_div_busy_st, &regval));
		nx_cpuif_reg_write_one(CMUI_SPI_2_CORE_clk_enb, 1);                                      // clock enable

		//nx_cpuif_reg_write_one(CMUI_SPI_2_APB_clk_enb, 1);                                       // clock enable
		//nx_cpuif_reg_write_one(RSTI_spi_2_apb_rst, 1);                                                   // reset enable

		nx_cpuif_reg_write_one(CMUI_SPI_2_APB_clk_enb , 0); // clock disable
		nx_cpuif_reg_write_one(CMUI_SPI_2_CORE_clk_enb, 0); // clock disable

		nx_cpuif_reg_write_one(RSTM_spi_2_apb_rst, 1); // reset mode must be 1 
		nx_cpuif_reg_write_one(RSTI_spi_2_apb_rst, 1); // reset enable

		nx_cpuif_reg_write_one(CMUI_SPI_2_APB_clk_enb , 1); // clock enable
		nx_cpuif_reg_write_one(CMUI_SPI_2_CORE_clk_enb, 1); // clock enable
	}
#endif


	if (option & 1 << SERIALFLASHSPEED)
		pSSPSPIReg->CH_CFG =
			1 << 6 |	// high speed en (0:low speed, 1:high speed)
			0 << 4 |	// master mode (0:master mode, 1:slave mode)
			0 << 2 |	// active high, format a
			0 << 1 |	// rx channel on (0:off, 1:on)
			0 << 0;		// tx channel on
	else
		pSSPSPIReg->CH_CFG =
			0 << 6 |	// high speed en (0:low speed, 1:high speed)
			0 << 4 |	// master mode (0:master mode, 1:slave mode)
			0 << 2 |	// active high, format a
			0 << 1 |	// rx channel on (0:off, 1:on)
			0 << 0;		// tx channel on

	pSSPSPIReg->MODE_CFG =
		0 << 29 |		// channel width (0:byte, 1:half word, 2:word)
		0 << 17 |		// bus width
		0 << 11 |		// rx fifo trigger level
		0 <<  5 |		// tx fifo trigger level
		0 <<  2 |		// rx dma mode (0:disable, 1:enable)
		0 <<  1 |		// tx dma mode
		0 <<  0;		// dma transfer type (0:single, 1:4 burst)

	pSSPSPIReg->CS_REG =
		0 << 1 |		// chip select toggle(0:auto, 1:manual)
		1 << 0;			// chip select state (0: active, 1:inactive)


	pSSPSPIReg->SPI_INT_EN = 0;		// all interrupt disasble
}

U32 iSPIBOOT(U32 option)
{
	register struct NX_SecondBootInfo *pSBI;
	register U8 *pdwBuffer = (U8*)BASEADDR_SRAM;
	register U32 iRxSize = 0;
	register U32 SPIPort = (option >> SELSPIPORT) & 0x1;
	CBOOL ret = CFALSE;//, bHighSpeed = CFALSE;

	if (option & 1 << SELSPIPORT1)
		SPIPort += 2;

	if (SPIPort >= 3) {
		SPIPort = 0;
//		bHighSpeed = CTRUE;     // ??
	}
	register struct NX_SSP_RegisterSet * const pSSPSPIReg =
						pgSSPSPIReg[SPIPort];
	printf("SPI Boot Port:%d\r\n", SPIPort);

	SPIInit(SPIPort, option);

	SPIPortInit(SPIPort);

	pSSPSPIReg->CS_REG &= ~(1<<0);		// chip select state to active

	pSSPSPIReg->CH_CFG |= 3<<0;			// rx, tx channel on

	pSSPSPIReg->SPI_TX_DATA = SER_READ;		// read command, Read Data from Memory Array

	if ((option >> SERIALFLASHADDR) & 0x1)
		pSSPSPIReg->SPI_TX_DATA = 0;		// start memory array address high byte
	pSSPSPIReg->SPI_TX_DATA = 0;			// start memory array address high byte
	pSSPSPIReg->SPI_TX_DATA = 0;			// start memory array address mid byte
	pSSPSPIReg->SPI_TX_DATA = 0;			// start memory array address low byte

	while (pSSPSPIReg->SPI_STATUS & 0x1FF << 6);	// wait while TX fifo counter is not 0
	while (!(pSSPSPIReg->SPI_STATUS & 0x1 << 25));	// wait for TX fifo is empty
	while (pSSPSPIReg->SPI_STATUS >> 15 & 0x1FF)	// while RX fifo is not empty
		pSSPSPIReg->SPI_RX_DATA;		// discard RX data cmd & address

	pSSPSPIReg->SPI_TX_DATA = 0xAA;			// send dummy data for receive read data.
	pSSPSPIReg->SPI_TX_DATA = 0xAA;			// send dummy data for receive read data.
	pSSPSPIReg->SPI_TX_DATA = 0xAA;			// send dummy data for receive read data.
	pSSPSPIReg->SPI_TX_DATA = 0xAA;			// send dummy data for receive read data.

	while (!(pSSPSPIReg->SPI_STATUS >> 15 & 0x1FF));	// wait RX fifo is not empty
	while (512 > iRxSize) {
		if (pSSPSPIReg->SPI_STATUS >> 15 & 0x1FF) {	// wait RX fifo is not empty
			pSSPSPIReg->SPI_TX_DATA = 0xAA; 		// send dummy data for receive read data.
			pdwBuffer[iRxSize] = (U8)pSSPSPIReg->SPI_RX_DATA;
			iRxSize++;
		}
	}

	if (option & 1 << DECRYPT)
		Decrypt((U32*)pdwBuffer, (U32*)pdwBuffer, 512);

	pSBI = (struct NX_SecondBootInfo *)pdwBuffer;

	if (pSBI->SIGNATURE == HEADER_ID) {
		U32 i, fcs, BootSize = pSBI->LOADSIZE;

		if (BootSize > INTERNAL_SRAM_SIZE - SECONDBOOT_STACK)
			BootSize = INTERNAL_SRAM_SIZE - SECONDBOOT_STACK;

		pdwBuffer = (U8*)(BASEADDR_SRAM + sizeof(struct NX_SecondBootInfo));
		iRxSize = 0;
		while (BootSize > iRxSize) {
			if (pSSPSPIReg->SPI_STATUS >> 15 & 0x1FF) {	// wait RX fifo is not empty
				pSSPSPIReg->SPI_TX_DATA = 0xAA; 		// send dummy data for receive read data.
				pdwBuffer[iRxSize] = (U8)pSSPSPIReg->SPI_RX_DATA;
				iRxSize++;
			}
		}

		if (option & 1 << DECRYPT)
			Decrypt((U32*)pdwBuffer, (U32*)pdwBuffer, BootSize);

		fcs = 0;
		for (i = 0; i < BootSize; i++)
			fcs = get_fcs(fcs, pdwBuffer[i]);

		if (fcs != 0 && fcs == pSBI->DBI.SPIBI.CRC32)
			ret = CTRUE;
	}

	while (pSSPSPIReg->SPI_STATUS & 0x1FF << 6);	// wait while TX fifo counter is not 0
	while (!(pSSPSPIReg->SPI_STATUS & 0x1 << 25));	// wait for TX fifo is empty
	while ((pSSPSPIReg->SPI_STATUS >> 15) & 0x1FF)	// while RX fifo is not empty
		pSSPSPIReg->SPI_RX_DATA;		// RX data read

	printf("Download completed!\n");

	pSSPSPIReg->CH_CFG &= ~(3 << 0);	// rx, tx channel off
	pSSPSPIReg->CS_REG |= 1 << 0;		// chip select state to inactive

	SPIPortDeinit(SPIPort);

	return ret;
}
