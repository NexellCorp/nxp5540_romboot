
//------------------------------------------------------------------------------
//
//  Copyright (C) 2009 Nexell Co., All Rights Reserved
//  Nexell Co. Proprietary & Confidential
//
//  NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//  AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//  FOR A PARTICULAR PURPOSE.
//
//  Module      : nx_base
//  File        : nx_chip.h
//  Description : support chip information
//  Author      : Goofy
//  Export      :
//  History     :
//      2012-06-27  Gamza remove OFFSET_OF_
//                        refer to PHY_BASEADDR_LIST( x ) in nx_prototype.h
//      2010.07.19  Hans modify to nxp-2120
//      2008.04.17  Goofy first draft.
//------------------------------------------------------------------------------



// SIMIO는 STACK_BASE에 설정한다.




//------------------------------------------------------------------------------
// BAGL RENDERING SETTING [ groupComponent generalInfo.xml ]
//
// DRAM BASE ADDRESS : 0x80000000
// SIMIO BASE ADDRESS: 0x82000000
// is_unit_test =
//------------------------------------------------------------------------------

#include <stddef.h>

#ifndef __NX_CHIP_NXP5540_H__ // __NX_CHIP_P2120_H__
#define __NX_CHIP_NXP5540_H__ // __NX_CHIP_P2120_H__


#include "nx_chip_sfr.h"
#include "nx_chip_tzpc.h"
#include "nx_chip_rst.h"
#include "nx_chip_irq.h"
#include "nx_chip_pll.h"

#define REMOVE_IOMUX_OLD
#ifndef REMOVE_IOMUX_OLD
	#include "nx_chip_iomux_old.h"
#else
	#include "nx_chip_iomux.h"
#endif

#define PADINDEX_OF_PDM0_DATA0  PADINDEX_OF_PDM_DATA0
#define PADINDEX_OF_PDM0_DATA1  PADINDEX_OF_PDM_DATA1
#define PADINDEX_OF_PDM0_STROBE PADINDEX_OF_PDM_STROBE


#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// To remove following waring on RVDS compiler
//      Warning : #66-D: enumeration value is out of "int" range
//------------------------------------------------------------------------------
#ifdef __arm
#pragma diag_remark 66      // disable #66 warining
#endif

//------------------------------------------------------------------------------
// Module declaration.
//------------------------------------------------------------------------------
//      NUMBER_OF_XXX_MODULE
//      PHY_BASEADDR_XXX_MODULE
//------------------------------------------------------------------------------
//  REF EXAMPLE
//  #define NUMBER_OF_SIMIO_MODULE     1
//  #define PHY_BASEADDR_SIMIO_MODULE  0x00100000
//
//  #define NUMBER_OF_OJTDMA_MODULE    1
//  #define PHY_BASEADDR_OJTDMA_MODULE 0xC0017000
//
//  #define NUMBER_OF_INTC_MODULE      1
//  #define PHY_BASEADDR_INTC_MODULE   0xC0010000
// config만 다를 경우, (ex) clkgen_cfg0, clkgen_cfg1 이럴 경우는 어떻게 해야 하는가..?

//------------------------------------------------------------------------------
// BAGL RENDERING
//------------------------------------------------------------------------------

#define NUMBER_OF_SIMIO_MODULE     1
#ifdef ENV_TESTMODE
    #define PHY_BASEADDR_SIMIO_MODULE  0x00400000
#else
    #define PHY_BASEADDR_SIMIO_MODULE  0x82000000
#endif

//-----------
// NUMBER OF MODULES
//-----------
		#define NUMBER_OF_CORE										4
		#define NUMBER_OF_CPUIF_P5QP_MODULE							1
        #define NUMBER_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE     1
        #define NUMBER_OF_MCUSTOP_MODULE                            1
        #define NUMBER_OF_AXISRAM_MODULE                            1
        #define NUMBER_OF_DMA_MODULE                                2
        #define NUMBER_OF_SDMA_MODULE                               2
        #define NUMBER_OF_MDMA_MODULE                               1
        #define NUMBER_OF_DREX_MODULE                               1
        #define NUMBER_OF_CLKPWR_MODULE                             1
        #define NUMBER_OF_INTC_MODULE                               1
        #define NUMBER_OF_pl01115_Uart_modem_MODULE                 1
        #define NUMBER_OF_UART_MODULE                               9
        //#define NUMBER_OF_pl01115_Uart_nodma_MODULE                 3
        #define NUMBER_OF_SSP_MODULE                                3
        // @modified sei 2015-03-20 : add 3 more i2c module
        #define NUMBER_OF_I2C_MODULE                                5
        #define NUMBER_OF_I2S_MODULE                                4
        #define NUMBER_OF_DEINTERLACE_MODULE                        1
        #define NUMBER_OF_SCALER_MODULE                             3 //@modified by choiyk 2015/11/30
        #define NUMBER_OF_AC97_MODULE                               1
        #define NUMBER_OF_SPDIFRX_MODULE                            1
        #define NUMBER_OF_SPDIFTX_MODULE                            1
        #define NUMBER_OF_TIMER_MODULE                              2
        #define NUMBER_OF_PWM_MODULE                                4
        #define NUMBER_OF_CLKGEN_MODULE                             41
        #define NUMBER_OF_WDT_MODULE                                2
        #define NUMBER_OF_MPEGTSI_MODULE                            1
        #define NUMBER_OF_DISPLAYTOP_MODULE                         1
        #define NUMBER_OF_VIP_MODULE                                4
        #define NUMBER_OF_MALI400_MODULE                            1
        #define NUMBER_OF_ADC_MODULE                                1
        #define NUMBER_OF_PPM_MODULE                                1
        #define NUMBER_OF_ahb3x1_MODULE                             1
        #define NUMBER_OF_SDMMC_MODULE                              3
        #define NUMBER_OF_CODA980_MODULE                            1
        #define NUMBER_OF_DWC_GMAC_MODULE                           1
        #define NUMBER_OF_USB20OTG_MODULE                           1
        #define NUMBER_OF_USB20HOST_MODULE                          1
        #define NUMBER_OF_USB3_MODULE                          		1
        #define NUMBER_OF_CAN_MODULE                                2
        #define NUMBER_OF_ECID_MODULE                               1
        #define NUMBER_OF_RSTCON_MODULE                             1
        #define NUMBER_OF_A3BM_AXI_TOP_MASTER_BUS_MODULE            1
        #define NUMBER_OF_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE         1
        #define NUMBER_OF_A3BM_AXI_PERI_BUS_MODULE                  1
        #define NUMBER_OF_A3BM_AXI_DISPLAY_BUS_MODULE               1
        #define NUMBER_OF_GPIO_MODULE                               8
        #define NUMBER_OF_CRYPTO_MODULE                             1
        #define NUMBER_OF_PDM_MODULE                                4
        #define NUMBER_OF_TIEOFF_MODULE                             1
        #define NUMBER_OF_TMCB_MODULE                               4
        #define NUMBER_OF_TMU_MODULE                                1

        #define NUMBER_OF_TZPC_MODULE                               1


	// @added by choiyk 2014/09/15, MLC, DPC
		#define NUMBER_OF_DPC_MODULE 2
		#define NUMBER_OF_MLC_MODULE 2

	// @added by yjkim 2014/12/29, PKA
		#define NUMBER_OF_PKA_MODULE 1

	// @added by choiyk 2015/02/06, ISS_CPUIF
		#define NUMBER_OF_ISS_CPUIF_MODULE 1

	// @added by choiyk 2016/05/18, LVDS
		#define NUMBER_OF_LVDS_MODULE 2
	// @added by yjkim 2015/11/30, WAVE
		#define NUMBER_OF_WAVE412_MODULE 1
		#define NUMBER_OF_WAVE420_MODULE 1
		#define NUMBER_OF_WAVE412_MAPC_MODULE 1

	// @added by charles 2015-12-09, CMU
		#define NUMBER_OF_CMU_BBUS_MODULE		1
		#define NUMBER_OF_CMU_CODA_MODULE   	1
		#define NUMBER_OF_ARMTOP_MODULE			1
		#define NUMBER_OF_ARMTOP_P1_MODULE		1
		#define NUMBER_OF_CMU_DISP_MODULE   	1
		#define NUMBER_OF_CMU_DREX0_MODULE  	1
		#define NUMBER_OF_CMU_DREX1_MODULE  	1
		#define NUMBER_OF_CMU_GPU_MODULE    	1
		#define NUMBER_OF_CMU_HDMI_MODULE   	1
		#define NUMBER_OF_CMU_ISP_MODULE    	1
		#define NUMBER_OF_CMU_LBUS_MODULE   	1
		#define NUMBER_OF_CMU_PCIE_MODULE   	1
		#define NUMBER_OF_CMU_SYS_MODULE    	1
		#define NUMBER_OF_CMU_TBUS_MODULE   	1
		#define NUMBER_OF_CMU_USB_MODULE    	1
		#define NUMBER_OF_CMU_WAVE_MODULE   	1
		#define NUMBER_OF_CMU_WAVE420_MODULE	1

		#define NUMBER_OF_CPUIF_SBUS_MODULE		1
		#define NUMBER_OF_CPUIF_BBUS_MODULE		1
		#define NUMBER_OF_CPUIF_LBUS_MODULE		1
		#define NUMBER_OF_CPUIF_TBUS_MODULE		1

	// @added by yjkim 2016/06/07, MCU
		#define NUMBER_OF_MCU_MODULE			1
//------------
// PHY BASEADDR
//------------

    //--------------------------------------------------------------------------
    //  SFR Base Address
    //--------------------------------------------------------------------------
	// @modified by yjkim, -> nx_chip_sfr.h

// { -----------------------------------------------------------------------------


	//###################################################################################
	// @modified by choiyk 2015/10/02, by evt0/design/nxp5540/doc/bus_architecture_v2.xls
	//###################################################################################
		#define NUMBER_OF_MIPICSIS_MODULE       1
		#define NUMBER_OF_MIPIDSIM_MODULE       1

		#define NUMBER_OF_HDMI_MODULE       1
		#define NUMBER_OF_HDMI_LINK_MODULE  NUMBER_OF_HDMI_MODULE
		#define NUMBER_OF_HDMI_CEC_MODULE   NUMBER_OF_HDMI_MODULE
		#define NUMBER_OF_HDMI_PHY_MODULE   NUMBER_OF_HDMI_MODULE

		// 임시로 정의함. ALIVE 내부에 있음
		#define PHY_BASEADDR_HDMI_CEC_MODULE 0

 		#define PHY_BASEADDR_SSP0_MODULE    PHY_BASEADDR_SPI0_MODULE
    	#define PHY_BASEADDR_SSP1_MODULE    PHY_BASEADDR_SPI1_MODULE
		#define PHY_BASEADDR_SSP2_MODULE    PHY_BASEADDR_SPI2_MODULE

		// just for helloworld c compile
		#define PHY_BASEADDR_CMU_CPU_MODULE   PHY_BASEADDR_CMU_CPU0_MODULE
		#define PHY_BASEADDR_CMU_DREX_MODULE  PHY_BASEADDR_CMU_DREX0_MODULE
		#define PHY_BASEADDR_DREXTZASC_MODULE PHY_BASEADDR_DREXTZASC0_MODULE
	//###################################################################################


	// @added by yjkim 2016.02.18
	#define PHY_BASEADDR_TRNG_MODULE        (PHY_BASEADDR_CRYPTO_MODULE + 0x8000)

	#define PHY_BASEADDR_CCI400_MODULE      PHY_BASEADDR_CCI4000_MODULE
	#define PHY_BASEADDR_GIC400_MODULE      PHY_BASEADDR_GIC4000_MODULE

    // @modified sei - nxp5430 base address
    #define PHY_BASEADDR_DMA0_MODULE        PHY_BASEADDR_DMAC0_MODULE
    #define PHY_BASEADDR_DMA1_MODULE        PHY_BASEADDR_DMAC1_MODULE
    #define PHY_BASEADDR_SDMA0_MODULE       PHY_BASEADDR_SEC_DMA0_MODULE
    #define PHY_BASEADDR_SDMA1_MODULE       PHY_BASEADDR_SEC_DMA1_MODULE
    #define PHY_BASEADDR_MDMA_MODULE        PHY_BASEADDR_MDMAC0_MODULE


    #define PHY_BASEADDR_INTC_MODULE        PHY_BASEADDR_GIC400_MODULE

    #define PHY_BASEADDR_CLKPWR_MODULE                          0x20010000
    #define PHY_BASEADDR_TIEOFF_MODULE                          0xC0011000
    #define PHY_BASEADDR_RSTCON_MODULE                          0xC0012000

    #define PHY_BASEADDR_TIMER0_MODULE							0x20620000 // non-secure
    #define PHY_BASEADDR_TIMER1_MODULE							0x20630000 // secure
    #define PHY_BASEADDR_PWM0_MODULE							0x20640000
    #define PHY_BASEADDR_PWM1_MODULE							0x20650000
    #define PHY_BASEADDR_PWM2_MODULE							0x20660000
    #define PHY_BASEADDR_PWM3_MODULE							0x20670000

    // 이것이 기준이다.
    #define PHY_BASEADDR_WDT0_MODULE                            0x20690000 // secure
    #define PHY_BASEADDR_WDT1_MODULE                            0x20680000 // non-secure

