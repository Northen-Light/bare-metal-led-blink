#include "mmap-regs.h"

extern char _estack;
extern char _end_rodata_;
extern char _start_data_;
extern char _end_data_;
extern char _start_bss_;
extern char _end_bss_;
extern void main();

volatile unsigned int g_ms_ticks = 0;
volatile unsigned int last_press = 0;
volatile unsigned int counter = 0;
volatile unsigned int input_bit_prev = 1;
volatile unsigned int RET_Counter = 0;
volatile unsigned int FET_Counter = 0;

void Reset_Handler(void);
void Hardfault_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);

__attribute__((section(".isr_vector")))
char *vector_table[] = {
  &_estack,
  (char *)Reset_Handler,
  0,
  (char *)Hardfault_Handler,
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
  (char *) SysTick_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  (char *) EXTI0_IRQHandler
};

void Reset_Handler(void) {
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

  SYST_RVR = 8000 - 1;
  SYST_CSR = 0x0;
  SYST_CSR = 0x7;
  
  main();
}

void Hardfault_Handler(void) {
  while(1);
}

void EXTI0_IRQHandler(void) {
  EXTI0_PR = (1 << 0);
  int now = g_ms_ticks;

  if (input_bit_prev == 0 && (GPIOA_IDR & (1 << 0))) RET_Counter++;
  if (input_bit_prev == 1 && (GPIOA_IDR & (1 << 0)) == 0) FET_Counter++;
  input_bit_prev = GPIOA_IDR & (1 << 0);

  /** Its taking sometimes close to 500ms for mechanical 
  input button bouncing to settle **/
  if (now - last_press >= 500) {
    last_press = now;
    GPIOC_ODR ^= (1 << 13);
    counter++;
  }
}

void SysTick_Handler(void) {
  g_ms_ticks++;
}