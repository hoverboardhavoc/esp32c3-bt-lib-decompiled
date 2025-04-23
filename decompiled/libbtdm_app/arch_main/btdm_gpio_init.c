/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_gpio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void btdm_gpio_init(undefined1 *param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  gpio_matrix_out(*param_1,0x6b,0,0);
  if ((((param_2 != 1) && (gpio_matrix_out(param_1[1],0x6c,0,0), param_2 != 2)) &&
      (gpio_matrix_out(param_1[2],0x6a,0,0), param_2 != 3)) &&
     (gpio_matrix_out(param_1[3],0x69,0,0), param_2 != 4)) {
    gpio_matrix_out(param_1[4],0x66,0,0);
    return;
  }
  return;
}

