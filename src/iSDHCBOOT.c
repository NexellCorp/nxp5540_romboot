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
//	History		: 2013.02.06 First implementation
//					2013.08.31 rev1 (port 0, 1, 2 selectable)
////////////////////////////////////////////////////////////////////////////////
#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include "nx_etacarinae_bootheader.h"
#include <nx_debug2.h>
#include "printf.h"


#include <nx_gpio.h>

#include <nx_sdmmc.h>

#include "iSDHCBOOT.h"

#ifdef NXP5540
#include "nx_resetcontrol_def.h"
#include "nx_clockcontrol_def.h"
#include "cpuif_regmap_framework.h"
#include "nx_chip_iomux.h"
#endif

#include "libarm.h"
#include "libplat.h"

#ifdef NXP5430
#include <nx_chip.h>
#include <nx_clkgen.h>

struct NX_CLKGEN_RegisterSet * const pgSDClkGenReg[3] =
{
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN18_MODULE,
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN19_MODULE,
	(struct NX_CLKGEN_RegisterSet *)PHY_BASEADDR_CLKGEN20_MODULE
};
U32 const SDResetNum[3] =
{
	RESETINDEX_OF_SDMMC0_MODULE_i_nRST,
	RESETINDEX_OF_SDMMC1_MODULE_i_nRST,
	RESETINDEX_OF_SDMMC2_MODULE_i_nRST
};
#endif

#ifdef NXP5540
static _nx_cpuif_sym_ cpuif[3][7] = {
	{
	CMUI_SDMMC_0_CORE_grp_clk_src,
	CMUI_SDMMC_0_CORE_dy_div_val,
	CMUI_SDMMC_0_CORE_dy_div_busy_st,
	CMUI_SDMMC_0_AXI_clk_enb,
	CMUI_SDMMC_0_CORE_clk_enb,
	RSTM_sdmmc_0_axi_rst,
	RSTI_sdmmc_0_axi_rst
	},
	{
	CMUI_SDMMC_1_CORE_grp_clk_src,
	CMUI_SDMMC_1_CORE_dy_div_val,
	CMUI_SDMMC_1_CORE_dy_div_busy_st,
	CMUI_SDMMC_1_AXI_clk_enb,
	CMUI_SDMMC_1_CORE_clk_enb,
	RSTM_sdmmc_1_axi_rst,
	RSTI_sdmmc_1_axi_rst
	},
	{
	CMUI_SDMMC_2_CORE_grp_clk_src,
	CMUI_SDMMC_2_CORE_dy_div_val,
	CMUI_SDMMC_2_CORE_dy_div_busy_st,
	CMUI_SDMMC_2_AXI_clk_enb,
	CMUI_SDMMC_2_CORE_clk_enb,
	RSTM_sdmmc_2_axi_rst,
	RSTI_sdmmc_2_axi_rst
	},
};
#endif
struct NX_SDMMC_RegisterSet * const pgSDXCReg[3] =
{
	(struct NX_SDMMC_RegisterSet *)PHY_BASEADDR_SDMMC0_MODULE,
	(struct NX_SDMMC_RegisterSet *)PHY_BASEADDR_SDMMC1_MODULE,
	(struct NX_SDMMC_RegisterSet *)PHY_BASEADDR_SDMMC2_MODULE
};

extern struct NX_GPIO_RegisterSet (* const pGPIOReg)[1];
//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SetClock(SDXCBOOTSTATUS *pSDXCBootStatus,
				CBOOL enb, U32 divider)
{
	volatile U32 timeout;
	U32 i = pSDXCBootStatus->SDPort;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[i];
#ifdef NXP5430
	register struct NX_CLKGEN_RegisterSet * const pSDClkGenReg =
					pgSDClkGenReg[i];
#endif


	#if defined(VERBOSE)
	NX_DEBUG_MSG("NX_SDMMC_SetClock : divider = ");
	NX_DEBUG_DEC(divider);
	NX_DEBUG_MSG("\n");
	#endif

	//--------------------------------------------------------------------------
	// 1. Confirm that no card is engaged in any transaction.
	//	If there's a transaction, wait until it has been finished.
//	while(NX_SDXC_IsDataTransferBusy())
//		;
//	while(NX_SDXC_IsCardDataBusy())
//		;

	#if defined(NX_DEBUG)
	if (pSDXCReg->STATUS & (NX_SDXC_STATUS_DATABUSY |
				NX_SDXC_STATUS_FSMBUSY)) {
		#if defined(NX_DEBUG)
		if (pSDXCReg->STATUS & NX_SDXC_STATUS_DATABUSY)
			NX_DEBUG_MSG("NX_SDMMC_SetClock : ERROR - Data is busy\n");

		if (pSDXCReg->STATUS & NX_SDXC_STATUS_FSMBUSY)
			NX_DEBUG_MSG("NX_SDMMC_SetClock : ERROR - Data Transfer is busy\n");
		#endif
		//return CFALSE;
		INFINTE_LOOP();
	}
	#endif

	//--------------------------------------------------------------------------
	// 2. Disable the output clock.
	// low power mode & clock disable
	pSDXCReg->CLKENA |= NX_SDXC_CLKENA_LOWPWR;
	pSDXCReg->CLKENA &= ~NX_SDXC_CLKENA_CLKENB;

#ifdef NXP5430
	pSDClkGenReg->CLKENB = NX_PCLKMODE_ALWAYS << 3 |
				NX_BCLKMODE_DYNAMIC << 0;
	pSDClkGenReg->CLKGEN[0] =
			(pSDClkGenReg->CLKGEN[0] & ~(0x7 << 2 | 0xFF << 5))
			| (SDXC_CLKSRC << 2)		// set clock source
			| ((divider - 1) << 5)		// set clock divisor
			| (0UL << 1);			// set clock invert
	pSDClkGenReg->CLKENB |= 0x1UL << 2;		// clock generation enable
	//--------------------------------------------------------------------------
	// 3. Program the clock divider as required.
	pSDXCReg->CLKDIV = (divider >> 1);	// 2*n divider (0 : bypass)
#endif

#ifdef NXP5540
	U32 regval;
	// sdmmc core clock source select
	nx_cpuif_reg_write_one(cpuif[i][0], SDXC_CLKSRC);
	// sdmmc core clock divider value
	nx_cpuif_reg_write_one(cpuif[i][1], (divider - 1));
	while (1 == nx_cpuif_reg_read_one(cpuif[i][2], &regval))
		;
	/////////////////////////////////////
	// s/w stop and go 
	/////////////////////////////////////
	// sdmmc bus clock disable
	nx_cpuif_reg_write_one(cpuif[i][3], 0);
	nx_cpuif_reg_write_one(cpuif[i][4], 0);

	// sdmmc reset mode
	nx_cpuif_reg_write_one(cpuif[i][5], 1);

	// sdmmc reset release
	nx_cpuif_reg_write_one(cpuif[i][6], 1);

	// sdmmc bus clock enable
	nx_cpuif_reg_write_one(cpuif[i][3], 1);
	nx_cpuif_reg_write_one(cpuif[i][4], 1);
#endif

	pSDXCReg->CLKENA &= ~NX_SDXC_CLKENA_LOWPWR;	// low power mode & clock disable


	//--------------------------------------------------------------------------
	// 4. Start a command with NX_SDXC_CMDFLAG_UPDATECLKONLY flag.
repeat_4 :
	pSDXCReg->CMD = 0 | NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_UPDATECLKONLY |
			NX_SDXC_CMDFLAG_STOPABORT;

	//--------------------------------------------------------------------------
	// 5. Wait until a update clock command is taken by the SDXC module.
	//	If a HLE is occurred, repeat 4.
	timeout = 0;
	while (pSDXCReg->CMD & NX_SDXC_CMDFLAG_STARTCMD) {
		if (++timeout > NX_SDMMC_TIMEOUT) {
			printf("TO to update clock.\r\n");
			INFINTE_LOOP();
			return CFALSE;
		}
	}

	if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HLE) {
		INFINTE_LOOP();
		pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_HLE;
		goto repeat_4;
	}

	if (CFALSE == enb)
		return CTRUE;

	//--------------------------------------------------------------------------
	// 6. Enable the output clock.
	pSDXCReg->CLKENA |= NX_SDXC_CLKENA_CLKENB;

	//--------------------------------------------------------------------------
	// 7. Start a command with NX_SDXC_CMDFLAG_UPDATECLKONLY flag.
