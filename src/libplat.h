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

#ifdef NXP5430
void ResetCon(U32 devicenum, CBOOL en);
inline void GPIOSetAltFunction(U32 AltFunc);
#endif
void Decrypt(U32 *SrcAddr, U32 *DestAddr, U32 Size);

#ifdef NXP5540
void GPIOSetAltFunction(struct nxpadi *pad, CBOOL setalt);
void GPIOSetDrvSt(struct nxpadi *pad, NX_GPIO_DRVSTRENGTH str);
void GPIOSetPullup(struct nxpadi *pad, NX_GPIO_PULL pull);
#endif
