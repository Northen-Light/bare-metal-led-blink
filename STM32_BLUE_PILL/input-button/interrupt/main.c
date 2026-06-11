#include "mmap-regs.h"
 
void main(void) {
  // Enable clocks for AFIO
  RCC_APB2ENR |= (1 << 0);
  RCC_APB2ENR |= (1 << 4);
  RCC_APB2ENR |= (1 << 2);

  // Config for PA0 as input
  GPIOA_CRL &= ~(0xF << 0); 
  GPIOA_CRL |= (0x8 << 0);
  GPIOA_ODR |= (1 << 0);

  // Config for PC13 as output
  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  // Setting this bit to 1, turns LED off
  GPIOC_ODR |= (1 << 13);

  // EXTI0 config
  AFIO_EXTICR1 &= ~(0xF << 0);
  EXTI0_IMR |= (1 << 0);
  EXTI0_FTSR |= (1 << 0);
  EXTI0_RTSR &= ~(1 << 0);
  // Enable NVIC to accept EXTI0 IRQ6 requests
  NVIC_ISER0 |= (1 << 6);

  while(1);
}
