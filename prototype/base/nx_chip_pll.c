
#include "nx_chip.h"
#include "nx_framework.h"

#define MAX_PLL     8
#define PLL_P 		18
#define PLL_M 		8
#define PLL_S 		0
#define SYSPMS0     (0x0008)
#define SYSPMS1     (0x000c)
#define SYSPMS2     (0x0010)
#define SYSPMS3     (0x0014)
#define SYSPMS4     (0x0018)
#define SYSPMS5     (0x001c)
#define SYSPMS6     (0x0020)
#define SYSPMS7     (0x0024)
#define OSC_CLK     (24)

void NX_CHIP_Reset_PLLFreqVar(void)
{
	U32 i, div;
	U32 sysctrl_addr = SFR_INFO.SYSCTRLTOP[0];
	U32 pll_val[MAX_PLL];
	U32 pll_val_P[MAX_PLL], pll_val_M[MAX_PLL], pll_val_S[MAX_PLL];

	double cur_pll_val[MAX_PLL];

	for(i=0;i<MAX_PLL;i++)
	{
		pll_val[i] = ReadIODW( (sysctrl_addr + SYSPMS0 + i*4) );
	}

	for(i=0;i<MAX_PLL;i++)
	{
		pll_val_P[i] = ((pll_val[i] >> PLL_P) & 0x1F);
		pll_val_M[i] = ((pll_val[i] >> PLL_M) & 0x1FF);
		pll_val_S[i] = ((pll_val[i] >> PLL_S) & 0x7);

		cur_pll_val[i] = (get_OSCCLK_IN()*pll_val_M[i]) / ( pll_val_P[i] * (1<<pll_val_S[i]) );
		NX_CONSOLE_Printf(" Current PLL Freq[%d] = %f( reg val : %08x, P : %d, M : %d, S : %d)\n",
				i, cur_pll_val[i], pll_val[i], pll_val_P[i],pll_val_M[i],pll_val_S[i]);
	}

	set_PLL0_CLK(cur_pll_val[0]);
	set_PLL1_CLK(cur_pll_val[1]);
	set_PLL2_CLK(cur_pll_val[2]);
	set_PLL3_CLK(cur_pll_val[3]);
	set_PLL4_CLK(cur_pll_val[4]);
	set_PLL5_CLK(cur_pll_val[5]);
	set_PLL6_CLK(cur_pll_val[6]);
	set_PLL7_CLK(cur_pll_val[7]);


	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[0].CLK );
	set_SCLK_PLL0(cur_pll_val[0]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[0].DIV );
	set_SCLK_PLL0_DIV(cur_pll_val[0]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[1].CLK );
	set_SCLK_PLL1(cur_pll_val[1]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[2].CLK );
	set_SCLK_PLL2(cur_pll_val[2]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[3].CLK );
	set_SCLK_PLL3(cur_pll_val[3]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[4].CLK );
	set_SCLK_PLL4(cur_pll_val[4]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[5].CLK );
	set_SCLK_PLL5(cur_pll_val[5]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[6].CLK );
	set_SCLK_PLL6(cur_pll_val[6]/div);
	div = NX_CLOCK_GetClockDivisor( &CMU_INFO.PLL[7].CLK );
	set_SCLK_PLL7(cur_pll_val[7]/div);

}
