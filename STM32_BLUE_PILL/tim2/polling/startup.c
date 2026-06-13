extern void main();
extern char _estack;

void Reset_Handler(void);
void HardFault_Handler(void);

__attribute__((section(".isr_vector")))
char *vector_table[] = {
  &_estack,
  (char *) Reset_Handler,
  0,
  (char *) HardFault_Handler
};

void Reset_Handler(void) {
  main();
}

void HardFault_Handler(void) {
  while(1);
}