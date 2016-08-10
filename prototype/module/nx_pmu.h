//	Copyright (C) 2009 Nexell Co., All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//	FOR A PARTICULAR PURPOSE.
//
//	Module		: Clock & Power Manager
//	File		: nx_PMU.h
//	Description	:
//	Author		: Firmware
//	History		:
//------------------------------------------------------------------------------
#ifndef __NX_PMU_H__
#define __NX_PMU_H__

#include "../base/nx_prototype.h"



#ifdef	__cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup	PMU Clock & Power Manager
//------------------------------------------------------------------------------
//@{

/// @brief	Clock & Power Manager Module's Register List
struct	NX_PMU_RegisterSet
{
	volatile U32 nISOLATE;
	volatile U32 SCPRE;
	volatile U32 SCALL;
	volatile U32 SCALLACK;

	volatile U32 ALIVE_nISOLATE;
	volatile U32 ALIVE_SCPRE;
	volatile U32 ALIVE_SCALL;
	volatile U32 ALIVE_SCALLOUT;

	volatile U32 ALIVE_RESET;

};


/// @brief	Reset status
typedef enum
{
	NX_PMU_POWER_SWITCH_ISOLATE	= 0,
	NX_PMU_POWER_SWITCH_SCPRE	= 1,
	NX_PMU_POWER_SWITCH_SCALL	= 2,

}	NX_PMU_POWER_SWITCH;



//------------------------------------------------------------------------------
/// @name	Module Interface
//@{
CBOOL NX_PMU_Initialize(void);
U32 NX_PMU_GetNumberOfModule(void);
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//@{
U32 NX_PMU_GetPhysicalAddress(void);
U32 NX_PMU_GetSizeOfRegisterSet(void);
void NX_PMU_SetBaseAddress(U32 BaseAddress);
U32 NX_PMU_GetBaseAddress(void);
CBOOL NX_PMU_OpenModule(void);
CBOOL NX_PMU_CloseModule(void);
CBOOL NX_PMU_CheckBusy(void);
CBOOL NX_PMU_CanPowerDown(void);
//@}

//------------------------------------------------------------------------------
///	@name	PMU Interface
//@{
void NX_PMU_SetPowerUp(U32 domain, NX_PMU_POWER_SWITCH  powerswitch);
void NX_PMU_SetPowerDown(U32 domain, NX_PMU_POWER_SWITCH  powerswitch);
CBOOL NX_PMU_GetPowerDownState(U32 domain);
U32 NX_PMU_GetNumberOfPowerDomain(void);
void NX_PMU_MCU_LeaveReset(void);
//@}


#ifdef	__cplusplus
}
#endif


#endif // __NX_PMU_H__