//	// @added by choiyk  2015/02/06, ISS_CPUIF
//	#define PHY_BASEADDR_ISS_CPUIF_MODULE  0x20B00000
//	why for old code in nx_mipi.c to rename MIPI to MIPI_CSIM and MIPI_DSIM
    #define PHY_BASEADDR_MIPICSIS_MODULE                        0x20E20000
	#define PHY_BASEADDR_MIPIDSIM_MODULE                        0x20E50000
//
//	//@modified by choiyk 2015/02/23 : GPIO BaseAddr
    #define PHY_BASEADDR_GPIOA_MODULE                           0x21050000
    #define PHY_BASEADDR_GPIOB_MODULE                           0x21051000
    #define PHY_BASEADDR_GPIOC_MODULE                           0x21052000
    #define PHY_BASEADDR_GPIOD_MODULE                           0x21053000
    #define PHY_BASEADDR_GPIOE_MODULE                           0x21054000
    #define PHY_BASEADDR_GPIOF_MODULE                           0x21055000
    #define PHY_BASEADDR_GPIOG_MODULE                           0x21056000
    #define PHY_BASEADDR_GPIOH_MODULE                           0x21057000

    #define PHY_BASEADDR_SECURE_GPIOA_MODULE                    0x21060000
    #define PHY_BASEADDR_SECURE_GPIOB_MODULE                    0x21061000
    #define PHY_BASEADDR_SECURE_GPIOC_MODULE                    0x21062000
    #define PHY_BASEADDR_SECURE_GPIOD_MODULE                    0x21063000
    #define PHY_BASEADDR_SECURE_GPIOE_MODULE                    0x21064000
    #define PHY_BASEADDR_SECURE_GPIOF_MODULE                    0x21065000
    #define PHY_BASEADDR_SECURE_GPIOG_MODULE                    0x21066000
    #define PHY_BASEADDR_SECURE_GPIOH_MODULE                    0x21067000

    #define PHY_BASEADDR_USBOTG_MODULE                          0x21200000
    #define PHY_BASEADDR_USBHOST_MODULE                         0x21210000
    #define PHY_BASEADDR_USB3_TIEOFF_MODULE                    0x21220000
    #define PHY_BASEADDR_USB20OTG_MODULE_AHBS0                  0x21280000
    #define PHY_BASEADDR_USB20HOST_MODULE_EHCI_S_AHB            0x212A0000
    #define PHY_BASEADDR_USB20HOST_MODULE_OHCI_S_AHB            0x212B0000
    #define PHY_BASEADDR_USB3_AHB                               0x21300000
//
//    #define PHY_BASEADDR_MCUSTOP_MODULE                         0X203d0000
    #define PHY_BASEADDR_ADC_MODULE                             0x21840000
    #define PHY_BASEADDR_PPM_MODULE                             0x20610000
//    #define PHY_BASEADDR_I2S0_MODULE                            0xC0055000
//    #define PHY_BASEADDR_I2S1_MODULE                            0xC0056000
//    #define PHY_BASEADDR_I2S2_MODULE                            0xC0057000
    #define PHY_BASEADDR_AC97_MODULE                            0x20820000
    #define PHY_BASEADDR_SPDIFTX_MODULE                         0x21930000
    #define PHY_BASEADDR_SPDIFRX_MODULE                         0x21940000
//    #define PHY_BASEADDR_MPEGTSI_MODULE                         0xC005D000
//    #define PHY_BASEADDR_GPU_MODULE                             0x21C00000

//    #define PHY_BASEADDR_DWC_GMAC_MODULE_APB0                   0xC0060000
//    #define PHY_BASEADDR_DWC_GMAC_MODULE_APB1                   0xC0061000
    #define PHY_BASEADDR_DWC_GMAC_MODULE                        PHY_BASEADDR_GMAC_MODULE
//    #define PHY_BASEADDR_SDMMC0_MODULE                          0xC0062000
//    #define PHY_BASEADDR_VIP0_MODULE                            0xC0063000
    #define PHY_BASEADDR_VIP1_MODULE                            0xC0064000
//    #define PHY_BASEADDR_DEINTERLACE_MODULE                     0xC0065000
    #define PHY_BASEADDR_SCALER_MODULE                          0xC0066000
//    #define PHY_BASEADDR_ECID_MODULE                            0xC0067000
//    #define PHY_BASEADDR_SDMMC1_MODULE                          0xC0068000
//    #define PHY_BASEADDR_SDMMC2_MODULE                          0xC0069000
    #define PHY_BASEADDR_USB20HOST_MODULE_APB                   0xC006A000
    #define PHY_BASEADDR_CLKGEN32_MODULE                        0xC006B000
    #define PHY_BASEADDR_USB20OTG_MODULE_APB                    0xC006C000
//    #define PHY_BASEADDR_pl01115_Uart_nodma1_MODULE             0xC006D000
    #define PHY_BASEADDR_CLKGEN26_MODULE                        0xC006E000
//    #define PHY_BASEADDR_pl01115_Uart_nodma2_MODULE             0xC006F000

    #define PHY_BASEADDR_MALI400_MODULE                         0xC0070000

    #define PHY_BASEADDR_CODA980_MODULE_APB0                    0xC0080000
    #define PHY_BASEADDR_CODA980_MODULE_APB1                    0xC0081000
    #define PHY_BASEADDR_CODA980_MODULE_APB2                    0xC0082000
    #define PHY_BASEADDR_CODA980_MODULE_APB3                    0xC0083000
    #define PHY_BASEADDR_XIUA_CODA0_MODULE                      0xC0084000
    #define PHY_BASEADDR_XIUA_CODA1_MODULE                      0xC0085000

    #define PHY_BASEADDR_IOPERI_BUS_MODULE                      0xC0090000
    #define PHY_BASEADDR_BOT_BUS_MODULE                         0xC0091000
    #define PHY_BASEADDR_TOP_BUS_MODULE                         0xC0092000
    #define PHY_BASEADDR_DISP_BUS_MODULE                        0xC0093000
    #define PHY_BASEADDR_SFR_BUS_MODULE                         0xC0094000
    #define PHY_BASEADDR_STATIC_BUS_MODULE                      0xC0095000
    //#define PHY_BASEADDR_TMU_SBUS_MODULE						0x20020000	// TMU0
    //#define PHY_BASEADDR_TMU_TBUS_MODULE						0x20810000	// TMU1
    //#define PHY_BASEADDR_TMU_LBUS_MODULE						0x21010000	// TMU2
    #define PHY_BASEADDR_TMU_BBUS_MODULE						0x21810000	// TMU3

    //#define PHY_BASEADDR_TIEOFF_TMU_SBUS_MODULE					0x20060000	// TMU0
    //#define PHY_BASEADDR_TIEOFF_TMU_TBUS_MODULE					0x20800000	// TMU1
    //#define PHY_BASEADDR_TIEOFF_TMU_LBUS_MODULE					0x21000000	// TMU2
    //#define PHY_BASEADDR_TIEOFF_TMU_BBUS_MODULE					0x21800000	// TMU3



	//#define PHY_BASEADDR_TBUS_MODULE							0x20800000
	//#define PHY_BASEADDR_LBUS_MODULE							0x21000000
	#define PHY_BASEADDR_BBUS_MODULE							0x21800000
	//#define PHY_BASEADDR_SYS_MODULE								0x20060000

	//#define PHY_BASEADDR_CPUIF_TBUS_MODULE						0x20800000
	//#define PHY_BASEADDR_CPUIF_LBUS_MODULE                      0x21000000
	#define PHY_BASEADDR_CPUIF_BBUS_MODULE                      0x21800000
	//#define PHY_BASEADDR_CPUIF_SBUS_MODULE                      0x20060000

	#define PHY_BASEADDR_wave_MODULE							0x21A00000
	#define PHY_BASEADDR_CPU_MODULE							0x202C0000
	#define PHY_BASEADDR_CPU1_MODULE							0x202E0000
	#define PHY_BASEADDR_WAVE420_MODULE							0x21B00000
	#define PHY_BASEADDR_DREX0_MODULE							0x20400000
	#define PHY_BASEADDR_DREX1_MODULE							0x20480000
	#define PHY_BASEADDR_PCI_MODULE								0x21C00000
	#define PHY_BASEADDR_CODA_MODULE							0x20500000

    #define PHY_BASEADDR_VIP2_MODULE                            0xC0099000
    #define PHY_BASEADDR_CLKGEN40_MODULE                        0xC009A000
    #define PHY_BASEADDR_XIUA_MALI0_MODULE                      0xC009C000
    #define PHY_BASEADDR_XIUA_MALI1_MODULE                      0xC009D000
    #define PHY_BASEADDR_XIUA_CSSYS_MODULE                      0xC009E000

//    #define PHY_BASEADDR_pl01115_Uart_modem_MODULE              0xC00A0000
//    #define PHY_BASEADDR_pl01115_Uart_nodma0_MODULE             0xC00A3000
    #define PHY_BASEADDR_UART0_MODULE                           0x21880000	// Inst_UART00_dma_nomodem
    #define PHY_BASEADDR_UART1_MODULE                           0x21890000  // Inst_UART01_dma_modem
    #define PHY_BASEADDR_pl01115_Uart_modem_MODULE              0x21890000
    #define PHY_BASEADDR_UART2_MODULE                           0x218A0000  // Inst_UART02_dma_nomodem
    #define PHY_BASEADDR_UART3_MODULE                           0x218B0000  // Inst_UART03_nodma_nomodem
    #define PHY_BASEADDR_UART4_MODULE                           0x218C0000  // Inst_UART04_nodma_nomodem
    #define PHY_BASEADDR_UART5_MODULE                           0x218D0000  // Inst_UART05_nodma_nomodem
    #define PHY_BASEADDR_UART6_MODULE							0x21950000
    #define PHY_BASEADDR_UART7_MODULE							0x21960000
    #define PHY_BASEADDR_UART8_MODULE							0x21970000

    //#define PHY_BASEADDR_TIEOFF_UART_MODULE						0x2180000C	// UART TIEOFF

