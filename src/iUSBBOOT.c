////////////////////////////////////////////////////////////////////////////////
//
//	Copyright (C) 2009 Nexell Co. All Rights Reserved
//	Nexell Co. Proprietary & Confidential
//
//	Nexell informs that this code and information is provided "as is" base
//	and without warranty of any kind, either expressed or implied, including
//	but not limited to the implied warranties of merchantability and/or fitness
//	for a particular puporse.
//
//
//	Module		:
//	File		:
//	Description	:
//	Author		: Hans
//	History		: 2010.08.03
//				Hans 2016.08.29 modify for nxp5540
//				Hans 2013.08.24 phy power off add when disconnected
//				Hans 2013.01.10 create
//
////////////////////////////////////////////////////////////////////////////////

#include <nx_etacarinae.h>
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include <nx_debug2.h>


#include <nx_usb20otg.h>
#include <iUSBBOOT.h>
#include "nx_etacarinae_bootheader.h"

#ifdef NXP5430
#include <nx_chip.h>
#include <nx_tieoff.h>
#endif

#ifdef NXP5540
#include <nx_tieoff_usb20otg.h>
#include "nx_resetcontrol_def.h"
#include "nx_clockcontrol_def.h"
#include "cpuif_regmap_framework.h"
#include "nx_chip_sfr.h"
#endif

#include <nx_ecid.h>

#include "libarm.h"
#include "libplat.h"
#include "printf.h"

#ifdef NXP5430
static struct NX_TIEOFF_RegisterSet * const pTieoffreg =
	(struct NX_TIEOFF_RegisterSet *)PHY_BASEADDR_TIEOFF_MODULE;
static struct NX_USB_OTG_RegisterSet * const pUOReg =
	(struct NX_USB_OTG_RegisterSet *)PHY_BASEADDR_USB20OTG_MODULE_AHBS0;
#endif
#ifdef NXP5540
static struct NX_TIEOFF_USB20OTG_RegisterSet * const pTieoffreg =
	(struct NX_TIEOFF_USB20OTG_RegisterSet *)PHY_BASEADDR_TIEOFF_OTG_MODULE;
static struct NX_USB_OTG_RegisterSet * const pUOReg =
	(struct NX_USB_OTG_RegisterSet *)PHY_BASEADDR_USB_OTG_LINK_A_MODULE;
#endif

static const U8 __attribute__ ((aligned(4)))
	gs_DeviceDescriptorFS[DEVICE_DESCRIPTOR_SIZE] =
{
	18,				//  0 desc size
	(U8)(DESCRIPTORTYPE_DEVICE),	//  1 desc type (DEVICE)
	(U8)(FULL_USB_VER % 0x100),	//  2 USB release
	(U8)(FULL_USB_VER / 0x100),	//  3 => 1.00
	0xFF,				//  4 class
	0xFF,				//  5 subclass
	0xFF,				//  6 protocol
	(U8)FULL_MAX_PKT_SIZE_EP0,	//  7 max pack size
	(U8)(VENDORID % 0x100),		//  8 vendor ID LSB
	(U8)(VENDORID / 0x100),		//  9 vendor ID MSB
	(U8)(PRODUCTID % 0x100),	// 10 product ID LSB (second product)
	(U8)(PRODUCTID / 0x100),	// 11 product ID MSB
	0x00,				// 12 device release LSB
	0x00,				// 13 device release MSB
	0x00,				// 14 manufacturer string desc index
	0x00,				// 15 product string desc index
	0x00,				// 16 serial num string desc index
	0x01				// 17 num of possible configurations
};

static const U8 __attribute__ ((aligned(4)))
	gs_DeviceDescriptorHS[DEVICE_DESCRIPTOR_SIZE] =
{
	18,				//  0 desc size
	(U8)(DESCRIPTORTYPE_DEVICE),	//  1 desc type (DEVICE)
	(U8)(HIGH_USB_VER % 0x100),	//  2 USB release
	(U8)(HIGH_USB_VER / 0x100),	//  3 => 1.00
	0xFF,				//  4 class
	0xFF,				//  5 subclass
	0xFF,				//  6 protocol
	(U8)HIGH_MAX_PKT_SIZE_EP0,	//  7 max pack size
	(U8)(VENDORID	% 0x100),	//  8 vendor ID LSB
	(U8)(VENDORID	/ 0x100),	//  9 vendor ID MSB
	(U8)(PRODUCTID % 0x100),	// 10 product ID LSB	(second product)
	(U8)(PRODUCTID / 0x100),	// 11 product ID MSB
	0x00,				// 12 device release LSB
	0x00,				// 13 device release MSB
	0x00,				// 14 manufacturer string desc index
	0x00,				// 15 product string desc index
	0x00,				// 16 serial num string desc index
	0x01				// 17 num of possible configurations
};


