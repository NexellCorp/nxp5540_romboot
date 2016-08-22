/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module          : Base
 *	File            : libarm.c
 *	Description     :
 *	Author          : Hans
 *	History         : 2014.08.20 Hans create
 *			2016.08.10 Hans add architecture feature
 */
#include <nx_type.h>
#include "nx_etacarinae.h"

#ifdef aarch32
static U32 u32divider(U32 dividend, U32 divisor, CBOOL qorr)
{
	U32 quotient, remainder;
	U32 t, num_bits;
	U32 q, bit, d=0;
	U32 i;

	remainder = 0;
	quotient = 0;

	if (divisor == 0)
		return -1;

	if (divisor > dividend)
		return 0;
	

	if (divisor == dividend)
		return 1;

	num_bits = 32;

	while (remainder < divisor) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		d = dividend;
		dividend = dividend << 1;
		num_bits--;
	}

	dividend = d;
	remainder = remainder >> 1;
	num_bits++;

	for (i = 0; i < num_bits; i++) {
		bit = (dividend & 0x80000000) >> 31;
		remainder = (remainder << 1) | bit;
		t = remainder - divisor;
		q = !((t & 0x80000000) >> 31);
		dividend = dividend << 1;
		quotient = (quotient << 1) | q;
		if (q)
			remainder = t;
	}
	if (qorr)
		return quotient;
	else
		return remainder;
}

inline U32 getquotient(U32 dividend, U32 divisor)
{
	return u32divider(dividend, divisor, CTRUE);
}
inline U32 getremainder(U32 dividend, U32 divisor)
{
	return u32divider(dividend, divisor, CFALSE);
}
#endif

#ifdef aarch64
inline U32 getquotient(U32 dividend, U32 divisor)
{
	return dividend / divisor;
}
inline U32 getremainder(U32 dividend, U32 divisor)
{
	return dividend % divisor;
}
#endif

void delay(U32 us)
{
#ifdef NXP5430
	register volatile unsigned int   count, temp;

	for (count = 0; count < us; count++) {
		temp ^= count;
	}
#else
	register volatile unsigned int   count, temp;

	for (count = 0; count < us; count++) {
		temp ^= count;
	}
#endif
}
