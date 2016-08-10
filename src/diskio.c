/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2007        */
/*-----------------------------------------------------------------------*/
/* This is a stub disk I/O module that acts as front end of the existing */
/* disk I/O modules and attach it to FatFs module with common interface. */
/*-----------------------------------------------------------------------*/

#include "nx_etacarinae.h"
#include "nx_etacarinae_bootoption.h"
#include <nx_type.h>
#include <nx_debug2.h>
#include "diskio.h"

#include <iSDHCBOOT.h>

/*-----------------------------------------------------------------------*/
/* Correspondence between physical drive number and physical drive.      */

#define MMC		0
#define USB		1
#define ATA		2



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */

DSTATUS disk_initialize (
	U8 drv				/* Physical drive nmuber (0..) */
)
{
//	DSTATUS stat = RES_OK;
//	int result;

	switch (drv) {
	case MMC :
//		result = MMC_disk_initialize();
		// translate the reslut code here

		return RES_OK;//stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Return Disk Status                                                    */

DSTATUS disk_status (
	U8 drv		/* Physical drive nmuber (0..) */
)
{
//	DSTATUS stat;
//	int result;

	switch (drv) {
	case MMC :
//		result = MMC_disk_status();
		// translate the reslut code here

		return RES_OK;//stat;
	}
	return STA_NOINIT;
}


/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */

DRESULT disk_read (
	U8 drv,			/* Physical drive nmuber (0..) */
	U8 *buff,		/* Data buffer to store read data */
	U32 sector,		/* Sector address (LBA) */
	U8 count		/* Number of sectors to read (1..255) */
)
{
	CBOOL	Result;
	SDXCBOOTSTATUS *pSDXCBootStatus, **pgSDXCBootStatus;

	pgSDXCBootStatus = (SDXCBOOTSTATUS**)(BASEADDR_SRAM+INTERNAL_SRAM_SIZE-sizeof(U32));
	pSDXCBootStatus = *pgSDXCBootStatus;

	switch (drv) {
	case MMC :
		Result = NX_SDMMC_ReadSectors( pSDXCBootStatus, sector, count, (U32*)buff );
		if(Result)
			return RES_OK;
	}
	return RES_PARERR;
}

