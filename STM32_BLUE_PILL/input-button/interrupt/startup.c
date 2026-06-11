#include "mmap-regs.h"

extern int _estack;
extern char _end_rodata_;
extern char _start_data_;
extern char _end_data_;
extern char _start_bss_;
extern char _end_bss_;
extern void main();

void Reset_Handler();
void Hardfault_Handler();
void EXTI0_IRQHandler();

volatile int count = 0;

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
  char *end_rodata = &_end_rodata_;
  char *start_data = &_start_data_;
  char *end_data = &_end_data_;

  while (start_data != end_data) {
    *start_data = *end_rodata;
    start_data++;
    end_rodata++;
  }

  char *start_bss = &_start_bss_;
  char *end_bss = &_end_bss_;

  while (start_bss != end_bss) {
    *start_bss = 0;
    start_bss++;
  }
  
  main();
}

void Hardfault_Handler() {
  while(1);
}

void EXTI0_IRQHandler() {
  EXTI0_PR = (1 << 0);
  GPIOC_ODR ^= (1 << 13);
  count++;
}