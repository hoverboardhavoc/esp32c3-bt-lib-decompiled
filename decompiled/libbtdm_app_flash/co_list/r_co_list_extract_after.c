/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> co_list.o -> r_co_list_extract_after
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_co_list_extract_after(int *param_1,int *param_2,int *param_3)

{
  if (param_1 == (int *)0x0) {
    r_assert_err("co_list.c",0x10f);
  }
  if (param_3 == (int *)0x0) {
    r_assert_err(0,"co_list.c",0x110);
  }
  if (param_2 == (int *)0x0) {
    if ((int *)*param_1 != param_3) {
      r_assert_err(0,"co_list.c",0x115);
    }
    *param_1 = *(int *)*param_1;
  }
  else {
    if ((int *)*param_2 != param_3) {
      r_assert_err(0,"co_list.c",0x11c);
    }
    *param_2 = *param_3;
  }
  if ((int *)param_1[1] == param_3) {
    param_1[1] = (int)param_2;
  }
  return;
}

