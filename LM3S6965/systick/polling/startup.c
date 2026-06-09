extern int _estack;
extern void main();

void reset_handler();
void hard_fault_handler();

__attribute((section(".isr_vector")))
int *vector_table[] = {
  &_estack,
  (int *)reset_handler,
  0, 
  (int *) hard_fault_handler
};

void reset_handler() {
  main();
}

void hard_fault_handler() {
  while(1);
}
