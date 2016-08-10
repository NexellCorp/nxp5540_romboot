//------------------------------------------------------------------------------
//
//	Copyright (C) Nexell Co. 2012
//
//  This confidential and proprietary software may be used only as authorized by a
//  licensing agreement from Nexell Co.
//  The entire notice above must be reproduced on all authorized copies and copies
//  may only be made to the extent permitted by a licensing agreement from Nexell Co.
//
//	Module		:
//	File		: nx_CRYPTO.h
//	Description	:
//	Author		:
//	History		:
//------------------------------------------------------------------------------


#ifndef __NX_CRYPTO_H__
#define __NX_CRYPTO_H__

#include "../base/nx_prototype.h"

#ifdef	__cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup	CRYPTO
//------------------------------------------------------------------------------
//@{

// TRNG Mode
#define NX_TRNG_CPUMODE  (0)
#define NX_TRNG_DRNGMODE (1)

#define NX_TRNG_RO_ENABLE   (0)
#define NX_TRNG_META_ENABLE (1)

// Whitening Mode
#define NX_TRNG_VON_WHITENING  (1)
#define NX_TRNG_LFSR_WHITENING (2)

// Interrupt Sources
#define NX_TRNG_INT_SRC_TESTER_MIN        (7)
#define NX_TRNG_INT_SRC_TESTER_MAX        (6)
#define NX_TRNG_INT_SRC_PROT1             (5)
#define NX_TRNG_INT_SRC_PROT0             (4)
#define NX_TRNG_INT_SRC_REPEAT            (3)
#define NX_TRNG_INT_SRC_DRNG_UNDERRUN     (2)
#define NX_TRNG_INT_SRC_TRNG_UNDERRUN     (1)
#define NX_TRNG_INT_SRC_DONE              (0)

// Internal Clear
#define NX_TRNG_FIFO_CLR     (0x02)
#define NX_TRNG_REPEAT_CLR   (0x10)
#define NX_TRNG_PROP_CLR     (0x20)
#define NX_TRNG_TESTER_CLR   (0x40)

//--------------------------------------------------------------------------
/// @brief	register map
typedef struct
{
	volatile U32 CRYPTO_CRT_CTRL0 ; // 0x00
	volatile U32 _Reserved[2]     ; // 0x04, 0x08
	volatile U32 CRYPTO_AES_CTRL0 ; // 0x0c
	volatile U32 CRYPTO_AES_IV0   ;
	volatile U32 CRYPTO_AES_IV1   ;
	volatile U32 CRYPTO_AES_IV2   ;
	volatile U32 CRYPTO_AES_IV3   ;
	volatile U32 CRYPTO_AES_CNT0  ;
	volatile U32 CRYPTO_AES_CNT1  ;
	volatile U32 CRYPTO_AES_CNT2  ;
	volatile U32 CRYPTO_AES_CNT3  ;
	volatile U32 CRYPTO_AES_KEY0  ;
	volatile U32 CRYPTO_AES_KEY1  ;
	volatile U32 CRYPTO_AES_KEY2  ;
	volatile U32 CRYPTO_AES_KEY3  ;
	volatile U32 CRYPTO_AES_KEY4  ;
	volatile U32 CRYPTO_AES_KEY5  ;
	volatile U32 CRYPTO_AES_KEY6  ;
	volatile U32 CRYPTO_AES_KEY7  ;
	volatile U32 CRYPTO_AES_TIN0  ;
	volatile U32 CRYPTO_AES_TIN1  ;
	volatile U32 CRYPTO_AES_TIN2  ;
	volatile U32 CRYPTO_AES_TIN3  ;
	volatile U32 CRYPTO_AES_TOUT0 ;
	volatile U32 CRYPTO_AES_TOUT1 ;
	volatile U32 CRYPTO_AES_TOUT2 ;
	volatile U32 CRYPTO_AES_TOUT3 ;
	volatile U32 CRYPTO_DES_CTRL0 ;
	volatile U32 CRYPTO_DES_IV0   ;
	volatile U32 CRYPTO_DES_IV1   ;
	volatile U32 CRYPTO_DES_KEY0_0;
	volatile U32 CRYPTO_DES_KEY0_1;
	volatile U32 CRYPTO_DES_KEY1_0;
	volatile U32 CRYPTO_DES_KEY1_1;
	volatile U32 CRYPTO_DES_KEY2_0;
	volatile U32 CRYPTO_DES_KEY2_1;
	volatile U32 CRYPTO_DES_TIN0  ;
	volatile U32 CRYPTO_DES_TIN1  ;
	volatile U32 CRYPTO_DES_TOUT0 ;
	volatile U32 CRYPTO_DES_TOUT1 ;
	volatile U32 CRYPTO_CRT_BDMAR ; // DMA Access Region ( DMA에 설정해주는 Register Addr  )
	volatile U32 CRYPTO_CRT_BDMAW ; // DMA Access Region
	volatile U32 CRYPTO_CRT_HDMAR ; // DMA Access Region
	volatile U32 CRYPTO_HASH_CTRL0;
	volatile U32 CRYPTO_HASH_IV0  ;
	volatile U32 CRYPTO_HASH_IV1  ;
	volatile U32 CRYPTO_HASH_IV2  ;
	volatile U32 CRYPTO_HASH_IV3  ;
	volatile U32 CRYPTO_HASH_IV4  ;
	volatile U32 CRYPTO_HASH_TOUT0;
	volatile U32 CRYPTO_HASH_TOUT1;
	volatile U32 CRYPTO_HASH_TOUT2;
	volatile U32 CRYPTO_HASH_TOUT3;
	volatile U32 CRYPTO_HASH_TOUT4;
	volatile U32 CRYPTO_HASH_TIN  ;
	volatile U32 CRYPTO_HASH_MSZE0;
	volatile U32 CRYPTO_HASH_MSZE1;
} NX_CRYPTO_RegisterSet;


