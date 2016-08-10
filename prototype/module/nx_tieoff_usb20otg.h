
//-----------------------------------------------------------------------------
//	Copyright (C) 2012 Nexell Co., All Rights Reserved
//	Nexell Co. Proprietary < Confidential
//
//	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//	FOR A PARTICULAR PURPOSE.
//
//	Module		: usb20 otg tieoff
//	File		: nx_tieoff_usb20otg.h
//	Description	:
//	Author		: SOC Team
//	History		:
//------------------------------------------------------------------------------
#ifndef __NX_TIEOFF_USB20OTG_H__
#define __NX_TIEOFF_USB20OTG_H__

#include "../base/nx_prototype.h"
#include "../base/nx_type.h"

#ifdef	__cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup
//------------------------------------------------------------------------------
//@{

	#define NumberOfTieOffReg 9

	struct	NX_TIEOFF_USB20OTG_RegisterSet
	{
		volatile U32	TIEOFFREG[NumberOfTieOffReg];			//
	};


#ifdef	__cplusplus
}
#endif

#endif // __NX_TIEOFF_USB20OTG_H__