static const U8	__attribute__ ((aligned(4)))
	gs_ConfigDescriptorFS[CONFIG_DESCRIPTOR_SIZE] =
{
	//--------------------------------------------------------------------------
	// Configuration Descriptor
	0x09,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_CONFIGURATION),	// [ 1] desc type (CONFIGURATION)
	(U8)(CONFIG_DESCRIPTOR_SIZE % 0x100),	// [ 2] total length of data returned LSB
	(U8)(CONFIG_DESCRIPTOR_SIZE / 0x100),	// [ 3] total length of data returned MSB
	0x01,					// [ 4] num of interfaces
	0x01,					// [ 5] value to select config (1 for now)
	0x00,					// [ 6] index of string desc ( 0 for now)
	CONF_ATTR_DEFAULT|CONF_ATTR_SELFPOWERED,	// [ 7] bus powered
	25,					// [ 8] max power, 50mA for now

	//--------------------------------------------------------------------------
	// Interface Decriptor
	0x09,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_INTERFACE),		// [ 1] desc type (INTERFACE)
	0x00,					// [ 2] interface index.
	0x00,					// [ 3] value for alternate setting
	0x02,					// [ 4] bNumEndpoints (number endpoints used, excluding EP0)
	0xFF,					// [ 5]
	0xFF,					// [ 6]
	0xFF,					// [ 7]
	0x00,					// [ 8] string index,

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 1 Bulk IN)
	0x07,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_ENDPOINT),		// [ 1] desc type (ENDPOINT)
	BULK_IN_EP|EP_ADDR_IN,			// [ 2] endpoint address: endpoint 1, IN
	EP_ATTR_BULK,				// [ 3] endpoint attributes: Bulk
	(U8)(FULL_MAX_PKT_SIZE_EP1 % 0x100),	// [ 4] max packet size LSB
	(U8)(FULL_MAX_PKT_SIZE_EP1 / 0x100),	// [ 5] max packet size MSB
	0x00,					// [ 6] polling interval (4ms/bit=time,500ms)

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 2 Bulk OUT)
	0x07,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_ENDPOINT),		// [ 1] desc type (ENDPOINT)
	BULK_OUT_EP|EP_ADDR_OUT,		// [ 2] endpoint address: endpoint 2, OUT
	EP_ATTR_BULK,				// [ 3] endpoint attributes: Bulk
	(U8)(FULL_MAX_PKT_SIZE_EP2 % 0x100),	// [ 4] max packet size LSB
	(U8)(FULL_MAX_PKT_SIZE_EP2 / 0x100),	// [ 5] max packet size MSB
	0x00					// [ 6] polling interval (4ms/bit=time,500ms)
};

static const U8	__attribute__ ((aligned(4)))
	gs_ConfigDescriptorHS[CONFIG_DESCRIPTOR_SIZE] =
{
	//--------------------------------------------------------------------------
	// Configuration Descriptor
	0x09,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_CONFIGURATION),	// [ 1] desc type (CONFIGURATION)
	(U8)(CONFIG_DESCRIPTOR_SIZE % 0x100),	// [ 2] total length of data returned LSB
	(U8)(CONFIG_DESCRIPTOR_SIZE / 0x100),	// [ 3] total length of data returned MSB
	0x01,					// [ 4] num of interfaces
	0x01,					// [ 5] value to select config (1 for now)
	0x00,					// [ 6] index of string desc ( 0 for now)
	CONF_ATTR_DEFAULT|CONF_ATTR_SELFPOWERED,// [ 7] bus powered
	25,					// [ 8] max power, 50mA for now

	//--------------------------------------------------------------------------
	// Interface Decriptor
	0x09,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_INTERFACE),		// [ 1] desc type (INTERFACE)
	0x00,					// [ 2] interface index.
	0x00,					// [ 3] value for alternate setting
	0x02,					// [ 4] bNumEndpoints (number endpoints used, excluding EP0)
	0xFF,					// [ 5]
	0xFF,					// [ 6]
	0xFF,					// [ 7]
	0x00,					// [ 8] string index,

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 1 Bulk IN)
	0x07,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_ENDPOINT),		// [ 1] desc type (ENDPOINT)
	BULK_IN_EP|EP_ADDR_IN,			// [ 2] endpoint address: endpoint 1, IN
	EP_ATTR_BULK,				// [ 3] endpoint attributes: Bulk
	(U8)(HIGH_MAX_PKT_SIZE_EP1 % 0x100),	// [ 4] max packet size LSB
	(U8)(HIGH_MAX_PKT_SIZE_EP1 / 0x100),	// [ 5] max packet size MSB
	0x00,					// [ 6] polling interval (4ms/bit=time,500ms)

	//--------------------------------------------------------------------------
	// Endpoint descriptor (EP 2 Bulk OUT)
	0x07,					// [ 0] desc size
	(U8)(DESCRIPTORTYPE_ENDPOINT),		// [ 1] desc type (ENDPOINT)
	BULK_OUT_EP|EP_ADDR_OUT,		// [ 2] endpoint address: endpoint 2, OUT
	EP_ATTR_BULK,				// [ 3] endpoint attributes: Bulk
	(U8)(HIGH_MAX_PKT_SIZE_EP2 % 0x100),	// [ 4] max packet size LSB
	(U8)(HIGH_MAX_PKT_SIZE_EP2 / 0x100),	// [ 5] max packet size MSB
	0x00					// [ 6] polling interval (4ms/bit=time,500ms)
};

static void nx_usb_write_in_fifo(U32 ep, U8 *buf, S32 num)
{
	S32 i;
	U32* dwbuf = (U32*)buf;	/* assume all data ptr is 4 bytes aligned */
	for (i = 0; i < (num + 3) / 4; i++)
		pUOReg->EPFifo[ep][0] = dwbuf[i];
}

static void nx_usb_read_out_fifo(U32 ep, U8 *buf, S32 num)
{
	S32 i;
	U32* dwbuf = (U32*)buf;
	for (i = 0; i < (num + 3) / 4; i++)
		dwbuf[i] = pUOReg->EPFifo[ep][0];
}

