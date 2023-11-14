OUTPUT_ARCH(powerpc)
ENTRY(entry)

MEMORY {
  TEXT_MEM : ORIGIN = 0x01800000, LENGTH = 0x10000000
}

SECTIONS {
  .text :
  {
    *(.entry)
    *(.text.*)
    *(.gcc_except_table)
    *(.gcc_except_table.*)
    *(.sdata)
    *(.sdata.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
    *(.bss.*)
    *(.sbss)
    *(.sbss.*)
    *(.data)
    *(.data.*)
    *(.ext)
    *(.ext.*)
    data_end = .;
  } > TEXT_MEM
}