//------------------------------------------------------------------------------
///	@name	CRYPTO Interface
//------------------------------------------------------------------------------
//@{
//U32   NX_CRYPTO_GetTEMP( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//------------------------------------------------------------------------------
//@{
CBOOL NX_CRYPTO_Initialize( void );
U32   NX_CRYPTO_GetNumberOfModule( void );

U32   NX_CRYPTO_GetSizeOfRegisterSet( void );
void  NX_CRYPTO_SetBaseAddress( U32 ModuleIndex, U32 BaseAddress );
U32   NX_CRYPTO_GetBaseAddress( U32 ModuleIndex );
U32   NX_CRYPTO_GetPhysicalAddress ( U32 ModuleIndex );
CBOOL NX_CRYPTO_OpenModule( U32 ModuleIndex );
CBOOL NX_CRYPTO_CloseModule( U32 ModuleIndex );
//CBOOL NX_CRYPTO_CheckBusy( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	clock Interface : PCLK Gating
//------------------------------------------------------------------------------
U32 NX_CRYPTO_GetClockNumber (U32 ModuleIndex);

//------------------------------------------------------------------------------
///	@name	reset Interface
//------------------------------------------------------------------------------
//@{
U32 NX_CRYPTO_GetResetNumber ( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	No Interrupt Interface
//------------------------------------------------------------------------------
U32 NX_CRYPTO_GetInterruptNumber( U32 ModuleIndex );
void	NX_CRYPTO_SetInterruptEnable( U32 ModuleIndex, CBOOL Enb );
void	NX_CRYPTO_SetInterruptMask( U32 ModuleIndex, U32 Mask );

CBOOL	NX_CRYPTO_GetInterruptPendingAll( U32 ModuleIndex );
void	NX_CRYPTO_ClearInterruptPendingAll( U32 ModuleIndex );

//------------------------------------------------------------------------------
///	@name	DMA Interface
//------------------------------------------------------------------------------
//@{
/// @brief	DMA index for DMAChannelIndex
typedef enum {
	CRYPDMA_BR		= 0,
	CRYPDMA_BW		= 1,
	CRYPDMA_HR		= 2,
}NX_CRYPTO_DMACHANNEL;

U32 NX_CRYPTO_GetDMANumber ( U32 ModuleIndex , NX_CRYPTO_DMACHANNEL Channel);
U32 NX_CRYPTO_GetDMABusWidth( );
//@}

//------------------------------------------------------------------------------
///	@name	No PAD Interface
//------------------------------------------------------------------------------
void NX_CRYPTO_EnablePAD( U32 ModuleIndex, U32 ModeIndex );

//------------------------------------------------------------------------------
///	@name	Basic Use Functions
//------------------------------------------------------------------------------
//@{

void	NX_CRYPTO_SetAESTextIn			( U32 ModuleIndex, U32 AES_TIN0, U32 AES_TIN1, U32 AES_TIN2, U32 AES_TIN3 ); // AES_TIN0, AES_TIN1, AES_TIN2, AES_TIN3
void	NX_CRYPTO_SetAESInitVec			( U32 ModuleIndex, U32 AES_IV0,  U32 AES_IV1,  U32 AES_IV2,  U32 AES_IV3 ); // AES_IV0, AES_IV1, AES_IV2, AES_IV3
void	NX_CRYPTO_SetAESKey				( U32 ModuleIndex,
	U32 AES_KEY0, U32 AES_KEY1, U32 AES_KEY2, U32 AES_KEY3,
	U32 AES_KEY4, U32 AES_KEY5, U32 AES_KEY6, U32 AES_KEY7 ); // AES_KEY0, AES_KEY1, AES_KEY2, AES_KEY3, AES_KEY4, AES_KEY5, AES_KEY6, AES_KEY7
void	NX_CRYPTO_SetAESEfuseKeyMode		( U32 ModuleIndex, CBOOL Enb );
void	NX_CRYPTO_SetAESOutputSwap			( U32 ModuleIndex, CBOOL Enb );
void	NX_CRYPTO_SetAESInputSwap			( U32 ModuleIndex, CBOOL Enb ); // 지금은 넣을때 BigEndian으로 넣어주고 있다.
void	NX_CRYPTO_SetAESBlockCiphterMode	( U32 ModuleIndex, U32 Mode );  // Block Cipher Mode-> 0:ECB, 1:CBC, 2:CTR
void	NX_CRYPTO_SetAESMode			( U32 ModuleIndex, U32 Mode ); // AES Mode->0:128, 1:192, 2:256
void	NX_CRYPTO_SetAESDMAMode			( U32 ModuleIndex, U32 Mode ); // DMA Mode->0:FIFO mode, 1:DMA mode
void	NX_CRYPTO_SetAESEncoderMode		( U32 ModuleIndex, U32 Mode ); // AES Encoder Mode->0:Decoder, 1: Encoder
void	NX_CRYPTO_SetAESEnable			( U32 ModuleIndex, CBOOL Enb );
void	NX_CRYPTO_SetHASHRun			( U32 ModuleIndex, CBOOL Enb ); // HASH Run : Disable
void	NX_CRYPTO_SetDESRun				( U32 ModuleIndex, CBOOL Enb ); // DES Run
void	NX_CRYPTO_SetAESRun				( U32 ModuleIndex, CBOOL Enb );
void	NX_CRYPTO_GetAESTextOut			( U32 ModuleIndex, U32* AES_TOUT0, U32* AES_TOUT1, U32* AES_TOUT2, U32* AES_TOUT3 ); // AES_TOUT0, AES_TOUT1, AES_TOUT2, AES_TOUT3
void	NX_CRYPTO_SetLoadDESIV			( U32 ModuleIndex, CBOOL Enb ); // Load DES IV
void	NX_CRYPTO_SetLoadAESIV			( U32 ModuleIndex, CBOOL Enb ); // Load AES IV

CBOOL    NX_CRYPTO_GetIdleAES            ( U32 ModuleIndex );

CBOOL	NX_CRYPTO_GetIdleHASH( U32 ModuleIndex );
CBOOL	NX_CRYPTO_GetIdleDES ( U32 ModuleIndex );
void NX_CRYPTO_GetDESTextOut ( U32 ModuleIndex, U32 *DES_TOUT0, U32 *DES_TOUT1 );

void NX_CRYPTO_SetDESTextIn            ( U32 ModuleIndex, U32 DES_TIN0, U32 DES_TIN1 ); // DES_TIN0, DES_TIN1
void NX_CRYPTO_SetDESInitVec           ( U32 ModuleIndex, U32 DES_IV0,  U32 DES_IV1);
void NX_CRYPTO_SetDESKeyIn0            ( U32 ModuleIndex, U32 DES_KEY0_0, U32 DES_KEY1_0 );
void NX_CRYPTO_SetDESKeyIn1            ( U32 ModuleIndex, U32 DES_KEY1_0, U32 DES_KEY1_1 );
void NX_CRYPTO_SetDESKeyIn2            ( U32 ModuleIndex, U32 DES_KEY2_0, U32 DES_KEY2_1 );
void NX_CRYPTO_SetTDESMode             ( U32 ModuleIndex, U32 TDESMODE ); // TDESMODE
void NX_CRYPTO_SetDESOutputSwap        ( U32 ModuleIndex, CBOOL Enb );
void NX_CRYPTO_SetDESInputSwap         ( U32 ModuleIndex, CBOOL Enb ); // 지금은 넣을때 BigEndian으로 넣어주고 있다.
void NX_CRYPTO_SetDESBlockCiphterMode  ( U32 ModuleIndex, U32 Mode );  // Block Cipher Mode-> 0:ECB, 1:CBC
void NX_CRYPTO_SetDESDMAMode           ( U32 ModuleIndex, U32 Mode ); // DMA Mode->0:FIFO mode, 1:DMA mode
void NX_CRYPTO_SetDESMode              ( U32 ModuleIndex, U32 Mode ); // 0:DES, 1:TDES
void NX_CRYPTO_SetDESEncoderMode       ( U32 ModuleIndex, U32 Mode ); // DES Encoder Mode->0:Decoder, 1: Encoder
void NX_CRYPTO_SetDESEnable            ( U32 ModuleIndex, CBOOL Enb ); // DES Enable
void NX_CRYPTO_SetDMAWritePath         ( U32 ModuleIndex, U32 Mode ); // DMA Write Path : 0:AES, 1:DES
void NX_CRYPTO_SetMSZEE0               ( U32 ModuleIndex, U32 HASH_MSZE0, U32 HASH_MSZE1 );
void NX_CRYPTO_SetINITTABLE            ( U32 ModuleIndex, U32 HASH_IV0,
										U32 HASH_IV1, U32 HASH_IV2, U32 HASH_IV3, U32 HASH_IV4 );

void NX_CRYPTO_SetHASHDMAPath          ( U32 ModuleIndex, U32 Mode );// DMA Path
void NX_CRYPTO_SetHASHInputSwap        ( U32 ModuleIndex, CBOOL Enb ); // Input Swap
void NX_CRYPTO_SetHASHMode             ( U32 ModuleIndex, U32 Mode ); // 0:SHA1, 1:MD5
void NX_CRYPTO_SetHASHCont             ( U32 ModuleIndex, U32 Mode ); // HASH Cont
void NX_CRYPTO_SetDMAMode              ( U32 ModuleIndex, U32 Mode ); // DMA Mode->0:FIFO mode, 1:DMA mode
void NX_CRYPTO_SetHASHEnable           ( U32 ModuleIndex, U32 Mode );

void NX_CRYPTO_GetHASHTextOut( U32 ModuleIndex,
	U32 *HASH_TOUT0, U32 *HASH_TOUT1, U32 *HASH_TOUT2, U32 *HASH_TOUT3, U32 *HASH_TOUT4 );

void NX_CRYPTO_SetAES64bitCounter( U32 ModuleIndex, U32 Mode ); // 64bit counter
void	NX_CRYPTO_SetHASHTextIn			( U32 ModuleIndex, U32 HASH_TIN ) ;
CBOOL NX_CRYPTO_GetIdleHASHCore( U32 ModuleIndex );

//@}

//=================
// Register R/W Test Function
// prototype 으로 제공한다.
//=================
CBOOL NX_CRYPTO_RegTest( U32 ModuleIndex );
CBOOL NX_CRYPTO_CheckReg( U32 Addr, U32 initvalue, U32 writevalue, char *RegName);

CBOOL NX_CRYPTO_RegTest_ECO_20130129( U32 ModuleIndex );

//////////////////////
// added by yjkim 2016.02.17
// TRNG Functions
//////////////////////
U32 NX_CRYPTO_TRNG_GetRandomNumber( U32 ModuleIndex, U32 *regval );
U32 NX_CRYPTO_TRNG_CheckBusy( U32 ModuelIndex );
CBOOL NX_CRYPTO_TRNG_SetInterruptClear( U32 ModuleIndex, U32 source );
CBOOL NX_CRYPTO_TRNG_SetInterruptEnable( U32 ModuleIndex, U32 source );
CBOOL NX_CRYPTO_TRNG_SetInterruptDisable( U32 ModuleIndex, U32 source );

CBOOL NX_CRYPTO_TRNG_SetStart( U32 ModuleIndex, U32 mode );
CBOOL NX_CRYPTO_TRNG_SetStop( U32 ModuleIndex );

CBOOL NX_CRYPTO_TRNG_SetOscillator( U32 ModuleIndex, U32 select );
CBOOL NX_CRYPTO_TRNG_SetOscillatorChainSelect( U32 ModuleIndex, U32 trng_sel,
		U32 sel0_reg, U32 sel1_reg, U32 sel2_reg, U32 sel3_reg, U32 sel4_reg );
CBOOL NX_CRYPTO_TRNG_SetWhiteningEnalbe( U32 ModuleIndex, U32 whitening );
CBOOL NX_CRYPTO_TRNG_SetHealthTest( U32 ModuleIndex, U32 repeat_cutoff, U32 prop_cutoff, U32 prop_max_count );
CBOOL NX_CRYPTO_TRNG_GetHealthTest( U32 ModuleIndex, U32 *repeat_cutoff, U32 *prop_cutoff, U32 *prop_max_count );
CBOOL NX_CRYPTO_TRNG_SetTesterMinMax( U32 ModuleIndex, U32 Min, U32 Max );
CBOOL NX_CRYPTO_TRNG_GetTesterMinMax( U32 ModuleIndex, U32 *Min, U32 *Max );
CBOOL NX_CRPYTO_TRNG_SetTesterControl( U32 ModuleIndex, U32 d, U32 Nd, U32 Ed );
CBOOL NX_CRPYTO_TRNG_GetTesterControl( U32 ModuleIndex, U32 *d, U32 *Nd, U32 *Ed );
CBOOL NX_CRYPTO_TRNG_SetInternalClear( U32 ModuleIndex, U32 type );
U32 NX_CRYPTO_TRNG_GetRepeatCount( U32 ModuleIndex, U32 *regval );
U32 NX_CRYPTO_TRNG_GetOneCount( U32 ModuleIndex, U32 *regval );
U32 NX_CRYPTO_TRNG_GetZeroCount( U32 ModuleIndex, U32 *regval );
U32 NX_CRYPTO_TRNG_GetTesterResultCount( U32 ModuleIndex, U32 *regval );
U32 NX_CRYPTO_TRNG_GetFIFOEmpty( U32 ModuleIndex, U32 *regval );

void NX_CRYPTO_DRNG_GetRandomNumber( U32 ModuleIndex,
		U32 *OUT0, U32 *OUT1, U32 *OUT2, U32 *OUT3);
void NX_CRYPTO_TRNG_AES_SetStart( U32 ModuleIndex );

//@}

#ifdef	__cplusplus
}
#endif


#endif // __NX_CRYPTO_H__
