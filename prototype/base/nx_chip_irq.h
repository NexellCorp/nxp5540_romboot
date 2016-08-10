#ifndef __NX_CHIP_IRQ__H__
#define __NX_CHIP_IRQ__H__

#ifndef U32 
	#define U32 unsigned int 
#endif

#ifdef	__cplusplus
extern "C"
{
#endif


//------------
// PHY BASEADDR 
//------------
        
    //--------------------------------------------------------------------------
    //  IRQ Base Address
    //--------------------------------------------------------------------------


enum {
	 INTNUM_OF_MIPIDSIM_MODULE                          = (254+32)	// Inst_DISP_o_MIPI0_DSI_INT
	,INTNUM_OF_MIPICSIS_MODULE                          = (253+32)	// Inst_DISP_o_MIPI0_CSI_INT
	,INTNUM_OF_AUDIO_IO_CTRL_MODULE                     = (252+32)	// Inst_AUDIO_IO_CTRL_o_IRQ
	,INTNUM_OF_USB3_MODULE_BC                           = (251+32)	// Inst_BLK_USB_usb3_bc_interrupt
	,INTNUM_OF_USB3_MODULE_ADP                          = (250+32)	// Inst_BLK_USB_usb3_adp_interrupt
	,INTNUM_OF_USB3_MODULE_OTG                          = (249+32)	// Inst_BLK_USB_usb3_otg_interrupt
	,INTNUM_OF_USB3_MODULE_INT                          = (248+32)	// Inst_BLK_USB_usb3_interrupt
	,INTNUM_OF_MDMA_MODULE                              = (247+32)	// Inst_mdmac_irq
	,INTNUM_OF_PDM3_MODULE                              = (244+32)	// Inst_PDM3_o_IRQ
	,INTNUM_OF_PDM2_MODULE                              = (243+32)	// Inst_PDM2_o_IRQ
	,INTNUM_OF_PDM1_MODULE                              = (242+32)	// Inst_PDM1_o_IRQ
	,INTNUM_OF_MPEGTSI_MODULE_TSI1                      = (241+32)	// Inst_MPEGTSI00_o_TSI1_IRQ
	,INTNUM_OF_MPEGTSI_MODULE_TSI0                      = (240+32)	// Inst_MPEGTSI00_o_TSI0_IRQ
	,INTNUM_OF_TIMER1_MODULE_INT4                       = (231+32)	// Inst_TIMER1_INT4
	,INTNUM_OF_TIMER0_MODULE_INT4                       = (230+32)	// Inst_TIMER0_INT4
	,INTNUM_OF_PWM3_MODULE_INT4                         = (229+32)	// Inst_PWM3_INT4
	,INTNUM_OF_PWM2_MODULE_INT4                         = (228+32)	// Inst_PWM2_INT4
	,INTNUM_OF_PWM1_MODULE_INT4                         = (227+32)	// Inst_PWM1_INT4
	,INTNUM_OF_PWM0_MODULE_INT4                         = (226+32)	// Inst_PWM0_INT4
	,INTNUM_OF_UART8_MODULE                             = (225+32)	// Inst_UART08_INTREQ
	,INTNUM_OF_UART7_MODULE                             = (224+32)	// Inst_UART07_INTREQ
	,INTNUM_OF_UART6_MODULE                             = (223+32)	// Inst_UART06_INTREQ
	,INTNUM_OF_MCD_MODULE                               = (222+32)	// Inst_DISP_o_MCD_IRQ
	,INTNUM_OF_DMAW11                                   = (221+32)	// Inst_DISP_o_IRQ_DMAW11
	,INTNUM_OF_DMAW10                                   = (220+32)	// Inst_DISP_o_IRQ_DMAW10
	,INTNUM_OF_DMAW9                                    = (219+32)	// Inst_DISP_o_IRQ_DMAW9
	,INTNUM_OF_DMAW8                                    = (218+32)	// Inst_DISP_o_IRQ_DMAW8
	,INTNUM_OF_DMAW7                                    = (217+32)	// Inst_DISP_o_IRQ_DMAW7
	,INTNUM_OF_DMAW6                                    = (216+32)	// Inst_DISP_o_IRQ_DMAW6
	,INTNUM_OF_GPIOH_MODULE                             = (215+32)	// GPIOH_IRQ_GPIOH_IRQ
	,INTNUM_OF_TPGEN0_MODULE                            = (206+32)	// Inst_DISP_o_IRQ_TPGEN0
	,INTNUM_OF_AXIM_IRQ_MODULE                          = (205+32)	// Inst_aximc_intr_or_o_IRQ
	,INTNUM_OF_GPIOG_MODULE                             = (178+32)	// GPIOG_IRQ_GPIOG_IRQ
	,INTNUM_OF_GPIOF_MODULE                             = (177+32)	// GPIOF_IRQ_GPIOF_IRQ
	,INTNUM_OF_GPIOE_MODULE                             = (176+32)	// GPIOE_IRQ_GPIOE_IRQ
	,INTNUM_OF_GPIOD_MODULE                             = (175+32)	// GPIOD_IRQ_GPIOD_IRQ
	,INTNUM_OF_GPIOC_MODULE                             = (174+32)	// GPIOC_IRQ_GPIOC_IRQ
	,INTNUM_OF_GPIOB_MODULE                             = (173+32)	// GPIOB_IRQ_GPIOB_IRQ
	,INTNUM_OF_GPIOA_MODULE                             = (172+32)	// GPIOA_IRQ_GPIOA_IRQ
	,INTNUM_OF_PWM3_MODULE_INT3                         = (171+32)	// Inst_PWM3_INT3
	,INTNUM_OF_PWM3_MODULE_INT2                         = (170+32)	// Inst_PWM3_INT2
	,INTNUM_OF_PWM3_MODULE_INT1                         = (169+32)	// Inst_PWM3_INT1
	,INTNUM_OF_PWM3_MODULE_INT0                         = (168+32)	// Inst_PWM3_INT0
	,INTNUM_OF_PWM2_MODULE_INT3                         = (167+32)	// Inst_PWM2_INT3
	,INTNUM_OF_PWM2_MODULE_INT2                         = (166+32)	// Inst_PWM2_INT2
	,INTNUM_OF_PWM2_MODULE_INT1                         = (165+32)	// Inst_PWM2_INT1
	,INTNUM_OF_PWM2_MODULE_INT0                         = (164+32)	// Inst_PWM2_INT0
	,INTNUM_OF_PWM1_MODULE_INT3                         = (163+32)	// Inst_PWM1_INT3
	,INTNUM_OF_PWM1_MODULE_INT2                         = (162+32)	// Inst_PWM1_INT2
	,INTNUM_OF_PWM1_MODULE_INT1                         = (161+32)	// Inst_PWM1_INT1
	,INTNUM_OF_PWM1_MODULE_INT0                         = (160+32)	// Inst_PWM1_INT0
	,INTNUM_OF_I2C4_MODULE                              = (159+32)	// Inst_I2C4_INT_I2C
	,INTNUM_OF_I2C3_MODULE                              = (158+32)	// Inst_I2C3_INT_I2C
	,INTNUM_OF_GPU_MODULE_INT1                          = (157+32)	// Inst_BLK_GPU_IRQ_1_
	,INTNUM_OF_GPU_MODULE                               = (156+32)	// Inst_BLK_GPU_IRQ_0_
	,INTNUM_OF_PKA_MODULE                               = (146+32)	// Inst_PKA_IRQ
	,INTNUM_OF_SDMA1_MODULE                             = (145+32)	// Inst_sdmac1_irq
	,INTNUM_OF_SDMA0_MODULE                             = (143+32)	// Inst_sdmac0_irq
	,INTNUM_OF_DMA1_MODULE                              = (141+32)	// Inst_dmac1_irq
	,INTNUM_OF_DMA0_MODULE                              = (139+32)	// Inst_dmac0_irq
	,INTNUM_OF_VIP3_MODULE                              = (137+32)	// Inst_DISP_o_VIP3_ODINT
	,INTNUM_OF_VIP2_MODULE                              = (136+32)	// Inst_DISP_o_VIP2_ODINT
	,INTNUM_OF_VIP1_MODULE                              = (135+32)	// Inst_DISP_o_VIP1_ODINT
	,INTNUM_OF_VIP0_MODULE                              = (134+32)	// Inst_DISP_o_VIP0_ODINT
	,INTNUM_OF_VIP3_SYNC_MODULE                         = (123+32)	// Inst_DISP_o_VIP3_SYNCIRQ
	,INTNUM_OF_NXS_TO_MIPIDSI_MODULE                    = (122+32)	// Inst_DISP_o_IRQ_NXS2MIPIDSI0
	,INTNUM_OF_DMAW5                                    =  (90+32)	// Inst_DISP_o_IRQ_DMAW5
	,INTNUM_OF_DMAW4                                    =  (89+32)	// Inst_DISP_o_IRQ_DMAW4
	,INTNUM_OF_DMAW3                                    =  (88+32)	// Inst_DISP_o_IRQ_DMAW3
	,INTNUM_OF_DMAW2                                    =  (87+32)	// Inst_DISP_o_IRQ_DMAW2
	,INTNUM_OF_DMAW1                                    =  (86+32)	// Inst_DISP_o_IRQ_DMAW1
	,INTNUM_OF_DMAW0                                    =  (85+32)	// Inst_DISP_o_IRQ_DMAW0
	,INTNUM_OF_PPM_MODULE_INT15                         =  (84+32)	// Inst_ppm_o_IRQ_15_
	,INTNUM_OF_PPM_MODULE_INT14                         =  (83+32)	// Inst_ppm_o_IRQ_14_
	,INTNUM_OF_PPM_MODULE_INT13                         =  (82+32)	// Inst_ppm_o_IRQ_13_
	,INTNUM_OF_PPM_MODULE_INT12                         =  (81+32)	// Inst_ppm_o_IRQ_12_
	,INTNUM_OF_PPM_MODULE_INT11                         =  (80+32)	// Inst_ppm_o_IRQ_11_
	,INTNUM_OF_PPM_MODULE_INT10                         =  (79+32)	// Inst_ppm_o_IRQ_10_
	,INTNUM_OF_PPM_MODULE_INT9                          =  (78+32)	// Inst_ppm_o_IRQ_9_
	,INTNUM_OF_TIMER1_MODULE_INT3                       =  (77+32)	// Inst_TIMER1_INT3
	,INTNUM_OF_TIMER1_MODULE_INT2                       =  (76+32)	// Inst_TIMER1_INT2
	,INTNUM_OF_TIMER1_MODULE_INT1                       =  (75+32)	// Inst_TIMER1_INT1
	,INTNUM_OF_TIMER1_MODULE_INT0                       =  (74+32)	// Inst_TIMER1_INT0
	,INTNUM_OF_VIP2_SYNC_MODULE                         =  (71+32)	// Inst_DISP_o_VIP2_SYNCIRQ
	,INTNUM_OF_DWC_GMAC_MODULE                          =  (68+32)	// Inst_gmac0_sbd_intr_o
	,INTNUM_OF_I2S3_MODULE                              =  (67+32)	// Inst_I2S3_I2S_INTR
	,INTNUM_OF_I2S2_MODULE                              =  (66+32)	// Inst_I2S2_I2S_INTR
	,INTNUM_OF_I2S1_MODULE                              =  (65+32)	// Inst_I2S1_I2S_INTR
	,INTNUM_OF_I2S0_MODULE                              =  (64+32)	// Inst_I2S0_I2S_INTR
	,INTNUM_OF_PPM_MODULE_INT8                          =  (63+32)	// Inst_ppm_o_IRQ_8_
	,INTNUM_OF_PPM_MODULE_INT7                          =  (62+32)	// Inst_ppm_o_IRQ_7_
	,INTNUM_OF_TMU_BBUS_MODULE                          =  (60+32)	// Inst_TMU_BBUS_INTREQ_TMU
	,INTNUM_OF_PDM0_MODULE                              =  (58+32)	// Inst_PDM0_o_IRQ
	,INTNUM_OF_CRYPTO_MODULE                            =  (57+32)	// Inst_Crypto_o_IRQ
	,INTNUM_OF_PPM_MODULE_INT6                          =  (56+32)	// Inst_ppm_o_IRQ_6_
	,INTNUM_OF_PPM_MODULE_INT5                          =  (55+32)	// Inst_ppm_o_IRQ_5_
	,INTNUM_OF_PPM_MODULE_INT4                          =  (54+32)	// Inst_ppm_o_IRQ_4_
	,INTNUM_OF_PPM_MODULE_INT3                          =  (53+32)	// Inst_ppm_o_IRQ_3_
	,INTNUM_OF_PPM_MODULE_INT2                          =  (52+32)	// Inst_ppm_o_IRQ_2_
	,INTNUM_OF_USB20HOST_MODULE                         =  (49+32)	// Inst_BLK_USB_o_HOST_interrupt
	,INTNUM_OF_USB20OTG_MODULE                          =  (48+32)	// Inst_BLK_USB_o_OTG_interrupt
	,INTNUM_OF_SDMMC2_MODULE                            =  (44+32)	// Inst_SDMMC2_o_IntReq
	,INTNUM_OF_SDMMC1_MODULE                            =  (43+32)	// Inst_SDMMC1_o_IntReq
	,INTNUM_OF_SDMMC0_MODULE                            =  (42+32)	// Inst_SDMMC0_o_IntReq
	,INTNUM_OF_PPM_MODULE_INT0                          =  (41+32)	// Inst_ppm_o_IRQ_0_
	,INTNUM_OF_ADC_MODULE                               =  (40+32)	// Inst_adc_IRQ
	,INTNUM_OF_PPM_MODULE_INT1                          =  (39+32)	// Inst_ppm_o_IRQ_1_
	,INTNUM_OF_VIP0_SYNC_MODULE                         =  (37+32)	// Inst_DISP_o_VIP0_SYNCIRQ
	,INTNUM_OF_VIP1_SYNC_MODULE                         =  (36+32)	// Inst_DISP_o_VIP1_SYNCIRQ
	,INTNUM_OF_HDMI_MODULE                              =  (35+32)	// Inst_HDMI_o_HDMI_IRQ
	,INTNUM_OF_NXS_TO_HDMI_MODULE                       =  (34+32)	// Inst_HDMI_o_NXS_TO_HDMI_IRQ
	,INTNUM_OF_MPEGTSI_MODULE_CORE                      =  (31+32)	// Inst_MPEGTSI00_o_CORE_IRQ
	,INTNUM_OF_WDT0_MODULE                              =  (30+32)	// Inst_WDT00_WDTINT
	,INTNUM_OF_PWM0_MODULE_INT3                         =  (29+32)	// Inst_PWM0_INT3
	,INTNUM_OF_PWM0_MODULE_INT2                         =  (28+32)	// Inst_PWM0_INT2
	,INTNUM_OF_PWM0_MODULE_INT1                         =  (27+32)	// Inst_PWM0_INT1
	,INTNUM_OF_PWM0_MODULE_INT0                         =  (26+32)	// Inst_PWM0_INT0
	,INTNUM_OF_TIMER0_MODULE_INT3                       =  (25+32)	// Inst_TIMER0_INT3
	,INTNUM_OF_TIMER0_MODULE_INT2                       =  (24+32)	// Inst_TIMER0_INT2
	,INTNUM_OF_TIMER0_MODULE_INT1                       =  (23+32)	// Inst_TIMER0_INT1
	,INTNUM_OF_TIMER0_MODULE_INT0                       =  (22+32)	// Inst_TIMER0_INT0
	,INTNUM_OF_SPDIFTX_MODULE                           =  (21+32)	// Inst_SPDIFTX00_o_IRQ
	,INTNUM_OF_SPDIFRX_MODULE                           =  (20+32)	// Inst_SPDIFRX00_IRQOUT
	,INTNUM_OF_AC97_MODULE                              =  (19+32)	// Inst_AC970_AC_INT
	,INTNUM_OF_WDT1_MODULE                              =  (18+32)	// Inst_WDT01_WDTINT
	,INTNUM_OF_DEINTERLACE_MODULE                       =  (17+32)	// Inst_DISP_o_DEINTERLACE_IRQ
	,INTNUM_OF_I2C2_MODULE                              =  (16+32)	// Inst_I2C2_INT_I2C
	,INTNUM_OF_I2C1_MODULE                              =  (15+32)	// Inst_I2C1_INT_I2C
	,INTNUM_OF_I2C0_MODULE                              =  (14+32)	// Inst_I2C0_INT_I2C
	,INTNUM_OF_SSP2_MODULE                              =  (13+32)	// Inst_SSP2_SPI_INT
	,INTNUM_OF_SSP1_MODULE                              =  (12+32)	// Inst_SSP1_SPI_INT
	,INTNUM_OF_SSP0_MODULE                              =  (11+32)	// Inst_SSP0_SPI_INT
	,INTNUM_OF_UART5_MODULE                             =  (10+32)	// Inst_UART05_INTREQ
	,INTNUM_OF_UART4_MODULE                             =   (9+32)	// Inst_UART04_INTREQ
	,INTNUM_OF_UART3_MODULE                             =   (8+32)	// Inst_UART03_INTREQ
	,INTNUM_OF_UART2_MODULE                             =   (7+32)	// Inst_UART02_INTREQ
	,INTNUM_OF_UART1_MODULE                             =   (6+32)	// Inst_UART01_INTREQ
	,INTNUM_OF_UART0_MODULE                             =   (5+32)	// Inst_UART00_INTREQ
	,INTNUM_OF_CLKPWR_MODULE_RTCIRQ                     =   (4+32)	// Inst_SYSCTRLTOP_o_RTCIRQ
	,INTNUM_OF_CLKPWR_MODULE_ALIVEIRQ                   =   (3+32)	// Inst_SYSCTRLTOP_o_AliveIRQ
	,INTNUM_OF_CLKPWR_MODULE_INTREQPWR                  =   (2+32)	// Inst_SYSCTRLTOP_o_IntReqPWR
	,INTNUM_OF_CLKPWR_MODULE_INT_CEC                    =   (1+32)	// Inst_SYSCTRLTOP_o_int_cec
	,INTNUM_OF_MCUSTOP_MODULE                           =   (0+32)	// Inst_MCUSTOP_o_IRQ
	,INTNUM_OF_SGI0                                     = 0
	,INTNUM_OF_SGI1                                     = 1
	,INTNUM_OF_SGI2                                     = 2
	,INTNUM_OF_SGI3                                     = 3
	,INTNUM_OF_SGI4                                     = 4
	,INTNUM_OF_SGI5                                     = 5
	,INTNUM_OF_SGI6                                     = 6
	,INTNUM_OF_SGI7                                     = 7
	,INTNUM_OF_SGI8                                     = 8
	,INTNUM_OF_SGI9                                     = 9
	,INTNUM_OF_SGI10                                    = 10
	,INTNUM_OF_SGI11                                    = 11
	,INTNUM_OF_SGI12                                    = 12
	,INTNUM_OF_SGI13                                    = 13
	,INTNUM_OF_SGI14                                    = 14
	,INTNUM_OF_SGI15                                    = 15
	,INTNUM_OF_PPI16                                    = 16
	,INTNUM_OF_PPI17                                    = 17
	,INTNUM_OF_PPI18                                    = 18
	,INTNUM_OF_PPI19                                    = 19
	,INTNUM_OF_PPI20                                    = 20
	,INTNUM_OF_PPI21                                    = 21
	,INTNUM_OF_PPI22                                    = 22
	,INTNUM_OF_PPI23                                    = 23
	,INTNUM_OF_PPI24                                    = 24
	,INTNUM_OF_PPI25                                    = 25
	,INTNUM_OF_PPI26                                    = 26
	,INTNUM_OF_PPI27                                    = 27
	,INTNUM_OF_PPI28                                    = 28
	,INTNUM_OF_PPI29                                    = 29
	,INTNUM_OF_PPI30                                    = 30
	,INTNUM_OF_PPI31                                    = 31
};


//####################################################
//# IRQ struct
//####################################################
typedef struct _ARMTOPIrqField {
	U32 COMMIRQ[4];
	U32 CTIIRQ[4];
	U32 EXTERRIRQ[1];
	U32 PMUIRQ[4];
} ARMTOPIrqField;
typedef struct _CODAIrqField {
	U32 HOST[1];
	U32 JPEG[1];
	U32 VPU[1];
} CODAIrqField;
typedef struct _GPUIrqField {
	U32 INT[2];
} GPUIrqField;
typedef struct _ISPIrqField {
	U32 INT[5];
	U32 CPUIF[1];
} ISPIrqField;
typedef struct _USBIrqField {
	U32 HOST_EHCI[1];
	U32 HOST_OHCI[1];
} USBIrqField;
typedef struct _USB3IrqField {
	U32 BC[1];
	U32 ADP[1];
	U32 OTG[1];
	U32 INT[1];
} USB3IrqField;
typedef struct _WAVEIrqField {
	U32 IDLE[1];
	U32 INT0[1];
} WAVEIrqField;
typedef struct _WAVE420IrqField {
	U32 IDLE[1];
	U32 INT0[1];
} WAVE420IrqField;
typedef struct _DISPIrqField {
	U32 PPMU[1];
	U32 SBUS[1];
} DISPIrqField;
typedef struct _VIP0IrqField {
	U32 ODINT[1];
	U32 SYNC[1];
} VIP0IrqField;
typedef struct _VIP1IrqField {
	U32 ODINT[1];
	U32 SYNC[1];
} VIP1IrqField;
typedef struct _VIP2IrqField {
	U32 ODINT[1];
	U32 SYNC[1];
} VIP2IrqField;
typedef struct _VIP3IrqField {
	U32 ODINT[1];
	U32 SYNC[1];
} VIP3IrqField;
typedef struct _DMAIrqField {
	U32 INT0[1];
	U32 INT1[1];
} DMAIrqField;
typedef struct _DwcGmacIrqField {
	U32 LPI[1];
	U32 PMT[1];
	U32 SBD[1];
} DwcGmacIrqField;
typedef struct _MDMAIrqField {
	U32 INT0[1];
	U32 INT1[1];
} MDMAIrqField;
typedef struct _MPEGTSIIrqField {
	U32 CORE[1];
	U32 TSI0[1];
	U32 TSI1[1];
} MPEGTSIIrqField;
typedef struct _PPMIrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
	U32 INT5[1];
	U32 INT6[1];
	U32 INT7[1];
	U32 INT8[1];
	U32 INT9[1];
	U32 INT10[1];
	U32 INT11[1];
	U32 INT12[1];
	U32 INT13[1];
	U32 INT14[1];
	U32 INT15[1];
} PPMIrqField;
typedef struct _PWM0IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} PWM0IrqField;
typedef struct _PWM1IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} PWM1IrqField;
typedef struct _PWM2IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} PWM2IrqField;
typedef struct _PWM3IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} PWM3IrqField;
typedef struct _SDMAIrqField {
	U32 INT0[1];
	U32 INT1[1];
} SDMAIrqField;
typedef struct _CLKPWRIrqField {
	U32 ALIVEIRQ[1];
	U32 INT_CEC[1];
	U32 INTREQPWR[1];
	U32 RTCIRQ[1];
} CLKPWRIrqField;
typedef struct _TIMER0IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} TIMER0IrqField;
typedef struct _TIMER1IrqField {
	U32 INT0[1];
	U32 INT1[1];
	U32 INT2[1];
	U32 INT3[1];
	U32 INT4[1];
} TIMER1IrqField;