repeat_7 :
	pSDXCReg->CMD = 0 | NX_SDXC_CMDFLAG_STARTCMD |
		NX_SDXC_CMDFLAG_UPDATECLKONLY |
		NX_SDXC_CMDFLAG_STOPABORT;

	//--------------------------------------------------------------------------
	// 8. Wait until a update clock command is taken by the SDXC module.
	//	If a HLE is occurred, repeat 7.
	timeout = 0;
	while (pSDXCReg->CMD & NX_SDXC_CMDFLAG_STARTCMD) {
		if (++timeout > NX_SDMMC_TIMEOUT) {
			printf("TO to update clock2.\r\n");
			INFINTE_LOOP();
			return CFALSE;
		}
	}

	if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HLE) {
		INFINTE_LOOP();
		pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_HLE;
		goto repeat_7;
	}

	return CTRUE;
}

//------------------------------------------------------------------------------
static U32 NX_SDMMC_SendCommandInternal(
		SDXCBOOTSTATUS *pSDXCBootStatus,
		NX_SDMMC_COMMAND *pCommand)
{
	U32		cmd, flag;
	U32		status = 0;
	volatile U32	timeout;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
				pgSDXCReg[pSDXCBootStatus->SDPort];

	NX_ASSERT(CNULL != pCommand);

	#ifdef VERBOSE
	NX_DEBUG_MSG("NX_SDMMC_SendCommandInternal : Command(");
	NX_DEBUG_HEX(pCommand->cmdidx);
	NX_DEBUG_MSG("h), Argument(");
	NX_DEBUG_HEX(pCommand->arg);
	NX_DEBUG_MSG("h)\n");
	#endif

	cmd	= pCommand->cmdidx & 0xFF;
	flag	= pCommand->flag;

	pSDXCReg->RINTSTS = 0xFFFFFFFF;

	//--------------------------------------------------------------------------
	// Send Command
	timeout = 0;
	do {
		pSDXCReg->RINTSTS	= NX_SDXC_RINTSTS_HLE;
		pSDXCReg->CMDARG	= pCommand->arg;
		pSDXCReg->CMD		= cmd | flag |
					NX_SDXC_CMDFLAG_USE_HOLD_REG;
		while (pSDXCReg->CMD & NX_SDXC_CMDFLAG_STARTCMD) {
			if (++timeout > NX_SDMMC_TIMEOUT) {
				printf("TO to send command.\r\n");
				status |= NX_SDMMC_STATUS_CMDBUSY;
				INFINTE_LOOP();
				goto End;
			}
		}
	} while (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HLE);

	//--------------------------------------------------------------------------
	// Wait until Command sent to card and got response from card.
	timeout = 0;
	while (1) {
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_CD)
			break;

		if (++timeout > NX_SDMMC_TIMEOUT) {
			printf("TO to wait cmd done.\r\n");
			status |= NX_SDMMC_STATUS_CMDTOUT;
			INFINTE_LOOP();
			goto End;
		}

		if ((flag & NX_SDXC_CMDFLAG_STOPABORT) &&
			(pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HTO)) {
			// You have to clear FIFO when HTO is occurred.
			// After that, SDXC module leaves in stopped state and takes next command.
			while (0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY)) {
				pSDXCReg->DATA;
			}
		}
	}

	// Check Response Error
	if (pSDXCReg->RINTSTS & (NX_SDXC_RINTSTS_RCRC |
				NX_SDXC_RINTSTS_RE |
				NX_SDXC_RINTSTS_RTO)) {
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_RCRC)
			status |= NX_SDMMC_STATUS_RESCRCFAIL;
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_RE)
			status |= NX_SDMMC_STATUS_RESERROR;
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_RTO)
			status |= NX_SDMMC_STATUS_RESTOUT;
	}

	if ((status == NX_SDMMC_STATUS_NOERROR) &&
		(flag & NX_SDXC_CMDFLAG_SHORTRSP)) {
		pCommand->response[0] = pSDXCReg->RESP0;
		if ((flag & NX_SDXC_CMDFLAG_LONGRSP) ==
				NX_SDXC_CMDFLAG_LONGRSP) {
			pCommand->response[1] = pSDXCReg->RESP1;
			pCommand->response[2] = pSDXCReg->RESP2;
			pCommand->response[3] = pSDXCReg->RESP3;
		}

		if (NX_SDMMC_RSPIDX_R1B == ((pCommand->cmdidx >> 8) & 0xFF)) {
			timeout = 0;
			do {
				if (++timeout > NX_SDMMC_TIMEOUT) {
					printf("TO to wait card data is ready.\r\n");
					status |= NX_SDMMC_STATUS_DATABUSY;
					INFINTE_LOOP();
					goto End;
				}
			} while (pSDXCReg->STATUS & NX_SDXC_STATUS_DATABUSY);
		}
	}

End:

	if (NX_SDMMC_STATUS_NOERROR != status) {
//		printf("err: cmd:%x, arg:%x => sts:%x, resp:%x\r\n",
//			pCommand->cmdidx, pCommand->arg,
//			status, pCommand->response[0]);
	}

	pCommand->status = status;

	return status;
}

//------------------------------------------------------------------------------
static U32 NX_SDMMC_SendStatus(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;

	cmd.cmdidx	= SEND_STATUS;
	cmd.arg		= pSDXCBootStatus->rca;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	status = NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd);

	#if defined(VERBOSE) && defined(NX_DEBUG) && (1)
	if (NX_SDMMC_STATUS_NOERROR == status)
		return status;

//	printf("err: cmd.resp:%x\r\n", cmd.response[0]);

	if (cmd.response[0] & (1UL << 31))
		NX_DEBUG_MSG("\t\t ERROR : OUT_OF_RANGE\n");
	if (cmd.response[0] & (1UL << 30))
		NX_DEBUG_MSG("\t\t ERROR : ADDRESS_ERROR\n");
	if (cmd.response[0] & (1UL << 29))
		NX_DEBUG_MSG("\t\t ERROR : BLOCK_LEN_ERROR\n");
	if (cmd.response[0] & (1UL << 28))
		NX_DEBUG_MSG("\t\t ERROR : ERASE_SEQ_ERROR\n");
	if (cmd.response[0] & (1UL << 27))
		NX_DEBUG_MSG("\t\t ERROR : ERASE_PARAM\n");
	if (cmd.response[0] & (1UL << 26))
		NX_DEBUG_MSG("\t\t ERROR : WP_VIOLATION\n");
	if (cmd.response[0] & (1UL << 24))
		NX_DEBUG_MSG("\t\t ERROR : LOCK_UNLOCK_FAILED\n");
	if (cmd.response[0] & (1UL << 23))
		NX_DEBUG_MSG("\t\t ERROR : COM_CRC_ERROR\n");
	if (cmd.response[0] & (1UL << 22))
		NX_DEBUG_MSG("\t\t ERROR : ILLEGAL_COMMAND\n");
	if (cmd.response[0] & (1UL << 21))
		NX_DEBUG_MSG("\t\t ERROR : CARD_ECC_FAILED\n");
	if (cmd.response[0] & (1UL << 20))
		NX_DEBUG_MSG("\t\t ERROR : Internal Card Controller ERROR\n");
	if (cmd.response[0] & (1UL << 19))
		NX_DEBUG_MSG("\t\t ERROR : General Error\n");
	if (cmd.response[0] & (1UL << 17))
		NX_DEBUG_MSG("\t\t ERROR : Deferred Response\n");
	if (cmd.response[0] & (1UL << 16))
		NX_DEBUG_MSG("\t\t ERROR : CID/CSD_OVERWRITE_ERROR\n");
	if (cmd.response[0] & (1UL << 15))
		NX_DEBUG_MSG("\t\t ERROR : WP_ERASE_SKIP\n");
	if (cmd.response[0] & (1UL << 3))
		NX_DEBUG_MSG("\t\t ERROR : AKE_SEQ_ERROR\n");

	switch ((cmd.response[0] >> 9) & 0xF) {
	case 0: NX_DEBUG_MSG("\t\t CURRENT_STATE : Idle\n");
		break;
	case 1: NX_DEBUG_MSG("\t\t CURRENT_STATE : Ready\n");
		break;
	case 2: NX_DEBUG_MSG("\t\t CURRENT_STATE : Identification\n");
		break;
	case 3: NX_DEBUG_MSG("\t\t CURRENT_STATE : Standby\n");
		break;
	case 4: NX_DEBUG_MSG("\t\t CURRENT_STATE : Transfer\n");
		break;
	case 5: NX_DEBUG_MSG("\t\t CURRENT_STATE : Data\n");
		break;
	case 6: NX_DEBUG_MSG("\t\t CURRENT_STATE : Receive\n");
		break;
	case 7: NX_DEBUG_MSG("\t\t CURRENT_STATE : Programming\n");
		break;
	case 8: NX_DEBUG_MSG("\t\t CURRENT_STATE : Disconnect\n");
		break;
	case 9: NX_DEBUG_MSG("\t\t CURRENT_STATE : Sleep\n");
		break;
	default: NX_DEBUG_MSG("\t\t CURRENT_STATE : Reserved\n");
		 break;
	}
	#endif

	return status;
}