static void nx_usb_ep0_int_hndlr(USBBOOTSTATUS *pUSBBootStatus)
{
	U32 buf[2];
	SetupPacket *pSetupPacket = (SetupPacket *)buf;
	U16 addr;

	NX_DEBUG_MSG("Event EP0\r\n");

	if (pUSBBootStatus->ep0_state != EP0_STATE_INIT) 
		goto noinit;

	buf[0] = pUOReg->EPFifo[CONTROL_EP][0];
	buf[1] = pUOReg->EPFifo[CONTROL_EP][0];

	NX_DEBUG_MSG("Req:");
	NX_DEBUG_BYTE(pSetupPacket->bmRequestType);
	NX_DEBUG_MSG(" ");
	NX_DEBUG_BYTE(pSetupPacket->bRequest);
	NX_DEBUG_MSG(" ");
	NX_DEBUG_WORD(pSetupPacket->wValue);
	NX_DEBUG_MSG(" ");
	NX_DEBUG_WORD(pSetupPacket->wIndex);
	NX_DEBUG_MSG(" ");
	NX_DEBUG_WORD(pSetupPacket->wLength);
	NX_DEBUG_MSG("\r\n");
	switch (pSetupPacket->bRequest) {
	case STANDARD_SET_ADDRESS:
		/* Set Address Update bit */
		NX_DEBUG_MSG("STANDARD_SET_ADDRESS:");
		addr = (pSetupPacket->wValue & 0xFF);
		NX_DEBUG_BYTE(addr);
		NX_DEBUG_MSG("\r\n");
		pUOReg->DCSR.DCFG =	1 << 18 |
					addr << 4 |
					pUSBBootStatus->speed << 0;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_SET_DESCRIPTOR:
		NX_DEBUG_MSG("STANDARD_SET_DESCRIPTOR\r\n");
		break;

	case STANDARD_SET_CONFIGURATION:
		NX_DEBUG_MSG("STANDARD_SET_CONFIGURATION\r\n");
		/* Configuration value in configuration descriptor */
		pUSBBootStatus->CurConfig = pSetupPacket->wValue;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_GET_CONFIGURATION:
		NX_DEBUG_MSG("STANDARD_GET_CONFIGURATION\r\n");
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) | (1 << 0);
		/*ep0 enable, clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL = EPEN_CNAK_EP0_8;
		pUOReg->EPFifo[CONTROL_EP][0] = pUSBBootStatus->CurConfig;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_GET_DESCRIPTOR:
		NX_DEBUG_MSG("STANDARD_GET_DESCRIPTOR :");
		pUSBBootStatus->Remain_size = (U32)pSetupPacket->wLength;
		switch (pSetupPacket->wValue>>8) {
		case DESCRIPTORTYPE_DEVICE:
			pUSBBootStatus->Current_ptr =
				(U8*)pUSBBootStatus->DeviceDescriptor;
			pUSBBootStatus->Current_Fifo_Size =
				pUSBBootStatus->ctrl_max_pktsize;
			if (pUSBBootStatus->Remain_size >
					DEVICE_DESCRIPTOR_SIZE)
				pUSBBootStatus->Remain_size =
					DEVICE_DESCRIPTOR_SIZE;
			pUSBBootStatus->ep0_state = EP0_STATE_GET_DSCPT;
			break;

		case DESCRIPTORTYPE_CONFIGURATION:
			pUSBBootStatus->Current_ptr =
				(U8*)pUSBBootStatus->ConfigDescriptor;
			pUSBBootStatus->Current_Fifo_Size =
				pUSBBootStatus->ctrl_max_pktsize;
			if (pUSBBootStatus->Remain_size >
					CONFIG_DESCRIPTOR_SIZE)
				pUSBBootStatus->Remain_size =
					CONFIG_DESCRIPTOR_SIZE;
			pUSBBootStatus->ep0_state = EP0_STATE_GET_DSCPT;
			break;

	//	case DESCRIPTORTYPE_STRING :
	//	case DESCRIPTORTYPE_INTERFACE:
	//	case DESCRIPTORTYPE_ENDPOINT:
		default:
			pUOReg->DCSR.DEPIR[0].DIEPCTL |= DEPCTL_STALL;
			break;
		}
		break;

	case STANDARD_CLEAR_FEATURE:
		NX_DEBUG_MSG("STANDARD_CLEAR_FEATURE :");
		break;

	case STANDARD_SET_FEATURE:
		NX_DEBUG_MSG("STANDARD_SET_FEATURE :");
		break;

	case STANDARD_GET_STATUS:
		NX_DEBUG_MSG("STANDARD_GET_STATUS :");
		pUSBBootStatus->ep0_state = EP0_STATE_GET_STATUS;
		break;

	case STANDARD_GET_INTERFACE:
		NX_DEBUG_MSG("STANDARD_GET_INTERFACE\r\n");
		pUSBBootStatus->ep0_state = EP0_STATE_GET_INTERFACE;
		break;

	case STANDARD_SET_INTERFACE:
		NX_DEBUG_MSG("STANDARD_SET_INTERFACE\r\n");
		pUSBBootStatus->CurInterface= pSetupPacket->wValue;
		pUSBBootStatus->CurSetting = pSetupPacket->wValue;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	case STANDARD_SYNCH_FRAME:
		NX_DEBUG_MSG("STANDARD_SYNCH_FRAME\r\n");
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	default:
		break;
	}

noinit:

	pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) |
			(pUSBBootStatus->ctrl_max_pktsize << 0);

	if (pUSBBootStatus->speed == USB_HIGH) {
		/*clear nak, next ep0, 64byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
				((1 << 26) |
			 (CONTROL_EP << 11) |
				 (0 << 0));
	} else {
		/*clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
				((1 << 26) |
			 (CONTROL_EP << 11) |
				 (3 << 0));
	}
}

static void nx_usb_transfer_ep0(USBBOOTSTATUS *pUSBBootStatus)
{
	switch (pUSBBootStatus->ep0_state) {
	case EP0_STATE_INIT:
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) | (0 << 0);
		/*ep0 enable, clear nak, next ep0, 8byte */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL = EPEN_CNAK_EP0_8;
		NX_DEBUG_MSG("EP0_STATE_INIT\r\n");
		break;

	/* GET_DESCRIPTOR:DEVICE */
	case EP0_STATE_GET_DSCPT:
		NX_DEBUG_MSG("EP0_STATE_GD_DEV_0 :");
		if (pUSBBootStatus->speed == USB_HIGH) {
			/*ep0 enable, clear nak, next ep0, max 64byte */
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
							EPEN_CNAK_EP0_64;
		} else {
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
							EPEN_CNAK_EP0_8;
		}
		if (pUSBBootStatus->Current_Fifo_Size >=
				pUSBBootStatus->Remain_size)
		{
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ =
				(1 << 19) |
				(pUSBBootStatus->Remain_size << 0);
			nx_usb_write_in_fifo(CONTROL_EP,
					pUSBBootStatus->Current_ptr,
					pUSBBootStatus->Remain_size);
			pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		} else {
			pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) |
				(pUSBBootStatus->Current_Fifo_Size << 0);
			nx_usb_write_in_fifo(CONTROL_EP,
					pUSBBootStatus->Current_ptr,
					pUSBBootStatus->Current_Fifo_Size);
			pUSBBootStatus->Remain_size -=
				pUSBBootStatus->Current_Fifo_Size;
			pUSBBootStatus->Current_ptr +=
				pUSBBootStatus->Current_Fifo_Size;
		}
		break;

	case EP0_STATE_GET_INTERFACE:
	case EP0_STATE_GET_CONFIG:
	case EP0_STATE_GET_STATUS:
		NX_DEBUG_MSG("EP0_STATE_INTERFACE_GET\r\n");
		NX_DEBUG_MSG("EP0_STATE_GET_STATUS\r\n");

		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPTSIZ = (1 << 19) | (1 << 0);
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL = EPEN_CNAK_EP0_8;

		if (pUSBBootStatus->ep0_state == EP0_STATE_GET_INTERFACE)
			pUOReg->EPFifo[CONTROL_EP][0] =
				pUSBBootStatus->CurInterface;
		else if(pUSBBootStatus->ep0_state == EP0_STATE_GET_CONFIG)
			pUOReg->EPFifo[CONTROL_EP][0] =
				pUSBBootStatus->CurConfig;
		else
			pUOReg->EPFifo[CONTROL_EP][0] = 0;
		pUSBBootStatus->ep0_state = EP0_STATE_INIT;
		break;

	default:
		break;
	}
}


