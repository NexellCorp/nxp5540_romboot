////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2009 Nexell Co., Ltd All Rights Reserved
// Nexell Co. Proprietary & Confidential
// 
// Nexell informs that this code and information is provided "as is" base
// and without warranty of any kind, either expressed or implied, including
// but not limited to the implied warranties of merchantability and/or
// fitness for a particular puporse.
// 
// Module		:
// File		: iROMBOOT.c
// Description	:
// Author		: Hans
// History		:
//		2014-01-12	Hans create
//		2016-08-09	Hans modified for NXP5540
////////////////////////////////////////////////////////////////////////////////
#include "printf.h"

inline void buildinfo(void)
{
	printf("\r\n\n iROMBOOT by Nexell Co. : Built on %s %s\r\n",
			__DATE__, __TIME__);
}

