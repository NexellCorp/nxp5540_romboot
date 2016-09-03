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
 *	File            : libarm.h
 *	Description     :
 *	Author          : Hans
 *	History         : 2016.08.10 Hans create
 */
U32 getquotient(U32 dividend, U32 divisor);
U32 getremainder(U32 dividend, U32 divisor);

void delay(U32 us);

unsigned int iget_fcs(unsigned int fcs, unsigned int data);
unsigned int sget_fcs(unsigned int fcs, unsigned short data);
unsigned int get_fcs(unsigned int fcs, unsigned char data);

unsigned int GetCPUID(void);
void SetNS(CBOOL bEnable, U32 tmp);

#ifdef aarch32
void EnterLowLevel(unsigned int *SVCStart, unsigned int SPSR, unsigned int SCR);
unsigned int GetCurrentSMode(void);
void SetSCR(unsigned int rSCR);
unsigned int GetSCR(void);
#endif

#ifdef aarch64
unsigned int xget_fcs(unsigned int fcs, unsigned long data);
void EnterLowLevel(unsigned int *EL1Start, unsigned int rSPSR);
unsigned int GetSCR_EL3(void);
void SetSCR_EL3(unsigned int rSCR);
unsigned int GetSCR_EL3(void);
void SetSCR_EL3(unsigned int rSCR);
unsigned int GetESR_EL3(void);
U32 GetISR_EL1(void);
CBOOL GetSavedAArchMode(void);
unsigned int GetSMCCodeFromAArch32(void);
unsigned int GetSMCCodeFromAArch64(void);
void SetMAIR_EL3(U64 val);
void SetSCTLR_EL3(U64 val);
U64 GetSCTLR_EL3(void);
void SetTCR_EL3(U32 val);
U64 GetTCR_EL3(void);
void SetTTBR0_EL3(U64 TTB);
void InvalidateTLB_All(void);
void InvalidateIcache_All(void);
void SetBootOption(U64 option);
U64 GetBootOption(void);
void SendFunctionPTR(U64 ptr);
#endif
