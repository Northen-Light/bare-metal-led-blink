#define RCC_APB2ENR     *((volatile unsigned int *) 0x40021018)
#define GPIOC_CRH       *((volatile unsigned int *) 0x40011004)
#define GPIOC_ODR       *((volatile unsigned int *) 0x4001100C)

#define GPIOA_CRL       *((volatile unsigned int *) 0x40010800)
#define GPIOA_IDR       *((volatile unsigned int *) 0x40010808) 
#define GPIOA_ODR       *((volatile unsigned int *) 0x4001080C)

#define AFIO_EXTICR1    *((volatile unsigned int *) 0x40010008)
#define EXTI0_IMR       *((volatile unsigned int *) 0x40010400)
#define EXTI0_FTSR      *((volatile unsigned int *) 0x4001040C)
#define EXTI0_RTSR      *((volatile unsigned int *) 0x40010408)
#define EXTI0_PR        *((volatile unsigned int *) 0x40010414)

#define NVIC_ISER0      *((volatile unsigned int *) 0xE000E100)