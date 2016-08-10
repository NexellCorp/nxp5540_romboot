
#ifndef __NX_CHIP_SFR__H__
#define __NX_CHIP_SFR__H__

#include "nx_type.h"

#ifdef	__cplusplus
extern "C"
{
#endif


//------------
// PHY BASEADDR 
//------------
        
    //--------------------------------------------------------------------------
    //  SFR Base Address
    //--------------------------------------------------------------------------
#if 1
	#define PHY_BASEADDR_AXISRAM_MODULE                         0x10000000
	#define PHY_BASEADDR_CHIPID_MODULE                          0x20000000
	#define PHY_BASEADDR_SYSCTRLTOP_MODULE                      0x20010000
	#define PHY_BASEADDR_PPMU_SYS_MODULE                        0x20030000
	#define PHY_BASEADDR_HPM_MODULE                             0x20040000
	#define PHY_BASEADDR_Q_ENHANCER_MODULE                      0x20050000
	#define PHY_BASEADDR_TIEOFF_SYS_MODULE                      0x20060000
	#define PHY_BASEADDR_CORESIGHT_MODULE                       0x20070000
	#define PHY_BASEADDR_CCI4000_MODULE                         0x20090000
	#define PHY_BASEADDR_CPU_REGBASE_MODULE                     0x200C0000
	#define PHY_BASEADDR_CMU_SYS_MODULE                         0x20100000
	#define PHY_BASEADDR_CMU_TBUS_MODULE                        0x20110000
	#define PHY_BASEADDR_CMU_LBUS_MODULE                        0x20120000
	#define PHY_BASEADDR_CMU_BBUS_MODULE                        0x20130000
	#define PHY_BASEADDR_CMU_ISP_MODULE                         0x20200000
	#define PHY_BASEADDR_CMU_CODA_MODULE                        0x20210000
	#define PHY_BASEADDR_CMU_DISP_MODULE                        0x20220000
	#define PHY_BASEADDR_CMU_USB_MODULE                         0x20230000
	#define PHY_BASEADDR_CMU_HDMI_MODULE                        0x20240000
	#define PHY_BASEADDR_CMU_GPU_MODULE                         0x20250000
	#define PHY_BASEADDR_CMU_WAVE_MODULE                        0x20260000
	#define PHY_BASEADDR_CMU_DREX0_MODULE                       0x20270000
	#define PHY_BASEADDR_CMU_WAVE420_MODULE                     0x20290000
	#define PHY_BASEADDR_CMU_PCIE_MODULE                        0x202A0000
	#define PHY_BASEADDR_TIEOFF_CPU0_MODULE                     0x202C0000
	#define PHY_BASEADDR_CMU_CPU0_MODULE                        0x202D0000
	#define PHY_BASEADDR_CMU_PERICLK_MODULE                     0x202E0000
	#define PHY_BASEADDR_TZPC_MODULE                            0x20300000
	#define PHY_BASEADDR_ECID_MODULE                            0x20310000
	#define PHY_BASEADDR_ECID_SECU_MODULE                       0x20320000
	#define PHY_BASEADDR_GIC4000_MODULE                         0x203F0000
	#define PHY_BASEADDR_TIEOFF_DREX0_MODULE                    0x20400000
	#define PHY_BASEADDR_DDRPHY0_MODULE                         0x20410000
	#define PHY_BASEADDR_DREXTZASC0_MODULE                      0x20420000
	#define PHY_BASEADDR_DREX0_CFG_MODULE                       0x20430000
	#define PHY_BASEADDR_TIEOFF_CODA_MODULE                     0x20500000
	#define PHY_BASEADDR_CODA9800_MODULE                        0x20510000
	#define PHY_BASEADDR_JPEG_MODULE                            0x20520000
	#define PHY_BASEADDR_AXIM_CODA0_MODULE                      0x20530000
	#define PHY_BASEADDR_AXIM_CODA1_MODULE                      0x20540000
	#define PHY_BASEADDR_AXIM_JPEG_MODULE                       0x20550000
	#define PHY_BASEADDR_CRYPTO_MODULE                          0x20600000
	#define PHY_BASEADDR_PPM_MODULE                             0x20610000
	#define PHY_BASEADDR_TIMER_MODULE                           0x20620000
	#define PHY_BASEADDR_TIMER_SECU_MODULE                      0x20630000
	#define PHY_BASEADDR_PWM0_MODULE                            0x20640000
	#define PHY_BASEADDR_PWM1_MODULE                            0x20650000
	#define PHY_BASEADDR_PWM2_MODULE                            0x20660000
	#define PHY_BASEADDR_PWM3_MODULE                            0x20670000
	#define PHY_BASEADDR_WDT_MODULE                             0x20680000
	#define PHY_BASEADDR_WDT_SECU_MODULE                        0x20690000
	#define PHY_BASEADDR_PDM0_MODULE                            0x206A0000
	#define PHY_BASEADDR_PDM1_MODULE                            0x206B0000
	#define PHY_BASEADDR_PDM2_MODULE                            0x206C0000
	#define PHY_BASEADDR_PDM3_MODULE                            0x206D0000
	#define PHY_BASEADDR_MCUSTOP_MODULE                         0x206E0000
	#define PHY_BASEADDR_AUDIO_IO_CTRL_MODULE                   0x206F0000
	#define PHY_BASEADDR_PKA_MODULE                             0x20700000
	#define PHY_BASEADDR_DMAC0_MODULE                           0x20780000
	#define PHY_BASEADDR_DMAC1_MODULE                           0x20790000
	#define PHY_BASEADDR_SEC_DMA0_MODULE                        0x207A0000
	#define PHY_BASEADDR_SEC_DMA1_MODULE                        0x207B0000
	#define PHY_BASEADDR_MDMAC0_MODULE                          0x207C0000
	#define PHY_BASEADDR_MCU_MAILBOX_MODULE                     0x20800000
	#define PHY_BASEADDR_MCU_SRAM_MODULE                        0x20810000
	#define PHY_BASEADDR_AC970_MODULE                           0x20820000
	#define PHY_BASEADDR_I2S0_MODULE                            0x20830000
	#define PHY_BASEADDR_I2S1_MODULE                            0x20840000
	#define PHY_BASEADDR_I2S2_MODULE                            0x20850000
	#define PHY_BASEADDR_I2S3_MODULE                            0x20860000
	#define PHY_BASEADDR_I2C0_MODULE                            0x20870000
	#define PHY_BASEADDR_I2C1_MODULE                            0x20880000
	#define PHY_BASEADDR_ISP_CPUIF_MODULE                       0x20900000
	#define PHY_BASEADDR_ISP_MODULE                             0x20920000
	#define PHY_BASEADDR_GPU_MODULE                             0x20A00000
	#define PHY_BASEADDR_AXIM_GPU_MODULE                        0x20A10000
	#define PHY_BASEADDR_TIEOFF_GPU_MODULE                      0x20A20000
	#define PHY_BASEADDR_ISS0_MODULE                            0x20C00000
	#define PHY_BASEADDR_SECURE_ISS0_MODULE                     0x20C10000
	#define PHY_BASEADDR_VIP_MCD0_MODULE                        0x20C20000
	#define PHY_BASEADDR_SECURE_VIP_MCD0_MODULE                 0x20C30000
	#define PHY_BASEADDR_VIP_VIP_MODULE                         0x20C40000
	#define PHY_BASEADDR_VIP_PRES_MODULE                        0x20C50000
	#define PHY_BASEADDR_SECURE_VIP_VIP_MODULE                  0x20C60000
	#define PHY_BASEADDR_SECURE_VIP_PRES_MODULE                 0x20C70000
	#define PHY_BASEADDR_DPC0_MODULE                            0x20C80000
	#define PHY_BASEADDR_DPC_0_I80MPU_MODULE                    0x20C90000
	#define PHY_BASEADDR_DPC1_MODULE                            0x20CA0000
	#define PHY_BASEADDR_DPC_1_NTSC_MODULE                      0x20CB0000
	#define PHY_BASEADDR_LVDS_MODULE                            0x20CC0000
	#define PHY_BASEADDR_MAPCONV0_MODULE                        0x20CD0000
	#define PHY_BASEADDR_LVDS1_MODULE                           0x20CE0000
	#define PHY_BASEADDR_AXIM_DMARW0_MODULE                     0x20D00000
	#define PHY_BASEADDR_AXIM_DMARW1_MODULE                     0x20D04000
	#define PHY_BASEADDR_AXIM_DMARW2_MODULE                     0x20D08000
	#define PHY_BASEADDR_AXIM_DMARW3_MODULE                     0x20D0C000
	#define PHY_BASEADDR_AXIM_DMARW4_MODULE                     0x20D10000
	#define PHY_BASEADDR_AXIM_DMARW5_MODULE                     0x20D14000
	#define PHY_BASEADDR_AXIM_DMARW6_MODULE                     0x20D18000
	#define PHY_BASEADDR_AXIM_DMARW7_MODULE                     0x20D1C000
	#define PHY_BASEADDR_AXIM_DMARW8_MODULE                     0x20D20000
	#define PHY_BASEADDR_AXIM_DMARW9_MODULE                     0x20D24000
	#define PHY_BASEADDR_AXIM_DMARW10_MODULE                    0x20D28000
	#define PHY_BASEADDR_AXIM_DMARW11_MODULE                    0x20D2C000
	#define PHY_BASEADDR_AXIM_DEINTERLACE0_MODULE               0x20D40000
	#define PHY_BASEADDR_AXIM_MAPCONV0_MODULE                   0x20D44000
	#define PHY_BASEADDR_AXIM_CSI_TO_AXI0_MODULE                0x20D4C000
	#define PHY_BASEADDR_DISP_TIEOFF_MODULE                     0x20E00000
	#define PHY_BASEADDR_DEINTERLACE_MODULE                     0x20E10000
	#define PHY_BASEADDR_MIPI_CSIS_MODULE                       0x20E20000
	#define PHY_BASEADDR_DISP_TZPC0_MODULE                      0x20E30000
	#define PHY_BASEADDR_DISP_TZPC1_MODULE                      0x20E40000
	#define PHY_BASEADDR_MIPI_DSIM_MODULE                       0x20E50000
	#define PHY_BASEADDR_DISP_BUS_CON_MODULE                    0x20E80000
	#define PHY_BASEADDR_NXS_TO_MIPIDSI_MODULE                  0x20E90000
	#define PHY_BASEADDR_NXS_TO_HDMI_MODULE                     0x20EC0000
	#define PHY_BASEADDR_HDMI_PHY_MODULE                        0x20ED0000
	#define PHY_BASEADDR_HDMI_LINK_MODULE                       0x20F00000
	#define PHY_BASEADDR_TIEOFF_LBUS_MODULE                     0x21000000
	#define PHY_BASEADDR_MPEGTSI_MODULE                         0x21040000
	#define PHY_BASEADDR_GPIO0_MODULE                           0x21050000
	#define PHY_BASEADDR_GPIO1_MODULE                           0x21060000
	#define PHY_BASEADDR_GMAC_MODULE                            0x21070000
	#define PHY_BASEADDR_I2C2_MODULE                            0x210B0000
	#define PHY_BASEADDR_I2C3_MODULE                            0x210C0000
	#define PHY_BASEADDR_I2C4_MODULE                            0x210D0000
	#define PHY_BASEADDR_SDMMC0_MODULE                          0x21100000
	#define PHY_BASEADDR_SDMMC1_MODULE                          0x21110000
	#define PHY_BASEADDR_SDMMC2_MODULE                          0x21120000
	#define PHY_BASEADDR_TIEOFF_OTG_MODULE                      0x21200000
	#define PHY_BASEADDR_TIEOFF_HOST_MODULE                     0x21210000
	#define PHY_BASEADDR_TIEOFF_USB300_MODULE                   0x21220000
	#define PHY_BASEADDR_USB_OTG_LINK_A_MODULE                  0x21280000
	#define PHY_BASEADDR_USB_OTG_LINK_B_MODULE                  0x21290000
	#define PHY_BASEADDR_USB_HOST_EHCI_LINK_MODULE              0x212A0000
	#define PHY_BASEADDR_USB_HOST_OHCI_LINK_MODULE              0x212B0000
	#define PHY_BASEADDR_USB300_MODULE                          0x21300000
	#define PHY_BASEADDR_AXIM_CONNECTOR0_MODULE                 0x21600000
	#define PHY_BASEADDR_AXIM_CONNECTOR1_MODULE                 0x21610000
	#define PHY_BASEADDR_AXIM_CONNECTOR2_MODULE                 0x21620000
	#define PHY_BASEADDR_AXIM_CONNECTOR3_MODULE                 0x21630000
	#define PHY_BASEADDR_AXIM_CONNECTOR4_MODULE                 0x21640000
	#define PHY_BASEADDR_AXIM_CONNECTOR5_MODULE                 0x21650000
	#define PHY_BASEADDR_AXIM_CONNECTOR6_MODULE                 0x21660000
	#define PHY_BASEADDR_AXIM_CONNECTOR7_MODULE                 0x21670000
	#define PHY_BASEADDR_AXIM_CONNECTOR8_MODULE                 0x21680000
	#define PHY_BASEADDR_AXIM_CONNECTOR9_MODULE                 0x21690000
	#define PHY_BASEADDR_TIEOFF_BBUS_MODULE                     0x21800000
	#define PHY_BASEADDR_TMU_BBUS_MODULE                        0x21810000
	#define PHY_BASEADDR_ADC_MODULE                             0x21840000
	#define PHY_BASEADDR_UART0_MODULE                           0x21880000
	#define PHY_BASEADDR_UART1_MODULE                           0x21890000
	#define PHY_BASEADDR_UART2_MODULE                           0x218A0000
	#define PHY_BASEADDR_UART3_MODULE                           0x218B0000
	#define PHY_BASEADDR_UART4_MODULE                           0x218C0000
	#define PHY_BASEADDR_UART5_MODULE                           0x218D0000
	#define PHY_BASEADDR_SPI0_MODULE                            0x21900000
	#define PHY_BASEADDR_SPI1_MODULE                            0x21910000
	#define PHY_BASEADDR_SPI2_MODULE                            0x21920000
	#define PHY_BASEADDR_SPDIFTX_MODULE                         0x21930000
	#define PHY_BASEADDR_SPDIFRX_MODULE                         0x21940000
	#define PHY_BASEADDR_UART6_MODULE                           0x21950000
	#define PHY_BASEADDR_UART7_MODULE                           0x21960000
	#define PHY_BASEADDR_UART8_MODULE                           0x21970000
	#define PHY_BASEADDR_TIEOFF_WAVE_MODULE                     0x21A00000
	#define PHY_BASEADDR_WAVE4120_MODULE                        0x21A10000
	#define PHY_BASEADDR_AXIM_WAVE0_MODULE                      0x21A20000
	#define PHY_BASEADDR_AXIM_WAVE1_MODULE                      0x21A30000
	#define PHY_BASEADDR_TIEOFF_WAVE4200_MODULE                 0x21B00000
	#define PHY_BASEADDR_WAVE4200_MODULE                        0x21B10000
	#define PHY_BASEADDR_AXIM_WAVE4200_MODULE                   0x21B20000
	#define PHY_BASEADDR_AXIM_WAVE4201_MODULE                   0x21B30000
	#define PHY_BASEADDR_TIEOFF_PCI_MODULE                      0x21C00000
	#define PHY_BASEADDR_AXIM_PCI_MODULE                        0x21C10000
	#define PHY_BASEADDR_PCIE_PHY_MODULE                        0x21C20000
	#define PHY_BASEADDR_PCI_DBI_MODULE                         0x21C80000
	#define PHY_BASEADDR_SONICS_BUS_MODULE                      0x21F00000
#endif

struct _SFR_INFO {
	U32 AXISRAM[1];
	U32 CHIPID[1];
	U32 SYSCTRLTOP[1];
	U32 PPMU_SYS[1];
	U32 HPM[1];
	U32 Q_ENHANCER[1];
	U32 TIEOFF_SYS[1];
	U32 CoreSight[1];
	U32 CCI400[1];
	U32 CPU_REGBASE[1];
	U32 CMU_SYS[1];
	U32 CMU_TBUS[1];
	U32 CMU_LBUS[1];
	U32 CMU_BBUS[1];
	U32 CMU_ISP[1];
	U32 CMU_CODA[1];
	U32 CMU_DISP[1];
	U32 CMU_USB[1];
	U32 CMU_HDMI[1];
	U32 CMU_GPU[1];
	U32 CMU_WAVE[1];
	U32 CMU_DREX0[1];
	U32 CMU_WAVE420[1];
	U32 CMU_PCIE[1];
	U32 TIEOFF_CPU[1];
	U32 CMU_CPU[1];
	U32 CMU_PERICLK[1];
	U32 TZPC[1];
	U32 ECID[1];
	U32 ECID_SECU[1];
	U32 GIC400[1];
	U32 TIEOFF_DREX0[1];
	U32 DDRPHY0[1];
	U32 DREXTZASC0[1];
	U32 DREX0_CFG[1];
	U32 TIEOFF_CODA[1];
	U32 CODA980[1];
	U32 JPEG[1];
	U32 AXIM_CODA[2];
	U32 AXIM_JPEG[1];
	U32 CRYPTO[1];
	U32 PPM[1];
	U32 TIMER[1];
	U32 TIMER_SECU[1];
	U32 PWM0[1];
	U32 PWM1[1];
	U32 PWM2[1];
	U32 PWM3[1];
	U32 WDT[1];
	U32 WDT_SECU[1];
	U32 PDM[4];
	U32 MCUSTOP[1];
	U32 AUDIO_IO_CTRL[1];
	U32 PKA[1];
	U32 DMAC0[1];
	U32 DMAC1[1];
	U32 SEC_DMA0[1];
	U32 SEC_DMA1[1];
	U32 MDMAC0[1];
	U32 MCU_MAILBOX[1];
	U32 MCU_SRAM[1];
	U32 AC97[1];
	U32 I2S0[1];
	U32 I2S1[1];
	U32 I2S2[1];
	U32 I2S3[1];
	U32 I2C0[1];
	U32 I2C1[1];
	U32 ISP_CPUIF[1];
	U32 ISP[1];
	U32 GPU[1];
	U32 AXIM_GPU[1];
	U32 TIEOFF_GPU[1];
	U32 ISS[1];
	U32 SECURE_ISS[1];
	U32 VIP_MCD[1];
	U32 SECURE_VIP_MCD[1];
	U32 VIP_VIP[1];
	U32 VIP_PRES[1];
	U32 SECURE_VIP_VIP[1];
	U32 SECURE_VIP_PRES[1];
	U32 DPC[2];
	U32 DPC_0_I80MPU[1];
	U32 DPC_1_NTSC[1];
	U32 LVDS[2];
	U32 MAPCONV[1];
	U32 AXIM_DMARW[12];
	U32 AXIM_DEINTERLACE[1];
	U32 AXIM_MAPCONV[1];
	U32 AXIM_CSI_TO_AXI[1];
	U32 DISP_TIEOFF[1];
	U32 DEINTERLACE[1];
	U32 MIPI_CSIS[1];
	U32 DISP_TZPC0[1];
	U32 DISP_TZPC1[1];
	U32 MIPI_DSIM[1];
	U32 disp_bus_con[1];
	U32 NXS_TO_MIPIDSI[1];
	U32 NXS_TO_HDMI[1];
	U32 HDMI_PHY[1];
	U32 HDMI_LINK[1];
	U32 TIEOFF_LBUS[1];
	U32 MPEGTSI[1];
	U32 GPIO0[1];
	U32 GPIO1[1];
	U32 GMAC[1];
	U32 I2C2[1];
	U32 I2C3[1];
	U32 I2C4[1];
	U32 SDMMC0[1];
	U32 SDMMC1[1];
	U32 SDMMC2[1];
	U32 TIEOFF_OTG[1];
	U32 TIEOFF_HOST[1];
	U32 TIEOFF_USB30[1];
	U32 USB_OTG_LINK_A[1];
	U32 USB_OTG_LINK_B[1];
	U32 USB_HOST_EHCI_LINK[1];
	U32 USB_HOST_OHCI_LINK[1];
	U32 USB30[1];
	U32 AXIM_CONNECTOR[10];
	U32 TIEOFF_BBUS[1];
	U32 TMU_BBUS[1];
	U32 ADC[1];
	U32 UART0[1];
	U32 UART1[1];
	U32 UART2[1];
	U32 UART3[1];
	U32 UART4[1];
	U32 UART5[1];
	U32 SPI0[1];
	U32 SPI1[1];
	U32 SPI2[1];
	U32 SPDIFTX[1];
	U32 SPDIFRX[1];
	U32 UART6[1];
	U32 UART7[1];
	U32 UART8[1];
	U32 TIEOFF_wave[1];
	U32 WAVE412[1];
	U32 AXIM_WAVE[2];
	U32 TIEOFF_WAVE420[1];
	U32 WAVE420[1];
	U32 AXIM_WAVE420[2];
	U32 TIEOFF_PCI[1];
	U32 axim_pci[1];
	U32 pcie_phy[1];
	U32 PCI_DBI[1];
	U32 sonics_bus[1];
};

extern struct _SFR_INFO SFR_INFO;

#ifdef	__cplusplus
}
#endif

#endif