static void nx_usb_int_bulkin(USBBOOTSTATUS *pUSBBootStatus)
{
	U8* bulkin_buf;
	U32 remain_cnt;

	NX_DEBUG_MSG("Bulk In Function\r\n");

	bulkin_buf = (U8*)pUSBBootStatus->up_ptr;
	remain_cnt = pUSBBootStatus->up_size -
			(pUSBBootStatus->up_ptr - pUSBBootStatus->up_addr);

	if (remain_cnt > pUSBBootStatus->bulkin_max_pktsize) {
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPTSIZ =
			(1 << 19) | (pUSBBootStatus->bulkin_max_pktsize << 0);

		/*ep1 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
			1u << 31| 1 << 26 | 2 << 18 | 1 << 15 |
			pUSBBootStatus->bulkin_max_pktsize << 0;

		nx_usb_write_in_fifo(BULK_IN_EP, bulkin_buf,
				pUSBBootStatus->bulkin_max_pktsize);

		pUSBBootStatus->up_ptr += pUSBBootStatus->bulkin_max_pktsize;

	} else if (remain_cnt > 0) {
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPTSIZ =
			(1 << 19) | (remain_cnt << 0);

		/*ep1 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
			1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
			pUSBBootStatus->bulkin_max_pktsize << 0;

		nx_usb_write_in_fifo(BULK_IN_EP, bulkin_buf, remain_cnt);

		pUSBBootStatus->up_ptr += remain_cnt;

	} else { /*remain_cnt = 0*/
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
					(DEPCTL_SNAK|DEPCTL_BULK_TYPE);
	}
}
static void nx_usb_int_bulkout(USBBOOTSTATUS *pUSBBootStatus,
				U32 fifo_cnt_byte, U32 option)
{
	if (CTRUE != pUSBBootStatus->bHeaderReceived) {
		U32 *pdwBuffer = (U32*)BASEADDR_SRAM;
		nx_usb_read_out_fifo(BULK_OUT_EP,
				(U8 *)&pdwBuffer[pUSBBootStatus->iRxHeaderSize / 4],
				fifo_cnt_byte);

		if ((fifo_cnt_byte & 3) == 0) {
			pUSBBootStatus->iRxHeaderSize += fifo_cnt_byte;
		} else {
			printf("Packet size align error:%d\r\n", fifo_cnt_byte);
			pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL |= DEPCTL_STALL;
		}

		if ((S32)sizeof(struct nx_bootheader) <=
				pUSBBootStatus->iRxHeaderSize) {
			struct nx_bootinfo *pSBI =
				(struct nx_bootinfo *)pdwBuffer;

			if (option & 1 << DECRYPT)
				Decrypt((U32*)pdwBuffer, (U32*)pdwBuffer,
						sizeof(struct nx_bootheader));

			if (pSBI->signature == HEADER_ID) {
				pUSBBootStatus->bHeaderReceived = CTRUE;
				pUSBBootStatus->RxBuffAddr =
					(U8*)pdwBuffer +
					pUSBBootStatus->iRxHeaderSize;
				pUSBBootStatus->RxBuffAddr_save	=
					(U8*)pdwBuffer +
					pUSBBootStatus->iRxHeaderSize;
				pUSBBootStatus->iRxSize = pSBI->LoadSize;

				if (pUSBBootStatus->iRxSize >
					(INTERNAL_SRAM_SIZE - SECONDBOOT_STACK))
					pUSBBootStatus->iRxSize =
						INTERNAL_SRAM_SIZE -
						SECONDBOOT_STACK;

				pUSBBootStatus->iRxSize_save =
					pUSBBootStatus->iRxSize;

				printf("USB Load Address = %x, %x\r\n",
						(MPTRS)pUSBBootStatus->RxBuffAddr,
						pUSBBootStatus->iRxSize);
			} else {
				pUSBBootStatus->iRxHeaderSize = 0;
				pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL |=
					DEPCTL_STALL;
			}
		}
	} else {
		NX_ASSERT((pUSBBootStatus->iRxSize) > 0);
		NX_ASSERT(0 == ((U32)pUSBBootStatus->RxBuffAddr & 3));
		nx_usb_read_out_fifo(BULK_OUT_EP,
				(U8 *)pUSBBootStatus->RxBuffAddr,
				fifo_cnt_byte);

#if (0)
		printf("Bin Packet Size = %x ==> %x, %x\r\n",
				iRxSize,
				pUSBBootStatus->RxBuffAddr,
				pUSBBootStatus->iRxSize);
#endif
		pUSBBootStatus->RxBuffAddr += fifo_cnt_byte;
		pUSBBootStatus->iRxSize	-= fifo_cnt_byte;

		if (pUSBBootStatus->iRxSize <= 0) {
			printf("Download completed!\r\n");

			pUSBBootStatus->bDownLoading	= CFALSE;
			pUSBBootStatus->bHeaderReceived = CFALSE;
		}
	}

	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPTSIZ =
		(1 << 19) | (pUSBBootStatus->bulkout_max_pktsize << 0);

	/*ep2 enable, clear nak, bulk, usb active, next ep2, max pkt 64*/
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL =
		1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkout_max_pktsize << 0;
}