//------------------------------------------------------------------------------
static U32 NX_SDMMC_SendCommand(SDXCBOOTSTATUS *pSDXCBootStatus,
				NX_SDMMC_COMMAND *pCommand)
{
	U32 status;

	status = NX_SDMMC_SendCommandInternal(pSDXCBootStatus, pCommand);
	if (NX_SDMMC_STATUS_NOERROR != status) {
		NX_SDMMC_SendStatus(pSDXCBootStatus);
	}

	return status;
}

//------------------------------------------------------------------------------
static U32 NX_SDMMC_SendAppCommand(SDXCBOOTSTATUS *pSDXCBootStatus,
				NX_SDMMC_COMMAND *pCommand)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;

	cmd.cmdidx	= APP_CMD;
	cmd.arg		= pSDXCBootStatus->rca;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	status = NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd);
	if (NX_SDMMC_STATUS_NOERROR == status) {
		NX_SDMMC_SendCommand(pSDXCBootStatus, pCommand);
	}

	return status;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_IdentifyCard(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	S32 timeout;
	U32 HCS, RCA;
	NX_SDMMC_CARDTYPE CardType = NX_SDMMC_CARDTYPE_UNKNOWN;
	NX_SDMMC_COMMAND cmd;
	struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	if (CFALSE == NX_SDMMC_SetClock(pSDXCBootStatus,
					CTRUE,
					SDXC_DIVIDER_400KHZ))
		return CFALSE;

	// Data Bus Width : 0(1-bit), 1(4-bit)
	pSDXCReg->CTYPE = 0;

	pSDXCBootStatus->rca = 0;

	//--------------------------------------------------------------------------
	//	Identify SD/MMC card
	//--------------------------------------------------------------------------
	// Go idle state
	cmd.cmdidx	= GO_IDLE_STATE;
	cmd.arg		= 0;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_SENDINIT |
			NX_SDXC_CMDFLAG_STOPABORT;

	NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);

	// Check SD Card Version
	cmd.cmdidx	= SEND_IF_COND;
	// argument = VHS : 2.7~3.6V and Check Pattern(0xAA)
	cmd.arg		= (1 << 8) | 0xAA;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	if (NX_SDMMC_STATUS_NOERROR ==
			NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd)) {
		// Ver 2.0 or later SD Memory Card
		if (cmd.response[0] != ((1 << 8) | 0xAA))
			return CFALSE;

		HCS = 1 << 30;
	} else {
		// voltage mismatch or Ver 1.X SD Memory Card or not SD Memory Card
		HCS = 0;
	}

	//--------------------------------------------------------------------------
	// voltage validation
	timeout = NX_SDMMC_TIMEOUT_IDENTIFY;

	cmd.cmdidx	= APP_CMD;
	cmd.arg		= pSDXCBootStatus->rca;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	if (NX_SDMMC_STATUS_NOERROR ==
			NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd)) {
		//----------------------------------------------------------------------
		// SD memory card
		#define FAST_BOOT	(1<<29)

		cmd.cmdidx	= SD_SEND_OP_COND;
		cmd.arg		= (HCS | FAST_BOOT | 0x00FC0000);	// 3.0 ~ 3.6V
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_SHORTRSP;

		if (NX_SDMMC_STATUS_NOERROR !=
				NX_SDMMC_SendCommandInternal(pSDXCBootStatus,
								&cmd)) {
			return CFALSE;
		}
		/* Wait until card has finished the power up routine */
		while (0==(cmd.response[0] & (1UL << 31))) {
			if (NX_SDMMC_STATUS_NOERROR !=
					NX_SDMMC_SendAppCommand(pSDXCBootStatus,
								&cmd)) {
				return CFALSE;
			}

			if (timeout-- <= 0) {
				printf("TO to wait power up for SD.\r\n");
				return CFALSE;
			}
		}

		printf("SD Card.\r\n");
#if 0
		NX_DEBUG_MSG("--> SD_SEND_OP_COND Response = 0x");
		NX_DEBUG_HEX(cmd.response[0]);
		NX_DEBUG_MSG("\n");
#endif

		CardType	= NX_SDMMC_CARDTYPE_SDMEM;
		RCA		= 0;
	} else {
		//----------------------------------------------------------------------
		// MMC memory card
		cmd.cmdidx	= GO_IDLE_STATE;
		cmd.arg		= 0;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_SENDINIT |
				NX_SDXC_CMDFLAG_STOPABORT;

		NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);

		do {
			cmd.cmdidx	= SEND_OP_COND;
			cmd.arg		= 0x40FC0000;	// MMC High Capacity -_-???
			cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
					NX_SDXC_CMDFLAG_WAITPRVDAT |
					NX_SDXC_CMDFLAG_SHORTRSP;
			if (NX_SDMMC_STATUS_NOERROR !=
					NX_SDMMC_SendCommand(pSDXCBootStatus,
								&cmd)) {
				return CFALSE;
			}

			if (timeout-- <= 0) {
				NX_DEBUG_MSG("TO to wait pow-up for MMC\r\n");
				return CFALSE;
			}
		/* Wait until card has finished the power up routine */
		} while (0==(cmd.response[0] & (1UL << 31)));

		printf("MMC Card.\r\n");
		#if defined(VERBOSE)
		NX_DEBUG_MSG("--> SEND_OP_COND Response = 0x");
		NX_DEBUG_HEX(cmd.response[0]);
		NX_DEBUG_MSG("\n");
		#endif

		CardType	= NX_SDMMC_CARDTYPE_MMC;
		RCA		= 2 << 16;
	}