//    #define PHY_BASEADDR_I2C0_MODULE                            0xC00A4000
//    #define PHY_BASEADDR_I2C1_MODULE                            0xC00A5000
//    #define PHY_BASEADDR_I2C2_MODULE                            0xC00A6000
    #define PHY_BASEADDR_CLKGEN39_MODULE                        0xC00A7000
    #define PHY_BASEADDR_CLKGEN24_MODULE                        0xC00A8000
    #define PHY_BASEADDR_CLKGEN22_MODULE                        0xC00A9000
    #define PHY_BASEADDR_CLKGEN23_MODULE                        0xC00AA000
    #define PHY_BASEADDR_CLKGEN25_MODULE                        0xC00AB000
    #define PHY_BASEADDR_CLKGEN37_MODULE                        0xC00AC000
    #define PHY_BASEADDR_CLKGEN38_MODULE                        0xC00AD000
    #define PHY_BASEADDR_CLKGEN6_MODULE                         0xC00AE000
    #define PHY_BASEADDR_CLKGEN7_MODULE                         0xC00AF000

    #define PHY_BASEADDR_CLKGEN8_MODULE                         0xC00B0000
    #define PHY_BASEADDR_CLKGEN27_MODULE                        0xC00B1000
    #define PHY_BASEADDR_CLKGEN15_MODULE                        0xC00B2000
    #define PHY_BASEADDR_CLKGEN16_MODULE                        0xC00B3000
    #define PHY_BASEADDR_CLKGEN17_MODULE                        0xC00B4000
    #define PHY_BASEADDR_CLKGEN28_MODULE                        0xC00B5000
    #define PHY_BASEADDR_CLKGEN35_MODULE                        0xC00B6000
    #define PHY_BASEADDR_CLKGEN12_MODULE                        0xC00B7000
    #define PHY_BASEADDR_CLKGEN11_MODULE                        0xC00B8000
    #define PHY_BASEADDR_CLKGEN14_MODULE                        0xC00B9000
    #define PHY_BASEADDR_CLKGEN13_MODULE                        0xC00BA000
    #define PHY_BASEADDR_CLKGEN0_MODULE                         0xC00BB000
    #define PHY_BASEADDR_CLKGEN1_MODULE                         0xC00BC000
    #define PHY_BASEADDR_CLKGEN2_MODULE                         0xC00BD000
    #define PHY_BASEADDR_CLKGEN3_MODULE                         0xC00BE000
    #define PHY_BASEADDR_CLKGEN4_MODULE                         0xC00BF000

    #define PHY_BASEADDR_CLKGEN5_MODULE                         0xC00C0000
    #define PHY_BASEADDR_CLKGEN30_MODULE                        0xC00C1000
    #define PHY_BASEADDR_CLKGEN31_MODULE                        0xC00C2000
    #define PHY_BASEADDR_CLKGEN21_MODULE                        0xC00C3000
    #define PHY_BASEADDR_CLKGEN29_MODULE                        0xC00C4000
    #define PHY_BASEADDR_CLKGEN18_MODULE                        0xC00C5000
    #define PHY_BASEADDR_CLKGEN34_MODULE                        0xC00C6000
    #define PHY_BASEADDR_CLKGEN33_MODULE                        0xC00C7000
    #define PHY_BASEADDR_CLKGEN10_MODULE                        0xC00C8000
    #define PHY_BASEADDR_CLKGEN9_MODULE                         0xC00CA000
    #define PHY_BASEADDR_CLKGEN36_MODULE                        0xC00CB000
    #define PHY_BASEADDR_CLKGEN19_MODULE                        0xC00CC000
    #define PHY_BASEADDR_CLKGEN20_MODULE                        0xC00CD000
    #define PHY_BASEADDR_CAN0_MODULE                            0xC00CE000
    #define PHY_BASEADDR_CAN1_MODULE                            0xC00CF000

//
//    #define PHY_BASEADDR_DREX_MODULE_CH0_APB                    0xC00E0000
//    #define PHY_BASEADDR_DREX_MODULE_CH1_APB                    0xC00E1000
//    #define PHY_BASEADDR_XIUA_DREX0_MODULE                      0xC00E2000
//    #define PHY_BASEADDR_XIUA_DREX1_MODULE                      0xC00E3000
//    #define PHY_BASEADDR_XIUA_DREX2_MODULE                      0xC00E4000
//
//
//
//    #define PHY_BASEADDR_DREXTZASC_MODULE                       0xC0300000
//    #define PHY_BASEADDR_TZPC0_MODULE                           0xC0301000
//    #define PHY_BASEADDR_TZPC1_MODULE                           0xC0302000
//    #define PHY_BASEADDR_TZPC2_MODULE                           0xC0303000
//    #define PHY_BASEADDR_TZPC3_MODULE                           0xC0304000
//    #define PHY_BASEADDR_TZPC4_MODULE                           0xC0305000
//    #define PHY_BASEADDR_TZPC5_MODULE                           0xC0306000
//    #define PHY_BASEADDR_TZPC6_MODULE                           0xC0307000
//    #define PHY_BASEADDR_CSSYS_MODULE                           0xC0308000
//
//    #define PHY_BASEADDR_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE  0x40000000
//    #define PHY_BASEADDR_AXISRAM_MODULE                         0xFFFF0000
//
//    // @Todo sei - need to be remove
    #define PHY_BASEADDR_A3BM_AXI_TOP_MASTER_BUS_MODULE                     0xC0052000
    #define PHY_BASEADDR_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE_S3               0x0
    #define PHY_BASEADDR_A3BM_AXI_BOTTOM_MASTER_BUS_MODULE_APB_BOTTOMBUS    0xC0050000
    #define PHY_BASEADDR_A3BM_AXI_PERI_BUS_MODULE                           0xC0000000
    #define PHY_BASEADDR_A3BM_AXI_DISPLAY_BUS_MODULE                        0xC005E000
	#define PHY_BASEADDR_CPUIF_P5QP_MODULE                        0x202C0000
//    #define PHY_BASEADDR_CPUIF_P5QP1_MODULE                        0x202E0000
//
// }-----------------------------------------------------------------------------


//------------------------------------------------------------------------------
// BAGL RENDERING END
//------------------------------------------------------------------------------

#ifdef __arm    // for RVDS
#pragma diag_default 66     // return to default setting for #66 warning
#endif

//------------------------------------------------------------------------------
// Interrupt Number of mudules for the interrupt controller.
//------------------------------------------------------------------------------
//  REF EXAMPLE :
//  enum {
//      INTNUM_OF_OJTDMA_MODULE_IRQ     = 0
//      ,INTNUM_OF_OJTDMA_MODULE_DMAIRQ = 1
//      };


//#define NX_INTC_NUM_OF_INT  224
#define NX_INTC_NUM_OF_INT  (256 + 32)

