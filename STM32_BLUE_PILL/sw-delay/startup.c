extern void main();
extern int _estack;

void Reset_Handler();
void Hardfault_Handler();

__attribute__((section(".isr_vector")))
int *vector_table[] = {
  &_estack,
  (int *)Reset_Handler,
  0,
  (int *)Hardfault_Handler
};

void Reset_Handler() {
  main();
}

void Hardfault_Handler() {
  while(1);
}