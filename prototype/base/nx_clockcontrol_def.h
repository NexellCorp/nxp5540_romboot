
#ifndef __NX_CLOCKCONTROL_DEF_H__
#define __NX_CLOCKCONTROL_DEF_H__

//======================================================================================================

//================================================
// define structure instance
//================================================
// clock on  : nx_cpuif_reg_write_one( CMU_INFO_DEF__SYS_0___AXI__clock_enable, 1 );
// clock off : nx_cpuif_reg_write_one( CMU_INFO_DEF__SYS_0___AXI__clock_enable, 1 );
//
// source  change : nx_cpuif_reg_write_one( CMU_INFO_DEF__SYS_0___AXI__group_clock_source , 3 );
// divider change : 
//
// 	nx_cpuif_reg_write_one( CMU_INFO_DEF__SYS_0___AXI__dynamic_divider_value , 2 );
// 	while( 1 == nx_cpuif_reg_read_one( CMU_INFO_DEF__SYS_0___AXI__dynamic_divider_busy_status ) );
// 
//================================================
/* SYS */
  /* SYS[0] */
	/* AXI  */
	#define CMU_INFO_DEF__SYS_0___AXI__group_clock_source		{ &SFR_INFO.CMU_SYS[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_SYS[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_SYS[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_SYS[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__dynamic_divider_stop		{ &SFR_INFO.CMU_SYS[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AXI__clock_enable			{ &SFR_INFO.CMU_SYS[0], 0x20c, 0, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__SYS_0___AHB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___AHB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___AHB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___AHB__divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AHB__dynamic_divider_value	{ &SFR_INFO.CMU_SYS[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AHB__dynamic_divider_stop		{ &SFR_INFO.CMU_SYS[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AHB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___AHB__clock_enable			{ &SFR_INFO.CMU_SYS[0], 0x20c, 4, 1 }
	/* APB  */
	#define CMU_INFO_DEF__SYS_0___APB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___APB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___APB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYS_0___APB__divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___APB__dynamic_divider_value	{ &SFR_INFO.CMU_SYS[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___APB__dynamic_divider_stop		{ &SFR_INFO.CMU_SYS[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___APB__clock_enable			{ &SFR_INFO.CMU_SYS[0], 0x20c, 5, 1 }
	/* OSCCLK  */
	#define CMU_INFO_DEF__SYS_0___OSCCLK__group_clock_source	{ &SFR_INFO.CMU_SYS[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__group_all_divider_reset	{ &SFR_INFO.CMU_SYS[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__group_gate_mode		{ &SFR_INFO.CMU_SYS[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__dynamic_divider_value	{ &SFR_INFO.CMU_SYS[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__dynamic_divider_stop	{ &SFR_INFO.CMU_SYS[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__SYS_0___OSCCLK__clock_enable		{ &SFR_INFO.CMU_SYS[0], 0x40c, 0, 1 }
/* BBUS */
  /* BBUS[0] */
	/* AXI  */
	#define CMU_INFO_DEF__BBUS_0___AXI__group_clock_source		{ &SFR_INFO.CMU_BBUS[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_BBUS[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_BBUS[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_BBUS[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__dynamic_divider_stop	{ &SFR_INFO.CMU_BBUS[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AXI__clock_enable		{ &SFR_INFO.CMU_BBUS[0], 0x20c, 0, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__BBUS_0___AHB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___AHB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___AHB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___AHB__divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AHB__dynamic_divider_value	{ &SFR_INFO.CMU_BBUS[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AHB__dynamic_divider_stop	{ &SFR_INFO.CMU_BBUS[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AHB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___AHB__clock_enable		{ &SFR_INFO.CMU_BBUS[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__BBUS_0___APB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___APB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___APB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_0___APB__divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___APB__dynamic_divider_value	{ &SFR_INFO.CMU_BBUS[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___APB__dynamic_divider_stop	{ &SFR_INFO.CMU_BBUS[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__BBUS_0___APB__clock_enable		{ &SFR_INFO.CMU_BBUS[0], 0x20c, 2, 1 }
/* TBUS */
  /* TBUS[0] */
	/* AXI  */
	#define CMU_INFO_DEF__TBUS_0___AXI__group_clock_source		{ &SFR_INFO.CMU_TBUS[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_TBUS[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_TBUS[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_TBUS[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__dynamic_divider_stop	{ &SFR_INFO.CMU_TBUS[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AXI__clock_enable		{ &SFR_INFO.CMU_TBUS[0], 0x20c, 0, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__TBUS_0___AHB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___AHB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___AHB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___AHB__divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AHB__dynamic_divider_value	{ &SFR_INFO.CMU_TBUS[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AHB__dynamic_divider_stop	{ &SFR_INFO.CMU_TBUS[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AHB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___AHB__clock_enable		{ &SFR_INFO.CMU_TBUS[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__TBUS_0___APB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___APB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___APB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_0___APB__divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___APB__dynamic_divider_value	{ &SFR_INFO.CMU_TBUS[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___APB__dynamic_divider_stop	{ &SFR_INFO.CMU_TBUS[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__TBUS_0___APB__clock_enable		{ &SFR_INFO.CMU_TBUS[0], 0x20c, 2, 1 }
/* LBUS */
  /* LBUS[0] */
	/* AXI  */
	#define CMU_INFO_DEF__LBUS_0___AXI__group_clock_source		{ &SFR_INFO.CMU_LBUS[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_LBUS[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_LBUS[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__divider_reset		{ &SFR_INFO.CMU_LBUS[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_LBUS[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__dynamic_divider_stop	{ &SFR_INFO.CMU_LBUS[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_LBUS[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AXI__clock_enable		{ &SFR_INFO.CMU_LBUS[0], 0x20c, 0, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__LBUS_0___AHB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___AHB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___AHB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___AHB__divider_reset		{ &SFR_INFO.CMU_LBUS[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AHB__dynamic_divider_value	{ &SFR_INFO.CMU_LBUS[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AHB__dynamic_divider_stop	{ &SFR_INFO.CMU_LBUS[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AHB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_LBUS[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___AHB__clock_enable		{ &SFR_INFO.CMU_LBUS[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__LBUS_0___APB__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___APB__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___APB__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_0___APB__divider_reset		{ &SFR_INFO.CMU_LBUS[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___APB__dynamic_divider_value	{ &SFR_INFO.CMU_LBUS[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___APB__dynamic_divider_stop	{ &SFR_INFO.CMU_LBUS[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_LBUS[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__LBUS_0___APB__clock_enable		{ &SFR_INFO.CMU_LBUS[0], 0x20c, 4, 1 }
/* USB */
  /* USB[0] */
	/* AXI  */
	#define CMU_INFO_DEF__USB_0___AXI__group_clock_source		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__group_all_divider_reset	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__group_gate_mode		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__dynamic_divider_value	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AXI__clock_enable			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x20c, 0, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__USB_0___AHB__group_clock_source		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___AHB__group_all_divider_reset	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___AHB__group_gate_mode		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___AHB__divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AHB__dynamic_divider_value	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AHB__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AHB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__USB_0___AHB__clock_enable			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x20c, 2, 1 }
	/* APB  */
	#define CMU_INFO_DEF__USB_0___APB__group_clock_source		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___APB__group_all_divider_reset	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___APB__group_gate_mode		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_0___APB__divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__USB_0___APB__dynamic_divider_value	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__USB_0___APB__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__USB_0___APB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__USB_0___APB__clock_enable			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x20c, 3, 1 }
/* ISP */
  /* ISP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__ISP_0___AXI__group_clock_source		{ &SFR_INFO.CMU_ISP[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_ISP[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_ISP[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__divider_reset		{ &SFR_INFO.CMU_ISP[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_ISP[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__dynamic_divider_stop		{ &SFR_INFO.CMU_ISP[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_ISP[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___AXI__clock_enable			{ &SFR_INFO.CMU_ISP[0], 0x20c, 0, 1 }
	/* DIV4  */
	#define CMU_INFO_DEF__ISP_0___DIV4__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_0___DIV4__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_0___DIV4__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_0___DIV4__divider_reset		{ &SFR_INFO.CMU_ISP[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___DIV4__dynamic_divider_value	{ &SFR_INFO.CMU_ISP[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___DIV4__dynamic_divider_stop	{ &SFR_INFO.CMU_ISP[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___DIV4__dynamic_divider_busy_status	{ &SFR_INFO.CMU_ISP[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__ISP_0___DIV4__clock_enable		{ &SFR_INFO.CMU_ISP[0], 0x20c, 1, 1 }
/* GPU */
  /* GPU[0] */
	/* AXI  */
	#define CMU_INFO_DEF__GPU_0___AXI__group_clock_source		{ &SFR_INFO.CMU_GPU[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__group_all_divider_reset	{ &SFR_INFO.CMU_GPU[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__group_gate_mode		{ &SFR_INFO.CMU_GPU[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__divider_reset		{ &SFR_INFO.CMU_GPU[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_GPU[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__dynamic_divider_stop		{ &SFR_INFO.CMU_GPU[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_GPU[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__GPU_0___AXI__clock_enable			{ &SFR_INFO.CMU_GPU[0], 0x20c, 0, 1 }
