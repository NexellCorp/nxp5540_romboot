//------------------------------------------------------------------------------
//
//  Copyright (C) Nexell Co. 2012
//
//  This confidential and proprietary software may be used only as authorized by a
//  licensing agreement from Nexell Co.
//  The entire notice above must be reproduced on all authorized copies and copies
//  may only be made to the extent permitted by a licensing agreement from Nexell Co.
//
//  Module      : ECID
//  File        : nx_ecid.h
//  Description :
//  Author      : Sei
//  History     :
//------------------------------------------------------------------------------
#ifndef __NX_ECID_H__
#define __NX_ECID_H__

#include "nx_prototype.h"

#ifdef  __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @defgroup   ECID
//------------------------------------------------------------------------------
//@{

    /// @brief ECID Module's Register List
    struct  NX_ECID_RegisterSet
    {
        volatile U32 ECID[4];           ///< 0x00  ~ 0x0C   : 128bit ECID Register
        volatile U8  CHIPNAME[48];      ///< 0x10  ~ 0x3C   : Chip Name Register
        volatile U32 RESERVED0;         ///< 0x40           : Reserved Region
        volatile U32 GUID0;             ///< 0x44           : GUID 0 Register
        volatile U16 GUID1;             ///< 0x48           : GUID 1 Register
        volatile U16 GUID2;             ///< 0x4A           : GUID 2 Register
        volatile U8  GUID3[8];          ///< 0x4C  ~ 0x50   : GUID 3-0 ~ 3-7 Register
        volatile U32 EC[3];             ///< 0x54  ~ 0x5C   : EC 0 ~ 2 Register
        volatile U32 BLOWCON;           ///< 0x60           : Blowing Control
        volatile U32 BLOWCFG0;          ///< 0x64           : CLK, BIT Cycle
        volatile U32 BLOWCFG1;          ///< 0x68           : FSR, PRW Cycle
        volatile U32 RESERVED1;         ///< 0x6C           : sense re-start
        volatile U32 BLOWDATA[4];       ///< 0x70  ~ 0x7C   : 128bit blow data
        volatile U32 SJTAG[4];          ///< 0x80  ~ 0x8C   : 128bit SJTAG Register
        volatile U32 BJTAG[4];          ///< 0x90  ~ 0x9C   : 128bit BJTAG Register
        volatile U32 RSTCFG;            ///< 0xA0           : 32bit Reset Config Register
        volatile U32 RESERVED3[3];      ///< 0xA4  ~ 0xAC   : Reserved Region
        volatile U32 SBOOTCFG;          ///< 0xB0           : Secure Key Configuration
        volatile U32 RESERVED4[3];      ///< 0xB4  ~ 0xBC   : Reserved Region
        volatile U32 SBOOTKEY[8];       ///< 0xC0  ~ 0xDC   : Compare Secure Key
        volatile U32 SECCFG[4];         ///< 0xE0  ~ 0xEC   : Secure User Efuse
        volatile U32 RESERVED5[(0x300-0xF0)/4];     ///< 0xF0  ~ 0x2FC  : Reserved Region
        volatile U32 CRAESKEY[4];       ///< 0x300 ~ 0x30C  : Cyrpto Aes Key
    };

    /// @brief ECID Module's GUID Format
    typedef struct {
        U32 GUID0;
        U16 GUID1;
        U16 GUID2;
        U8  GUID3[8];
    } NX_GUID;

    //--------------------------------------------------------------------------
    enum CS {
        CS_DISABLE = 0,
        CS_ENABLE  = 1
    };

    enum SIGDEV {
        SIGDEV_DISABLE = 0,
        SIGDEV_ENABLE  = 1
    };

    enum FSET {
        FSET_DISABLE = 0,
        FSET_ENABLE  = 1
    };

    enum PRCHG {
        PRCHG_DISABLE = 0,
        PRCHG_ENABLE  = 1
    };

    enum ECID_CPUIF_SEL {
        ECID_NSC_CPUIF   = 0,       // non-secure cpu interface
        ECID_SEC_CPUIF   = 1        // secure cpu interface
    };


//------------------------------------------------------------------------------
/// @name   Module Interface
//@{
CBOOL   NX_ECID_Initialize( void );
U32     NX_ECID_GetNumberOfModule( void );
//@}