static void nx_usb_reset(USBBOOTSTATUS *pUSBBootStatus)
{
	U32 i;
	/* set all out ep nak */
	for (i = 0; i < 16; i++)
		pUOReg->DCSR.DEPOR[i].DOEPCTL |= DEPCTL_SNAK;

	pUSBBootStatus->ep0_state = EP0_STATE_INIT;
	pUOReg->DCSR.DAINTMSK = ((1 << BULK_OUT_EP) |
				(1 << CONTROL_EP)) << 16 |
				((1 << BULK_IN_EP) |
				 (1 << CONTROL_EP));
	pUOReg->DCSR.DOEPMSK = CTRL_OUT_EP_SETUP_PHASE_DONE |
				AHB_ERROR |
				TRANSFER_DONE;
	pUOReg->DCSR.DIEPMSK = INTKN_TXFEMP |
				NON_ISO_IN_EP_TIMEOUT |
				AHB_ERROR |
				TRANSFER_DONE;

	/* Rx FIFO Size */
	pUOReg->GCSR.GRXFSIZ = RX_FIFO_SIZE;

	/* Non Periodic Tx FIFO Size */
	pUOReg->GCSR.GNPTXFSIZ = NPTX_FIFO_SIZE << 16 |
				NPTX_FIFO_START_ADDR << 0;

	/* clear all out ep nak */
	for (i = 0; i < 16; i++)
		pUOReg->DCSR.DEPOR[i].DOEPCTL |= (DEPCTL_EPENA|DEPCTL_CNAK);

	/*clear device address */
	pUOReg->DCSR.DCFG &= ~(0x7F << 4);
}

static S32 nx_usb_set_init(USBBOOTSTATUS *pUSBBootStatus)
{
	U32 status = pUOReg->DCSR.DSTS; /* System status read */

	pUSBBootStatus->bHeaderReceived = CFALSE;
	pUSBBootStatus->iRxHeaderSize = 0;

	/* Set if Device is High speed or Full speed */
	if (((status & 0x6) >> 1) == USB_HIGH) {
		pUSBBootStatus->speed = USB_HIGH;
		printf("High Speed Detection\r\n");
	} else if (((status & 0x6) >> 1) == USB_FULL) {
		pUSBBootStatus->speed = USB_FULL;
		printf("Full Speed Detection\r\n");
	} else {
		printf("**** Error:Neither High_Speed nor Full_Speed\r\n");
		return CFALSE;
	}

	/* set endpoint */
	/* Unmask NX_OTG_DAINT source */
	pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT = 0xFF;
	pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT = 0xFF;
	pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT = 0xFF;
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT = 0xFF;

	/* Init For Ep0*/
	if (pUSBBootStatus->speed == USB_HIGH) {
		pUSBBootStatus->ctrl_max_pktsize = HIGH_MAX_PKT_SIZE_EP0;
		pUSBBootStatus->bulkin_max_pktsize = HIGH_MAX_PKT_SIZE_EP1;
		pUSBBootStatus->bulkout_max_pktsize = HIGH_MAX_PKT_SIZE_EP2;
		pUSBBootStatus->DeviceDescriptor = gs_DeviceDescriptorHS;
		pUSBBootStatus->ConfigDescriptor = gs_ConfigDescriptorHS;

		/*MPS:64bytes */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (0 << 0));
		/*ep0 enable, clear nak */
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			(1u << 31) | (1 << 26) | (0 << 0);
	} else {
		pUSBBootStatus->ctrl_max_pktsize = FULL_MAX_PKT_SIZE_EP0;
		pUSBBootStatus->bulkin_max_pktsize = FULL_MAX_PKT_SIZE_EP1;
		pUSBBootStatus->bulkout_max_pktsize = FULL_MAX_PKT_SIZE_EP2;
		pUSBBootStatus->DeviceDescriptor = gs_DeviceDescriptorFS;
		pUSBBootStatus->ConfigDescriptor = gs_ConfigDescriptorFS;

		/*MPS:8bytes */
		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPCTL =
			((1 << 26) | (CONTROL_EP << 11) | (3 << 0));
		/*ep0 enable, clear nak */
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			(1u << 31) | (1 << 26) | (3 << 0);
	}

	/* set_opmode */
	pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP |INT_IN_EP |
		INT_ENUMDONE | INT_RESET | INT_SUSPEND | INT_RX_FIFO_NOT_EMPTY;

	pUOReg->GCSR.GAHBCFG = MODE_SLAVE|BURST_SINGLE|GBL_INT_UNMASK;

	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPTSIZ =
		(1 << 19) | (pUSBBootStatus->bulkout_max_pktsize << 0);

	pUOReg->DCSR.DEPOR[BULK_IN_EP].DOEPTSIZ = (1 << 19) | (0 << 0);

	/*bulk out ep enable, clear nak, bulk, usb active, next ep2, max pkt */
	pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPCTL =
		1u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkout_max_pktsize << 0;

	/*bulk in ep enable, clear nak, bulk, usb active, next ep1, max pkt */
	pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPCTL =
		0u << 31 | 1 << 26 | 2 << 18 | 1 << 15 |
		pUSBBootStatus->bulkin_max_pktsize << 0;

	return CTRUE;
}

