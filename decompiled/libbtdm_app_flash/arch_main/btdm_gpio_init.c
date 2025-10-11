/*
 * Last changed at upstream commit 42c965137ecc3c6cf3d38ecece7ce71ffc461353
 * https://github.com/espressif/esp32c3-bt-lib/commit/42c965137ecc3c6cf3d38ecece7ce71ffc461353
 * Upstream date: 2025-10-11 11:01:59 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(18b5cbe)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_gpio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * btdm_gpio_init(undefined1 *param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_2 == 0) {
    return param_1;
  }
  puVar1 = (undefined1 *)btdm_gpio_matrix_out(*param_1,0x6b,0,0);
  if ((((param_2 != 1) &&
       (puVar1 = (undefined1 *)btdm_gpio_matrix_out(param_1[1],0x6c,0,0), param_2 != 2)) &&
      (puVar1 = (undefined1 *)btdm_gpio_matrix_out(param_1[2],0x6a,0,0), param_2 != 3)) &&
     (puVar1 = (undefined1 *)btdm_gpio_matrix_out(param_1[3],0x69,0,0), param_2 != 4)) {
    return (undefined1 *)(uint)(byte)param_1[4];
  }
  return puVar1;
}

