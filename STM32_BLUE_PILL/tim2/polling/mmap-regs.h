#define RCC_APB2ENR       *((volatile unsigned int *)0x40021018)
#define RCC_APB1ENR       *((volatile unsigned int *)0x4002101C)

#define TIM2_CR1          *((volatile unsigned int *)0x40000000)
#define TIM2_SR           *((volatile unsigned int *)0x40000010)
#define TIM2_PSC          *((volatile unsigned int *)0x40000028)
#define TIM2_ARR          *((volatile unsigned int *)0x4000002C)

#define GPIOC_CRH         *((volatile unsigned int *)0x40011004)
#define GPIOC_ODR         *((volatile unsigned int *)0x4001100C)
