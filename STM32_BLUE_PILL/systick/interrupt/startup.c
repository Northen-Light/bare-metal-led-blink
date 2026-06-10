#include "mmap-regs.h"

extern void main();
extern int _estack;

void Reset_Handler();
void Hardfault_Handler();
void Systick_Handler();

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
  (int *)Systick_Handler
};

void Reset_Handler() {
  main();
}

void Hardfault_Handler() {
  while(1);
}

void Systick_Handler() {
  GPIOC_ODR ^= (1 << 13);
}