//	NX_ASSERT( (cmd.response[0] & 0x00FC0000) == 0x00FC0000 );
	pSDXCBootStatus->bHighCapacity =
		(cmd.response[0] & (1 << 30)) ? CTRUE : CFALSE;

	if (pSDXCBootStatus->bHighCapacity)
		printf("HiCap Card.\r\n");

	//--------------------------------------------------------------------------
	// Get CID
	cmd.cmdidx	= ALL_SEND_CID;
	cmd.arg		= 0;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_LONGRSP;
	if (NX_SDMMC_STATUS_NOERROR !=
			NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd))
		return CFALSE;

	//--------------------------------------------------------------------------
	// Get RCA and change to Stand-by State in data transfer mode
	cmd.cmdidx	= (CardType == NX_SDMMC_CARDTYPE_SDMEM) ?
					SEND_RELATIVE_ADDR : SET_RELATIVE_ADDR;
	cmd.arg		= RCA;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;
	if (NX_SDMMC_STATUS_NOERROR !=
			NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd))
		return CFALSE;

	if (CardType == NX_SDMMC_CARDTYPE_SDMEM)
		pSDXCBootStatus->rca = cmd.response[0] & 0xFFFF0000;
	else
		pSDXCBootStatus->rca = RCA;

	#if defined(VERBOSE)
	NX_DEBUG_MSG("RCA = 0x");
	NX_DEBUG_HEX(pSDXCBootStatus->rca);
	NX_DEBUG_MSG("\n");
	#endif

	pSDXCBootStatus->CardType = CardType;

	return CTRUE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SelectCard(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;

	cmd.cmdidx	= SELECT_CARD;
	cmd.arg		= pSDXCBootStatus->rca;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	status = NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);

	return (NX_SDMMC_STATUS_NOERROR == status) ? CTRUE : CFALSE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SetCardDetectPullUp(SDXCBOOTSTATUS *pSDXCBootStatus,
					CBOOL bEnb)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;

	cmd.cmdidx	= SET_CLR_CARD_DETECT;
	cmd.arg		= (bEnb) ? 1 : 0;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;

	status = NX_SDMMC_SendAppCommand(pSDXCBootStatus, &cmd);

	return (NX_SDMMC_STATUS_NOERROR == status) ? CTRUE : CFALSE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SetBusWidth(SDXCBOOTSTATUS *pSDXCBootStatus,
					U32 buswidth )
{
	U32 status;
	NX_SDMMC_COMMAND cmd;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	NX_ASSERT( buswidth==1 || buswidth==4 );

	if (pSDXCBootStatus->CardType == NX_SDMMC_CARDTYPE_SDMEM) {
		cmd.cmdidx	= SET_BUS_WIDTH;
		cmd.arg		= (buswidth >> 1);
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP;
		status = NX_SDMMC_SendAppCommand(pSDXCBootStatus, &cmd);
	} else {
		/* ExtCSD[183] : BUS_WIDTH <= 0 : 1-bit, 1 : 4-bit, 2 : 8-bit */
		cmd.cmdidx	= SWITCH_FUNC;
		cmd.arg		=		  (3 << 24) |
						(183 << 16) |
				    ((buswidth >> 2) << 8) |
						  (0 << 0);
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP;
		status = NX_SDMMC_SendCommand( pSDXCBootStatus, &cmd );
	}

	if (NX_SDMMC_STATUS_NOERROR != status)
		return CFALSE;

	/* 0 : 1-bit mode, 1 : 4-bit mode */
	pSDXCReg->CTYPE = buswidth >> 2;
#ifdef NXP5540
	pSDXCReg->TIEMODE = buswidth >> 2;
#endif

	return CTRUE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SetBlockLength(SDXCBOOTSTATUS *pSDXCBootStatus,
					U32 blocklength)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	cmd.cmdidx	= SET_BLOCKLEN;
	cmd.arg		= blocklength;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_WAITPRVDAT |
			NX_SDXC_CMDFLAG_CHKRSPCRC |
			NX_SDXC_CMDFLAG_SHORTRSP;
	status = NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);

	if (NX_SDMMC_STATUS_NOERROR != status)
		return CFALSE;

	pSDXCReg->BLKSIZ = blocklength;

	return CTRUE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_SelectPartition(SDXCBOOTSTATUS *pSDXCBootStatus,
					U32 partition)
{
	U32 status;
	NX_SDMMC_COMMAND cmd;

	#define IMMEDIATE_RESPONSE		(1<<0)
	#define DEFERRED_RESPONSE		(1<<17)

	if (pSDXCBootStatus->CardType == NX_SDMMC_CARDTYPE_SDMEM) {
		NX_ASSERT( partition < 256 );

		cmd.cmdidx	= SELECT_PARTITION;
		cmd.arg		= (partition << 24) | IMMEDIATE_RESPONSE;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP;
	} else {
		NX_ASSERT(partition == 1 || partition == 2);

		/* Set Bits : BOOT_CONFIG[1:0] = 1 or 2	// R/W Boot Partition */
		cmd.cmdidx	= SWITCH_FUNC;
		cmd.arg		=	  (1 << 24) |
					(179 << 16) |
				  (partition << 8) |
					  (0 << 0);
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP;
	}

	status = NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);

	if (NX_SDMMC_STATUS_NOERROR != status) {
		return CFALSE;
	}

	if (cmd.response[0] & DEFERRED_RESPONSE) {
		status = NX_SDMMC_SendStatus(pSDXCBootStatus);
		if (NX_SDMMC_STATUS_NOERROR != status)
			return CFALSE;
	}

	return CTRUE;
}

//------------------------------------------------------------------------------
CBOOL NX_SDMMC_Init(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	U32 i = pSDXCBootStatus->SDPort;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[i];
#ifdef NXP5430
 	register struct NX_CLKGEN_RegisterSet * const pSDClkGenReg =
					pgSDClkGenReg[i];

 	pSDClkGenReg->CLKENB = NX_PCLKMODE_ALWAYS << 3 | NX_BCLKMODE_DYNAMIC << 0;
 	pSDClkGenReg->CLKGEN[0] =
			(pSDClkGenReg->CLKGEN[0] & ~(0x7 << 2 | 0xFF << 5))
			  | ((SDXC_CLKDIV_LOW - 1) << 5)// set clock divisor
			  | (SDXC_CLKSRC << 2)		// set clock source
			  | (0UL << 1);			// set clock invert
 	pSDClkGenReg->CLKENB |= 0x1UL << 2;		// clock generation enable

 	ResetCon(SDResetNum[i], CTRUE);	// reset on
 	ResetCon(SDResetNum[i], CFALSE);	// reset negate
#endif

#ifdef NXP5540
    // pll0 : 550 Mhz
    // pll1 : 147 Mhz
    // pll2 :  96 Mhz
    // pll5 : 147 Mhz
    // pll6 :  96 Mhz
    // pll7 : 200 Mhz
	U32 regval;
	// sdmmc core clock source select
	nx_cpuif_reg_write_one(cpuif[i][0], SDXC_CLKSRC);
	// sdmmc core clock divider value
	nx_cpuif_reg_write_one(cpuif[i][1], (SDXC_CLKDIV_LOW - 1));
	while (1 == nx_cpuif_reg_read_one(cpuif[i][2], &regval))
		;
	/////////////////////////////////////
	// s/w stop and go 
	/////////////////////////////////////
	// sdmmc bus clock disable
	nx_cpuif_reg_write_one(cpuif[i][3], 0);
	nx_cpuif_reg_write_one(cpuif[i][4], 0);

	// sdmmc reset mode
	nx_cpuif_reg_write_one(cpuif[i][5], 1);

	// sdmmc reset release
	nx_cpuif_reg_write_one(cpuif[i][6], 1);

	// sdmmc bus clock enable
	nx_cpuif_reg_write_one(cpuif[i][3], 1);
	nx_cpuif_reg_write_one(cpuif[i][4], 1);
#endif

	pSDXCReg->PWREN = 0 << 0;	// Set Power Disable

	pSDXCReg->CLKENA = NX_SDXC_CLKENA_LOWPWR;// low power mode & clock disable
#ifdef NXP5430
	pSDXCReg->CLKCTRL =
		0 << 24 |	// sample clock phase shift 0:0 1:90 2:180 3:270
		2 << 16 |	// drive clock phase shift 0:0 1:90 2:180 3:270
		0 << 8  |	// sample clock delay
		0 << 0;		// drive clock delay
#endif
#ifdef NXP5540
	pSDXCReg->TIEDRVPHASE   = NX_SDMMC_CLOCK_SHIFT_180 << 8;
	pSDXCReg->TIESMPPHASE   = NX_SDMMC_CLOCK_SHIFT_0  << 8;
#endif

	pSDXCReg->CLKSRC = 0;	// prescaler 0
	pSDXCReg->CLKDIV = SDCLK_DIVIDER >> 1;	//	2*n divider (0 : bypass)

	// fifo mode, not read wait(only use sdio mode)
	pSDXCReg->CTRL &= ~(NX_SDXC_CTRL_DMAMODE_EN | NX_SDXC_CTRL_READWAIT);
	// Reset the controller & DMA interface & FIFO
	pSDXCReg->CTRL = NX_SDXC_CTRL_DMARST |
			NX_SDXC_CTRL_FIFORST |
			NX_SDXC_CTRL_CTRLRST;
	while (pSDXCReg->CTRL & (NX_SDXC_CTRL_DMARST |
				NX_SDXC_CTRL_FIFORST |
				NX_SDXC_CTRL_CTRLRST))
		;

	pSDXCReg->PWREN = 0x1 << 0;	// Set Power Enable

	// Data Timeout = 0xFFFFFF, Response Timeout = 0x64
	pSDXCReg->TMOUT = (0xFFFFFFU << 8) | (0x64 << 0);

	// Data Bus Width : 0(1-bit), 1(4-bit)
	pSDXCReg->CTYPE = 0;

	// Block size
	pSDXCReg->BLKSIZ = BLOCK_LENGTH;

	// Issue when RX FIFO Count >= 8 x 4 bytes & TX FIFO Count <= 8 x 4 bytes
	pSDXCReg->FIFOTH = ((8 - 1) << 16) |		// Rx threshold
				(8 << 0);		// Tx threshold

	// Mask & Clear All interrupts
	pSDXCReg->INTMASK = 0;
	pSDXCReg->RINTSTS = 0xFFFFFFFF;

#ifdef NXP5540
	// Wake up & Power on fifo sram
	pSDXCReg->TIESRAM = 0x3;
#endif

	return CTRUE;
}

