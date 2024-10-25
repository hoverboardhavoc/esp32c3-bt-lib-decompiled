/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> arch_main.o -> btdm_gpio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_gpio_init(undefined1 *param_1,uint param_2)

{
  _DAT_60031304 = _DAT_60031304 | 0xffff0000;
  if (param_2 == 0) {
    return;
  }
  gpio_matrix_out(*param_1,0x6b,0,0);
  if (((1 < param_2) && (gpio_matrix_out(param_1[1],0x6c,0,0), param_2 != 2)) &&
     (gpio_matrix_out(param_1[2],0x6a,0,0), param_2 != 3)) {
    gpio_matrix_out(param_1[3],0x71,0,0);
    return;
  }
  return;
}

