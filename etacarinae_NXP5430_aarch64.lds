OUTPUT_FORMAT("elf64-littleaarch64", "elf64-littleaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(Startup)

;MEMORY {
;    ROM (rx): ORIGIN = 0x50000000, LENGTH = 0x10000
;    RAM (rwx): ORIGIN = 0x60000000, LENGTH = 0x34000
;}
SECTIONS
{
	. = 0x50000000;
	. = ALIGN(4096);
	.text :
	{
		obj/startup_aarch64.o	(.text)
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