//------------------------------------------------------------------------------
// BAGL RENDERING
//------------------------------------------------------------------------------
//@modified sei 20151005 - interrupt number for nxp5540
//enum {
//     INTNUM_OF_MCUSTOP_MODULE                               = 0
//    // @modified sei 20151005 - removed
//    //,INTNUM_OF_DMA0_MODULE                                  = 1
//    //,INTNUM_OF_DMA1_MODULE                                  = 2
//    ,INTNUM_OF_CLKPWR_MODULE_INTREQPWR                      = 3
//    ,INTNUM_OF_CLKPWR_MODULE_ALIVEIRQ                       = 4
//    ,INTNUM_OF_CLKPWR_MODULE_RTCIRQ                         = 5
//    ,INTNUM_OF_UART0_MODULE                                 = 6
//    ,INTNUM_OF_UART1_MODULE                                 = 7
//    ,INTNUM_OF_UART2_MODULE                                 = 8
//    ,INTNUM_OF_UART3_MODULE                                 = 9
//    ,INTNUM_OF_UART4_MODULE                                 = 10
//    ,INTNUM_OF_UART5_MODULE                                 = 11
//    ,INTNUM_OF_SSP0_MODULE                                  = 12
//    ,INTNUM_OF_SSP1_MODULE                                  = 13
//    ,INTNUM_OF_SSP2_MODULE                                  = 14
//    ,INTNUM_OF_I2C0_MODULE                                  = 15
//    ,INTNUM_OF_I2C1_MODULE                                  = 16
//    ,INTNUM_OF_I2C2_MODULE                                  = 17
//    ,INTNUM_OF_DEINTERLACE_MODULE                           = 18
//    ,INTNUM_OF_SCALER_MODULE                                = 19
//    ,INTNUM_OF_AC97_MODULE                                  = 20
//    ,INTNUM_OF_SPDIFRX_MODULE                               = 21
//    ,INTNUM_OF_SPDIFTX_MODULE                               = 22
//    ,INTNUM_OF_TIMER0_MODULE_INT0                           = 23
//    ,INTNUM_OF_TIMER0_MODULE_INT1                           = 24
//    ,INTNUM_OF_TIMER0_MODULE_INT2                           = 25
//    ,INTNUM_OF_TIMER0_MODULE_INT3                           = 26
//    ,INTNUM_OF_TIMER1_MODULE_INT0                           = 27
//    ,INTNUM_OF_TIMER1_MODULE_INT1                           = 28
//    ,INTNUM_OF_TIMER1_MODULE_INT2                           = 29
//    ,INTNUM_OF_TIMER1_MODULE_INT3                           = 30
//
//	// @todo charlse
//    ,INTNUM_OF_PWM0_MODULE_INT0                             = 30
//    ,INTNUM_OF_PWM0_MODULE_INT1                             = 30
//    ,INTNUM_OF_PWM0_MODULE_INT2                             = 30
//    ,INTNUM_OF_PWM0_MODULE_INT3                             = 30
//    ,INTNUM_OF_PWM1_MODULE_INT0                             = 30
//    ,INTNUM_OF_PWM1_MODULE_INT1                             = 30
//    ,INTNUM_OF_PWM1_MODULE_INT2                             = 30
//    ,INTNUM_OF_PWM1_MODULE_INT3                             = 30
//    ,INTNUM_OF_PWM2_MODULE_INT0                             = 30
//    ,INTNUM_OF_PWM2_MODULE_INT1                             = 30
//    ,INTNUM_OF_PWM2_MODULE_INT2                             = 30
//    ,INTNUM_OF_PWM2_MODULE_INT3                             = 30
//    ,INTNUM_OF_PWM3_MODULE_INT0                             = 30
//    ,INTNUM_OF_PWM3_MODULE_INT1                             = 30
//    ,INTNUM_OF_PWM3_MODULE_INT2                             = 30
//    ,INTNUM_OF_PWM3_MODULE_INT3                             = 30
//
//
//
//    ,INTNUM_OF_WDT_MODULE                                   = 31
//    ,INTNUM_OF_MPEGTSI_MODULE                               = 32
//    ,INTNUM_OF_DISPLAYTOP_MODULE_DUALDISPLAY_PRIMIRQ        = 33
//    ,INTNUM_OF_DISPLAYTOP_MODULE_DUALDISPLAY_SECONDIRQ      = 34
//    // @modified sei 20151005 - changed
//    //,INTNUM_OF_DISPLAYTOP_MODULE_RESCONV_IRQ                = 35    // 영경씨 확인 필요
//    ,INTNUM_OF_NXS_TO_HDMI_MODULE                           = 35
//    ,INTNUM_OF_DISPLAYTOP_MODULE_HDMI_IRQ                   = 36
//    // @modified sei 20151005 - changed
//    //,INTNUM_OF_VIP0_MODULE                                  = 37
//    //,INTNUM_OF_VIP1_MODULE                                  = 38
//    ,INTNUM_OF_VIP1_MODULE                                  = 37
//    ,INTNUM_OF_VIP0_MODULE                                  = 38
//    ,INTNUM_OF_MIPI_MODULE                                 = 39
//    // @modified sei 20151005 - removed
//    //,INTNUM_OF_MALI400_MODULE                               = 40
//    ,INTNUM_OF_ADC_MODULE                                   = 41
//    ,INTNUM_OF_PPM_MODULE                                   = 42
//    ,INTNUM_OF_SDMMC0_MODULE                                = 43
//    ,INTNUM_OF_SDMMC1_MODULE                                = 44
//    ,INTNUM_OF_SDMMC2_MODULE                                = 45
//    ,INTNUM_OF_CODA980_MODULE_HOST_INTRPT                   = 46
//    ,INTNUM_OF_CODA980_MODULE_JPG_INTRPT                    = 47
//    ,INTNUM_OF_DWC_GMAC_MODULE                              = 48
//    ,INTNUM_OF_USB20OTG_MODULE                              = 49
//    ,INTNUM_OF_USB20HOST_MODULE                             = 50
//    // @modified sei 20151005 - removed
//    //,INTNUM_OF_CAN0_MODULE                                  = 51
//    //,INTNUM_OF_CAN1_MODULE                                  = 52
//    ,INTNUM_OF_GPIOA_MODULE                                 = 53
//    ,INTNUM_OF_GPIOB_MODULE                                 = 54
//    ,INTNUM_OF_GPIOC_MODULE                                 = 55
//    ,INTNUM_OF_GPIOD_MODULE                                 = 56
//    ,INTNUM_OF_GPIOE_MODULE                                 = 57
//    ,INTNUM_OF_CRYPTO_MODULE                                = 58
//    ,INTNUM_OF_PDM_MODULE                                   = 59
//    // @modified sei 20151005 - changed
//    //,INTNUM_OF_TMU0_MODULE                                  = 60
//    //,INTNUM_OF_TMU1_MODULE                                  = 61
//
//    ,INTNUM_OF_TMU_LBUS_MODULE                              = 60    // TMU2
//    ,INTNUM_OF_TMU_BBUS_MODULE                              = 61    // TMU3
//    ,INTNUM_OF_TMU_TBUS_MODULE                              = 62    // TMU1
//
//    ,INTNUM_OF_TIMER_MODULE_INT4                            = 64
//
//	// @todo charlse
//    ,INTNUM_OF_PWM_MODULE_INT4                              = 65
//    ,INTNUM_OF_PWM0_MODULE_INT4                              = 65
//    ,INTNUM_OF_PWM1_MODULE_INT4                              = 65
//    ,INTNUM_OF_PWM2_MODULE_INT4                              = 65
//    ,INTNUM_OF_PWM3_MODULE_INT4                              = 65
//
//    ,INTNUM_OF_I2S0_MODULE                                  = 66
//    ,INTNUM_OF_I2S1_MODULE                                  = 67
//
//    ,INTNUM_OF_VIP2_MODULE                                  = 72
//
//    ,INTNUM_OF_TMU_SBUS_MODULE                              = 99    // TMU0
//    ,INTNUM_OF_PKA_MODULE                                   = 100
//
//
//    ,INTNUM_OF_GPU_MODULE                                   = 156
//    ,INTNUM_OF_I2C3_MODULE                                  = 158
//    ,INTNUM_OF_I2C4_MODULE                                  = 159
//    ,INTNUM_OF_I2C5_MODULE                                  = 160
//
//	// @added by choiyk 2015/08/27, LVDS
//    ,INTNUM_OF_LVDS_MODULE                                 = 255
//
//    ,INTNUM_OF_NXS_TO_MIPIDSI_MODULE                       = 145
//
//    ,INTNUM_OF_DMA0_MODULE                                  = 164
//    ,INTNUM_OF_DMA1_MODULE                                  = 166
//    ,INTNUM_OF_SDMA0_MODULE                                 = 172
//    ,INTNUM_OF_SDMA1_MODULE                                 = 174
//};
//------------------------------------------------------------------------------
// BAGL RENDERING END
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Reset Controller : Number of Reset
//------------------------------------------------------------------------------
/*#define NUMBER_OF_RESET_MODULE_PIN 69
enum {
// xl50200_AC97_cfg0
RESETINDEX_OF_AC97_MODULE_PRESETn = 0
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET1 = 1
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET2 = 2
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nCPURESET3 = 3
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET1 = 4
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET2 = 5
,// nx01301_CORTEXA9MP_TOP_QUADL2C
RESETINDEX_OF_nx01301_CORTEXA9MP_TOP_QUADL2C_MODULE_nWDRESET3 = 6
,// nx02600_CRYPTO_cfg0
RESETINDEX_OF_CRYPTO_MODULE_i_nRST = 7
,// nx01501_DEINTERLACE_cfg0
RESETINDEX_OF_DEINTERLACE_MODULE_i_nRST = 8
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_Top_nRST = 9
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_DualDisplay_nRST = 10
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_ResConv_nRST = 11
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_LCDIF_nRST = 12
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_nRST = 13
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_VIDEO_nRST = 14
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_SPDIF_nRST = 15
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_TMDS_nRST = 16
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_PHY_nRST = 17
,// nx71000_DisplayTop_cfg5
RESETINDEX_OF_DISPLAYTOP_MODULE_i_LVDS_nRST = 18
,// nx50100_ECID_128bit
RESETINDEX_OF_ECID_MODULE_i_nRST = 19
,// xl00100_I2C_cfg0
RESETINDEX_OF_I2C0_MODULE_PRESETn = 20
,// xl00100_I2C_cfg0
RESETINDEX_OF_I2C1_MODULE_PRESETn = 21
,// xl00100_I2C_cfg0
RESETINDEX_OF_I2C2_MODULE_PRESETn = 22
,// xl00300_I2S_cfg1
RESETINDEX_OF_I2S0_MODULE_PRESETn = 23
,// xl00300_I2S_cfg1
RESETINDEX_OF_I2S1_MODULE_PRESETn = 24
,// xl00300_I2S_cfg1
RESETINDEX_OF_I2S2_MODULE_PRESETn = 25
,// xl00112_DREX_cfg1
RESETINDEX_OF_DREX_MODULE_CRESETn = 26
,// xl00112_DREX_cfg1
RESETINDEX_OF_DREX_MODULE_ARESETn = 27
,// xl00112_DREX_cfg1
RESETINDEX_OF_DREX_MODULE_nPRST = 28
,// nx71100_mipi_cfg1
RESETINDEX_OF_MIPI_MODULE_i_nRST = 29
,// nx71100_mipi_cfg1
RESETINDEX_OF_MIPI_MODULE_i_DSI_I_PRESETn = 30
,// nx71100_mipi_cfg1
RESETINDEX_OF_MIPI_MODULE_i_CSI_I_PRESETn = 31
,// nx71100_mipi_cfg1
RESETINDEX_OF_MIPI_MODULE_i_PHY_S_RESETN = 32
,// nx71100_mipi_cfg1
RESETINDEX_OF_MIPI_MODULE_i_PHY_M_RESETN = 33
,// nx01910_MPEGTSI_cfg0
RESETINDEX_OF_MPEGTSI_MODULE_i_nRST = 34
,// nx02500_PDM_cfg0
RESETINDEX_OF_PDM_MODULE_i_nRST = 35
,// xl50010_PWMTIMER_usetimer
RESETINDEX_OF_TIMER_MODULE_PRESETn = 36
,// xl50010_PWMTIMER_usepwm
RESETINDEX_OF_PWM_MODULE_PRESETn = 37
,// nx01400_SCALER_cfg0
RESETINDEX_OF_SCALER_MODULE_i_nRST = 38
,// xl00500_SDMMC_cfg0
RESETINDEX_OF_SDMMC0_MODULE_i_nRST = 39
,// xl00500_SDMMC_cfg0
RESETINDEX_OF_SDMMC1_MODULE_i_nRST = 40
,// xl00500_SDMMC_cfg0
RESETINDEX_OF_SDMMC2_MODULE_i_nRST = 41
,// nx01600_SPDIFRX_cfg0
RESETINDEX_OF_SPDIFRX_MODULE_PRESETn = 42
,// xl50300_SPDIFTX_hdmipinout
RESETINDEX_OF_SPDIFTX_MODULE_PRESETn = 43
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP0_MODULE_PRESETn = 44
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP0_MODULE_nSSPRST = 45
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP1_MODULE_PRESETn = 46
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP1_MODULE_nSSPRST = 47
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP2_MODULE_PRESETn = 48
,// pl02212_Ssp_cfg1
RESETINDEX_OF_SSP2_MODULE_nSSPRST = 49
,// pl01115_Uart_cfg0
RESETINDEX_OF_UART0_MODULE_nUARTRST = 50
,// pl01115_Uart_modem
RESETINDEX_OF_pl01115_Uart_modem_MODULE_nUARTRST = 51
,// pl01115_Uart_cfg0
RESETINDEX_OF_UART1_MODULE_nUARTRST = 52
,// pl01115_Uart_nodma
RESETINDEX_OF_pl01115_Uart_nodma0_MODULE_nUARTRST = 53
,// pl01115_Uart_nodma
RESETINDEX_OF_pl01115_Uart_nodma1_MODULE_nUARTRST = 54
,// pl01115_Uart_nodma
RESETINDEX_OF_pl01115_Uart_nodma2_MODULE_nUARTRST = 55
,// xl00700_USB20HOST_cfg0
RESETINDEX_OF_USB20HOST_MODULE_i_nRST = 56
,// xl00600_USB20OTG_cfg0
RESETINDEX_OF_USB20OTG_MODULE_i_nRST = 57
,// xl50500_WDT_cfg0
RESETINDEX_OF_WDT_MODULE_PRESETn = 58
,// xl50500_WDT_cfg0
RESETINDEX_OF_WDT_MODULE_nPOR = 59
,// nx01700_adc_cfg0
RESETINDEX_OF_ADC_MODULE_nRST = 60
,// xl07000_coda960_cfg1
RESETINDEX_OF_CODA980_MODULE_i_areset_n = 61
,// xl07000_coda960_cfg1
RESETINDEX_OF_CODA980_MODULE_i_preset_n = 62
,// xl07000_coda960_cfg1
RESETINDEX_OF_CODA980_MODULE_i_creset_n = 63
,// xl50400_DWC_GMAC_RGMII
RESETINDEX_OF_DWC_GMAC_MODULE_aresetn_i = 64
,// xl06000_mali400_cfg1
RESETINDEX_OF_MALI400_MODULE_nRST = 65
,// nx02300_ppm_cfg0
RESETINDEX_OF_PPM_MODULE_i_nRST = 66
,// nx01800_vip_twopadwrapper
RESETINDEX_OF_VIP1_MODULE_i_nRST = 67
,// nx01800_vip_cfg3
RESETINDEX_OF_VIP0_MODULE_i_nRST = 68
,
RESETINDEX_OF_VIP2_MODULE_i_nRST = 69

// ECID Reset Number
//#define  RESETINDEX_OF_ECID_MODULE_i_nRST  19
*/

	#define NUMBER_OF_RESET_MODULE_PIN 	300
	#define MAX_RESET_LIST_NUM			0x80
	#define LOG2_MAX_RESET_LIST_NUM		7
	#define MAX_RESET_LIST_NUM_MASK		0x7f

	// nx01000_CMUTOP_sys_cpuif_regmap
	#define RESETINDEX_OF_SRAM_MODULE_axi_rst			((MAX_RESET_LIST_NUM*1)|0x00)
	#define RESETINDEX_OF_GIC400_MODULE_axi_rst   		((MAX_RESET_LIST_NUM*1)|0x01)
	#define RESETINDEX_OF_BCH_MODULE_axi_rst      		((MAX_RESET_LIST_NUM*1)|0x02)
	#define RESETINDEX_OF_SYS_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x03)
	#define RESETINDEX_OF_SYSCTRL_MODULE_PRESETn  		((MAX_RESET_LIST_NUM*1)|0x04)
	#define RESETINDEX_OF_PPMU_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*1)|0x05)
	#define RESETINDEX_OF_HPM_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x06)
	#define RESETINDEX_OF_QENHANCER_MODULE_PRESETn		((MAX_RESET_LIST_NUM*1)|0x07)
	#define RESETINDEX_OF_TMU_SYS_MODULE_PRESETn      	((MAX_RESET_LIST_NUM*1)|0x08)
	#define RESETINDEX_OF_SYSTIEOFF_MODULE_PRESETn		((MAX_RESET_LIST_NUM*1)|0x09)
	#define RESETINDEX_OF_CRYPTO_MODULE_i_nRST   		((MAX_RESET_LIST_NUM*1)|0x0a)
	#define RESETINDEX_OF_TIMER_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x0b)
	#define RESETINDEX_OF_PWM_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0c)
