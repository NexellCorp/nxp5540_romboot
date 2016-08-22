
#ifndef _NX_CLOCKCONTROL_DEF_H_
#define _NX_CLOCKCONTROL_DEF_H_

//======================================================================================================

//================================================
// define structure instance
//================================================
// clk on  : nx_cpuif_reg_write_one( CMUI_SYS_0_AXI_clk_enb, 1 );
// clk off : nx_cpuif_reg_write_one( CMUI_SYS_0_AXI_clk_enb, 1 );
//
// src  change : nx_cpuif_reg_write_one( CMUI_SYS_0_AXI_grp_clk_src , 3 );
// div change : 
//
// 	nx_cpuif_reg_write_one( CMUI_SYS_0_AXI_dy_div_val , 2 );
// 	while( 1 == nx_cpuif_reg_read_one( CMUI_SYS_0_AXI_dy_div_busy_st ) );
// 
//================================================
/* SYS */
  /* SYS[0] */
/* AXI  */
struct cmuc {
	unsigned int group_clock_source;		/* 0x000 */
	unsigned int group_all_divider_reset;		/* 0x004 */
	unsigned int group_gate_mode;			/* 0x008 */
	unsigned int clock_enable;			/* 0x00c */
	unsigned int __reserved0[0xD];			/* 0x010 - 0x040 */
	unsigned int divider_reset;			/* 0x044 */
	unsigned int dynamic_divider_value;		/* 0x048 */
	unsigned int dynamic_divider_stop;		/* 0x04c */
	unsigned int dynamic_divider_busy_status;	/* 0x050 */
	unsigned int __reserved1[0xB];			/* 0x054 - 0x7c */
};
//struct cmuc cmucarray[4];
#define CMUI_SYS_0_AXI_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x200, 0, 32}
#define CMUI_SYS_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x204, 0, 32}
#define CMUI_SYS_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x208, 0, 32}
#define CMUI_SYS_0_AXI_div_rst			{&SFR_INFO.CMU_SYS[0], 0x244, 0, 32}
#define CMUI_SYS_0_AXI_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x248, 0, 32}
#define CMUI_SYS_0_AXI_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x24c, 0, 32}
#define CMUI_SYS_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x250, 0, 32}
#define CMUI_SYS_0_AXI_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 0, 1}
/* AHB  */
#define CMUI_SYS_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_SYS_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_SYS_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_SYS_0_AHB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x284, 0, 32}
#define CMUI_SYS_0_AHB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x288, 0, 32}
#define CMUI_SYS_0_AHB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x28c, 0, 32}
#define CMUI_SYS_0_AHB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x290, 0, 32}
#define CMUI_SYS_0_AHB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 4, 1}
/* APB  */
#define CMUI_SYS_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SYS_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_SYS_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_SYS_0_APB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x2c4, 0, 32}
#define CMUI_SYS_0_APB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2c8, 0, 32}
#define CMUI_SYS_0_APB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x2cc, 0, 32}
#define CMUI_SYS_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x2d0, 0, 32}
#define CMUI_SYS_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 5, 1}
/* OSCCLK  */
#define CMUI_SYS_0_OSCCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x400, 0, 32}
#define CMUI_SYS_0_OSCCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x404, 0, 32}
#define CMUI_SYS_0_OSCCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x408, 0, 32}
#define CMUI_SYS_0_OSCCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x444, 0, 32}
#define CMUI_SYS_0_OSCCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x448, 0, 32}
#define CMUI_SYS_0_OSCCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x44c, 0, 32}
#define CMUI_SYS_0_OSCCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x450, 0, 32}
#define CMUI_SYS_0_OSCCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 0, 1}
/* BBUS */
/* BBUS[0] */
/* AXI  */
#define CMUI_BBUS_0_AXI_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x200, 0, 32}
#define CMUI_BBUS_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x204, 0, 32}
#define CMUI_BBUS_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x208, 0, 32}
#define CMUI_BBUS_0_AXI_div_rst			{&SFR_INFO.CMU_BBUS[0], 0x244, 0, 32}
#define CMUI_BBUS_0_AXI_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x248, 0, 32}
#define CMUI_BBUS_0_AXI_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x24c, 0, 32}
#define CMUI_BBUS_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x250, 0, 32}
#define CMUI_BBUS_0_AXI_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 0, 1}
/* AHB  */
#define CMUI_BBUS_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_BBUS_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_BBUS_0_AHB_div_rst			{&SFR_INFO.CMU_BBUS[0], 0x284, 0, 32}
#define CMUI_BBUS_0_AHB_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x288, 0, 32}
#define CMUI_BBUS_0_AHB_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x28c, 0, 32}
#define CMUI_BBUS_0_AHB_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x290, 0, 32}
#define CMUI_BBUS_0_AHB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_BBUS_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_BBUS_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_BBUS_0_APB_div_rst			{&SFR_INFO.CMU_BBUS[0], 0x2c4, 0, 32}
#define CMUI_BBUS_0_APB_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x2c8, 0, 32}
#define CMUI_BBUS_0_APB_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x2cc, 0, 32}
#define CMUI_BBUS_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x2d0, 0, 32}
#define CMUI_BBUS_0_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 2, 1}
/* TBUS */
/* TBUS[0] */
/* AXI  */
#define CMUI_TBUS_0_AXI_grp_clk_src		{&SFR_INFO.CMU_TBUS[0], 0x200, 0, 32}
#define CMUI_TBUS_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_TBUS[0], 0x204, 0, 32}
#define CMUI_TBUS_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_TBUS[0], 0x208, 0, 32}
#define CMUI_TBUS_0_AXI_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x244, 0, 32}
#define CMUI_TBUS_0_AXI_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x248, 0, 32}
#define CMUI_TBUS_0_AXI_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x24c, 0, 32}
#define CMUI_TBUS_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x250, 0, 32}
#define CMUI_TBUS_0_AXI_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 0, 1}
/* AHB  */
#define CMUI_TBUS_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TBUS_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_TBUS_0_AHB_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x284, 0, 32}
#define CMUI_TBUS_0_AHB_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x288, 0, 32}
#define CMUI_TBUS_0_AHB_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x28c, 0, 32}
#define CMUI_TBUS_0_AHB_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x290, 0, 32}
#define CMUI_TBUS_0_AHB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_TBUS_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TBUS_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TBUS_0_APB_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x2c4, 0, 32}
#define CMUI_TBUS_0_APB_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x2c8, 0, 32}
#define CMUI_TBUS_0_APB_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x2cc, 0, 32}
#define CMUI_TBUS_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x2d0, 0, 32}
#define CMUI_TBUS_0_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 2, 1}
/* LBUS */
/* LBUS[0] */
/* AXI  */
#define CMUI_LBUS_0_AXI_grp_clk_src		{&SFR_INFO.CMU_LBUS[0], 0x200, 0, 32}
#define CMUI_LBUS_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_LBUS[0], 0x204, 0, 32}
#define CMUI_LBUS_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_LBUS[0], 0x208, 0, 32}
#define CMUI_LBUS_0_AXI_div_rst			{&SFR_INFO.CMU_LBUS[0], 0x244, 0, 32}
#define CMUI_LBUS_0_AXI_dy_div_val		{&SFR_INFO.CMU_LBUS[0], 0x248, 0, 32}
#define CMUI_LBUS_0_AXI_dy_div_stop		{&SFR_INFO.CMU_LBUS[0], 0x24c, 0, 32}
#define CMUI_LBUS_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_LBUS[0], 0x250, 0, 32}
#define CMUI_LBUS_0_AXI_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 0, 1}
/* AHB  */
#define CMUI_LBUS_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_LBUS_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_LBUS_0_AHB_div_rst			{&SFR_INFO.CMU_LBUS[0], 0x284, 0, 32}
#define CMUI_LBUS_0_AHB_dy_div_val		{&SFR_INFO.CMU_LBUS[0], 0x288, 0, 32}
#define CMUI_LBUS_0_AHB_dy_div_stop		{&SFR_INFO.CMU_LBUS[0], 0x28c, 0, 32}
#define CMUI_LBUS_0_AHB_dy_div_busy_st		{&SFR_INFO.CMU_LBUS[0], 0x290, 0, 32}
#define CMUI_LBUS_0_AHB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_LBUS_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_LBUS_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_LBUS_0_APB_div_rst			{&SFR_INFO.CMU_LBUS[0], 0x2c4, 0, 32}
#define CMUI_LBUS_0_APB_dy_div_val		{&SFR_INFO.CMU_LBUS[0], 0x2c8, 0, 32}
#define CMUI_LBUS_0_APB_dy_div_stop		{&SFR_INFO.CMU_LBUS[0], 0x2cc, 0, 32}
#define CMUI_LBUS_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_LBUS[0], 0x2d0, 0, 32}
#define CMUI_LBUS_0_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 4, 1}
/* USB */
/* USB[0] */
/* AXI  */
#define CMUI_USB_0_AXI_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x200, 0, 32}
#define CMUI_USB_0_AXI_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x204, 0, 32}
#define CMUI_USB_0_AXI_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x208, 0, 32}
#define CMUI_USB_0_AXI_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x244, 0, 32}
#define CMUI_USB_0_AXI_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x248, 0, 32}
#define CMUI_USB_0_AXI_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x24c, 0, 32}
#define CMUI_USB_0_AXI_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x250, 0, 32}
#define CMUI_USB_0_AXI_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x20c, 0, 1}
/* AHB  */
#define CMUI_USB_0_AHB_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_AHB_grp_a_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_AHB_grp_gate_mode		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_AHB_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x284, 0, 32}
#define CMUI_USB_0_AHB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x288, 0, 32}
#define CMUI_USB_0_AHB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x28c, 0, 32}
#define CMUI_USB_0_AHB_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x290, 0, 32}
#define CMUI_USB_0_AHB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x20c, 2, 1}
/* APB  */
#define CMUI_USB_0_APB_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_APB_grp_a_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_APB_grp_gate_mode		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_0_APB_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x2c4, 0, 32}
#define CMUI_USB_0_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x2c8, 0, 32}
#define CMUI_USB_0_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x2cc, 0, 32}
#define CMUI_USB_0_APB_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x2d0, 0, 32}
#define CMUI_USB_0_APB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x20c, 3, 1}
/* ISP */
/* ISP[0] */
/* AXI  */
#define CMUI_ISP_0_AXI_grp_clk_src		{&SFR_INFO.CMU_ISP[0], 0x200, 0, 32}
#define CMUI_ISP_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_ISP[0], 0x204, 0, 32}
#define CMUI_ISP_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_ISP[0], 0x208, 0, 32}
#define CMUI_ISP_0_AXI_div_rst			{&SFR_INFO.CMU_ISP[0], 0x244, 0, 32}
#define CMUI_ISP_0_AXI_dy_div_val		{&SFR_INFO.CMU_ISP[0], 0x248, 0, 32}
#define CMUI_ISP_0_AXI_dy_div_stop		{&SFR_INFO.CMU_ISP[0], 0x24c, 0, 32}
#define CMUI_ISP_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_ISP[0], 0x250, 0, 32}
#define CMUI_ISP_0_AXI_clk_enb			{&SFR_INFO.CMU_ISP[0], 0x20c, 0, 1}
/* DIV4  */
#define CMUI_ISP_0_DIV4_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_0_DIV4_grp_a_div_rst		{0,0,0,0}
#define CMUI_ISP_0_DIV4_grp_gate_mode		{0,0,0,0}
#define CMUI_ISP_0_DIV4_div_rst			{&SFR_INFO.CMU_ISP[0], 0x284, 0, 32}
#define CMUI_ISP_0_DIV4_dy_div_val		{&SFR_INFO.CMU_ISP[0], 0x288, 0, 32}
#define CMUI_ISP_0_DIV4_dy_div_stop		{&SFR_INFO.CMU_ISP[0], 0x28c, 0, 32}
#define CMUI_ISP_0_DIV4_dy_div_busy_st		{&SFR_INFO.CMU_ISP[0], 0x290, 0, 32}
#define CMUI_ISP_0_DIV4_clk_enb			{&SFR_INFO.CMU_ISP[0], 0x20c, 1, 1}
/* GPU */
/* GPU[0] */
/* AXI  */
#define CMUI_GPU_0_AXI_grp_clk_src		{&SFR_INFO.CMU_GPU[0], 0x200, 0, 32}
#define CMUI_GPU_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_GPU[0], 0x204, 0, 32}
#define CMUI_GPU_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_GPU[0], 0x208, 0, 32}
#define CMUI_GPU_0_AXI_div_rst			{&SFR_INFO.CMU_GPU[0], 0x244, 0, 32}
#define CMUI_GPU_0_AXI_dy_div_val		{&SFR_INFO.CMU_GPU[0], 0x248, 0, 32}
#define CMUI_GPU_0_AXI_dy_div_stop		{&SFR_INFO.CMU_GPU[0], 0x24c, 0, 32}
#define CMUI_GPU_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_GPU[0], 0x250, 0, 32}
#define CMUI_GPU_0_AXI_clk_enb			{&SFR_INFO.CMU_GPU[0], 0x20c, 0, 1}
/* DREX0 */
/* DREX0[0] */
/* DREX  */
#define CMUI_DREX0_0_DREX_grp_clk_src		{&SFR_INFO.CMU_DREX0[0], 0x200, 0, 32}
#define CMUI_DREX0_0_DREX_grp_a_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x204, 0, 32}
#define CMUI_DREX0_0_DREX_grp_gate_mode		{&SFR_INFO.CMU_DREX0[0], 0x208, 0, 32}
#define CMUI_DREX0_0_DREX_div_rst		{0,0,0,0}
#define CMUI_DREX0_0_DREX_dy_div_val		{0,0,0,0}
#define CMUI_DREX0_0_DREX_dy_div_stop		{0,0,0,0}
#define CMUI_DREX0_0_DREX_dy_div_busy_st	{0,0,0,0}
#define CMUI_DREX0_0_DREX_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 0, 1}
/* DLL  */
#define CMUI_DREX0_0_DLL_grp_clk_src		{0,0,0,0}
#define CMUI_DREX0_0_DLL_grp_a_div_rst		{0,0,0,0}
#define CMUI_DREX0_0_DLL_grp_gate_mode		{0,0,0,0}
#define CMUI_DREX0_0_DLL_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x244, 0, 32}
#define CMUI_DREX0_0_DLL_dy_div_val		{&SFR_INFO.CMU_DREX0[0], 0x248, 0, 32}
#define CMUI_DREX0_0_DLL_dy_div_stop		{&SFR_INFO.CMU_DREX0[0], 0x24c, 0, 32}
#define CMUI_DREX0_0_DLL_dy_div_busy_st		{&SFR_INFO.CMU_DREX0[0], 0x250, 0, 32}
#define CMUI_DREX0_0_DLL_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 1, 1}
/* MEM  */
#define CMUI_DREX0_0_MEM_grp_clk_src		{0,0,0,0}
#define CMUI_DREX0_0_MEM_grp_a_div_rst		{0,0,0,0}
#define CMUI_DREX0_0_MEM_grp_gate_mode		{0,0,0,0}
#define CMUI_DREX0_0_MEM_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x284, 0, 32}
#define CMUI_DREX0_0_MEM_dy_div_val		{&SFR_INFO.CMU_DREX0[0], 0x288, 0, 32}
#define CMUI_DREX0_0_MEM_dy_div_stop		{&SFR_INFO.CMU_DREX0[0], 0x28c, 0, 32}
#define CMUI_DREX0_0_MEM_dy_div_busy_st		{&SFR_INFO.CMU_DREX0[0], 0x290, 0, 32}
#define CMUI_DREX0_0_MEM_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 2, 1}
/* AXI  */
#define CMUI_DREX0_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DREX0_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DREX0_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DREX0_0_AXI_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x2c4, 0, 32}
#define CMUI_DREX0_0_AXI_dy_div_val		{&SFR_INFO.CMU_DREX0[0], 0x2c8, 0, 32}
#define CMUI_DREX0_0_AXI_dy_div_stop		{&SFR_INFO.CMU_DREX0[0], 0x2cc, 0, 32}
#define CMUI_DREX0_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_DREX0[0], 0x2d0, 0, 32}
#define CMUI_DREX0_0_AXI_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 3, 1}
/* APB  */
#define CMUI_DREX0_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_DREX0_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_DREX0_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_DREX0_0_APB_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x304, 0, 32}
#define CMUI_DREX0_0_APB_dy_div_val		{&SFR_INFO.CMU_DREX0[0], 0x308, 0, 32}
#define CMUI_DREX0_0_APB_dy_div_stop		{&SFR_INFO.CMU_DREX0[0], 0x30c, 0, 32}
#define CMUI_DREX0_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_DREX0[0], 0x310, 0, 32}
#define CMUI_DREX0_0_APB_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 4, 1}
/* DISP */
/* DISP[0] */
/* AXI  */
#define CMUI_DISP_0_AXI_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x200, 0, 32}
#define CMUI_DISP_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x204, 0, 32}
#define CMUI_DISP_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x208, 0, 32}
#define CMUI_DISP_0_AXI_div_rst			{&SFR_INFO.CMU_DISP[0], 0x244, 0, 32}
#define CMUI_DISP_0_AXI_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x248, 0, 32}
#define CMUI_DISP_0_AXI_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x24c, 0, 32}
#define CMUI_DISP_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x250, 0, 32}
#define CMUI_DISP_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 0, 1}
/* APB  */
#define CMUI_DISP_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_DISP_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_DISP_0_APB_div_rst			{&SFR_INFO.CMU_DISP[0], 0x284, 0, 32}
#define CMUI_DISP_0_APB_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x288, 0, 32}
#define CMUI_DISP_0_APB_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x28c, 0, 32}
#define CMUI_DISP_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x290, 0, 32}
#define CMUI_DISP_0_APB_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 23, 1}
/* HDMI */
/* HDMI[0] */
/* AXI  */
#define CMUI_HDMI_0_AXI_grp_clk_src		{&SFR_INFO.CMU_HDMI[0], 0x200, 0, 32}
#define CMUI_HDMI_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x204, 0, 32}
#define CMUI_HDMI_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_HDMI[0], 0x208, 0, 32}
#define CMUI_HDMI_0_AXI_div_rst			{&SFR_INFO.CMU_HDMI[0], 0x244, 0, 32}
#define CMUI_HDMI_0_AXI_dy_div_val		{&SFR_INFO.CMU_HDMI[0], 0x248, 0, 32}
#define CMUI_HDMI_0_AXI_dy_div_stop		{&SFR_INFO.CMU_HDMI[0], 0x24c, 0, 32}
#define CMUI_HDMI_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_HDMI[0], 0x250, 0, 32}
#define CMUI_HDMI_0_AXI_clk_enb			{&SFR_INFO.CMU_HDMI[0], 0x20c, 0, 1}
/* APB  */
#define CMUI_HDMI_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_HDMI_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_HDMI_0_APB_div_rst			{&SFR_INFO.CMU_HDMI[0], 0x284, 0, 32}
#define CMUI_HDMI_0_APB_dy_div_val		{&SFR_INFO.CMU_HDMI[0], 0x288, 0, 32}
#define CMUI_HDMI_0_APB_dy_div_stop		{&SFR_INFO.CMU_HDMI[0], 0x28c, 0, 32}
#define CMUI_HDMI_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_HDMI[0], 0x290, 0, 32}
#define CMUI_HDMI_0_APB_clk_enb			{&SFR_INFO.CMU_HDMI[0], 0x20c, 2, 1}
/* CPU */
/* CPU[0] */
/* ARM  */
#define CMUI_CPU_0_ARM_grp_clk_src		{&SFR_INFO.CMU_CPU[0], 0x200, 0, 32}
#define CMUI_CPU_0_ARM_grp_a_div_rst		{&SFR_INFO.CMU_CPU[0], 0x204, 0, 32}
#define CMUI_CPU_0_ARM_grp_gate_mode		{&SFR_INFO.CMU_CPU[0], 0x208, 0, 32}
#define CMUI_CPU_0_ARM_div_rst			{&SFR_INFO.CMU_CPU[0], 0x244, 0, 32}
#define CMUI_CPU_0_ARM_dy_div_val		{&SFR_INFO.CMU_CPU[0], 0x248, 0, 32}
#define CMUI_CPU_0_ARM_dy_div_stop		{&SFR_INFO.CMU_CPU[0], 0x24c, 0, 32}
#define CMUI_CPU_0_ARM_dy_div_busy_st		{&SFR_INFO.CMU_CPU[0], 0x250, 0, 32}
#define CMUI_CPU_0_ARM_clk_enb			{&SFR_INFO.CMU_CPU[0], 0x20c, 0, 1}
/* ACLK_COREM0  */
#define CMUI_CPU_0_ACLK_COREM0_grp_clk_src	{0,0,0,0}
#define CMUI_CPU_0_ACLK_COREM0_grp_a_div_rst	{0,0,0,0}
#define CMUI_CPU_0_ACLK_COREM0_grp_gate_mode	{0,0,0,0}
#define CMUI_CPU_0_ACLK_COREM0_div_rst		{&SFR_INFO.CMU_CPU[0], 0x284, 0, 32}
#define CMUI_CPU_0_ACLK_COREM0_dy_div_val	{&SFR_INFO.CMU_CPU[0], 0x288, 0, 32}
#define CMUI_CPU_0_ACLK_COREM0_dy_div_stop	{&SFR_INFO.CMU_CPU[0], 0x28c, 0, 32}
#define CMUI_CPU_0_ACLK_COREM0_dy_div_busy_st	{&SFR_INFO.CMU_CPU[0], 0x290, 0, 32}
#define CMUI_CPU_0_ACLK_COREM0_clk_enb		{&SFR_INFO.CMU_CPU[0], 0x20c, 1, 1}
/* ATCLK  */
#define CMUI_CPU_0_ATCLK_grp_clk_src		{0,0,0,0}
#define CMUI_CPU_0_ATCLK_grp_a_div_rst		{0,0,0,0}
#define CMUI_CPU_0_ATCLK_grp_gate_mode		{0,0,0,0}
#define CMUI_CPU_0_ATCLK_div_rst		{&SFR_INFO.CMU_CPU[0], 0x2c4, 0, 32}
#define CMUI_CPU_0_ATCLK_dy_div_val		{&SFR_INFO.CMU_CPU[0], 0x2c8, 0, 32}
#define CMUI_CPU_0_ATCLK_dy_div_stop		{&SFR_INFO.CMU_CPU[0], 0x2cc, 0, 32}
#define CMUI_CPU_0_ATCLK_dy_div_busy_st		{&SFR_INFO.CMU_CPU[0], 0x2d0, 0, 32}
#define CMUI_CPU_0_ATCLK_clk_enb		{&SFR_INFO.CMU_CPU[0], 0x20c, 2, 1}
/* CNTCLK  */
#define CMUI_CPU_0_CNTCLK_grp_clk_src		{0,0,0,0}
#define CMUI_CPU_0_CNTCLK_grp_a_div_rst		{0,0,0,0}
#define CMUI_CPU_0_CNTCLK_grp_gate_mode		{0,0,0,0}
#define CMUI_CPU_0_CNTCLK_div_rst		{&SFR_INFO.CMU_CPU[0], 0x304, 0, 32}
#define CMUI_CPU_0_CNTCLK_dy_div_val		{&SFR_INFO.CMU_CPU[0], 0x308, 0, 32}
#define CMUI_CPU_0_CNTCLK_dy_div_stop		{&SFR_INFO.CMU_CPU[0], 0x30c, 0, 32}
#define CMUI_CPU_0_CNTCLK_dy_div_busy_st	{&SFR_INFO.CMU_CPU[0], 0x310, 0, 32}
#define CMUI_CPU_0_CNTCLK_clk_enb		{&SFR_INFO.CMU_CPU[0], 0x20c, 3, 1}
/* PCLK_DBG  */
#define CMUI_CPU_0_PCLK_DBG_grp_clk_src		{0,0,0,0}
#define CMUI_CPU_0_PCLK_DBG_grp_a_div_rst	{0,0,0,0}
#define CMUI_CPU_0_PCLK_DBG_grp_gate_mode	{0,0,0,0}
#define CMUI_CPU_0_PCLK_DBG_div_rst		{&SFR_INFO.CMU_CPU[0], 0x344, 0, 32}
#define CMUI_CPU_0_PCLK_DBG_dy_div_val		{&SFR_INFO.CMU_CPU[0], 0x348, 0, 32}
#define CMUI_CPU_0_PCLK_DBG_dy_div_stop		{&SFR_INFO.CMU_CPU[0], 0x34c, 0, 32}
#define CMUI_CPU_0_PCLK_DBG_dy_div_busy_st	{&SFR_INFO.CMU_CPU[0], 0x350, 0, 32}
#define CMUI_CPU_0_PCLK_DBG_clk_enb		{&SFR_INFO.CMU_CPU[0], 0x20c, 4, 1}
/* CODA */
/* CODA[0] */
/* AXI  */
#define CMUI_CODA_0_AXI_grp_clk_src		{&SFR_INFO.CMU_CODA[0], 0x200, 0, 32}
#define CMUI_CODA_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_CODA[0], 0x204, 0, 32}
#define CMUI_CODA_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_CODA[0], 0x208, 0, 32}
#define CMUI_CODA_0_AXI_div_rst			{&SFR_INFO.CMU_CODA[0], 0x244, 0, 32}
#define CMUI_CODA_0_AXI_dy_div_val		{&SFR_INFO.CMU_CODA[0], 0x248, 0, 32}
#define CMUI_CODA_0_AXI_dy_div_stop		{&SFR_INFO.CMU_CODA[0], 0x24c, 0, 32}
#define CMUI_CODA_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_CODA[0], 0x250, 0, 32}
#define CMUI_CODA_0_AXI_clk_enb			{&SFR_INFO.CMU_CODA[0], 0x20c, 0, 1}
/* APB  */
#define CMUI_CODA_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_CODA_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_CODA_0_APB_div_rst			{&SFR_INFO.CMU_CODA[0], 0x284, 0, 32}
#define CMUI_CODA_0_APB_dy_div_val		{&SFR_INFO.CMU_CODA[0], 0x288, 0, 32}
#define CMUI_CODA_0_APB_dy_div_stop		{&SFR_INFO.CMU_CODA[0], 0x28c, 0, 32}
#define CMUI_CODA_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_CODA[0], 0x290, 0, 32}
#define CMUI_CODA_0_APB_clk_enb			{&SFR_INFO.CMU_CODA[0], 0x20c, 3, 1}
/* WAVE */
/* WAVE[0] */
/* AXI  */
#define CMUI_WAVE_0_AXI_grp_clk_src		{&SFR_INFO.CMU_WAVE[0], 0x200, 0, 32}
#define CMUI_WAVE_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x204, 0, 32}
#define CMUI_WAVE_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_WAVE[0], 0x208, 0, 32}
#define CMUI_WAVE_0_AXI_div_rst			{&SFR_INFO.CMU_WAVE[0], 0x244, 0, 32}
#define CMUI_WAVE_0_AXI_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0x248, 0, 32}
#define CMUI_WAVE_0_AXI_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0x24c, 0, 32}
#define CMUI_WAVE_0_AXI_dy_div_busy_st		{&SFR_INFO.CMU_WAVE[0], 0x250, 0, 32}
#define CMUI_WAVE_0_AXI_clk_enb			{&SFR_INFO.CMU_WAVE[0], 0x20c, 0, 1}
/* APB  */
#define CMUI_WAVE_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_WAVE_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_WAVE_0_APB_div_rst			{&SFR_INFO.CMU_WAVE[0], 0x284, 0, 32}
#define CMUI_WAVE_0_APB_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0x288, 0, 32}
#define CMUI_WAVE_0_APB_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0x28c, 0, 32}
#define CMUI_WAVE_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_WAVE[0], 0x290, 0, 32}
#define CMUI_WAVE_0_APB_clk_enb			{&SFR_INFO.CMU_WAVE[0], 0x20c, 1, 1}
/* WAVE420 */
/* WAVE420[0] */
/* AXI  */
#define CMUI_WAVE420_0_AXI_grp_clk_src		{&SFR_INFO.CMU_WAVE420[0], 0x200, 0, 32}
#define CMUI_WAVE420_0_AXI_grp_a_div_rst	{&SFR_INFO.CMU_WAVE420[0], 0x204, 0, 32}
#define CMUI_WAVE420_0_AXI_grp_gate_mode	{&SFR_INFO.CMU_WAVE420[0], 0x208, 0, 32}
#define CMUI_WAVE420_0_AXI_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0x244, 0, 32}
#define CMUI_WAVE420_0_AXI_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0x248, 0, 32}
#define CMUI_WAVE420_0_AXI_dy_div_stop		{&SFR_INFO.CMU_WAVE420[0], 0x24c, 0, 32}
#define CMUI_WAVE420_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0x250, 0, 32}
#define CMUI_WAVE420_0_AXI_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0x20c, 0, 1}
/* APB  */
#define CMUI_WAVE420_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE420_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_0_APB_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0x284, 0, 32}
#define CMUI_WAVE420_0_APB_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0x288, 0, 32}
#define CMUI_WAVE420_0_APB_dy_div_stop		{&SFR_INFO.CMU_WAVE420[0], 0x28c, 0, 32}
#define CMUI_WAVE420_0_APB_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0x290, 0, 32}
#define CMUI_WAVE420_0_APB_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0x20c, 1, 1}
/* PERICLK */
/* PERICLK[0] */
/* APB  */
#define CMUI_PERICLK_0_APB_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x200, 0, 32}
#define CMUI_PERICLK_0_APB_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x204, 0, 32}
#define CMUI_PERICLK_0_APB_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x208, 0, 32}
#define CMUI_PERICLK_0_APB_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x244, 0, 32}
#define CMUI_PERICLK_0_APB_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x248, 0, 32}
#define CMUI_PERICLK_0_APB_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x24c, 0, 32}
#define CMUI_PERICLK_0_APB_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x250, 0, 32}
#define CMUI_PERICLK_0_APB_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x20c, 0, 1}
/* PLL */
/* PLL[0] */
/* CLK  */
#define CMUI_PLL_0_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x600, 0, 32}
#define CMUI_PLL_0_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x604, 0, 32}
#define CMUI_PLL_0_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x608, 0, 32}
#define CMUI_PLL_0_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_0_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_0_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x60c, 0, 1}
/* DIV  */
#define CMUI_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_0_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_0_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_0_DIV_div_rst			{&SFR_INFO.CMU_SYS[0], 0x644, 0, 32}
#define CMUI_PLL_0_DIV_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x648, 0, 32}
#define CMUI_PLL_0_DIV_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x64c, 0, 32}
#define CMUI_PLL_0_DIV_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x650, 0, 32}
#define CMUI_PLL_0_DIV_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x60c, 1, 1}
/* PLL[1] */
/* CLK  */
#define CMUI_PLL_1_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x800, 0, 32}
#define CMUI_PLL_1_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x804, 0, 32}
#define CMUI_PLL_1_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x808, 0, 32}
#define CMUI_PLL_1_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_1_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_1_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x80c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_1_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_1_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_1_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_1_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_1_DIV_clk_enb			{0,0,0,0}
/* PLL[2] */
/* CLK  */
#define CMUI_PLL_2_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0xa00, 0, 32}
#define CMUI_PLL_2_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0xa04, 0, 32}
#define CMUI_PLL_2_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0xa08, 0, 32}
#define CMUI_PLL_2_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_2_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_2_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0xa0c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_2_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_2_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_2_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_2_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_2_DIV_clk_enb			{0,0,0,0}
/* PLL[3] */
/* CLK  */
#define CMUI_PLL_3_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0xc00, 0, 32}
#define CMUI_PLL_3_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0xc04, 0, 32}
#define CMUI_PLL_3_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0xc08, 0, 32}
#define CMUI_PLL_3_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_3_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_3_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0xc0c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_3_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_3_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_3_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_3_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_3_DIV_clk_enb			{0,0,0,0}
/* PLL[4] */
/* CLK  */
#define CMUI_PLL_4_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0xe00, 0, 32}
#define CMUI_PLL_4_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0xe04, 0, 32}
#define CMUI_PLL_4_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0xe08, 0, 32}
#define CMUI_PLL_4_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_4_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_4_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0xe0c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_4_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_4_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_4_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_4_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_4_DIV_clk_enb			{0,0,0,0}
/* PLL[5] */
/* CLK  */
#define CMUI_PLL_5_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x1000, 0, 32}
#define CMUI_PLL_5_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x1004, 0, 32}
#define CMUI_PLL_5_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x1008, 0, 32}
#define CMUI_PLL_5_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_5_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_5_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x100c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_5_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_5_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_5_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_5_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_5_DIV_clk_enb			{0,0,0,0}
/* PLL[6] */
/* CLK  */
#define CMUI_PLL_6_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x1200, 0, 32}
#define CMUI_PLL_6_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x1204, 0, 32}
#define CMUI_PLL_6_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x1208, 0, 32}
#define CMUI_PLL_6_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_6_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_6_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x120c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_6_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_6_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_6_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_6_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_6_DIV_clk_enb			{0,0,0,0}
/* PLL[7] */
/* CLK  */
#define CMUI_PLL_7_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x1400, 0, 32}
#define CMUI_PLL_7_CLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x1404, 0, 32}
#define CMUI_PLL_7_CLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x1408, 0, 32}
#define CMUI_PLL_7_CLK_div_rst			{0,0,0,0}
#define CMUI_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_7_CLK_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_7_CLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x140c, 0, 1}
/* DIV :not_using_div */
#define CMUI_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_PLL_7_DIV_grp_a_div_rst		{0,0,0,0}
#define CMUI_PLL_7_DIV_grp_gate_mode		{0,0,0,0}
#define CMUI_PLL_7_DIV_div_rst			{0,0,0,0}
#define CMUI_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_PLL_7_DIV_dy_div_busy_st		{0,0,0,0}
#define CMUI_PLL_7_DIV_clk_enb			{0,0,0,0}
/* USBOPHY */
/* USBOPHY[0] */
/* CLK  */
#define CMUI_USBOPHY_0_CLK_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1600, 0, 32}
#define CMUI_USBOPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1604, 0, 32}
#define CMUI_USBOPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1608, 0, 32}
#define CMUI_USBOPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBOPHY_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBOPHY_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBOPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBOPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x160c, 0, 1}
/* USBHPHY */
/* USBHPHY[0] */
/* CLK  */
#define CMUI_USBHPHY_0_CLK_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1800, 0, 32}
#define CMUI_USBHPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1804, 0, 32}
#define CMUI_USBHPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x1808, 0, 32}
#define CMUI_USBHPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBHPHY_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBHPHY_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBHPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USBHPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x180c, 0, 1}
/* HDMIPHY_PIXEL */
/* HDMIPHY_PIXEL[0] */
/* CLK  */
#define CMUI_HDMIPHY_PIXEL_0_CLK_grp_clk_src	{&SFR_INFO.CMU_SYS[0], 0x1a00, 0, 32}
#define CMUI_HDMIPHY_PIXEL_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x1a04, 0, 32}
#define CMUI_HDMIPHY_PIXEL_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x1a08, 0, 32}
#define CMUI_HDMIPHY_PIXEL_0_CLK_div_rst	{0,0,0,0}
#define CMUI_HDMIPHY_PIXEL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_HDMIPHY_PIXEL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_HDMIPHY_PIXEL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIPHY_PIXEL_0_CLK_clk_enb	{&SFR_INFO.CMU_SYS[0], 0x1a0c, 0, 1}
/* HDMIPHY_TMDS */
/* HDMIPHY_TMDS[0] */
/* CLK  */
#define CMUI_HDMIPHY_TMDS_0_CLK_grp_clk_src	{&SFR_INFO.CMU_SYS[0], 0x1c00, 0, 32}
#define CMUI_HDMIPHY_TMDS_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x1c04, 0, 32}
#define CMUI_HDMIPHY_TMDS_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x1c08, 0, 32}
#define CMUI_HDMIPHY_TMDS_0_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMIPHY_TMDS_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_HDMIPHY_TMDS_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_HDMIPHY_TMDS_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIPHY_TMDS_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1c0c, 0, 1}
/* BBUS_PLL */
/* BBUS_PLL[0] */
/* DIV  */
#define CMUI_BBUS_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 2, 1}
/* CLK :not_using_div */
#define CMUI_BBUS_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_0_CLK_clk_enb		{0,0,0,0}
/* BBUS_PLL[1] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 1, 1}
/* BBUS_PLL[2] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 1, 1}
/* BBUS_PLL[3] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 1, 1}
/* BBUS_PLL[4] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 1, 1}
/* BBUS_PLL[5] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 1, 1}
/* BBUS_PLL[6] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 1, 1}
/* BBUS_PLL[7] */
/* DIV :not_using_div */
#define CMUI_BBUS_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_BBUS_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 1, 1}
/* BBUS_USBOPHY */
/* BBUS_USBOPHY[0] */
/* CLK  */
#define CMUI_BBUS_USBOPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBOPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x160c, 1, 1}
/* BBUS_USBHPHY */
/* BBUS_USBHPHY[0] */
/* CLK  */
#define CMUI_BBUS_USBHPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_BBUS_USBHPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x180c, 1, 1}
/* BBUS_HDMIPHY_PIXEL */
/* BBUS_HDMIPHY_PIXEL[0] */
/* CLK  */
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_PIXEL_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1a0c, 1, 1}
/* BBUS_HDMIPHY_TMDS */
/* BBUS_HDMIPHY_TMDS[0] */
/* CLK  */
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_div_rst		{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUS_HDMIPHY_TMDS_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1c0c, 1, 1}
/* TBUS_PLL */
/* TBUS_PLL[0] */
/* DIV  */
#define CMUI_TBUS_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 3, 1}
/* CLK :not_using_div */
#define CMUI_TBUS_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_0_CLK_clk_enb		{0,0,0,0}
/* TBUS_PLL[1] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 2, 1}
/* TBUS_PLL[2] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 2, 1}
/* TBUS_PLL[3] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 2, 1}
/* TBUS_PLL[4] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 2, 1}
/* TBUS_PLL[5] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 2, 1}
/* TBUS_PLL[6] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 2, 1}
/* TBUS_PLL[7] */
/* DIV :not_using_div */
#define CMUI_TBUS_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_TBUS_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 2, 1}
/* TBUS_USBOPHY */
/* TBUS_USBOPHY[0] */
/* CLK  */
#define CMUI_TBUS_USBOPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBOPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x160c, 2, 1}
/* TBUS_USBHPHY */
/* TBUS_USBHPHY[0] */
/* CLK  */
#define CMUI_TBUS_USBHPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_TBUS_USBHPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x180c, 2, 1}
/* TBUS_HDMIPHY_PIXEL */
/* TBUS_HDMIPHY_PIXEL[0] */
/* CLK  */
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_PIXEL_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1a0c, 2, 1}
/* TBUS_HDMIPHY_TMDS */
/* TBUS_HDMIPHY_TMDS[0] */
/* CLK  */
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_div_rst		{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_TBUS_HDMIPHY_TMDS_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1c0c, 2, 1}
/* LBUS_PLL */
/* LBUS_PLL[0] */
/* DIV  */
#define CMUI_LBUS_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 4, 1}
/* CLK :not_using_div */
#define CMUI_LBUS_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_0_CLK_clk_enb		{0,0,0,0}
/* LBUS_PLL[1] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 3, 1}
/* LBUS_PLL[2] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 3, 1}
/* LBUS_PLL[3] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 3, 1}
/* LBUS_PLL[4] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 3, 1}
/* LBUS_PLL[5] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 3, 1}
/* LBUS_PLL[6] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 3, 1}
/* LBUS_PLL[7] */
/* DIV :not_using_div */
#define CMUI_LBUS_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_LBUS_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 3, 1}
/* LBUS_USBOPHY */
/* LBUS_USBOPHY[0] */
/* CLK  */
#define CMUI_LBUS_USBOPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBOPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x160c, 3, 1}
/* LBUS_USBHPHY */
/* LBUS_USBHPHY[0] */
/* CLK  */
#define CMUI_LBUS_USBHPHY_0_CLK_grp_clk_src	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_dy_div_val	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_dy_div_stop	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_LBUS_USBHPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x180c, 3, 1}
/* LBUS_HDMIPHY_PIXEL */
/* LBUS_HDMIPHY_PIXEL[0] */
/* CLK  */
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_PIXEL_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1a0c, 3, 1}
/* LBUS_HDMIPHY_TMDS */
/* LBUS_HDMIPHY_TMDS[0] */
/* CLK  */
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_div_rst		{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUS_HDMIPHY_TMDS_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1c0c, 3, 1}
/* DISP_PLL */
/* DISP_PLL[0] */
/* DIV  */
#define CMUI_DISP_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 5, 1}
/* CLK :not_using_div */
#define CMUI_DISP_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_0_CLK_clk_enb		{0,0,0,0}
/* DISP_PLL[1] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 4, 1}
/* DISP_PLL[2] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 4, 1}
/* DISP_PLL[3] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 4, 1}
/* DISP_PLL[4] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 4, 1}
/* DISP_PLL[5] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 4, 1}
/* DISP_PLL[6] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 4, 1}
/* DISP_PLL[7] */
/* DIV :not_using_div */
#define CMUI_DISP_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_DISP_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 4, 1}
/* HDMI_PLL */
/* HDMI_PLL[0] */
/* DIV  */
#define CMUI_HDMI_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 6, 1}
/* CLK :not_using_div */
#define CMUI_HDMI_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_0_CLK_clk_enb		{0,0,0,0}
/* HDMI_PLL[1] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 5, 1}
/* HDMI_PLL[2] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 5, 1}
/* HDMI_PLL[3] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 5, 1}
/* HDMI_PLL[4] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 5, 1}
/* HDMI_PLL[5] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 5, 1}
/* HDMI_PLL[6] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 5, 1}
/* HDMI_PLL[7] */
/* DIV :not_using_div */
#define CMUI_HDMI_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_HDMI_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 5, 1}
/* CODA_PLL */
/* CODA_PLL[0] */
/* DIV  */
#define CMUI_CODA_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 7, 1}
/* CLK :not_using_div */
#define CMUI_CODA_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_0_CLK_clk_enb		{0,0,0,0}
/* CODA_PLL[1] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 6, 1}
/* CODA_PLL[2] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 6, 1}
/* CODA_PLL[3] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 6, 1}
/* CODA_PLL[4] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 6, 1}
/* CODA_PLL[5] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 6, 1}
/* CODA_PLL[6] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 6, 1}
/* CODA_PLL[7] */
/* DIV :not_using_div */
#define CMUI_CODA_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_CODA_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 6, 1}
/* WAVE_PLL */
/* WAVE_PLL[0] */
/* DIV  */
#define CMUI_WAVE_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 8, 1}
/* CLK :not_using_div */
#define CMUI_WAVE_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_0_CLK_clk_enb		{0,0,0,0}
/* WAVE_PLL[1] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 7, 1}
/* WAVE_PLL[2] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 7, 1}
/* WAVE_PLL[3] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 7, 1}
/* WAVE_PLL[4] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 7, 1}
/* WAVE_PLL[5] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 7, 1}
/* WAVE_PLL[6] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 7, 1}
/* WAVE_PLL[7] */
/* DIV :not_using_div */
#define CMUI_WAVE_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 7, 1}
/* WAVE420_PLL */
/* WAVE420_PLL[0] */
/* DIV  */
#define CMUI_WAVE420_PLL_0_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 9, 1}
/* CLK :not_using_div */
#define CMUI_WAVE420_PLL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_0_CLK_clk_enb		{0,0,0,0}
/* WAVE420_PLL[1] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_1_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_1_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 8, 1}
/* WAVE420_PLL[2] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_2_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_2_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 8, 1}
/* WAVE420_PLL[3] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_3_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_3_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 8, 1}
/* WAVE420_PLL[4] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_4_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_4_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 8, 1}
/* WAVE420_PLL[5] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_5_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_5_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 8, 1}
/* WAVE420_PLL[6] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_6_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_6_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 8, 1}
/* WAVE420_PLL[7] */
/* DIV :not_using_div */
#define CMUI_WAVE420_PLL_7_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_WAVE420_PLL_7_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 8, 1}
/* USB_PLL */
/* USB_PLL[0] */
/* DIV  */
#define CMUI_USB_PLL_0_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_DIV_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x60c, 10, 1}
/* CLK :not_using_div */
#define CMUI_USB_PLL_0_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_0_CLK_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* USB_PLL[1] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_1_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_1_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_1_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x80c, 9, 1}
/* USB_PLL[2] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_2_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_2_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_2_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0xa0c, 9, 1}
/* USB_PLL[3] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_3_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_3_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_3_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0xc0c, 9, 1}
/* USB_PLL[4] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_4_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_4_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_4_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0xe0c, 9, 1}
/* USB_PLL[5] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_5_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_5_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_5_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x100c, 9, 1}
/* USB_PLL[6] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_6_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_6_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_6_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x120c, 9, 1}
/* USB_PLL[7] */
/* DIV :not_using_div */
#define CMUI_USB_PLL_7_DIV_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_DIV_clk_enb		(_nx_cpuif_sym_){0,0,0,0}
/* CLK  */
#define CMUI_USB_PLL_7_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_PLL_7_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x140c, 9, 1}
/* ISP_PLL */
/* ISP_PLL[0] */
/* DIV  */
#define CMUI_ISP_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 11, 1}
/* CLK :not_using_div */
#define CMUI_ISP_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_0_CLK_clk_enb		{0,0,0,0}
/* ISP_PLL[1] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 10, 1}
/* ISP_PLL[2] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 10, 1}
/* ISP_PLL[3] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 10, 1}
/* ISP_PLL[4] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 10, 1}
/* ISP_PLL[5] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 10, 1}
/* ISP_PLL[6] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 10, 1}
/* ISP_PLL[7] */
/* DIV :not_using_div */
#define CMUI_ISP_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_ISP_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 10, 1}
/* GPU_PLL */
/* GPU_PLL[0] */
/* DIV  */
#define CMUI_GPU_PLL_0_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 12, 1}
/* CLK :not_using_div */
#define CMUI_GPU_PLL_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_0_CLK_clk_enb		{0,0,0,0}
/* GPU_PLL[1] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_1_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_1_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 11, 1}
/* GPU_PLL[2] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_2_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_2_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 11, 1}
/* GPU_PLL[3] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_3_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_3_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 11, 1}
/* GPU_PLL[4] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_4_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_4_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 11, 1}
/* GPU_PLL[5] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_5_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_5_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 11, 1}
/* GPU_PLL[6] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_6_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_6_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 11, 1}
/* GPU_PLL[7] */
/* DIV :not_using_div */
#define CMUI_GPU_PLL_7_DIV_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_GPU_PLL_7_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 11, 1}
/* PERICLK_PLL */
/* PERICLK_PLL[0] */
/* DIV  */
#define CMUI_PERICLK_PLL_0_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_DIV_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x60c, 13, 1}
/* CLK :not_using_div */
#define CMUI_PERICLK_PLL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_0_CLK_clk_enb		{0,0,0,0}
/* PERICLK_PLL[1] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_1_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_1_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_1_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x80c, 12, 1}
/* PERICLK_PLL[2] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_2_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_2_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_2_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xa0c, 12, 1}
/* PERICLK_PLL[3] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_3_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_3_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_3_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xc0c, 12, 1}
/* PERICLK_PLL[4] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_4_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_4_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_4_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0xe0c, 12, 1}
/* PERICLK_PLL[5] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_5_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_5_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_5_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x100c, 12, 1}
/* PERICLK_PLL[6] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_6_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_6_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_6_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x120c, 12, 1}
/* PERICLK_PLL[7] */
/* DIV :not_using_div */
#define CMUI_PERICLK_PLL_7_DIV_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_DIV_clk_enb		{0,0,0,0}
/* CLK  */
#define CMUI_PERICLK_PLL_7_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_PLL_7_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x140c, 12, 1}
/* PERICLK_USBOPHY */
/* PERICLK_USBOPHY[0] */
/* CLK  */
#define CMUI_PERICLK_USBOPHY_0_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBOPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x160c, 4, 1}
/* PERICLK_USBHPHY */
/* PERICLK_USBHPHY[0] */
/* CLK  */
#define CMUI_PERICLK_USBHPHY_0_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_PERICLK_USBHPHY_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x180c, 4, 1}
/* PERICLK_HDMIPHY_PIXEL */
/* PERICLK_HDMIPHY_PIXEL[0] */
/* CLK  */
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_div_rst	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_PIXEL_0_CLK_clk_enb	{&SFR_INFO.CMU_SYS[0], 0x1a0c, 4, 1}
/* PERICLK_HDMIPHY_TMDS */
/* PERICLK_HDMIPHY_TMDS[0] */
/* CLK  */
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_HDMIPHY_TMDS_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x1c0c, 4, 1}
/* PDM */
/* PDM[0] */
/* APB  */
#define CMUI_PDM_0_APB_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x1e00, 0, 32}
#define CMUI_PDM_0_APB_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x1e04, 0, 32}
#define CMUI_PDM_0_APB_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x1e08, 0, 32}
#define CMUI_PDM_0_APB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x1e44, 0, 32}
#define CMUI_PDM_0_APB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x1e48, 0, 32}
#define CMUI_PDM_0_APB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x1e4c, 0, 32}
#define CMUI_PDM_0_APB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x1e50, 0, 32}
#define CMUI_PDM_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x1e0c, 0, 1}
/* PDM[1] */
/* APB  */
#define CMUI_PDM_1_APB_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2000, 0, 32}
#define CMUI_PDM_1_APB_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2004, 0, 32}
#define CMUI_PDM_1_APB_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x2008, 0, 32}
#define CMUI_PDM_1_APB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x2044, 0, 32}
#define CMUI_PDM_1_APB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2048, 0, 32}
#define CMUI_PDM_1_APB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x204c, 0, 32}
#define CMUI_PDM_1_APB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x2050, 0, 32}
#define CMUI_PDM_1_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x200c, 0, 1}
/* PDM[2] */
/* APB  */
#define CMUI_PDM_2_APB_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2200, 0, 32}
#define CMUI_PDM_2_APB_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2204, 0, 32}
#define CMUI_PDM_2_APB_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x2208, 0, 32}
#define CMUI_PDM_2_APB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x2244, 0, 32}
#define CMUI_PDM_2_APB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2248, 0, 32}
#define CMUI_PDM_2_APB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x224c, 0, 32}
#define CMUI_PDM_2_APB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x2250, 0, 32}
#define CMUI_PDM_2_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x220c, 0, 1}
/* PDM[3] */
/* APB  */
#define CMUI_PDM_3_APB_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2400, 0, 32}
#define CMUI_PDM_3_APB_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2404, 0, 32}
#define CMUI_PDM_3_APB_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x2408, 0, 32}
#define CMUI_PDM_3_APB_div_rst			{&SFR_INFO.CMU_SYS[0], 0x2444, 0, 32}
#define CMUI_PDM_3_APB_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2448, 0, 32}
#define CMUI_PDM_3_APB_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x244c, 0, 32}
#define CMUI_PDM_3_APB_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x2450, 0, 32}
#define CMUI_PDM_3_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x240c, 0, 1}
/* AUDIO_IO_CTRL */
/* AUDIO_IO_CTRL[0] */
/* APB  */
#define CMUI_AUDIO_IO_CTRL_0_APB_grp_clk_src	{&SFR_INFO.CMU_SYS[0], 0x2600, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x2604, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x2608, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_div_rst	{&SFR_INFO.CMU_SYS[0], 0x2644, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_dy_div_val	{&SFR_INFO.CMU_SYS[0], 0x2648, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_dy_div_stop	{&SFR_INFO.CMU_SYS[0], 0x264c, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x2650, 0, 32}
#define CMUI_AUDIO_IO_CTRL_0_APB_clk_enb	{&SFR_INFO.CMU_SYS[0], 0x260c, 0, 1}
/* UART */
/* UART[0] */
/* CORE  */
#define CMUI_UART_0_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x400, 0, 32}
#define CMUI_UART_0_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x404, 0, 32}
#define CMUI_UART_0_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x408, 0, 32}
#define CMUI_UART_0_CORE_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x444, 0, 32}
#define CMUI_UART_0_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x448, 0, 32}
#define CMUI_UART_0_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x44c, 0, 32}
#define CMUI_UART_0_CORE_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x450, 0, 32}
#define CMUI_UART_0_CORE_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x40c, 0, 1}
/* APB  */
#define CMUI_UART_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_0_APB_div_rst			{0,0,0,0}
#define CMUI_UART_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_0_APB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x20c, 3, 1}
/* UART[1] */
/* CORE  */
#define CMUI_UART_1_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x600, 0, 32}
#define CMUI_UART_1_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x604, 0, 32}
#define CMUI_UART_1_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x608, 0, 32}
#define CMUI_UART_1_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x644, 0, 32}
#define CMUI_UART_1_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x648, 0, 32}
#define CMUI_UART_1_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x64c, 0, 32}
#define CMUI_UART_1_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x650, 0, 32}
#define CMUI_UART_1_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x60c, 0, 1}
/* APB  */
#define CMUI_UART_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_1_APB_div_rst			{0,0,0,0}
#define CMUI_UART_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_1_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 4, 1}
/* UART[2] */
/* CORE  */
#define CMUI_UART_2_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x800, 0, 32}
#define CMUI_UART_2_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x804, 0, 32}
#define CMUI_UART_2_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x808, 0, 32}
#define CMUI_UART_2_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x844, 0, 32}
#define CMUI_UART_2_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x848, 0, 32}
#define CMUI_UART_2_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x84c, 0, 32}
#define CMUI_UART_2_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x850, 0, 32}
#define CMUI_UART_2_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x80c, 0, 1}
/* APB  */
#define CMUI_UART_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_2_APB_div_rst			{0,0,0,0}
#define CMUI_UART_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_2_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 5, 1}
/* UART[3] */
/* CORE  */
#define CMUI_UART_3_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0xa00, 0, 32}
#define CMUI_UART_3_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xa04, 0, 32}
#define CMUI_UART_3_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0xa08, 0, 32}
#define CMUI_UART_3_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xa44, 0, 32}
#define CMUI_UART_3_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0xa48, 0, 32}
#define CMUI_UART_3_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0xa4c, 0, 32}
#define CMUI_UART_3_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0xa50, 0, 32}
#define CMUI_UART_3_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0xa0c, 0, 1}
/* APB  */
#define CMUI_UART_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_3_APB_div_rst			{0,0,0,0}
#define CMUI_UART_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_3_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 6, 1}
/* UART[4] */
/* CORE  */
#define CMUI_UART_4_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0xc00, 0, 32}
#define CMUI_UART_4_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xc04, 0, 32}
#define CMUI_UART_4_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0xc08, 0, 32}
#define CMUI_UART_4_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xc44, 0, 32}
#define CMUI_UART_4_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0xc48, 0, 32}
#define CMUI_UART_4_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0xc4c, 0, 32}
#define CMUI_UART_4_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0xc50, 0, 32}
#define CMUI_UART_4_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0xc0c, 0, 1}
/* APB  */
#define CMUI_UART_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_4_APB_div_rst			{0,0,0,0}
#define CMUI_UART_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_4_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 7, 1}
/* UART[5] */
/* CORE  */
#define CMUI_UART_5_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0xe00, 0, 32}
#define CMUI_UART_5_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xe04, 0, 32}
#define CMUI_UART_5_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0xe08, 0, 32}
#define CMUI_UART_5_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0xe44, 0, 32}
#define CMUI_UART_5_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0xe48, 0, 32}
#define CMUI_UART_5_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0xe4c, 0, 32}
#define CMUI_UART_5_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0xe50, 0, 32}
#define CMUI_UART_5_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0xe0c, 0, 1}
/* APB  */
#define CMUI_UART_5_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_5_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_5_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_5_APB_div_rst			{0,0,0,0}
#define CMUI_UART_5_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_5_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_5_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_5_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 8, 1}
/* UART[6] */
/* CORE  */
#define CMUI_UART_6_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x1000, 0, 32}
#define CMUI_UART_6_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1004, 0, 32}
#define CMUI_UART_6_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x1008, 0, 32}
#define CMUI_UART_6_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1044, 0, 32}
#define CMUI_UART_6_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x1048, 0, 32}
#define CMUI_UART_6_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x104c, 0, 32}
#define CMUI_UART_6_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x1050, 0, 32}
#define CMUI_UART_6_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x100c, 0, 1}
/* APB  */
#define CMUI_UART_6_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_6_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_6_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_6_APB_div_rst			{0,0,0,0}
#define CMUI_UART_6_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_6_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_6_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_6_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 9, 1}
/* UART[7] */
/* CORE  */
#define CMUI_UART_7_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x1200, 0, 32}
#define CMUI_UART_7_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1204, 0, 32}
#define CMUI_UART_7_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x1208, 0, 32}
#define CMUI_UART_7_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1244, 0, 32}
#define CMUI_UART_7_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x1248, 0, 32}
#define CMUI_UART_7_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x124c, 0, 32}
#define CMUI_UART_7_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x1250, 0, 32}
#define CMUI_UART_7_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x120c, 0, 1}
/* APB  */
#define CMUI_UART_7_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_7_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_7_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_7_APB_div_rst			{0,0,0,0}
#define CMUI_UART_7_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_7_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_7_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_7_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 10, 1}
/* UART[8] */
/* CORE  */
#define CMUI_UART_8_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x1400, 0, 32}
#define CMUI_UART_8_CORE_grp_a_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1404, 0, 32}
#define CMUI_UART_8_CORE_grp_gate_mode		{&SFR_INFO.CMU_BBUS[0], 0x1408, 0, 32}
#define CMUI_UART_8_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x1444, 0, 32}
#define CMUI_UART_8_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x1448, 0, 32}
#define CMUI_UART_8_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x144c, 0, 32}
#define CMUI_UART_8_CORE_dy_div_busy_st		{&SFR_INFO.CMU_BBUS[0], 0x1450, 0, 32}
#define CMUI_UART_8_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x140c, 0, 1}
/* APB  */
#define CMUI_UART_8_APB_grp_clk_src		{0,0,0,0}
#define CMUI_UART_8_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_UART_8_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_UART_8_APB_div_rst			{0,0,0,0}
#define CMUI_UART_8_APB_dy_div_val		{0,0,0,0}
#define CMUI_UART_8_APB_dy_div_stop		{0,0,0,0}
#define CMUI_UART_8_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_UART_8_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 11, 1}
/* SPI */
/* SPI[0] */
/* APB  */
#define CMUI_SPI_0_APB_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1600, 0, 32}
#define CMUI_SPI_0_APB_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1604, 0, 32}
#define CMUI_SPI_0_APB_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1608, 0, 32}
#define CMUI_SPI_0_APB_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1644, 0, 32}
#define CMUI_SPI_0_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1648, 0, 32}
#define CMUI_SPI_0_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x164c, 0, 32}
#define CMUI_SPI_0_APB_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1650, 0, 32}
#define CMUI_SPI_0_APB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x160c, 0, 1}
/* CORE  */
#define CMUI_SPI_0_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1800, 0, 32}
#define CMUI_SPI_0_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1804, 0, 32}
#define CMUI_SPI_0_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1808, 0, 32}
#define CMUI_SPI_0_CORE_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1844, 0, 32}
#define CMUI_SPI_0_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1848, 0, 32}
#define CMUI_SPI_0_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x184c, 0, 32}
#define CMUI_SPI_0_CORE_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1850, 0, 32}
#define CMUI_SPI_0_CORE_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x180c, 0, 1}
/* SPI[1] */
/* APB  */
#define CMUI_SPI_1_APB_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a00, 0, 32}
#define CMUI_SPI_1_APB_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a04, 0, 32}
#define CMUI_SPI_1_APB_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a08, 0, 32}
#define CMUI_SPI_1_APB_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a44, 0, 32}
#define CMUI_SPI_1_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a48, 0, 32}
#define CMUI_SPI_1_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a4c, 0, 32}
#define CMUI_SPI_1_APB_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a50, 0, 32}
#define CMUI_SPI_1_APB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1a0c, 0, 1}
/* CORE  */
#define CMUI_SPI_1_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c00, 0, 32}
#define CMUI_SPI_1_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c04, 0, 32}
#define CMUI_SPI_1_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c08, 0, 32}
#define CMUI_SPI_1_CORE_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c44, 0, 32}
#define CMUI_SPI_1_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c48, 0, 32}
#define CMUI_SPI_1_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c4c, 0, 32}
#define CMUI_SPI_1_CORE_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c50, 0, 32}
#define CMUI_SPI_1_CORE_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1c0c, 0, 1}
/* SPI[2] */
/* APB  */
#define CMUI_SPI_2_APB_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e00, 0, 32}
#define CMUI_SPI_2_APB_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e04, 0, 32}
#define CMUI_SPI_2_APB_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e08, 0, 32}
#define CMUI_SPI_2_APB_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e44, 0, 32}
#define CMUI_SPI_2_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e48, 0, 32}
#define CMUI_SPI_2_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e4c, 0, 32}
#define CMUI_SPI_2_APB_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e50, 0, 32}
#define CMUI_SPI_2_APB_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x1e0c, 0, 1}
/* CORE  */
#define CMUI_SPI_2_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2000, 0, 32}
#define CMUI_SPI_2_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2004, 0, 32}
#define CMUI_SPI_2_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2008, 0, 32}
#define CMUI_SPI_2_CORE_div_rst			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2044, 0, 32}
#define CMUI_SPI_2_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2048, 0, 32}
#define CMUI_SPI_2_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x204c, 0, 32}
#define CMUI_SPI_2_CORE_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x2050, 0, 32}
#define CMUI_SPI_2_CORE_clk_enb			(_nx_cpuif_sym_){&SFR_INFO.CMU_BBUS[0], 0x200c, 0, 1}
/* SPDIFTX */
/* SPDIFTX[0] */
/* CORE  */
#define CMUI_SPDIFTX_0_CORE_grp_clk_src		{&SFR_INFO.CMU_BBUS[0], 0x2200, 0, 32}
#define CMUI_SPDIFTX_0_CORE_grp_a_div_rst	{&SFR_INFO.CMU_BBUS[0], 0x2204, 0, 32}
#define CMUI_SPDIFTX_0_CORE_grp_gate_mode	{&SFR_INFO.CMU_BBUS[0], 0x2208, 0, 32}
#define CMUI_SPDIFTX_0_CORE_div_rst		{&SFR_INFO.CMU_BBUS[0], 0x2244, 0, 32}
#define CMUI_SPDIFTX_0_CORE_dy_div_val		{&SFR_INFO.CMU_BBUS[0], 0x2248, 0, 32}
#define CMUI_SPDIFTX_0_CORE_dy_div_stop		{&SFR_INFO.CMU_BBUS[0], 0x224c, 0, 32}
#define CMUI_SPDIFTX_0_CORE_dy_div_busy_st	{&SFR_INFO.CMU_BBUS[0], 0x2250, 0, 32}
#define CMUI_SPDIFTX_0_CORE_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x220c, 0, 1}
/* APB  */
#define CMUI_SPDIFTX_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_div_rst		{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_SPDIFTX_0_APB_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x20c, 12, 1}
/* I2S */
/* I2S[0] */
/* CORE  */
#define CMUI_I2S_0_CORE_grp_clk_src		{&SFR_INFO.CMU_TBUS[0], 0x400, 0, 32}
#define CMUI_I2S_0_CORE_grp_a_div_rst		{&SFR_INFO.CMU_TBUS[0], 0x404, 0, 32}
#define CMUI_I2S_0_CORE_grp_gate_mode		{&SFR_INFO.CMU_TBUS[0], 0x408, 0, 32}
#define CMUI_I2S_0_CORE_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x444, 0, 32}
#define CMUI_I2S_0_CORE_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x448, 0, 32}
#define CMUI_I2S_0_CORE_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x44c, 0, 32}
#define CMUI_I2S_0_CORE_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x450, 0, 32}
#define CMUI_I2S_0_CORE_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x40c, 0, 1}
/* APB  */
#define CMUI_I2S_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2S_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2S_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2S_0_APB_div_rst			{0,0,0,0}
#define CMUI_I2S_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2S_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2S_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2S_0_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 3, 1}
/* I2S[1] */
/* CORE  */
#define CMUI_I2S_1_CORE_grp_clk_src		{&SFR_INFO.CMU_TBUS[0], 0x600, 0, 32}
#define CMUI_I2S_1_CORE_grp_a_div_rst		{&SFR_INFO.CMU_TBUS[0], 0x604, 0, 32}
#define CMUI_I2S_1_CORE_grp_gate_mode		{&SFR_INFO.CMU_TBUS[0], 0x608, 0, 32}
#define CMUI_I2S_1_CORE_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x644, 0, 32}
#define CMUI_I2S_1_CORE_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x648, 0, 32}
#define CMUI_I2S_1_CORE_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x64c, 0, 32}
#define CMUI_I2S_1_CORE_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x650, 0, 32}
#define CMUI_I2S_1_CORE_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x60c, 0, 1}
/* APB  */
#define CMUI_I2S_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2S_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2S_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2S_1_APB_div_rst			{0,0,0,0}
#define CMUI_I2S_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2S_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2S_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2S_1_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 4, 1}
/* I2S[2] */
/* CORE  */
#define CMUI_I2S_2_CORE_grp_clk_src		{&SFR_INFO.CMU_TBUS[0], 0x800, 0, 32}
#define CMUI_I2S_2_CORE_grp_a_div_rst		{&SFR_INFO.CMU_TBUS[0], 0x804, 0, 32}
#define CMUI_I2S_2_CORE_grp_gate_mode		{&SFR_INFO.CMU_TBUS[0], 0x808, 0, 32}
#define CMUI_I2S_2_CORE_div_rst			{&SFR_INFO.CMU_TBUS[0], 0x844, 0, 32}
#define CMUI_I2S_2_CORE_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0x848, 0, 32}
#define CMUI_I2S_2_CORE_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0x84c, 0, 32}
#define CMUI_I2S_2_CORE_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0x850, 0, 32}
#define CMUI_I2S_2_CORE_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x80c, 0, 1}
/* APB  */
#define CMUI_I2S_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2S_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2S_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2S_2_APB_div_rst			{0,0,0,0}
#define CMUI_I2S_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2S_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2S_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2S_2_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 5, 1}
/* I2S[3] */
/* CORE  */
#define CMUI_I2S_3_CORE_grp_clk_src		{&SFR_INFO.CMU_TBUS[0], 0xa00, 0, 32}
#define CMUI_I2S_3_CORE_grp_a_div_rst		{&SFR_INFO.CMU_TBUS[0], 0xa04, 0, 32}
#define CMUI_I2S_3_CORE_grp_gate_mode		{&SFR_INFO.CMU_TBUS[0], 0xa08, 0, 32}
#define CMUI_I2S_3_CORE_div_rst			{&SFR_INFO.CMU_TBUS[0], 0xa44, 0, 32}
#define CMUI_I2S_3_CORE_dy_div_val		{&SFR_INFO.CMU_TBUS[0], 0xa48, 0, 32}
#define CMUI_I2S_3_CORE_dy_div_stop		{&SFR_INFO.CMU_TBUS[0], 0xa4c, 0, 32}
#define CMUI_I2S_3_CORE_dy_div_busy_st		{&SFR_INFO.CMU_TBUS[0], 0xa50, 0, 32}
#define CMUI_I2S_3_CORE_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0xa0c, 0, 1}
/* APB  */
#define CMUI_I2S_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2S_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2S_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2S_3_APB_div_rst			{0,0,0,0}
#define CMUI_I2S_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2S_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2S_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2S_3_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 6, 1}
/* SDMMC */
/* SDMMC[0] */
/* CORE  */
#define CMUI_SDMMC_0_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x400, 0, 32}
#define CMUI_SDMMC_0_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x404, 0, 32}
#define CMUI_SDMMC_0_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x408, 0, 32}
#define CMUI_SDMMC_0_CORE_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x444, 0, 32}
#define CMUI_SDMMC_0_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x448, 0, 32}
#define CMUI_SDMMC_0_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x44c, 0, 32}
#define CMUI_SDMMC_0_CORE_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x450, 0, 32}
#define CMUI_SDMMC_0_CORE_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x40c, 0, 1}
/* AXI  */
#define CMUI_SDMMC_0_AXI_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x600, 0, 32}
#define CMUI_SDMMC_0_AXI_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x604, 0, 32}
#define CMUI_SDMMC_0_AXI_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x608, 0, 32}
#define CMUI_SDMMC_0_AXI_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x644, 0, 32}
#define CMUI_SDMMC_0_AXI_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x648, 0, 32}
#define CMUI_SDMMC_0_AXI_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x64c, 0, 32}
#define CMUI_SDMMC_0_AXI_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x650, 0, 32}
#define CMUI_SDMMC_0_AXI_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x60c, 0, 1}
/* SDMMC[1] */
/* CORE  */
#define CMUI_SDMMC_1_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x800, 0, 32}
#define CMUI_SDMMC_1_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x804, 0, 32}
#define CMUI_SDMMC_1_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x808, 0, 32}
#define CMUI_SDMMC_1_CORE_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x844, 0, 32}
#define CMUI_SDMMC_1_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x848, 0, 32}
#define CMUI_SDMMC_1_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x84c, 0, 32}
#define CMUI_SDMMC_1_CORE_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x850, 0, 32}
#define CMUI_SDMMC_1_CORE_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0x80c, 0, 1}
/* AXI  */
#define CMUI_SDMMC_1_AXI_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa00, 0, 32}
#define CMUI_SDMMC_1_AXI_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa04, 0, 32}
#define CMUI_SDMMC_1_AXI_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa08, 0, 32}
#define CMUI_SDMMC_1_AXI_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa44, 0, 32}
#define CMUI_SDMMC_1_AXI_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa48, 0, 32}
#define CMUI_SDMMC_1_AXI_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa4c, 0, 32}
#define CMUI_SDMMC_1_AXI_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa50, 0, 32}
#define CMUI_SDMMC_1_AXI_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xa0c, 0, 1}
/* SDMMC[2] */
/* CORE  */
#define CMUI_SDMMC_2_CORE_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc00, 0, 32}
#define CMUI_SDMMC_2_CORE_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc04, 0, 32}
#define CMUI_SDMMC_2_CORE_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc08, 0, 32}
#define CMUI_SDMMC_2_CORE_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc44, 0, 32}
#define CMUI_SDMMC_2_CORE_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc48, 0, 32}
#define CMUI_SDMMC_2_CORE_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc4c, 0, 32}
#define CMUI_SDMMC_2_CORE_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc50, 0, 32}
#define CMUI_SDMMC_2_CORE_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xc0c, 0, 1}
/* AXI  */
#define CMUI_SDMMC_2_AXI_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe00, 0, 32}
#define CMUI_SDMMC_2_AXI_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe04, 0, 32}
#define CMUI_SDMMC_2_AXI_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe08, 0, 32}
#define CMUI_SDMMC_2_AXI_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe44, 0, 32}
#define CMUI_SDMMC_2_AXI_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe48, 0, 32}
#define CMUI_SDMMC_2_AXI_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe4c, 0, 32}
#define CMUI_SDMMC_2_AXI_dy_div_busy_st		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe50, 0, 32}
#define CMUI_SDMMC_2_AXI_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_LBUS[0], 0xe0c, 0, 1}
/* GMAC */
/* GMAC[0] */
/* MII  */
#define CMUI_GMAC_0_MII_grp_clk_src		{&SFR_INFO.CMU_LBUS[0], 0x1000, 0, 32}
#define CMUI_GMAC_0_MII_grp_a_div_rst		{&SFR_INFO.CMU_LBUS[0], 0x1004, 0, 32}
#define CMUI_GMAC_0_MII_grp_gate_mode		{&SFR_INFO.CMU_LBUS[0], 0x1008, 0, 32}
#define CMUI_GMAC_0_MII_div_rst			{&SFR_INFO.CMU_LBUS[0], 0x1044, 0, 32}
#define CMUI_GMAC_0_MII_dy_div_val		{&SFR_INFO.CMU_LBUS[0], 0x1048, 0, 32}
#define CMUI_GMAC_0_MII_dy_div_stop		{&SFR_INFO.CMU_LBUS[0], 0x104c, 0, 32}
#define CMUI_GMAC_0_MII_dy_div_busy_st		{&SFR_INFO.CMU_LBUS[0], 0x1050, 0, 32}
#define CMUI_GMAC_0_MII_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x100c, 0, 1}
/* TX_CLK  */
#define CMUI_GMAC_0_TX_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GMAC_0_TX_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GMAC_0_TX_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GMAC_0_TX_CLK_div_rst		{&SFR_INFO.CMU_LBUS[0], 0x1084, 0, 32}
#define CMUI_GMAC_0_TX_CLK_dy_div_val		{&SFR_INFO.CMU_LBUS[0], 0x1088, 0, 32}
#define CMUI_GMAC_0_TX_CLK_dy_div_stop		{&SFR_INFO.CMU_LBUS[0], 0x108c, 0, 32}
#define CMUI_GMAC_0_TX_CLK_dy_div_busy_st	{&SFR_INFO.CMU_LBUS[0], 0x1090, 0, 32}
#define CMUI_GMAC_0_TX_CLK_clk_enb		{&SFR_INFO.CMU_LBUS[0], 0x100c, 1, 1}
/* AHB  */
#define CMUI_GMAC_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_GMAC_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GMAC_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_GMAC_0_AHB_div_rst			{0,0,0,0}
#define CMUI_GMAC_0_AHB_dy_div_val		{0,0,0,0}
#define CMUI_GMAC_0_AHB_dy_div_stop		{0,0,0,0}
#define CMUI_GMAC_0_AHB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GMAC_0_AHB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 2, 1}
/* CSR  */
#define CMUI_GMAC_0_CSR_grp_clk_src		{0,0,0,0}
#define CMUI_GMAC_0_CSR_grp_a_div_rst		{0,0,0,0}
#define CMUI_GMAC_0_CSR_grp_gate_mode		{0,0,0,0}
#define CMUI_GMAC_0_CSR_div_rst			{0,0,0,0}
#define CMUI_GMAC_0_CSR_dy_div_val		{0,0,0,0}
#define CMUI_GMAC_0_CSR_dy_div_stop		{0,0,0,0}
#define CMUI_GMAC_0_CSR_dy_div_busy_st		{0,0,0,0}
#define CMUI_GMAC_0_CSR_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 5, 1}
/* PKA */
/* PKA[0] */
/* CORE  */
#define CMUI_PKA_0_CORE_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2800, 0, 32}
#define CMUI_PKA_0_CORE_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2804, 0, 32}
#define CMUI_PKA_0_CORE_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x2808, 0, 32}
#define CMUI_PKA_0_CORE_div_rst			{&SFR_INFO.CMU_SYS[0], 0x2844, 0, 32}
#define CMUI_PKA_0_CORE_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2848, 0, 32}
#define CMUI_PKA_0_CORE_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x284c, 0, 32}
#define CMUI_PKA_0_CORE_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x2850, 0, 32}
#define CMUI_PKA_0_CORE_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x280c, 0, 1}
/* CSSYS_SRC */
/* CSSYS_SRC[0] */
/* AXI  */
#define CMUI_CSSYS_SRC_0_AXI_grp_clk_src	{&SFR_INFO.CMU_SYS[0], 0x2a00, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x2a04, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x2a08, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2a44, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2a48, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_dy_div_stop	{&SFR_INFO.CMU_SYS[0], 0x2a4c, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x2a50, 0, 32}
#define CMUI_CSSYS_SRC_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x2a0c, 0, 1}
/* MCUSTOP */
/* MCUSTOP[0] */
/* CLK  */
#define CMUI_MCUSTOP_0_CLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2c00, 0, 32}
#define CMUI_MCUSTOP_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x2c04, 0, 32}
#define CMUI_MCUSTOP_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x2c08, 0, 32}
#define CMUI_MCUSTOP_0_CLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2c44, 0, 32}
#define CMUI_MCUSTOP_0_CLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2c48, 0, 32}
#define CMUI_MCUSTOP_0_CLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x2c4c, 0, 32}
#define CMUI_MCUSTOP_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x2c50, 0, 32}
#define CMUI_MCUSTOP_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x2c0c, 0, 1}
/* TIMER */
/* TIMER[0] */
/* TCLK  */
#define CMUI_TIMER_0_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x2e00, 0, 32}
#define CMUI_TIMER_0_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2e04, 0, 32}
#define CMUI_TIMER_0_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x2e08, 0, 32}
#define CMUI_TIMER_0_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x2e44, 0, 32}
#define CMUI_TIMER_0_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x2e48, 0, 32}
#define CMUI_TIMER_0_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x2e4c, 0, 32}
#define CMUI_TIMER_0_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x2e50, 0, 32}
#define CMUI_TIMER_0_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x2e0c, 0, 1}
/* APB  */
#define CMUI_TIMER_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_0_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 6, 1}
/* TIMER[1] */
/* TCLK  */
#define CMUI_TIMER_1_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3000, 0, 32}
#define CMUI_TIMER_1_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3004, 0, 32}
#define CMUI_TIMER_1_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3008, 0, 32}
#define CMUI_TIMER_1_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3044, 0, 32}
#define CMUI_TIMER_1_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3048, 0, 32}
#define CMUI_TIMER_1_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x304c, 0, 32}
#define CMUI_TIMER_1_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3050, 0, 32}
#define CMUI_TIMER_1_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x300c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_1_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_1_APB_clk_enb		{0,0,0,0}
/* TIMER[2] */
/* TCLK  */
#define CMUI_TIMER_2_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3200, 0, 32}
#define CMUI_TIMER_2_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3204, 0, 32}
#define CMUI_TIMER_2_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3208, 0, 32}
#define CMUI_TIMER_2_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3244, 0, 32}
#define CMUI_TIMER_2_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3248, 0, 32}
#define CMUI_TIMER_2_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x324c, 0, 32}
#define CMUI_TIMER_2_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3250, 0, 32}
#define CMUI_TIMER_2_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x320c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_2_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_2_APB_clk_enb		{0,0,0,0}
/* TIMER[3] */
/* TCLK  */
#define CMUI_TIMER_3_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3400, 0, 32}
#define CMUI_TIMER_3_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3404, 0, 32}
#define CMUI_TIMER_3_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3408, 0, 32}
#define CMUI_TIMER_3_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3444, 0, 32}
#define CMUI_TIMER_3_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3448, 0, 32}
#define CMUI_TIMER_3_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x344c, 0, 32}
#define CMUI_TIMER_3_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3450, 0, 32}
#define CMUI_TIMER_3_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x340c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_3_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_3_APB_clk_enb		{0,0,0,0}
/* TIMER[4] */
/* TCLK  */
#define CMUI_TIMER_4_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3600, 0, 32}
#define CMUI_TIMER_4_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3604, 0, 32}
#define CMUI_TIMER_4_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3608, 0, 32}
#define CMUI_TIMER_4_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3644, 0, 32}
#define CMUI_TIMER_4_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3648, 0, 32}
#define CMUI_TIMER_4_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x364c, 0, 32}
#define CMUI_TIMER_4_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3650, 0, 32}
#define CMUI_TIMER_4_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x360c, 0, 1}
/* APB  */
#define CMUI_TIMER_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_4_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_4_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 7, 1}
/* TIMER[5] */
/* TCLK  */
#define CMUI_TIMER_5_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3800, 0, 32}
#define CMUI_TIMER_5_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3804, 0, 32}
#define CMUI_TIMER_5_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3808, 0, 32}
#define CMUI_TIMER_5_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3844, 0, 32}
#define CMUI_TIMER_5_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3848, 0, 32}
#define CMUI_TIMER_5_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x384c, 0, 32}
#define CMUI_TIMER_5_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3850, 0, 32}
#define CMUI_TIMER_5_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x380c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_5_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_5_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_5_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_5_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_5_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_5_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_5_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_5_APB_clk_enb		{0,0,0,0}
/* TIMER[6] */
/* TCLK  */
#define CMUI_TIMER_6_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3a00, 0, 32}
#define CMUI_TIMER_6_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3a04, 0, 32}
#define CMUI_TIMER_6_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3a08, 0, 32}
#define CMUI_TIMER_6_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3a44, 0, 32}
#define CMUI_TIMER_6_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3a48, 0, 32}
#define CMUI_TIMER_6_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x3a4c, 0, 32}
#define CMUI_TIMER_6_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3a50, 0, 32}
#define CMUI_TIMER_6_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x3a0c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_6_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_6_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_6_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_6_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_6_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_6_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_6_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_6_APB_clk_enb		{0,0,0,0}
/* TIMER[7] */
/* TCLK  */
#define CMUI_TIMER_7_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3c00, 0, 32}
#define CMUI_TIMER_7_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3c04, 0, 32}
#define CMUI_TIMER_7_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3c08, 0, 32}
#define CMUI_TIMER_7_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3c44, 0, 32}
#define CMUI_TIMER_7_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3c48, 0, 32}
#define CMUI_TIMER_7_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x3c4c, 0, 32}
#define CMUI_TIMER_7_TCLK_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x3c50, 0, 32}
#define CMUI_TIMER_7_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x3c0c, 0, 1}
/* APB :not_using_div */
#define CMUI_TIMER_7_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TIMER_7_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TIMER_7_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TIMER_7_APB_div_rst		{0,0,0,0}
#define CMUI_TIMER_7_APB_dy_div_val		{0,0,0,0}
#define CMUI_TIMER_7_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TIMER_7_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TIMER_7_APB_clk_enb		{0,0,0,0}
/* PWM */
/* PWM[0] */
/* TCLK  */
#define CMUI_PWM_0_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x3e00, 0, 32}
#define CMUI_PWM_0_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x3e04, 0, 32}
#define CMUI_PWM_0_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x3e08, 0, 32}
#define CMUI_PWM_0_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x3e44, 0, 32}
#define CMUI_PWM_0_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x3e48, 0, 32}
#define CMUI_PWM_0_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x3e4c, 0, 32}
#define CMUI_PWM_0_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x3e50, 0, 32}
#define CMUI_PWM_0_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x3e0c, 0, 1}
/* APB  */
#define CMUI_PWM_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_0_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 8, 1}
/* PWM[1] */
/* TCLK  */
#define CMUI_PWM_1_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4000, 0, 32}
#define CMUI_PWM_1_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4004, 0, 32}
#define CMUI_PWM_1_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4008, 0, 32}
#define CMUI_PWM_1_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4044, 0, 32}
#define CMUI_PWM_1_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4048, 0, 32}
#define CMUI_PWM_1_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x404c, 0, 32}
#define CMUI_PWM_1_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4050, 0, 32}
#define CMUI_PWM_1_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x400c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_1_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_1_APB_clk_enb			{0,0,0,0}
/* PWM[2] */
/* TCLK  */
#define CMUI_PWM_2_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4200, 0, 32}
#define CMUI_PWM_2_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4204, 0, 32}
#define CMUI_PWM_2_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4208, 0, 32}
#define CMUI_PWM_2_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4244, 0, 32}
#define CMUI_PWM_2_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4248, 0, 32}
#define CMUI_PWM_2_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x424c, 0, 32}
#define CMUI_PWM_2_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4250, 0, 32}
#define CMUI_PWM_2_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x420c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_2_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_2_APB_clk_enb			{0,0,0,0}
/* PWM[3] */
/* TCLK  */
#define CMUI_PWM_3_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4400, 0, 32}
#define CMUI_PWM_3_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4404, 0, 32}
#define CMUI_PWM_3_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4408, 0, 32}
#define CMUI_PWM_3_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4444, 0, 32}
#define CMUI_PWM_3_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4448, 0, 32}
#define CMUI_PWM_3_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x444c, 0, 32}
#define CMUI_PWM_3_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4450, 0, 32}
#define CMUI_PWM_3_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x440c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_3_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_3_APB_clk_enb			{0,0,0,0}
/* PWM[4] */
/* TCLK  */
#define CMUI_PWM_4_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4600, 0, 32}
#define CMUI_PWM_4_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4604, 0, 32}
#define CMUI_PWM_4_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4608, 0, 32}
#define CMUI_PWM_4_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4644, 0, 32}
#define CMUI_PWM_4_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4648, 0, 32}
#define CMUI_PWM_4_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x464c, 0, 32}
#define CMUI_PWM_4_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4650, 0, 32}
#define CMUI_PWM_4_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x460c, 0, 1}
/* APB  */
#define CMUI_PWM_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_4_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_4_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 9, 1}
/* PWM[5] */
/* TCLK  */
#define CMUI_PWM_5_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4800, 0, 32}
#define CMUI_PWM_5_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4804, 0, 32}
#define CMUI_PWM_5_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4808, 0, 32}
#define CMUI_PWM_5_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4844, 0, 32}
#define CMUI_PWM_5_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4848, 0, 32}
#define CMUI_PWM_5_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x484c, 0, 32}
#define CMUI_PWM_5_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4850, 0, 32}
#define CMUI_PWM_5_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x480c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_5_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_5_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_5_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_5_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_5_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_5_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_5_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_5_APB_clk_enb			{0,0,0,0}
/* PWM[6] */
/* TCLK  */
#define CMUI_PWM_6_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4a00, 0, 32}
#define CMUI_PWM_6_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4a04, 0, 32}
#define CMUI_PWM_6_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4a08, 0, 32}
#define CMUI_PWM_6_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4a44, 0, 32}
#define CMUI_PWM_6_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4a48, 0, 32}
#define CMUI_PWM_6_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x4a4c, 0, 32}
#define CMUI_PWM_6_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4a50, 0, 32}
#define CMUI_PWM_6_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x4a0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_6_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_6_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_6_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_6_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_6_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_6_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_6_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_6_APB_clk_enb			{0,0,0,0}
/* PWM[7] */
/* TCLK  */
#define CMUI_PWM_7_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4c00, 0, 32}
#define CMUI_PWM_7_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4c04, 0, 32}
#define CMUI_PWM_7_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4c08, 0, 32}
#define CMUI_PWM_7_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4c44, 0, 32}
#define CMUI_PWM_7_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4c48, 0, 32}
#define CMUI_PWM_7_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x4c4c, 0, 32}
#define CMUI_PWM_7_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4c50, 0, 32}
#define CMUI_PWM_7_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x4c0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_7_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_7_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_7_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_7_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_7_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_7_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_7_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_7_APB_clk_enb			{0,0,0,0}
/* PWM[8] */
/* TCLK  */
#define CMUI_PWM_8_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x4e00, 0, 32}
#define CMUI_PWM_8_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x4e04, 0, 32}
#define CMUI_PWM_8_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x4e08, 0, 32}
#define CMUI_PWM_8_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x4e44, 0, 32}
#define CMUI_PWM_8_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x4e48, 0, 32}
#define CMUI_PWM_8_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x4e4c, 0, 32}
#define CMUI_PWM_8_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x4e50, 0, 32}
#define CMUI_PWM_8_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x4e0c, 0, 1}
/* APB  */
#define CMUI_PWM_8_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_8_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_8_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_8_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_8_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_8_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_8_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_8_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 10, 1}
/* PWM[9] */
/* TCLK  */
#define CMUI_PWM_9_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5000, 0, 32}
#define CMUI_PWM_9_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5004, 0, 32}
#define CMUI_PWM_9_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5008, 0, 32}
#define CMUI_PWM_9_TCLK_div_rst			{&SFR_INFO.CMU_SYS[0], 0x5044, 0, 32}
#define CMUI_PWM_9_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5048, 0, 32}
#define CMUI_PWM_9_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x504c, 0, 32}
#define CMUI_PWM_9_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5050, 0, 32}
#define CMUI_PWM_9_TCLK_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x500c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_9_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_9_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_9_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_9_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_9_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_9_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_9_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_9_APB_clk_enb			{0,0,0,0}
/* PWM[10] */
/* TCLK  */
#define CMUI_PWM_10_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5200, 0, 32}
#define CMUI_PWM_10_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5204, 0, 32}
#define CMUI_PWM_10_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5208, 0, 32}
#define CMUI_PWM_10_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5244, 0, 32}
#define CMUI_PWM_10_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5248, 0, 32}
#define CMUI_PWM_10_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x524c, 0, 32}
#define CMUI_PWM_10_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5250, 0, 32}
#define CMUI_PWM_10_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x520c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_10_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_10_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_10_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_10_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_10_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_10_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_10_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_10_APB_clk_enb			{0,0,0,0}
/* PWM[11] */
/* TCLK  */
#define CMUI_PWM_11_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5400, 0, 32}
#define CMUI_PWM_11_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5404, 0, 32}
#define CMUI_PWM_11_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5408, 0, 32}
#define CMUI_PWM_11_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5444, 0, 32}
#define CMUI_PWM_11_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5448, 0, 32}
#define CMUI_PWM_11_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x544c, 0, 32}
#define CMUI_PWM_11_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5450, 0, 32}
#define CMUI_PWM_11_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x540c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_11_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_11_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_11_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_11_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_11_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_11_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_11_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_11_APB_clk_enb			{0,0,0,0}
/* PWM[12] */
/* TCLK  */
#define CMUI_PWM_12_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5600, 0, 32}
#define CMUI_PWM_12_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5604, 0, 32}
#define CMUI_PWM_12_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5608, 0, 32}
#define CMUI_PWM_12_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5644, 0, 32}
#define CMUI_PWM_12_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5648, 0, 32}
#define CMUI_PWM_12_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x564c, 0, 32}
#define CMUI_PWM_12_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5650, 0, 32}
#define CMUI_PWM_12_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x560c, 0, 1}
/* APB  */
#define CMUI_PWM_12_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_12_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_12_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_12_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_12_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_12_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_12_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_12_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 11, 1}
/* PWM[13] */
/* TCLK  */
#define CMUI_PWM_13_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5800, 0, 32}
#define CMUI_PWM_13_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5804, 0, 32}
#define CMUI_PWM_13_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5808, 0, 32}
#define CMUI_PWM_13_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5844, 0, 32}
#define CMUI_PWM_13_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5848, 0, 32}
#define CMUI_PWM_13_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x584c, 0, 32}
#define CMUI_PWM_13_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5850, 0, 32}
#define CMUI_PWM_13_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x580c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_13_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_13_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_13_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_13_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_13_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_13_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_13_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_13_APB_clk_enb			{0,0,0,0}
/* PWM[14] */
/* TCLK  */
#define CMUI_PWM_14_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5a00, 0, 32}
#define CMUI_PWM_14_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5a04, 0, 32}
#define CMUI_PWM_14_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5a08, 0, 32}
#define CMUI_PWM_14_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5a44, 0, 32}
#define CMUI_PWM_14_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5a48, 0, 32}
#define CMUI_PWM_14_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x5a4c, 0, 32}
#define CMUI_PWM_14_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5a50, 0, 32}
#define CMUI_PWM_14_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x5a0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_14_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_14_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_14_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_14_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_14_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_14_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_14_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_14_APB_clk_enb			{0,0,0,0}
/* PWM[15] */
/* TCLK  */
#define CMUI_PWM_15_TCLK_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5c00, 0, 32}
#define CMUI_PWM_15_TCLK_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5c04, 0, 32}
#define CMUI_PWM_15_TCLK_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5c08, 0, 32}
#define CMUI_PWM_15_TCLK_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5c44, 0, 32}
#define CMUI_PWM_15_TCLK_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5c48, 0, 32}
#define CMUI_PWM_15_TCLK_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x5c4c, 0, 32}
#define CMUI_PWM_15_TCLK_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5c50, 0, 32}
#define CMUI_PWM_15_TCLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x5c0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PWM_15_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PWM_15_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PWM_15_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PWM_15_APB_div_rst			{0,0,0,0}
#define CMUI_PWM_15_APB_dy_div_val		{0,0,0,0}
#define CMUI_PWM_15_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PWM_15_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PWM_15_APB_clk_enb			{0,0,0,0}
/* PO */
/* PO[0] */
/* OUT  */
#define CMUI_PO_0_OUT_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x5e00, 0, 32}
#define CMUI_PO_0_OUT_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x5e04, 0, 32}
#define CMUI_PO_0_OUT_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x5e08, 0, 32}
#define CMUI_PO_0_OUT_div_rst			{&SFR_INFO.CMU_SYS[0], 0x5e44, 0, 32}
#define CMUI_PO_0_OUT_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x5e48, 0, 32}
#define CMUI_PO_0_OUT_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x5e4c, 0, 32}
#define CMUI_PO_0_OUT_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x5e50, 0, 32}
#define CMUI_PO_0_OUT_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x5e0c, 0, 1}
/* PO[1] */
/* OUT  */
#define CMUI_PO_1_OUT_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6000, 0, 32}
#define CMUI_PO_1_OUT_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6004, 0, 32}
#define CMUI_PO_1_OUT_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x6008, 0, 32}
#define CMUI_PO_1_OUT_div_rst			{&SFR_INFO.CMU_SYS[0], 0x6044, 0, 32}
#define CMUI_PO_1_OUT_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6048, 0, 32}
#define CMUI_PO_1_OUT_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x604c, 0, 32}
#define CMUI_PO_1_OUT_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x6050, 0, 32}
#define CMUI_PO_1_OUT_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x600c, 0, 1}
/* PO[2] */
/* OUT  */
#define CMUI_PO_2_OUT_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6200, 0, 32}
#define CMUI_PO_2_OUT_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6204, 0, 32}
#define CMUI_PO_2_OUT_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x6208, 0, 32}
#define CMUI_PO_2_OUT_div_rst			{&SFR_INFO.CMU_SYS[0], 0x6244, 0, 32}
#define CMUI_PO_2_OUT_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6248, 0, 32}
#define CMUI_PO_2_OUT_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x624c, 0, 32}
#define CMUI_PO_2_OUT_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x6250, 0, 32}
#define CMUI_PO_2_OUT_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x620c, 0, 1}
/* PO[3] */
/* OUT  */
#define CMUI_PO_3_OUT_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6400, 0, 32}
#define CMUI_PO_3_OUT_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6404, 0, 32}
#define CMUI_PO_3_OUT_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x6408, 0, 32}
#define CMUI_PO_3_OUT_div_rst			{&SFR_INFO.CMU_SYS[0], 0x6444, 0, 32}
#define CMUI_PO_3_OUT_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6448, 0, 32}
#define CMUI_PO_3_OUT_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x644c, 0, 32}
#define CMUI_PO_3_OUT_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x6450, 0, 32}
#define CMUI_PO_3_OUT_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x640c, 0, 1}
/* PO[4] */
/* OUT  */
#define CMUI_PO_4_OUT_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6600, 0, 32}
#define CMUI_PO_4_OUT_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6604, 0, 32}
#define CMUI_PO_4_OUT_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x6608, 0, 32}
#define CMUI_PO_4_OUT_div_rst			{&SFR_INFO.CMU_SYS[0], 0x6644, 0, 32}
#define CMUI_PO_4_OUT_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6648, 0, 32}
#define CMUI_PO_4_OUT_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x664c, 0, 32}
#define CMUI_PO_4_OUT_dy_div_busy_st		{&SFR_INFO.CMU_SYS[0], 0x6650, 0, 32}
#define CMUI_PO_4_OUT_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x660c, 0, 1}
/* PPM */
/* PPM[0] */
/* PPMCLK  */
#define CMUI_PPM_0_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x400, 0, 32}
#define CMUI_PPM_0_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x404, 0, 32}
#define CMUI_PPM_0_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x408, 0, 32}
#define CMUI_PPM_0_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x444, 0, 32}
#define CMUI_PPM_0_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x448, 0, 32}
#define CMUI_PPM_0_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x44c, 0, 32}
#define CMUI_PPM_0_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x450, 0, 32}
#define CMUI_PPM_0_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x40c, 0, 1}
/* APB  */
#define CMUI_PPM_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_0_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_0_APB_clk_enb			{&SFR_INFO.CMU_PERICLK[0], 0x20c, 1, 1}
/* PPM[1] */
/* PPMCLK  */
#define CMUI_PPM_1_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x600, 0, 32}
#define CMUI_PPM_1_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x604, 0, 32}
#define CMUI_PPM_1_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x608, 0, 32}
#define CMUI_PPM_1_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x644, 0, 32}
#define CMUI_PPM_1_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x648, 0, 32}
#define CMUI_PPM_1_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x64c, 0, 32}
#define CMUI_PPM_1_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x650, 0, 32}
#define CMUI_PPM_1_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x60c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_1_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_1_APB_clk_enb			{0,0,0,0}
/* PPM[2] */
/* PPMCLK  */
#define CMUI_PPM_2_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x800, 0, 32}
#define CMUI_PPM_2_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x804, 0, 32}
#define CMUI_PPM_2_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x808, 0, 32}
#define CMUI_PPM_2_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x844, 0, 32}
#define CMUI_PPM_2_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x848, 0, 32}
#define CMUI_PPM_2_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x84c, 0, 32}
#define CMUI_PPM_2_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x850, 0, 32}
#define CMUI_PPM_2_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x80c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_2_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_2_APB_clk_enb			{0,0,0,0}
/* PPM[3] */
/* PPMCLK  */
#define CMUI_PPM_3_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0xa00, 0, 32}
#define CMUI_PPM_3_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xa04, 0, 32}
#define CMUI_PPM_3_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0xa08, 0, 32}
#define CMUI_PPM_3_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xa44, 0, 32}
#define CMUI_PPM_3_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0xa48, 0, 32}
#define CMUI_PPM_3_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0xa4c, 0, 32}
#define CMUI_PPM_3_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0xa50, 0, 32}
#define CMUI_PPM_3_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0xa0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_3_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_3_APB_clk_enb			{0,0,0,0}
/* PPM[4] */
/* PPMCLK  */
#define CMUI_PPM_4_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0xc00, 0, 32}
#define CMUI_PPM_4_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xc04, 0, 32}
#define CMUI_PPM_4_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0xc08, 0, 32}
#define CMUI_PPM_4_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xc44, 0, 32}
#define CMUI_PPM_4_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0xc48, 0, 32}
#define CMUI_PPM_4_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0xc4c, 0, 32}
#define CMUI_PPM_4_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0xc50, 0, 32}
#define CMUI_PPM_4_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0xc0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_4_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_4_APB_clk_enb			{0,0,0,0}
/* PPM[5] */
/* PPMCLK  */
#define CMUI_PPM_5_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0xe00, 0, 32}
#define CMUI_PPM_5_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xe04, 0, 32}
#define CMUI_PPM_5_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0xe08, 0, 32}
#define CMUI_PPM_5_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0xe44, 0, 32}
#define CMUI_PPM_5_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0xe48, 0, 32}
#define CMUI_PPM_5_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0xe4c, 0, 32}
#define CMUI_PPM_5_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0xe50, 0, 32}
#define CMUI_PPM_5_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0xe0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_5_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_5_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_5_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_5_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_5_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_5_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_5_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_5_APB_clk_enb			{0,0,0,0}
/* PPM[6] */
/* PPMCLK  */
#define CMUI_PPM_6_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1000, 0, 32}
#define CMUI_PPM_6_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1004, 0, 32}
#define CMUI_PPM_6_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x1008, 0, 32}
#define CMUI_PPM_6_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1044, 0, 32}
#define CMUI_PPM_6_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1048, 0, 32}
#define CMUI_PPM_6_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x104c, 0, 32}
#define CMUI_PPM_6_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1050, 0, 32}
#define CMUI_PPM_6_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x100c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_6_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_6_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_6_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_6_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_6_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_6_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_6_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_6_APB_clk_enb			{0,0,0,0}
/* PPM[7] */
/* PPMCLK  */
#define CMUI_PPM_7_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1200, 0, 32}
#define CMUI_PPM_7_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1204, 0, 32}
#define CMUI_PPM_7_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x1208, 0, 32}
#define CMUI_PPM_7_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1244, 0, 32}
#define CMUI_PPM_7_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1248, 0, 32}
#define CMUI_PPM_7_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x124c, 0, 32}
#define CMUI_PPM_7_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1250, 0, 32}
#define CMUI_PPM_7_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x120c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_7_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_7_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_7_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_7_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_7_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_7_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_7_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_7_APB_clk_enb			{0,0,0,0}
/* PPM[8] */
/* PPMCLK  */
#define CMUI_PPM_8_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1400, 0, 32}
#define CMUI_PPM_8_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1404, 0, 32}
#define CMUI_PPM_8_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x1408, 0, 32}
#define CMUI_PPM_8_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1444, 0, 32}
#define CMUI_PPM_8_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1448, 0, 32}
#define CMUI_PPM_8_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x144c, 0, 32}
#define CMUI_PPM_8_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1450, 0, 32}
#define CMUI_PPM_8_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x140c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_8_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_8_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_8_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_8_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_8_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_8_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_8_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_8_APB_clk_enb			{0,0,0,0}
/* PPM[9] */
/* PPMCLK  */
#define CMUI_PPM_9_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1600, 0, 32}
#define CMUI_PPM_9_PPMCLK_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1604, 0, 32}
#define CMUI_PPM_9_PPMCLK_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x1608, 0, 32}
#define CMUI_PPM_9_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1644, 0, 32}
#define CMUI_PPM_9_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1648, 0, 32}
#define CMUI_PPM_9_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x164c, 0, 32}
#define CMUI_PPM_9_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1650, 0, 32}
#define CMUI_PPM_9_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x160c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_9_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_9_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_9_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_9_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_9_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_9_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_9_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_9_APB_clk_enb			{0,0,0,0}
/* PPM[10] */
/* PPMCLK  */
#define CMUI_PPM_10_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1800, 0, 32}
#define CMUI_PPM_10_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x1804, 0, 32}
#define CMUI_PPM_10_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x1808, 0, 32}
#define CMUI_PPM_10_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1844, 0, 32}
#define CMUI_PPM_10_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1848, 0, 32}
#define CMUI_PPM_10_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x184c, 0, 32}
#define CMUI_PPM_10_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1850, 0, 32}
#define CMUI_PPM_10_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x180c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_10_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_10_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_10_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_10_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_10_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_10_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_10_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_10_APB_clk_enb			{0,0,0,0}
/* PPM[11] */
/* PPMCLK  */
#define CMUI_PPM_11_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1a00, 0, 32}
#define CMUI_PPM_11_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x1a04, 0, 32}
#define CMUI_PPM_11_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x1a08, 0, 32}
#define CMUI_PPM_11_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1a44, 0, 32}
#define CMUI_PPM_11_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1a48, 0, 32}
#define CMUI_PPM_11_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x1a4c, 0, 32}
#define CMUI_PPM_11_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1a50, 0, 32}
#define CMUI_PPM_11_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x1a0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_11_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_11_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_11_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_11_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_11_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_11_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_11_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_11_APB_clk_enb			{0,0,0,0}
/* PPM[12] */
/* PPMCLK  */
#define CMUI_PPM_12_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1c00, 0, 32}
#define CMUI_PPM_12_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x1c04, 0, 32}
#define CMUI_PPM_12_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x1c08, 0, 32}
#define CMUI_PPM_12_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1c44, 0, 32}
#define CMUI_PPM_12_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1c48, 0, 32}
#define CMUI_PPM_12_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x1c4c, 0, 32}
#define CMUI_PPM_12_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1c50, 0, 32}
#define CMUI_PPM_12_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x1c0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_12_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_12_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_12_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_12_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_12_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_12_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_12_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_12_APB_clk_enb			{0,0,0,0}
/* PPM[13] */
/* PPMCLK  */
#define CMUI_PPM_13_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x1e00, 0, 32}
#define CMUI_PPM_13_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x1e04, 0, 32}
#define CMUI_PPM_13_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x1e08, 0, 32}
#define CMUI_PPM_13_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x1e44, 0, 32}
#define CMUI_PPM_13_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x1e48, 0, 32}
#define CMUI_PPM_13_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x1e4c, 0, 32}
#define CMUI_PPM_13_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x1e50, 0, 32}
#define CMUI_PPM_13_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x1e0c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_13_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_13_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_13_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_13_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_13_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_13_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_13_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_13_APB_clk_enb			{0,0,0,0}
/* PPM[14] */
/* PPMCLK  */
#define CMUI_PPM_14_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x2000, 0, 32}
#define CMUI_PPM_14_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x2004, 0, 32}
#define CMUI_PPM_14_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x2008, 0, 32}
#define CMUI_PPM_14_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x2044, 0, 32}
#define CMUI_PPM_14_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x2048, 0, 32}
#define CMUI_PPM_14_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x204c, 0, 32}
#define CMUI_PPM_14_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x2050, 0, 32}
#define CMUI_PPM_14_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x200c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_14_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_14_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_14_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_14_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_14_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_14_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_14_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_14_APB_clk_enb			{0,0,0,0}
/* PPM[15] */
/* PPMCLK  */
#define CMUI_PPM_15_PPMCLK_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x2200, 0, 32}
#define CMUI_PPM_15_PPMCLK_grp_a_div_rst	{&SFR_INFO.CMU_PERICLK[0], 0x2204, 0, 32}
#define CMUI_PPM_15_PPMCLK_grp_gate_mode	{&SFR_INFO.CMU_PERICLK[0], 0x2208, 0, 32}
#define CMUI_PPM_15_PPMCLK_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x2244, 0, 32}
#define CMUI_PPM_15_PPMCLK_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x2248, 0, 32}
#define CMUI_PPM_15_PPMCLK_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x224c, 0, 32}
#define CMUI_PPM_15_PPMCLK_dy_div_busy_st	{&SFR_INFO.CMU_PERICLK[0], 0x2250, 0, 32}
#define CMUI_PPM_15_PPMCLK_clk_enb		{&SFR_INFO.CMU_PERICLK[0], 0x220c, 0, 1}
/* APB :not_using_div */
#define CMUI_PPM_15_APB_grp_clk_src		{0,0,0,0}
#define CMUI_PPM_15_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_PPM_15_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_PPM_15_APB_div_rst			{0,0,0,0}
#define CMUI_PPM_15_APB_dy_div_val		{0,0,0,0}
#define CMUI_PPM_15_APB_dy_div_stop		{0,0,0,0}
#define CMUI_PPM_15_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_PPM_15_APB_clk_enb			{0,0,0,0}
/* DPC */
/* DPC[0] */
/* X2  */
#define CMUI_DPC_0_X2_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x400, 0, 32}
#define CMUI_DPC_0_X2_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x404, 0, 32}
#define CMUI_DPC_0_X2_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x408, 0, 32}
#define CMUI_DPC_0_X2_div_rst			{&SFR_INFO.CMU_DISP[0], 0x444, 0, 32}
#define CMUI_DPC_0_X2_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x448, 0, 32}
#define CMUI_DPC_0_X2_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x44c, 0, 32}
#define CMUI_DPC_0_X2_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x450, 0, 32}
#define CMUI_DPC_0_X2_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x40c, 0, 1}
/* X1  */
#define CMUI_DPC_0_X1_grp_clk_src		{0,0,0,0}
#define CMUI_DPC_0_X1_grp_a_div_rst		{0,0,0,0}
#define CMUI_DPC_0_X1_grp_gate_mode		{0,0,0,0}
#define CMUI_DPC_0_X1_div_rst			{&SFR_INFO.CMU_DISP[0], 0x484, 0, 32}
#define CMUI_DPC_0_X1_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x488, 0, 32}
#define CMUI_DPC_0_X1_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x48c, 0, 32}
#define CMUI_DPC_0_X1_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x490, 0, 32}
#define CMUI_DPC_0_X1_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x40c, 1, 1}
/* AXI  */
#define CMUI_DPC_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DPC_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DPC_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DPC_0_AXI_div_rst			{0,0,0,0}
#define CMUI_DPC_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DPC_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DPC_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DPC_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 3, 1}
/* DPC[1] */
/* X2  */
#define CMUI_DPC_1_X2_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x600, 0, 32}
#define CMUI_DPC_1_X2_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x604, 0, 32}
#define CMUI_DPC_1_X2_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x608, 0, 32}
#define CMUI_DPC_1_X2_div_rst			{&SFR_INFO.CMU_DISP[0], 0x644, 0, 32}
#define CMUI_DPC_1_X2_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x648, 0, 32}
#define CMUI_DPC_1_X2_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x64c, 0, 32}
#define CMUI_DPC_1_X2_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x650, 0, 32}
#define CMUI_DPC_1_X2_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x60c, 0, 1}
/* X1  */
#define CMUI_DPC_1_X1_grp_clk_src		{0,0,0,0}
#define CMUI_DPC_1_X1_grp_a_div_rst		{0,0,0,0}
#define CMUI_DPC_1_X1_grp_gate_mode		{0,0,0,0}
#define CMUI_DPC_1_X1_div_rst			{&SFR_INFO.CMU_DISP[0], 0x684, 0, 32}
#define CMUI_DPC_1_X1_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x688, 0, 32}
#define CMUI_DPC_1_X1_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x68c, 0, 32}
#define CMUI_DPC_1_X1_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x690, 0, 32}
#define CMUI_DPC_1_X1_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x60c, 1, 1}
/* AXI  */
#define CMUI_DPC_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DPC_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DPC_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DPC_1_AXI_div_rst			{0,0,0,0}
#define CMUI_DPC_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DPC_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DPC_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DPC_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 4, 1}
/* MIPI */
/* MIPI[0] */
/* X2  */
#define CMUI_MIPI_0_X2_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x800, 0, 32}
#define CMUI_MIPI_0_X2_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x804, 0, 32}
#define CMUI_MIPI_0_X2_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x808, 0, 32}
#define CMUI_MIPI_0_X2_div_rst			{&SFR_INFO.CMU_DISP[0], 0x844, 0, 32}
#define CMUI_MIPI_0_X2_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x848, 0, 32}
#define CMUI_MIPI_0_X2_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x84c, 0, 32}
#define CMUI_MIPI_0_X2_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x850, 0, 32}
#define CMUI_MIPI_0_X2_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x80c, 0, 1}
/* X1  */
#define CMUI_MIPI_0_X1_grp_clk_src		{0,0,0,0}
#define CMUI_MIPI_0_X1_grp_a_div_rst		{0,0,0,0}
#define CMUI_MIPI_0_X1_grp_gate_mode		{0,0,0,0}
#define CMUI_MIPI_0_X1_div_rst			{&SFR_INFO.CMU_DISP[0], 0x884, 0, 32}
#define CMUI_MIPI_0_X1_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x888, 0, 32}
#define CMUI_MIPI_0_X1_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x88c, 0, 32}
#define CMUI_MIPI_0_X1_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x890, 0, 32}
#define CMUI_MIPI_0_X1_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x80c, 1, 1}
/* CSI  */
#define CMUI_MIPI_0_CSI_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0xa00, 0, 32}
#define CMUI_MIPI_0_CSI_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0xa04, 0, 32}
#define CMUI_MIPI_0_CSI_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0xa08, 0, 32}
#define CMUI_MIPI_0_CSI_div_rst			{&SFR_INFO.CMU_DISP[0], 0xa44, 0, 32}
#define CMUI_MIPI_0_CSI_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0xa48, 0, 32}
#define CMUI_MIPI_0_CSI_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0xa4c, 0, 32}
#define CMUI_MIPI_0_CSI_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0xa50, 0, 32}
#define CMUI_MIPI_0_CSI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0xa0c, 0, 1}
/* AXI  */
#define CMUI_MIPI_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_MIPI_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_MIPI_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_MIPI_0_AXI_div_rst			{0,0,0,0}
#define CMUI_MIPI_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MIPI_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_MIPI_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_MIPI_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 1, 1}
/* APBCSI  */
#define CMUI_MIPI_0_APBCSI_grp_clk_src		{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_grp_gate_mode	{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_div_rst		{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_dy_div_val		{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_dy_div_stop		{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MIPI_0_APBCSI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 28, 1}
/* APBDSI  */
#define CMUI_MIPI_0_APBDSI_grp_clk_src		{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_grp_gate_mode	{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_div_rst		{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_dy_div_val		{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_dy_div_stop		{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MIPI_0_APBDSI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 29, 1}
/* CSIPHY  */
#define CMUI_MIPI_0_CSIPHY_grp_clk_src		{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_grp_a_div_rst	{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_grp_gate_mode	{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_div_rst		{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_dy_div_val		{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_dy_div_stop		{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_dy_div_busy_st	{0,0,0,0}
#define CMUI_MIPI_0_CSIPHY_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 30, 1}
/* LVDS */
/* LVDS[0] */
/* VCLK  */
#define CMUI_LVDS_0_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0xc00, 0, 32}
#define CMUI_LVDS_0_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0xc04, 0, 32}
#define CMUI_LVDS_0_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0xc08, 0, 32}
#define CMUI_LVDS_0_VCLK_div_rst		{&SFR_INFO.CMU_DISP[0], 0xc44, 0, 32}
#define CMUI_LVDS_0_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0xc48, 0, 32}
#define CMUI_LVDS_0_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0xc4c, 0, 32}
#define CMUI_LVDS_0_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0xc50, 0, 32}
#define CMUI_LVDS_0_VCLK_clk_enb		{&SFR_INFO.CMU_DISP[0], 0xc0c, 0, 1}
/* AXI  */
#define CMUI_LVDS_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_LVDS_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_LVDS_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_LVDS_0_AXI_div_rst			{0,0,0,0}
#define CMUI_LVDS_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_LVDS_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_LVDS_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_LVDS_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 5, 1}
/* PHY  */
#define CMUI_LVDS_0_PHY_grp_clk_src		{0,0,0,0}
#define CMUI_LVDS_0_PHY_grp_a_div_rst		{0,0,0,0}
#define CMUI_LVDS_0_PHY_grp_gate_mode		{0,0,0,0}
#define CMUI_LVDS_0_PHY_div_rst			{0,0,0,0}
#define CMUI_LVDS_0_PHY_dy_div_val		{0,0,0,0}
#define CMUI_LVDS_0_PHY_dy_div_stop		{0,0,0,0}
#define CMUI_LVDS_0_PHY_dy_div_busy_st		{0,0,0,0}
#define CMUI_LVDS_0_PHY_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 6, 1}
/* LVDS[1] */
/* VCLK  */
#define CMUI_LVDS_1_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0xe00, 0, 32}
#define CMUI_LVDS_1_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0xe04, 0, 32}
#define CMUI_LVDS_1_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0xe08, 0, 32}
#define CMUI_LVDS_1_VCLK_div_rst		{&SFR_INFO.CMU_DISP[0], 0xe44, 0, 32}
#define CMUI_LVDS_1_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0xe48, 0, 32}
#define CMUI_LVDS_1_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0xe4c, 0, 32}
#define CMUI_LVDS_1_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0xe50, 0, 32}
#define CMUI_LVDS_1_VCLK_clk_enb		{&SFR_INFO.CMU_DISP[0], 0xe0c, 0, 1}
/* AXI  */
#define CMUI_LVDS_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_LVDS_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_LVDS_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_LVDS_1_AXI_div_rst			{0,0,0,0}
#define CMUI_LVDS_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_LVDS_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_LVDS_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_LVDS_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 7, 1}
/* PHY  */
#define CMUI_LVDS_1_PHY_grp_clk_src		{0,0,0,0}
#define CMUI_LVDS_1_PHY_grp_a_div_rst		{0,0,0,0}
#define CMUI_LVDS_1_PHY_grp_gate_mode		{0,0,0,0}
#define CMUI_LVDS_1_PHY_div_rst			{0,0,0,0}
#define CMUI_LVDS_1_PHY_dy_div_val		{0,0,0,0}
#define CMUI_LVDS_1_PHY_dy_div_stop		{0,0,0,0}
#define CMUI_LVDS_1_PHY_dy_div_busy_st		{0,0,0,0}
#define CMUI_LVDS_1_PHY_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 8, 1}
/* VIP */
/* VIP[0] */
/* VCLK  */
#define CMUI_VIP_0_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1000, 0, 32}
#define CMUI_VIP_0_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1004, 0, 32}
#define CMUI_VIP_0_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x1008, 0, 32}
#define CMUI_VIP_0_VCLK_div_rst			{&SFR_INFO.CMU_DISP[0], 0x1044, 0, 32}
#define CMUI_VIP_0_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1048, 0, 32}
#define CMUI_VIP_0_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x104c, 0, 32}
#define CMUI_VIP_0_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x1050, 0, 32}
#define CMUI_VIP_0_VCLK_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x100c, 0, 1}
/* AXI  */
#define CMUI_VIP_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_VIP_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_VIP_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_VIP_0_AXI_div_rst			{0,0,0,0}
#define CMUI_VIP_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_VIP_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_VIP_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 17, 1}
/* VIP[1] */
/* VCLK  */
#define CMUI_VIP_1_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1200, 0, 32}
#define CMUI_VIP_1_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1204, 0, 32}
#define CMUI_VIP_1_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x1208, 0, 32}
#define CMUI_VIP_1_VCLK_div_rst			{&SFR_INFO.CMU_DISP[0], 0x1244, 0, 32}
#define CMUI_VIP_1_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1248, 0, 32}
#define CMUI_VIP_1_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x124c, 0, 32}
#define CMUI_VIP_1_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x1250, 0, 32}
#define CMUI_VIP_1_VCLK_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x120c, 0, 1}
/* AXI  */
#define CMUI_VIP_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_VIP_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_VIP_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_VIP_1_AXI_div_rst			{0,0,0,0}
#define CMUI_VIP_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_VIP_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_VIP_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 18, 1}
/* VIP[2] */
/* VCLK  */
#define CMUI_VIP_2_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1400, 0, 32}
#define CMUI_VIP_2_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1404, 0, 32}
#define CMUI_VIP_2_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x1408, 0, 32}
#define CMUI_VIP_2_VCLK_div_rst			{&SFR_INFO.CMU_DISP[0], 0x1444, 0, 32}
#define CMUI_VIP_2_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1448, 0, 32}
#define CMUI_VIP_2_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x144c, 0, 32}
#define CMUI_VIP_2_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x1450, 0, 32}
#define CMUI_VIP_2_VCLK_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x140c, 0, 1}
/* AXI  */
#define CMUI_VIP_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_VIP_2_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_VIP_2_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_VIP_2_AXI_div_rst			{0,0,0,0}
#define CMUI_VIP_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_VIP_2_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_VIP_2_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 19, 1}
/* VIP[3] */
/* VCLK  */
#define CMUI_VIP_3_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1600, 0, 32}
#define CMUI_VIP_3_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1604, 0, 32}
#define CMUI_VIP_3_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x1608, 0, 32}
#define CMUI_VIP_3_VCLK_div_rst			{&SFR_INFO.CMU_DISP[0], 0x1644, 0, 32}
#define CMUI_VIP_3_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1648, 0, 32}
#define CMUI_VIP_3_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x164c, 0, 32}
#define CMUI_VIP_3_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x1650, 0, 32}
#define CMUI_VIP_3_VCLK_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x160c, 0, 1}
/* AXI  */
#define CMUI_VIP_3_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_VIP_3_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_VIP_3_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_VIP_3_AXI_div_rst			{0,0,0,0}
#define CMUI_VIP_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_3_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_VIP_3_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_VIP_3_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 20, 1}
/* DEINTERLACE */
/* DEINTERLACE[0] */
/* AXI  */
#define CMUI_DEINTERLACE_0_AXI_grp_clk_src	{&SFR_INFO.CMU_DISP[0], 0x1800, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_grp_a_div_rst	{&SFR_INFO.CMU_DISP[0], 0x1804, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_grp_gate_mode	{&SFR_INFO.CMU_DISP[0], 0x1808, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1844, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_dy_div_val	{&SFR_INFO.CMU_DISP[0], 0x1848, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_dy_div_stop	{&SFR_INFO.CMU_DISP[0], 0x184c, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_DISP[0], 0x1850, 0, 32}
#define CMUI_DEINTERLACE_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x180c, 0, 1}
/* APB  */
#define CMUI_DEINTERLACE_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_div_rst		{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_DEINTERLACE_0_APB_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 24, 1}
/* MAPCONV */
/* MAPCONV[0] */
/* AXI  */
#define CMUI_MAPCONV_0_AXI_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1a00, 0, 32}
#define CMUI_MAPCONV_0_AXI_grp_a_div_rst	{&SFR_INFO.CMU_DISP[0], 0x1a04, 0, 32}
#define CMUI_MAPCONV_0_AXI_grp_gate_mode	{&SFR_INFO.CMU_DISP[0], 0x1a08, 0, 32}
#define CMUI_MAPCONV_0_AXI_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1a44, 0, 32}
#define CMUI_MAPCONV_0_AXI_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1a48, 0, 32}
#define CMUI_MAPCONV_0_AXI_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x1a4c, 0, 32}
#define CMUI_MAPCONV_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_DISP[0], 0x1a50, 0, 32}
#define CMUI_MAPCONV_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x1a0c, 0, 1}
/* HDMIV2 */
/* HDMIV2[0] */
/* TMDS_10B  */
#define CMUI_HDMIV2_0_TMDS_10B_grp_clk_src	{&SFR_INFO.CMU_HDMI[0], 0x400, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_grp_a_div_rst	{&SFR_INFO.CMU_HDMI[0], 0x404, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_grp_gate_mode	{&SFR_INFO.CMU_HDMI[0], 0x408, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x444, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_dy_div_val	{&SFR_INFO.CMU_HDMI[0], 0x448, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_dy_div_stop	{&SFR_INFO.CMU_HDMI[0], 0x44c, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_dy_div_busy_st	{&SFR_INFO.CMU_HDMI[0], 0x450, 0, 32}
#define CMUI_HDMIV2_0_TMDS_10B_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x40c, 0, 1}
/* TMDS_20B  */
#define CMUI_HDMIV2_0_TMDS_20B_grp_clk_src	{0,0,0,0}
#define CMUI_HDMIV2_0_TMDS_20B_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMIV2_0_TMDS_20B_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMIV2_0_TMDS_20B_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x484, 0, 32}
#define CMUI_HDMIV2_0_TMDS_20B_dy_div_val	{&SFR_INFO.CMU_HDMI[0], 0x488, 0, 32}
#define CMUI_HDMIV2_0_TMDS_20B_dy_div_stop	{&SFR_INFO.CMU_HDMI[0], 0x48c, 0, 32}
#define CMUI_HDMIV2_0_TMDS_20B_dy_div_busy_st	{&SFR_INFO.CMU_HDMI[0], 0x490, 0, 32}
#define CMUI_HDMIV2_0_TMDS_20B_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x40c, 1, 1}
/* PIXELX2  */
#define CMUI_HDMIV2_0_PIXELX2_grp_clk_src	{&SFR_INFO.CMU_HDMI[0], 0x600, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_grp_a_div_rst	{&SFR_INFO.CMU_HDMI[0], 0x604, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_grp_gate_mode	{&SFR_INFO.CMU_HDMI[0], 0x608, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x644, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_dy_div_val	{&SFR_INFO.CMU_HDMI[0], 0x648, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_dy_div_stop	{&SFR_INFO.CMU_HDMI[0], 0x64c, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_dy_div_busy_st	{&SFR_INFO.CMU_HDMI[0], 0x650, 0, 32}
#define CMUI_HDMIV2_0_PIXELX2_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x60c, 0, 1}
/* PIXEL  */
#define CMUI_HDMIV2_0_PIXEL_grp_clk_src		{0,0,0,0}
#define CMUI_HDMIV2_0_PIXEL_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMIV2_0_PIXEL_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMIV2_0_PIXEL_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x684, 0, 32}
#define CMUI_HDMIV2_0_PIXEL_dy_div_val		{&SFR_INFO.CMU_HDMI[0], 0x688, 0, 32}
#define CMUI_HDMIV2_0_PIXEL_dy_div_stop		{&SFR_INFO.CMU_HDMI[0], 0x68c, 0, 32}
#define CMUI_HDMIV2_0_PIXEL_dy_div_busy_st	{&SFR_INFO.CMU_HDMI[0], 0x690, 0, 32}
#define CMUI_HDMIV2_0_PIXEL_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x60c, 1, 1}
/* AUDIO  */
#define CMUI_HDMIV2_0_AUDIO_grp_clk_src		{&SFR_INFO.CMU_HDMI[0], 0x800, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_grp_a_div_rst	{&SFR_INFO.CMU_HDMI[0], 0x804, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_grp_gate_mode	{&SFR_INFO.CMU_HDMI[0], 0x808, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_div_rst		{&SFR_INFO.CMU_HDMI[0], 0x844, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_dy_div_val		{&SFR_INFO.CMU_HDMI[0], 0x848, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_dy_div_stop		{&SFR_INFO.CMU_HDMI[0], 0x84c, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_dy_div_busy_st	{&SFR_INFO.CMU_HDMI[0], 0x850, 0, 32}
#define CMUI_HDMIV2_0_AUDIO_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x80c, 0, 1}
/* AXI  */
#define CMUI_HDMIV2_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIV2_0_AXI_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_HDMIV2_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_HDMIV2_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIV2_0_APB_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x20c, 3, 1}
/* APBPHY  */
#define CMUI_HDMIV2_0_APBPHY_grp_clk_src	{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_dy_div_val		{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_dy_div_stop	{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIV2_0_APBPHY_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x20c, 4, 1}
/* PHY  */
#define CMUI_HDMIV2_0_PHY_grp_clk_src		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_grp_a_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_grp_gate_mode		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_div_rst		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_dy_div_val		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_dy_div_stop		{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMIV2_0_PHY_clk_enb		{&SFR_INFO.CMU_HDMI[0], 0x20c, 5, 1}
/* CODA980 */
/* CODA980[0] */
/* CORE  */
#define CMUI_CODA980_0_CORE_grp_clk_src		{&SFR_INFO.CMU_CODA[0], 0x400, 0, 32}
#define CMUI_CODA980_0_CORE_grp_a_div_rst	{&SFR_INFO.CMU_CODA[0], 0x404, 0, 32}
#define CMUI_CODA980_0_CORE_grp_gate_mode	{&SFR_INFO.CMU_CODA[0], 0x408, 0, 32}
#define CMUI_CODA980_0_CORE_div_rst		{&SFR_INFO.CMU_CODA[0], 0x444, 0, 32}
#define CMUI_CODA980_0_CORE_dy_div_val		{&SFR_INFO.CMU_CODA[0], 0x448, 0, 32}
#define CMUI_CODA980_0_CORE_dy_div_stop		{&SFR_INFO.CMU_CODA[0], 0x44c, 0, 32}
#define CMUI_CODA980_0_CORE_dy_div_busy_st	{&SFR_INFO.CMU_CODA[0], 0x450, 0, 32}
#define CMUI_CODA980_0_CORE_clk_enb		{&SFR_INFO.CMU_CODA[0], 0x40c, 0, 1}
/* SRAM  */
#define CMUI_CODA980_0_SRAM_grp_clk_src		{0,0,0,0}
#define CMUI_CODA980_0_SRAM_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA980_0_SRAM_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA980_0_SRAM_div_rst		{&SFR_INFO.CMU_CODA[0], 0x484, 0, 32}
#define CMUI_CODA980_0_SRAM_dy_div_val		{&SFR_INFO.CMU_CODA[0], 0x488, 0, 32}
#define CMUI_CODA980_0_SRAM_dy_div_stop		{&SFR_INFO.CMU_CODA[0], 0x48c, 0, 32}
#define CMUI_CODA980_0_SRAM_dy_div_busy_st	{&SFR_INFO.CMU_CODA[0], 0x490, 0, 32}
#define CMUI_CODA980_0_SRAM_clk_enb		{&SFR_INFO.CMU_CODA[0], 0x40c, 1, 1}
/* AXI  */
#define CMUI_CODA980_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CODA980_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA980_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA980_0_AXI_div_rst		{0,0,0,0}
#define CMUI_CODA980_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CODA980_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CODA980_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA980_0_AXI_clk_enb		{&SFR_INFO.CMU_CODA[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_CODA980_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_CODA980_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA980_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA980_0_APB_div_rst		{0,0,0,0}
#define CMUI_CODA980_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_CODA980_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_CODA980_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA980_0_APB_clk_enb					{&SFR_INFO.CMU_CODA[0], 0x20c, 4, 1}
/* JPEG */
/* JPEG[0] */
/* CORE  */
#define CMUI_JPEG_0_CORE_grp_clk_src		{&SFR_INFO.CMU_CODA[0], 0x600, 0, 32}
#define CMUI_JPEG_0_CORE_grp_a_div_rst		{&SFR_INFO.CMU_CODA[0], 0x604, 0, 32}
#define CMUI_JPEG_0_CORE_grp_gate_mode		{&SFR_INFO.CMU_CODA[0], 0x608, 0, 32}
#define CMUI_JPEG_0_CORE_div_rst		{&SFR_INFO.CMU_CODA[0], 0x644, 0, 32}
#define CMUI_JPEG_0_CORE_dy_div_val		{&SFR_INFO.CMU_CODA[0], 0x648, 0, 32}
#define CMUI_JPEG_0_CORE_dy_div_stop		{&SFR_INFO.CMU_CODA[0], 0x64c, 0, 32}
#define CMUI_JPEG_0_CORE_dy_div_busy_st		{&SFR_INFO.CMU_CODA[0], 0x650, 0, 32}
#define CMUI_JPEG_0_CORE_clk_enb		{&SFR_INFO.CMU_CODA[0], 0x60c, 0, 1}
/* AXI  */
#define CMUI_JPEG_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_JPEG_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_JPEG_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_JPEG_0_AXI_div_rst			{0,0,0,0}
#define CMUI_JPEG_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_JPEG_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_JPEG_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_JPEG_0_AXI_clk_enb			{&SFR_INFO.CMU_CODA[0], 0x20c, 2, 1}
/* APB  */
#define CMUI_JPEG_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_JPEG_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_JPEG_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_JPEG_0_APB_div_rst			{0,0,0,0}
#define CMUI_JPEG_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_JPEG_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_JPEG_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_JPEG_0_APB_clk_enb			{&SFR_INFO.CMU_CODA[0], 0x20c, 5, 1}
/* OTG_SYS */
/* OTG_SYS[0] */
/* AHB  */
#define CMUI_OTG_SYS_0_AHB_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x400, 0, 32}
#define CMUI_OTG_SYS_0_AHB_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x404, 0, 32}
#define CMUI_OTG_SYS_0_AHB_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x408, 0, 32}
#define CMUI_OTG_SYS_0_AHB_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x444, 0, 32}
#define CMUI_OTG_SYS_0_AHB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x448, 0, 32}
#define CMUI_OTG_SYS_0_AHB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x44c, 0, 32}
#define CMUI_OTG_SYS_0_AHB_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x450, 0, 32}
#define CMUI_OTG_SYS_0_AHB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x40c, 0, 1}
/* APB  */
#define CMUI_OTG_SYS_0_APB_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_OTG_SYS_0_APB_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_OTG_SYS_0_APB_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_OTG_SYS_0_APB_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x484, 0, 32}
#define CMUI_OTG_SYS_0_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x488, 0, 32}
#define CMUI_OTG_SYS_0_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x48c, 0, 32}
#define CMUI_OTG_SYS_0_APB_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x490, 0, 32}
#define CMUI_OTG_SYS_0_APB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x40c, 1, 1}
/* HOST_SYS */
/* HOST_SYS[0] */
/* EHCIAHB  */
#define CMUI_HOST_SYS_0_EHCIAHB_grp_clk_src	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x600, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x604, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x608, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x644, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_dy_div_val	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x648, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_dy_div_stop	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x64c, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x650, 0, 32}
#define CMUI_HOST_SYS_0_EHCIAHB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x60c, 0, 1}
/* OHCIAHB  */                                                                                   
#define CMUI_HOST_SYS_0_OHCIAHB_grp_clk_src	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x800, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x804, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x808, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x844, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_dy_div_val	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x848, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_dy_div_stop	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x84c, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x850, 0, 32}
#define CMUI_HOST_SYS_0_OHCIAHB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x80c, 0, 1}
/* APB  */
#define CMUI_HOST_SYS_0_APB_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_HOST_SYS_0_APB_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_HOST_SYS_0_APB_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_HOST_SYS_0_APB_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x884, 0, 32}
#define CMUI_HOST_SYS_0_APB_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x888, 0, 32}
#define CMUI_HOST_SYS_0_APB_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x88c, 0, 32}
#define CMUI_HOST_SYS_0_APB_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x890, 0, 32}
#define CMUI_HOST_SYS_0_APB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x80c, 1, 1}
/* USB30_ALT_PCS */
/* USB30_ALT_PCS[0] */
/* CLK  */
#define CMUI_USB30_ALT_PCS_0_CLK_grp_clk_src	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa00, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa04, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa08, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa44, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_dy_div_val	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa48, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_dy_div_stop	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa4c, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_dy_div_busy_st (_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa50, 0, 32}
#define CMUI_USB30_ALT_PCS_0_CLK_clk_enb	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xa0c, 0, 1}
/* USB30_ALT_PIPE */
/* USB30_ALT_PIPE[0] */
/* CLK  */
#define CMUI_USB30_ALT_PIPE_0_CLK_grp_clk_src		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc00, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_grp_a_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc04, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_grp_gate_mode		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc08, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc44, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_dy_div_val		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc48, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_dy_div_stop		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc4c, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc50, 0, 32}
#define CMUI_USB30_ALT_PIPE_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xc0c, 0, 1}
/* HSIC_REFDIG */
/* HSIC_REFDIG[0] */
/* CLK  */
#define CMUI_HSIC_REFDIG_0_CLK_grp_clk_src	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe00, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe04, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe08, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe44, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_dy_div_val	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe48, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_dy_div_stop	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe4c, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe50, 0, 32}
#define CMUI_HSIC_REFDIG_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0xe0c, 0, 1}
/* HSIC_F480M */
/* HSIC_F480M[0] */
/* CLK  */
#define CMUI_HSIC_F480M_0_CLK_grp_clk_src	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1000, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1004, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1008, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_div_rst		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1044, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_dy_div_val	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1048, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_dy_div_stop	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x104c, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x1050, 0, 32}
#define CMUI_HSIC_F480M_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x100c, 0, 1}
/* DREX_REFR */
/* DREX_REFR[0] */
/* CLK  */
#define CMUI_DREX_REFR_0_CLK_grp_clk_src	{&SFR_INFO.CMU_DREX0[0], 0x400, 0, 32}
#define CMUI_DREX_REFR_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_DREX0[0], 0x404, 0, 32}
#define CMUI_DREX_REFR_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_DREX0[0], 0x408, 0, 32}
#define CMUI_DREX_REFR_0_CLK_div_rst		{&SFR_INFO.CMU_DREX0[0], 0x444, 0, 32}
#define CMUI_DREX_REFR_0_CLK_dy_div_val		{&SFR_INFO.CMU_DREX0[0], 0x448, 0, 32}
#define CMUI_DREX_REFR_0_CLK_dy_div_stop	{&SFR_INFO.CMU_DREX0[0], 0x44c, 0, 32}
#define CMUI_DREX_REFR_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_DREX0[0], 0x450, 0, 32}
#define CMUI_DREX_REFR_0_CLK_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x40c, 0, 1}
/* WAVE_V */
/* WAVE_V[0] */
/* CLK  */
#define CMUI_WAVE_V_0_CLK_grp_clk_src		{&SFR_INFO.CMU_WAVE[0], 0x400, 0, 32}
#define CMUI_WAVE_V_0_CLK_grp_a_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x404, 0, 32}
#define CMUI_WAVE_V_0_CLK_grp_gate_mode		{&SFR_INFO.CMU_WAVE[0], 0x408, 0, 32}
#define CMUI_WAVE_V_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x444, 0, 32}
#define CMUI_WAVE_V_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0x448, 0, 32}
#define CMUI_WAVE_V_0_CLK_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0x44c, 0, 32}
#define CMUI_WAVE_V_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE[0], 0x450, 0, 32}
#define CMUI_WAVE_V_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE[0], 0x40c, 0, 1}
/* WAVE_M */
/* WAVE_M[0] */
/* CLK  */
#define CMUI_WAVE_M_0_CLK_grp_clk_src		{&SFR_INFO.CMU_WAVE[0], 0x600, 0, 32}
#define CMUI_WAVE_M_0_CLK_grp_a_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x604, 0, 32}
#define CMUI_WAVE_M_0_CLK_grp_gate_mode		{&SFR_INFO.CMU_WAVE[0], 0x608, 0, 32}
#define CMUI_WAVE_M_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x644, 0, 32}
#define CMUI_WAVE_M_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0x648, 0, 32}
#define CMUI_WAVE_M_0_CLK_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0x64c, 0, 32}
#define CMUI_WAVE_M_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE[0], 0x650, 0, 32}
#define CMUI_WAVE_M_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE[0], 0x60c, 0, 1}
/* WAVE_C */
/* WAVE_C[0] */
/* CLK  */
#define CMUI_WAVE_C_0_CLK_grp_clk_src		{&SFR_INFO.CMU_WAVE[0], 0x800, 0, 32}
#define CMUI_WAVE_C_0_CLK_grp_a_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x804, 0, 32}
#define CMUI_WAVE_C_0_CLK_grp_gate_mode		{&SFR_INFO.CMU_WAVE[0], 0x808, 0, 32}
#define CMUI_WAVE_C_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE[0], 0x844, 0, 32}
#define CMUI_WAVE_C_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0x848, 0, 32}
#define CMUI_WAVE_C_0_CLK_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0x84c, 0, 32}
#define CMUI_WAVE_C_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE[0], 0x850, 0, 32}
#define CMUI_WAVE_C_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE[0], 0x80c, 0, 1}
/* WAVE_B */
/* WAVE_B[0] */
/* CLK  */
#define CMUI_WAVE_B_0_CLK_grp_clk_src		{&SFR_INFO.CMU_WAVE[0], 0xa00, 0, 32}
#define CMUI_WAVE_B_0_CLK_grp_a_div_rst		{&SFR_INFO.CMU_WAVE[0], 0xa04, 0, 32}
#define CMUI_WAVE_B_0_CLK_grp_gate_mode		{&SFR_INFO.CMU_WAVE[0], 0xa08, 0, 32}
#define CMUI_WAVE_B_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE[0], 0xa44, 0, 32}
#define CMUI_WAVE_B_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE[0], 0xa48, 0, 32}
#define CMUI_WAVE_B_0_CLK_dy_div_stop		{&SFR_INFO.CMU_WAVE[0], 0xa4c, 0, 32}
#define CMUI_WAVE_B_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE[0], 0xa50, 0, 32}
#define CMUI_WAVE_B_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE[0], 0xa0c, 0, 1}
/* WAVE420_V */
/* WAVE420_V[0] */
/* CLK  */
#define CMUI_WAVE420_V_0_CLK_grp_clk_src	{&SFR_INFO.CMU_WAVE420[0], 0x400, 0, 32}
#define CMUI_WAVE420_V_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_WAVE420[0], 0x404, 0, 32}
#define CMUI_WAVE420_V_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_WAVE420[0], 0x408, 0, 32}
#define CMUI_WAVE420_V_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0x444, 0, 32}
#define CMUI_WAVE420_V_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0x448, 0, 32}
#define CMUI_WAVE420_V_0_CLK_dy_div_stop	{&SFR_INFO.CMU_WAVE420[0], 0x44c, 0, 32}
#define CMUI_WAVE420_V_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0x450, 0, 32}
#define CMUI_WAVE420_V_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0x40c, 0, 1}
/* WAVE420_M */
/* WAVE420_M[0] */
/* CLK  */
#define CMUI_WAVE420_M_0_CLK_grp_clk_src	{&SFR_INFO.CMU_WAVE420[0], 0x600, 0, 32}
#define CMUI_WAVE420_M_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_WAVE420[0], 0x604, 0, 32}
#define CMUI_WAVE420_M_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_WAVE420[0], 0x608, 0, 32}
#define CMUI_WAVE420_M_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0x644, 0, 32}
#define CMUI_WAVE420_M_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0x648, 0, 32}
#define CMUI_WAVE420_M_0_CLK_dy_div_stop	{&SFR_INFO.CMU_WAVE420[0], 0x64c, 0, 32}
#define CMUI_WAVE420_M_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0x650, 0, 32}
#define CMUI_WAVE420_M_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0x60c, 0, 1}
/* WAVE420_C */
/* WAVE420_C[0] */
/* CLK  */
#define CMUI_WAVE420_C_0_CLK_grp_clk_src	{&SFR_INFO.CMU_WAVE420[0], 0x800, 0, 32}
#define CMUI_WAVE420_C_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_WAVE420[0], 0x804, 0, 32}
#define CMUI_WAVE420_C_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_WAVE420[0], 0x808, 0, 32}
#define CMUI_WAVE420_C_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0x844, 0, 32}
#define CMUI_WAVE420_C_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0x848, 0, 32}
#define CMUI_WAVE420_C_0_CLK_dy_div_stop	{&SFR_INFO.CMU_WAVE420[0], 0x84c, 0, 32}
#define CMUI_WAVE420_C_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0x850, 0, 32}
#define CMUI_WAVE420_C_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0x80c, 0, 1}
/* WAVE420_B */
/* WAVE420_B[0] */
/* CLK  */
#define CMUI_WAVE420_B_0_CLK_grp_clk_src	{&SFR_INFO.CMU_WAVE420[0], 0xa00, 0, 32}
#define CMUI_WAVE420_B_0_CLK_grp_a_div_rst	{&SFR_INFO.CMU_WAVE420[0], 0xa04, 0, 32}
#define CMUI_WAVE420_B_0_CLK_grp_gate_mode	{&SFR_INFO.CMU_WAVE420[0], 0xa08, 0, 32}
#define CMUI_WAVE420_B_0_CLK_div_rst		{&SFR_INFO.CMU_WAVE420[0], 0xa44, 0, 32}
#define CMUI_WAVE420_B_0_CLK_dy_div_val		{&SFR_INFO.CMU_WAVE420[0], 0xa48, 0, 32}
#define CMUI_WAVE420_B_0_CLK_dy_div_stop	{&SFR_INFO.CMU_WAVE420[0], 0xa4c, 0, 32}
#define CMUI_WAVE420_B_0_CLK_dy_div_busy_st	{&SFR_INFO.CMU_WAVE420[0], 0xa50, 0, 32}
#define CMUI_WAVE420_B_0_CLK_clk_enb		{&SFR_INFO.CMU_WAVE420[0], 0xa0c, 0, 1}
/* MCD */
/* MCD[0] */
/* VCLK  */
#define CMUI_MCD_0_VCLK_grp_clk_src		{&SFR_INFO.CMU_DISP[0], 0x1c00, 0, 32}
#define CMUI_MCD_0_VCLK_grp_a_div_rst		{&SFR_INFO.CMU_DISP[0], 0x1c04, 0, 32}
#define CMUI_MCD_0_VCLK_grp_gate_mode		{&SFR_INFO.CMU_DISP[0], 0x1c08, 0, 32}
#define CMUI_MCD_0_VCLK_div_rst			{&SFR_INFO.CMU_DISP[0], 0x1c44, 0, 32}
#define CMUI_MCD_0_VCLK_dy_div_val		{&SFR_INFO.CMU_DISP[0], 0x1c48, 0, 32}
#define CMUI_MCD_0_VCLK_dy_div_stop		{&SFR_INFO.CMU_DISP[0], 0x1c4c, 0, 32}
#define CMUI_MCD_0_VCLK_dy_div_busy_st		{&SFR_INFO.CMU_DISP[0], 0x1c50, 0, 32}
#define CMUI_MCD_0_VCLK_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x1c0c, 0, 1}
/* BUS_DMAC */
/* BUS_DMAC[0] */
/* AXI  */
#define CMUI_BUS_DMAC_0_AXI_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6800, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_grp_a_div_rst	{&SFR_INFO.CMU_SYS[0], 0x6804, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_grp_gate_mode	{&SFR_INFO.CMU_SYS[0], 0x6808, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6844, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6848, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x684c, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x6850, 0, 32}
#define CMUI_BUS_DMAC_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x680c, 0, 1}
/* DMAC */
/* DMAC[0] */
/* AXI  */
#define CMUI_DMAC_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAC_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAC_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAC_0_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAC_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAC_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAC_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAC_0_AXI_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x680c, 1, 1}
/* APB  */
#define CMUI_DMAC_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_DMAC_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAC_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAC_0_APB_div_rst			{0,0,0,0}
#define CMUI_DMAC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_DMAC_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_DMAC_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAC_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 22, 1}
/* DMAC[1] */
/* AXI  */
#define CMUI_DMAC_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAC_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAC_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAC_1_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAC_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAC_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAC_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAC_1_AXI_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x680c, 2, 1}
/* APB  */
#define CMUI_DMAC_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_DMAC_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAC_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAC_1_APB_div_rst			{0,0,0,0}
#define CMUI_DMAC_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_DMAC_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_DMAC_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAC_1_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 23, 1}
/* SDMAC */
/* SDMAC[0] */
/* AXI  */
#define CMUI_SDMAC_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_div_rst		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_SDMAC_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x680c, 3, 1}
/* APB  */
#define CMUI_SDMAC_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SDMAC_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_SDMAC_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_SDMAC_0_APB_div_rst		{0,0,0,0}
#define CMUI_SDMAC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_SDMAC_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_SDMAC_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_SDMAC_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 24, 1}
/* SDMAC[1] */
/* AXI  */
#define CMUI_SDMAC_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_div_rst		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_SDMAC_1_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x680c, 4, 1}
/* APB  */
#define CMUI_SDMAC_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SDMAC_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_SDMAC_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_SDMAC_1_APB_div_rst		{0,0,0,0}
#define CMUI_SDMAC_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_SDMAC_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_SDMAC_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_SDMAC_1_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 25, 1}
/* MDMAC */
/* MDMAC[0] */
/* AXI  */
#define CMUI_MDMAC_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_div_rst		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_MDMAC_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x680c, 5, 1}
/* APB  */
#define CMUI_MDMAC_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_MDMAC_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_MDMAC_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_MDMAC_0_APB_div_rst		{0,0,0,0}
#define CMUI_MDMAC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_MDMAC_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_MDMAC_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_MDMAC_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 26, 1}
/* GIC400 */
/* GIC400[0] */
/* AXI  */
#define CMUI_GIC400_0_AXI_grp_clk_src		{&SFR_INFO.CMU_SYS[0], 0x6a00, 0, 32}
#define CMUI_GIC400_0_AXI_grp_a_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6a04, 0, 32}
#define CMUI_GIC400_0_AXI_grp_gate_mode		{&SFR_INFO.CMU_SYS[0], 0x6a08, 0, 32}
#define CMUI_GIC400_0_AXI_div_rst		{&SFR_INFO.CMU_SYS[0], 0x6a44, 0, 32}
#define CMUI_GIC400_0_AXI_dy_div_val		{&SFR_INFO.CMU_SYS[0], 0x6a48, 0, 32}
#define CMUI_GIC400_0_AXI_dy_div_stop		{&SFR_INFO.CMU_SYS[0], 0x6a4c, 0, 32}
#define CMUI_GIC400_0_AXI_dy_div_busy_st	{&SFR_INFO.CMU_SYS[0], 0x6a50, 0, 32}
#define CMUI_GIC400_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x6a0c, 0, 1}
/* MCU */
/* MCU[0] */
/* CORE  */
#define CMUI_MCU_0_CORE_grp_clk_src		{&SFR_INFO.CMU_PERICLK[0], 0x2400, 0, 32}
#define CMUI_MCU_0_CORE_grp_a_div_rst		{&SFR_INFO.CMU_PERICLK[0], 0x2404, 0, 32}
#define CMUI_MCU_0_CORE_grp_gate_mode		{&SFR_INFO.CMU_PERICLK[0], 0x2408, 0, 32}
#define CMUI_MCU_0_CORE_div_rst			{&SFR_INFO.CMU_PERICLK[0], 0x2444, 0, 32}
#define CMUI_MCU_0_CORE_dy_div_val		{&SFR_INFO.CMU_PERICLK[0], 0x2448, 0, 32}
#define CMUI_MCU_0_CORE_dy_div_stop		{&SFR_INFO.CMU_PERICLK[0], 0x244c, 0, 32}
#define CMUI_MCU_0_CORE_dy_div_busy_st		{&SFR_INFO.CMU_PERICLK[0], 0x2450, 0, 32}
#define CMUI_MCU_0_CORE_clk_enb			{&SFR_INFO.CMU_PERICLK[0], 0x240c, 0, 1}
/* SPDIFRX */
/* SPDIFRX[0] */
/* APB  */
#define CMUI_SPDIFRX_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_div_rst		{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_SPDIFRX_0_APB_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x20c, 13, 1}
/* AC97 */
/* AC97[0] */
/* APB  */
#define CMUI_AC97_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_AC97_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_AC97_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_AC97_0_APB_div_rst			{0,0,0,0}
#define CMUI_AC97_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_AC97_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_AC97_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_AC97_0_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 7, 1}
/* TMU */
/* TMU[0] */
/* APB  */
#define CMUI_TMU_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TMU_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TMU_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TMU_0_APB_div_rst			{0,0,0,0}
#define CMUI_TMU_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_TMU_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TMU_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TMU_0_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 14, 1}
/* CCI400 */
/* CCI400[0] */
/* AXI  */
#define CMUI_CCI400_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CCI400_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CCI400_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CCI400_0_AXI_div_rst		{0,0,0,0}
#define CMUI_CCI400_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CCI400_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CCI400_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CCI400_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 1, 1}
/* TIEOFF_CCI */
/* TIEOFF_CCI[0] */
/* AXI  */
#define CMUI_TIEOFF_CCI_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_div_rst		{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_dy_div_val	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_TIEOFF_CCI_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 2, 1}
/* SYSCTRL */
/* SYSCTRL[0] */
/* APB  */
#define CMUI_SYSCTRL_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_div_rst		{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_SYSCTRL_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 12, 1}
/* HPM */
/* HPM[0] */
/* APB  */
#define CMUI_HPM_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_HPM_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_HPM_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_HPM_0_APB_div_rst			{0,0,0,0}
#define CMUI_HPM_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_HPM_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_HPM_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_HPM_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 13, 1}
/* Q_ENHANCER */
/* Q_ENHANCER[0] */
/* APB  */
#define CMUI_Q_ENHANCER_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_div_rst		{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_Q_ENHANCER_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 14, 1}
/* CRYPTO */
/* CRYPTO[0] */
/* AXI  */
#define CMUI_CRYPTO_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_div_rst		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CRYPTO_0_AXI_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 3, 1}
/* APB  */
#define CMUI_CRYPTO_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_div_rst		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_CRYPTO_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_CRYPTO_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 15, 1}
/* WDT */
/* WDT[0] */
/* APB  */
#define CMUI_WDT_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_WDT_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_WDT_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_WDT_0_APB_div_rst			{0,0,0,0}
#define CMUI_WDT_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_WDT_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_WDT_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_WDT_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 16, 1}
/* POR  */
#define CMUI_WDT_0_POR_grp_clk_src		{0,0,0,0}
#define CMUI_WDT_0_POR_grp_a_div_rst		{0,0,0,0}
#define CMUI_WDT_0_POR_grp_gate_mode		{0,0,0,0}
#define CMUI_WDT_0_POR_div_rst			{0,0,0,0}
#define CMUI_WDT_0_POR_dy_div_val		{0,0,0,0}
#define CMUI_WDT_0_POR_dy_div_stop		{0,0,0,0}
#define CMUI_WDT_0_POR_dy_div_busy_st		{0,0,0,0}
#define CMUI_WDT_0_POR_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 17, 1}
/* WDT[1] */
/* APB  */
#define CMUI_WDT_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_WDT_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_WDT_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_WDT_1_APB_div_rst			{0,0,0,0}
#define CMUI_WDT_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_WDT_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_WDT_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_WDT_1_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 18, 1}
/* POR  */
#define CMUI_WDT_1_POR_grp_clk_src		{0,0,0,0}
#define CMUI_WDT_1_POR_grp_a_div_rst		{0,0,0,0}
#define CMUI_WDT_1_POR_grp_gate_mode		{0,0,0,0}
#define CMUI_WDT_1_POR_div_rst			{0,0,0,0}
#define CMUI_WDT_1_POR_dy_div_val		{0,0,0,0}
#define CMUI_WDT_1_POR_dy_div_stop		{0,0,0,0}
#define CMUI_WDT_1_POR_dy_div_busy_st		{0,0,0,0}
#define CMUI_WDT_1_POR_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 19, 1}
/* TZPC */
/* TZPC[0] */
/* APB  */
#define CMUI_TZPC_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_TZPC_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_TZPC_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_TZPC_0_APB_div_rst			{0,0,0,0}
#define CMUI_TZPC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_TZPC_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_TZPC_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_TZPC_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 20, 1}
/* ECID */
/* ECID[0] */
/* APB  */
#define CMUI_ECID_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_ECID_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_ECID_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_ECID_0_APB_div_rst			{0,0,0,0}
#define CMUI_ECID_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_ECID_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_ECID_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_ECID_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 21, 1}
/* BBUSTIEOFF */
/* BBUSTIEOFF[0] */
/* APB  */
#define CMUI_BBUSTIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_BBUSTIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_BBUS[0], 0x20c, 15, 1}
/* LBUSTIEOFF */
/* LBUSTIEOFF[0] */
/* APB  */
#define CMUI_LBUSTIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_LBUSTIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_LBUS[0], 0x20c, 6, 1}
/* SYSTIEOFF */
/* SYSTIEOFF[0] */
/* APB  */
#define CMUI_SYSTIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_SYSTIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x20c, 27, 1}
/* ADC */
/* ADC[0] */
/* APB  */
#define CMUI_ADC_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_ADC_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_ADC_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_ADC_0_APB_div_rst			{0,0,0,0}
#define CMUI_ADC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_ADC_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_ADC_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_ADC_0_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 16, 1}
/* GPIO */
/* GPIO[0] */
/* APB  */
#define CMUI_GPIO_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_GPIO_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GPIO_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_GPIO_0_APB_div_rst			{0,0,0,0}
#define CMUI_GPIO_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_GPIO_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_GPIO_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GPIO_0_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 7, 1}
/* GPIO[1] */
/* APB  */
#define CMUI_GPIO_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_GPIO_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GPIO_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_GPIO_1_APB_div_rst			{0,0,0,0}
#define CMUI_GPIO_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_GPIO_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_GPIO_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GPIO_1_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 8, 1}
/* GPIO[2] */
/* APB  */
#define CMUI_GPIO_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_GPIO_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GPIO_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_GPIO_2_APB_div_rst			{0,0,0,0}
#define CMUI_GPIO_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_GPIO_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_GPIO_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GPIO_2_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 17, 1}
/* GPIO[3] */
/* APB  */
#define CMUI_GPIO_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_GPIO_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GPIO_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_GPIO_3_APB_div_rst			{0,0,0,0}
#define CMUI_GPIO_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_GPIO_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_GPIO_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GPIO_3_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 18, 1}
/* GPIO[4] */
/* APB  */
#define CMUI_GPIO_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_GPIO_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_GPIO_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_GPIO_4_APB_div_rst			{0,0,0,0}
#define CMUI_GPIO_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_GPIO_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_GPIO_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_GPIO_4_APB_clk_enb			{&SFR_INFO.CMU_BBUS[0], 0x20c, 19, 1}
/* I2C */
/* I2C[0] */
/* APB  */
#define CMUI_I2C_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2C_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2C_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2C_0_APB_div_rst			{0,0,0,0}
#define CMUI_I2C_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2C_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2C_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2C_0_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 8, 1}
/* I2C[1] */
/* APB  */
#define CMUI_I2C_1_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2C_1_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2C_1_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2C_1_APB_div_rst			{0,0,0,0}
#define CMUI_I2C_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2C_1_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2C_1_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2C_1_APB_clk_enb			{&SFR_INFO.CMU_TBUS[0], 0x20c, 9, 1}
/* I2C[2] */
/* APB  */
#define CMUI_I2C_2_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2C_2_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2C_2_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2C_2_APB_div_rst			{0,0,0,0}
#define CMUI_I2C_2_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2C_2_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2C_2_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2C_2_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 9, 1}
/* I2C[3] */
/* APB  */
#define CMUI_I2C_3_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2C_3_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2C_3_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2C_3_APB_div_rst			{0,0,0,0}
#define CMUI_I2C_3_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2C_3_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2C_3_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2C_3_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 10, 1}
/* I2C[4] */
/* APB  */
#define CMUI_I2C_4_APB_grp_clk_src		{0,0,0,0}
#define CMUI_I2C_4_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_I2C_4_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_I2C_4_APB_div_rst			{0,0,0,0}
#define CMUI_I2C_4_APB_dy_div_val		{0,0,0,0}
#define CMUI_I2C_4_APB_dy_div_stop		{0,0,0,0}
#define CMUI_I2C_4_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_I2C_4_APB_clk_enb			{&SFR_INFO.CMU_LBUS[0], 0x20c, 11, 1}
/* MP2TS */
/* MP2TS[0] */
/* AHB  */
#define CMUI_MP2TS_0_AHB_grp_clk_src		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_grp_a_div_rst		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_grp_gate_mode		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_div_rst		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_dy_div_val		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_dy_div_stop		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_dy_div_busy_st		{0,0,0,0}
#define CMUI_MP2TS_0_AHB_clk_enb		{&SFR_INFO.CMU_LBUS[0], 0x20c, 3, 1}
/* DREXTIEOFF */
/* DREXTIEOFF[0] */
/* APB  */
#define CMUI_DREXTIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_DREXTIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_DREX0[0], 0x20c, 5, 1}
/* CPUTIEOFF */
/* CPUTIEOFF[0] */
/* APB  */
#define CMUI_CPUTIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_CPUTIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_CPU[0], 0x20c, 5, 1}
/* MCUS */
/* MCUS[0] */
/* APB  */
#define CMUI_MCUS_0_APB_grp_clk_src		{0,0,0,0}
#define CMUI_MCUS_0_APB_grp_a_div_rst		{0,0,0,0}
#define CMUI_MCUS_0_APB_grp_gate_mode		{0,0,0,0}
#define CMUI_MCUS_0_APB_div_rst			{0,0,0,0}
#define CMUI_MCUS_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_MCUS_0_APB_dy_div_stop		{0,0,0,0}
#define CMUI_MCUS_0_APB_dy_div_busy_st		{0,0,0,0}
#define CMUI_MCUS_0_APB_clk_enb			{&SFR_INFO.CMU_SYS[0], 0x20c, 28, 1}
/* DISP_TIEOFF */
/* DISP_TIEOFF[0] */
/* APB  */
#define CMUI_DISP_TIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_TIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 25, 1}
/* DISP_TZPC */
/* DISP_TZPC[0] */
/* APB  */
#define CMUI_DISP_TZPC_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_div_rst		{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_dy_div_val		{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_TZPC_0_APB_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 26, 1}
/* DISP_TZPC[1] */
/* APB  */
#define CMUI_DISP_TZPC_1_APB_grp_clk_src	{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_div_rst		{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_dy_div_val		{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_dy_div_stop	{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_TZPC_1_APB_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 27, 1}
/* CSI_TO_AXI */
/* CSI_TO_AXI[0] */
/* AXI  */
#define CMUI_CSI_TO_AXI_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_div_rst		{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_dy_div_val	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CSI_TO_AXI_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 2, 1}
/* CSI_TO_NXS */
/* CSI_TO_NXS[0] */
/* AXI  */
#define CMUI_CSI_TO_NXS_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_div_rst		{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_dy_div_val	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CSI_TO_NXS_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 3, 1}
/* CSI_TO_NXS[1] */
/* AXI  */
#define CMUI_CSI_TO_NXS_1_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_div_rst		{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_dy_div_val	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CSI_TO_NXS_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 4, 1}
/* CSI_TO_NXS[2] */
/* AXI  */
#define CMUI_CSI_TO_NXS_2_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_div_rst		{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_dy_div_val	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CSI_TO_NXS_2_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 5, 1}
/* CSI_TO_NXS[3] */
/* AXI  */
#define CMUI_CSI_TO_NXS_3_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_div_rst		{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_dy_div_val	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_CSI_TO_NXS_3_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 6, 1}
/* MLC */
/* MLC[0] */
/* BOTTOM0  */
#define CMUI_MLC_0_BOTTOM0_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM0_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 7, 1}
/* BOTTOM1  */
#define CMUI_MLC_0_BOTTOM1_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BOTTOM1_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 8, 1}
/* BLENDER0  */
#define CMUI_MLC_0_BLENDER0_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER0_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 9, 1}
/* BLENDER1  */
#define CMUI_MLC_0_BLENDER1_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER1_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 10, 1}
/* BLENDER2  */
#define CMUI_MLC_0_BLENDER2_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER2_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 11, 1}
/* BLENDER3  */
#define CMUI_MLC_0_BLENDER3_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER3_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 12, 1}
/* BLENDER4  */
#define CMUI_MLC_0_BLENDER4_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER4_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 13, 1}
/* BLENDER5  */
#define CMUI_MLC_0_BLENDER5_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER5_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 14, 1}
/* BLENDER6  */
#define CMUI_MLC_0_BLENDER6_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER6_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 15, 1}
/* BLENDER7  */
#define CMUI_MLC_0_BLENDER7_grp_clk_src		{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_grp_a_div_rst	{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_grp_gate_mode	{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_div_rst		{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_dy_div_val		{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_dy_div_stop		{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_dy_div_busy_st	{0,0,0,0}
#define CMUI_MLC_0_BLENDER7_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 16, 1}
/* MCD_CPUIF */
/* MCD_CPUIF[0] */
/* AXI  */
#define CMUI_MCD_CPUIF_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_div_rst		{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MCD_CPUIF_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 21, 1}
/* VIP_CPUIF */
/* VIP_CPUIF[0] */
/* AXI  */
#define CMUI_VIP_CPUIF_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_div_rst		{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_VIP_CPUIF_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 22, 1}
/* VIP_PRES_CPUIF */
/* VIP_PRES_CPUIF[0] */
/* AXI  */
#define CMUI_VIP_PRES_CPUIF_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_div_rst		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_VIP_PRES_CPUIF_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 23, 1}
/* ISS_CPUIF */
/* ISS_CPUIF[0] */
/* AXI  */
#define CMUI_ISS_CPUIF_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_div_rst		{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISS_CPUIF_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 24, 1}
/* DISP2ISP */
/* DISP2ISP[0] */
/* AXI  */
#define CMUI_DISP2ISP_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_div_rst		{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP2ISP_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 25, 1}
/* ISP2DISP */
/* ISP2DISP[0] */
/* AXI  */
#define CMUI_ISP2DISP_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_div_rst		{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP2DISP_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 26, 1}
/* ISP2DISP[1] */
/* AXI  */
#define CMUI_ISP2DISP_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_div_rst		{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP2DISP_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x20c, 27, 1}
/* CROP */
/* CROP[0] */
/* AXI  */
#define CMUI_CROP_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CROP_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CROP_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CROP_0_AXI_div_rst			{0,0,0,0}
#define CMUI_CROP_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CROP_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CROP_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CROP_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 28, 1}
/* CROP[1] */
/* AXI  */
#define CMUI_CROP_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CROP_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CROP_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CROP_1_AXI_div_rst			{0,0,0,0}
#define CMUI_CROP_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CROP_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CROP_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CROP_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 29, 1}
/* CSC */
/* CSC[0] */
/* AXI  */
#define CMUI_CSC_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CSC_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CSC_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CSC_0_AXI_div_rst			{0,0,0,0}
#define CMUI_CSC_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CSC_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CSC_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CSC_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 30, 1}
/* CSC[1] */
/* AXI  */
#define CMUI_CSC_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CSC_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CSC_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CSC_1_AXI_div_rst			{0,0,0,0}
#define CMUI_CSC_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CSC_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CSC_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CSC_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x20c, 31, 1}
/* CSC[2] */
/* AXI  */
#define CMUI_CSC_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CSC_2_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CSC_2_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CSC_2_AXI_div_rst			{0,0,0,0}
#define CMUI_CSC_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CSC_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CSC_2_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CSC_2_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 0, 1}
/* CSC[3] */
/* AXI  */
#define CMUI_CSC_3_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_CSC_3_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_CSC_3_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_CSC_3_AXI_div_rst			{0,0,0,0}
#define CMUI_CSC_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_CSC_3_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_CSC_3_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_CSC_3_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 1, 1}
/* SCALER */
/* SCALER[0] */
/* AXI  */
#define CMUI_SCALER_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_SCALER_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_SCALER_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_SCALER_0_AXI_div_rst		{0,0,0,0}
#define CMUI_SCALER_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_SCALER_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_SCALER_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_SCALER_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 2, 1}
/* SCALER[1] */
/* AXI  */
#define CMUI_SCALER_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_SCALER_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_SCALER_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_SCALER_1_AXI_div_rst		{0,0,0,0}
#define CMUI_SCALER_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_SCALER_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_SCALER_1_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_SCALER_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 3, 1}
/* SCALER[2] */
/* AXI  */
#define CMUI_SCALER_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_SCALER_2_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_SCALER_2_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_SCALER_2_AXI_div_rst		{0,0,0,0}
#define CMUI_SCALER_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_SCALER_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_SCALER_2_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_SCALER_2_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 4, 1}
/* MULTI_TAP */
/* MULTI_TAP[0] */
/* AXI  */
#define CMUI_MULTI_TAP_0_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_div_rst		{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MULTI_TAP_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 5, 1}
/* MULTI_TAP[1] */
/* AXI  */
#define CMUI_MULTI_TAP_1_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_div_rst		{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MULTI_TAP_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 6, 1}
/* MULTI_TAP[2] */
/* AXI  */
#define CMUI_MULTI_TAP_2_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_div_rst		{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MULTI_TAP_2_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 7, 1}
/* MULTI_TAP[3] */
/* AXI  */
#define CMUI_MULTI_TAP_3_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_div_rst		{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_MULTI_TAP_3_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 8, 1}
/* DMAR */
/* DMAR[0] */
/* AXI  */
#define CMUI_DMAR_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_0_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 9, 1}
/* DMAR[1] */
/* AXI  */
#define CMUI_DMAR_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_1_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 10, 1}
/* DMAR[2] */
/* AXI  */
#define CMUI_DMAR_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_2_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_2_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_2_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_2_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_2_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 11, 1}
/* DMAR[3] */
/* AXI  */
#define CMUI_DMAR_3_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_3_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_3_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_3_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_3_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_3_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_3_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 12, 1}
/* DMAR[4] */
/* AXI  */
#define CMUI_DMAR_4_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_4_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_4_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_4_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_4_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_4_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_4_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_4_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 13, 1}
/* DMAR[5] */
/* AXI  */
#define CMUI_DMAR_5_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_5_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_5_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_5_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_5_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_5_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_5_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_5_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 14, 1}
/* DMAR[6] */
/* AXI  */
#define CMUI_DMAR_6_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_6_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_6_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_6_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_6_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_6_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_6_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_6_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 15, 1}
/* DMAR[7] */
/* AXI  */
#define CMUI_DMAR_7_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_7_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_7_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_7_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_7_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_7_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_7_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_7_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 16, 1}
/* DMAR[8] */
/* AXI  */
#define CMUI_DMAR_8_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_8_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_8_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_8_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_8_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_8_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_8_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_8_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 17, 1}
/* DMAR[9] */
/* AXI  */
#define CMUI_DMAR_9_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAR_9_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAR_9_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAR_9_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAR_9_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAR_9_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAR_9_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAR_9_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 18, 1}
/* DMAW */
/* DMAW[0] */
/* AXI  */
#define CMUI_DMAW_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_0_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 19, 1}
/* DMAW[1] */
/* AXI  */
#define CMUI_DMAW_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_1_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 20, 1}
/* DMAW[2] */
/* AXI  */
#define CMUI_DMAW_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_2_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_2_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_2_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_2_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_2_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 21, 1}
/* DMAW[3] */
/* AXI  */
#define CMUI_DMAW_3_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_3_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_3_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_3_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_3_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_3_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_3_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 22, 1}
/* DMAW[4] */
/* AXI  */
#define CMUI_DMAW_4_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_4_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_4_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_4_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_4_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_4_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_4_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_4_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 23, 1}
/* DMAW[5] */
/* AXI  */
#define CMUI_DMAW_5_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_5_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_5_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_5_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_5_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_5_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_5_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_5_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 24, 1}
/* DMAW[6] */
/* AXI  */
#define CMUI_DMAW_6_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_6_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_6_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_6_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_6_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_6_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_6_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_6_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 25, 1}
/* DMAW[7] */
/* AXI  */
#define CMUI_DMAW_7_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_7_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_7_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_7_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_7_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_7_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_7_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_7_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 26, 1}
/* DMAW[8] */
/* AXI  */
#define CMUI_DMAW_8_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_8_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_8_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_8_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_8_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_8_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_8_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_8_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 27, 1}
/* DMAW[9] */
/* AXI  */
#define CMUI_DMAW_9_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_9_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_9_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_9_AXI_div_rst			{0,0,0,0}
#define CMUI_DMAW_9_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_9_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_9_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_9_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 28, 1}
/* DMAW[10] */
/* AXI  */
#define CMUI_DMAW_10_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_10_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_10_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_10_AXI_div_rst		{0,0,0,0}
#define CMUI_DMAW_10_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_10_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_10_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_10_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 29, 1}
/* DMAW[11] */
/* AXI  */
#define CMUI_DMAW_11_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_DMAW_11_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_DMAW_11_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_DMAW_11_AXI_div_rst		{0,0,0,0}
#define CMUI_DMAW_11_AXI_dy_div_val		{0,0,0,0}
#define CMUI_DMAW_11_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_DMAW_11_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_DMAW_11_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x210, 30, 1}
/* HUE */
/* HUE[0] */
/* AXI  */
#define CMUI_HUE_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_HUE_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_HUE_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_HUE_0_AXI_div_rst			{0,0,0,0}
#define CMUI_HUE_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_HUE_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_HUE_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_HUE_0_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x210, 31, 1}
/* HUE[1] */
/* AXI  */
#define CMUI_HUE_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_HUE_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_HUE_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_HUE_1_AXI_div_rst			{0,0,0,0}
#define CMUI_HUE_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_HUE_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_HUE_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_HUE_1_AXI_clk_enb			{&SFR_INFO.CMU_DISP[0], 0x214, 0, 1}
/* GAMMA */
/* GAMMA[0] */
/* AXI  */
#define CMUI_GAMMA_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_div_rst		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_GAMMA_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 1, 1}
/* GAMMA[1] */
/* AXI  */
#define CMUI_GAMMA_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_div_rst		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_GAMMA_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 2, 1}
/* NXS_FIFO */
/* NXS_FIFO[0] */
/* AXI  */
#define CMUI_NXS_FIFO_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 9, 1}
/* NXS_FIFO[1] */
/* AXI  */
#define CMUI_NXS_FIFO_1_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_1_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 10, 1}
/* NXS_FIFO[2] */
/* AXI  */
#define CMUI_NXS_FIFO_2_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_2_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 11, 1}
/* NXS_FIFO[3] */
/* AXI  */
#define CMUI_NXS_FIFO_3_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_3_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 12, 1}
/* NXS_FIFO[4] */
/* AXI  */
#define CMUI_NXS_FIFO_4_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_4_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 13, 1}
/* NXS_FIFO[5] */
/* AXI  */
#define CMUI_NXS_FIFO_5_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_5_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 14, 1}
/* NXS_FIFO[6] */
/* AXI  */
#define CMUI_NXS_FIFO_6_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_6_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 15, 1}
/* NXS_FIFO[7] */
/* AXI  */
#define CMUI_NXS_FIFO_7_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_7_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 16, 1}
/* NXS_FIFO[8] */
/* AXI  */
#define CMUI_NXS_FIFO_8_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_8_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 17, 1}
/* NXS_FIFO[9] */
/* AXI  */
#define CMUI_NXS_FIFO_9_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_9_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 18, 1}
/* NXS_FIFO[10] */
/* AXI  */
#define CMUI_NXS_FIFO_10_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_10_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 19, 1}
/* NXS_FIFO[11] */
/* AXI  */
#define CMUI_NXS_FIFO_11_AXI_grp_clk_src	{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_dy_div_stop	{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS_FIFO_11_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 20, 1}
/* NXS2HDMI */
/* NXS2HDMI[0] */
/* AXI  */
#define CMUI_NXS2HDMI_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_grp_a_div_rst	{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_grp_gate_mode	{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_div_rst		{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_dy_div_busy_st	{0,0,0,0}
#define CMUI_NXS2HDMI_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 21, 1}
/* TPGEN */
/* TPGEN[0] */
/* AXI  */
#define CMUI_TPGEN_0_AXI_grp_clk_src		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_grp_a_div_rst		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_grp_gate_mode		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_div_rst		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_dy_div_val		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_dy_div_stop		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_dy_div_busy_st		{0,0,0,0}
#define CMUI_TPGEN_0_AXI_clk_enb		{&SFR_INFO.CMU_DISP[0], 0x214, 22, 1}
/* CODATIEOFF */
/* CODATIEOFF[0] */
/* APB  */
#define CMUI_CODATIEOFF_0_APB_grp_clk_src	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_grp_gate_mode	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_div_rst		{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_dy_div_val	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_dy_div_stop	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODATIEOFF_0_APB_clk_enb		{&SFR_INFO.CMU_CODA[0], 0x20c, 6, 1}
/* ISP_CMU */
/* ISP_CMU[0] */
/* CLK  */
#define CMUI_ISP_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_ISP_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 1, 1}
/* DISP_CMU */
/* DISP_CMU[0] */
/* CLK  */
#define CMUI_DISP_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DISP_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 2, 1}
/* USB_CMU */
/* USB_CMU[0] */
/* CLK  */
#define CMUI_USB_CMU_0_CLK_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_grp_a_div_rst	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_grp_gate_mode	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_dy_div_busy_st	(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB_CMU_0_CLK_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_SYS[0], 0x40c, 3, 1}
/* CODA_CMU */
/* CODA_CMU[0] */
/* CLK  */
#define CMUI_CODA_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CODA_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 4, 1}
/* GPU_CMU */
/* GPU_CMU[0] */
/* CLK  */
#define CMUI_GPU_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_GPU_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 5, 1}
/* HDMI_CMU */
/* HDMI_CMU[0] */
/* CLK  */
#define CMUI_HDMI_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_HDMI_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 6, 1}
/* WAVE_CMU */
/* WAVE_CMU[0] */
/* CLK  */
#define CMUI_WAVE_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 7, 1}
/* WAVE420_CMU */
/* WAVE420_CMU[0] */
/* CLK  */
#define CMUI_WAVE420_CMU_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_WAVE420_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 8, 1}
/* DREX_CMU */
/* DREX_CMU[0] */
/* CLK  */
#define CMUI_DREX_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_DREX_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 9, 1}
/* CPU_CMU */
/* CPU_CMU[0] */
/* CLK  */
#define CMUI_CPU_CMU_0_CLK_grp_clk_src		{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_dy_div_val		{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_dy_div_stop		{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_CPU_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 10, 1}
/* PERICLK_CMU */
/* PERICLK_CMU[0] */
/* CLK  */
#define CMUI_PERICLK_CMU_0_CLK_grp_clk_src	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_grp_a_div_rst	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_grp_gate_mode	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_div_rst		{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_dy_div_val	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_dy_div_stop	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_dy_div_busy_st	{0,0,0,0}
#define CMUI_PERICLK_CMU_0_CLK_clk_enb		{&SFR_INFO.CMU_SYS[0], 0x40c, 11, 1}
/* USB30 */
/* USB30[0] */
/* AXI  */
#define CMUI_USB30_0_AXI_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_grp_a_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_grp_gate_mode		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_dy_div_busy_st		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_AXI_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x20c, 1, 1}
/* APB  */
#define CMUI_USB30_0_APB_grp_clk_src		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_grp_a_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_grp_gate_mode		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_div_rst		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_dy_div_val		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_dy_div_stop		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_dy_div_busy_st		(_nx_cpuif_sym_){0,0,0,0}
#define CMUI_USB30_0_APB_clk_enb		(_nx_cpuif_sym_){&SFR_INFO.CMU_USB[0], 0x20c, 4, 1}
#endif // #ifndef _NX_CLOCKCONTROL_DEF_H_


