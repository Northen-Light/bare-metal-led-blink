#include "systick.h"
#include "mmap-regs.h"

static systick_count0_callback_t count0_callback = 0;

void systick_init(uint32_t reload_value) {
  SYST_RVR = reload_value;
  SYST_CVR = 0;
  SYST_CSR = 7;
}

void systick_set_count0_callback(systick_count0_callback_t cb) {
  count0_callback = cb;
}

void Systick_Handler() {
  if (count0_callback) {
    count0_callback();
  }
}