// @todo charlse
	#define RESETINDEX_OF_PWM0_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0c)
	#define RESETINDEX_OF_PWM1_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0c)
	#define RESETINDEX_OF_PWM2_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0c)
	#define RESETINDEX_OF_PWM3_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0c)
	#define RESETINDEX_OF_WDT0_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x0d)
	#define RESETINDEX_OF_TZPC0_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x0e)
	#define RESETINDEX_OF_TZPC1_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x0f)
	#define RESETINDEX_OF_TZPC2_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x10)
	#define RESETINDEX_OF_TZPC3_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x11)
	#define RESETINDEX_OF_TZPC4_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x12)
	#define RESETINDEX_OF_TZPC5_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x13)
	#define RESETINDEX_OF_TZPC6_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x14)
	#define RESETINDEX_OF_TZPC7_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*1)|0x15)
	#define RESETINDEX_OF_ECID_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*1)|0x16)
	#define RESETINDEX_OF_PPM_MODULE_i_nRST      		((MAX_RESET_LIST_NUM*1)|0x17)
	#define RESETINDEX_OF_PKA_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x18)
	#define RESETINDEX_OF_ISP_MODULE_CMU_rst      		((MAX_RESET_LIST_NUM*1)|0x19)
	#define RESETINDEX_OF_DISP_MODULE_CMU_rst     		((MAX_RESET_LIST_NUM*1)|0x1a)
	#define RESETINDEX_OF_USB_MODULE_CMU_rst      		((MAX_RESET_LIST_NUM*1)|0x1b)
	#define RESETINDEX_OF_EISC_MODULE_CMU_rst     		((MAX_RESET_LIST_NUM*1)|0x1c)
	#define RESETINDEX_OF_CODA_MODULE_CMU_rst     		((MAX_RESET_LIST_NUM*1)|0x1d)
	#define RESETINDEX_OF_DREX_MODULE_CMU_rst     		((MAX_RESET_LIST_NUM*1)|0x1e)
	#define RESETINDEX_OF_CPU_MODULE_CMU_rst      		((MAX_RESET_LIST_NUM*1)|0x1f)
	#define RESETINDEX_OF_GPU_MODULE_CMU_rst      		((MAX_RESET_LIST_NUM*1)|0x20)
	#define RESETINDEX_OF_CSSYS_MODULE_axi_rst    		((MAX_RESET_LIST_NUM*1)|0x21)
	#define RESETINDEX_OF_cssys_MODULE_atclk_rst  		((MAX_RESET_LIST_NUM*1)|0x22)
	#define RESETINDEX_OF_MCUSTOP_MODULE_axi_rst  		((MAX_RESET_LIST_NUM*1)|0x23)
	#define RESETINDEX_OF_TMCB0_MODULE_core_rst   		((MAX_RESET_LIST_NUM*1)|0x24)
	#define RESETINDEX_OF_TMCB1_MODULE_core_rst   		((MAX_RESET_LIST_NUM*1)|0x25)
	#define RESETINDEX_OF_TMCB2_MODULE_core_rst   		((MAX_RESET_LIST_NUM*1)|0x26)
	#define RESETINDEX_OF_TMCB3_MODULE_core_rst   		((MAX_RESET_LIST_NUM*1)|0x27)
	#define RESETINDEX_OF_TIMER0_MODULE_core_rst  		((MAX_RESET_LIST_NUM*1)|0x28)
	#define RESETINDEX_OF_TIMER1_MODULE_core_rst  		((MAX_RESET_LIST_NUM*1)|0x29)
	#define RESETINDEX_OF_PWM0_MODULE_core_rst    		((MAX_RESET_LIST_NUM*1)|0x2a)
	#define RESETINDEX_OF_PWM1_MODULE_core_rst    		((MAX_RESET_LIST_NUM*1)|0x2b)
	#define RESETINDEX_OF_PPMU_MODULE_core_rst    		((MAX_RESET_LIST_NUM*1)|0x2c)
	#define RESETINDEX_OF_WDT1_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*1)|0x2d)

	// nx01000_CMUTOP_bbus_cpuif_regmap
	#define RESETINDEX_OF_BBUS_MODULE_axi_rst      		((MAX_RESET_LIST_NUM*2)|0x00)
	#define RESETINDEX_OF_DMAC0_MODULE_axi_rst     		((MAX_RESET_LIST_NUM*2)|0x01)
	#define RESETINDEX_OF_DMAC1_MODULE_axi_rst     		((MAX_RESET_LIST_NUM*2)|0x02)
	#define RESETINDEX_OF_BBUS_MODULE_ahb_rst      		((MAX_RESET_LIST_NUM*2)|0x03)
	#define RESETINDEX_OF_SDMMC1_MODULE_ahb_rst    		((MAX_RESET_LIST_NUM*2)|0x04)
	#define RESETINDEX_OF_BBUS_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x05)
	#define RESETINDEX_OF_BBUSTIEOFF_MODULE_PRESETn		((MAX_RESET_LIST_NUM*2)|0x06)
	#define RESETINDEX_OF_TMU_BBUS_MODULE_PRESETn       ((MAX_RESET_LIST_NUM*2)|0x07)
	#define RESETINDEX_OF_DMAC0_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x08)
	#define RESETINDEX_OF_DMAC1_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x09)
	#define RESETINDEX_OF_SDMMC1_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*2)|0x0a)
	#define RESETINDEX_OF_ADC_MODULE_nRST       		((MAX_RESET_LIST_NUM*2)|0x0b)
	#define RESETINDEX_OF_GPIO2_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x0c)
	#define RESETINDEX_OF_GPIO3_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x0d)
	#define RESETINDEX_OF_GPIO4_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x0e)
	#define RESETINDEX_OF_UART0_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x0f)
	#define RESETINDEX_OF_UART1_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x10)
	#define RESETINDEX_OF_UART2_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x11)
	#define RESETINDEX_OF_UART3_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x12)
	#define RESETINDEX_OF_UART4_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x13)
	#define RESETINDEX_OF_UART5_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x14)
	#define RESETINDEX_OF_PDM_MODULE_PRESETn       		((MAX_RESET_LIST_NUM*2)|0x15)
	#define RESETINDEX_OF_SPI0_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x16)
	#define RESETINDEX_OF_SPI2_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x17)
	#define RESETINDEX_OF_SPDIFTX_MODULE_PRESETn   		((MAX_RESET_LIST_NUM*2)|0x18)
	#define RESETINDEX_OF_SPDIFRX_MODULE_PRESETn   		((MAX_RESET_LIST_NUM*2)|0x19)
	#define RESETINDEX_OF_I2S0_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x1a)
	#define RESETINDEX_OF_I2S1_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x1b)
	#define RESETINDEX_OF_I2S5CH_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*2)|0x1c)
	#define RESETINDEX_OF_I2C0_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x1d)
	#define RESETINDEX_OF_I2C1_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x1e)
	#define RESETINDEX_OF_I2C2_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x1f)
	#define RESETINDEX_OF_I2C3_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x20)
	#define RESETINDEX_OF_I2C4_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x21)
	#define RESETINDEX_OF_I2C5_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*2)|0x22)
	#define RESETINDEX_OF_SDMMC1_MODULE_i_nRST   		((MAX_RESET_LIST_NUM*2)|0x23)
	#define RESETINDEX_OF_UART0_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x24)
	#define RESETINDEX_OF_UART1_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x25)
	#define RESETINDEX_OF_UART2_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x26)
	#define RESETINDEX_OF_UART3_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x27)
	#define RESETINDEX_OF_UART4_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x28)
	#define RESETINDEX_OF_UART5_MODULE_nUARTRST			((MAX_RESET_LIST_NUM*2)|0x29)
	#define RESETINDEX_OF_SPI0_MODULE_core_rst     		((MAX_RESET_LIST_NUM*2)|0x2a)
	#define RESETINDEX_OF_SPI2_MODULE_core_rst     		((MAX_RESET_LIST_NUM*2)|0x2b)
	#define RESETINDEX_OF_SPDIF_TX_MODULE_rst      		((MAX_RESET_LIST_NUM*2)|0x2c)
	#define RESETINDEX_OF_I2S0_MODULE_core_rst     		((MAX_RESET_LIST_NUM*2)|0x2d)
	#define RESETINDEX_OF_I2S1_MODULE_core_rst     		((MAX_RESET_LIST_NUM*2)|0x2e)
	#define RESETINDEX_OF_I2S5CH_MODULE_core_rst   		((MAX_RESET_LIST_NUM*2)|0x2f)
	#define RESETINDEX_OF_I2S2_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*2)|0x30)

	// nx01000_CMUTOP_lbus_cpuif_regmap
	#define RESETINDEX_OF_LBUS_MODULE_axi_rst 			((MAX_RESET_LIST_NUM*3)|0x00)
	#define RESETINDEX_OF_LBUS_MODULE_ahb_rst      		((MAX_RESET_LIST_NUM*3)|0x01)
	#define RESETINDEX_OF_SDMMC0_MODULE_ahb_rst    		((MAX_RESET_LIST_NUM*3)|0x02)
	#define RESETINDEX_OF_SDMMC3_MODULE_ahb_rst    		((MAX_RESET_LIST_NUM*3)|0x03)
	#define RESETINDEX_OF_MP2TS_MODULE_ahb_rst     		((MAX_RESET_LIST_NUM*3)|0x04)
	#define RESETINDEX_OF_LBUS_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*3)|0x05)
	#define RESETINDEX_OF_LBUSTIEOFF_MODULE_PRESETn		((MAX_RESET_LIST_NUM*3)|0x06)
	#define RESETINDEX_OF_TMULBUS_MODULE_PRESETn   		((MAX_RESET_LIST_NUM*3)|0x07)
	#define RESETINDEX_OF_SDMMC0_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*3)|0x08)
	#define RESETINDEX_OF_SDMMC3_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*3)|0x09)
	#define RESETINDEX_OF_MP2TS_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*3)|0x0a)
	#define RESETINDEX_OF_GPIO0_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*3)|0x0b)
	#define RESETINDEX_OF_GPIO1_MODULE_PRESETn     		((MAX_RESET_LIST_NUM*3)|0x0c)
	#define RESETINDEX_OF_SDMMC0_MODULE_i_nRST   		((MAX_RESET_LIST_NUM*3)|0x0d)
	#define RESETINDEX_OF_SDMMC3_MODULE_i_nRST   		((MAX_RESET_LIST_NUM*3)|0x0e)

	// nx01000_CMUTOP_tbus_cpuif_regmap
	#define RESETINDEX_OF_TBUS_MODULE_axi_rst 			((MAX_RESET_LIST_NUM*4)|0x00)
	#define RESETINDEX_OF_DWC_GMAC_MODULE_aresetn_i		((MAX_RESET_LIST_NUM*4)|0x01)
	#define RESETINDEX_OF_TBUS_MODULE_ahb_rst      		((MAX_RESET_LIST_NUM*4)|0x02)
	#define RESETINDEX_OF_SDMMC2_MODULE_ahb_rst    		((MAX_RESET_LIST_NUM*4)|0x03)
	#define RESETINDEX_OF_TBUS_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*4)|0x04)
	#define RESETINDEX_OF_TBUSTIEOFF_MODULE_PRESETn		((MAX_RESET_LIST_NUM*4)|0x05)
	#define RESETINDEX_OF_TMUTBUS_MODULE_PRESETn   		((MAX_RESET_LIST_NUM*4)|0x06)
	#define RESETINDEX_OF_GMAC_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*4)|0x07)
	#define RESETINDEX_OF_SDMMC2_MODULE_PRESETn    		((MAX_RESET_LIST_NUM*4)|0x08)
	#define RESETINDEX_OF_AC97_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*4)|0x09)
	#define RESETINDEX_OF_SPI1_MODULE_PRESETn      		((MAX_RESET_LIST_NUM*4)|0x0a)
	#define RESETINDEX_OF_SPI1_MODULE_core_rst     		((MAX_RESET_LIST_NUM*4)|0x0b)
	#define RESETINDEX_OF_SDMMC2_MODULE_i_nRST   		((MAX_RESET_LIST_NUM*4)|0x0c)
	#define RESETINDEX_OF_AC97_MODULE_bit_rst      		((MAX_RESET_LIST_NUM*4)|0x0d)

	// nx01000_CMUTOP_gpu_cpuif_regmap
	#define RESETINDEX_OF_GPUTIEOFF_MODULE_PRESETn		((MAX_RESET_LIST_NUM*5)|0x00)
	#define RESETINDEX_OF_GPU_MODULE_PRESETn            ((MAX_RESET_LIST_NUM*5)|0x01)

	// nx01000_CMUTOP_usb_cpuif_regmap
	#define RESETINDEX_OF_USB_MODULE_ahb_rst			((MAX_RESET_LIST_NUM*6)|0x00)
	#define RESETINDEX_OF_USB_MODULE_PRESETn            ((MAX_RESET_LIST_NUM*6)|0x01)
	#define RESETINDEX_OF_USBOTG_MODULE_ahb_rst         ((MAX_RESET_LIST_NUM*6)|0x02)
	#define RESETINDEX_OF_USBOTG_MODULE_PRESETn         ((MAX_RESET_LIST_NUM*6)|0x03)
	#define RESETINDEX_OF_USBEHCI_MODULE_ahb_rst        ((MAX_RESET_LIST_NUM*6)|0x04)
	#define RESETINDEX_OF_USBOHCI_MODULE_ahb_rst        ((MAX_RESET_LIST_NUM*6)|0x05)
	#define RESETINDEX_OF_USBHST_MODULE_PRESETn         ((MAX_RESET_LIST_NUM*6)|0x06)
	#define RESETINDEX_OF_HSIC_MODULE_refclkdig_rst     ((MAX_RESET_LIST_NUM*6)|0x07)
	#define RESETINDEX_OF_USBOTG_MODULE_ref_rst         ((MAX_RESET_LIST_NUM*6)|0x08)
	#define RESETINDEX_OF_USBHST_MODULE_ref_rst         ((MAX_RESET_LIST_NUM*6)|0x09)

	// nx01000_CMUTOP_disp_cpuif_regmap
	#define RESETINDEX_OF_DISP_MODULE_axi_rst			((MAX_RESET_LIST_NUM*7)|0x00)
	#define RESETINDEX_OF_VIP_MODULE_CPUIF_rst          ((MAX_RESET_LIST_NUM*7)|0x01)
	#define RESETINDEX_OF_VIP_PRES_MODULE_CPUIF_rst     ((MAX_RESET_LIST_NUM*7)|0x02)
	#define RESETINDEX_OF_ISS_MODULE_CPUIF_rst          ((MAX_RESET_LIST_NUM*7)|0x03)
	#define RESETINDEX_OF_DISP_MODULE_CPUIF_rst         ((MAX_RESET_LIST_NUM*7)|0x04)
	#define RESETINDEX_OF_DISP_MODULE_TIEOFF_rst        ((MAX_RESET_LIST_NUM*7)|0x05)
	#define RESETINDEX_OF_DISP2ISP_MODULE_rst           ((MAX_RESET_LIST_NUM*7)|0x06)
	#define RESETINDEX_OF_ISP2DISP0_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x07)
	#define RESETINDEX_OF_ISP2DISP1_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x08)
	#define RESETINDEX_OF_CROP0_MODULE_rst              ((MAX_RESET_LIST_NUM*7)|0x09)
	#define RESETINDEX_OF_CROP1_MODULE_rst              ((MAX_RESET_LIST_NUM*7)|0x0a)
	#define RESETINDEX_OF_CSC0_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x0b)
	#define RESETINDEX_OF_CSC1_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x0c)
	#define RESETINDEX_OF_CSC2_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x0d)
	#define RESETINDEX_OF_CSC3_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x0e)
	#define RESETINDEX_OF_SCALER0_MODULE_rst            ((MAX_RESET_LIST_NUM*7)|0x0f)
	#define RESETINDEX_OF_SCALER1_MODULE_rst            ((MAX_RESET_LIST_NUM*7)|0x10)
	#define RESETINDEX_OF_SCALER2_MODULE_rst            ((MAX_RESET_LIST_NUM*7)|0x11)
	#define RESETINDEX_OF_fm_conv1p2p_0_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x12)
	#define RESETINDEX_OF_fm_conv1p2p_1_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x13)
	#define RESETINDEX_OF_fm_conv1p2p_2_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x14)
	#define RESETINDEX_OF_fm_conv1p2p_3_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x15)
	#define RESETINDEX_OF_fm_conv1p2p_4_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x16)
	#define RESETINDEX_OF_fm_conv1p2p_5_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x17)
	#define RESETINDEX_OF_fm_conv444p_0_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x18)
	#define RESETINDEX_OF_fm_conv444p_1_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x19)
	#define RESETINDEX_OF_fm_conv444p_2_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x1a)
	#define RESETINDEX_OF_fm_conv444p_3_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x1b)
	#define RESETINDEX_OF_fm_conv444p_4_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x1c)
	#define RESETINDEX_OF_fm_conv444p_5_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x1d)
	#define RESETINDEX_OF_multitap0_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x1e)
	#define RESETINDEX_OF_multitap1_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x1f)
	#define RESETINDEX_OF_multitap2_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x20)
	#define RESETINDEX_OF_multitap3_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x21)
	#define RESETINDEX_OF_iss_dmar0_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x22)
	#define RESETINDEX_OF_iss_dmar1_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x23)
	#define RESETINDEX_OF_iss_dmaw0_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x24)
	#define RESETINDEX_OF_iss_dmaw1_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x25)
	#define RESETINDEX_OF_iss_dmaw2_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x26)
	#define RESETINDEX_OF_iss_dmaw3_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x27)
	#define RESETINDEX_OF_iss_dmaw4_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x28)
	#define RESETINDEX_OF_iss_dmaw5_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x29)
	#define RESETINDEX_OF_iss_dmaw6_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x2a)
	#define RESETINDEX_OF_iss_dmaw7_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x2b)
	#define RESETINDEX_OF_iss_dmaw8_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x2c)
	#define RESETINDEX_OF_iss_dmaw9_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x2d)
	#define RESETINDEX_OF_iss_dmaw10_MODULE_rst         ((MAX_RESET_LIST_NUM*7)|0x2e)
	#define RESETINDEX_OF_iss_dmaw11_MODULE_rst         ((MAX_RESET_LIST_NUM*7)|0x2f)
	#define RESETINDEX_OF_hue0_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x30)
	#define RESETINDEX_OF_hue1_MODULE_rst               ((MAX_RESET_LIST_NUM*7)|0x31)
	#define RESETINDEX_OF_gamma0_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x32)
	#define RESETINDEX_OF_gamma1_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x33)
	#define RESETINDEX_OF_mlcpri_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x34)
	#define RESETINDEX_OF_mlcpri_dmar0_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x35)
	#define RESETINDEX_OF_mlcpri_dmar1_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x36)
	#define RESETINDEX_OF_mlcpri_dmar2_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x37)
	#define RESETINDEX_OF_mlcpri_dmar3_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x38)
	#define RESETINDEX_OF_mlcpri_dmar4_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x39)
	#define RESETINDEX_OF_mlcpri_dmar5_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x3a)
	#define RESETINDEX_OF_mlcsec_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x3b)
	#define RESETINDEX_OF_mlcsec_dmar0_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x3c)
	#define RESETINDEX_OF_mlcsec_dmar1_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x3d)
	#define RESETINDEX_OF_mlcsec_dmar2_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x3e)
	#define RESETINDEX_OF_mlcsec_dmar3_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x3f)
	#define RESETINDEX_OF_mlcsec_dmar4_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x40)
	#define RESETINDEX_OF_mlcsec_dmar5_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x41)
	#define RESETINDEX_OF_lvdslink_MODULE_rst           ((MAX_RESET_LIST_NUM*7)|0x42)
	#define RESETINDEX_OF_VIP0_MODULE_i_nRST            ((MAX_RESET_LIST_NUM*7)|0x43)
	#define RESETINDEX_OF_VIP1_MODULE_i_nRST            ((MAX_RESET_LIST_NUM*7)|0x44)
	#define RESETINDEX_OF_VIP2_MODULE_i_nRST            ((MAX_RESET_LIST_NUM*7)|0x45)
	#define RESETINDEX_OF_VIP3_MODULE_i_nRST            ((MAX_RESET_LIST_NUM*7)|0x46)
	#define RESETINDEX_OF_MIPI_MODULE_rst              ((MAX_RESET_LIST_NUM*7)|0x47)
	#define RESETINDEX_OF_MIPI_PHY_M_MODULE_rst        ((MAX_RESET_LIST_NUM*7)|0x48)
	#define RESETINDEX_OF_MIPI_PHY_S_MODULE_rst        ((MAX_RESET_LIST_NUM*7)|0x49)
	#define RESETINDEX_OF_MIPI_CSI_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x4a)
	#define RESETINDEX_OF_MIPI_DSI_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x4b)
	#define RESETINDEX_OF_DEINTERLACE_MODULE_i_nRST     ((MAX_RESET_LIST_NUM*7)|0x52)
	#define RESETINDEX_OF_dpcpri_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x53)
	#define RESETINDEX_OF_dpcsec_MODULE_rst             ((MAX_RESET_LIST_NUM*7)|0x54)
	#define RESETINDEX_OF_mux2hdmi_MODULE_rst           ((MAX_RESET_LIST_NUM*7)|0x55)
	#define RESETINDEX_OF_mux2lvds_MODULE_rst           ((MAX_RESET_LIST_NUM*7)|0x56)
	#define RESETINDEX_OF_mux2mipi0_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x57)
	#define RESETINDEX_OF_mux2mipi1_MODULE_rst          ((MAX_RESET_LIST_NUM*7)|0x58)
	#define RESETINDEX_OF_hdmilink_MODULE_rst           ((MAX_RESET_LIST_NUM*7)|0x59)
	#define RESETINDEX_OF_hdmilink_video_MODULE_rst     ((MAX_RESET_LIST_NUM*7)|0x5a)
	#define RESETINDEX_OF_hdmilink_spdif_MODULE_rst     ((MAX_RESET_LIST_NUM*7)|0x5b)
	#define RESETINDEX_OF_hdmilink_tmds_MODULE_rst      ((MAX_RESET_LIST_NUM*7)|0x5c)
	#define RESETINDEX_OF_hdmilink_cec_MODULE_rst       ((MAX_RESET_LIST_NUM*7)|0x5d)
	#define RESETINDEX_OF_hdmiphy_MODULE_rset           ((MAX_RESET_LIST_NUM*7)|0x5e)
	#define RESETINDEX_OF_hdmiphy_MODULE_presetn        ((MAX_RESET_LIST_NUM*7)|0x5f)
	#define RESETINDEX_OF_lvdsphy_MODULE_rst            ((MAX_RESET_LIST_NUM*7)|0x60)

	// nx01000_CMUTOP_coda_cpuif_regmap
	#define RESETINDEX_OF_CODA_MODULE_APB_rst			((MAX_RESET_LIST_NUM*8)|0x00)
	#define RESETINDEX_OF_CODATIEOFF_MODULE_apb_rst     ((MAX_RESET_LIST_NUM*8)|0x01)
	#define RESETINDEX_OF_JPEG_MODULE_APB_rst           ((MAX_RESET_LIST_NUM*8)|0x02)


	// 5540에는 없는데 prototype에 존재하는 reset pin ==> c compile error가 나서 추가해놓음
	// !!!!!!!!!!!!!! 관리 안되는 것들 ==> 담당자가 확인해야 함 !!!!!!!!!!!!!!!!
	#define RESETINDEX_OF_MPEGTSI_MODULE_i_nRST    				(0x1000)
	#define RESETINDEX_OF_USB20HOST_MODULE_i_nRST				(0x1001)	// = 56
	#define RESETINDEX_OF_USB20OTG_MODULE_i_nRST				(0x1002)	// = 57
	#define RESETINDEX_OF_MALI400_MODULE_nRST					(0x1003)	// = 65
	//#define RESETINDEX_OF_DEINTERLACE_MODULE_i_nRST				(0x1004)	// = 8
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_Top_nRST			(0x1005)	// = 9
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_DualDisplay_nRST	(0x1006)	// = 10
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_ResConv_nRST		(0x1007)	// = 11
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_LCDIF_nRST		(0x1008)	// = 12
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_nRST			(0x1009)	// = 13
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_VIDEO_nRST	(0x100a)	// = 14
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_SPDIF_nRST	(0x100b)	// = 15
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_TMDS_nRST	(0x100c)	// = 16
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_HDMI_PHY_nRST		(0x100d)	// = 17
	#define RESETINDEX_OF_DISPLAYTOP_MODULE_i_LVDS_nRST			(0x100e)	// = 18

	#define RESETINDEX_OF_MIPI_MODULE_i_nRST					(0x100f)	// = 29
	#define RESETINDEX_OF_MIPI_MODULE_i_DSI_I_PRESETn			(0x1010)	// = 30
	#define RESETINDEX_OF_MIPI_MODULE_i_CSI_I_PRESETn			(0x1011)	// = 31
	#define RESETINDEX_OF_MIPI_MODULE_i_PHY_S_RESETN			(0x1012)	// = 32
	#define RESETINDEX_OF_MIPI_MODULE_i_PHY_M_RESETN			(0x1013)	// = 33

	//#define RESETINDEX_OF_MPEGTSI_MODULE_i_nRST					(0x1014)	// = 34
	#define RESETINDEX_OF_PDM_MODULE_i_nRST						(0x1015)	// = 35
	#define RESETINDEX_OF_SCALER_MODULE_i_nRST					(0x1016)	// = 38
	#define RESETINDEX_OF_SSP0_MODULE_PRESETn					(0x1017)	// = 44
	#define RESETINDEX_OF_SSP0_MODULE_nSSPRST					(0x1018)	// = 45
	#define RESETINDEX_OF_SSP1_MODULE_PRESETn					(0x1019)	// = 46
	#define RESETINDEX_OF_SSP1_MODULE_nSSPRST					(0x101a)	// = 47
	#define RESETINDEX_OF_SSP2_MODULE_PRESETn					(0x101b)	// = 48
	#define RESETINDEX_OF_SSP2_MODULE_nSSPRST					(0x101c)	// = 49
	#define RESETINDEX_OF_WDT0_MODULE_nPOR						(0x101d)	// = 59
	#define RESETINDEX_OF_WDT1_MODULE_nPOR						(0x101e)	// = 59

