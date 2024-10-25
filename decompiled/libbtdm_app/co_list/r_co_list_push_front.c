/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> co_list.o -> r_co_list_push_front
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_co_list_push_front(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"co_list.c",0x9d,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*param_1 == 0) {
    param_1[1] = (int)param_2;
  }
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  return;
}