//------------------------------------------------------------------------------
/// @name   Basic Interface
//@{
U32     NX_ECID_GetPhysicalAddress( void );
U32     NX_ECID_GetSecurePhysicalAddress( void );
U32     NX_ECID_GetSizeOfRegisterSet( void );
void    NX_ECID_SetBaseAddress( U32 BaseAddress );
void	NX_ECID_SetSecureBaseAddress( U32 BaseAddress );
U32     NX_ECID_GetBaseAddress( void );
U32		NX_ECID_GetSecureBaseAddress( void );
CBOOL   NX_ECID_OpenModule( void );
CBOOL   NX_ECID_CloseModule( void );
CBOOL   NX_ECID_CheckBusy( void );
CBOOL   NX_ECID_CanPowerDown( void );
//@}

//------------------------------------------------------------------------------
/// @name Clock Control Interface
//U32     NX_ECID_GetClockNumber( void );
//U32     NX_ECID_GetResetNumber( void );

//------------------------------------------------------------------------------
/// @name   Module Interface
//@{

void    NX_ECID_GetECID( U32 ECID[4] );
void    NX_ECID_GetSJTAG( U32 SJTAG[4] );
void    NX_ECID_GetBJTAG( U32 BJTAG[4] );
void    NX_ECID_GetSECCFG( U32 SECCFG[4] );
//void    NX_ECID_GetSJTAG( U32 BJTAG[4] );
void    NX_ECID_GetChipName( U8 ChipName[64] );
void    NX_ECID_GetGUID( NX_GUID *guid );
U32     NX_ECID_GetRSTCFG( void );


//void    NX_ECID_SetA( U32 Addr );
//U32     NX_ECID_GetA( void );
//void    NX_ECID_SetCS( CBOOL Enable );
//CBOOL   NX_ECID_GetCS( void );
//void    NX_ECID_SetSIGDEV( CBOOL Enable );
//CBOOL   NX_ECID_GetSIGDEV( void );
//void    NX_ECID_SetFSET( CBOOL Enable );
//CBOOL   NX_ECID_GetFSET( void );
//void    NX_ECID_SetPRCHG( CBOOL Enable );
//CBOOL   NX_ECID_GetPRCHG( void );
U32     NX_ECID_GetBondingID( void );

//void    NX_ECID_SetPROG( CBOOL Enable );
//CBOOL   NX_ECID_GetPROG( void );
//void    NX_ECID_SetSCK( CBOOL Enable );
//CBOOL   NX_ECID_GetSCK( void );
//void    NX_ECID_SetSDI( CBOOL Enable );
//CBOOL   NX_ECID_GetSDI( void );

CBOOL   NX_ECID_GetKeyReady( void );
void    NX_ECID_SetHdcpEfuseSel( CBOOL Enable );
CBOOL   NX_ECID_GetHdcpEfuseSel( void );
void    NX_ECID_SetSelectFlowingBank( U32 Sel );
U32     NX_ECID_GetSelectFlowingBank( void );

//void    NX_ECID_SetBONDINGID( CBOOL set_cs, CBOOL set_sigdev, CBOOL set_fset, CBOOL set_prchg);
U32     NX_ECID_GetBONDINGID ( void );

void    NX_ECID_SetBlowInit( void );
CBOOL   NX_ECID_GetBlowInitDone( void );
void    NX_ECID_SetBlowStart( void );
CBOOL   NX_ECID_GetBlowDone( void );

void    NX_ECID_SetBitCycle( U8 cycle );
U32     NX_ECID_GetBitCycle( void );
void    NX_ECID_SetClkCycle( U8 cycle );
U32     NX_ECID_GetClkCycle( void );
void    NX_ECID_SetPrwCycle( U16 cycle );
U32     NX_ECID_GetPrwCycle( void );
void    NX_ECID_SetFsrCycle( U16 cycle );
U32     NX_ECID_GetFsrCycle( void );

void    NX_ECID_SetBlowData( const U32 BlowData[4] );
void    NX_ECID_GetBlowData( U32 BlowData[4] );

void    NX_ECID_SetSenseInit( void );

void    NX_ECID_SetSelectCompSBOOT( U32 selVal );
U32     NX_ECID_GetSelectCompSBOOT( void );
U32     NX_ECID_GetCompResultSBOOT( void );
void    NX_ECID_SetCompSBOOT( const U32 secKey[8] );
void    NX_ECID_SetCRAESKEY( const U32 secKey[4] );
//@}

#ifdef  __cplusplus
}
#endif


#endif // __NX_ECID_H__