static void nx_usb_pkt_receive(USBBOOTSTATUS *pUSBBootStatus, U32 option)
{
	U32 rx_status;
	U32 fifo_cnt_byte;

	rx_status = pUOReg->GCSR.GRXSTSP;

	if ((rx_status & (0xf << 17)) == SETUP_PKT_RECEIVED) {
		NX_DEBUG_MSG("SETUP_PKT_RECEIVED\r\n");
		nx_usb_ep0_int_hndlr(pUSBBootStatus);
	} else if ((rx_status & (0xf << 17)) == OUT_PKT_RECEIVED) {
		fifo_cnt_byte = (rx_status & 0x7ff0) >> 4;
		NX_DEBUG_MSG("OUT_PKT_RECEIVED\r\n");

		if ((rx_status & BULK_OUT_EP)&&(fifo_cnt_byte)) {
			nx_usb_int_bulkout(pUSBBootStatus,
					fifo_cnt_byte, option);
			pUOReg->GCSR.GINTMSK =
				INT_RESUME | INT_OUT_EP | INT_IN_EP |
				INT_ENUMDONE | INT_RESET | INT_SUSPEND |
				INT_RX_FIFO_NOT_EMPTY;
			return;
		}
	} else if ((rx_status & (0xf << 17)) == GLOBAL_OUT_NAK) {
		NX_DEBUG_MSG("GLOBAL_OUT_NAK\r\n");
	} else if ((rx_status & (0xf << 17)) == OUT_TRNASFER_COMPLETED) {
		NX_DEBUG_MSG("OUT_TRNASFER_COMPLETED\r\n");
	} else if ((rx_status & (0xf << 17)) == SETUP_TRANSACTION_COMPLETED) {
		NX_DEBUG_MSG("SETUP_TRANSACTION_COMPLETED\r\n");
	} else {
		NX_DEBUG_MSG("Reserved\r\n");
	}
}

static void nx_usb_transfer(USBBOOTSTATUS *pUSBBootStatus)
{
	U32 ep_int;
	U32 ep_int_status;

	ep_int = pUOReg->DCSR.DAINT;

	if (ep_int & (1 << CONTROL_EP)) {
		ep_int_status = pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT;

		if (ep_int_status & INTKN_TXFEMP) {

			while ((pUOReg->GCSR.GNPTXSTS & 0xFFFF) <
					pUSBBootStatus->ctrl_max_pktsize)
				;

			nx_usb_transfer_ep0(pUSBBootStatus);
		}

		pUOReg->DCSR.DEPIR[CONTROL_EP].DIEPINT = ep_int_status;
	}

	if (ep_int & ((1 << CONTROL_EP) << 16)) {
		ep_int_status = pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT;

		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPTSIZ =
				(1 << 29) | (1 << 19) | (8 << 0);
		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPCTL =
			1u << 31 | 1 << 26; /*ep0 enable, clear nak */

		pUOReg->DCSR.DEPOR[CONTROL_EP].DOEPINT =
			ep_int_status; /* Interrupt Clear */
	}

	if (ep_int & (1 << BULK_IN_EP)) {
		ep_int_status = pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT;
		/* Interrupt Clear */
		pUOReg->DCSR.DEPIR[BULK_IN_EP].DIEPINT = ep_int_status;

		if (ep_int_status & INTKN_TXFEMP)
			nx_usb_int_bulkin(pUSBBootStatus);
	}

	if (ep_int & ((1 << BULK_OUT_EP) << 16)) {
		ep_int_status = pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT;
		/* Interrupt Clear */
		pUOReg->DCSR.DEPOR[BULK_OUT_EP].DOEPINT = ep_int_status;
	}
}

static void nx_udc_int_hndlr(USBBOOTSTATUS *pUSBBootStatus, U32 option)
{
	U32 int_status;
	S32 tmp;

	int_status = pUOReg->GCSR.GINTSTS; /* Core Interrupt Register */

	if (int_status & INT_RESET) {
		NX_DEBUG_MSG("INT_RESET\r\n");

		nx_usb_reset(pUSBBootStatus);
	}

	if (int_status & INT_ENUMDONE) {
		NX_DEBUG_MSG("INT_ENUMDONE :");

		tmp = nx_usb_set_init(pUSBBootStatus);
		if (tmp == CFALSE) {
			pUOReg->GCSR.GINTSTS = int_status; /* Interrupt Clear */
			return;
		}
	}

	if (int_status & INT_RESUME) {
		NX_DEBUG_MSG("INT_RESUME\r\n");
	}

	if (int_status & INT_SUSPEND) {
		NX_DEBUG_MSG("INT_SUSPEND\r\n");
	}

	if (int_status & INT_RX_FIFO_NOT_EMPTY) {
		NX_DEBUG_MSG("INT_RX_FIFO_NOT_EMPTY\r\n");
		/* Read only register field */

		pUOReg->GCSR.GINTMSK =
			INT_RESUME | INT_OUT_EP | INT_IN_EP |
			INT_ENUMDONE | INT_RESET | INT_SUSPEND;
		nx_usb_pkt_receive(pUSBBootStatus, option);
		pUOReg->GCSR.GINTMSK =
			INT_RESUME | INT_OUT_EP | INT_IN_EP |
			INT_ENUMDONE | INT_RESET | INT_SUSPEND |
			INT_RX_FIFO_NOT_EMPTY;
	}

	if ((int_status & INT_IN_EP) || (int_status & INT_OUT_EP)) {
		NX_DEBUG_MSG("INT_IN or OUT_EP\r\n");
		/* Read only register field */

		nx_usb_transfer(pUSBBootStatus);
	}
	pUOReg->GCSR.GINTSTS = int_status; /* Interrupt Clear */
}
//#define SIM_TEST
void udelay(U32 utime)
{
	register volatile U32 i;
	for( ; utime>0 ; utime--)
#ifdef SIM_TEST
		for(i = 6; i > 0; i--);
#else
		for(i = 106; i > 0; i--);
#endif
}


