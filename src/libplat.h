/*
 *	Copyright (C) 2012 Nexell Co., All Rights Reserved
 *	Nexell Co. Proprietary & Confidential
 *	
 *	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
 *	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
 *	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *	FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	Module		: library
 *	File		: libplat.h
 *	Description	: various chip library
 *	Author		: Hans
 *	History		: 2016.08.12 First Implementation
 */

#include <nx_gpio.h>
#include <nx_type.h>

#ifdef NXP5430
void ResetCon(U32 devicenum, CBOOL en);
inline void GPIOSetAltFunction(U32 AltFunc);
#endif
void Decrypt(U32 *SrcAddr, U32 *DestAddr, U32 Size);

#ifdef NXP5540
struct nxpadi;
void GPIOSetAltFunction(const struct nxpadi *pad, CBOOL setalt);
void GPIOSetDrvSt(const struct nxpadi *pad, NX_GPIO_DRVSTRENGTH str);
void GPIOSetPullup(const struct nxpadi *pad, NX_GPIO_PULL pull);
#endif
