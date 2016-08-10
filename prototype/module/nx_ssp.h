#ifndef __NX_SSP_H__
#define __NX_SSP_H__

#include "../base/nx_prototype.h"

//#include <nx_rstcon.h>
//#include <nx_clkgen.h>


//==========================
// for configuration clock info 
//==========================
#include <nx_sysclkinfo.h> 


#ifdef	__cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup	SSP
//------------------------------------------------------------------------------
//@{
/// @brief	SSP Module's Register List
struct	NX_SSP_RegisterSet
{
	volatile U32	CH_CFG;			///< 0x00 :
	volatile U32	_Reserved0;		///< 0x04 :
	volatile U32	MODE_CFG;		///< 0x08 :
	volatile U32	CS_REG;			///< 0x0C : 
	volatile U32	SPI_INT_EN;		///< 0x10 : 
	volatile U32	SPI_STATUS;		///< 0x14 :
	volatile U32	SPI_TX_DATA;		///< 0x18 :
	volatile U32	SPI_RX_DATA;		///< 0x1C :
	volatile U32	PACKET_CNT_REG;		///< 0x20 :
	volatile U32	PENDING_CLR_REG;	///< 0x24 :
	volatile U32	SWAP_CFG;		///< 0x28 :
	volatile U32	FB_CLK_SEL;		///< 0x2C :
};

// PAD의 prototype 기술.
//typedef enum{
//	
//}