//------------------------------------------------------------------------------
CBOOL NX_SDMMC_Terminate(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];
#ifdef NXP5430
	register struct NX_CLKGEN_RegisterSet * const pSDClkGenReg =
					pgSDClkGenReg[pSDXCBootStatus->SDPort];
#endif
	// Clear All interrupts
	pSDXCReg->RINTSTS = 0xFFFFFFFF;

	// Reset the controller & DMA interface & FIFO
	pSDXCReg->CTRL = NX_SDXC_CTRL_DMARST |
			NX_SDXC_CTRL_FIFORST |
			NX_SDXC_CTRL_CTRLRST;
	while (pSDXCReg->CTRL & (NX_SDXC_CTRL_DMARST |
				NX_SDXC_CTRL_FIFORST |
				NX_SDXC_CTRL_CTRLRST))
		;

#ifdef NXP5430
	// Disable CLKGEN
	pSDClkGenReg->CLKENB = 0;
	ResetCon(SDResetNum[pSDXCBootStatus->SDPort], CTRUE);	// reset on
#endif

#ifdef NXP5540
	// sdmmc reset disable
	nx_cpuif_reg_write_one(RSTI_sdmmc_0_axi_rst, 0);
	// sdmmc bus clock disable
	nx_cpuif_reg_write_one(CMUI_SDMMC_0_AXI_clk_enb, 0);
	// sdmmc core clock disable
	nx_cpuif_reg_write_one(CMUI_SDMMC_0_CORE_clk_enb, 0);
#endif

	return CTRUE;
}

//------------------------------------------------------------------------------
CBOOL NX_SDMMC_Open(SDXCBOOTSTATUS *pSDXCBootStatus, U32 option)
{
	U32 SDSpeed;
	if (pSDXCBootStatus->bHighSpeed == CTRUE)
		SDSpeed = SDXC_CLKDIV_HIGH;
	else
		SDSpeed = SDXC_CLKDIV_LOW;
	//--------------------------------------------------------------------------
	// card identification mode : Identify & Initialize
	if (CFALSE == NX_SDMMC_IdentifyCard(pSDXCBootStatus)) {
		printf("Identify Fail\r\n");
		return CFALSE;
	}

	//--------------------------------------------------------------------------
	// data transfer mode : Stand-by state
	if (CFALSE == NX_SDMMC_SetClock(pSDXCBootStatus, CTRUE, SDSpeed)) {
		printf("Card Clock reset fail\r\n");
		return CFALSE;
	}
	if (CFALSE == NX_SDMMC_SelectCard(pSDXCBootStatus)) {
		printf("Card Select Fail\r\n");
		return CFALSE;
	}

	//--------------------------------------------------------------------------
	// data transfer mode : Transfer state
	if (pSDXCBootStatus->CardType == NX_SDMMC_CARDTYPE_SDMEM) {
		NX_SDMMC_SetCardDetectPullUp(pSDXCBootStatus, CFALSE);
	}

	if (CFALSE == NX_SDMMC_SetBlockLength(pSDXCBootStatus, BLOCK_LENGTH)) {
		printf("Set Block Length Fail\r\n");
		return CFALSE;
	}

	NX_SDMMC_SetBusWidth(pSDXCBootStatus, 4);

	// Select Boot Partiton for eSD and eMMC
	if (option & (1 << SDXCPARTITION))
		NX_SDMMC_SelectPartition(pSDXCBootStatus, 1);

	return CTRUE;
}

//------------------------------------------------------------------------------
CBOOL NX_SDMMC_Close(SDXCBOOTSTATUS *pSDXCBootStatus)
{
	NX_SDMMC_SetClock(pSDXCBootStatus, CFALSE, SDXC_DIVIDER_400KHZ);
	return CTRUE;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_ReadSectorData(
		SDXCBOOTSTATUS *pSDXCBootStatus,
		U32 numberOfSector,
		U32 *pdwBuffer)
{
	U32		count;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	NX_ASSERT(0==((U32)pdwBuffer & 3));

	count = numberOfSector * BLOCK_LENGTH;
	NX_ASSERT(0 == (count % 32));

	while (0 < count) {
		if ((pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_RXDR)
		 || (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DTO)) {
			U32 FSize, Timeout = NX_SDMMC_TIMEOUT;
			while ((pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY) &&
					Timeout--)
				;
			if (0 == Timeout)
				break;
			FSize = (pSDXCReg->STATUS &
					NX_SDXC_STATUS_FIFOCOUNT) >> 17;
			count -= (FSize * 4);
			while (FSize) {
				*pdwBuffer++ = pSDXCReg->DATA;
				FSize--;
			}

			pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_RXDR;
		}

		// Check Errors
		if (pSDXCReg->RINTSTS & (NX_SDXC_RINTSTS_DRTO |
					NX_SDXC_RINTSTS_EBE |
					NX_SDXC_RINTSTS_SBE |
					NX_SDXC_RINTSTS_DCRC)) {
			printf("Read left = %x\r\n", count);

			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DRTO)
				printf("DRTO\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_EBE)
				printf("EBE\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_SBE)
				printf("SBE\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DCRC)
				printf("DCRC\r\n");

			return CFALSE;
		}

		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DTO) {
			if (count == 0) {
				pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_DTO;
				break;
			}
		}

		#if defined(NX_DEBUG)
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HTO) {
			printf("HTO\r\n");
			pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_HTO;
		}
		#endif

		NX_ASSERT(0 == (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_FRUN));
	}

	pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_DTO;

	return CTRUE;
}

//------------------------------------------------------------------------------
CBOOL NX_SDMMC_ReadSectors(SDXCBOOTSTATUS *pSDXCBootStatus,
			U32 SectorNum, U32 numberOfSector, U32 *pdwBuffer)
{
	CBOOL	result = CFALSE;
	U32		status;
	#if defined(NX_DEBUG)
	U32	response;
	#endif
	NX_SDMMC_COMMAND cmd;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	NX_ASSERT( 0 == ((U32)pdwBuffer & 3) );
	
	// wait while data busy or data transfer busy
	while (pSDXCReg->STATUS & (1 << 9 | 1 << 10))
		;

	//--------------------------------------------------------------------------
	// wait until 'Ready for data' is set and card is in transfer state.
	do {
		cmd.cmdidx	= SEND_STATUS;
		cmd.arg		= pSDXCBootStatus->rca;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP;
		status = NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);
		if (NX_SDMMC_STATUS_NOERROR != status)
			goto End;
	} while (!((cmd.response[0] & (1 << 8)) &&
		(((cmd.response[0] >> 9) & 0xF) == 4)));

	NX_ASSERT(NX_SDXC_STATUS_FIFOEMPTY ==
			(pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY));
	NX_ASSERT(0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FSMBUSY));

	// Set byte count
	pSDXCReg->BYTCNT = numberOfSector * BLOCK_LENGTH;

	//--------------------------------------------------------------------------
	// Send Command
	if (numberOfSector > 1) {
		cmd.cmdidx	= READ_MULTIPLE_BLOCK;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP |
				NX_SDXC_CMDFLAG_BLOCK |
				NX_SDXC_CMDFLAG_RXDATA |
				NX_SDXC_CMDFLAG_SENDAUTOSTOP;
	} else {
		cmd.cmdidx	= READ_SINGLE_BLOCK;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_WAITPRVDAT |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP |
				NX_SDXC_CMDFLAG_BLOCK |
				NX_SDXC_CMDFLAG_RXDATA;
	}
	cmd.arg		= (pSDXCBootStatus->bHighCapacity) ?
				SectorNum : SectorNum*BLOCK_LENGTH;

	status = NX_SDMMC_SendCommand(pSDXCBootStatus, &cmd);
	if (NX_SDMMC_STATUS_NOERROR != status)
		goto End;

	//--------------------------------------------------------------------------
	// Read data
	if (CTRUE != NX_SDMMC_ReadSectorData(pSDXCBootStatus,
						numberOfSector, pdwBuffer)) 
		goto End;

	NX_ASSERT(NX_SDXC_STATUS_FIFOEMPTY ==
			(pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY));
	NX_ASSERT(0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOFULL));
	NX_ASSERT(0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOCOUNT));

	if (numberOfSector > 1) {
		// Wait until the Auto-stop command has been finished.
		while (0 == (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_ACD))
			;

		NX_ASSERT(0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FSMBUSY));

		#if defined(NX_DEBUG)
		// Get Auto-stop response and then check it.
		response = pSDXCReg->RESP1;
		if (response & 0xFDF98008) {
			printf("Auto Stop Resp Failed = %x\r\n", response);
			//goto End;
		}
		#endif
	}

	result = CTRUE;

