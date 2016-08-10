#ifndef _NX_UART_H
#define _NX_UART_H

//------------------------------------------------------------------------------
//  includes
//------------------------------------------------------------------------------
#include "nx_prototype.h"

#ifdef	__cplusplus
extern "C"
{
#endif

/******************************************************************************/
/******************** REGISTER BIT MASKS **************************************/
/******************************************************************************/
/* For UCON_REG Register */
#define DISABLE_TRANSMIT		0x0
#define POLLING_MODE_TRANSMIT	0x1
#define DMA_MODE_TRANSMIT		0x2
#define DISABLE_RECIEVE			0x0
#define POLLING_MODE_RECIEVE	0x1
#define DMA_MODE_RECIEVE		0x2

/* UARTMIS Register */
#define UART_MODEM_RIMINT         0x01
#define UART_MODEM_CTSMINT        0x02
#define UART_MODEM_DCDMINT        0x04
#define UART_MODEM_DSRMINT        0x08
#define UART_MODEM_RXMINT         0x10
#define UART_MODEM_TXMINT         0x20
#define UART_MODEM_RTMINT         0x40
#define UART_MODEM_FEMINT         0x80
#define UART_MODEM_PEMINT         0x100
#define UART_MODEM_BEMINT         0x200
#define UART_MODEM_OEMINT         0x400

#ifndef PADINDEX_OF_UART0_nCTS
#define PADINDEX_OF_UART0_nCTS 0
#endif
#ifndef PADINDEX_OF_UART1_nCTS
#define PADINDEX_OF_UART1_nCTS 0
#endif
#ifndef PADINDEX_OF_UART2_nCTS
#define PADINDEX_OF_UART2_nCTS 0
#endif
#ifndef PADINDEX_OF_UART3_nCTS
#define PADINDEX_OF_UART3_nCTS 0
#endif
#ifndef PADINDEX_OF_UART4_nCTS
#define PADINDEX_OF_UART4_nCTS 0
#endif
#ifndef PADINDEX_OF_UART5_nCTS
#define PADINDEX_OF_UART5_nCTS 0
#endif
#ifndef PADINDEX_OF_UART6_nCTS
#define PADINDEX_OF_UART6_nCTS 0
#endif
#ifndef PADINDEX_OF_UART7_nCTS
#define PADINDEX_OF_UART7_nCTS 0
#endif
#ifndef PADINDEX_OF_UART8_nCTS
#define PADINDEX_OF_UART8_nCTS 0
#endif

#ifndef PADINDEX_OF_UART0_nRTS
#define PADINDEX_OF_UART0_nRTS 0
#endif
#ifndef PADINDEX_OF_UART1_nRTS
#define PADINDEX_OF_UART1_nRTS 0
#endif
#ifndef PADINDEX_OF_UART2_nRTS
#define PADINDEX_OF_UART2_nRTS 0
#endif
#ifndef PADINDEX_OF_UART3_nRTS
#define PADINDEX_OF_UART3_nRTS 0
#endif
#ifndef PADINDEX_OF_UART4_nRTS
#define PADINDEX_OF_UART4_nRTS 0
#endif
#ifndef PADINDEX_OF_UART5_nRTS
#define PADINDEX_OF_UART5_nRTS 0
#endif
#ifndef PADINDEX_OF_UART6_nRTS
#define PADINDEX_OF_UART6_nRTS 0
#endif
#ifndef PADINDEX_OF_UART7_nRTS
#define PADINDEX_OF_UART7_nRTS 0
#endif
#ifndef PADINDEX_OF_UART8_nRTS
#define PADINDEX_OF_UART8_nRTS 0
#endif

#ifndef PADINDEX_OF_UART0_nDCD
#define PADINDEX_OF_UART0_nDCD 0
#endif
#ifndef PADINDEX_OF_UART1_nDCD
#define PADINDEX_OF_UART1_nDCD 0
#endif
#ifndef PADINDEX_OF_UART2_nDCD
#define PADINDEX_OF_UART2_nDCD 0
#endif
#ifndef PADINDEX_OF_UART3_nDCD
#define PADINDEX_OF_UART3_nDCD 0
#endif
#ifndef PADINDEX_OF_UART4_nDCD
#define PADINDEX_OF_UART4_nDCD 0
#endif
#ifndef PADINDEX_OF_UART5_nDCD
#define PADINDEX_OF_UART5_nDCD 0
#endif
#ifndef PADINDEX_OF_UART6_nDCD
#define PADINDEX_OF_UART6_nDCD 0
#endif
#ifndef PADINDEX_OF_UART7_nDCD
#define PADINDEX_OF_UART7_nDCD 0
#endif
#ifndef PADINDEX_OF_UART8_nDCD
#define PADINDEX_OF_UART8_nDCD 0
#endif

#ifndef PADINDEX_OF_UART0_nDSR
#define PADINDEX_OF_UART0_nDSR 0
#endif
#ifndef PADINDEX_OF_UART1_nDSR
#define PADINDEX_OF_UART1_nDSR 0
#endif
#ifndef PADINDEX_OF_UART2_nDSR
#define PADINDEX_OF_UART2_nDSR 0
#endif
#ifndef PADINDEX_OF_UART3_nDSR
#define PADINDEX_OF_UART3_nDSR 0
#endif
#ifndef PADINDEX_OF_UART4_nDSR
#define PADINDEX_OF_UART4_nDSR 0
#endif
#ifndef PADINDEX_OF_UART5_nDSR
#define PADINDEX_OF_UART5_nDSR 0
#endif
#ifndef PADINDEX_OF_UART6_nDSR
#define PADINDEX_OF_UART6_nDSR 0
#endif
#ifndef PADINDEX_OF_UART7_nDSR
#define PADINDEX_OF_UART7_nDSR 0
#endif
#ifndef PADINDEX_OF_UART8_nDSR
#define PADINDEX_OF_UART8_nDSR 0
#endif

#ifndef PADINDEX_OF_UART0_nDTR
#define PADINDEX_OF_UART0_nDTR 0
#endif
#ifndef PADINDEX_OF_UART1_nDTR
#define PADINDEX_OF_UART1_nDTR 0
#endif
#ifndef PADINDEX_OF_UART2_nDTR
#define PADINDEX_OF_UART2_nDTR 0
#endif
#ifndef PADINDEX_OF_UART3_nDTR
#define PADINDEX_OF_UART3_nDTR 0
#endif
#ifndef PADINDEX_OF_UART4_nDTR
#define PADINDEX_OF_UART4_nDTR 0
#endif
#ifndef PADINDEX_OF_UART5_nDTR
#define PADINDEX_OF_UART5_nDTR 0
#endif
#ifndef PADINDEX_OF_UART6_nDTR
#define PADINDEX_OF_UART6_nDTR 0
#endif
#ifndef PADINDEX_OF_UART7_nDTR
#define PADINDEX_OF_UART7_nDTR 0
#endif
#ifndef PADINDEX_OF_UART8_nDTR
#define PADINDEX_OF_UART8_nDTR 0
#endif

#ifndef PADINDEX_OF_UART0_nRI
#define PADINDEX_OF_UART0_nRI  0
#endif
#ifndef PADINDEX_OF_UART1_nRI
#define PADINDEX_OF_UART1_nRI  0
#endif
#ifndef PADINDEX_OF_UART2_nRI
#define PADINDEX_OF_UART2_nRI  0
#endif
#ifndef PADINDEX_OF_UART3_nRI
#define PADINDEX_OF_UART3_nRI  0
#endif
#ifndef PADINDEX_OF_UART4_nRI
#define PADINDEX_OF_UART4_nRI  0
#endif
#ifndef PADINDEX_OF_UART5_nRI
#define PADINDEX_OF_UART5_nRI  0
#endif
#ifndef PADINDEX_OF_UART6_nRI
#define PADINDEX_OF_UART6_nRI  0
#endif
#ifndef PADINDEX_OF_UART7_nRI
#define PADINDEX_OF_UART7_nRI  0
#endif
#ifndef PADINDEX_OF_UART8_nRI
#define PADINDEX_OF_UART8_nRI  0
#endif

//------------------------------------------------------------------------------
/// @brief  UART register set structure
//------------------------------------------------------------------------------
struct NX_UART_RegisterSet
{

	volatile U32	LCON	;	// 0x00	// Line Control
	volatile U32	UCON	;	// 0x04	// Control
	volatile U32	FCON	;	// 0x08	// FIFO Control
	volatile U32	MCON	;	// 0x0C	// Modem Control
	volatile U32	USTATUS	;	// 0x10	// Tx/Rx Status
	volatile U32	ESTATUS	;	// 0x14	// Rx Error Status
	volatile U32	FSTATUS	;	// 0x18	// FIFO Status
	volatile U32	MSTATUS	;	// 0x1C	// Modem Status
	volatile U32	THR		;	// 0x20	// TransTHRmit Buffer
	volatile U32	RBR		;	// 0x24	// Recieve Buffer
	volatile U32	BRDR	;	// 0x28	// Baud Rate Driver
	volatile U32	FRACVAL	;	// 0x2C	// Driver Fractional Value
	volatile U32	INTP	;	// 0x30	// Instrrupt Pending
	volatile U32	INTSP	;	// 0x34	// Instrrupt Source
	volatile U32	INTM	;	// 0x38	// Instrrupt Mask
	volatile U32	VERSION ;	// 0x3C	// Version
};

//---------------- LCON enum ----------------//
typedef enum
{
	NX_UART_NORMAL_MODE_OPERATION	= 0UL<<6,
	NX_UART_INFRARED_TXRX_MODE		= 1UL<<6
}NX_UART_SIGNAL_MODE;

typedef enum
{
	NX_UART_NO_PARITY			= 0UL<<3,
	NX_UART_ODD_PARITY			= 4UL<<3,
	NX_UART_EVEN_PARITY			= 5UL<<3,
	NX_UART_PARITY_FORCED_1		= 6UL<<3,
	NX_UART_PARITY_FORCED_0		= 7UL<<3
}NX_UART_PARITY;

typedef enum
{
	NX_UART_ONE_STOP_BIT_PER_FRAME	= 0UL<<2,
	NX_UART_TWO_STOP_BIT_PER_FRAME	= 1UL<<2
}NX_UART_STOP_BIT;

typedef enum
{
	NX_UART_5BIT_DATA	= 0UL<<0,
	NX_UART_6BIT_DATA	= 1UL<<0,
	NX_UART_7BIT_DATA	= 2UL<<0,
	NX_UART_8BIT_DATA	= 3UL<<0
}NX_UART_DATA_BIT;

//---------------- UCON enum ----------------//
typedef enum
{
	NX_UART_TX_DMA_BURST_SIZE_1		= 0UL<<20,
	NX_UART_TX_DMA_BURST_SIZE_4		= 1UL<<20,
	NX_UART_TX_DMA_BURST_SIZE_8		= 2UL<<20
}NX_UART_TX_DMA_BURST_SIZE;

typedef enum
{
	NX_UART_RX_DMA_BURST_SIZE_1		= 0UL<<16,
	NX_UART_RX_DMA_BURST_SIZE_4		= 1UL<<16,
	NX_UART_RX_DMA_BURST_SIZE_8		= 2UL<<16,
	NX_UART_RX_DMA_BURST_SIZE_16	= 3UL<<16
}NX_UART_RX_DMA_BURST_SIZE;

typedef enum
{
	NX_UART_DISABLE_RX_TIMEOUT_WITH_EMPTY_RXFIFO	= 0UL<<11,
	NX_UART_ENABLE_RX_TIMEOUT_WITH_EMPTY_RXFIFO		= 1UL<<11
}NX_UART_RX_TIMEOUT_WITH_EMPTY_RXFIFO;

typedef enum
{
	NX_UART_DISABLE_SUSPENDING_RX_DMA_FSM		= 0UL<<10,
	NX_UART_ENABLE_SUSPENDING_RX_DMA_FSM		= 1UL<<10
}NX_UART_SUSPENDING_RX_DMA_FSM;

typedef enum
{
	NX_UART_TX_INTERRUPT_TYPE_PULSE		= 0UL<<9,
	NX_UART_TX_INTERRUPT_TYPE_LEVEL		= 1UL<<9
}NX_UART_TX_INTERRUPT_TYPE;

typedef enum
{
	NX_UART_RX_INTERRUPT_TYPE_PULSE		= 0UL<<8,
	NX_UART_RX_INTERRUPT_TYPE_LEVEL		= 1UL<<8
}NX_UART_RX_INTERRUPT_TYPE;

typedef enum
{
	NX_UART_RX_DISABLE_TIMEOUT_INTERRUPT	= 0UL<<7,
	NX_UART_RX_ENABLE_TIMEOUT_INTERRUPT		= 1UL<<7
}NX_UART_RX_TIMEOUT_INTERRUPT;

typedef enum
{
	NX_UART_NOT_GENERATE_RECIEVE_ERROR_STATUS_INTERRUPT		= 0UL<<6,
	NX_UART_GENERATE_RECIEVE_ERROR_STATUS_INTERRUPT			= 1UL<<6
}NX_UART_GENERATE_RECIEVE_ERROR_STATUS;

typedef enum
{
	NX_UART_ONE_WAY_OPERATION		= 0UL<<5,
	NX_UART_LOOP_BACK_MODE			= 1UL<<5
}NX_UART_LOOP_BACK;

typedef enum
{
	NX_UART_NORMAL_TRANSMIT		= 0UL<<4,
	NX_UART_SEND_BREAK_SIGNAL	= 1UL<<4
}NX_UART_TRANSMIT_CONTROL;

typedef enum
{
	NX_UART_DISABLE_TRANSMIT		= 0UL<<2,
	NX_UART_POLLING_MODE_TRANSMIT	= 1UL<<2,
	NX_UART_DMA_MODE_TRANSMIT		= 2UL<<2
}NX_UART_TRANSMIT_MODE;

typedef enum
{
	NX_UART_DISABLE_RECIEVE			= 0UL<<0,
	NX_UART_POLLING_MODE_RECIEVE	= 1UL<<0,
	NX_UART_DMA_MODE_RECIEVE		= 2UL<<0
}NX_UART_RECIEVE_MODE;

//---------------- FCON enum ----------------//
typedef enum
{
	NX_UART_TX_FIFO_TRIGGER_LEVEL_0		= 0UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_1		= 1UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_2		= 2UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_3		= 3UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_4		= 4UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_5		= 5UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_6		= 6UL<<8,
	NX_UART_TX_FIFO_TRIGGER_LEVEL_7		= 7UL<<8
}NX_UART_TX_FIFO_TRIGGER_LEVEL;

typedef enum
{
	NX_UART_RX_FIFO_TRIGGER_LEVEL_0		= 0UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_1		= 1UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_2		= 2UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_3		= 3UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_4		= 4UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_5		= 5UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_6		= 6UL<<4,
	NX_UART_RX_FIFO_TRIGGER_LEVEL_7		= 7UL<<4
}NX_UART_RX_FIFO_TRIGGER_LEVEL;

typedef enum
{
	NX_UART_TX_FIFO_RESET		= 1UL<<2
}NX_UART_TX_FIFO_CONTROL;

typedef enum
{
	NX_UART_RX_FIFO_RESET		= 1UL<<1
}NX_UART_RX_FIFO;

typedef enum
{
	NX_UART_FIFO_ENABLE		= 1UL<<0,
	NX_UART_FIFO_DISABLE	= 0UL<<0
}NX_UART_FIFO;

//---------------- MCON enum ----------------//
typedef enum
{
	NX_UART_RTS_TRIGGER_LEVEL_0		= 0UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_1		= 1UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_2		= 2UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_3		= 3UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_4		= 4UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_5		= 5UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_6		= 6UL<<5,
	NX_UART_RTS_TRIGGER_LEVEL_7		= 7UL<<5
}NX_UART_RTS_TRIGGER_LEVEL;

typedef enum
{
	NX_UART_AUTO_FLOW_CONTROL		= 1UL<<4
}NX_UART_AUTO_FLOW;

typedef enum
{
	NX_UART_MODEM_INTERRUPT_ENABLE	= 1UL<<3
}NX_UART_MODEM_INTERRUPT;

typedef enum
{
	NX_UART_REQUEST_TO_SEND_HIGH	= 0UL<<0,
	NX_UART_REQUEST_TO_SEND_LOW		= 1UL<<0
}NX_UART_REQUEST_TO_SEND;

//---------------- UINTPn enum ----------------//
typedef enum
{
	NX_UART_INT_RXD		= 1UL<<0,
	NX_UART_INT_ERROR	= 1UL<<1,
	NX_UART_INT_TXD		= 1UL<<2,
	NX_UART_INT_MODEM	= 1UL<<3
}NX_UART_INT;


//---------------- FSTATUS enum ----------------//
typedef enum
{
	NX_UART_RX_FIFO_COUNT	= 0xff<<0,
	NX_UART_RX_FIFO_FULL	= 0x1 <<8,
	NX_UART_RX_FIFO_ERROR	= 0x1 <<9,
	NX_UART_TX_FIFO_COUNT	= 0xff<<16,
	NX_UART_TX_FIFO_FULL	= 0x1 <<24
}NX_UART_TX_FIFO;


//------------------------------------------------------------------------------
/// @name	Module Interface
//@{
CBOOL	NX_UART_Initialize( void );
U32		NX_UART_GetNumberOfModule( void );
//@}

//------------------------------------------------------------------------------
///	@name	Basic Interface
//@{
U32		NX_UART_GetPhysicalAddress( U32 ModuleIndex );
U32		NX_UART_GetTieoffPhysicalAddress ( void );

//U32		NX_UART_GetResetNumber( U32 ModuleIndex, U32 ChannelIndex );
U32		NX_UART_GetNumberOfReset( void );
U32		NX_UART_GetSizeOfRegisterSet( void );
void	NX_UART_SetBaseAddress( U32 ModuleIndex, U32 BaseAddress );
U32		NX_UART_GetBaseAddress( U32 ModuleIndex );
CBOOL	NX_UART_OpenModule( U32 ModuleIndex );
CBOOL	NX_UART_CloseModule( U32 ModuleIndex );
CBOOL	NX_UART_CheckBusy( U32 ModuleIndex );
CBOOL	NX_UART_CanPowerDown( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	clock ,reset Interface
//------------------------------------------------------------------------------
//@{
//U32 NX_UART_GetClockNumber ( U32 ModuleIndex );
//U32 NX_UART_GetResetNumber ( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	Interrupt Interface
//@{
U32		NX_UART_GetInterruptNumber( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	DMA Interface
//@{
U32		NX_UART_GetDMAIndex_Tx( U32 ModuleIndex );
U32		NX_UART_GetDMAIndex_Rx( U32 ModuleIndex );
U32		NX_UART_GetDMABusWidth( U32 ModuleIndex );
//@}

//------------------------------------------------------------------------------
///	@name	UART Pad Enable Function
//@{
void NX_UART_EnablePAD( U32 ModuleIndex, U32 ModeIndex );
//@}

//--------------------------------------------------------------------------
/// @name	Configuration operations
//--------------------------------------------------------------------------
//@{
//void	NX_UART_Set( U32 ModuleIndex, CBOOL  );
//CBOOL	NX_UART_Get( U32 ModuleIndex );

void	NX_UART_SetTransmitMode( U32 ModuleIndex, U8 mode );
U8		NX_UART_GetTransmitMode( U32 ModuleIndex );

void	NX_UART_SetRecieveMode( U32 ModuleIndex, U8 mode );
U8		NX_UART_GetRecieveMode( U32 ModuleIndex );

CBOOL	NX_UART_GetTransmitterEmpty( U32 ModuleIndex );
CBOOL	NX_UART_GetTransmitBufferEmpty( U32 ModuleIndex );

U8		NX_UART_GetRxFIFOCount( U32 ModuleIndex );




//@}

//--------------------------------------------------------------------------
/// @name	Register handling
//--------------------------------------------------------------------------
//@{
void	NX_UART_SetLCON	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetLCON	( U32 ModuleIndex );

void	NX_UART_SetUCON	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetUCON	( U32 ModuleIndex );

void	NX_UART_SetFCON	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetFCON	( U32 ModuleIndex );

void	NX_UART_SetMCON	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetMCON	( U32 ModuleIndex );

void	NX_UART_SetUSTATUS	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetUSTATUS	( U32 ModuleIndex );

void	NX_UART_SetESTATUS	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetESTATUS	( U32 ModuleIndex );

void	NX_UART_SetFSTATUS	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetFSTATUS	( U32 ModuleIndex );

void	NX_UART_SetMSTATUS	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetMSTATUS	( U32 ModuleIndex );

void	NX_UART_SetTHR		( U32 ModuleIndex, U32 value );

void	NX_UART_SetRBR		( U32 ModuleIndex, U32 value );
U32		NX_UART_GetRBR		( U32 ModuleIndex );

void	NX_UART_SetBRDR	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetBRDR	( U32 ModuleIndex );

void	NX_UART_SetFRACVAL	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetFRACVAL	( U32 ModuleIndex );

void	NX_UART_SetINTP	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetINTP	( U32 ModuleIndex );

void	NX_UART_SetINTSP	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetINTSP	( U32 ModuleIndex );

void	NX_UART_SetINTM	( U32 ModuleIndex, U32 value );
U32		NX_UART_GetINTM	( U32 ModuleIndex );

U32		NX_UART_GetVERSION ( U32 ModuleIndex );
//@}

//--------------------------------------------------------------------------
/// @name	SIMIO
//--------------------------------------------------------------------------
void	Uart_Test_Exit( void );

//@}

#ifdef	__cplusplus
}
#endif

#endif // _NX_UART_H
