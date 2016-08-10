
#ifndef __NX_RESETCONTROL_DEF_H__
#define __NX_RESETCONTROL_DEF_H__




//================================================
// usage eample
//================================================
//	nx_cpuif_reg_write_one( RST_INFO_DEF__sys_0_axi_rst );

#ifndef _NX_RESET_INFO_DEF_REPORT_
#define _NX_RESET_INFO_DEF_REPORT_


	#define RST_INFO_DEF__cci400_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__tieoff_cci_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__sys_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__sys_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__timer_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__timer_4_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__pwm_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__pwm_4_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__pwm_8_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__pwm_12_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__sysctrl_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__hpm_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),11,1}
	#define RST_INFO_DEF__q_enhancer_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),12,1}
	#define RST_INFO_DEF__crypto_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),13,1}
	#define RST_INFO_DEF__wdt_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),14,1}
	#define RST_INFO_DEF__wdt_0_por_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),15,1}
	#define RST_INFO_DEF__wdt_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),16,1}
	#define RST_INFO_DEF__wdt_1_por_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),17,1}
	#define RST_INFO_DEF__tzpc_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),18,1}
	#define RST_INFO_DEF__ecid_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),19,1}
	#define RST_INFO_DEF__dmac_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),20,1}
	#define RST_INFO_DEF__dmac_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),21,1}
	#define RST_INFO_DEF__sdmac_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),22,1}
	#define RST_INFO_DEF__sdmac_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),23,1}
	#define RST_INFO_DEF__mdmac_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),24,1}
	#define RST_INFO_DEF__systieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),25,1}
	#define RST_INFO_DEF__mcus_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),26,1}
	#define RST_INFO_DEF__isp_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),27,1}
	#define RST_INFO_DEF__disp_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),28,1}
	#define RST_INFO_DEF__usb_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),29,1}
	#define RST_INFO_DEF__coda_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),30,1}
	#define RST_INFO_DEF__gpu_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x0),31,1}
	#define RST_INFO_DEF__hdmi_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),0,1}
	#define RST_INFO_DEF__wave_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),1,1}
	#define RST_INFO_DEF__wave420_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),2,1}
	#define RST_INFO_DEF__drex_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),3,1}
	#define RST_INFO_DEF__cpu_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),4,1}
	#define RST_INFO_DEF__periclk_cmu_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),5,1}
	#define RST_INFO_DEF__pdm_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),6,1}
	#define RST_INFO_DEF__pdm_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),7,1}
	#define RST_INFO_DEF__pdm_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),8,1}
	#define RST_INFO_DEF__pdm_3_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),9,1}
	#define RST_INFO_DEF__audio_io_ctrl_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),10,1}
	#define RST_INFO_DEF__pka_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),11,1}
	#define RST_INFO_DEF__cssys_src_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),12,1}
	#define RST_INFO_DEF__mcustop_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),13,1}
	#define RST_INFO_DEF__bus_dmac_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),14,1}
	#define RST_INFO_DEF__dmac_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),15,1}
	#define RST_INFO_DEF__dmac_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),16,1}
	#define RST_INFO_DEF__sdmac_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),17,1}
	#define RST_INFO_DEF__sdmac_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),18,1}
	#define RST_INFO_DEF__mdmac_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),19,1}
	#define RST_INFO_DEF__gic400_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_SYS[0], ((1<<15)|0x4),20,1}
	#define RST_INFO_DEF__bbus_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__bbus_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__bbus_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__uart_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__uart_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__uart_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__uart_3_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__uart_4_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__uart_5_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__uart_6_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__uart_7_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__uart_8_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),11,1}
	#define RST_INFO_DEF__spdiftx_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),12,1}
	#define RST_INFO_DEF__spdifrx_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),13,1}
	#define RST_INFO_DEF__tmu_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),14,1}
	#define RST_INFO_DEF__bbustieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),15,1}
	#define RST_INFO_DEF__adc_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),16,1}
	#define RST_INFO_DEF__gpio_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),17,1}
	#define RST_INFO_DEF__gpio_3_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),18,1}
	#define RST_INFO_DEF__gpio_4_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),19,1}
	#define RST_INFO_DEF__uart_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),20,1}
	#define RST_INFO_DEF__uart_1_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),21,1}
	#define RST_INFO_DEF__uart_2_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),22,1}
	#define RST_INFO_DEF__uart_3_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),23,1}
	#define RST_INFO_DEF__uart_4_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),24,1}
	#define RST_INFO_DEF__uart_5_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),25,1}
	#define RST_INFO_DEF__uart_6_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),26,1}
	#define RST_INFO_DEF__uart_7_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),27,1}
	#define RST_INFO_DEF__uart_8_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),28,1}
	#define RST_INFO_DEF__spi_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),29,1}
	#define RST_INFO_DEF__spi_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),30,1}
	#define RST_INFO_DEF__spi_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x0),31,1}
	#define RST_INFO_DEF__spi_1_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x4),0,1}
	#define RST_INFO_DEF__spi_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x4),1,1}
	#define RST_INFO_DEF__spi_2_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x4),2,1}
	#define RST_INFO_DEF__spdiftx_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_BBUS[0], ((1<<15)|0x4),3,1}
	#define RST_INFO_DEF__tbus_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__tbus_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__tbus_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__i2s_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__i2s_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__i2s_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__i2s_3_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__ac97_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__i2c_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__i2c_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__i2s_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__i2s_1_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),11,1}
	#define RST_INFO_DEF__i2s_2_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),12,1}
	#define RST_INFO_DEF__i2s_3_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_TBUS[0], ((1<<15)|0x0),13,1}
	#define RST_INFO_DEF__lbus_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__lbus_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__gmac_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__mp2ts_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__lbus_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__gmac_0_csr_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__lbustieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__gpio_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__gpio_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__i2c_2_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__i2c_3_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__i2c_4_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),11,1}
	#define RST_INFO_DEF__sdmmc_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),12,1}
	#define RST_INFO_DEF__sdmmc_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),13,1}
	#define RST_INFO_DEF__sdmmc_1_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),14,1}
	#define RST_INFO_DEF__sdmmc_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),15,1}
	#define RST_INFO_DEF__sdmmc_2_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),16,1}
	#define RST_INFO_DEF__sdmmc_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_LBUS[0], ((1<<15)|0x0),17,1}
	#define RST_INFO_DEF__usb_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__usb30_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__usb_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__usb_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__usb30_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__otg_sys_0_ahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__otg_sys_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__host_sys_0_ehciahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__host_sys_0_ohciahb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__host_sys_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__hsic_refdig_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_USB[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__drex0_0_drex_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__drex0_0_dll_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__drex0_0_mem_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__drex0_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__drex0_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__drextieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__drex_refr_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DREX0[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__disp_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__mipi_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__csi_to_axi_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__csi_to_nxs_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__csi_to_nxs_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__csi_to_nxs_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__csi_to_nxs_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__mlc_0_bottom0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__mlc_0_bottom1_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__mlc_0_blender0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__mlc_0_blender1_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),10,1}
	#define RST_INFO_DEF__mlc_0_blender2_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),11,1}
	#define RST_INFO_DEF__mlc_0_blender3_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),12,1}
	#define RST_INFO_DEF__mlc_0_blender4_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),13,1}
	#define RST_INFO_DEF__mlc_0_blender5_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),14,1}
	#define RST_INFO_DEF__mlc_0_blender6_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),15,1}
	#define RST_INFO_DEF__mlc_0_blender7_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),16,1}
	#define RST_INFO_DEF__vip_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),17,1}
	#define RST_INFO_DEF__vip_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),18,1}
	#define RST_INFO_DEF__vip_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),19,1}
	#define RST_INFO_DEF__vip_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),20,1}
	#define RST_INFO_DEF__mcd_cpuif_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),21,1}
	#define RST_INFO_DEF__vip_cpuif_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),22,1}
	#define RST_INFO_DEF__vip_pres_cpuif_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),23,1}
	#define RST_INFO_DEF__iss_cpuif_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),24,1}
	#define RST_INFO_DEF__disp2isp_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),25,1}
	#define RST_INFO_DEF__isp2disp_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),26,1}
	#define RST_INFO_DEF__isp2disp_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),27,1}
	#define RST_INFO_DEF__crop_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),28,1}
	#define RST_INFO_DEF__crop_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),29,1}
	#define RST_INFO_DEF__csc_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),30,1}
	#define RST_INFO_DEF__csc_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x0),31,1}
	#define RST_INFO_DEF__csc_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),0,1}
	#define RST_INFO_DEF__csc_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),1,1}
	#define RST_INFO_DEF__scaler_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),2,1}
	#define RST_INFO_DEF__scaler_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),3,1}
	#define RST_INFO_DEF__scaler_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),4,1}
	#define RST_INFO_DEF__multi_tap_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),5,1}
	#define RST_INFO_DEF__multi_tap_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),6,1}
	#define RST_INFO_DEF__multi_tap_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),7,1}
	#define RST_INFO_DEF__multi_tap_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),8,1}
	#define RST_INFO_DEF__dmar_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),9,1}
	#define RST_INFO_DEF__dmar_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),10,1}
	#define RST_INFO_DEF__dmar_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),11,1}
	#define RST_INFO_DEF__dmar_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),12,1}
	#define RST_INFO_DEF__dmar_4_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),13,1}
	#define RST_INFO_DEF__dmar_5_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),14,1}
	#define RST_INFO_DEF__dmar_6_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),15,1}
	#define RST_INFO_DEF__dmar_7_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),16,1}
	#define RST_INFO_DEF__dmar_8_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),17,1}
	#define RST_INFO_DEF__dmar_9_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),18,1}
	#define RST_INFO_DEF__dmaw_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),19,1}
	#define RST_INFO_DEF__dmaw_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),20,1}
	#define RST_INFO_DEF__dmaw_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),21,1}
	#define RST_INFO_DEF__dmaw_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),22,1}
	#define RST_INFO_DEF__dmaw_4_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),23,1}
	#define RST_INFO_DEF__dmaw_5_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),24,1}
	#define RST_INFO_DEF__dmaw_6_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),25,1}
	#define RST_INFO_DEF__dmaw_7_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),26,1}
	#define RST_INFO_DEF__dmaw_8_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),27,1}
	#define RST_INFO_DEF__dmaw_9_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),28,1}
	#define RST_INFO_DEF__dmaw_10_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),29,1}
	#define RST_INFO_DEF__dmaw_11_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),30,1}
	#define RST_INFO_DEF__hue_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x4),31,1}
	#define RST_INFO_DEF__hue_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),0,1}
	#define RST_INFO_DEF__gamma_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),1,1}
	#define RST_INFO_DEF__gamma_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),2,1}
	#define RST_INFO_DEF__dpc_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),3,1}
	#define RST_INFO_DEF__dpc_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),4,1}
	#define RST_INFO_DEF__lvds_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),5,1}
	#define RST_INFO_DEF__lvds_0_phy_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),6,1}
	#define RST_INFO_DEF__lvds_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),7,1}
	#define RST_INFO_DEF__lvds_1_phy_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),8,1}
	#define RST_INFO_DEF__nxs_fifo_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),9,1}
	#define RST_INFO_DEF__nxs_fifo_1_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),10,1}
	#define RST_INFO_DEF__nxs_fifo_2_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),11,1}
	#define RST_INFO_DEF__nxs_fifo_3_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),12,1}
	#define RST_INFO_DEF__nxs_fifo_4_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),13,1}
	#define RST_INFO_DEF__nxs_fifo_5_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),14,1}
	#define RST_INFO_DEF__nxs_fifo_6_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),15,1}
	#define RST_INFO_DEF__nxs_fifo_7_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),16,1}
	#define RST_INFO_DEF__nxs_fifo_8_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),17,1}
	#define RST_INFO_DEF__nxs_fifo_9_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),18,1}
	#define RST_INFO_DEF__nxs_fifo_10_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),19,1}
	#define RST_INFO_DEF__nxs_fifo_11_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),20,1}
	#define RST_INFO_DEF__nxs2hdmi_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),21,1}
	#define RST_INFO_DEF__tpgen_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),22,1}
	#define RST_INFO_DEF__disp_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),23,1}
	#define RST_INFO_DEF__deinterlace_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),24,1}
	#define RST_INFO_DEF__disp_tieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),25,1}
	#define RST_INFO_DEF__disp_tzpc_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),26,1}
	#define RST_INFO_DEF__disp_tzpc_1_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),27,1}
	#define RST_INFO_DEF__mipi_0_apbcsi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),28,1}
	#define RST_INFO_DEF__mipi_0_apbdsi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),29,1}
	#define RST_INFO_DEF__mipi_0_csiphy_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),30,1}
	#define RST_INFO_DEF__dpc_0_x2_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0x8),31,1}
	#define RST_INFO_DEF__dpc_1_x2_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),0,1}
	#define RST_INFO_DEF__mipi_0_x2_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),1,1}
	#define RST_INFO_DEF__lvds_0_vclk_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),2,1}
	#define RST_INFO_DEF__lvds_1_vclk_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),3,1}
	#define RST_INFO_DEF__deinterlace_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),4,1}
	#define RST_INFO_DEF__mapconv_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),5,1}
	#define RST_INFO_DEF__mcd_0_vclk_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_DISP[0], ((1<<15)|0xc),6,1}
	#define RST_INFO_DEF__hdmi_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__hdmiv2_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__hdmiv2_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__hdmiv2_0_apbphy_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__hdmiv2_0_phy_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__hdmiv2_0_tmds_10b_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__hdmiv2_0_tmds_20b_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__hdmiv2_0_pixelx2_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__hdmiv2_0_pixel_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),8,1}
	#define RST_INFO_DEF__hdmiv2_0_audio_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_HDMI[0], ((1<<15)|0x0),9,1}
	#define RST_INFO_DEF__cputieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CPU[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__coda980_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__jpeg_0_axi_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__coda980_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__jpeg_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__codatieoff_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__coda980_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),5,1}
	#define RST_INFO_DEF__coda980_0_sram_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),6,1}
	#define RST_INFO_DEF__jpeg_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_CODA[0], ((1<<15)|0x0),7,1}
	#define RST_INFO_DEF__wave_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__wave_v_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__wave_m_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__wave_c_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__wave_b_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__wave420_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__wave420_v_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__wave420_m_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|0x0),2,1}
	#define RST_INFO_DEF__wave420_c_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|0x0),3,1}
	#define RST_INFO_DEF__wave420_b_0_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|0x0),4,1}
	#define RST_INFO_DEF__periclk_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|0x0),0,1}
	#define RST_INFO_DEF__ppm_0_apb_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|0x0),1,1}
	#define RST_INFO_DEF__mcu_0_core_rst				(__nx_cpuif_symbol__){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|0x0),2,1}

#endif // #ifndef _NX_RESET_INFO_DEF_REPORT_
#endif // #ifndef __NX_RESETCONTROL_DEF_H__


