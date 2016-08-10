

###########################################################################
# Build Environment
###########################################################################
DEBUG			= y

EMUL_CPU		= NXP5430
#EMUL_CPU		= NXP5540

OPMODE			= aarch32
#OPMODE			= aarch64


CROSS_TOOL_TOP		=
ifeq ($(OPMODE), aarch32)
ifeq ($(OS),Windows_NT)
CROSS_TOOL		= $(CROSS_TOOL_TOP)arm-none-eabi-
else
CROSS_TOOL		= $(CROSS_TOOL_TOP)arm-eabi-
#CROSS_TOOL		= $(CROSS_TOOL_TOP)arm-none-eabi-
endif
endif

ifeq ($(OPMODE), aarch64)
ifeq ($(OS),Windows_NT)
CROSS_TOOL		= $(CROSS_TOOL_TOP)aarch64-none-elf-
else
CROSS_TOOL		= $(CROSS_TOOL_TOP)aarch64-elf-
endif
endif



###########################################################################
# Top Names
###########################################################################
PROJECT_NAME		= etacarinae
LDS_NAME		= $(PROJECT_NAME).lds


###########################################################################
# Directories
###########################################################################
DIR_PROJECT_TOP		=
DIR_OBJOUTPUT		= obj
DIR_TARGETOUTPUT	= build

CODE_MAIN_INCLUDE	=

###########################################################################
# Build Environment
###########################################################################
CPU			= cortex-a9
CC			= $(CROSS_TOOL)gcc
LD 			= $(CROSS_TOOL)ld
AS 			= $(CROSS_TOOL)as
AR 			= $(CROSS_TOOL)ar
MAKEBIN			= $(CROSS_TOOL)objcopy
RANLIB 			= $(CROSS_TOOL)ranlib

GCC_LIB			= $(shell $(CC) -print-libgcc-file-name)

ifeq ($(DEBUG), y)
CFLAGS			= -DNX_RELEASE -O0
Q			= @
else
CFLAGS			= -DNX_RELEASE -Os
Q			= @
endif

###########################################################################
# MISC tools for MS-DOS
###########################################################################
ifeq ($(OS),Windows_NT)
MKDIR			= mkdir
RM			= del /q /f
MV			= move
CD			= cd
CP			= copy
ECHO			= echo
RMDIR			= rmdir /s /q
else
MKDIR			= mkdir -p
RM			= rm -f
MV			= mv
CD			= cd
CP			= cp
ECHO			= echo
RMDIR			= rm -rf
endif
###########################################################################
# FLAGS
###########################################################################
ARFLAGS			= rcs
ARFLAGS_REMOVE		= -d
ARLIBFLAGS		= -v -s

ASFLAG			= -D__ASSEMBLY__ -D$(OPMODE)


CFLAGS			+= -g -Wall						\
			-Wextra -ffreestanding -fno-builtin			\
		 	-mlittle-endian						\
		 	-mcpu=$(CPU)						\
			$(CODE_MAIN_INCLUDE)					\
			-D__arm	-D$(OPMODE) -D$(EMUL_CPU)			\

ifeq ($(OPMODE) , aarch32)
CFLAGS			+= -msoft-float				\
			-mstructure-size-boundary=32
endif

ifeq ($(OPMODE) , aarch64)
ASFLAG			+= -march=$(ARCH) -mcpu=$(CPU)

CFLAGS			+= -mcmodel=small				\
			-march=$(ARCH)
endif

