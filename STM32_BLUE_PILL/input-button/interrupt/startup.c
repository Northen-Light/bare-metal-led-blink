#include "mmap-regs.h"

extern int _estack;
extern void main();
extern void toggle_pc13();

void Reset_Handler();
void Hardfault_Handler();
void EXTI0_IRQHandler();

__attribute__((section(".isr_vector")))
int *vector_table[] = {
  &_estack,
  (int *)Reset_Handler,
  0,
  (int *)Hardfault_Handler,
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
  (int *) EXTI0_IRQHandler
};

void Reset_Handler() {
  main();
}

void Hardfault_Handler() {
  while(1);
}

void EXTI0_IRQHandler() {
  EXTI0_PR = (1 << 0);
  toggle_pc13();
}