struct _IRQ_INFO {
	U32	GPIO[8];
	U32	AC97[1];
	U32	ADC[1];
	ARMTOPIrqField	ARMTOP[1];
	U32	AUDIO_IO_CTRL[1];
	U32	AXIM_IRQ[1];
	CODAIrqField	CODA[1];
	GPUIrqField	GPU[1];
	ISPIrqField	ISP[1];
	USBIrqField	USB[1];
	U32	USB20HOST[1];
	U32	USB20OTG[1];
	USB3IrqField	USB3[1];
	WAVEIrqField	WAVE[1];
	WAVE420IrqField	WAVE420[1];
	U32	CRYPTO[1];
	U32	CSI_TO_NXS[4];
	U32	DEINTERLACE[1];
	U32	DPC[2];
	U32	CROP[2];
	U32	CSC[4];
	U32	DMAR[10];
	U32	DMAW[12];
	U32	GAMMA[2];
	U32	HUE[2];
	U32	MULTI_TAP[4];
	U32	NXS_TO_MIPIDSI[1];
	DISPIrqField	DISP[1];
	U32	SCALER[3];
	U32	TPGEN[1];
	U32	LVDS[2];
	U32	WAVE412_MAPC[1];
	U32	MCD[1];
	U32	BLENDER[8];
	U32	BOTTOM[2];
	VIP0IrqField	VIP0[1];
	VIP1IrqField	VIP1[1];
	VIP2IrqField	VIP2[1];
	VIP3IrqField	VIP3[1];
	U32	NXS_FIFO[12];
	U32	CSI_TO_AXI[1];
	U32	MIPI_DSI[1];
	U32	MIPI_CSI[1];
	DMAIrqField	DMA[2];
	DwcGmacIrqField	DWC_GMAC[1];
	U32	HDMI[1];
	U32	NXS_TO_HDMI[1];
	U32	I2C0[1];
	U32	I2C1[1];
	U32	I2C2[1];
	U32	I2C3[1];
	U32	I2C4[1];
	U32	I2S0[1];
	U32	I2S1[1];
	U32	I2S2[1];
	U32	I2S3[1];
	U32	MCUSTOP[1];
	MDMAIrqField	MDMA[1];
	MPEGTSIIrqField	MPEGTSI[1];
	U32	PDM[4];
	U32	PKA[1];
	PPMIrqField	PPM[1];
	PWM0IrqField	PWM0[1];
	PWM1IrqField	PWM1[1];
	PWM2IrqField	PWM2[1];
	PWM3IrqField	PWM3[1];
	SDMAIrqField	SDMA[2];
	U32	SDMMC0[1];
	U32	SDMMC1[1];
	U32	SDMMC2[1];
	U32	SPDIFRX[1];
	U32	SPDIFTX[1];
	U32	SSP0[1];
	U32	SSP1[1];
	U32	SSP2[1];
	CLKPWRIrqField	CLKPWR[1];
	TIMER0IrqField	TIMER0[1];
	TIMER1IrqField	TIMER1[1];
	U32	TMU_BBUS[1];
	U32	UART[9];
	U32	WDT0[1];
	U32	WDT1[1];
	U32	MCU_MAILBOX[1];
};


extern struct _IRQ_INFO IRQ_INFO;


#ifdef	__cplusplus
}
#endif

#endif
