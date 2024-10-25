/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> co_list.o -> r_co_list_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short r_co_list_size(int *param_1)

{
  short sVar1;
  
  sVar1 = 0;
  for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    sVar1 = sVar1 + 1;
  }
  return sVar1;
}

