////////////////////////////////////////////////////////////////////////////////
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	Nexell informs that this code and information is provided "as is" base
//	and without warranty of any kind, either expressed or implied, including
//	but not limited to the implied warranties of merchantability and/or fitness
//	for a particular puporse.
//
//
//	Module		: CRC32.c
//	File		:
//	Description	:
//	Author		: Hans
//	History		: 2013.01.10 First implementation
//
////////////////////////////////////////////////////////////////////////////////
#include <nx_etacarinae.h>
#include <nx_type.h>

U32 get_fcs(U32 fcs, U8 data)
{
	register int i;
	fcs ^= (U32)data;
	for (i = 0; i < 8; i++) {
		if (fcs & 0x01)
			fcs = (fcs >> 1) ^ POLY;
		fcs >>= 1;
	}
	return fcs;
}

