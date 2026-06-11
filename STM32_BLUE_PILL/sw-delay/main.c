#include "mmap-regs.h"

void delay();

void main(void) {
  RCC_APB2ENR |= (1 << 4);
  RCC_APB2ENR |= (1 << 3);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);
  GPIOC_ODR |= (1 << 13);

  GPIOC_CRH &= ~(0xF << 24);
  GPIOC_CRH |= (2 << 24);
  GPIOC_ODR |= (1 << 14);

  GPIOB_CRL &= ~(0xF << 20);
  GPIOB_CRL |= (0x2 << 20);
  GPIOB_ODR |= (1 << 5);

  GPIOB_CRH &= ~(0xF << 20);
  GPIOB_CRH |= (0x2 << 20);
  GPIOB_ODR |= (1 << 13);

  while(1) {
    delay();
    GPIOC_ODR ^= (1 << 13);
    delay();
    GPIOB_ODR ^= (1 << 5);
    delay();
    GPIOB_ODR ^= (1 << 13);
    delay();  
    GPIOC_ODR ^= (1 << 14);
  }
}

void delay(void) {
  for (int i = 0; i < 100000; i++);
}