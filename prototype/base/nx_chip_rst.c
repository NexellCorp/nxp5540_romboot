
#include <nx_framework.h>
#include <nx_chip.h>
#include <nx_sysclkinfo.h>

//################################
// @modified by choiyk 2015/10/08
//--------------------------------
// 현재 CMU/RGU 의 구조를 알고있으므로, 모든 Reset을 풀때는 손으로 작성한 코드를 가지고 작업한다.
// 모든 CMU/RGU 에 들어가서, 모든 RESET 을 1로 만들어주는 코드이다.
//################################


#define MAX_CMU_NUM 32
#define MAX_RGU_NUM  8
#define MAX_CLKGATE_NUM 4
static const U32 * CMU_ADDR[MAX_CMU_NUM] = {
	 (U32*)PHY_BASEADDR_CMU_SYS_MODULE   //@note : CMU_SYS가 무조건 가장 먼저 RESET을 풀어주어야 한다 !!
	,(U32*)PHY_BASEADDR_CMU_TBUS_MODULE
	,(U32*)PHY_BASEADDR_CMU_LBUS_MODULE
	,(U32*)PHY_BASEADDR_CMU_BBUS_MODULE
	,(U32*)PHY_BASEADDR_CMU_ISP_MODULE
	,(U32*)PHY_BASEADDR_CMU_CODA_MODULE
	,(U32*)PHY_BASEADDR_CMU_DISP_MODULE
	,(U32*)PHY_BASEADDR_CMU_USB_MODULE
	,(U32*)PHY_BASEADDR_CMU_HDMI_MODULE
	,(U32*)PHY_BASEADDR_CMU_GPU_MODULE
	,(U32*)PHY_BASEADDR_CMU_WAVE_MODULE
	,(U32*)PHY_BASEADDR_CMU_WAVE420_MODULE
	,(U32*)PHY_BASEADDR_CMU_DREX0_MODULE
	,(U32*)PHY_BASEADDR_CMU_CPU0_MODULE
	,(U32*)PHY_BASEADDR_CMU_PERICLK_MODULE
	//,PHY_BASEADDR_CMU_CPU1_MODULE
	,0
};
void NX_CHIP_ResetRelease(void)
{
	U32 i,j;
	volatile U32 * rgu_reg;

	for (i = 0; i < MAX_CMU_NUM; i++) {
		if (CMU_ADDR[i] != 0) {

			/////////////////////////////////////////////////////////
			// clock gate on
			// all clock on mode
			/////////////////////////////////////////////////////////
			for (rgu_reg = (U32*)(CMU_ADDR[i] + (0x200 / sizeof(U32)));
				rgu_reg < (U32*)(CMU_ADDR[i] + ((1 << 15) / sizeof(U32)));
				rgu_reg += (0x200 / sizeof(U32))) {
				*(rgu_reg + (0x8 / sizeof(U32))) = 3; // CLK GATE MODE : ALL_ON
			}

			/////////////////////////////////////////////////////////
			// reset release
			/////////////////////////////////////////////////////////
			rgu_reg = (U32 *)(CMU_ADDR[i] + ((1 << 15) / sizeof(U32)) );
			NX_CONSOLE_Printf("\n[NX_CHIP_ResetRelease] index = %d, RGU ADDR : 0x%x", i, rgu_reg );
			for (j = 0; j < MAX_RGU_NUM; j++) {
				*(rgu_reg + j) = 0xFFFFFFFF;
			}
		}
	}
}
void NX_CHIP_ResetRelease_fake(void)
{
	U32 i,j;
	volatile U32 * rgu_reg;

	#define MAX_CMU_NUM 32
	#define MAX_RGU_NUM  8

	U32 * CMU_ADDR[MAX_CMU_NUM] = {
		 (U32*)PHY_BASEADDR_CMU_SYS_MODULE   //@note : CMU_SYS가 무조건 가장 먼저 RESET을 풀어주어야 한다 !!
		,(U32*)PHY_BASEADDR_CMU_TBUS_MODULE
		,(U32*)PHY_BASEADDR_CMU_LBUS_MODULE
		,(U32*)PHY_BASEADDR_CMU_BBUS_MODULE
		//,(U32*)PHY_BASEADDR_CMU_ISP_MODULE
		//,(U32*)PHY_BASEADDR_CMU_CODA_MODULE
		//,(U32*)PHY_BASEADDR_CMU_DISP_MODULE
		//TODO,(U32*)PHY_BASEADDR_CMU_USB_MODULE
		//,(U32*)PHY_BASEADDR_CMU_HDMI_MODULE
		//TODO,(U32*)PHY_BASEADDR_CMU_GPU_MODULE
		//TODO,(U32*)PHY_BASEADDR_CMU_WAVE_MODULE
		,(U32*)PHY_BASEADDR_CMU_DREX0_MODULE
		,(U32*)PHY_BASEADDR_CMU_CPU0_MODULE
		//,PHY_BASEADDR_CMU_CPU1_MODULE
		,0
	};

	for (i = 0; i < MAX_CMU_NUM; i++) {
		if (CMU_ADDR[i] != 0 ) {

			/////////////////////////////////////////////////////////
			// clock gate on
			// all clock on mode
			/////////////////////////////////////////////////////////
			for (rgu_reg = (U32*)(CMU_ADDR[i] + (0x200 / sizeof(U32)));
				rgu_reg < (U32*)(CMU_ADDR[i] + ((1 << 15) / sizeof(U32)));
				rgu_reg += (0x200 / sizeof(U32)) ) {
				*(rgu_reg+ (0x8/sizeof(U32)) ) = 3; // CLK GATE MODE : ALL_ON
			}

			/////////////////////////////////////////////////////////
			// reset release
			/////////////////////////////////////////////////////////
			rgu_reg = (U32 *)(CMU_ADDR[i] + ((1 << 15) / sizeof(U32)) );
			NX_CONSOLE_Printf("\n[NX_CHIP_ResetRelease] index = %d, RGU ADDR : 0x%x", i, rgu_reg );
			for (j = 0; j < MAX_RGU_NUM; j++) {
				*(rgu_reg + j) = 0xFFFFFFFF;
			}
		}
	}
}
//################################

