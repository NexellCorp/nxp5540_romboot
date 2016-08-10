
#ifndef __NX_SystemClockInfo_Parameter__
struct NX_SystemClockInfo_Parameter {
	U32	num_of_clock_src;
	double	clock_src_freq[16];
};

/*
static double nx_sys_clk_info_get_cmu_config( double clock_freq, 
					   struct NX_SystemClockInfo_Parameter  * p_sysclkinfo_param,
					   U32 * clk_src,
					   U32 * clk_div    )
{
	U32 i; 
	double min_diff = 9999999;	
	double min_sign = 1;
	for(i=0; i< p_sysclkinfo_param->num_of_clock_src; i=i+1) {
		double cur_freq;
		double cur_err;
		double cur_sign = 1;
		U32 cur_div;
		
		if( p_sysclkinfo_param->clock_src_freq[i] != 0 ) {

			cur_div = (U32)((p_sysclkinfo_param->clock_src_freq[i] / clock_freq) + 0.5);
			if( cur_div == 0 ) cur_div = 1;

			if( cur_div != 0 ) {

				if( cur_div != 1 ) {
					cur_div = cur_div - (cur_div%2); 
				}
				cur_freq = p_sysclkinfo_param->clock_src_freq[i] / cur_div ;

				cur_err = cur_freq - clock_freq;
				if( cur_err < 0 ) {
					cur_err = -1 * cur_err;
					cur_sign = -1;
				}

				if( cur_err < min_diff ) {
					*clk_src = i;
					*clk_div = cur_div;
					min_diff = cur_err;
					min_sign = cur_sign;
				}
			}

		}
	}

	if( min_diff == 9999999 ) return -1;
	
	min_diff = min_diff * min_sign ;
	if( min_diff == -1 ) return -1.01;
	return min_diff;
}
*/

#define __NX_SystemClockInfo_Parameter__
#endif


