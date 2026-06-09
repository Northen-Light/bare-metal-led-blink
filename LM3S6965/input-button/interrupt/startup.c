#include "mmap-regs.h"

extern void main();
extern int _estack;

void Reset_Handler();
void HardFault_Handler();
void GPIOF_Handler();

__attribute__((section(".isr_vector")))
int *vector_table[] = {
  &_estack,
  (int *)Reset_Handler,
  0,
  (int *)HardFault_Handler,
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
  0,
  0,
  (int *) GPIOF_Handler,
};
 
void Reset_Handler() {
  main();
}

void HardFault_Handler() {
  while(1);
}

void GPIOF_Handler() {
  GPIOF_IC |= (1 << 4);
  GPIOF_DATA ^= (1 << 3);
}