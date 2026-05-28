#define RCGC_GPIO *((volatile unsigned int*) 0x400FE108)
#define GPIOF_DATA *((volatile unsigned int*) 0x400253FC)
#define GPIOF_DEN *((volatile unsigned int*) 0x4002551C)
#define GPIOF_DIR *((volatile unsigned int*) 0x40025400)

void delay();

void main() {
  RCGC_GPIO |= (1 << 5);
  GPIOF_DIR |= (1 << 3);
  GPIOF_DEN |= (1 << 3);
  while(1) {
    GPIOF_DATA ^= (1 << 3);
    delay();  
  }
}

void delay() {
  for (int i = 0; i < 1000000; i++);
}
