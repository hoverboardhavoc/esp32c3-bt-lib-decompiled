/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> co_list.o -> r_co_list_push_back_sublist
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_co_list_push_back_sublist(int *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 == 0) {
    r_assert_err(0,"co_list.c",0x74);
  }
  if (param_3 == (undefined4 *)0x0) {
    r_assert_err(0,"co_list.c",0x75);
  }
  if (*param_1 == 0) {
    *param_1 = param_2;
  }
  else {
    *(int *)param_1[1] = param_2;
  }
  param_1[1] = (int)param_3;
  *param_3 = 0;
  return;
}

