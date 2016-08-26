
#ifndef __NX_RESETCONTROL_DEF_H__
#define __NX_RESETCONTROL_DEF_H__




//================================================
// usage eample
//================================================
//	nx_cpuif_reg_write_one( RSTI_sys_0_axi_rst );

#ifndef _NX_RESET_INFO_DEF_REPORT_
#define _NX_RESET_INFO_DEF_REPORT_

#define RSTI_cci400_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),0,1}
#define RSTM_cci400_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_tieoff_cci_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),1,1}
#define RSTM_tieoff_cci_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_sys_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),2,1}
#define RSTM_sys_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),3,1}
#define RSTM_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_timer_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),4,1}
#define RSTM_timer_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_timer_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),5,1}
#define RSTM_timer_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_pwm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),6,1}
#define RSTM_pwm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_pwm_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),7,1}
#define RSTM_pwm_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_pwm_8_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),8,1}
#define RSTM_pwm_8_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_pwm_12_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),9,1}
#define RSTM_pwm_12_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_sysctrl_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),10,1}
#define RSTM_sysctrl_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_hpm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),11,1}
#define RSTM_hpm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),11,1}
#define RSTI_q_enhancer_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),12,1}
#define RSTM_q_enhancer_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),12,1}
#define RSTI_crypto_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),13,1}
#define RSTM_crypto_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),13,1}
#define RSTI_wdt_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),14,1}
#define RSTM_wdt_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),14,1}
#define RSTI_wdt_0_por_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),15,1}
#define RSTM_wdt_0_por_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),15,1}
#define RSTI_wdt_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),16,1}
#define RSTM_wdt_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),16,1}
#define RSTI_wdt_1_por_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),17,1}
#define RSTM_wdt_1_por_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),17,1}
#define RSTI_tzpc_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),18,1}
#define RSTM_tzpc_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),18,1}
#define RSTI_ecid_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),19,1}
#define RSTM_ecid_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),19,1}
#define RSTI_dmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),20,1}
#define RSTM_dmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),20,1}
#define RSTI_dmac_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),21,1}
#define RSTM_dmac_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),21,1}
#define RSTI_sdmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),22,1}
#define RSTM_sdmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),22,1}
#define RSTI_sdmac_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),23,1}
#define RSTM_sdmac_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),23,1}
#define RSTI_mdmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),24,1}
#define RSTM_mdmac_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),24,1}
#define RSTI_systieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),25,1}
#define RSTM_systieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),25,1}
#define RSTI_mcus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),26,1}
#define RSTM_mcus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),26,1}
#define RSTI_isp_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),27,1}
#define RSTM_isp_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),27,1}
#define RSTI_disp_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),28,1}
#define RSTM_disp_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),28,1}
#define RSTI_usb_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),29,1}
#define RSTM_usb_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),29,1}
#define RSTI_coda_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),30,1}
#define RSTM_coda_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),30,1}
#define RSTI_gpu_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x0),31,1}
#define RSTM_gpu_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x0),31,1}
#define RSTI_hdmi_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),0,1}
#define RSTM_hdmi_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),0,1}
#define RSTI_wave_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),1,1}
#define RSTM_wave_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),1,1}
#define RSTI_wave420_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),2,1}
#define RSTM_wave420_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),2,1}
#define RSTI_drex_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),3,1}
#define RSTM_drex_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),3,1}
#define RSTI_cpu_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),4,1}
#define RSTM_cpu_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),4,1}
#define RSTI_periclk_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),5,1}
#define RSTM_periclk_cmu_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),5,1}
#define RSTI_pdm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),6,1}
#define RSTM_pdm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),6,1}
#define RSTI_pdm_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),7,1}
#define RSTM_pdm_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),7,1}
#define RSTI_pdm_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),8,1}
#define RSTM_pdm_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),8,1}
#define RSTI_pdm_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),9,1}
#define RSTM_pdm_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),9,1}
#define RSTI_audio_io_ctrl_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),10,1}
#define RSTM_audio_io_ctrl_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),10,1}
#define RSTI_pka_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),11,1}
#define RSTM_pka_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),11,1}
#define RSTI_cssys_src_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),12,1}
#define RSTM_cssys_src_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),12,1}
#define RSTI_mcustop_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),13,1}
#define RSTM_mcustop_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),13,1}
#define RSTI_bus_dmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),14,1}
#define RSTM_bus_dmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),14,1}
#define RSTI_dmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),15,1}
#define RSTM_dmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),15,1}
#define RSTI_dmac_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),16,1}
#define RSTM_dmac_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),16,1}
#define RSTI_sdmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),17,1}
#define RSTM_sdmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),17,1}
#define RSTI_sdmac_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),18,1}
#define RSTM_sdmac_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),18,1}
#define RSTI_mdmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),19,1}
#define RSTM_mdmac_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),19,1}
#define RSTI_gic400_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)        |0x4),20,1}
#define RSTM_gic400_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], ((1<<15)|(1<<11)|0x4),20,1}
#define RSTI_bbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),0,1}
#define RSTM_bbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_bbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),1,1}
#define RSTM_bbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_bbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),2,1}
#define RSTM_bbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_uart_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),3,1}
#define RSTM_uart_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_uart_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),4,1}
#define RSTM_uart_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_uart_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),5,1}
#define RSTM_uart_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_uart_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),6,1}
#define RSTM_uart_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_uart_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),7,1}
#define RSTM_uart_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_uart_5_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),8,1}
#define RSTM_uart_5_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_uart_6_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),9,1}
#define RSTM_uart_6_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_uart_7_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),10,1}
#define RSTM_uart_7_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_uart_8_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),11,1}
#define RSTM_uart_8_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),11,1}
#define RSTI_spdiftx_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),12,1}
#define RSTM_spdiftx_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),12,1}
#define RSTI_spdifrx_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),13,1}
#define RSTM_spdifrx_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),13,1}
#define RSTI_tmu_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),14,1}
#define RSTM_tmu_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),14,1}
#define RSTI_bbustieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),15,1}
#define RSTM_bbustieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),15,1}
#define RSTI_adc_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),16,1}
#define RSTM_adc_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),16,1}
#define RSTI_gpio_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),17,1}
#define RSTM_gpio_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),17,1}
#define RSTI_gpio_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),18,1}
#define RSTM_gpio_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),18,1}
#define RSTI_gpio_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),19,1}
#define RSTM_gpio_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),19,1}
#define RSTI_uart_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),20,1}
#define RSTM_uart_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),20,1}
#define RSTI_uart_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),21,1}
#define RSTM_uart_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),21,1}
#define RSTI_uart_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),22,1}
#define RSTM_uart_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),22,1}
#define RSTI_uart_3_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),23,1}
#define RSTM_uart_3_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),23,1}
#define RSTI_uart_4_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),24,1}
#define RSTM_uart_4_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),24,1}
#define RSTI_uart_5_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),25,1}
#define RSTM_uart_5_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),25,1}
#define RSTI_uart_6_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),26,1}
#define RSTM_uart_6_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),26,1}
#define RSTI_uart_7_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),27,1}
#define RSTM_uart_7_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),27,1}
#define RSTI_uart_8_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),28,1}
#define RSTM_uart_8_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),28,1}
#define RSTI_spi_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),29,1}
#define RSTM_spi_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),29,1}
#define RSTI_spi_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),30,1}
#define RSTM_spi_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),30,1}
#define RSTI_spi_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x0),31,1}
#define RSTM_spi_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x0),31,1}
#define RSTI_spi_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x4),0,1}
#define RSTM_spi_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x4),0,1}
#define RSTI_spi_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x4),1,1}
#define RSTM_spi_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x4),1,1}
#define RSTI_spi_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x4),2,1}
#define RSTM_spi_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x4),2,1}
#define RSTI_spdiftx_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)        |0x4),3,1}
#define RSTM_spdiftx_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], ((1<<15)|(1<<11)|0x4),3,1}
#define RSTI_tbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),0,1}
#define RSTM_tbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_tbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),1,1}
#define RSTM_tbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_tbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),2,1}
#define RSTM_tbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_i2s_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),3,1}
#define RSTM_i2s_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_i2s_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),4,1}
#define RSTM_i2s_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_i2s_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),5,1}
#define RSTM_i2s_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_i2s_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),6,1}
#define RSTM_i2s_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_ac97_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),7,1}
#define RSTM_ac97_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_i2c_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),8,1}
#define RSTM_i2c_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_i2c_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),9,1}
#define RSTM_i2c_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_i2s_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),10,1}
#define RSTM_i2s_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_i2s_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),11,1}
#define RSTM_i2s_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),11,1}
#define RSTI_i2s_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),12,1}
#define RSTM_i2s_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),12,1}
#define RSTI_i2s_3_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)        |0x0),13,1}
#define RSTM_i2s_3_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_TBUS[0], ((1<<15)|(1<<11)|0x0),13,1}
#define RSTI_lbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),0,1}
#define RSTM_lbus_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_lbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),1,1}
#define RSTM_lbus_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_gmac_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),2,1}
#define RSTM_gmac_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_mp2ts_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),3,1}
#define RSTM_mp2ts_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_lbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),4,1}
#define RSTM_lbus_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_gmac_0_csr_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),5,1}
#define RSTM_gmac_0_csr_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_lbustieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),6,1}
#define RSTM_lbustieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_gpio_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),7,1}
#define RSTM_gpio_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_gpio_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),8,1}
#define RSTM_gpio_1_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_i2c_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),9,1}
#define RSTM_i2c_2_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_i2c_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),10,1}
#define RSTM_i2c_3_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_i2c_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),11,1}
#define RSTM_i2c_4_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),11,1}
#define RSTI_sdmmc_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),12,1}
#define RSTM_sdmmc_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),12,1}
#define RSTI_sdmmc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),13,1}
#define RSTM_sdmmc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),13,1}
#define RSTI_sdmmc_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),14,1}
#define RSTM_sdmmc_1_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),14,1}
#define RSTI_sdmmc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),15,1}
#define RSTM_sdmmc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),15,1}
#define RSTI_sdmmc_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),16,1}
#define RSTM_sdmmc_2_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),16,1}
#define RSTI_sdmmc_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)        |0x0),17,1}
#define RSTM_sdmmc_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], ((1<<15)|(1<<11)|0x0),17,1}
#define RSTI_usb_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),0,1}
#define RSTM_usb_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_usb30_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),1,1}
#define RSTM_usb30_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_usb_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),2,1}
#define RSTM_usb_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_usb_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),3,1}
#define RSTM_usb_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_usb30_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),4,1}
#define RSTM_usb30_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_otg_sys_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),5,1}
#define RSTM_otg_sys_0_ahb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_otg_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),6,1}
#define RSTM_otg_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_host_sys_0_ehciahb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),7,1}
#define RSTM_host_sys_0_ehciahb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_host_sys_0_ohciahb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),8,1}
#define RSTM_host_sys_0_ohciahb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_host_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),9,1}
#define RSTM_host_sys_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_hsic_refdig_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)        |0x0),10,1}
#define RSTM_hsic_refdig_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_drex0_0_drex_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),0,1}
#define RSTM_drex0_0_drex_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_drex0_0_dll_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),1,1}
#define RSTM_drex0_0_dll_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_drex0_0_mem_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),2,1}
#define RSTM_drex0_0_mem_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_drex0_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),3,1}
#define RSTM_drex0_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_drex0_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),4,1}
#define RSTM_drex0_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_drextieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),5,1}
#define RSTM_drextieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_drex_refr_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)        |0x0),6,1}
#define RSTM_drex_refr_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DREX0[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_disp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),0,1}
#define RSTM_disp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_mipi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),1,1}
#define RSTM_mipi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_csi_to_axi_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),2,1}
#define RSTM_csi_to_axi_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_csi_to_nxs_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),3,1}
#define RSTM_csi_to_nxs_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_csi_to_nxs_1_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),4,1}
#define RSTM_csi_to_nxs_1_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_csi_to_nxs_2_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),5,1}
#define RSTM_csi_to_nxs_2_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_csi_to_nxs_3_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),6,1}
#define RSTM_csi_to_nxs_3_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_mlc_0_bottom0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),7,1}
#define RSTM_mlc_0_bottom0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_mlc_0_bottom1_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),8,1}
#define RSTM_mlc_0_bottom1_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_mlc_0_blender0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),9,1}
#define RSTM_mlc_0_blender0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_mlc_0_blender1_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),10,1}
#define RSTM_mlc_0_blender1_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),10,1}
#define RSTI_mlc_0_blender2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),11,1}
#define RSTM_mlc_0_blender2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),11,1}
#define RSTI_mlc_0_blender3_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),12,1}
#define RSTM_mlc_0_blender3_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),12,1}
#define RSTI_mlc_0_blender4_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),13,1}
#define RSTM_mlc_0_blender4_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),13,1}
#define RSTI_mlc_0_blender5_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),14,1}
#define RSTM_mlc_0_blender5_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),14,1}
#define RSTI_mlc_0_blender6_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),15,1}
#define RSTM_mlc_0_blender6_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),15,1}
#define RSTI_mlc_0_blender7_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),16,1}
#define RSTM_mlc_0_blender7_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),16,1}
#define RSTI_vip_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),17,1}
#define RSTM_vip_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),17,1}
#define RSTI_vip_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),18,1}
#define RSTM_vip_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),18,1}
#define RSTI_vip_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),19,1}
#define RSTM_vip_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),19,1}
#define RSTI_vip_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),20,1}
#define RSTM_vip_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),20,1}
#define RSTI_mcd_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),21,1}
#define RSTM_mcd_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),21,1}
#define RSTI_vip_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),22,1}
#define RSTM_vip_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),22,1}
#define RSTI_vip_pres_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),23,1}
#define RSTM_vip_pres_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),23,1}
#define RSTI_iss_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),24,1}
#define RSTM_iss_cpuif_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),24,1}
#define RSTI_disp2isp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),25,1}
#define RSTM_disp2isp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),25,1}
#define RSTI_isp2disp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),26,1}
#define RSTM_isp2disp_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),26,1}
#define RSTI_isp2disp_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),27,1}
#define RSTM_isp2disp_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),27,1}
#define RSTI_crop_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),28,1}
#define RSTM_crop_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),28,1}
#define RSTI_crop_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),29,1}
#define RSTM_crop_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),29,1}
#define RSTI_csc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),30,1}
#define RSTM_csc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),30,1}
#define RSTI_csc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x0),31,1}
#define RSTM_csc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x0),31,1}
#define RSTI_csc_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),0,1}
#define RSTM_csc_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),0,1}
#define RSTI_csc_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),1,1}
#define RSTM_csc_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),1,1}
#define RSTI_scaler_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),2,1}
#define RSTM_scaler_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),2,1}
#define RSTI_scaler_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),3,1}
#define RSTM_scaler_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),3,1}
#define RSTI_scaler_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),4,1}
#define RSTM_scaler_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),4,1}
#define RSTI_multi_tap_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),5,1}
#define RSTM_multi_tap_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),5,1}
#define RSTI_multi_tap_1_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),6,1}
#define RSTM_multi_tap_1_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),6,1}
#define RSTI_multi_tap_2_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),7,1}
#define RSTM_multi_tap_2_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),7,1}
#define RSTI_multi_tap_3_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),8,1}
#define RSTM_multi_tap_3_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),8,1}
#define RSTI_dmar_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),9,1}
#define RSTM_dmar_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),9,1}
#define RSTI_dmar_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),10,1}
#define RSTM_dmar_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),10,1}
#define RSTI_dmar_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),11,1}
#define RSTM_dmar_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),11,1}
#define RSTI_dmar_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),12,1}
#define RSTM_dmar_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),12,1}
#define RSTI_dmar_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),13,1}
#define RSTM_dmar_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),13,1}
#define RSTI_dmar_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),14,1}
#define RSTM_dmar_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),14,1}
#define RSTI_dmar_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),15,1}
#define RSTM_dmar_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),15,1}
#define RSTI_dmar_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),16,1}
#define RSTM_dmar_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),16,1}
#define RSTI_dmar_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),17,1}
#define RSTM_dmar_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),17,1}
#define RSTI_dmar_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),18,1}
#define RSTM_dmar_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),18,1}
#define RSTI_dmaw_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),19,1}
#define RSTM_dmaw_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),19,1}
#define RSTI_dmaw_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),20,1}
#define RSTM_dmaw_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),20,1}
#define RSTI_dmaw_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),21,1}
#define RSTM_dmaw_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),21,1}
#define RSTI_dmaw_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),22,1}
#define RSTM_dmaw_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),22,1}
#define RSTI_dmaw_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),23,1}
#define RSTM_dmaw_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),23,1}
#define RSTI_dmaw_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),24,1}
#define RSTM_dmaw_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),24,1}
#define RSTI_dmaw_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),25,1}
#define RSTM_dmaw_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),25,1}
#define RSTI_dmaw_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),26,1}
#define RSTM_dmaw_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),26,1}
#define RSTI_dmaw_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),27,1}
#define RSTM_dmaw_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),27,1}
#define RSTI_dmaw_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),28,1}
#define RSTM_dmaw_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),28,1}
#define RSTI_dmaw_10_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),29,1}
#define RSTM_dmaw_10_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),29,1}
#define RSTI_dmaw_11_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),30,1}
#define RSTM_dmaw_11_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),30,1}
#define RSTI_hue_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x4),31,1}
#define RSTM_hue_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x4),31,1}
#define RSTI_hue_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),0,1}
#define RSTM_hue_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),0,1}
#define RSTI_gamma_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),1,1}
#define RSTM_gamma_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),1,1}
#define RSTI_gamma_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),2,1}
#define RSTM_gamma_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),2,1}
#define RSTI_dpc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),3,1}
#define RSTM_dpc_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),3,1}
#define RSTI_dpc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),4,1}
#define RSTM_dpc_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),4,1}
#define RSTI_lvds_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),5,1}
#define RSTM_lvds_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),5,1}
#define RSTI_lvds_0_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),6,1}
#define RSTM_lvds_0_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),6,1}
#define RSTI_lvds_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),7,1}
#define RSTM_lvds_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),7,1}
#define RSTI_lvds_1_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),8,1}
#define RSTM_lvds_1_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),8,1}
#define RSTI_nxs_fifo_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),9,1}
#define RSTM_nxs_fifo_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),9,1}
#define RSTI_nxs_fifo_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),10,1}
#define RSTM_nxs_fifo_1_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),10,1}
#define RSTI_nxs_fifo_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),11,1}
#define RSTM_nxs_fifo_2_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),11,1}
#define RSTI_nxs_fifo_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),12,1}
#define RSTM_nxs_fifo_3_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),12,1}
#define RSTI_nxs_fifo_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),13,1}
#define RSTM_nxs_fifo_4_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),13,1}
#define RSTI_nxs_fifo_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),14,1}
#define RSTM_nxs_fifo_5_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),14,1}
#define RSTI_nxs_fifo_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),15,1}
#define RSTM_nxs_fifo_6_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),15,1}
#define RSTI_nxs_fifo_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),16,1}
#define RSTM_nxs_fifo_7_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),16,1}
#define RSTI_nxs_fifo_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),17,1}
#define RSTM_nxs_fifo_8_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),17,1}
#define RSTI_nxs_fifo_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),18,1}
#define RSTM_nxs_fifo_9_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),18,1}
#define RSTI_nxs_fifo_10_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),19,1}
#define RSTM_nxs_fifo_10_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),19,1}
#define RSTI_nxs_fifo_11_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),20,1}
#define RSTM_nxs_fifo_11_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),20,1}
#define RSTI_nxs2hdmi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),21,1}
#define RSTM_nxs2hdmi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),21,1}
#define RSTI_tpgen_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),22,1}
#define RSTM_tpgen_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),22,1}
#define RSTI_disp_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),23,1}
#define RSTM_disp_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),23,1}
#define RSTI_deinterlace_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),24,1}
#define RSTM_deinterlace_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),24,1}
#define RSTI_disp_tieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),25,1}
#define RSTM_disp_tieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),25,1}
#define RSTI_disp_tzpc_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),26,1}
#define RSTM_disp_tzpc_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),26,1}
#define RSTI_disp_tzpc_1_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),27,1}
#define RSTM_disp_tzpc_1_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),27,1}
#define RSTI_mipi_0_apbcsi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),28,1}
#define RSTM_mipi_0_apbcsi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),28,1}
#define RSTI_mipi_0_apbdsi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),29,1}
#define RSTM_mipi_0_apbdsi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),29,1}
#define RSTI_mipi_0_csiphy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),30,1}
#define RSTM_mipi_0_csiphy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),30,1}
#define RSTI_dpc_0_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0x8),31,1}
#define RSTM_dpc_0_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0x8),31,1}
#define RSTI_dpc_1_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),0,1}
#define RSTM_dpc_1_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),0,1}
#define RSTI_mipi_0_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),1,1}
#define RSTM_mipi_0_x2_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),1,1}
#define RSTI_lvds_0_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),2,1}
#define RSTM_lvds_0_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),2,1}
#define RSTI_lvds_1_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),3,1}
#define RSTM_lvds_1_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),3,1}
#define RSTI_deinterlace_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),4,1}
#define RSTM_deinterlace_0_axi_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),4,1}
#define RSTI_mapconv_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),5,1}
#define RSTM_mapconv_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),5,1}
#define RSTI_mcd_0_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)        |0xc),6,1}
#define RSTM_mcd_0_vclk_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_DISP[0], ((1<<15)|(1<<11)|0xc),6,1}
#define RSTI_hdmi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),0,1}
#define RSTM_hdmi_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_hdmiv2_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),1,1}
#define RSTM_hdmiv2_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_hdmiv2_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),2,1}
#define RSTM_hdmiv2_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_hdmiv2_0_apbphy_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),3,1}
#define RSTM_hdmiv2_0_apbphy_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_hdmiv2_0_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),4,1}
#define RSTM_hdmiv2_0_phy_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_hdmiv2_0_tmds_10b_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),5,1}
#define RSTM_hdmiv2_0_tmds_10b_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_hdmiv2_0_tmds_20b_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),6,1}
#define RSTM_hdmiv2_0_tmds_20b_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_hdmiv2_0_pixelx2_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),7,1}
#define RSTM_hdmiv2_0_pixelx2_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_hdmiv2_0_pixel_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),8,1}
#define RSTM_hdmiv2_0_pixel_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),8,1}
#define RSTI_hdmiv2_0_audio_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)        |0x0),9,1}
#define RSTM_hdmiv2_0_audio_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_HDMI[0], ((1<<15)|(1<<11)|0x0),9,1}
#define RSTI_cputieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_CPU[0], ((1<<15)        |0x0),0,1}
#define RSTM_cputieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_CPU[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_coda980_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),0,1}
#define RSTM_coda980_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_jpeg_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),1,1}
#define RSTM_jpeg_0_axi_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_coda980_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),2,1}
#define RSTM_coda980_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_jpeg_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),3,1}
#define RSTM_jpeg_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_codatieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),4,1}
#define RSTM_codatieoff_0_apb_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_coda980_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),5,1}
#define RSTM_coda980_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),5,1}
#define RSTI_coda980_0_sram_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),6,1}
#define RSTM_coda980_0_sram_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),6,1}
#define RSTI_jpeg_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)        |0x0),7,1}
#define RSTM_jpeg_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_CODA[0], ((1<<15)|(1<<11)|0x0),7,1}
#define RSTI_wave_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)        |0x0),0,1}
#define RSTM_wave_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_wave_v_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)        |0x0),1,1}
#define RSTM_wave_v_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_wave_m_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)        |0x0),2,1}
#define RSTM_wave_m_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_wave_c_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)        |0x0),3,1}
#define RSTM_wave_c_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_wave_b_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)        |0x0),4,1}
#define RSTM_wave_b_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_wave420_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)        |0x0),0,1}
#define RSTM_wave420_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_wave420_v_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)        |0x0),1,1}
#define RSTM_wave420_v_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_wave420_m_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)        |0x0),2,1}
#define RSTM_wave420_m_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|(1<<11)|0x0),2,1}
#define RSTI_wave420_c_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)        |0x0),3,1}
#define RSTM_wave420_c_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|(1<<11)|0x0),3,1}
#define RSTI_wave420_b_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)        |0x0),4,1}
#define RSTM_wave420_b_0_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_WAVE420[0], ((1<<15)|(1<<11)|0x0),4,1}
#define RSTI_periclk_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)        |0x0),0,1}
#define RSTM_periclk_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|(1<<11)|0x0),0,1}
#define RSTI_ppm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)        |0x0),1,1}
#define RSTM_ppm_0_apb_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|(1<<11)|0x0),1,1}
#define RSTI_mcu_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)        |0x0),2,1}
#define RSTM_mcu_0_core_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_PERICLK[0], ((1<<15)|(1<<11)|0x0),2,1}

#endif // #ifndef _NX_RESET_INFO_DEF_REPORT_
#endif // #ifndef __NX_RESETCONTROL_DEF_H__