End:
	if (CFALSE == result) {
		cmd.cmdidx	= STOP_TRANSMISSION;
		cmd.arg		= 0;
		cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
				NX_SDXC_CMDFLAG_CHKRSPCRC |
				NX_SDXC_CMDFLAG_SHORTRSP |
				NX_SDXC_CMDFLAG_STOPABORT;
		NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd);

		if (0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY)) {
			pSDXCReg->CTRL = NX_SDXC_CTRL_FIFORST;
			while (pSDXCReg->CTRL & NX_SDXC_CTRL_FIFORST)
				;
		}
	}

	return result;
}

//------------------------------------------------------------------------------
static CBOOL NX_SDMMC_ReadBootSector(
		SDXCBOOTSTATUS *pSDXCBootStatus,
		U32 numberOfSector,
		U32 *pdwBuffer)
{
	U32		count;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
					pgSDXCReg[pSDXCBootStatus->SDPort];

	NX_ASSERT(0==((U32)pdwBuffer & 3));

	count = numberOfSector * BLOCK_LENGTH;
	NX_ASSERT(0 == (count % 32));

	while (0 < count) {
		if ((pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_RXDR)
		 || (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DTO)) {
			U32 FSize, Timeout = NX_SDMMC_TIMEOUT;
			while ((pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY) &&
					Timeout--)
				;
//			if (0 == Timeout)
//				break;
			FSize = (pSDXCReg->STATUS &
					NX_SDXC_STATUS_FIFOCOUNT) >> 17;
			count -= (FSize * 4);
			while (FSize) {
				*pdwBuffer++ = pSDXCReg->DATA;
				FSize--;
			}

			pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_RXDR;
		}
#if 0
		// Check Errors
		if (pSDXCReg->RINTSTS & (NX_SDXC_RINTSTS_DRTO |
					NX_SDXC_RINTSTS_EBE |
					NX_SDXC_RINTSTS_SBE |
					NX_SDXC_RINTSTS_DCRC)) {
			printf("Read left = %x\r\n", count);

			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DRTO)
				printf("DRTO\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_EBE)
				printf("EBE\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_SBE)
				printf("SBE\r\n");
			if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DCRC)
				printf("DCRC\r\n");

			return CFALSE;
		}
#endif
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_DTO) {
			if (count == 0) {
				pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_DTO;
				printf("DTO\r\n");
				break;
			}
		}

		#if defined(NX_DEBUG)
		if (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_HTO) {
			printf("HTO\r\n");
			pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_HTO;
		}
		#endif

		NX_ASSERT(0 == (pSDXCReg->RINTSTS & NX_SDXC_RINTSTS_FRUN));
	}

	pSDXCReg->RINTSTS = NX_SDXC_RINTSTS_DTO;

	return CTRUE;
}
#ifdef NXP5430
void DataDump(U32 * Addr, U32 Size)
{
	U32 i, j;
	for (i = 0; i < Size / 16; i++) {
		printf("0x%08X: ", (U32)Addr);
		for (j = 0; j < 4; j++) {
			printf("%08X ", Addr[j]); 
			if (Size <= i * 16 + j * 4)
				break;
		}
		Addr += 4;
		printf("\r\n");
	}
	printf("\r\n");
}
#endif

//------------------------------------------------------------------------------
static CBOOL eMMCBoot(SDXCBOOTSTATUS *pSDXCBootStatus, U32 option)
{
	register CBOOL	result = CFALSE;
	register struct NX_SDMMC_RegisterSet * const pSDXCReg =
				pgSDXCReg[pSDXCBootStatus->SDPort];
	register U32 SDSpeed;
	NX_SDMMC_COMMAND cmd;

	if (pSDXCBootStatus->bHighSpeed == CTRUE)
		SDSpeed = SDXC_CLKDIV_HIGH;
	else
		SDSpeed = SDXC_CLKDIV_LOW;

	pSDXCReg->CTYPE		= 1;	/* Data Bus Width : 0(1-bit), 1(4-bit) */
	pSDXCReg->BYTCNT	= 0;	/* unspecified data size */

	if (CFALSE == NX_SDMMC_SetClock(pSDXCBootStatus, CTRUE, SDSpeed)) {
		printf("clock init fail\r\n");
		return CFALSE;
	}

#if 0
	cmd.cmdidx	= GO_IDLE_STATE;
	cmd.arg		= 0xF0F0F0F0;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_SENDINIT |
			NX_SDXC_CMDFLAG_STOPABORT;

	NX_SDMMC_SendCommand(&cmd);
#endif

	//--------------------------------------------------------------------------
	//	Send Alternative boot command
	cmd.cmdidx	= GO_IDLE_STATE;
	cmd.arg		= 0xFFFFFFFA;		/* Alternative boot mode */
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD | NX_SDXC_CMDFLAG_SENDINIT |
			  NX_SDXC_CMDFLAG_BLOCK | NX_SDXC_CMDFLAG_RXDATA;
#if 0	/* not supported boot ack */
	cmd.flag	|= NX_SDXC_CMDFLAG_EXPECTBOOTACK;
#endif

	option |= 1 << eMMCBOOTMODE;
//	0: normal boot, 1: Alternative boot
	if ((option & 1 << eMMCBOOTMODE) == 0)
		cmd.flag |= NX_SDXC_CMDFLAG_ENABLE_BOOT;	// normal boot

	/* just send boot command. no expect response */
	if (NX_SDMMC_STATUS_NOERROR !=
			NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd)) {
		if (option & 1 << eMMCBOOTMODE) {
			printf("Send Cmd Internal Err\r\n");
			goto error;
		}
	}

	struct nx_bootinfo *pSBI =
		(struct nx_bootinfo *)BASEADDR_SRAM;

	// read bootheader 1024 bytes
	if (NX_SDMMC_ReadBootSector(pSDXCBootStatus, 2, (U32 *)pSBI)
			== CFALSE) { 
		printf("Cannot Read Boot Header\r\n");
		goto error;
	}
 	if (option & 1 << DECRYPT)
 		Decrypt((U32*)BASEADDR_SRAM, (U32*)BASEADDR_SRAM,
				sizeof(struct nx_bootheader));

