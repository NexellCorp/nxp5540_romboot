OUTPUT_FORMAT("elf64-littleaarch64", "elf64-littleaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(Startup)

SECTIONS
{
	. = 0x50000000;
	. = ALIGN(4);
	.text :
	{
		obj/startup_aarch64_NXP5430.o	(.text)
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
    ASSERT( . < 0x50010000, "*E, Bianry Must be smaller than 64KB")
}

