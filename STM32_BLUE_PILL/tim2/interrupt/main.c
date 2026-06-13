#include "mmap-regs.h"

void main(void) {
  RCC_APB2ENR |= (1 << 4);
  RCC_APB1ENR |= (1 << 0);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (0x2 << 20);

  TIM2_PSC = 7999;
  TIM2_ARR = 99;
  TIM2_DIER |= (1 << 0);
  NVIC_ISER0 |= (1 << 28);
  TIM2_CR1 |= (1 << 0);

  while(1);
}