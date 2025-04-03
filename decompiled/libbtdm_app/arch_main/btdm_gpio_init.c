/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> arch_main.o -> btdm_gpio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void btdm_gpio_init(undefined1 *param_1,uint param_2)

{
  if (param_2 == 0) {
    return;
  }
  gpio_matrix_out(*param_1,0x6b,0,0);
  if ((((1 < param_2) && (gpio_matrix_out(param_1[1],0x6c,0,0), param_2 != 2)) &&
      (gpio_matrix_out(param_1[2],0x6a,0,0), param_2 != 3)) &&
     (gpio_matrix_out(param_1[3],0x69,0,0), param_2 != 4)) {
    gpio_matrix_out(param_1[4],0x66,0,0);
    return;
  }
  return;
}

