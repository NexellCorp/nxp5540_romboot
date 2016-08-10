//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <nx_debug.h>
#include "nx_chip.h"
#include "nx_tzpc.h"

#define NX_TZPC_CHIP_DEBUG (2)
#if   ( 3==NX_TZPC_CHIP_DEBUG )
	#define ENTER		NX_CONSOLE_Printf( "*D: ENTER: %s(%d)\n", __func__, __LINE__ )
	#define LEAVE		NX_CONSOLE_Printf( "*D: LEAVE: %s(%d)\n", __func__, __LINE__ )
	#define LOGD		NX_CONSOLE_Printf
	#define LOGI		NX_CONSOLE_Printf
	#define LOGE		NX_CONSOLE_Printf
#elif ( 2==NX_TZPC_CHIP_DEBUG )
	#define ENTER
	#define LEAVE
	#define LOGD		NX_CONSOLE_Printf
	#define LOGI		NX_CONSOLE_Printf
	#define LOGE		NX_CONSOLE_Printf
#elif ( 1==NX_TZPC_CHIP_DEBUG )
	#define ENTER
	#define LEAVE
	#define LOGD
	#define LOGI		NX_CONSOLE_Printf
	#define LOGE		NX_CONSOLE_Printf
#elif ( 0==NX_TZPC_CHIP_DEBUG )
	#define ENTER
	#define LEAVE
	#define LOGD
	#define LOGI
	#define LOGE		NX_CONSOLE_Printf
#else
	#define ENTER
	#define LEAVE
	#define LOGD
	#define LOGI
	#define LOGE
#endif


//------------------------------------------------------------------------------
/**
 *	@brief		CPU mode Control Function
 *	@return
 *	@see
 * - secure mode     : PROT_SECURE    (0)
 * - non secure mode : PROT_NONSECURE (1)
 */
//------------------------------------------------------------------------------
void NX_CHIP_SetCPUSecureMode( U32 PROT )
{
#define __SIMULATION_ONLY__
#ifdef __SIMULATION_ONLY__

	U32 SIMIO_ENDADDR = 0x82000400;
	U32 ARPROT_ADDR   = SIMIO_ENDADDR - 4;

	if (PROT == PROT_SECURE) {	// secure
		WriteIODW( ARPROT_ADDR, 0xDEAD0000 );
	}
	if (PROT == PROT_NONSECURE) {	// non secure
		WriteIODW( ARPROT_ADDR, 0xDEAD1111 );
	}

#endif
}

//------------------------------------------------------------------------------
/**
 *	@brief		Data Read Write to secure or non-secure cpu mode
 *	@return
 *	@see
 * - secure mode     : PROT_SECURE    (0)
 * - non secure mode : PROT_NONSECURE (1)
 */
//------------------------------------------------------------------------------
void NX_CHIP_SetSecureBaseaddr( U32 index )
{
	switch(index)
	{
#ifndef TZ_NOT_YET
	case 0: __ISS_SET_BASEADDR( PHY_BASEADDR_ISS_SECURE_MODULE ); break;
	case 1: __VIP_SET_BASEADDR( PHY_BASEADDR_VIP_SECURE_MODULE ); break;
	case 2: __VIP_PRES_SET_BASEADDR( PHY_BASEADDR_VIP_PRES_SECURE_MODULE ); break;
	case 3: __MLC_SET_BASEADDR( PHY_BASEADDR_MLC_SECURE_MODULE ); break;
#endif
	default: LOGE("*E: [TZPC_CHIP] Error %s(%d) index(%d)\n", __func__, __LINE__, index);
	}
}

void NX_CHIP_SetNonSecureBaseaddr( U32 index )
{
	switch(index)
	{
#ifndef TZ_NOT_YET
	case 0: __ISS_SET_BASEADDR( PHY_BASEADDR_ISS_MODULE ); break;
	case 1: __VIP_SET_BASEADDR( PHY_BASEADDR_VIP_MODULE ); break;
	case 2: __VIP_PRES_SET_BASEADDR( PHY_BASEADDR_VIP_PRES_MODULE ); break;
	case 3: __MLC_SET_BASEADDR( PHY_BASEADDR_MLC_MODULE ); break;
#endif
	default: LOGE("*E: [TZPC_CHIP] Error %s(%d) index(%d)\n", __func__, __LINE__, index);
	}
}