//------------------------------------------------------------------------------
// Clock Generator : Module Index of Clock Generator
//------------------------------------------------------------------------------

enum {
 CLOCKINDEX_OF_TIMER_SRC1_MODULE          = 0
,CLOCKINDEX_OF_TIMER_SRC2_MODULE          = 1
,CLOCKINDEX_OF_TIMER_SRC3_MODULE          = 2
,CLOCKINDEX_OF_PWM_SRC1_MODULE            = 3
,CLOCKINDEX_OF_PWM_SRC2_MODULE            = 4
,CLOCKINDEX_OF_PWM_SRC3_MODULE            = 5
,CLOCKINDEX_OF_I2C0_MODULE                  = 6
,CLOCKINDEX_OF_I2C1_MODULE                  = 7
,CLOCKINDEX_OF_I2C2_MODULE                  = 8
,CLOCKINDEX_OF_MIPI_MODULE                  = 9
,CLOCKINDEX_OF_DWC_GMAC_MODULE              = 10
,CLOCKINDEX_OF_SPDIFTX_MODULE               = 11
,CLOCKINDEX_OF_MPEGTSI_MODULE               = 12
,CLOCKINDEX_OF_PWM_SRC0_MODULE                   = 13
,CLOCKINDEX_OF_TIMER_SRC0_MODULE                 = 14
,CLOCKINDEX_OF_I2S0_MODULE                  = 15
,CLOCKINDEX_OF_I2S1_MODULE                  = 16
,CLOCKINDEX_OF_I2S2_MODULE                  = 17
,CLOCKINDEX_OF_SDMMC0_MODULE                = 18
,CLOCKINDEX_OF_SDMMC1_MODULE                = 19
,CLOCKINDEX_OF_SDMMC2_MODULE                = 20
,CLOCKINDEX_OF_MALI400_MODULE               = 21
,CLOCKINDEX_OF_UART0_MODULE                 = 22
,CLOCKINDEX_OF_UART1_MODULE                 = 23
,CLOCKINDEX_OF_pl01115_Uart_modem_MODULE    = 24
,CLOCKINDEX_OF_pl01115_Uart_nodma0_MODULE   = 25
,CLOCKINDEX_OF_pl01115_Uart_nodma1_MODULE   = 26
,CLOCKINDEX_OF_pl01115_Uart_nodma2_MODULE   = 27
,CLOCKINDEX_OF_DEINTERLACE_MODULE           = 28
,CLOCKINDEX_OF_PPM_MODULE                   = 29
,CLOCKINDEX_OF_VIP0_MODULE                  = 30
,CLOCKINDEX_OF_VIP1_MODULE                  = 31
,CLOCKINDEX_OF_USB20HOST_MODULE             = 32
,CLOCKINDEX_OF_CODA980_MODULE               = 33
,CLOCKINDEX_OF_CRYPTO_MODULE                = 34
,CLOCKINDEX_OF_SCALER_MODULE                = 35
,CLOCKINDEX_OF_PDM_MODULE                   = 36
,CLOCKINDEX_OF_SSP0_MODULE                  = 37
,CLOCKINDEX_OF_SSP1_MODULE                  = 38
,CLOCKINDEX_OF_SSP2_MODULE                  = 39
,CLOCKINDEX_OF_VIP2_MODULE                  = 40
};

