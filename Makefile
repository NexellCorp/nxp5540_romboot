#
#	Copyright (C) 2012 Nexell Co., All Rights Reserved
#	Nexell Co. Proprietary & Confidential
#
#	NEXELL INFORMS THAT THIS CODE AND INFORMATION IS PROVIDED "AS IS" BASE
#	AND WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
#	BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
#	FITNESS FOR A PARTICULAR PURPOSE.
#
#	Moudle		: bl0
#	File		: Makefile
#	Description	:
#	Author		: Firware Team
#	History		: 2016.08.10 hans first draft
#

include config.mak


LDFLAGS		= -Bstatic						\
		-Wl,-Map=$(DIR_TARGETOUTPUT)/$(PROJECT_NAME).map,--cref	\
		-T$(LDS_NAME)						\
		-Wl,--start-group					\
		-L$src/$(DIR_OBJOUTPUT)					\
		-Wl,--end-group						\
		-nostdlib

SYS_OBJS	 = 	startup_$(OPMODE).o iROMBOOT.o CRYPTO.o GPIO.o
SYS_OBJS	+= 	iSDHCBOOT.o
SYS_OBJS	+= 	iUSBBOOT.o
SYS_OBJS	+= 	iSPIBOOT.o
SYS_OBJS	+= 	iNANDBOOTEC.o
SYS_OBJS	+= 	iSDHCFSBOOT.o fatfs.o diskio.o
SYS_OBJS	+= 	cpuif_regmap_framework.o
SYS_OBJS	+= 	nx_chip_sfr.o
SYS_OBJS	+= 	libarm.o lib_$(OPMODE).o

SYS_OBJS_LIST	= 	$(addprefix $(DIR_OBJOUTPUT)/,$(SYS_OBJS))

SYS_INCLUDES 	=	-I ./src			\
			-I ./prototype/base 		\
			-I ./prototype/module


################################################################################
$(DIR_OBJOUTPUT)/%.o: src/%.c
	$(Q)echo [compile....$<]
	$(Q)$(CC) -MMD $< -c -o $@ $(CFLAGS) $(SYS_INCLUDES)
################################################################################
$(DIR_OBJOUTPUT)/%.o: src/%.S
	$(Q)echo [compile....$<]
	$(Q)$(CC) -MMD $< -c -o $@ $(ASFLAG) $(CFLAGS) $(SYS_INCLUDES)
################################################################################


all: mkobjdir $(SYS_OBJS_LIST) link bin

mkobjdir:
ifeq ($(OS),Windows_NT)
	$(Q)if not exist $(DIR_OBJOUTPUT)		\
		$(Q)$(MKDIR) $(DIR_OBJOUTPUT)
	$(Q)if not exist $(DIR_TARGETOUTPUT)		\
		$(Q)$(MKDIR) $(DIR_TARGETOUTPUT)
else
	$(Q)if [ ! -e $(DIR_OBJOUTPUT) ]; then		\
		$(MKDIR) $(DIR_OBJOUTPUT);		\
	fi;
	$(Q)if [ ! -e $(DIR_TARGETOUTPUT) ]; then	\
		$(MKDIR) $(DIR_TARGETOUTPUT);		\
	fi;
endif

link:
	$(Q)echo [link.... $(PROJECT_NAME).elf]
	$(Q)$(CC) $(SYS_OBJS_LIST) $(LDFLAGS) -o $(DIR_TARGETOUTPUT)/$(PROJECT_NAME).elf
#	@cp -f $(DIR_TARGETOUTPUT)/$(PROJECT_NAME).elf  ../../bootcodegen/firstly_boot_program.elf

bin:
	$(Q)echo [binary.... $(PROJECT_NAME).bin]
	$(Q)$(MAKEBIN) -O binary $(DIR_TARGETOUTPUT)/$(PROJECT_NAME).elf $(DIR_TARGETOUTPUT)/$(PROJECT_NAME).bin

clean:
ifeq ($(OS),Windows_NT)
	$(Q)if exist $(DIR_OBJOUTPUT)			\
		$(Q)$(RMDIR) $(DIR_OBJOUTPUT)
	$(Q)if exist $(DIR_TARGETOUTPUT)		\
		$(Q)$(RMDIR) $(DIR_TARGETOUTPUT)
else
	$(Q)if [ -e $(DIR_OBJOUTPUT) ]; then		\
		$(RMDIR) $(DIR_OBJOUTPUT);		\
	fi;
	$(Q)if [ -e $(DIR_TARGETOUTPUT) ]; then		\
		$(RMDIR) $(DIR_TARGETOUTPUT);		\
	fi;

endif


################################################################################
-include $(SYS_OBJS_LIST:.o=.d)