#ifdef NXP5430
	DataDump(BASEADDR_SRAM, 1024);
#endif
	if (pSBI->signature != HEADER_ID) {
		printf("no boot header(%04X)\r\n", pSBI->signature);
		goto error;
	}

//	__asm__ __volatile__ ("wfi");
	printf("Load Addr: %x, Load Size: %x, Launch Addr :%x\r\n",
			pSBI->LoadAddr, pSBI->LoadSize,
			pSBI->StartAddr);

	U32 BootSize = pSBI->LoadSize;

	if (BootSize > INTERNAL_SRAM_SIZE - SECONDBOOT_STACK)
		BootSize = INTERNAL_SRAM_SIZE - SECONDBOOT_STACK;

	//	Read Data
	result = NX_SDMMC_ReadBootSector(pSDXCBootStatus,
			(BootSize + BLOCK_LENGTH - 1) / BLOCK_LENGTH,
			(U32 *)(BASEADDR_SRAM + sizeof(struct nx_bootheader)));

	if (option & 1 << DECRYPT)
		Decrypt((U32*)(BASEADDR_SRAM + sizeof(struct nx_bootheader)),
			(U32*)(BASEADDR_SRAM + sizeof(struct nx_bootheader)),
			BootSize);

#ifdef NXP5430
	DataDump(BASEADDR_SRAM, 1024);
#endif
error:

	//--------------------------------------------------------------------------
	cmd.cmdidx	= GO_IDLE_STATE;
	cmd.arg		= 0;
	cmd.flag	= NX_SDXC_CMDFLAG_STARTCMD |
			NX_SDXC_CMDFLAG_STOPABORT |
			NX_SDXC_CMDFLAG_DISABLE_BOOT;
	NX_SDMMC_SendCommandInternal(pSDXCBootStatus, &cmd);

	if (0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY)) {
		pSDXCReg->CTRL = NX_SDXC_CTRL_FIFORST;
		while (pSDXCReg->CTRL & NX_SDXC_CTRL_FIFORST)
			;
	}

	return result;
}

//------------------------------------------------------------------------------
static CBOOL SDMMCBOOT(SDXCBOOTSTATUS *pSDXCBootStatus, U32 option)
{
	CBOOL	result = CFALSE;
	struct NX_SDMMC_RegisterSet * const pSDXCReg =
				pgSDXCReg[pSDXCBootStatus->SDPort];

	if (CTRUE != NX_SDMMC_Open(pSDXCBootStatus, option)) {
		printf("SD open fail\r\n");
		goto error;
	}
	struct nx_bootinfo *pSBI =
		(struct nx_bootinfo *)BASEADDR_SRAM;
	if (0 == (pSDXCReg->STATUS & NX_SDXC_STATUS_FIFOEMPTY)) {
		volatile U32 tempcount = 0x100000;
		pSDXCReg->CTRL = NX_SDXC_CTRL_FIFORST;
		/* Wait until the FIFO reset is completed. */
		while ((pSDXCReg->CTRL & NX_SDXC_CTRL_FIFORST) &&
				tempcount--)
			;
	}
#ifdef NXP5430
	if (NX_SDMMC_ReadSectors(pSDXCBootStatus, 0x81, 2, (U32 *)pSBI) == CFALSE) {
		printf("cannot read boot header\r\n");
		goto error;
	}
#endif
#ifdef NXP5540
	if (NX_SDMMC_ReadSectors(pSDXCBootStatus, 1, 2, (U32 *)pSBI) == CFALSE) {
		printf("cannot read boot header\r\n");
		goto error;
	}
#endif
 	if (option & 1 << DECRYPT)
 		Decrypt((U32*)BASEADDR_SRAM,
			(U32*)BASEADDR_SRAM,
			sizeof(struct nx_bootheader));

	if (pSBI->signature != HEADER_ID) {
		printf("wrong boot Sinature(%04x)\r\n", pSBI->signature);
#ifdef NXP5430
		DataDump((U32*)pSBI, sizeof(struct nx_bootheader));
#endif
		goto error;
	}
	U32 BootSize;
	printf("Load Addr :%x  Load Size :%x  Launch Addr :%x\r\n",
		pSBI->LoadAddr, pSBI->LoadSize, pSBI->StartAddr);

	BootSize = pSBI->LoadSize;
	if (BootSize > INTERNAL_SRAM_SIZE - SECONDBOOT_STACK)
		BootSize = INTERNAL_SRAM_SIZE - SECONDBOOT_STACK;

	result = NX_SDMMC_ReadSectors(pSDXCBootStatus, 3,
			(BootSize + BLOCK_LENGTH - 1) / BLOCK_LENGTH,
			(U32 *)(BASEADDR_SRAM + sizeof(struct nx_bootheader)));

 	if (option & 1 << DECRYPT)
 		Decrypt((U32*)(BASEADDR_SRAM + sizeof(struct nx_bootheader)),
			(U32*)(BASEADDR_SRAM + sizeof(struct nx_bootheader)),
			BootSize);
error:

	return result;
}

#ifdef NXP5540
static const union nxpad sdmmcpad[3][6] = {
{
	{PADI_SDMMC0_CDATA_0_},
	{PADI_SDMMC0_CDATA_1_},
	{PADI_SDMMC0_CDATA_2_},
	{PADI_SDMMC0_CDATA_3_},
	{PADI_SDMMC0_CCLK},
	{PADI_SDMMC0_CMD}
},
{
	{PADI_SDMMC1_CDATA_0_},
	{PADI_SDMMC1_CDATA_1_},
	{PADI_SDMMC1_CDATA_2_},
	{PADI_SDMMC1_CDATA_3_},
	{PADI_SDMMC1_CCLK},
	{PADI_SDMMC1_CMD}
},
{
	{PADI_SDMMC2_CDATA_0_},
	{PADI_SDMMC2_CDATA_1_},
	{PADI_SDMMC2_CDATA_2_},
	{PADI_SDMMC2_CDATA_3_},
	{PADI_SDMMC2_CCLK},
	{PADI_SDMMC2_CMD}
}};
#endif
void NX_SDPADSetALT(U32 PortNum)
{
#ifdef NXP5430
	if (PortNum == 0) {
		register U32 *pGPIOARegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_A]->GPIOx_ALTFN[1];	// c31, c30, c29, c28, c27
		register U32 *pGPIOBRegA0 =
			(U32 *)&pGPIOReg[GPIO_GROUP_B]->GPIOx_ALTFN[0];	// d05, d04, d03, d02, d01, d00
		*pGPIOARegA1 = (*pGPIOARegA1 & ~0xCC000000) | 0x44000000;	// all alt is 1
		*pGPIOBRegA0 = (*pGPIOBRegA0 & ~0x0000CCCC) | 0x00004444;	// all alt is 1

		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW			&= ~(0x5 << 29);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW_DISABLE_DEFAULT	|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0			|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0_DISABLE_DEFAULT	|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1			|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1_DISABLE_DEFAULT	|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL			|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL_DISABLE_DEFAULT	|=   0x5 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB			|=   0x4 << 29;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB_DISABLE_DEFAULT	|=   0x5 << 29;

		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW			&= ~(0x55 << 1);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW_DISABLE_DEFAULT	|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0			|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0_DISABLE_DEFAULT	|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1			|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1_DISABLE_DEFAULT	|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL			|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL_DISABLE_DEFAULT	|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB			|=   0x55 << 1;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB_DISABLE_DEFAULT	|=   0x55 << 1;
	} else if(PortNum == 1) {
		register U32 *pGPIODRegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[1];	// d16
		*pGPIODRegA1 = (*pGPIODRegA1 & ~0x00FFF000) | 0x00555000;	// all alt is 1
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW			&= ~(0x3F << 22);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW_DISABLE_DEFAULT	|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0			|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0_DISABLE_DEFAULT	|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1			|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1_DISABLE_DEFAULT	|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL			|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL_DISABLE_DEFAULT	|=   0x3F << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB			|=   0x3E << 22;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB_DISABLE_DEFAULT	|=   0x3F << 22;
	} else {   // PortNum == 2
		register U32 *pGPIOCRegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1];
		*pGPIOCRegA1 = (*pGPIOCRegA1 & ~0x0000FFF0) | 0x000AAA0;	// all alt is 1
		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW			&= ~(0x3F << 18);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW_DISABLE_DEFAULT	|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0			|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0_DISABLE_DEFAULT	|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1			|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1_DISABLE_DEFAULT	|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL			|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL_DISABLE_DEFAULT	|=   0x3F << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB			|=   0x3E << 18;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB_DISABLE_DEFAULT	|=   0x3F << 18;
	}