//  예시
//	#define CLOCKINDEX_OF_TIMER_SRC0_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER_SRC1_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//	#define CLOCKINDEX_OF_TIMER_SRC2_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER_SRC3_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//
//	#define CLOCKINDEX_OF_TIMER0_SRC0_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER0_SRC1_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//	#define CLOCKINDEX_OF_TIMER0_SRC2_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER0_SRC3_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//	#define CLOCKINDEX_OF_TIMER1_SRC0_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER1_SRC1_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//	#define CLOCKINDEX_OF_TIMER1_SRC2_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
//	#define CLOCKINDEX_OF_TIMER1_SRC3_MODULE			((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//
//	#define CLOCKINDEX_OF_UART0_MODULE					((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
//	#define CLOCKINDEX_OF_UART1_MODULE					((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
/*
	#define MAX_BUS_CLOCK_LIST_NUM			0x20
	#define LOG2_MAX_BUS_CLOCK_LIST_NUM		5
	#define MAX_BUS_CLOCK_LIST_NUM_MASK		0x1f

	// nx01000_CMUTOP_sys_cpuif_regmap
	#define CLOCKINDEX_OF_OSC_MUX_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x00)
	#define CLOCKINDEX_OF_PLL0_CLK_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x01)
	#define CLOCKINDEX_OF_PLL1_CLK_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x02)
	#define CLOCKINDEX_OF_PLL2_CLK_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*1)|0x03)
	#define CLOCKINDEX_OF_PLL3_CLK_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*1)|0x04)
	#define CLOCKINDEX_OF_PLL4_CLK_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*1)|0x05)
	#define CLOCKINDEX_OF_BUS_SYS_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x06)
	#define CLOCKINDEX_OF_PKA_SRC_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x07)
	#define CLOCKINDEX_OF_OSC_SRC_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x08)
	#define CLOCKINDEX_OF_CSSYS_SRC_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*1)|0x09)
	#define CLOCKINDEX_OF_MCUSTOP_SRC_MODULE        	((MAX_BUS_CLOCK_LIST_NUM*1)|0x0a)
	#define CLOCKINDEX_OF_TMCB_SRC_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*1)|0x0b)
	#define CLOCKINDEX_OF_TIMER_SRC0_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0c)
	#define CLOCKINDEX_OF_TIMER_SRC1_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0d)
	#define CLOCKINDEX_OF_TIMER_SRC2_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0e)
	#define CLOCKINDEX_OF_TIMER_SRC3_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x0f)
	#define CLOCKINDEX_OF_PWM_SRC0_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x10)
	#define CLOCKINDEX_OF_PWM_SRC1_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x11)
	#define CLOCKINDEX_OF_PWM_SRC2_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x12)
	#define CLOCKINDEX_OF_PWM_SRC3_MODULE				((MAX_BUS_CLOCK_LIST_NUM*1)|0x13)
	#define CLOCKINDEX_OF_PPMU_SYS_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*1)|0x14)
	#define CLOCKINDEX_OF_PO_SRC0_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x15)
	#define CLOCKINDEX_OF_PO_SRC1_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x16)
	#define CLOCKINDEX_OF_PO_SRC2_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x17)
	#define CLOCKINDEX_OF_PO_SRC3_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x18)
	#define CLOCKINDEX_OF_PO_SRC4_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x19)
	#define CLOCKINDEX_OF_PPM_MODULE	            	((MAX_BUS_CLOCK_LIST_NUM*1)|0x1a)

	// nx01000_CMUTOP_bbus_cpuif_regmap
	#define CLOCKINDEX_OF_BBUS_SYS_MODULE				((MAX_BUS_CLOCK_LIST_NUM*2)|0x00)
	#define CLOCKINDEX_OF_SDMMC1_MODULE             	((MAX_BUS_CLOCK_LIST_NUM*2)|0x01)
	#define CLOCKINDEX_OF_UART0_MODULE         			((MAX_BUS_CLOCK_LIST_NUM*2)|0x02)
	#define CLOCKINDEX_OF_UART1_MODULE         			((MAX_BUS_CLOCK_LIST_NUM*2)|0x03)
	#define CLOCKINDEX_OF_pl01115_Uart_modem_MODULE 	((MAX_BUS_CLOCK_LIST_NUM*2)|0x04)
	#define CLOCKINDEX_OF_pl01115_Uart_nodma0_MODULE	((MAX_BUS_CLOCK_LIST_NUM*2)|0x05)
	#define CLOCKINDEX_OF_pl01115_Uart_nodma1_MODULE	((MAX_BUS_CLOCK_LIST_NUM*2)|0x06)
	#define CLOCKINDEX_OF_pl01115_Uart_nodma2_MODULE	((MAX_BUS_CLOCK_LIST_NUM*2)|0x07)
	#define CLOCKINDEX_OF_SSP0_MODULE          			((MAX_BUS_CLOCK_LIST_NUM*2)|0x08)
	#define CLOCKINDEX_OF_SSP2_MODULE          			((MAX_BUS_CLOCK_LIST_NUM*2)|0x09)
	#define CLOCKINDEX_OF_SPDIFTX_MODULE       			((MAX_BUS_CLOCK_LIST_NUM*2)|0x0a)
	#define CLOCKINDEX_OF_I2S0_MODULE          			((MAX_BUS_CLOCK_LIST_NUM*2)|0x0b)
	#define CLOCKINDEX_OF_I2S1_MODULE          			((MAX_BUS_CLOCK_LIST_NUM*2)|0x0c)
	//#define CLOCKINDEX_OF_I2S5CH_MODULE        			(MAX_BUS_CLOCK_LIST_NUM*2)|0x0d
	#define CLOCKINDEX_OF_I2S2_MODULE        			((MAX_BUS_CLOCK_LIST_NUM*2)|0x0d)

	// nx01000_CMUTOP_lbus_cpuif_regmap
	#define CLOCKINDEX_OF_LBUS_SYS_MODULE				((MAX_BUS_CLOCK_LIST_NUM*3)|0x00)
	#define CLOCKINDEX_OF_SDMMC0_MODULE             	((MAX_BUS_CLOCK_LIST_NUM*3)|0x01)
	#define CLOCKINDEX_OF_SDMMC3_MODULE             	((MAX_BUS_CLOCK_LIST_NUM*3)|0x02)

	// nx01000_CMUTOP_tbus_cpuif_regmap
	#define CLOCKINDEX_OF_TBUS_SYS_MODULE				((MAX_BUS_CLOCK_LIST_NUM*4)|0x00)
	#define CLOCKINDEX_OF_DWC_GMAC_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*4)|0x01)
	#define CLOCKINDEX_OF_SSP1_MODULE 		         	((MAX_BUS_CLOCK_LIST_NUM*4)|0x02)
	#define CLOCKINDEX_OF_SDMMC2_MODULE             	((MAX_BUS_CLOCK_LIST_NUM*4)|0x03)
	#define CLOCKINDEX_OF_AC97_SCLK_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*4)|0x04)

	// nx01000_CMUTOP_gpu_cpuif_regmap
	#define CLOCKINDEX_OF_GPU_SYS_MODULE				((MAX_BUS_CLOCK_LIST_NUM*5)|0x00)

	// nx01000_CMUTOP_usb_cpuif_regmap
	#define CLOCKINDEX_OF_USB_SYS_MODULE				((MAX_BUS_CLOCK_LIST_NUM*6)|0x00)
	#define CLOCKINDEX_OF_OTG_SYS_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*6)|0x01)
	#define CLOCKINDEX_OF_HOST_SYS_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*6)|0x02)
	#define CLOCKINDEX_OF_HSIC_REFDIG_MODULE        	((MAX_BUS_CLOCK_LIST_NUM*6)|0x03)
	#define CLOCKINDEX_OF_HSIC_480M_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*6)|0x04)
	#define CLOCKINDEX_OF_OTG_REF_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*6)|0x05)
	//#define CLOCKINDEX_OF_HST_REF_MODULE          	  (MAX_BUS_CLOCK_LIST_NUM*6)|0x06
	#define CLOCKINDEX_OF_USB20HOST_MODULE				((MAX_BUS_CLOCK_LIST_NUM*6)|0x06)

	// nx01000_CMUTOP_disp_cpuif_regmap
	#define CLOCKINDEX_OF_DISP_SYS_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*7)|0x00)
	#define CLOCKINDEX_OF_HDMIPHY_APB_MODULE        	((MAX_BUS_CLOCK_LIST_NUM*7)|0x01)
	#define CLOCKINDEX_OF_DPC_PRI_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*7)|0x02)
	#define CLOCKINDEX_OF_DPC_SEC_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*7)|0x03)
	#define CLOCKINDEX_OF_DSI_PIX_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*7)|0x04)
	#define CLOCKINDEX_OF_DSI_1_PIX_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*7)|0x05)
	#define CLOCKINDEX_OF_CSI_PIX_MODULE            	((MAX_BUS_CLOCK_LIST_NUM*7)|0x06)
	#define CLOCKINDEX_OF_CSI_1_PIX_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*7)|0x07)
	#define CLOCKINDEX_OF_HDMI_PRE_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*7)|0x08)
	#define CLOCKINDEX_OF_HDMI_PIX_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*7)|0x09)
	#define CLOCKINDEX_OF_LVDS_PIX_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0a)
	#define CLOCKINDEX_OF_HDMI_SPDIF_MODULE         	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0b)
	#define CLOCKINDEX_OF_VIP0_MODULE               	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0c)
	#define CLOCKINDEX_OF_VIP1_MODULE               	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0d)
	#define CLOCKINDEX_OF_VIP2_MODULE               	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0e)
	#define CLOCKINDEX_OF_VIP3_MODULE               	((MAX_BUS_CLOCK_LIST_NUM*7)|0x0f)

	// nx01000_CMUTOP_coda_cpuif_regmap
	#define CLOCKINDEX_OF_CODA_SYS_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*8)|0x01)
	#define CLOCKINDEX_OF_JPEG_SYS_MODULE           	((MAX_BUS_CLOCK_LIST_NUM*8)|0x02)
	//#define CLOCKINDEX_OF_CODA_CORE_MODULE        	  (MAX_BUS_CLOCK_LIST_NUM*8)|0x03
	#define CLOCKINDEX_OF_CODA980_MODULE				((MAX_BUS_CLOCK_LIST_NUM*8)|0x03)
	#define CLOCKINDEX_OF_JPEG_CORE_MODULE          	((MAX_BUS_CLOCK_LIST_NUM*8)|0x04)

	// 5540에는 없는데 prototype에 존재하는 reset pin ==> c compile error가 나서 추가해놓음
	// !!!!!!!!!!!!!! 관리 안되는 것들 ==> 담당자가 확인해야 함 !!!!!!!!!!!!!!!!
	#define CLOCKINDEX_OF_MPEGTSI_MODULE				(0x200)
	#define CLOCKINDEX_OF_CRYPTO_MODULE					(0x201)
	#define CLOCKINDEX_OF_DEINTERLACE_MODULE			(0x202)
	#define CLOCKINDEX_OF_I2C0_MODULE					(0x203)
	#define CLOCKINDEX_OF_I2C1_MODULE					(0x204)
	#define CLOCKINDEX_OF_I2C2_MODULE					(0x205)
	#define CLOCKINDEX_OF_MALI400_MODULE				(0x206)
	#define CLOCKINDEX_OF_MIPI_MODULE					(0x207)
	#define CLOCKINDEX_OF_PDM_MODULE					(0x208)
	#define CLOCKINDEX_OF_SCALER_MODULE					(0x209)
*/

