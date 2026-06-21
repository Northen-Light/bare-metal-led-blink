#ifndef SYSTICK_H
#define SYSTICK_H

#include "stdint.h"

typedef void (*systick_count0_callback_t)(void);

void systick_init(uint32_t reload_value);
void systick_set_count0_callback(systick_count0_callback_t cb);
void Systick_Handler(void);

#endif