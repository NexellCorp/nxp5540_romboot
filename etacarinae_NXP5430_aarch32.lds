OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(Vectors)

SECTIONS
{
	. = 0x50000000;
	. = ALIGN(4);
	.text :
	{
		obj/startup_aarch32_NXP5430.o	(.text)
		*(.text)
	}

	. = ALIGN(4);
	.rodata : { *(.rodata) }

	. = ALIGN(4);
	.data : { *(.data) }

	. = ALIGN(4);
	.got : { *(.got) }

	end = .;

    . = ALIGN(4);
    .bss :
    {
		__bss_start__ = ABSOLUTE (.);
		__bss_end__ = ABSOLUTE (.);
	}

	_end = .;
}