//------------------------------------------------------------------------------
// DMA peripheral index of modules for the DMA controller.
//------------------------------------------------------------------------------

enum {
//------------------------------------------------------------------------------
// BAGL RENDERING
//------------------------------------------------------------------------------
     DMAINDEX_OF_UART0_MODULE_UARTTXDMA                 = 0
    ,DMAINDEX_OF_UART0_MODULE_UARTRXDMA                 = 1
    ,DMAINDEX_OF_UART1_MODULE_UARTTXDMA                 = 2
    ,DMAINDEX_OF_UART1_MODULE_UARTRXDMA                 = 3
    ,DMAINDEX_OF_UART2_MODULE_UARTTXDMA                 = 4
    ,DMAINDEX_OF_UART2_MODULE_UARTRXDMA                 = 5
    ,DMAINDEX_OF_UART3_MODULE_UARTTXDMA                 = 16
    ,DMAINDEX_OF_UART3_MODULE_UARTRXDMA                 = 17
    ,DMAINDEX_OF_UART4_MODULE_UARTTXDMA                 = 18
    ,DMAINDEX_OF_UART4_MODULE_UARTRXDMA                 = 19
    ,DMAINDEX_OF_UART5_MODULE_UARTTXDMA                 = 20
    ,DMAINDEX_OF_UART5_MODULE_UARTRXDMA                 = 21
    ,DMAINDEX_OF_UART6_MODULE_UARTTXDMA                 = 22
    ,DMAINDEX_OF_UART6_MODULE_UARTRXDMA                 = 23
    ,DMAINDEX_OF_UART7_MODULE_UARTTXDMA                 = 53
    ,DMAINDEX_OF_UART7_MODULE_UARTRXDMA                 = 54
    ,DMAINDEX_OF_UART8_MODULE_UARTTXDMA                 = 55
    ,DMAINDEX_OF_UART8_MODULE_UARTRXDMA                 = 56

    ,DMAINDEX_OF_SSP0_MODULE_SSPTXDMA                   = 6
    ,DMAINDEX_OF_SSP0_MODULE_SSPRXDMA                   = 7
    ,DMAINDEX_OF_SSP1_MODULE_SSPTXDMA                   = 8
    ,DMAINDEX_OF_SSP1_MODULE_SSPRXDMA                   = 9
    ,DMAINDEX_OF_SSP2_MODULE_SSPTXDMA                   = 10
    ,DMAINDEX_OF_SSP2_MODULE_SSPRXDMA                   = 11
    ,DMAINDEX_OF_I2S0_MODULE_I2STXDMA                   = 12
    ,DMAINDEX_OF_I2S0_MODULE_I2SRXDMA                   = 13
    ,DMAINDEX_OF_I2S1_MODULE_I2STXDMA                   = 14
    ,DMAINDEX_OF_I2S1_MODULE_I2SRXDMA                   = 15

    ,DMAINDEX_OF_I2S2_MODULE_I2STXDMA                   = 32
    ,DMAINDEX_OF_I2S2_MODULE_I2SRXDMA                   = 33
    ,DMAINDEX_OF_AC97_MODULE_PCMOUTDMA                  = 34
    ,DMAINDEX_OF_AC97_MODULE_PCMINDMA                   = 35
    ,DMAINDEX_OF_AC97_MODULE_MICINDMA                   = 36
    ,DMAINDEX_OF_SPDIFRX_MODULE                         = 37
    ,DMAINDEX_OF_SPDIFTX_MODULE                         = 38
    ,DMAINDEX_OF_MPEGTSI_MODULE_MPTSIDMA0               = 39
    ,DMAINDEX_OF_MPEGTSI_MODULE_MPTSIDMA1               = 40
    ,DMAINDEX_OF_MPEGTSI_MODULE_MPTSIDMA2               = 41
    ,DMAINDEX_OF_MPEGTSI_MODULE_MPTSIDMA3               = 42
    ,DMAINDEX_OF_CRYPTO_MODULE_CRYPDMA_BR               = 43
    ,DMAINDEX_OF_CRYPTO_MODULE_CRYPDMA_BW               = 44
    ,DMAINDEX_OF_CRYPTO_MODULE_CRYPDMA_HR               = 45
    ,DMAINDEX_OF_PDM0_MODULE                            = 46
    ,DMAINDEX_OF_PWM_MODULE_PWMDMA                      = 47        // @todo charlse - remove
    ,DMAINDEX_OF_PWM0_MODULE_PWMDMA                     = 47
    ,DMAINDEX_OF_PWM1_MODULE_PWMDMA                     = 48
    ,DMAINDEX_OF_PWM2_MODULE_PWMDMA                     = 49
    ,DMAINDEX_OF_PWM3_MODULE_PWMDMA                     = 50
    ,DMAINDEX_OF_I2S3_MODULE_I2STXDMA                   = 51
    ,DMAINDEX_OF_I2S3_MODULE_I2SRXDMA                   = 52

	,DMAINDEX_OF_PDM1_MODULE                            = 57
	,DMAINDEX_OF_PDM2_MODULE                            = 58
	,DMAINDEX_OF_PDM3_MODULE                            = 59

	,DMAINDEX_OF_PDM0_MODULE_RAW                        = 60
	,DMAINDEX_OF_PDM1_MODULE_RAW                        = 61
	,DMAINDEX_OF_PDM2_MODULE_RAW                        = 62
	,DMAINDEX_OF_PDM3_MODULE_RAW                        = 63

};

//------------------------------------------------------------------------------
// BAGL RENDERING END
//------------------------------------------------------------------------------






#ifdef __cplusplus
}
#endif

#endif // __NX_CHIP_NXP5540_H__


