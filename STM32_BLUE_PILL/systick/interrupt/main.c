#include "mmap-regs.h"
#include "systick.h"

void toggle_GPIO_PC13_bit();

void main(void) {
  RCC_APB2ENR |= (1 << 4);

  GPIOC_CRH &= ~(0xF << 20);
  GPIOC_CRH |= (2 << 20);

  systick_set_count0_callback(toggle_GPIO_PC13_bit);
  systick_init(8000000 - 1);
  
  while(1);
}

void toggle_GPIO_PC13_bit() {
  GPIOC_ODR ^= (1 << 13);
}