#endif

#ifdef NXP5540
	U32 i;
	for (i = 0; i < 6; i++) {
		GPIOSetAltFunction(&sdmmcpad[PortNum][i].padi, CTRUE);
		GPIOSetDrvSt(&sdmmcpad[PortNum][i].padi, NX_GPIO_DRVSTRENGTH_3);
		GPIOSetPullup(&sdmmcpad[PortNum][i].padi, NX_GPIO_PULL_OFF);
	}
#endif
}

void NX_SDPADSetGPIO(U32 PortNum)
{
#ifdef NXP5430
	if (PortNum == 0) {
		register U32 *pGPIOARegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_C]->GPIOx_ALTFN[1];	// c31, c30, c29, c28, c27
		register U32 *pGPIOBRegA0 =
			(U32 *)&pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[0];	// d05, d04, d03, d02, d01, d00
		*pGPIOARegA1 = (*pGPIOARegA1 & ~0xFFC00000);                                // all alt is 1
		*pGPIOBRegA0 = (*pGPIOBRegA0 & ~0x00000FFF);                                // all alt is 1

		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW |= 0x1F << 27;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_SLEW_DISABLE_DEFAULT |= 0x1F << 27;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0 &= ~(0x1F << 27);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV0_DISABLE_DEFAULT |= 0x1F << 27;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1 &= ~(0x1F << 27);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_DRV1_DISABLE_DEFAULT |= 0x1F << 27;
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL &= ~(0x1F << 27);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLSEL_DISABLE_DEFAULT &= ~(0x1F << 27);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB &= ~(0x1F << 27);
		pGPIOReg[GPIO_GROUP_C]->GPIOx_PULLENB_DISABLE_DEFAULT &= ~(0x1F << 27);

		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW |= 0x3F << 0;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW_DISABLE_DEFAULT |= 0x3F << 0;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0 &= ~(0x3F << 0);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0_DISABLE_DEFAULT |= 0x3F << 0;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1 &= ~(0x3F << 0);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1_DISABLE_DEFAULT |= 0x3F << 0;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL &= ~(0x3F << 0);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL_DISABLE_DEFAULT &= ~(0x3F << 0);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB &= ~(0x3F << 0);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB_DISABLE_DEFAULT &= ~(0x3F << 0);
	} else if(PortNum == 1) {
		register U32 *pGPIODRegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[1];	// d16
		register U32 *pGPIODRegA0 =
			(U32 *)&pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[0];	// d15, d14, d13, d12, d11, d10, d09, d08, d07, d06
		*pGPIODRegA1 = (*pGPIODRegA1 & ~0x00000003);                                // all alt is 0
		*pGPIODRegA0 = (*pGPIODRegA1 & ~0xFFFFF000);                                // all alt is 0

		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW |= 0x7FF << 6;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW_DISABLE_DEFAULT |= 0x7FF << 6;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0 &= ~(0x7FF << 6);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0_DISABLE_DEFAULT |= 0x7FF << 6;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1 &= ~(0x7FF << 6);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1_DISABLE_DEFAULT |= 0x7FF << 6;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL &= ~(0x7FF << 6);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL_DISABLE_DEFAULT &= ~(0x7FF << 6);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB &= ~(0x7FF << 6);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB_DISABLE_DEFAULT &= ~(0x7FF << 6);
	} else {
		register U32 *pGPIOCRegA1 =
			(U32 *)&pGPIOReg[GPIO_GROUP_D]->GPIOx_ALTFN[1];	// d27, d26, d25, d24, d23, d22, d21, d20, d19, d18, d17
		*pGPIOCRegA1 = (*pGPIOCRegA1 & ~0x00FFFFF7);	                            // all alt is 0

		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW |= 0x7FF << 17;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_SLEW_DISABLE_DEFAULT |= 0x7FF << 17;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0 &= ~(0x7FF << 17);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV0_DISABLE_DEFAULT |= 0x7FF << 17;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1 &= ~(0x7FF << 17);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_DRV1_DISABLE_DEFAULT |= 0x7FF << 17;
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL &= ~(0x7FF << 17);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLSEL_DISABLE_DEFAULT &= ~(0x7FF << 17);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB &= ~(0x7FF << 17);
		pGPIOReg[GPIO_GROUP_D]->GPIOx_PULLENB_DISABLE_DEFAULT &= ~(0x7FF << 17);
	}
#endif

#ifdef NXP5540
	U32 i;
	for (i = 0; i < 6; i++) {
		GPIOSetAltFunction(&sdmmcpad[PortNum][i].padi, CFALSE);
		GPIOSetDrvSt(&sdmmcpad[PortNum][i].padi, NX_GPIO_DRVSTRENGTH_3);
		GPIOSetPullup(&sdmmcpad[PortNum][i].padi, NX_GPIO_PULL_OFF);
	}
#endif
}

//------------------------------------------------------------------------------
U32 iSDXCBOOT(U32 option)
{
	SDXCBOOTSTATUS SDXCBootStatus, *pSDXCBootStatus;
	CBOOL	result = CFALSE;

	pSDXCBootStatus = &SDXCBootStatus;

	pSDXCBootStatus->SDPort = ((option >> SELSDPORT) & 0x1);// 0 or 1
	if (option & 2UL << SELSDPORT)
		pSDXCBootStatus->SDPort += 2;			// 2 or 3

	if (pSDXCBootStatus->SDPort >= 3) {
		pSDXCBootStatus->SDPort = 2;
		pSDXCBootStatus->bHighSpeed = CTRUE;
	} else
		pSDXCBootStatus->bHighSpeed = CFALSE;
//	pSDXCBootStatus->SDPort = 0;
//	printf("SD Boot with Port %d\r\n", pSDXCBootStatus->SDPort);
	NX_SDPADSetALT(pSDXCBootStatus->SDPort);

	NX_SDMMC_Init(pSDXCBootStatus);

	//--------------------------------------------------------------------------
	// eMMC or MMC ver 4.3+
	//if (option & (1U << eMMCBOOTMODE))
	if ((option & 0x7) == 0) {
		printf("eMMC%d boot start\r\n", pSDXCBootStatus->SDPort);
		result = eMMCBoot(pSDXCBootStatus, option);
	}

	//--------------------------------------------------------------------------
	// Normal SD(eSD)/MMC ver 4.2 boot
	if (CFALSE == result) {
		printf("SD%d boot start\r\n", pSDXCBootStatus->SDPort);
		result = SDMMCBOOT(pSDXCBootStatus, option);
	}

	NX_SDMMC_Close(pSDXCBootStatus);
	NX_SDMMC_Terminate(pSDXCBootStatus);

	NX_SDPADSetGPIO(pSDXCBootStatus->SDPort);

	return result;
}
