#define RCC_APB2ENR     *((volatile unsigned int *) 0x40021018)
#define GPIOC_CRH       *((volatile unsigned int *) 0x40011004)
#define GPIOC_ODR       *((volatile unsigned int *) 0x4001100C)

#define SYST_CSR        *((volatile unsigned int *) 0xE000E010)
#define SYST_RVR        *((volatile unsigned int *) 0xE000E014)
#define SYST_CVR        *((volatile unsigned int *) 0xE000E018)