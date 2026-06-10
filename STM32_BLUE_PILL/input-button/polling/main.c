#include "mmap-regs.h"

void main(void) {
  RCC_APB2ENR |= (1 << 4);
  RCC_APB2ENR |= (1 << 2);

  GPIOA_CRL &= ~(0xF << 0); 
  GPIOA_CRL = (0x8 << 0);
  GPIOA_ODR |= (1 << 0);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  while (1) {
    if (GPIOA_IDR & (1 << 0)) {
      GPIOC_ODR &= ~(1 << 13);
    } else {
      GPIOC_ODR |= (1 << 13);
    }
  }
}
