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
 *	File		: libplat.c
 *	Description	: various chip library
 *	Author		: Hans
 *	History		: 2016.08.12 First Implementation
 */

#include <nx_type.h>

#include <nx_gpio.h>

#ifdef NXP5540
#include <nx_chip_iomux.h>
#endif

#ifdef NXP5430
#include <nx_rstcon.h>
struct NX_RSTCON_RegisterSet * const pReg_RstCon =
		(struct NX_RSTCON_RegisterSet * const)PHY_BASEADDR_RSTCON_MODULE;

void ResetCon(U32 devicenum, CBOOL en)
{
	if (en)
		ClearIO32(&pReg_RstCon->REGRST[(devicenum >> 5) & 0x3],
			  (0x1 << (devicenum & 0x1F))); // reset
	else
		SetIO32(&pReg_RstCon->REGRST[(devicenum >> 5) & 0x3],
			(0x1 << (devicenum & 0x1F))); // reset negate
}

struct NXPERIDOT_GPIO_RegSet
{
	struct NX_GPIO_RegisterSet NXGPIO;
	U8 Reserved[0x1000 - sizeof(struct NX_GPIO_RegisterSet)];
};

#if !DIRECT_IO
static struct NXPERIDOT_GPIO_RegSet (* const pBaseGPIOReg)[1] =
	(struct NXPERIDOT_GPIO_RegSet (*)[])(PHY_BASEADDR_GPIOA_MODULE);
inline void GPIOSetAltFunction(U32 AltFunc)
{
	register struct NX_GPIO_RegisterSet *pGPIOReg =
			&pBaseGPIOReg[(AltFunc >> 8) & 0x7]->NXGPIO;
	pGPIOReg->GPIOx_ALTFN[(AltFunc >> 6) & 0x1] =
			(pGPIOReg->GPIOx_ALTFN[(AltFunc >> 6) & 0x1] &
				~(0x3UL << (((AltFunc >> 3) & 0xF) * 2)))
			| ((AltFunc & 0x3) << (((AltFunc >> 3) & 0xF) * 2));
}
#endif
#endif

#ifdef NXP5540
extern struct NX_GPIO_RegisterSet (* const pGPIOReg)[1];
void GPIOSetAltFunction(struct nxpadi *pad, CBOOL setalt)
{
	U32 regvalue;
	U32 alt = setalt ? pad->alt : 0;

	if (!pad->flag)
		return;

	regvalue = pGPIOReg[pad->grp]->GPIOx_ALTFN[pad->pin >> 4];
	pGPIOReg[pad->grp]->GPIOx_ALTFN[pad->pin >> 4] =
		(regvalue & ~(3 << (pad->pin & 0xF))) |
			pad->alt << (pad->pin & 0xF);
}
#if 0
void GPIO_SetIO(struct padi *pad, CBOOL inout)	/* 0: out, 1: in */
{
	struct NX_GPIO_RegisterSet *pGPIOReg = pNXGPIO[pad->group];
	if (!pad->flag)
		return;
	if (inout)
		pGPIOReg->GPIOx_CLR_OUTENB = 1 << pad->pin;
	else
		pGPIOReg->GPIOx_SET_OUTENB = 1 << pad->pin;
}
#endif
void GPIOSetDrvSt(struct nxpadi *pad, NX_GPIO_DRVSTRENGTH str)
{
	struct NX_GPIO_RegisterSet *pGPIOxReg = pGPIOReg[pad->grp];
	U32 d0 = str & 1, d1 = (str >> 1) & 1;

	if (!pad->flag)
		return;

	if (d0) {
		pGPIOxReg->GPIOx_SET_DRV0 = 0x1 << pad->pin;
		pGPIOxReg->GPIOx_SET_DRV0_DISABLE_DEFAULT = 0x1 << pad->pin;
	} else {
		pGPIOxReg->GPIOx_CLR_DRV0 = 0x1 << pad->pin;
		pGPIOxReg->GPIOx_CLR_DRV0_DISABLE_DEFAULT = 0x1 << pad->pin;
	}
	if (d1) {
		pGPIOxReg->GPIOx_SET_DRV1 = 0x1 << pad->pin;
		pGPIOxReg->GPIOx_SET_DRV1_DISABLE_DEFAULT = 0x1 << pad->pin;
	} else {
		pGPIOxReg->GPIOx_CLR_DRV1 = 0x1 << pad->pin;
		pGPIOxReg->GPIOx_CLR_DRV1_DISABLE_DEFAULT = 0x1 << pad->pin;
	}
}
void GPIOSetPullup(struct nxpadi *pad, NX_GPIO_PULL pull)
{
	struct NX_GPIO_RegisterSet *pGPIOxReg = pGPIOReg[pad->grp];
	U32 pullupdown = pull & 1, pullen = (pull >> 1) & 1;

	if (!pad->flag)
		return;

	if (pullupdown) {
		pGPIOxReg->GPIOx_SET_PULLSEL = 1 << pad->pin;
		pGPIOxReg->GPIOx_SET_PULLSEL_DISABLE_DEFAULT = 1 << pad->pin;
	} else {
		pGPIOxReg->GPIOx_CLR_PULLSEL = 1 << pad->pin;
		pGPIOxReg->GPIOx_CLR_PULLSEL_DISABLE_DEFAULT = 1 << pad->pin;
	}
	if (pullen) {
		pGPIOxReg->GPIOx_SET_PULLENB = 1 << pad->pin;
		pGPIOxReg->GPIOx_SET_PULLENB_DISABLE_DEFAULT = 1 << pad->pin;
	} else {
		pGPIOxReg->GPIOx_CLR_PULLENB = 1 << pad->pin;
		pGPIOxReg->GPIOx_CLR_PULLENB_DISABLE_DEFAULT = 1 << pad->pin;
	}
}
#endif
