#include "mmap-regs.h"

void delay();

void main(void) {
  RCC_APB2ENR |= (1 << 4);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  while(1) {
    delay();
    GPIOC_ODR ^= (1 << 13);
  }
}

void delay(void) {
  for (int i = 0; i < 1000000; i++);
}