//------------------------------------------------------------------------------
/// @name	Module Interface
//@{
CBOOL	NX_SSP_Initialize		( void );
U32	NX_SSP_GetNumberOfModule	( void );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//@{
U32	NX_SSP_GetPhysicalAddress	( U32 ModuleIndex );
U32	NX_SSP_GetSizeOfRegisterSet	( void );
void	NX_SSP_SetBaseAddress		( U32 ModuleIndex, U32 BaseAddress );
U32	NX_SSP_GetBaseAddress		( U32 ModuleIndex );
CBOOL	NX_SSP_OpenModule		( U32 ModuleIndex );
CBOOL	NX_SSP_CloseModule		( U32 ModuleIndex );
CBOOL	NX_SSP_CheckBusy		( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Interrupt Interface
//@{

// Interrupt Channel ENUM
#ifndef __DEF__NX_SSP_INTR_MASK
#define __DEF__NX_SSP_INTR_MASK
typedef enum {
	TXFIFO_RDY  = 0,
	RXFIFO_RDY  = 1,
	TX_UNDERRUN = 2,
	TX_OVERRUN  = 3,
	RX_UNDERRUN = 4,
	RX_OVERRUN  = 5,
	TRAILING    = 6, // RX FIFO is not empty, but did not read for a while 
} NX_SSP_INTR_MASK;
#endif

#define  NX_SSP_INTR_MAXNUMBER   7

U32	NX_SSP_GetInterruptNumber	( U32 ModuleIndex );
void	NX_SSP_SetInterruptEnable	( U32 ModuleIndex, NX_SSP_INTR_MASK IntNum, CBOOL Enable );
CBOOL	NX_SSP_GetInterruptEnable	( U32 ModuleIndex, NX_SSP_INTR_MASK IntNum );
CBOOL	NX_SSP_GetInterruptPending	( U32 ModuleIndex, NX_SSP_INTR_MASK IntNum );
void	NX_SSP_ClearInterruptPending	( U32 ModuleIndex, NX_SSP_INTR_MASK IntNum );

void	NX_SSP_SetInterruptEnableAll	( U32 ModuleIndex, CBOOL Enable );
CBOOL	NX_SSP_GetInterruptEnableAll	( U32 ModuleIndex );
CBOOL	NX_SSP_GetInterruptPendingAll	( U32 ModuleIndex ); 
void	NX_SSP_ClearInterruptPendingAll	( U32 ModuleIndex );

NX_SSP_INTR_MASK	NX_SSP_GetInterruptPendingNumber( U32 ModuleIndex );	// -1 if None
//@}
//------------------------------------------------------------------------------
///	@name	SSP Pad Enable Function
//@{
void 	NX_SSP_EnablePAD		( U32 ModuleIndex ); // 해당 모듈에서 사용하는 모든 PAD를 enable 시킨다..

//------------------------------------------------------------------------------
///	@name	DMA Interface
//@{
U32		NX_SSP_GetDMAIndex_Tx( U32 ModuleIndex );
U32		NX_SSP_GetDMAIndex_Rx( U32 ModuleIndex );
U32		NX_SSP_GetDMABusWidth( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Clock Control Interface
//@{
// NK3 SPI has only 2x clock divider. 
// SCLK_SPI must be divided in System Controller for operation .
//@}

//--------------------------------------------------------------------------
/// @name Configuration Function
//--------------------------------------------------------------------------
//@{
// Transmit/ Receive 둘다 Enable.
void	NX_SSP_SetDMATransferMode( U32 ModuleIndex, CBOOL bDMA );
CBOOL	NX_SSP_GetDMATransferMode( U32 ModuleIndex );

void	NX_SSP_SetDMATransmitMode( U32 ModuleIndex, CBOOL bDMA );
CBOOL	NX_SSP_GetDMATransmitMode( U32 ModuleIndex );
void	NX_SSP_SetDMAReceiveMode( U32 ModuleIndex, CBOOL bDMA );
CBOOL	NX_SSP_GetDMAReceiveMode( U32 ModuleIndex );
void	NX_SSP_SetBitWidth( U32 ModuleIndex, U32 bitWidth );
U32		NX_SSP_GetBitWidth( U32 ModuleIndex );
void	NX_SSP_SetSlaveMode( U32 ModuleIndex, CBOOL bSlave );
CBOOL	NX_SSP_GetSlaveMode( U32 ModuleIndex );

void	NX_SSP_SetSlaveOutputEnable( U32 ModuleIndex, CBOOL Enable );
CBOOL	NX_SSP_GetSlaveOutputEnable( U32 ModuleIndex );

void	NX_SSP_SetClockPolarityInvert( U32 ModuleIndex, CBOOL bInvert );
CBOOL	NX_SSP_GetClockPolarityInvert( U32 ModuleIndex );

typedef enum
{
	NX_SSP_FORMAT_A	= 0,	///< Format A, SPH = 0
	NX_SSP_FORMAT_B	= 1		///< Format B, SPH = 1
}NX_SSP_FORMAT;

void	NX_SSP_SetSPIFormat( U32 ModuleIndex, NX_SSP_FORMAT format);
NX_SSP_FORMAT	NX_SSP_GetSPIFormat( U32 ModuleIndex );

void	NX_SSP_SetClockPhase( U32 ModuleIndex, U32	Phase );
U32	NX_SSP_GetClockPhase( U32 ModuleIndex );


/// @brief	Communication protocol
typedef enum
{
	NX_SSP_PROTOCOL_SPI	= 0,	///< SSP (Motorola Synchronous Serial Protocol)
	//NX_SSP_PROTOCOL_SSP	= 1,	///< SPI (TI Serial Peripheral Interface Protocol )
	NX_SSP_PROTOCOL_NM	= 2	///< National Microwire frame format )
} NX_SSP_PROTOCOL ;

void	NX_SSP_SetProtocol( U32 ModuleIndex, NX_SSP_PROTOCOL protocol );
NX_SSP_PROTOCOL	NX_SSP_GetProtocol( U32 ModuleIndex );

void	NX_SSP_SetByteSwap( U32 ModuleIndex, CBOOL bSwap );
CBOOL	NX_SSP_GetByteSwap( U32 ModuleIndex );

typedef enum
{
	NX_SSP_CS_MODE_AUTO = 1,
	NX_SSP_CS_MODE_MANUAL = 0,
} NX_SSP_CS_MODE ;
void	NX_SSP_SetCSMode( U32 ModuleIndex, NX_SSP_CS_MODE Mode ); 
//@}

//--------------------------------------------------------------------------
/// @name Operation Function
//--------------------------------------------------------------------------
//@{
void	NX_SSP_ResetFIFO( U32 ModuleIndex );

typedef enum {
	SINGLE = 0,
	BURST_4 = 1, 
} NX_SSP_DMABurstSize;

void	NX_SSP_SetDMABurstSize( U32 ModuleIndex , NX_SSP_DMABurstSize Mode );

void	NX_SSP_SetEnable( U32 ModuleIndex, CBOOL bEnable );
CBOOL	NX_SSP_GetEnable( U32 ModuleIndex );
U8	NX_SSP_GetByte(U32 ModuleIndex);
U16	NX_SSP_GetHalfWord(U32 ModuleIndex);
void	NX_SSP_PutByte(U32 ModuleIndex, U8 ByteData);
void	NX_SSP_PutHalfWord(U32 ModuleIndex, U16 HalfWordData);

//@}


//--------------------------------------------------------------------------
/// @name FIFO State Check Function
//--------------------------------------------------------------------------
//@{

//const static U32 NX_SSP_TX_FIFO_FULL_LVL[10] = { 256,256,256 };
//const static U32 NX_SSP_RX_FIFO_FULL_LVL[10] = { 256,256,256 };
const U32 NX_SSP_TX_FIFO_FULL_LVL[10] = { 256,256,256 };
const U32 NX_SSP_RX_FIFO_FULL_LVL[10] = { 256,256,256 };

CBOOL	NX_SSP_IsTxFIFOEmpty(U32 ModuleIndex);
CBOOL	NX_SSP_IsTxFIFOFull(U32 ModuleIndex);
CBOOL	NX_SSP_IsRxFIFOEmpty(U32 ModuleIndex);
CBOOL	NX_SSP_IsRxFIFOFull(U32 ModuleIndex);

CBOOL	NX_SSP_IsTxRxEnd( U32 ModuleIndex ); // CheckBusy로 대체.

U32	NX_SSP_GetTxFIFOLVL(U32 ModuleIndex);
U32	NX_SSP_GetRxFIFOLVL(U32 ModuleIndex);

// use for slave selection signal Active or Inactive

void	NX_SSP_SetNSSOUT( U32 ModuleIndex, U32 NSSOUT );




//================================
// NXP4330 function 
//================================
U32 NX_SSP_GetClockNumber (U32 ModuleIndex);
U32	NX_SSP_GetResetNumber (U32 ModuleIndex, U32 ChannelIndex);
enum {
	NX_SSP_PRESETn = 0,
};

//------------------------------------------------------------------------------
///	@	Set CMU Source & Divider
void NX_SSP_SetClockFreq( 	U32 spi_index, 
				double clock_freq, 
				struct NX_SystemClockInfo_Parameter  * p_sysclkinfo_param );
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
///	@name	Register Backup & Store Function
void 	NX_SSP_EnablePAD	( U32 ModuleIndex ); // 해당 모듈에서 사용하는 모든 PAD를 enable 시킨다..
//------------------------------------------------------------------------------


//=======================================
// in slave mode, can use HIGHSPEED mode(half TXD delay)
//=======================================
void  NX_SSP_SetHIGHSPEEDMode( U32 ModuleIndex, U32 Enb);


//=======================================
// TX_RDY_LVL, trigger level in INT mode
//=======================================
void  NX_SSP_SetRXRDYLVL( U32 ModuleIndex, U32 RX_RDY_LVL );
void  NX_SSP_SetTXRDYLVL( U32 ModuleIndex, U32 TX_RDY_LVL );

//=======================================
// feedback clock config. (for fast ssp mastermode)
//=======================================
enum {
	NX_SSP_FEEDBACK_BYPASS = 0,
	NX_SSP_FEEDBACK_90     = 1,
	NX_SSP_FEEDBACK_180    = 2,
	NX_SSP_FEEDBACK_270    = 3,
};
void  NX_SSP_SetFeedbackClock( U32 ModuleIndex, U32 Feedback_Config ); 


//@}

#ifdef	__cplusplus
}
#endif

#endif // __NX_SSP_H__



