#include "mmap-regs.h"

void main() {
  // Enable clock for Port F
  RCGC_GPIO |= (1 << 5);

  // PF3 -> OUTPUT (LED)
  GPIOF_DIR |= (1 << 3);
  GPIOF_DEN |= (1 << 3);

  // PF4 -> INPUT (BUTTON)
  GPIOF_DIR &= ~(1 << 4);
  GPIOF_DEN |= (1 << 4);

  // GPIOF INTERUPPT CONFIGURATION
  GPIOF_IS &= ~(1 << 4);
  GPIOF_IBE &= ~(1 << 4);
  GPIOF_IEV &= ~(1 << 4);
  GPIOF_IC |= (1 << 4);
  GPIOF_IM |= (1 << 4);

  // Enable GPIOF interrupt in NVIV (IRQ30)
  NVIC_EN0 |= (1 << 30);
  while(1) {
    NVIC_ISPR0 |= (1 << 30);
  }
}