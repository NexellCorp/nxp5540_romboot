//------------------------------------------------------------------------------
//
//	Copyright (C) 2009 Nexell Co., All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
//	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS
//	FOR A PARTICULAR PURPOSE.
//
//	Module		: GPIO
//	File		: nx_gpio.h
//	Description:
//	Author		: Firmware Team
//	History	:
//
//------------------------------------------------------------------------------
#ifndef __NX_GPIO_H__
#define __NX_GPIO_H__

#include "../base/nx_prototype.h"

#ifdef	__cplusplus
extern "C"
{
#endif

#define GPIO_REG_STRIDE		0x80

//------------------------------------------------------------------------------
/// @defgroup	GPIO GPIO
//------------------------------------------------------------------------------
//@{

/// @brief	GPIO Module's Register List
struct	NX_GPIO_RegisterSet
{
	volatile U32 GPIOx_OUT;				///< 0x000	: Output Register
	volatile U32 GPIOx_OUTENB;			///< 0x004	: Output Enable Register
	volatile U32 GPIOx_DETMODE[2];			///< 0x008	: Event Detect Mode Register
	volatile U32 GPIOx_INTENB;			///< 0x010	: Interrupt Enable Register
	volatile U32 GPIOx_DET;				///< 0x014	: Event Detect Register
	volatile U32 GPIOx_PAD;				///< 0x018	: PAD Status Register
	volatile U32 GPIOx_PUENB;			///< 0x01C	: Pull Up Enable Register /// @note charles - THIS REGISTER IS NOT USED
	volatile U32 GPIOx_ALTFN[2];			///< 0x020	: Alternate Function Select Register
	volatile U32 __Reserved[5];			///< 0x028	:
	volatile U32 GPIOx_DETENB;			///< 0x03C	: IntPend Detect Enable Register
	volatile U32 GPIOx_SLEW;			///< 0x040
	volatile U32 GPIOx_SLEW_DISABLE_DEFAULT;    	///< 0x044
	volatile U32 GPIOx_DRV1;                    	///< 0x048
	volatile U32 GPIOx_DRV1_DISABLE_DEFAULT;    	///< 0x04C
	volatile U32 GPIOx_DRV0;                    	///< 0x050
	volatile U32 GPIOx_DRV0_DISABLE_DEFAULT;    	///< 0x054
	volatile U32 GPIOx_PULLSEL;                 	///< 0x058
	volatile U32 GPIOx_PULLSEL_DISABLE_DEFAULT; 	///< 0x05C
	volatile U32 GPIOx_PULLENB;                 	///< 0x060
	volatile U32 GPIOx_PULLENB_DISABLE_DEFAULT; 	///< 0x064
	volatile U32 GPIOx_InputMuxSelect[2];		///< 0x068
	volatile U32 GPIOx_SECURE_MARKING;		///< 0x070
	volatile U32 GPIOx_INPUTENB;			///< 0x074
	volatile U32 GPIOx_INPUTENB_DISABLE_DEFAULT;	///< 0x078
	
	U8 __Reserved_MID0[(GPIO_REG_STRIDE*1)-((GPIO_REG_STRIDE*0)+0x7C)];

	volatile U32 GPIOx_SET_OUT;			///< 0x100	: Output Register
	volatile U32 GPIOx_SET_OUTENB;			///< 0x104	: Output Enable Register
	//volatile U32 GPIOx_SET_DETMODE[2];		///< 0x108	: Event Detect Mode Register
	volatile U32 __Reserved_SET0[2];		///< 0x108	:
	volatile U32 GPIOx_SET_INTENB;			///< 0x110	: Interrupt Enable Register
	//volatile U32 GPIOx_SET_DET;			///< 0x114	: Event Detect Register
	volatile U32 __Reserved_SET1[1];
	volatile U32 GPIOx_SET_PAD;			///< 0x118	: PAD Status Register
	volatile U32 GPIOx_SET_PUENB;			///< 0x11C	: Pull Up Enable Register /// @note charles - THIS REGISTER IS NOT USED
	//volatile U32 GPIOx_SET_ALTFN[2];		///< 0x120	: Alternate Function Select Register
	volatile U32 __Reserved_SET2[2];		///< 0x120	:
	volatile U32 __Reserved_SET3[5];		///< 0x128	:
	volatile U32 GPIOx_SET_DETENB;			///< 0x13C	: IntPend Detect Enable Register
	volatile U32 GPIOx_SET_SLEW;			///< 0x140
	volatile U32 GPIOx_SET_SLEW_DISABLE_DEFAULT;    ///< 0x144
	volatile U32 GPIOx_SET_DRV1;                    ///< 0x148
	volatile U32 GPIOx_SET_DRV1_DISABLE_DEFAULT;    ///< 0x14C
	volatile U32 GPIOx_SET_DRV0;                    ///< 0x150
	volatile U32 GPIOx_SET_DRV0_DISABLE_DEFAULT;    ///< 0x154
	volatile U32 GPIOx_SET_PULLSEL;                 ///< 0x158
	volatile U32 GPIOx_SET_PULLSEL_DISABLE_DEFAULT; ///< 0x15C
	volatile U32 GPIOx_SET_PULLENB;                 ///< 0x160
	volatile U32 GPIOx_SET_PULLENB_DISABLE_DEFAULT; ///< 0x164
	volatile U32 GPIOx_SET_InputMuxSelect[2];	///< 0x168
	volatile U32 __Reserved_SET4[1];		///< 0x170
	volatile U32 GPIOx_SET_INPUTENB;		///< 0x174
	volatile U32 GPIOx_SET_INPUTENB_DISABLE_DEFAULT;///< 0x178
	
	U8 __Reserved_MID1[(GPIO_REG_STRIDE*2)-((GPIO_REG_STRIDE*1)+0x7C)];

	volatile U32 GPIOx_CLR_OUT;			///< 0x200	: Output Register
	volatile U32 GPIOx_CLR_OUTENB;			///< 0x204	: Output Enable Register
	//volatile U32 GPIOx_CLR_DETMODE[2];		///< 0x208	: Event Detect Mode Register
	volatile U32 __Reserved_CLR0[2];		///< 0x228	:
	volatile U32 GPIOx_CLR_INTENB;			///< 0x210	: Interrupt Enable Register
	//volatile U32 GPIOx_CLR_DET;			///< 0x214	: Event Detect Register
	volatile U32 __Reserved_CLR1[1];
	volatile U32 GPIOx_CLR_PAD;			///< 0x218	: PAD Status Register
	volatile U32 GPIOx_CLR_PUENB;			///< 0x21C	: Pull Up Enable Register /// @note charles - THIS REGISTER IS NOT USED
	//volatile U32 GPIOx_CLR_ALTFN[2];		///< 0x220	: Alternate Function Select Register
	volatile U32 __Reserved_CLR2[2];		///< 0x220	:
	volatile U32 __Reserved_CLR3[5];		///< 0x228	:
	volatile U32 GPIOx_CLR_DETENB;			///< 0x23C	: IntPend Detect Enable Register
	volatile U32 GPIOx_CLR_SLEW;			///< 0x240
	volatile U32 GPIOx_CLR_SLEW_DISABLE_DEFAULT;    ///< 0x244
	volatile U32 GPIOx_CLR_DRV1;                    ///< 0x248
	volatile U32 GPIOx_CLR_DRV1_DISABLE_DEFAULT;    ///< 0x24C
	volatile U32 GPIOx_CLR_DRV0;                    ///< 0x250
	volatile U32 GPIOx_CLR_DRV0_DISABLE_DEFAULT;    ///< 0x254
	volatile U32 GPIOx_CLR_PULLSEL;                 ///< 0x258
	volatile U32 GPIOx_CLR_PULLSEL_DISABLE_DEFAULT; ///< 0x25C
	volatile U32 GPIOx_CLR_PULLENB;                 ///< 0x260
	volatile U32 GPIOx_CLR_PULLENB_DISABLE_DEFAULT; ///< 0x264
	volatile U32 GPIOx_CLR_InputMuxSelect[2];	///< 0x268
	volatile U32 __Reserved_CLR4[1];		///< 0x270
	volatile U32 GPIOx_CLR_INPUTENB;		///< 0x274
	volatile U32 GPIOx_CLR_INPUTENB_DISABLE_DEFAULT;///< 0x278

	//@modified choiyk 2013-02-25 오후 9:52:32 
	// 이 부분이 중요 (romboot시 이부분이 꼭 필요하다..) 
	U8 __Reserved1[0x1000-((GPIO_REG_STRIDE*2)+0x7C)];
};

///@brief	GPIO Interrupts for interrupt interface
enum
{
	NX_GPIO_INT_GPIO0	= 0,	///<	GPIO 0 Interrupt
	NX_GPIO_INT_GPIO1	= 1,	///<	GPIO 1 Interrupt
	NX_GPIO_INT_GPIO2	= 2,	///<	GPIO 2 Interrupt
	NX_GPIO_INT_GPIO3	= 3,	///<	GPIO 3 Interrupt
	NX_GPIO_INT_GPIO4	= 4,	///<	GPIO 4 Interrupt
	NX_GPIO_INT_GPIO5	= 5,	///<	GPIO 5 Interrupt
	NX_GPIO_INT_GPIO6	= 6,	///<	GPIO 6 Interrupt
	NX_GPIO_INT_GPIO7	= 7,	///<	GPIO 7 Interrupt
	NX_GPIO_INT_GPIO8	= 8,	///<	GPIO 8 Interrupt
	NX_GPIO_INT_GPIO9	= 9,	///<	GPIO 9 Interrupt
	NX_GPIO_INT_GPIO10	= 10,	///<	GPIO 10 Interrupt
	NX_GPIO_INT_GPIO11	= 11,	///<	GPIO 11 Interrupt
	NX_GPIO_INT_GPIO12	= 12,	///<	GPIO 12 Interrupt
	NX_GPIO_INT_GPIO13	= 13,	///<	GPIO 13 Interrupt
	NX_GPIO_INT_GPIO14	= 14,	///<	GPIO 14 Interrupt
	NX_GPIO_INT_GPIO15	= 15,	///<	GPIO 15 Interrupt
	NX_GPIO_INT_GPIO16	= 16,	///<	GPIO 16 Interrupt
	NX_GPIO_INT_GPIO17	= 17,	///<	GPIO 17 Interrupt
	NX_GPIO_INT_GPIO18	= 18,	///<	GPIO 18 Interrupt
	NX_GPIO_INT_GPIO19	= 19,	///<	GPIO 19 Interrupt
	NX_GPIO_INT_GPIO20	= 20,	///<	GPIO 20 Interrupt
	NX_GPIO_INT_GPIO21	= 21,	///<	GPIO 21 Interrupt
	NX_GPIO_INT_GPIO22	= 22,	///<	GPIO 22 Interrupt
	NX_GPIO_INT_GPIO23	= 23,	///<	GPIO 23 Interrupt
	NX_GPIO_INT_GPIO24	= 24,	///<	GPIO 24 Interrupt
	NX_GPIO_INT_GPIO25	= 25,	///<	GPIO 25 Interrupt
	NX_GPIO_INT_GPIO26	= 26,	///<	GPIO 26 Interrupt
	NX_GPIO_INT_GPIO27	= 27,	///<	GPIO 27 Interrupt
	NX_GPIO_INT_GPIO28	= 28,	///<	GPIO 28 Interrupt
	NX_GPIO_INT_GPIO29	= 29,	///<	GPIO 29 Interrupt
	NX_GPIO_INT_GPIO30	= 30,	///<	GPIO 30 Interrupt
	NX_GPIO_INT_GPIO31	= 31	///<	GPIO 31 Interrupt
};

/// @brief	GPIO interrupt mode
typedef enum
{
	NX_GPIO_INTMODE_LOWLEVEL	= 0UL,	///< Low level detect
	NX_GPIO_INTMODE_HIGHLEVEL	= 1UL,	///< High level detect
	NX_GPIO_INTMODE_FALLINGEDGE	= 2UL,	///< Falling edge detect
	NX_GPIO_INTMODE_RISINGEDGE	= 3UL,	///< Rising edge detect
	NX_GPIO_INTMODE_BOTHEDGE	= 4UL	///< both (rise and falling) edge detect

}NX_GPIO_INTMODE;

/// @brief	I/O mode
typedef enum
{
	NX_GPIO_PADFUNC_GPIO		= 0UL,	///< GPIO mode
	NX_GPIO_PADFUNC_1		= 1UL,	///< Alternate function 1
	NX_GPIO_PADFUNC_2		= 2UL,	///< Alternate function 2
	NX_GPIO_PADFUNC_3		= 3UL	///< Alternate function 3

}NX_GPIO_PADFUNC ;

typedef enum
{
	NX_GPIO_DRVSTRENGTH_0	= 0UL,
	NX_GPIO_DRVSTRENGTH_1	= 1UL,
	NX_GPIO_DRVSTRENGTH_2	= 2UL,
	NX_GPIO_DRVSTRENGTH_3	= 3UL

}NX_GPIO_DRVSTRENGTH;

typedef enum
{
	NX_GPIO_PULL_DOWN	= 0UL,
	NX_GPIO_PULL_UP		= 1UL,
	NX_GPIO_PULL_OFF	= 2UL
} NX_GPIO_PULL;
//------------------------------------------------------------------------------
/// @name	Module Interface
//@{
CBOOL	NX_GPIO_Initialize( void );
U32		NX_GPIO_GetNumberOfModule( void );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//@{
U32		NX_GPIO_GetPhysicalAddress( U32 ModuleIndex );
U32		NX_SECURE_GPIO_GetPhysicalAddress( U32 ModuleIndex );
U32		NX_GPIO_GetSizeOfRegisterSet( void );
void	NX_GPIO_SetBaseAddress( U32 ModuleIndex, U32 BaseAddress );
U32		NX_GPIO_GetBaseAddress( U32 ModuleIndex );
CBOOL	NX_GPIO_OpenModule( U32 ModuleIndex );
CBOOL	NX_GPIO_CloseModule( U32 ModuleIndex );
CBOOL	NX_GPIO_CheckBusy( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Interrupt Interface
//@{
U32		NX_GPIO_GetInterruptNumber( U32 ModuleIndex );

void	NX_GPIO_SetInterruptEnable( U32 ModuleIndex, S32 IntNum, CBOOL Enable );
CBOOL	NX_GPIO_GetInterruptEnable( U32 ModuleIndex, S32 IntNum );
CBOOL	NX_GPIO_GetInterruptPending( U32 ModuleIndex, S32 IntNum );
void	NX_GPIO_ClearInterruptPending( U32 ModuleIndex, S32 IntNum );

void	NX_GPIO_SetInterruptEnableAll( U32 ModuleIndex, CBOOL Enable );
CBOOL	NX_GPIO_GetInterruptEnableAll( U32 ModuleIndex );
CBOOL	NX_GPIO_GetInterruptPendingAll( U32 ModuleIndex );
void	NX_GPIO_ClearInterruptPendingAll( U32 ModuleIndex );

void	NX_GPIO_SetInterruptEnable32( U32 ModuleIndex, U32 EnableFlag );
U32		NX_GPIO_GetInterruptEnable32( U32 ModuleIndex );
U32		NX_GPIO_GetInterruptPending32( U32 ModuleIndex );
void	NX_GPIO_ClearInterruptPending32( U32 ModuleIndex, U32 PendingFlag );

S32		NX_GPIO_GetInterruptPendingNumber( U32 ModuleIndex );	// -1 if None
//@}

//------------------------------------------------------------------------------
///	@name	GPIO Operation.
//@{
void			NX_GPIO_SetInterruptMode( U32 ModuleIndex, U32 BitNumber, NX_GPIO_INTMODE IntMode );
NX_GPIO_INTMODE	NX_GPIO_GetInterruptMode( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetDetectMode32_0( U32 ModuleIndex, U32 Value );
U32				NX_GPIO_GetDetectMode32_0( U32 ModuleIndex );
void			NX_GPIO_SetDetectMode32_1( U32 ModuleIndex, U32 Value );
U32				NX_GPIO_GetDetectMode32_1( U32 ModuleIndex );
void			NX_GPIO_SetDetectEnable ( U32 ModuleIndex, U32 BitNumber, CBOOL DetectEnb );
CBOOL			NX_GPIO_GetDetectEnable ( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetDetectEnable32 ( U32 ModuleIndex, U32 EnableFlag );
U32				NX_GPIO_GetDetectEnable32 ( U32 ModuleIndex );
void			NX_GPIO_SetOutputEnable ( U32 ModuleIndex, U32 BitNumber, CBOOL OutputEnb );
CBOOL			NX_GPIO_GetOutputEnable ( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetOutputEnable32 ( U32 ModuleIndex, U32 Value );
U32				NX_GPIO_GetOutputEnable32 ( U32 ModuleIndex );
void			NX_GPIO_SetOutputValue	( U32 ModuleIndex, U32 BitNumber, CBOOL Value );
CBOOL			NX_GPIO_GetOutputValue	( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetOutputValue32	( U32 ModuleIndex, U32 Value );
U32				NX_GPIO_GetOutputValue32	( U32 ModuleIndex );
CBOOL			NX_GPIO_GetInputValue		( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetPullUpEnable ( U32 ModuleIndex, U32 BitNumber, CBOOL enable);
CBOOL			NX_GPIO_GetPullUpEnable ( U32 ModuleIndex, U32 BitNumber );
void			NX_GPIO_SetPullUpEnable32 ( U32 ModuleIndex, U32 Value );
U32				NX_GPIO_GetPullUpEnable32 ( U32 ModuleIndex );

void			NX_GPIO_SetPadFunction( U32 ModuleIndex, U32 BitNumber, NX_GPIO_PADFUNC padfunc );
void			NX_GPIO_SetPadFunction32_0( U32 ModuleIndex, U32 Value );
void			NX_GPIO_SetPadFunction32_1( U32 ModuleIndex, U32 Value );
NX_GPIO_PADFUNC	NX_GPIO_GetPadFunction( U32 ModuleIndex, U32 BitNumber );
U32				NX_GPIO_GetPadFunction32_0( U32 ModuleIndex );
U32				NX_GPIO_GetPadFunction32_1( U32 ModuleIndex );

//------------------------------------------------------------------------------
///	@name	GPIO Operation.
//@{
void	NX_GPIO_SetSLEW	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetSLEW	( U32 ModuleIndex );           
void	NX_GPIO_SetSLEW_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetSLEW_DISABLE_DEFAULT	( U32 ModuleIndex );           
void	NX_GPIO_SetDRV1	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetDRV1	( U32 ModuleIndex );           
void	NX_GPIO_SetDRV1_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetDRV1_DISABLE_DEFAULT	( U32 ModuleIndex );           
void	NX_GPIO_SetDRV0	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetDRV0	( U32 ModuleIndex );           
void	NX_GPIO_SetDRV0_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetDRV0_DISABLE_DEFAULT	( U32 ModuleIndex );           
void	NX_GPIO_SetPULLSEL	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetPULLSEL	( U32 ModuleIndex );           
void	NX_GPIO_SetPULLSEL_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetPULLSEL_DISABLE_DEFAULT	( U32 ModuleIndex );           
void	NX_GPIO_SetPULLENB	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetPULLENB	( U32 ModuleIndex );           
void	NX_GPIO_SetPULLENB_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetPULLENB_DISABLE_DEFAULT	( U32 ModuleIndex );           
void	NX_GPIO_SetInputMuxSelect0	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetInputMuxSelect0	( U32 ModuleIndex );
void	NX_GPIO_SetInputMuxSelect1	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetInputMuxSelect1	( U32 ModuleIndex );
void	NX_GPIO_SetSECURE_MARKING	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetSECURE_MARKING	( U32 ModuleIndex );           
void	NX_GPIO_SetINPUTENB	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetINPUTENB	( U32 ModuleIndex );           
void	NX_GPIO_SetINPUTENB_DISABLE_DEFAULT	( U32 ModuleIndex, U32 Value );
U32		NX_GPIO_GetINPUTENB_DISABLE_DEFAULT	( U32 ModuleIndex );           

U32		NX_GPIO_GetValidBit( U32 ModuleIndex );

void	NX_GPIO_EnablePAD ( U32 ModuleIndex, U32 channel );
void	NX_GPIO_SetPadFunctionEnable (  U32 padInfo  );

//@}

//@}

#ifdef	__cplusplus
}
#endif

#endif //__NX_GPIO_H__
