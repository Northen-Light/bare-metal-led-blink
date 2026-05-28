extern int _estack;
extern void main();
extern void toggle_gpiof_data();

void Reset_Handler();
void HardFault_Handler();
void SysTick_Handler();

__attribute((section(".isr_vector")))
int *vector_table[] = {
  &_estack,
  (int *)Reset_Handler,
  0, 
  (int *) HardFault_Handler,
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
  (int*) SysTick_Handler
};

void Reset_Handler() {
  main();
}

void HardFault_Handler() {
  while(1);
}

void SysTick_Handler() {
  toggle_gpiof_data();
}
