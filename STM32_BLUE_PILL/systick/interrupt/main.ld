MEMORY {
  FLASH : ORIGIN = 0x08000000, LENGTH = 128K,
  SRAM : ORIGIN = 0x20000000, LENGTH = 20K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS {
  .text : {
    *(.isr_vector)
    *(.text)
  } > FLASH
  
  .rodata : {
    *(.rodata)
  } > FLASH
  
  .data : {
    *(.data)
  } > SRAM

  .bss : {
    *(.bss)
  } > SRAM
}