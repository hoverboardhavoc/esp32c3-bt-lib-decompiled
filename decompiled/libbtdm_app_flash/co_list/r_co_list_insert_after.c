/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> co_list.o -> r_co_list_insert_after
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_co_list_insert_after(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_3 == (int *)0x0) {
    r_assert_err(0,"co_list.c",0x1ac);
  }
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    while( true ) {
      if (piVar1 == param_2) {
        iVar2 = *param_2;
        if (iVar2 == 0) {
          param_1[1] = (int)param_3;
        }
        *param_3 = iVar2;
        *param_2 = (int)param_3;
        return;
      }
      if (piVar1 == (int *)0x0) break;
      piVar1 = (int *)*piVar1;
    }
  }
  if (param_3 == (int *)0x0) {
    r_assert_err(0,"co_list.c",0x56);
  }
  if (*param_1 == 0) {
    *param_1 = (int)param_3;
  }
  else {
    *(int **)param_1[1] = param_3;
  }
  param_1[1] = (int)param_3;
  *param_3 = 0;
  return;
}