/* DREX0 */
  /* DREX0[0] */
	/* DREX  */
	#define CMU_INFO_DEF__DREX0_0___DREX__group_clock_source	{ &SFR_INFO.CMU_DREX0[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DREX__group_all_divider_reset	{ &SFR_INFO.CMU_DREX0[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DREX__group_gate_mode		{ &SFR_INFO.CMU_DREX0[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DREX__divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DREX__dynamic_divider_value	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DREX__dynamic_divider_stop	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DREX__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DREX__clock_enable		{ &SFR_INFO.CMU_DREX0[0], 0x20c, 0, 1 }
	/* DLL  */
	#define CMU_INFO_DEF__DREX0_0___DLL__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DLL__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DLL__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___DLL__divider_reset		{ &SFR_INFO.CMU_DREX0[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DLL__dynamic_divider_value	{ &SFR_INFO.CMU_DREX0[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DLL__dynamic_divider_stop	{ &SFR_INFO.CMU_DREX0[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DLL__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DREX0[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___DLL__clock_enable		{ &SFR_INFO.CMU_DREX0[0], 0x20c, 1, 1 }
	/* MEM  */
	#define CMU_INFO_DEF__DREX0_0___MEM__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___MEM__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___MEM__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___MEM__divider_reset		{ &SFR_INFO.CMU_DREX0[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___MEM__dynamic_divider_value	{ &SFR_INFO.CMU_DREX0[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___MEM__dynamic_divider_stop	{ &SFR_INFO.CMU_DREX0[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___MEM__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DREX0[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___MEM__clock_enable		{ &SFR_INFO.CMU_DREX0[0], 0x20c, 2, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__DREX0_0___AXI__group_clock_source		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___AXI__group_all_divider_reset	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___AXI__group_gate_mode		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___AXI__divider_reset		{ &SFR_INFO.CMU_DREX0[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___AXI__dynamic_divider_value	{ &SFR_INFO.CMU_DREX0[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_DREX0[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DREX0[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___AXI__clock_enable					{ &SFR_INFO.CMU_DREX0[0], 0x20c, 3, 1 }
	/* APB  */
	#define CMU_INFO_DEF__DREX0_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX0_0___APB__divider_reset				{ &SFR_INFO.CMU_DREX0[0], 0x304, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_DREX0[0], 0x308, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_DREX0[0], 0x30c, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DREX0[0], 0x310, 0, 32 }
	#define CMU_INFO_DEF__DREX0_0___APB__clock_enable					{ &SFR_INFO.CMU_DREX0[0], 0x20c, 4, 1 }
/* DISP */
  /* DISP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DISP_0___AXI__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__DISP_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_0___APB__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__DISP_0___APB__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 23, 1 }
/* HDMI */
  /* HDMI[0] */
	/* AXI  */
	#define CMU_INFO_DEF__HDMI_0___AXI__group_clock_source			{ &SFR_INFO.CMU_HDMI[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_HDMI[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_HDMI[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___AXI__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__HDMI_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_0___APB__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__HDMI_0___APB__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 2, 1 }
