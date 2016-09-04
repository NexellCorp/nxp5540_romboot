OUTPUT_FORMAT("elf64-littleaarch64", "elf64-littleaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(Startup)

SECTIONS
{
	. = 0x00000000;
	. = ALIGN(4096);
	.text :
	{
		obj/startup_aarch64.o	(.text)
		*(.text)
	}

	_end = .;
    . = 0x00006000;
    . = ALIGN(4);
    .rodata : {
        obj/NXP5540_pagetable.o(.rodata)
        *(.rodata)
    }

	. = ALIGN(4);
	.data : { *(.data) }
    
	. = ALIGN(4);
	.got : { *(.got) }

	end = .;

    ASSERT( . < 0x8000 , "*E, Bianry Must be smaller than 32KB, in MPW. 20160901 choiyk")
	. = ALIGN(4);
	.bss :
	{
		__bss_start__ = ABSOLUTE (.);
		__bss_end__ = ABSOLUTE (.);
	}

}