extern struct NX_ECID_RegisterSet * const pECIDReg;
CBOOL iUSBBOOT(U32 option)
{
	USBBOOTSTATUS USBBootStatus, *pUSBBootStatus;
	__attribute__ ((aligned(4))) U8 updata[512];
	U32 i;
	U8 *ptr;
	U16 VID, PID;

	pUSBBootStatus = &USBBootStatus;
	ptr = (U8*)pUSBBootStatus;

	U32 ID = pECIDReg->ECID[3];
	if (ID == 0) {	// ECID is not burned
		VID = VENDORID;
		PID = PRODUCTID;
	} else {
		VID = (ID >> 16) & 0xFFFF;
		PID = (ID >>  0) & 0xFFFF;
	}
	printf("USB VID:%04X, PID:%04X\r\n", VID, PID);


	for(i = 0; i < sizeof(USBBOOTSTATUS); i++);
		ptr[i] = 0;
	for(i = 0; i < DEVICE_DESCRIPTOR_SIZE; i++) {
		pUSBBootStatus->HSDeviceDescriptor[i] = gs_DeviceDescriptorHS[i];
		pUSBBootStatus->FSDeviceDescriptor[i] = gs_DeviceDescriptorFS[i];
	}

	pUSBBootStatus->HSDeviceDescriptor[ 8] = (VID >> 0) & 0xFF;
	pUSBBootStatus->HSDeviceDescriptor[ 9] = (VID >> 8) & 0xFF;
	pUSBBootStatus->HSDeviceDescriptor[10] = (PID >> 0) & 0xFF;
	pUSBBootStatus->HSDeviceDescriptor[11] = (PID >> 8) & 0xFF;
	pUSBBootStatus->FSDeviceDescriptor[ 8] = (VID >> 0) & 0xFF;
	pUSBBootStatus->FSDeviceDescriptor[ 9] = (VID >> 8) & 0xFF;
	pUSBBootStatus->FSDeviceDescriptor[10] = (PID >> 0) & 0xFF;
	pUSBBootStatus->FSDeviceDescriptor[11] = (PID >> 8) & 0xFF;

	pUSBBootStatus->up_addr = updata;
	pUSBBootStatus->up_ptr = updata;
	pUSBBootStatus->up_size = 512;

	U32 *pdwupdata = (U32*)updata;
	pdwupdata[0] = pECIDReg->ECID[0];
	pdwupdata[1] = pECIDReg->ECID[1];
	pdwupdata[2] = pECIDReg->ECID[2];
	pdwupdata[3] = pECIDReg->ECID[3];
	for (i = 16; i < 512; i += 4)
		pdwupdata[i >> 2] = 0;

#ifdef NXP5430
	ResetCon(RESETINDEX_OF_USB20OTG_MODULE_i_nRST, CTRUE);  // reset on
	ResetCon(RESETINDEX_OF_USB20OTG_MODULE_i_nRST, CFALSE); // reset negate
#endif

#ifdef NXP5540
	// usb cmu clock enable
	nx_cpuif_reg_write_one(CMUI_USB_CMU_0_CLK_clk_enb, 1);
	// usb cmu reset release
	nx_cpuif_reg_write_one(RSTI_usb_cmu_0_rst, 1);

	/////////////////////////////////////
	// s/w stop and go 
	/////////////////////////////////////
	// USB all clock disable first 
	nx_cpuif_reg_write_one(CMUI_USB_0_AXI_clk_enb, 0);
	nx_cpuif_reg_write_one(CMUI_USB_0_AHB_clk_enb, 0);
	nx_cpuif_reg_write_one(CMUI_USB_0_APB_clk_enb, 0);
	nx_cpuif_reg_write_one(CMUI_OTG_SYS_0_AHB_clk_enb, 0);
	nx_cpuif_reg_write_one(CMUI_OTG_SYS_0_APB_clk_enb, 0);

	// USB all clock reset mode to 1
	nx_cpuif_reg_write_one(RSTM_usb_0_axi_rst, 1);
	nx_cpuif_reg_write_one(RSTM_usb_0_ahb_rst, 1);
	nx_cpuif_reg_write_one(RSTM_usb_0_apb_rst, 1);
	nx_cpuif_reg_write_one(RSTM_otg_sys_0_ahb_rst, 1);
	nx_cpuif_reg_write_one(RSTM_otg_sys_0_apb_rst, 1);

	// USB all reset release
	nx_cpuif_reg_write_one(RSTI_usb_0_axi_rst, 1);
	nx_cpuif_reg_write_one(RSTI_usb_0_ahb_rst, 1);
	nx_cpuif_reg_write_one(RSTI_usb_0_apb_rst, 1);
	nx_cpuif_reg_write_one(RSTI_otg_sys_0_ahb_rst, 1);
	nx_cpuif_reg_write_one(RSTI_otg_sys_0_apb_rst, 1);

	// last USB all clock enable
	nx_cpuif_reg_write_one(CMUI_USB_0_AXI_clk_enb, 1);
	nx_cpuif_reg_write_one(CMUI_USB_0_AHB_clk_enb, 1);
	nx_cpuif_reg_write_one(CMUI_USB_0_APB_clk_enb, 1);
	nx_cpuif_reg_write_one(CMUI_OTG_SYS_0_AHB_clk_enb, 1);
	nx_cpuif_reg_write_one(CMUI_OTG_SYS_0_APB_clk_enb, 1);

	/* 29: enable, 30:phy word interface (0: 8 bit, 1: 16 bit) */
	pTieoffreg->TIEOFFREG[2] |= 3 << 29;
	pTieoffreg->TIEOFFREG[1] &= ~(1 << 28);	// 28 : POR=0
	pTieoffreg->TIEOFFREG[1] |= 1 << 27;	// 27 : POR_ENB=1

	udelay(40);				// 40us delay need.

	pTieoffreg->TIEOFFREG[0] |= 1 << 8;	// 8 : i_nUtmiResetSync

	udelay(1);				// 10 clock need

	pTieoffreg->TIEOFFREG[0] |= 1 << 7;	// 7 : i_nResetSync 

	udelay(1);				// 10 clock need

#endif
#ifdef NXP5430
	pTieoffreg->TIEOFFREG[12] &= ~0x3;
	/* 29: enable, 30:phy word interface (0: 8 bit, 1: 16 bit) */
	pTieoffreg->TIEOFFREG[14] |= 0x3 << 8;
	pTieoffreg->TIEOFFREG[13] = 0xA3006C00;	// 5V VBUS, POR = 0
	pTieoffreg->TIEOFFREG[13] |= 1 << 7;	// 7 : POR_ENB=1

	udelay(40);				// 40us delay need.

	pTieoffreg->TIEOFFREG[13] |= 1 << 3;	// 3 : i_nUtmiResetSync

	udelay(1);				// 10 clock need

	pTieoffreg->TIEOFFREG[13] |= 1 << 2;	// 2 : i_nResetSync 

	udelay(1);				// 10 clock need
#endif
	/* usb core soft reset */
	pUOReg->GCSR.GRSTCTL = CORE_SOFT_RESET;
	while (!(pUOReg->GCSR.GRSTCTL & AHB_MASTER_IDLE))
		;

	/* init_core */
	pUOReg->GCSR.GAHBCFG = PTXFE_HALF | NPTXFE_HALF | MODE_SLAVE |
				BURST_SINGLE | GBL_INT_UNMASK;
	pUOReg->GCSR.GUSBCFG =
		  0 << 15	/* PHY Low Power Clock sel */
		| 1 << 14	/* Non-Periodic TxFIFO Rewind Enable */
		| 5 << 10	/* Turnaround time */
		| 0 << 9	/* 0:HNP disable, 1:HNP enable */
		| 0 << 8	/* 0:SRP disable, 1:SRP enable */
		| 0 << 7	/* ULPI DDR sel */
		| 0 << 6	/* 0: high speed utmi+, 1: full speed serial */
		| 0 << 4	/* 0: utmi+, 1:ulpi */
		| 1 << 3	/* phy i/f  0:8bit, 1:16bit */
		| 7 << 0;	/* HS/FS Timeout**/

	/* check current mode */
	if ((pUOReg->GCSR.GINTSTS & 0x1) == INT_DEV_MODE) {
		/* soft disconnect on */
		pUOReg->DCSR.DCTL |= SOFT_DISCONNECT;

		udelay(10);
		/* soft disconnect off */
		pUOReg->DCSR.DCTL &= ~SOFT_DISCONNECT;

		/* usb init device */
		pUOReg->DCSR.DCFG = 1 << 18;
		pUOReg->GCSR.GINTMSK = INT_RESUME | INT_OUT_EP | INT_IN_EP |
					INT_ENUMDONE | INT_RESET | INT_SUSPEND |
					INT_RX_FIFO_NOT_EMPTY;
	}

	pUSBBootStatus->CurConfig = 0;
	pUSBBootStatus->CurInterface = 0;
	pUSBBootStatus->CurSetting = 0;
	pUSBBootStatus->speed = USB_HIGH;
	pUSBBootStatus->ep0_state = EP0_STATE_INIT;

	printf("irom usb boot ready!\r\n");

	pUSBBootStatus->bDownLoading = CTRUE;
	while (pUSBBootStatus->bDownLoading) {
		if (pUOReg->GCSR.GINTSTS &
				(WkUpInt | OEPInt | IEPInt | EnumDone |
				 USBRst | USBSusp | RXFLvl)) {
			nx_udc_int_hndlr(pUSBBootStatus, option);
			pUOReg->GCSR.GINTSTS = 0xFFFFFFFF;
		}
	}
	/* usb core soft reset */
	pUOReg->GCSR.GRSTCTL = CORE_SOFT_RESET;
	while (!(pUOReg->GCSR.GRSTCTL & AHB_MASTER_IDLE))
		;

#ifdef NXP5540
	 /* reset Avalid, Bvalid, sessend */
	pUOReg->GCSR.GOTGCTL = 0x00;
#endif

	pTieoffreg->TIEOFFREG[0] &= ~(1 << 8);	// 8 : i_nUtmiResetSync
	pTieoffreg->TIEOFFREG[0] &= ~(1 << 7);	// 7 : i_nResetSync
	pTieoffreg->TIEOFFREG[1] |=   3 << 27;	// 27 : POR_ENB=1, 28 : POR=1

#ifdef NXP5430
	ResetCon(RESETINDEX_OF_USB20OTG_MODULE_i_nRST, CTRUE);  // reset on
#endif
#ifdef NXP5540
	nx_cpuif_reg_write_one(RSTI_otg_sys_0_ahb_rst, 0);   // usb otg ahb reset release
	nx_cpuif_reg_write_one(RSTI_otg_sys_0_apb_rst, 0);   // usb otg apb reset release
#endif

	if (option & 1 << DECRYPT)
		Decrypt((U32*)pUSBBootStatus->RxBuffAddr_save,
			(U32*)pUSBBootStatus->RxBuffAddr_save,
			pUSBBootStatus->iRxSize_save);

	return CTRUE;
}