void NX_CHIP_WriteSecureAccess( U32 addr, U32 data )
{
	NX_CHIP_SetCPUSecureMode( PROT_SECURE );
	WriteIODW( addr, data );
	LOGD("*D: [TZPC_CHIP] 0x%x:secure Write(0x%x)\n", addr, data );
}

U32 NX_CHIP_ReadSecureAccess( U32 addr )
{
	U32 regval=0;
	NX_CHIP_SetCPUSecureMode( PROT_SECURE );
	regval = ReadIODW( addr );
	LOGD("*D: [TZPC_CHIP] 0x%x:secure Read(0x%x)\n", addr, regval );
	return regval;
}
void NX_CHIP_WriteNonSecureAccess( U32 addr, U32 data )
{
	NX_CHIP_SetCPUSecureMode( PROT_NONSECURE );
	WriteIODW( addr, data );
	LOGD("*D: [TZPC_CHIP] 0x%x:non-secure Write(0x%x)\n", addr, data );
}

U32 NX_CHIP_ReadNonSecureAccess( U32 addr )
{
	U32 regval=0;
	NX_CHIP_SetCPUSecureMode( PROT_NONSECURE );
	regval = ReadIODW( addr );
	LOGD("*D: [TZPC_CHIP] 0x%x:non-secure Read(0x%x)\n", addr, regval );
	return regval;
}

//
//TODO: need to make DREX Prototype
//

#define TZRSLOW0            (0x0100    )   // R/W  TZASC Region Setup Low Register 1               0x0000_0000
#define TZRSHIGH0           (0x0104    )   // R/W  TZASC Region Setup High Register 1              0x0000_0000
#define TZRSATTR0           (0x0108    )   // R/W  TZASC Region Setup Attribute Register 1         0xF000_0000

void NX_DREX_SetTZASC( U32 index, U32 addr, U32 size, U32 type )
{
       U32 reg;
	   U32 secure_type;

       reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSLOW0  + 0x10*index);
       WriteIODW( reg, addr );
       LOGD("*D: [TZPC_CHIP] addr (0x%x), data(0x%x), read (0x%x)\n", reg, addr, ReadIODW(reg) );

       reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSHIGH0 + 0x10*index);
       WriteIODW( reg, 0x0  );
       LOGD("*D: [TZPC_CHIP] addr (0x%x), data(0x%x), read (0x%x)\n", reg, 0x0, ReadIODW(reg) );

       reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSATTR0 + 0x10*index);
	   if     ( type==TZASC_SECURE )         secure_type = 0xC; //WriteIODW( reg, (0xC << 28 | size<<4 | 1<<0) ); // secure access | size | enable
	   else if( type==TZASC_NONSECURE )      secure_type = 0xF; //WriteIODW( reg, (0xF << 28 | size<<4 | 1<<0) ); // secure access | size | enable
	   else if( type==TZASC_NONSECURE_ONLY ) secure_type = 0x3; //WriteIODW( reg, (0x3 << 28 | size<<4 | 1<<0) ); // secure access | size | enable
	   else                                  secure_type = 0xF; //WriteIODW( reg, (0xF << 28 | size<<4 | 1<<0) ); // secure access | size | enable

	   WriteIODW( reg, ((secure_type&0xF) << 28 | size<<4 | 1<<0) ); // secure access | size | enable
       LOGD("*D: [TZPC_CHIP] addr (0x%x), data(0x%x), read (0x%x)\n", reg, ((secure_type&0xF) << 28 | size<<4 | 1<<0), ReadIODW(reg) );

       //reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSLOW0 + 0x10*index);
       //WriteIODW( reg, addr );
       //reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSHIGH0 + 0x10*index);
       //WriteIODW( reg, 0x0 );
       //reg = (PHY_BASEADDR_DREXTZASC_MODULE + TZRSATTR0 + 0x10*index);
       //WriteIODW( reg, (0xC << 28 | size<<4 | 1<<0) );       // secure access | size | enable
}

U32 NX_DREX_CheckReadDrex(void)
{
	if( 0xDEADC0DE == ReadIODW(PHY_BASEADDR_DREX0_CFG_MODULE) )
	{
	    NX_CONSOLE_Printf("*I: [DEBUG] is fake Drex!!!\n");
	    return CFALSE;
	}

	NX_CONSOLE_Printf("*I: [DEBUG] is Real Drex!!!\n");
	return CTRUE;
}