/* CPU */
  /* CPU[0] */
	/* ARM  */
	#define CMU_INFO_DEF__CPU_0___ARM__group_clock_source			{ &SFR_INFO.CMU_CPU[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__group_all_divider_reset		{ &SFR_INFO.CMU_CPU[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__group_gate_mode				{ &SFR_INFO.CMU_CPU[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__divider_reset				{ &SFR_INFO.CMU_CPU[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__dynamic_divider_value		{ &SFR_INFO.CMU_CPU[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__dynamic_divider_stop			{ &SFR_INFO.CMU_CPU[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CPU[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ARM__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 0, 1 }
	/* ACLK_COREM0  */
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__divider_reset				{ &SFR_INFO.CMU_CPU[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__dynamic_divider_value		{ &SFR_INFO.CMU_CPU[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__dynamic_divider_stop			{ &SFR_INFO.CMU_CPU[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CPU[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ACLK_COREM0__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 1, 1 }
	/* ATCLK  */
	#define CMU_INFO_DEF__CPU_0___ATCLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__divider_reset				{ &SFR_INFO.CMU_CPU[0], 0x2c4, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__dynamic_divider_value		{ &SFR_INFO.CMU_CPU[0], 0x2c8, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_CPU[0], 0x2cc, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CPU[0], 0x2d0, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___ATCLK__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 2, 1 }
	/* CNTCLK  */
	#define CMU_INFO_DEF__CPU_0___CNTCLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__divider_reset				{ &SFR_INFO.CMU_CPU[0], 0x304, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__dynamic_divider_value		{ &SFR_INFO.CMU_CPU[0], 0x308, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_CPU[0], 0x30c, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CPU[0], 0x310, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___CNTCLK__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 3, 1 }
	/* PCLK_DBG  */
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__divider_reset				{ &SFR_INFO.CMU_CPU[0], 0x344, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__dynamic_divider_value		{ &SFR_INFO.CMU_CPU[0], 0x348, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__dynamic_divider_stop			{ &SFR_INFO.CMU_CPU[0], 0x34c, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CPU[0], 0x350, 0, 32 }
	#define CMU_INFO_DEF__CPU_0___PCLK_DBG__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 4, 1 }
/* CODA */
  /* CODA[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CODA_0___AXI__group_clock_source			{ &SFR_INFO.CMU_CODA[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_CODA[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_CODA[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__divider_reset				{ &SFR_INFO.CMU_CODA[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_CODA[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_CODA[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CODA[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___AXI__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__CODA_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_0___APB__divider_reset				{ &SFR_INFO.CMU_CODA[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_CODA[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_CODA[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CODA[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__CODA_0___APB__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 3, 1 }
/* WAVE */
  /* WAVE[0] */
	/* AXI  */
	#define CMU_INFO_DEF__WAVE_0___AXI__group_clock_source			{ &SFR_INFO.CMU_WAVE[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_WAVE[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___AXI__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0x20c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__WAVE_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_0___APB__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__WAVE_0___APB__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0x20c, 1, 1 }
/* WAVE420 */
  /* WAVE420[0] */
	/* AXI  */
	#define CMU_INFO_DEF__WAVE420_0___AXI__group_clock_source			{ &SFR_INFO.CMU_WAVE420[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE420[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_WAVE420[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___AXI__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0x20c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__WAVE420_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_0___APB__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0x284, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0x288, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0x28c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0x290, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_0___APB__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0x20c, 1, 1 }
/* PERICLK */
  /* PERICLK[0] */
	/* APB  */
	#define CMU_INFO_DEF__PERICLK_0___APB__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x200, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x204, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x208, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x244, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x248, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x24c, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x250, 0, 32 }
	#define CMU_INFO_DEF__PERICLK_0___APB__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x20c, 0, 1 }
/* PLL */
  /* PLL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_0___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 0, 1 }
	/* DIV  */
	#define CMU_INFO_DEF__PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_0___DIV__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___DIV__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___DIV__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___DIV__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 1, 1 }
  /* PLL[1] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_1___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__PLL_1___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__PLL_1___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_1___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[2] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_2___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__PLL_2___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__PLL_2___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_2___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[3] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_3___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__PLL_3___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__PLL_3___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_3___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[4] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_4___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__PLL_4___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__PLL_4___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_4___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[5] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_5___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__PLL_5___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__PLL_5___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_5___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[6] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_6___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1200, 0, 32 }
	#define CMU_INFO_DEF__PLL_6___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1204, 0, 32 }
	#define CMU_INFO_DEF__PLL_6___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1208, 0, 32 }
	#define CMU_INFO_DEF__PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_6___DIV__clock_enable					{ 0,0,0,0 }
  /* PLL[7] */
	/* CLK  */
	#define CMU_INFO_DEF__PLL_7___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1400, 0, 32 }
	#define CMU_INFO_DEF__PLL_7___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1404, 0, 32 }
	#define CMU_INFO_DEF__PLL_7___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1408, 0, 32 }
	#define CMU_INFO_DEF__PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 0, 1 }
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PLL_7___DIV__clock_enable					{ 0,0,0,0 }
/* USBOPHY */
  /* USBOPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__USBOPHY_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1600, 0, 32 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1604, 0, 32 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1608, 0, 32 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__divider_reset				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__dynamic_divider_value		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBOPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x160c, 0, 1 }
/* USBHPHY */
  /* USBHPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__USBHPHY_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1800, 0, 32 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1804, 0, 32 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x1808, 0, 32 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__divider_reset				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__dynamic_divider_value		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USBHPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x180c, 0, 1 }
/* HDMIPHY_PIXEL */
  /* HDMIPHY_PIXEL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1a00, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1a04, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1a08, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_PIXEL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1a0c, 0, 1 }
/* HDMIPHY_TMDS */
  /* HDMIPHY_TMDS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1c00, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1c04, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1c08, 0, 32 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIPHY_TMDS_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1c0c, 0, 1 }
/* BBUS_PLL */
  /* BBUS_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 2, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* BBUS_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 1, 1 }
  /* BBUS_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 1, 1 }
  /* BBUS_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 1, 1 }
  /* BBUS_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 1, 1 }
  /* BBUS_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 1, 1 }
  /* BBUS_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 1, 1 }
  /* BBUS_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 1, 1 }
/* BBUS_USBOPHY */
  /* BBUS_USBOPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__dynamic_divider_stop		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBOPHY_0___CLK__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x160c, 1, 1 }
/* BBUS_USBHPHY */
  /* BBUS_USBHPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__dynamic_divider_stop		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_USBHPHY_0___CLK__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x180c, 1, 1 }
/* BBUS_HDMIPHY_PIXEL */
  /* BBUS_HDMIPHY_PIXEL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_PIXEL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1a0c, 1, 1 }
/* BBUS_HDMIPHY_TMDS */
  /* BBUS_HDMIPHY_TMDS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUS_HDMIPHY_TMDS_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1c0c, 1, 1 }
/* TBUS_PLL */
  /* TBUS_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 3, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* TBUS_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 2, 1 }
  /* TBUS_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 2, 1 }
  /* TBUS_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 2, 1 }
  /* TBUS_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 2, 1 }
  /* TBUS_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 2, 1 }
  /* TBUS_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 2, 1 }
  /* TBUS_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 2, 1 }
/* TBUS_USBOPHY */
  /* TBUS_USBOPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__dynamic_divider_stop		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBOPHY_0___CLK__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x160c, 2, 1 }
/* TBUS_USBHPHY */
  /* TBUS_USBHPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__dynamic_divider_stop		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_USBHPHY_0___CLK__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x180c, 2, 1 }
/* TBUS_HDMIPHY_PIXEL */
  /* TBUS_HDMIPHY_PIXEL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_PIXEL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1a0c, 2, 1 }
/* TBUS_HDMIPHY_TMDS */
  /* TBUS_HDMIPHY_TMDS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TBUS_HDMIPHY_TMDS_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1c0c, 2, 1 }
/* LBUS_PLL */
  /* LBUS_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 4, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* LBUS_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 3, 1 }
  /* LBUS_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 3, 1 }
  /* LBUS_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 3, 1 }
  /* LBUS_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 3, 1 }
  /* LBUS_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 3, 1 }
  /* LBUS_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 3, 1 }
  /* LBUS_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 3, 1 }
/* LBUS_USBOPHY */
  /* LBUS_USBOPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBOPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x160c, 3, 1 }
/* LBUS_USBHPHY */
  /* LBUS_USBHPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_USBHPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x180c, 3, 1 }
/* LBUS_HDMIPHY_PIXEL */
  /* LBUS_HDMIPHY_PIXEL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_PIXEL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1a0c, 3, 1 }
/* LBUS_HDMIPHY_TMDS */
  /* LBUS_HDMIPHY_TMDS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUS_HDMIPHY_TMDS_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1c0c, 3, 1 }
/* DISP_PLL */
  /* DISP_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 5, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* DISP_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 4, 1 }
  /* DISP_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 4, 1 }
  /* DISP_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 4, 1 }
  /* DISP_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 4, 1 }
  /* DISP_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 4, 1 }
  /* DISP_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 4, 1 }
  /* DISP_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 4, 1 }
/* HDMI_PLL */
  /* HDMI_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 6, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* HDMI_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 5, 1 }
  /* HDMI_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 5, 1 }
  /* HDMI_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 5, 1 }
  /* HDMI_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 5, 1 }
  /* HDMI_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 5, 1 }
  /* HDMI_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 5, 1 }
  /* HDMI_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 5, 1 }
/* CODA_PLL */
  /* CODA_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 7, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* CODA_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 6, 1 }
  /* CODA_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 6, 1 }
  /* CODA_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 6, 1 }
  /* CODA_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 6, 1 }
  /* CODA_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 6, 1 }
  /* CODA_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 6, 1 }
  /* CODA_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 6, 1 }
/* WAVE_PLL */
  /* WAVE_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 8, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* WAVE_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 7, 1 }
  /* WAVE_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 7, 1 }
  /* WAVE_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 7, 1 }
  /* WAVE_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 7, 1 }
  /* WAVE_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 7, 1 }
  /* WAVE_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 7, 1 }
  /* WAVE_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 7, 1 }
/* WAVE420_PLL */
  /* WAVE420_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 9, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* WAVE420_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 8, 1 }
  /* WAVE420_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 8, 1 }
  /* WAVE420_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 8, 1 }
  /* WAVE420_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 8, 1 }
  /* WAVE420_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 8, 1 }
  /* WAVE420_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 8, 1 }
  /* WAVE420_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 8, 1 }
/* USB_PLL */
  /* USB_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__USB_PLL_0___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___DIV__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x60c, 10, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_0___CLK__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
  /* USB_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_1___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_1___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_1___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x80c, 9, 1 }
  /* USB_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_2___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_2___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_2___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0xa0c, 9, 1 }
  /* USB_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_3___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_3___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_3___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0xc0c, 9, 1 }
  /* USB_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_4___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_4___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_4___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0xe0c, 9, 1 }
  /* USB_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_5___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_5___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_5___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x100c, 9, 1 }
  /* USB_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_6___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_6___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_6___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x120c, 9, 1 }
  /* USB_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__USB_PLL_7___DIV__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___DIV__clock_enable					    (__nx_cpuif_symbol__){ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__USB_PLL_7___CLK__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_PLL_7___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x140c, 9, 1 }
/* ISP_PLL */
  /* ISP_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 11, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* ISP_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 10, 1 }
  /* ISP_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 10, 1 }
  /* ISP_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 10, 1 }
  /* ISP_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 10, 1 }
  /* ISP_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 10, 1 }
  /* ISP_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 10, 1 }
  /* ISP_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 10, 1 }
/* GPU_PLL */
  /* GPU_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 12, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* GPU_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 11, 1 }
  /* GPU_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 11, 1 }
  /* GPU_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 11, 1 }
  /* GPU_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 11, 1 }
  /* GPU_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 11, 1 }
  /* GPU_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 11, 1 }
  /* GPU_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 11, 1 }
/* PERICLK_PLL */
  /* PERICLK_PLL[0] */
	/* DIV  */
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___DIV__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x60c, 13, 1 }
	/* CLK :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_0___CLK__clock_enable					{ 0,0,0,0 }
  /* PERICLK_PLL[1] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_1___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x80c, 12, 1 }
  /* PERICLK_PLL[2] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_2___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xa0c, 12, 1 }
  /* PERICLK_PLL[3] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_3___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xc0c, 12, 1 }
  /* PERICLK_PLL[4] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_4___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0xe0c, 12, 1 }
  /* PERICLK_PLL[5] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_5___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x100c, 12, 1 }
  /* PERICLK_PLL[6] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_6___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x120c, 12, 1 }
  /* PERICLK_PLL[7] */
	/* DIV :not_using_div */
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___DIV__clock_enable					{ 0,0,0,0 }
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_PLL_7___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x140c, 12, 1 }
/* PERICLK_USBOPHY */
  /* PERICLK_USBOPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__divider_reset				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__dynamic_divider_value		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBOPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x160c, 4, 1 }
/* PERICLK_USBHPHY */
  /* PERICLK_USBHPHY[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__divider_reset				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__dynamic_divider_value		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_USBHPHY_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x180c, 4, 1 }
/* PERICLK_HDMIPHY_PIXEL */
  /* PERICLK_HDMIPHY_PIXEL[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_PIXEL_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1a0c, 4, 1 }
/* PERICLK_HDMIPHY_TMDS */
  /* PERICLK_HDMIPHY_TMDS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_HDMIPHY_TMDS_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1c0c, 4, 1 }
/* PDM */
  /* PDM[0] */
	/* APB  */
	#define CMU_INFO_DEF__PDM_0___APB__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x1e00, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x1e04, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x1e08, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x1e44, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x1e48, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x1e4c, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x1e50, 0, 32 }
	#define CMU_INFO_DEF__PDM_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x1e0c, 0, 1 }
  /* PDM[1] */
	/* APB  */
	#define CMU_INFO_DEF__PDM_1___APB__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2000, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2004, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2008, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2044, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2048, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x204c, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2050, 0, 32 }
	#define CMU_INFO_DEF__PDM_1___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x200c, 0, 1 }
  /* PDM[2] */
	/* APB  */
	#define CMU_INFO_DEF__PDM_2___APB__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2200, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2204, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2208, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2244, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2248, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x224c, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2250, 0, 32 }
	#define CMU_INFO_DEF__PDM_2___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x220c, 0, 1 }
  /* PDM[3] */
	/* APB  */
	#define CMU_INFO_DEF__PDM_3___APB__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2400, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2404, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2408, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2444, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2448, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x244c, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2450, 0, 32 }
	#define CMU_INFO_DEF__PDM_3___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x240c, 0, 1 }
/* AUDIO_IO_CTRL */
  /* AUDIO_IO_CTRL[0] */
	/* APB  */
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2600, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2604, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2608, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2644, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2648, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x264c, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2650, 0, 32 }
	#define CMU_INFO_DEF__AUDIO_IO_CTRL_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x260c, 0, 1 }
/* UART */
  /* UART[0] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_0___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__UART_0___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x40c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 3, 1 }
  /* UART[1] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_1___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__UART_1___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x60c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_1___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 4, 1 }
  /* UART[2] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_2___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__UART_2___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x80c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_2___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 5, 1 }
  /* UART[3] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_3___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__UART_3___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0xa0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_3___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 6, 1 }
  /* UART[4] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_4___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0xc44, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0xc48, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0xc4c, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0xc50, 0, 32 }
	#define CMU_INFO_DEF__UART_4___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0xc0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_4___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 7, 1 }
  /* UART[5] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_5___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0xe44, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0xe48, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0xe4c, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0xe50, 0, 32 }
	#define CMU_INFO_DEF__UART_5___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0xe0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_5___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_5___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 8, 1 }
  /* UART[6] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_6___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x1044, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x1048, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x104c, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x1050, 0, 32 }
	#define CMU_INFO_DEF__UART_6___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x100c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_6___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_6___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 9, 1 }
  /* UART[7] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_7___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x1200, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x1204, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x1208, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x1244, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x1248, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x124c, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x1250, 0, 32 }
	#define CMU_INFO_DEF__UART_7___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x120c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_7___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_7___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 10, 1 }
  /* UART[8] */
	/* CORE  */
	#define CMU_INFO_DEF__UART_8___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x1400, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x1404, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x1408, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x1444, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x1448, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x144c, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x1450, 0, 32 }
	#define CMU_INFO_DEF__UART_8___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x140c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__UART_8___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__UART_8___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 11, 1 }
/* SPI */
  /* SPI[0] */
	/* APB  */
	#define CMU_INFO_DEF__SPI_0___APB__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1600, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1604, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1608, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1644, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1648, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x164c, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1650, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___APB__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x160c, 0, 1 }
	/* CORE  */
	#define CMU_INFO_DEF__SPI_0___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1800, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1804, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1808, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1844, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1848, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x184c, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1850, 0, 32 }
	#define CMU_INFO_DEF__SPI_0___CORE__clock_enable				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x180c, 0, 1 }
  /* SPI[1] */
	/* APB  */
	#define CMU_INFO_DEF__SPI_1___APB__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a00, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a04, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a08, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a44, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a48, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a4c, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a50, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___APB__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1a0c, 0, 1 }
	/* CORE  */
	#define CMU_INFO_DEF__SPI_1___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c00, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c04, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c08, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c44, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c48, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c4c, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c50, 0, 32 }
	#define CMU_INFO_DEF__SPI_1___CORE__clock_enable				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1c0c, 0, 1 }
  /* SPI[2] */
	/* APB  */
	#define CMU_INFO_DEF__SPI_2___APB__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e00, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e04, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e08, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e44, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e48, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e4c, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e50, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___APB__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x1e0c, 0, 1 }
	/* CORE  */
	#define CMU_INFO_DEF__SPI_2___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2000, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2004, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2008, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__divider_reset				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2044, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__dynamic_divider_value		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2048, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__dynamic_divider_stop		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x204c, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x2050, 0, 32 }
	#define CMU_INFO_DEF__SPI_2___CORE__clock_enable				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_BBUS[0], 0x200c, 0, 1 }
/* SPDIFTX */
  /* SPDIFTX[0] */
	/* CORE  */
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__group_clock_source			{ &SFR_INFO.CMU_BBUS[0], 0x2200, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_BBUS[0], 0x2204, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_BBUS[0], 0x2208, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__divider_reset				{ &SFR_INFO.CMU_BBUS[0], 0x2244, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_BBUS[0], 0x2248, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_BBUS[0], 0x224c, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_BBUS[0], 0x2250, 0, 32 }
	#define CMU_INFO_DEF__SPDIFTX_0___CORE__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x220c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__SPDIFTX_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFTX_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 12, 1 }
/* I2S */
  /* I2S[0] */
	/* CORE  */
	#define CMU_INFO_DEF__I2S_0___CORE__group_clock_source			{ &SFR_INFO.CMU_TBUS[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_TBUS[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__divider_reset				{ &SFR_INFO.CMU_TBUS[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_TBUS[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_TBUS[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__I2S_0___CORE__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x40c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__I2S_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_0___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 3, 1 }
  /* I2S[1] */
	/* CORE  */
	#define CMU_INFO_DEF__I2S_1___CORE__group_clock_source			{ &SFR_INFO.CMU_TBUS[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__group_gate_mode				{ &SFR_INFO.CMU_TBUS[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__divider_reset				{ &SFR_INFO.CMU_TBUS[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_TBUS[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_TBUS[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__I2S_1___CORE__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x60c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__I2S_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_1___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 4, 1 }
  /* I2S[2] */
	/* CORE  */
	#define CMU_INFO_DEF__I2S_2___CORE__group_clock_source			{ &SFR_INFO.CMU_TBUS[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__group_gate_mode				{ &SFR_INFO.CMU_TBUS[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__divider_reset				{ &SFR_INFO.CMU_TBUS[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_TBUS[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_TBUS[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__I2S_2___CORE__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x80c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__I2S_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_2___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 5, 1 }
  /* I2S[3] */
	/* CORE  */
	#define CMU_INFO_DEF__I2S_3___CORE__group_clock_source			{ &SFR_INFO.CMU_TBUS[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_TBUS[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__group_gate_mode				{ &SFR_INFO.CMU_TBUS[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__divider_reset				{ &SFR_INFO.CMU_TBUS[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_TBUS[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_TBUS[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_TBUS[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__I2S_3___CORE__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0xa0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__I2S_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2S_3___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 6, 1 }
/* SDMMC */
  /* SDMMC[0] */
	/* CORE  */
	#define CMU_INFO_DEF__SDMMC_0___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___CORE__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x40c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__SDMMC_0___AXI__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_0___AXI__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x60c, 0, 1 }
  /* SDMMC[1] */
	/* CORE  */
	#define CMU_INFO_DEF__SDMMC_1___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___CORE__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0x80c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__SDMMC_1___AXI__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_1___AXI__clock_enable					(__nx_cpuif_symbol__)(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xa0c, 0, 1 }
  /* SDMMC[2] */
	/* CORE  */
	#define CMU_INFO_DEF__SDMMC_2___CORE__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc44, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc48, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc4c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc50, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___CORE__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xc0c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__SDMMC_2___AXI__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe44, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe48, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe4c, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe50, 0, 32 }
	#define CMU_INFO_DEF__SDMMC_2___AXI__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_LBUS[0], 0xe0c, 0, 1 }
/* GMAC */
  /* GMAC[0] */
	/* MII  */
	#define CMU_INFO_DEF__GMAC_0___MII__group_clock_source			{ &SFR_INFO.CMU_LBUS[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__group_all_divider_reset		{ &SFR_INFO.CMU_LBUS[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__group_gate_mode				{ &SFR_INFO.CMU_LBUS[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__divider_reset				{ &SFR_INFO.CMU_LBUS[0], 0x1044, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__dynamic_divider_value		{ &SFR_INFO.CMU_LBUS[0], 0x1048, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__dynamic_divider_stop			{ &SFR_INFO.CMU_LBUS[0], 0x104c, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__dynamic_divider_busy_status	{ &SFR_INFO.CMU_LBUS[0], 0x1050, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___MII__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x100c, 0, 1 }
	/* TX_CLK  */
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__divider_reset				{ &SFR_INFO.CMU_LBUS[0], 0x1084, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__dynamic_divider_value		{ &SFR_INFO.CMU_LBUS[0], 0x1088, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_LBUS[0], 0x108c, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_LBUS[0], 0x1090, 0, 32 }
	#define CMU_INFO_DEF__GMAC_0___TX_CLK__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x100c, 1, 1 }
	/* AHB  */
	#define CMU_INFO_DEF__GMAC_0___AHB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___AHB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 2, 1 }
	/* CSR  */
	#define CMU_INFO_DEF__GMAC_0___CSR__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GMAC_0___CSR__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 5, 1 }
/* PKA */
  /* PKA[0] */
	/* CORE  */
	#define CMU_INFO_DEF__PKA_0___CORE__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2800, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2804, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2808, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2844, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2848, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x284c, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2850, 0, 32 }
	#define CMU_INFO_DEF__PKA_0___CORE__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x280c, 0, 1 }
/* CSSYS_SRC */
  /* CSSYS_SRC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2a00, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2a04, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2a08, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2a44, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2a48, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x2a4c, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2a50, 0, 32 }
	#define CMU_INFO_DEF__CSSYS_SRC_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x2a0c, 0, 1 }
/* MCUSTOP */
  /* MCUSTOP[0] */
	/* CLK  */
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2c00, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2c04, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2c08, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2c44, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2c48, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x2c4c, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2c50, 0, 32 }
	#define CMU_INFO_DEF__MCUSTOP_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x2c0c, 0, 1 }
/* TIMER */
  /* TIMER[0] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_0___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x2e00, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x2e04, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x2e08, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x2e44, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x2e48, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x2e4c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x2e50, 0, 32 }
	#define CMU_INFO_DEF__TIMER_0___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x2e0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__TIMER_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 6, 1 }
  /* TIMER[1] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_1___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3000, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3004, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3008, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3044, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3048, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x304c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3050, 0, 32 }
	#define CMU_INFO_DEF__TIMER_1___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x300c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_1___APB__clock_enable					{ 0,0,0,0 }
  /* TIMER[2] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_2___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3200, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3204, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3208, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3244, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3248, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x324c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3250, 0, 32 }
	#define CMU_INFO_DEF__TIMER_2___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x320c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_2___APB__clock_enable					{ 0,0,0,0 }
  /* TIMER[3] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_3___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3400, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3404, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3408, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3444, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3448, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x344c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3450, 0, 32 }
	#define CMU_INFO_DEF__TIMER_3___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x340c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_3___APB__clock_enable					{ 0,0,0,0 }
  /* TIMER[4] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_4___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3600, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3604, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3608, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3644, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3648, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x364c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3650, 0, 32 }
	#define CMU_INFO_DEF__TIMER_4___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x360c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__TIMER_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_4___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 7, 1 }
  /* TIMER[5] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_5___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3800, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3804, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3808, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3844, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3848, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x384c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3850, 0, 32 }
	#define CMU_INFO_DEF__TIMER_5___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x380c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_5___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_5___APB__clock_enable					{ 0,0,0,0 }
  /* TIMER[6] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_6___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3a00, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3a04, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3a08, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3a44, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3a48, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x3a4c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3a50, 0, 32 }
	#define CMU_INFO_DEF__TIMER_6___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x3a0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_6___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_6___APB__clock_enable					{ 0,0,0,0 }
  /* TIMER[7] */
	/* TCLK  */
	#define CMU_INFO_DEF__TIMER_7___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3c00, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3c04, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3c08, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3c44, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3c48, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x3c4c, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3c50, 0, 32 }
	#define CMU_INFO_DEF__TIMER_7___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x3c0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__TIMER_7___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIMER_7___APB__clock_enable					{ 0,0,0,0 }
/* PWM */
  /* PWM[0] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_0___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x3e00, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x3e04, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x3e08, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x3e44, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x3e48, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x3e4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x3e50, 0, 32 }
	#define CMU_INFO_DEF__PWM_0___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x3e0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__PWM_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 8, 1 }
  /* PWM[1] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_1___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4000, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4004, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4008, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4044, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4048, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x404c, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4050, 0, 32 }
	#define CMU_INFO_DEF__PWM_1___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x400c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_1___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[2] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_2___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4200, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4204, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4208, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4244, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4248, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x424c, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4250, 0, 32 }
	#define CMU_INFO_DEF__PWM_2___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x420c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_2___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[3] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_3___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4400, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4404, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4408, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4444, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4448, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x444c, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4450, 0, 32 }
	#define CMU_INFO_DEF__PWM_3___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x440c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_3___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[4] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_4___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4600, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4604, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4608, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4644, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4648, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x464c, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4650, 0, 32 }
	#define CMU_INFO_DEF__PWM_4___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x460c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__PWM_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_4___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 9, 1 }
  /* PWM[5] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_5___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4800, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4804, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4808, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4844, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4848, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x484c, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4850, 0, 32 }
	#define CMU_INFO_DEF__PWM_5___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x480c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_5___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_5___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[6] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_6___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4a00, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4a04, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4a08, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4a44, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4a48, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x4a4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4a50, 0, 32 }
	#define CMU_INFO_DEF__PWM_6___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x4a0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_6___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_6___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[7] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_7___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4c00, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4c04, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4c08, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4c44, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4c48, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x4c4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4c50, 0, 32 }
	#define CMU_INFO_DEF__PWM_7___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x4c0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_7___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_7___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[8] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_8___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x4e00, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x4e04, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x4e08, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x4e44, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x4e48, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x4e4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x4e50, 0, 32 }
	#define CMU_INFO_DEF__PWM_8___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x4e0c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__PWM_8___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_8___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 10, 1 }
  /* PWM[9] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_9___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5000, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5004, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5008, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5044, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5048, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x504c, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5050, 0, 32 }
	#define CMU_INFO_DEF__PWM_9___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x500c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_9___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_9___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[10] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_10___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5200, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5204, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5208, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5244, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5248, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x524c, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5250, 0, 32 }
	#define CMU_INFO_DEF__PWM_10___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x520c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_10___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_10___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[11] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_11___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5400, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5404, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5408, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5444, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5448, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x544c, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5450, 0, 32 }
	#define CMU_INFO_DEF__PWM_11___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x540c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_11___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_11___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[12] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_12___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5600, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5604, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5608, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5644, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5648, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x564c, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5650, 0, 32 }
	#define CMU_INFO_DEF__PWM_12___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x560c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__PWM_12___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_12___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 11, 1 }
  /* PWM[13] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_13___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5800, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5804, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5808, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5844, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5848, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x584c, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5850, 0, 32 }
	#define CMU_INFO_DEF__PWM_13___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x580c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_13___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_13___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[14] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_14___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5a00, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5a04, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5a08, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5a44, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5a48, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x5a4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5a50, 0, 32 }
	#define CMU_INFO_DEF__PWM_14___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x5a0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_14___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_14___APB__clock_enable					{ 0,0,0,0 }
  /* PWM[15] */
	/* TCLK  */
	#define CMU_INFO_DEF__PWM_15___TCLK__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5c00, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5c04, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5c08, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5c44, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5c48, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x5c4c, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5c50, 0, 32 }
	#define CMU_INFO_DEF__PWM_15___TCLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x5c0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PWM_15___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PWM_15___APB__clock_enable					{ 0,0,0,0 }
/* PO */
  /* PO[0] */
	/* OUT  */
	#define CMU_INFO_DEF__PO_0___OUT__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x5e00, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x5e04, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x5e08, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x5e44, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x5e48, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x5e4c, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x5e50, 0, 32 }
	#define CMU_INFO_DEF__PO_0___OUT__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x5e0c, 0, 1 }
  /* PO[1] */
	/* OUT  */
	#define CMU_INFO_DEF__PO_1___OUT__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6000, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6004, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6008, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6044, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6048, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x604c, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6050, 0, 32 }
	#define CMU_INFO_DEF__PO_1___OUT__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x600c, 0, 1 }
  /* PO[2] */
	/* OUT  */
	#define CMU_INFO_DEF__PO_2___OUT__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6200, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6204, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6208, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6244, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6248, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x624c, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6250, 0, 32 }
	#define CMU_INFO_DEF__PO_2___OUT__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x620c, 0, 1 }
  /* PO[3] */
	/* OUT  */
	#define CMU_INFO_DEF__PO_3___OUT__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6400, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6404, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6408, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6444, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6448, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x644c, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6450, 0, 32 }
	#define CMU_INFO_DEF__PO_3___OUT__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x640c, 0, 1 }
  /* PO[4] */
	/* OUT  */
	#define CMU_INFO_DEF__PO_4___OUT__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6600, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6604, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6608, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6644, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6648, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x664c, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6650, 0, 32 }
	#define CMU_INFO_DEF__PO_4___OUT__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x660c, 0, 1 }
/* PPM */
  /* PPM[0] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_0___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__PPM_0___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x40c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__PPM_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_0___APB__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x20c, 1, 1 }
  /* PPM[1] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_1___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__PPM_1___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x60c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_1___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[2] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_2___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__PPM_2___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x80c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_2___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[3] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_3___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__PPM_3___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0xa0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_3___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[4] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_4___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0xc44, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0xc48, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0xc4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0xc50, 0, 32 }
	#define CMU_INFO_DEF__PPM_4___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0xc0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_4___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[5] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_5___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0xe44, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0xe48, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0xe4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0xe50, 0, 32 }
	#define CMU_INFO_DEF__PPM_5___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0xe0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_5___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_5___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[6] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_6___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1044, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1048, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x104c, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1050, 0, 32 }
	#define CMU_INFO_DEF__PPM_6___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x100c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_6___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_6___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[7] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_7___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1200, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1204, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1208, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1244, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1248, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x124c, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1250, 0, 32 }
	#define CMU_INFO_DEF__PPM_7___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x120c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_7___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_7___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[8] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_8___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1400, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1404, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1408, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1444, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1448, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x144c, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1450, 0, 32 }
	#define CMU_INFO_DEF__PPM_8___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x140c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_8___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_8___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[9] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_9___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1600, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1604, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1608, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1644, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1648, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x164c, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1650, 0, 32 }
	#define CMU_INFO_DEF__PPM_9___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x160c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_9___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_9___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[10] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_10___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1800, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1804, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1808, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1844, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1848, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x184c, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1850, 0, 32 }
	#define CMU_INFO_DEF__PPM_10___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x180c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_10___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_10___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[11] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_11___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1a00, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1a04, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1a08, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1a44, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1a48, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x1a4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1a50, 0, 32 }
	#define CMU_INFO_DEF__PPM_11___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x1a0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_11___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_11___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[12] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_12___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1c00, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1c04, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1c08, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1c44, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1c48, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x1c4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1c50, 0, 32 }
	#define CMU_INFO_DEF__PPM_12___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x1c0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_12___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_12___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[13] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_13___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x1e00, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x1e04, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x1e08, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x1e44, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x1e48, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x1e4c, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x1e50, 0, 32 }
	#define CMU_INFO_DEF__PPM_13___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x1e0c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_13___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_13___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[14] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_14___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x2000, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x2004, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x2008, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x2044, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x2048, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x204c, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x2050, 0, 32 }
	#define CMU_INFO_DEF__PPM_14___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x200c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_14___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_14___APB__clock_enable					{ 0,0,0,0 }
  /* PPM[15] */
	/* PPMCLK  */
	#define CMU_INFO_DEF__PPM_15___PPMCLK__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x2200, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x2204, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x2208, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x2244, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x2248, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x224c, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x2250, 0, 32 }
	#define CMU_INFO_DEF__PPM_15___PPMCLK__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x220c, 0, 1 }
	/* APB :not_using_div */
	#define CMU_INFO_DEF__PPM_15___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PPM_15___APB__clock_enable					{ 0,0,0,0 }
/* DPC */
  /* DPC[0] */
	/* X2  */
	#define CMU_INFO_DEF__DPC_0___X2__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X2__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x40c, 0, 1 }
	/* X1  */
	#define CMU_INFO_DEF__DPC_0___X1__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___X1__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___X1__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___X1__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x484, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X1__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x488, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X1__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x48c, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X1__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x490, 0, 32 }
	#define CMU_INFO_DEF__DPC_0___X1__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x40c, 1, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__DPC_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 3, 1 }
  /* DPC[1] */
	/* X2  */
	#define CMU_INFO_DEF__DPC_1___X2__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X2__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x60c, 0, 1 }
	/* X1  */
	#define CMU_INFO_DEF__DPC_1___X1__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___X1__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___X1__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___X1__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x684, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X1__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x688, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X1__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x68c, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X1__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x690, 0, 32 }
	#define CMU_INFO_DEF__DPC_1___X1__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x60c, 1, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__DPC_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DPC_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 4, 1 }
/* MIPI */
  /* MIPI[0] */
	/* X2  */
	#define CMU_INFO_DEF__MIPI_0___X2__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X2__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x80c, 0, 1 }
	/* X1  */
	#define CMU_INFO_DEF__MIPI_0___X1__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___X1__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___X1__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___X1__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x884, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X1__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x888, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X1__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x88c, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X1__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x890, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___X1__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x80c, 1, 1 }
	/* CSI  */
	#define CMU_INFO_DEF__MIPI_0___CSI__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__MIPI_0___CSI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0xa0c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__MIPI_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 1, 1 }
	/* APBCSI  */
	#define CMU_INFO_DEF__MIPI_0___APBCSI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBCSI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 28, 1 }
	/* APBDSI  */
	#define CMU_INFO_DEF__MIPI_0___APBDSI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___APBDSI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 29, 1 }
	/* CSIPHY  */
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MIPI_0___CSIPHY__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 30, 1 }
/* LVDS */
  /* LVDS[0] */
	/* VCLK  */
	#define CMU_INFO_DEF__LVDS_0___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0xc44, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0xc48, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0xc4c, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0xc50, 0, 32 }
	#define CMU_INFO_DEF__LVDS_0___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0xc0c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__LVDS_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 5, 1 }
	/* PHY  */
	#define CMU_INFO_DEF__LVDS_0___PHY__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_0___PHY__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 6, 1 }
  /* LVDS[1] */
	/* VCLK  */
	#define CMU_INFO_DEF__LVDS_1___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0xe44, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0xe48, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0xe4c, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0xe50, 0, 32 }
	#define CMU_INFO_DEF__LVDS_1___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0xe0c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__LVDS_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 7, 1 }
	/* PHY  */
	#define CMU_INFO_DEF__LVDS_1___PHY__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LVDS_1___PHY__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 8, 1 }
/* VIP */
  /* VIP[0] */
	/* VCLK  */
	#define CMU_INFO_DEF__VIP_0___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1044, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1048, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x104c, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1050, 0, 32 }
	#define CMU_INFO_DEF__VIP_0___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x100c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__VIP_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 17, 1 }
  /* VIP[1] */
	/* VCLK  */
	#define CMU_INFO_DEF__VIP_1___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1200, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1204, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1208, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1244, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1248, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x124c, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1250, 0, 32 }
	#define CMU_INFO_DEF__VIP_1___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x120c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__VIP_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 18, 1 }
  /* VIP[2] */
	/* VCLK  */
	#define CMU_INFO_DEF__VIP_2___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1400, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1404, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1408, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1444, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1448, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x144c, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1450, 0, 32 }
	#define CMU_INFO_DEF__VIP_2___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x140c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__VIP_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 19, 1 }
  /* VIP[3] */
	/* VCLK  */
	#define CMU_INFO_DEF__VIP_3___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1600, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1604, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1608, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1644, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1648, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x164c, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1650, 0, 32 }
	#define CMU_INFO_DEF__VIP_3___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x160c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__VIP_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 20, 1 }
/* DEINTERLACE */
  /* DEINTERLACE[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1800, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1804, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1808, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1844, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1848, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x184c, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1850, 0, 32 }
	#define CMU_INFO_DEF__DEINTERLACE_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x180c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DEINTERLACE_0___APB__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 24, 1 }
/* MAPCONV */
  /* MAPCONV[0] */
	/* AXI  */
	#define CMU_INFO_DEF__MAPCONV_0___AXI__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1a00, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1a04, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1a08, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1a44, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1a48, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x1a4c, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1a50, 0, 32 }
	#define CMU_INFO_DEF__MAPCONV_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x1a0c, 0, 1 }
/* HDMIV2 */
  /* HDMIV2[0] */
	/* TMDS_10B  */
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__group_clock_source			{ &SFR_INFO.CMU_HDMI[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__group_all_divider_reset		{ &SFR_INFO.CMU_HDMI[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__group_gate_mode				{ &SFR_INFO.CMU_HDMI[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_10B__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x40c, 0, 1 }
	/* TMDS_20B  */
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x484, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x488, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x48c, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x490, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___TMDS_20B__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x40c, 1, 1 }
	/* PIXELX2  */
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__group_clock_source			{ &SFR_INFO.CMU_HDMI[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__group_all_divider_reset		{ &SFR_INFO.CMU_HDMI[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__group_gate_mode				{ &SFR_INFO.CMU_HDMI[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXELX2__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x60c, 0, 1 }
	/* PIXEL  */
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x684, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x688, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x68c, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x690, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___PIXEL__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x60c, 1, 1 }
	/* AUDIO  */
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__group_clock_source			{ &SFR_INFO.CMU_HDMI[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__group_all_divider_reset		{ &SFR_INFO.CMU_HDMI[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__group_gate_mode				{ &SFR_INFO.CMU_HDMI[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__divider_reset				{ &SFR_INFO.CMU_HDMI[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__dynamic_divider_value		{ &SFR_INFO.CMU_HDMI[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__dynamic_divider_stop			{ &SFR_INFO.CMU_HDMI[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__dynamic_divider_busy_status	{ &SFR_INFO.CMU_HDMI[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__HDMIV2_0___AUDIO__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x80c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__HDMIV2_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___AXI__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__HDMIV2_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APB__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 3, 1 }
	/* APBPHY  */
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___APBPHY__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 4, 1 }
	/* PHY  */
	#define CMU_INFO_DEF__HDMIV2_0___PHY__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMIV2_0___PHY__clock_enable					{ &SFR_INFO.CMU_HDMI[0], 0x20c, 5, 1 }
/* CODA980 */
  /* CODA980[0] */
	/* CORE  */
	#define CMU_INFO_DEF__CODA980_0___CORE__group_clock_source			{ &SFR_INFO.CMU_CODA[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_CODA[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_CODA[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__divider_reset				{ &SFR_INFO.CMU_CODA[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_CODA[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_CODA[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CODA[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___CORE__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x40c, 0, 1 }
	/* SRAM  */
	#define CMU_INFO_DEF__CODA980_0___SRAM__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__divider_reset				{ &SFR_INFO.CMU_CODA[0], 0x484, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__dynamic_divider_value		{ &SFR_INFO.CMU_CODA[0], 0x488, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__dynamic_divider_stop			{ &SFR_INFO.CMU_CODA[0], 0x48c, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CODA[0], 0x490, 0, 32 }
	#define CMU_INFO_DEF__CODA980_0___SRAM__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x40c, 1, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__CODA980_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___AXI__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__CODA980_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA980_0___APB__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 4, 1 }
/* JPEG */
  /* JPEG[0] */
	/* CORE  */
	#define CMU_INFO_DEF__JPEG_0___CORE__group_clock_source			{ &SFR_INFO.CMU_CODA[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_CODA[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_CODA[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__divider_reset				{ &SFR_INFO.CMU_CODA[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_CODA[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_CODA[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_CODA[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__JPEG_0___CORE__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x60c, 0, 1 }
	/* AXI  */
	#define CMU_INFO_DEF__JPEG_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___AXI__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 2, 1 }
	/* APB  */
	#define CMU_INFO_DEF__JPEG_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__JPEG_0___APB__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 5, 1 }
/* OTG_SYS */
  /* OTG_SYS[0] */
	/* AHB  */
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__group_clock_source			        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__group_all_divider_reset		        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__group_gate_mode				        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__divider_reset				        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__dynamic_divider_value		        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__dynamic_divider_stop			        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__dynamic_divider_busy_status	        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___AHB__clock_enable					        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x40c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__OTG_SYS_0___APB__group_clock_source			        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__group_all_divider_reset		        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__group_gate_mode				        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__divider_reset				        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x484, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__dynamic_divider_value		        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x488, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__dynamic_divider_stop			        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x48c, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__dynamic_divider_busy_status	        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x490, 0, 32 }
	#define CMU_INFO_DEF__OTG_SYS_0___APB__clock_enable					        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x40c, 1, 1 }
/* HOST_SYS */
  /* HOST_SYS[0] */
	/* EHCIAHB  */
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__group_all_divider_reset		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__group_gate_mode				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__dynamic_divider_stop		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___EHCIAHB__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x60c, 0, 1 }
	/* OHCIAHB  */                                                                                   
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__group_all_divider_reset		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__group_gate_mode				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__dynamic_divider_stop		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___OHCIAHB__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x80c, 0, 1 }
	/* APB  */
	#define CMU_INFO_DEF__HOST_SYS_0___APB__group_clock_source			        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__group_all_divider_reset		        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__group_gate_mode				        (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__divider_reset				        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x884, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__dynamic_divider_value		        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x888, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__dynamic_divider_stop			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x88c, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__dynamic_divider_busy_status	        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x890, 0, 32 }
	#define CMU_INFO_DEF__HOST_SYS_0___APB__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x80c, 1, 1 }
/* USB30_ALT_PCS */
  /* USB30_ALT_PCS[0] */
	/* CLK  */
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__group_all_divider_reset	    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__group_gate_mode			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__dynamic_divider_stop		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__dynamic_divider_busy_status    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PCS_0___CLK__clock_enable				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xa0c, 0, 1 }
/* USB30_ALT_PIPE */
  /* USB30_ALT_PIPE[0] */
	/* CLK  */
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc00, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc04, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc08, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc44, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc48, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc4c, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc50, 0, 32 }
	#define CMU_INFO_DEF__USB30_ALT_PIPE_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xc0c, 0, 1 }
/* HSIC_REFDIG */
  /* HSIC_REFDIG[0] */
	/* CLK  */
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe00, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe04, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe08, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__divider_reset				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe44, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__dynamic_divider_value		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe48, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe4c, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe50, 0, 32 }
	#define CMU_INFO_DEF__HSIC_REFDIG_0___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0xe0c, 0, 1 }
/* HSIC_F480M */
  /* HSIC_F480M[0] */
	/* CLK  */
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__group_clock_source			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1000, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__group_all_divider_reset		    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1004, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__group_gate_mode				    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1008, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__divider_reset				        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1044, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__dynamic_divider_value		        (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1048, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__dynamic_divider_stop			    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x104c, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__dynamic_divider_busy_status	    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x1050, 0, 32 }
	#define CMU_INFO_DEF__HSIC_F480M_0___CLK__clock_enable					    (__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x100c, 0, 1 }
/* DREX_REFR */
  /* DREX_REFR[0] */
	/* CLK  */
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__group_clock_source			{ &SFR_INFO.CMU_DREX0[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_DREX0[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_DREX0[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__divider_reset				{ &SFR_INFO.CMU_DREX0[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_DREX0[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DREX0[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DREX0[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__DREX_REFR_0___CLK__clock_enable					{ &SFR_INFO.CMU_DREX0[0], 0x40c, 0, 1 }
/* WAVE_V */
  /* WAVE_V[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_V_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__WAVE_V_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0x40c, 0, 1 }
/* WAVE_M */
  /* WAVE_M[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_M_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__WAVE_M_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0x60c, 0, 1 }
/* WAVE_C */
  /* WAVE_C[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_C_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__WAVE_C_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0x80c, 0, 1 }
/* WAVE_B */
  /* WAVE_B[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_B_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__WAVE_B_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE[0], 0xa0c, 0, 1 }
/* WAVE420_V */
  /* WAVE420_V[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE420[0], 0x400, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE420[0], 0x404, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE420[0], 0x408, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0x444, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0x448, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0x44c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0x450, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_V_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0x40c, 0, 1 }
/* WAVE420_M */
  /* WAVE420_M[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE420[0], 0x600, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE420[0], 0x604, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE420[0], 0x608, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0x644, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0x648, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0x64c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0x650, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_M_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0x60c, 0, 1 }
/* WAVE420_C */
  /* WAVE420_C[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE420[0], 0x800, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE420[0], 0x804, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE420[0], 0x808, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0x844, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0x848, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0x84c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0x850, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_C_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0x80c, 0, 1 }
/* WAVE420_B */
  /* WAVE420_B[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__group_clock_source			{ &SFR_INFO.CMU_WAVE420[0], 0xa00, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__group_all_divider_reset		{ &SFR_INFO.CMU_WAVE420[0], 0xa04, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__group_gate_mode				{ &SFR_INFO.CMU_WAVE420[0], 0xa08, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__divider_reset				{ &SFR_INFO.CMU_WAVE420[0], 0xa44, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__dynamic_divider_value		{ &SFR_INFO.CMU_WAVE420[0], 0xa48, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__dynamic_divider_stop			{ &SFR_INFO.CMU_WAVE420[0], 0xa4c, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_WAVE420[0], 0xa50, 0, 32 }
	#define CMU_INFO_DEF__WAVE420_B_0___CLK__clock_enable					{ &SFR_INFO.CMU_WAVE420[0], 0xa0c, 0, 1 }
/* MCD */
  /* MCD[0] */
	/* VCLK  */
	#define CMU_INFO_DEF__MCD_0___VCLK__group_clock_source			{ &SFR_INFO.CMU_DISP[0], 0x1c00, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__group_all_divider_reset		{ &SFR_INFO.CMU_DISP[0], 0x1c04, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__group_gate_mode				{ &SFR_INFO.CMU_DISP[0], 0x1c08, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__divider_reset				{ &SFR_INFO.CMU_DISP[0], 0x1c44, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__dynamic_divider_value		{ &SFR_INFO.CMU_DISP[0], 0x1c48, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__dynamic_divider_stop			{ &SFR_INFO.CMU_DISP[0], 0x1c4c, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__dynamic_divider_busy_status	{ &SFR_INFO.CMU_DISP[0], 0x1c50, 0, 32 }
	#define CMU_INFO_DEF__MCD_0___VCLK__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x1c0c, 0, 1 }
/* BUS_DMAC */
  /* BUS_DMAC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6800, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6804, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6808, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6844, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6848, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x684c, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6850, 0, 32 }
	#define CMU_INFO_DEF__BUS_DMAC_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 0, 1 }
/* DMAC */
  /* DMAC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAC_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__DMAC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 22, 1 }
  /* DMAC[1] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAC_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 2, 1 }
	/* APB  */
	#define CMU_INFO_DEF__DMAC_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAC_1___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 23, 1 }
/* SDMAC */
  /* SDMAC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__SDMAC_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 3, 1 }
	/* APB  */
	#define CMU_INFO_DEF__SDMAC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 24, 1 }
  /* SDMAC[1] */
	/* AXI  */
	#define CMU_INFO_DEF__SDMAC_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 4, 1 }
	/* APB  */
	#define CMU_INFO_DEF__SDMAC_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SDMAC_1___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 25, 1 }
/* MDMAC */
  /* MDMAC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__MDMAC_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x680c, 5, 1 }
	/* APB  */
	#define CMU_INFO_DEF__MDMAC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MDMAC_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 26, 1 }
/* GIC400 */
  /* GIC400[0] */
	/* AXI  */
	#define CMU_INFO_DEF__GIC400_0___AXI__group_clock_source			{ &SFR_INFO.CMU_SYS[0], 0x6a00, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__group_all_divider_reset		{ &SFR_INFO.CMU_SYS[0], 0x6a04, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__group_gate_mode				{ &SFR_INFO.CMU_SYS[0], 0x6a08, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__divider_reset				{ &SFR_INFO.CMU_SYS[0], 0x6a44, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__dynamic_divider_value		{ &SFR_INFO.CMU_SYS[0], 0x6a48, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__dynamic_divider_stop			{ &SFR_INFO.CMU_SYS[0], 0x6a4c, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__dynamic_divider_busy_status	{ &SFR_INFO.CMU_SYS[0], 0x6a50, 0, 32 }
	#define CMU_INFO_DEF__GIC400_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x6a0c, 0, 1 }
/* MCU */
  /* MCU[0] */
	/* CORE  */
	#define CMU_INFO_DEF__MCU_0___CORE__group_clock_source			{ &SFR_INFO.CMU_PERICLK[0], 0x2400, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__group_all_divider_reset		{ &SFR_INFO.CMU_PERICLK[0], 0x2404, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__group_gate_mode				{ &SFR_INFO.CMU_PERICLK[0], 0x2408, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__divider_reset				{ &SFR_INFO.CMU_PERICLK[0], 0x2444, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__dynamic_divider_value		{ &SFR_INFO.CMU_PERICLK[0], 0x2448, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__dynamic_divider_stop			{ &SFR_INFO.CMU_PERICLK[0], 0x244c, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__dynamic_divider_busy_status	{ &SFR_INFO.CMU_PERICLK[0], 0x2450, 0, 32 }
	#define CMU_INFO_DEF__MCU_0___CORE__clock_enable					{ &SFR_INFO.CMU_PERICLK[0], 0x240c, 0, 1 }
/* SPDIFRX */
  /* SPDIFRX[0] */
	/* APB  */
	#define CMU_INFO_DEF__SPDIFRX_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SPDIFRX_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 13, 1 }
/* AC97 */
  /* AC97[0] */
	/* APB  */
	#define CMU_INFO_DEF__AC97_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__AC97_0___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 7, 1 }
/* TMU */
  /* TMU[0] */
	/* APB  */
	#define CMU_INFO_DEF__TMU_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TMU_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 14, 1 }
/* CCI400 */
  /* CCI400[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CCI400_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CCI400_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 1, 1 }
/* TIEOFF_CCI */
  /* TIEOFF_CCI[0] */
	/* AXI  */
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TIEOFF_CCI_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 2, 1 }
/* SYSCTRL */
  /* SYSCTRL[0] */
	/* APB  */
	#define CMU_INFO_DEF__SYSCTRL_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSCTRL_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 12, 1 }
/* HPM */
  /* HPM[0] */
	/* APB  */
	#define CMU_INFO_DEF__HPM_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HPM_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 13, 1 }
/* Q_ENHANCER */
  /* Q_ENHANCER[0] */
	/* APB  */
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__Q_ENHANCER_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 14, 1 }
/* CRYPTO */
  /* CRYPTO[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CRYPTO_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___AXI__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 3, 1 }
	/* APB  */
	#define CMU_INFO_DEF__CRYPTO_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CRYPTO_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 15, 1 }
/* WDT */
  /* WDT[0] */
	/* APB  */
	#define CMU_INFO_DEF__WDT_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 16, 1 }
	/* POR  */
	#define CMU_INFO_DEF__WDT_0___POR__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_0___POR__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 17, 1 }
  /* WDT[1] */
	/* APB  */
	#define CMU_INFO_DEF__WDT_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 18, 1 }
	/* POR  */
	#define CMU_INFO_DEF__WDT_1___POR__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WDT_1___POR__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 19, 1 }
/* TZPC */
  /* TZPC[0] */
	/* APB  */
	#define CMU_INFO_DEF__TZPC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TZPC_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 20, 1 }
/* ECID */
  /* ECID[0] */
	/* APB  */
	#define CMU_INFO_DEF__ECID_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ECID_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 21, 1 }
/* BBUSTIEOFF */
  /* BBUSTIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__BBUSTIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 15, 1 }
/* LBUSTIEOFF */
  /* LBUSTIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__LBUSTIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 6, 1 }
/* SYSTIEOFF */
  /* SYSTIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SYSTIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 27, 1 }
/* ADC */
  /* ADC[0] */
	/* APB  */
	#define CMU_INFO_DEF__ADC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ADC_0___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 16, 1 }
/* GPIO */
  /* GPIO[0] */
	/* APB  */
	#define CMU_INFO_DEF__GPIO_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_0___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 7, 1 }
  /* GPIO[1] */
	/* APB  */
	#define CMU_INFO_DEF__GPIO_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_1___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 8, 1 }
  /* GPIO[2] */
	/* APB  */
	#define CMU_INFO_DEF__GPIO_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_2___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 17, 1 }
  /* GPIO[3] */
	/* APB  */
	#define CMU_INFO_DEF__GPIO_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_3___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 18, 1 }
  /* GPIO[4] */
	/* APB  */
	#define CMU_INFO_DEF__GPIO_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPIO_4___APB__clock_enable					{ &SFR_INFO.CMU_BBUS[0], 0x20c, 19, 1 }
/* I2C */
  /* I2C[0] */
	/* APB  */
	#define CMU_INFO_DEF__I2C_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_0___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 8, 1 }
  /* I2C[1] */
	/* APB  */
	#define CMU_INFO_DEF__I2C_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_1___APB__clock_enable					{ &SFR_INFO.CMU_TBUS[0], 0x20c, 9, 1 }
  /* I2C[2] */
	/* APB  */
	#define CMU_INFO_DEF__I2C_2___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_2___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 9, 1 }
  /* I2C[3] */
	/* APB  */
	#define CMU_INFO_DEF__I2C_3___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_3___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 10, 1 }
  /* I2C[4] */
	/* APB  */
	#define CMU_INFO_DEF__I2C_4___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__I2C_4___APB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 11, 1 }
/* MP2TS */
  /* MP2TS[0] */
	/* AHB  */
	#define CMU_INFO_DEF__MP2TS_0___AHB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MP2TS_0___AHB__clock_enable					{ &SFR_INFO.CMU_LBUS[0], 0x20c, 3, 1 }
/* DREXTIEOFF */
  /* DREXTIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREXTIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_DREX0[0], 0x20c, 5, 1 }
/* CPUTIEOFF */
  /* CPUTIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPUTIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_CPU[0], 0x20c, 5, 1 }
/* MCUS */
  /* MCUS[0] */
	/* APB  */
	#define CMU_INFO_DEF__MCUS_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCUS_0___APB__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x20c, 28, 1 }
/* DISP_TIEOFF */
  /* DISP_TIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 25, 1 }
/* DISP_TZPC */
  /* DISP_TZPC[0] */
	/* APB  */
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_0___APB__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 26, 1 }
  /* DISP_TZPC[1] */
	/* APB  */
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_TZPC_1___APB__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 27, 1 }
/* CSI_TO_AXI */
  /* CSI_TO_AXI[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_AXI_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 2, 1 }
/* CSI_TO_NXS */
  /* CSI_TO_NXS[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 3, 1 }
  /* CSI_TO_NXS[1] */
	/* AXI  */
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 4, 1 }
  /* CSI_TO_NXS[2] */
	/* AXI  */
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 5, 1 }
  /* CSI_TO_NXS[3] */
	/* AXI  */
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSI_TO_NXS_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 6, 1 }
/* MLC */
  /* MLC[0] */
	/* BOTTOM0  */
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM0__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 7, 1 }
	/* BOTTOM1  */
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BOTTOM1__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 8, 1 }
	/* BLENDER0  */
	#define CMU_INFO_DEF__MLC_0___BLENDER0__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER0__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 9, 1 }
	/* BLENDER1  */
	#define CMU_INFO_DEF__MLC_0___BLENDER1__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER1__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 10, 1 }
	/* BLENDER2  */
	#define CMU_INFO_DEF__MLC_0___BLENDER2__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER2__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 11, 1 }
	/* BLENDER3  */
	#define CMU_INFO_DEF__MLC_0___BLENDER3__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER3__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 12, 1 }
	/* BLENDER4  */
	#define CMU_INFO_DEF__MLC_0___BLENDER4__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER4__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 13, 1 }
	/* BLENDER5  */
	#define CMU_INFO_DEF__MLC_0___BLENDER5__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER5__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 14, 1 }
	/* BLENDER6  */
	#define CMU_INFO_DEF__MLC_0___BLENDER6__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER6__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 15, 1 }
	/* BLENDER7  */
	#define CMU_INFO_DEF__MLC_0___BLENDER7__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MLC_0___BLENDER7__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 16, 1 }
/* MCD_CPUIF */
  /* MCD_CPUIF[0] */
	/* AXI  */
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MCD_CPUIF_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 21, 1 }
/* VIP_CPUIF */
  /* VIP_CPUIF[0] */
	/* AXI  */
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_CPUIF_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 22, 1 }
/* VIP_PRES_CPUIF */
  /* VIP_PRES_CPUIF[0] */
	/* AXI  */
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__VIP_PRES_CPUIF_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 23, 1 }
/* ISS_CPUIF */
  /* ISS_CPUIF[0] */
	/* AXI  */
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISS_CPUIF_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 24, 1 }
/* DISP2ISP */
  /* DISP2ISP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP2ISP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 25, 1 }
/* ISP2DISP */
  /* ISP2DISP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 26, 1 }
  /* ISP2DISP[1] */
	/* AXI  */
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP2DISP_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 27, 1 }
/* CROP */
  /* CROP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CROP_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 28, 1 }
  /* CROP[1] */
	/* AXI  */
	#define CMU_INFO_DEF__CROP_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CROP_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 29, 1 }
/* CSC */
  /* CSC[0] */
	/* AXI  */
	#define CMU_INFO_DEF__CSC_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 30, 1 }
  /* CSC[1] */
	/* AXI  */
	#define CMU_INFO_DEF__CSC_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x20c, 31, 1 }
  /* CSC[2] */
	/* AXI  */
	#define CMU_INFO_DEF__CSC_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 0, 1 }
  /* CSC[3] */
	/* AXI  */
	#define CMU_INFO_DEF__CSC_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CSC_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 1, 1 }
/* SCALER */
  /* SCALER[0] */
	/* AXI  */
	#define CMU_INFO_DEF__SCALER_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 2, 1 }
  /* SCALER[1] */
	/* AXI  */
	#define CMU_INFO_DEF__SCALER_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 3, 1 }
  /* SCALER[2] */
	/* AXI  */
	#define CMU_INFO_DEF__SCALER_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__SCALER_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 4, 1 }
/* MULTI_TAP */
  /* MULTI_TAP[0] */
	/* AXI  */
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 5, 1 }
  /* MULTI_TAP[1] */
	/* AXI  */
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 6, 1 }
  /* MULTI_TAP[2] */
	/* AXI  */
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 7, 1 }
  /* MULTI_TAP[3] */
	/* AXI  */
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__MULTI_TAP_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 8, 1 }
/* DMAR */
  /* DMAR[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 9, 1 }
  /* DMAR[1] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 10, 1 }
  /* DMAR[2] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 11, 1 }
  /* DMAR[3] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 12, 1 }
  /* DMAR[4] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_4___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_4___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 13, 1 }
  /* DMAR[5] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_5___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_5___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 14, 1 }
  /* DMAR[6] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_6___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_6___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 15, 1 }
  /* DMAR[7] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_7___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_7___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 16, 1 }
  /* DMAR[8] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_8___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_8___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 17, 1 }
  /* DMAR[9] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAR_9___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAR_9___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 18, 1 }
/* DMAW */
  /* DMAW[0] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 19, 1 }
  /* DMAW[1] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 20, 1 }
  /* DMAW[2] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 21, 1 }
  /* DMAW[3] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 22, 1 }
  /* DMAW[4] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_4___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_4___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 23, 1 }
  /* DMAW[5] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_5___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_5___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 24, 1 }
  /* DMAW[6] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_6___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_6___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 25, 1 }
  /* DMAW[7] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_7___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_7___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 26, 1 }
  /* DMAW[8] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_8___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_8___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 27, 1 }
  /* DMAW[9] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_9___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_9___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 28, 1 }
  /* DMAW[10] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_10___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_10___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 29, 1 }
  /* DMAW[11] */
	/* AXI  */
	#define CMU_INFO_DEF__DMAW_11___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DMAW_11___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 30, 1 }
/* HUE */
  /* HUE[0] */
	/* AXI  */
	#define CMU_INFO_DEF__HUE_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x210, 31, 1 }
  /* HUE[1] */
	/* AXI  */
	#define CMU_INFO_DEF__HUE_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HUE_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 0, 1 }
/* GAMMA */
  /* GAMMA[0] */
	/* AXI  */
	#define CMU_INFO_DEF__GAMMA_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 1, 1 }
  /* GAMMA[1] */
	/* AXI  */
	#define CMU_INFO_DEF__GAMMA_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GAMMA_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 2, 1 }
/* NXS_FIFO */
  /* NXS_FIFO[0] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 9, 1 }
  /* NXS_FIFO[1] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_1___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 10, 1 }
  /* NXS_FIFO[2] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_2___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 11, 1 }
  /* NXS_FIFO[3] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_3___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 12, 1 }
  /* NXS_FIFO[4] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_4___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 13, 1 }
  /* NXS_FIFO[5] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_5___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 14, 1 }
  /* NXS_FIFO[6] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_6___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 15, 1 }
  /* NXS_FIFO[7] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_7___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 16, 1 }
  /* NXS_FIFO[8] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_8___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 17, 1 }
  /* NXS_FIFO[9] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_9___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 18, 1 }
  /* NXS_FIFO[10] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_10___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 19, 1 }
  /* NXS_FIFO[11] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS_FIFO_11___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 20, 1 }
/* NXS2HDMI */
  /* NXS2HDMI[0] */
	/* AXI  */
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__NXS2HDMI_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 21, 1 }
/* TPGEN */
  /* TPGEN[0] */
	/* AXI  */
	#define CMU_INFO_DEF__TPGEN_0___AXI__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__TPGEN_0___AXI__clock_enable					{ &SFR_INFO.CMU_DISP[0], 0x214, 22, 1 }
/* CODATIEOFF */
  /* CODATIEOFF[0] */
	/* APB  */
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODATIEOFF_0___APB__clock_enable					{ &SFR_INFO.CMU_CODA[0], 0x20c, 6, 1 }
/* ISP_CMU */
  /* ISP_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__ISP_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 1, 1 }
/* DISP_CMU */
  /* DISP_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DISP_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 2, 1 }
/* USB_CMU */
  /* USB_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__USB_CMU_0___CLK__group_clock_source			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__group_all_divider_reset		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__group_gate_mode				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__divider_reset				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__dynamic_divider_value		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB_CMU_0___CLK__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_SYS[0], 0x40c, 3, 1 }
/* CODA_CMU */
  /* CODA_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CODA_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 4, 1 }
/* GPU_CMU */
  /* GPU_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__GPU_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 5, 1 }
/* HDMI_CMU */
  /* HDMI_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__HDMI_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 6, 1 }
/* WAVE_CMU */
  /* WAVE_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 7, 1 }
/* WAVE420_CMU */
  /* WAVE420_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__WAVE420_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 8, 1 }
/* DREX_CMU */
  /* DREX_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__DREX_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 9, 1 }
/* CPU_CMU */
  /* CPU_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__CPU_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 10, 1 }
/* PERICLK_CMU */
  /* PERICLK_CMU[0] */
	/* CLK  */
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__group_clock_source			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__group_all_divider_reset		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__group_gate_mode				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__divider_reset				{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__dynamic_divider_value		{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__dynamic_divider_stop			{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__dynamic_divider_busy_status	{ 0,0,0,0 }
	#define CMU_INFO_DEF__PERICLK_CMU_0___CLK__clock_enable					{ &SFR_INFO.CMU_SYS[0], 0x40c, 11, 1 }
/* USB30 */
  /* USB30[0] */
	/* AXI  */
	#define CMU_INFO_DEF__USB30_0___AXI__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__group_all_divider_reset		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__group_gate_mode				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___AXI__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x20c, 1, 1 }
	/* APB  */
	#define CMU_INFO_DEF__USB30_0___APB__group_clock_source			    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__group_all_divider_reset		(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__group_gate_mode				(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__divider_reset				    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__dynamic_divider_value		    (__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__dynamic_divider_stop			(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__dynamic_divider_busy_status	(__nx_cpuif_symbol__){ 0,0,0,0 }
	#define CMU_INFO_DEF__USB30_0___APB__clock_enable					(__nx_cpuif_symbol__){ &SFR_INFO.CMU_USB[0], 0x20c, 4, 1 }
#endif // #ifndef __NX_CLOCKCONTROL_DEF_H__


