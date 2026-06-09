#define RCGC_GPIO *((volatile unsigned int*) 0x400FE108)
#define GPIOF_DATA *((volatile unsigned int*) 0x400253FC)
#define GPIOF_DEN *((volatile unsigned int*) 0x4002551C)
#define GPIOF_DIR *((volatile unsigned int*) 0x40025400)

#define STCTRL *((volatile unsigned int*) 0xE000E010)
#define STRELOAD *((volatile unsigned int*) 0xE000E014)
#define STCURRENT *((volatile unsigned int*) 0xE000E018)


void main() {
  RCGC_GPIO |= (1 << 5);
  GPIOF_DIR |= (1 << 3);
  GPIOF_DEN |= (1 << 3);

  
  STRELOAD = 16000000 - 1; 
  STCURRENT = 0;
  STCTRL = 7;
  while(1);
}

void toggle_gpiof_data() {
  GPIOF_DATA ^= (1 << 3);
}

