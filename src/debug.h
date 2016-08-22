//------------------------------------------------------------------------------
/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module		:
 *	File		: debug.h
 *	Description     :
 *	Author		: Hans
 *	History		: 
 *
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

//#include <stdio.h>
//#include <stdarg.h>
#include <nx_type.h>

CBOOL   DebugInit( U32 port );
void    DebugPutch( S8 ch );
//S8      DebugGetch( void );
CBOOL	DebugIsUartTxDone(void);

CBOOL	DebugIsTXEmpty(void);
CBOOL   DebugIsBusy( void );
S8	DebugGetch( void );

#endif // __DEBUG_H__
