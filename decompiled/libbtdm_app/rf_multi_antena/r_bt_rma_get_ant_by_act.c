/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rf_multi_antena.o -> r_bt_rma_get_ant_by_act
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_bt_rma_get_ant_by_act
               (undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x1dc))
                    (param_2,param_3,param_4,*(code **)(_r_modules_funcs_p + 0x1dc));
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x1d0))
                        (param_1,param_3,param_4,*(code **)(_r_modules_funcs_p + 0x1d0)), iVar1 == 0
     )) {
    if (param_3 != (undefined1 *)0x0) {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      *param_3 = *(undefined1 *)(iVar1 + 0x1c);
    }
    if (param_4 != (undefined1 *)0x0) {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      *param_4 = *(undefined1 *)(iVar1 + 0x1d);
    }
  }
  return;
}

