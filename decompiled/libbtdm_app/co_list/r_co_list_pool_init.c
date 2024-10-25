/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> co_list.o -> r_co_list_pool_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_co_list_pool_init(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  
  *param_1 = (int)param_2;
  piVar1 = param_2;
  for (uVar2 = 0; uVar2 < param_4 - 1U; uVar2 = uVar2 + 1) {
    *piVar1 = (int)piVar1 + param_3;
    piVar1 = (int *)((int)piVar1 + param_3);
  }
  param_2 = (int *)((int)param_2 + (param_4 - 1U) * param_3);
  *param_2 = 0;
  param_1[1] = (int)param_2;
  return;
}

