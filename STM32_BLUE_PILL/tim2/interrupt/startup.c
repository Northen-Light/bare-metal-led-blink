#include "mmap-regs.h"

extern void main(void);
extern char _estack;

void Reset_Handler(void);
void HardFault_Handler(void);
void TIM2_IRQHandler(void);

__attribute__((section(".isr_vector")))
char *vector_table[] = {
  &_estack,
  (char *) Reset_Handler,
  0,
  (char *) HardFault_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  (char *) TIM2_IRQHandler,
};

void Reset_Handler(void) {
  main();
}

void HardFault_Handler(void) {
  while(1);
}

void TIM2_IRQHandler(void) {
  TIM2_SR &= ~(1 << 0);
  GPIOC_ODR ^= (1 << 13);
}