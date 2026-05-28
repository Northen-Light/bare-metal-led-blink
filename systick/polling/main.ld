MEMORY {
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256k
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64k
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
