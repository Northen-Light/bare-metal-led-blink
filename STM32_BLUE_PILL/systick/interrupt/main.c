#include "mmap-regs.h"

void main(void) {
  RCC_APB2ENR |= (1 << 4);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  SYST_RVR = 8000000 - 1;
  SYST_CVR = 0;
  SYST_CSR = 7;

  while(1);
}
