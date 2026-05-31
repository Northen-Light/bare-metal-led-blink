MEMORY {
  FLASH : ORIGIN = 0x00000000, LENGTH = 256K
  RAM : ORIGIN = 0x20000000, LENGTH = 64K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
  .text : {
    *(.isr_vector)
    *(.text)
    *(.rodata)
  } > FLASH

  .data : {
    *(.data)
  } > RAM
 
  .bss : {
    *(.bss)
  } > RAM
}