#include "nx_chip_irq.h"

// IRQ struct
struct _IRQ_INFO IRQ_INFO = {
	/* GPIO */
	{
		/* GPIO[0] */ (172 + 32),
		/* GPIO[1] */ (173 + 32),
		/* GPIO[2] */ (174 + 32),
		/* GPIO[3] */ (175 + 32),
		/* GPIO[4] */ (176 + 32),
		/* GPIO[5] */ (177 + 32),
		/* GPIO[6] */ (178 + 32),
		/* GPIO[7] */ (215 + 32),
	},
	/* AC97 */
	{
		/* AC97[0] */ (19 + 32),
	},
	/* ADC */
	{
		/* ADC[0] */ (40 + 32),
	},
	/* ARMTOP */
	{
		{
			{
			/* ARMTOP[0].COMMIRQ[0] */ (180 + 32),
			/* ARMTOP[0].COMMIRQ[1] */ (181 + 32),
			/* ARMTOP[0].COMMIRQ[2] */ (182 + 32),
			/* ARMTOP[0].COMMIRQ[3] */ (183 + 32),
			},
			{
			/* ARMTOP[0].CTIIRQ[0] */ (184 + 32),
			/* ARMTOP[0].CTIIRQ[1] */ (185 + 32),
			/* ARMTOP[0].CTIIRQ[2] */ (186 + 32),
			/* ARMTOP[0].CTIIRQ[3] */ (187 + 32),
			},
			{
			/* ARMTOP[0].EXTERRIRQ[0] */ (179 + 32),
			},
			{
			/* ARMTOP[0].PMUIRQ[0] */ (188 + 32),
			/* ARMTOP[0].PMUIRQ[1] */ (189 + 32),
			/* ARMTOP[0].PMUIRQ[2] */ (190 + 32),
			/* ARMTOP[0].PMUIRQ[3] */ (191 + 32),
			},
		},
	},
	/* AUDIO_IO_CTRL */
	{
		/* AUDIO_IO_CTRL[0] */ (252 + 32),
	},
	/* AXIM_IRQ */
	{
		/* AXIM_IRQ[0] */ (205 + 32),
	},
	/* CODA */
	{
		{
			{
			/* CODA[0].HOST[0] */ (45 + 32),
			},
			{
			/* CODA[0].JPEG[0] */ (46 + 32),
			},
			{
			/* CODA[0].VPU[0] */ (47 + 32),
			},
		},
	},
	/* GPU */
	{
		{
			{
			/* GPU[0].INT[0] */ (156 + 32),
			/* GPU[0].INT[1] */ (157 + 32),
			},
		},
	},
	/* ISP */
	{
		{
			{
			/* ISP[0].INT[0] */ (148 + 32),
			/* ISP[0].INT[1] */ (149 + 32),
			/* ISP[0].INT[2] */ (150 + 32),
			/* ISP[0].INT[3] */ (151 + 32),
			/* ISP[0].INT[4] */ (152 + 32),
			},
			{
			/* ISP[0].CPUIF[0] */ (147 + 32),
			},
		},
	},
	/* USB */
	{
		{
			{
			/* USB[0].HOST_EHCI[0] */ (51 + 32),
			},
			{
			/* USB[0].HOST_OHCI[0] */ (50 + 32),
			},
		},
	},
	/* USB20HOST */
	{
		/* USB20HOST[0] */ (49 + 32),
	},
	/* USB20OTG */
	{
		/* USB20OTG[0] */ (48 + 32),
	},
	/* USB3 */
	{
		{
			{
			/* USB3[0].BC[0] */ (251 + 32),
			},
			{
			/* USB3[0].ADP[0] */ (250 + 32),
			},
			{
			/* USB3[0].OTG[0] */ (249 + 32),
			},
			{
			/* USB3[0].INT[0] */ (248 + 32),
			},
		},
	},
	/* WAVE */
	{
		{
			{
			/* WAVE[0].IDLE[0] */ (72 + 32),
			},
			{
			/* WAVE[0].INT0[0] */ (73 + 32),
			},
		},
	},
	/* WAVE420 */
	{
		{
			{
			/* WAVE420[0].IDLE[0] */ (153 + 32),
			},
			{
			/* WAVE420[0].INT0[0] */ (154 + 32),
			},
		},
	},
	/* CRYPTO */
	{
		/* CRYPTO[0] */ (57 + 32),
	},
	/* CSI_TO_NXS */
	{
		/* CSI_TO_NXS[0] */ (110 + 32),
		/* CSI_TO_NXS[1] */ (111 + 32),
		/* CSI_TO_NXS[2] */ (112 + 32),
		/* CSI_TO_NXS[3] */ (113 + 32),
	},
	/* DEINTERLACE */
	{
		/* DEINTERLACE[0] */ (17 + 32),
	},
	/* DPC */
	{
		/* DPC[0] */ (32 + 32),
		/* DPC[1] */ (33 + 32),
	},
	/* CROP */
	{
		/* CROP[0] */ (95 + 32),
		/* CROP[1] */ (96 + 32),
	},
	/* CSC */
	{
		/* CSC[0] */ (128 + 32),
		/* CSC[1] */ (129 + 32),
		/* CSC[2] */ (130 + 32),
		/* CSC[3] */ (131 + 32),
	},
	/* DMAR */
	{
		/* DMAR[0] */ (97 + 32),
		/* DMAR[1] */ (98 + 32),
		/* DMAR[2] */ (99 + 32),
		/* DMAR[3] */ (100 + 32),
		/* DMAR[4] */ (101 + 32),
		/* DMAR[5] */ (102 + 32),
		/* DMAR[6] */ (103 + 32),
		/* DMAR[7] */ (104 + 32),
		/* DMAR[8] */ (105 + 32),
		/* DMAR[9] */ (106 + 32),
	},
	/* DMAW */
	{
		/* DMAW[0] */ (85 + 32),
		/* DMAW[1] */ (86 + 32),
		/* DMAW[2] */ (87 + 32),
		/* DMAW[3] */ (88 + 32),
		/* DMAW[4] */ (89 + 32),
		/* DMAW[5] */ (90 + 32),
		/* DMAW[6] */ (216 + 32),
		/* DMAW[7] */ (217 + 32),
		/* DMAW[8] */ (218 + 32),
		/* DMAW[9] */ (219 + 32),
		/* DMAW[10] */ (220 + 32),
		/* DMAW[11] */ (221 + 32),
	},
	/* GAMMA */
	{
		/* GAMMA[0] */ (93 + 32),
		/* GAMMA[1] */ (94 + 32),
	},
	/* HUE */
	{
		/* HUE[0] */ (91 + 32),
		/* HUE[1] */ (92 + 32),
	},
	/* MULTI_TAP */
	{
		/* MULTI_TAP[0] */ (114 + 32),
		/* MULTI_TAP[1] */ (115 + 32),
		/* MULTI_TAP[2] */ (116 + 32),
		/* MULTI_TAP[3] */ (117 + 32),
	},
	/* NXS_TO_MIPIDSI */
	{
		/* NXS_TO_MIPIDSI[0] */ (122 + 32),
	},
	/* DISP */
	{
		{
			{
			/* DISP[0].PPMU[0] */ (120 + 32),
			},
			{
			/* DISP[0].SBUS[0] */ (119 + 32),
			},
		},
	},
	/* SCALER */
	{
		/* SCALER[0] */ (107 + 32),
		/* SCALER[1] */ (108 + 32),
		/* SCALER[2] */ (109 + 32),
	},
	/* TPGEN */
	{
		/* TPGEN[0] */ (206 + 32),
	},
	/* LVDS */
	{
		/* LVDS[0] */ (118 + 32),
		/* LVDS[1] */ (38 + 32),
	},
	/* WAVE412_MAPC */
	{
		/* WAVE412_MAPC[0] */ (121 + 32),
	},
	/* MCD */
	{
		/* MCD[0] */ (222 + 32),
	},
	/* BLENDER */
	{
		/* BLENDER[0] */ (207 + 32),
		/* BLENDER[1] */ (208 + 32),
		/* BLENDER[2] */ (209 + 32),
		/* BLENDER[3] */ (210 + 32),
		/* BLENDER[4] */ (211 + 32),
		/* BLENDER[5] */ (212 + 32),
		/* BLENDER[6] */ (213 + 32),
		/* BLENDER[7] */ (214 + 32),
	},
	/* BOTTOM */
	{
		/* BOTTOM[0] */ (132 + 32),
		/* BOTTOM[1] */ (133 + 32),
	},
	/* VIP0 */
	{
		{
			{
			/* VIP0[0].ODINT[0] */ (134 + 32),
			},
			{
			/* VIP0[0].SYNC[0] */ (37 + 32),
			},
		},
	},
	/* VIP1 */
	{
		{
			{
			/* VIP1[0].ODINT[0] */ (135 + 32),
			},
			{
			/* VIP1[0].SYNC[0] */ (36 + 32),
			},
		},
	},
	/* VIP2 */
	{
		{
			{
			/* VIP2[0].ODINT[0] */ (136 + 32),
			},
			{
			/* VIP2[0].SYNC[0] */ (71 + 32),
			},
		},
	},
	/* VIP3 */
	{
		{
			{
			/* VIP3[0].ODINT[0] */ (137 + 32),
			},
			{
			/* VIP3[0].SYNC[0] */ (123 + 32),
			},
		},
	},
	/* NXS_FIFO */
	{
		/* NXS_FIFO[0] */ (239 + 32),
		/* NXS_FIFO[1] */ (238 + 32),
		/* NXS_FIFO[2] */ (237 + 32),
		/* NXS_FIFO[3] */ (236 + 32),
		/* NXS_FIFO[4] */ (235 + 32),
		/* NXS_FIFO[5] */ (234 + 32),
		/* NXS_FIFO[6] */ (233 + 32),
		/* NXS_FIFO[7] */ (232 + 32),
		/* NXS_FIFO[8] */ (204 + 32),
		/* NXS_FIFO[9] */ (203 + 32),
		/* NXS_FIFO[10] */ (202 + 32),
		/* NXS_FIFO[11] */ (201 + 32),
	},
	/* CSI_TO_AXI */
	{
		/* CSI_TO_AXI[0] */ (245 + 32),
	},
	/* MIPI_DSI */
	{
		/* MIPI_DSI[0] */ (254 + 32),
	},
	/* MIPI_CSI */
	{
		/* MIPI_CSI[0] */ (253 + 32),
	},
	/* DMA */
	{
		{
			{
			/* DMA[0].INT0[0] */ (139 + 32),
			},
			{
			/* DMA[0].INT1[0] */ (138 + 32),
			},
		},
		{
			{
			/* DMA[1].INT0[0] */ (141 + 32),
			},
			{
			/* DMA[1].INT1[0] */ (140 + 32),
			},
		},
	},
	/* DWC_GMAC */
	{
		{
			{
			/* DWC_GMAC[0].LPI[0] */ (69 + 32),
			},
			{
			/* DWC_GMAC[0].PMT[0] */ (70 + 32),
			},
			{
			/* DWC_GMAC[0].SBD[0] */ (68 + 32),
			},
		},
	},
	/* HDMI */
	{
		/* HDMI[0] */ (35 + 32),
	},
	/* NXS_TO_HDMI */
	{
		/* NXS_TO_HDMI[0] */ (34 + 32),
	},
	/* I2C0 */
	{
		/* I2C0[0] */ (14 + 32),
	},
	/* I2C1 */
	{
		/* I2C1[0] */ (15 + 32),
	},
	/* I2C2 */
	{
		/* I2C2[0] */ (16 + 32),
	},
	/* I2C3 */
	{
		/* I2C3[0] */ (158 + 32),
	},
	/* I2C4 */
	{
		/* I2C4[0] */ (159 + 32),
	},
	/* I2S0 */
	{
		/* I2S0[0] */ (64 + 32),
	},
	/* I2S1 */
	{
		/* I2S1[0] */ (65 + 32),
	},
	/* I2S2 */
	{
		/* I2S2[0] */ (66 + 32),
	},
	/* I2S3 */
	{
		/* I2S3[0] */ (67 + 32),
	},
	/* MCUSTOP */
	{
		/* MCUSTOP[0] */ (0 + 32),
	},
	/* MDMA */
	{
		{
			{
			/* MDMA[0].INT0[0] */ (247 + 32),
			},
			{
			/* MDMA[0].INT1[0] */ (246 + 32),
			},
		},
	},
	/* MPEGTSI */
	{
		{
			{
			/* MPEGTSI[0].CORE[0] */ (31 + 32),
			},
			{
			/* MPEGTSI[0].TSI0[0] */ (240 + 32),
			},
			{
			/* MPEGTSI[0].TSI1[0] */ (241 + 32),
			},
		},
	},
	/* PDM */
	{
		/* PDM[0] */ (58 + 32),
		/* PDM[1] */ (242 + 32),
		/* PDM[2] */ (243 + 32),
		/* PDM[3] */ (244 + 32),
	},
	/* PKA */
	{
		/* PKA[0] */ (146 + 32),
	},
	/* PPM */
	{
		{
			{
			/* PPM[0].INT0[0] */ (41 + 32),
			},
			{
			/* PPM[0].INT1[0] */ (39 + 32),
			},
			{
			/* PPM[0].INT2[0] */ (52 + 32),
			},
			{
			/* PPM[0].INT3[0] */ (53 + 32),
			},
			{
			/* PPM[0].INT4[0] */ (54 + 32),
			},
			{
			/* PPM[0].INT5[0] */ (55 + 32),
			},
			{
			/* PPM[0].INT6[0] */ (56 + 32),
			},
			{
			/* PPM[0].INT7[0] */ (62 + 32),
			},
			{
			/* PPM[0].INT8[0] */ (63 + 32),
			},
			{
			/* PPM[0].INT9[0] */ (78 + 32),
			},
			{
			/* PPM[0].INT10[0] */ (79 + 32),
			},
			{
			/* PPM[0].INT11[0] */ (80 + 32),
			},
			{
			/* PPM[0].INT12[0] */ (81 + 32),
			},
			{
			/* PPM[0].INT13[0] */ (82 + 32),
			},
			{
			/* PPM[0].INT14[0] */ (83 + 32),
			},
			{
			/* PPM[0].INT15[0] */ (84 + 32),
			},
		},
	},
	/* PWM0 */
	{
		{
			{
			/* PWM0[0].INT0[0] */ (26 + 32),
			},
			{
			/* PWM0[0].INT1[0] */ (27 + 32),
			},
			{
			/* PWM0[0].INT2[0] */ (28 + 32),
			},
			{
			/* PWM0[0].INT3[0] */ (29 + 32),
			},
			{
			/* PWM0[0].INT4[0] */ (226 + 32),
			},
		},
	},
	/* PWM1 */
	{
		{
			{
			/* PWM1[0].INT0[0] */ (160 + 32),
			},
			{
			/* PWM1[0].INT1[0] */ (161 + 32),
			},
			{
			/* PWM1[0].INT2[0] */ (162 + 32),
			},
			{
			/* PWM1[0].INT3[0] */ (163 + 32),
			},
			{
			/* PWM1[0].INT4[0] */ (227 + 32),
			},
		},
	},
	/* PWM2 */
	{
		{
			{
			/* PWM2[0].INT0[0] */ (164 + 32),
			},
			{
			/* PWM2[0].INT1[0] */ (165 + 32),
			},
			{
			/* PWM2[0].INT2[0] */ (166 + 32),
			},
			{
			/* PWM2[0].INT3[0] */ (167 + 32),
			},
			{
			/* PWM2[0].INT4[0] */ (228 + 32),
			},
		},
	},
	/* PWM3 */
	{
		{
			{
			/* PWM3[0].INT0[0] */ (168 + 32),
			},
			{
			/* PWM3[0].INT1[0] */ (169 + 32),
			},
			{
			/* PWM3[0].INT2[0] */ (170 + 32),
			},
			{
			/* PWM3[0].INT3[0] */ (171 + 32),
			},
			{
			/* PWM3[0].INT4[0] */ (229 + 32),
			},
		},
	},
	/* SDMA */
	{
		{
			{
			/* SDMA[0].INT0[0] */ (143 + 32),
			},
			{
			/* SDMA[0].INT1[0] */ (142 + 32),
			},
		},
		{
			{
			/* SDMA[1].INT0[0] */ (145 + 32),
			},
			{
			/* SDMA[1].INT1[0] */ (144 + 32),
			},
		},
	},
	/* SDMMC0 */
	{
		/* SDMMC0[0] */ (42 + 32),
	},
	/* SDMMC1 */
	{
		/* SDMMC1[0] */ (43 + 32),
	},
	/* SDMMC2 */
	{
		/* SDMMC2[0] */ (44 + 32),
	},
	/* SPDIFRX */
	{
		/* SPDIFRX[0] */ (20 + 32),
	},
	/* SPDIFTX */
	{
		/* SPDIFTX[0] */ (21 + 32),
	},
	/* SSP0 */
	{
		/* SSP0[0] */ (11 + 32),
	},
	/* SSP1 */
	{
		/* SSP1[0] */ (12 + 32),
	},
	/* SSP2 */
	{
		/* SSP2[0] */ (13 + 32),
	},
	/* CLKPWR */
	{
		{
			{
			/* CLKPWR[0].ALIVEIRQ[0] */ (3 + 32),
			},
			{
			/* CLKPWR[0].INT_CEC[0] */ (1 + 32),
			},
			{
			/* CLKPWR[0].INTREQPWR[0] */ (2 + 32),
			},
			{
			/* CLKPWR[0].RTCIRQ[0] */ (4 + 32),
			},
		},
	},
	/* TIMER0 */
	{
		{
			{
			/* TIMER0[0].INT0[0] */ (22 + 32),
			},
			{
			/* TIMER0[0].INT1[0] */ (23 + 32),
			},
			{
			/* TIMER0[0].INT2[0] */ (24 + 32),
			},
			{
			/* TIMER0[0].INT3[0] */ (25 + 32),
			},
			{
			/* TIMER0[0].INT4[0] */ (230 + 32),
			},
		},
	},
	/* TIMER1 */
	{
		{
			{
			/* TIMER1[0].INT0[0] */ (74 + 32),
			},
			{
			/* TIMER1[0].INT1[0] */ (75 + 32),
			},
			{
			/* TIMER1[0].INT2[0] */ (76 + 32),
			},
			{
			/* TIMER1[0].INT3[0] */ (77 + 32),
			},
			{
			/* TIMER1[0].INT4[0] */ (231 + 32),
			},
		},
	},
	/* TMU_BBUS */
	{
		/* TMU_BBUS[0] */ (60 + 32),
	},
	/* UART */
	{
		/* UART[0] */ (5 + 32),
		/* UART[1] */ (6 + 32),
		/* UART[2] */ (7 + 32),
		/* UART[3] */ (8 + 32),
		/* UART[4] */ (9 + 32),
		/* UART[5] */ (10 + 32),
		/* UART[6] */ (223 + 32),
		/* UART[7] */ (224 + 32),
		/* UART[8] */ (225 + 32),
	},
	/* WDT0 */
	{
		/* WDT0[0] */ (30 + 32),
	},
	/* WDT1 */
	{
		/* WDT1[0] */ (18 + 32),
	},
	/* MCU_MAILBOX */
	{
		/* MCU_MAILBOX[0] */ (200 + 32),
	},
};

