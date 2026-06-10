#include "mmap-regs.h"

void main(void) {
  RCC_APB2ENR |= (1 << 4);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  SYST_RVR = 800000 - 1;
  SYST_CVR = 0;
  SYST_CSR = (1 << 2) | (1 << 0);

  while(1) {
    while ((SYST_CSR & (1 << 16)) == 0);
    GPIOC_ODR ^= (1 << 13);
  }
}
