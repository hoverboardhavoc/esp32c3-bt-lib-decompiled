/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_get_txpwr_idx_by_act_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_bt_rtp_get_txpwr_idx_by_act_hack(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_11 [5];
  
  auStack_11[0] = 0;
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x204))
                    (param_2,auStack_11,*(code **)(_r_modules_funcs_p + 0x204));
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(_r_modules_funcs_p + 0x1f8))
                        (param_1,auStack_11,*(code **)(_r_modules_funcs_p + 0x1f8)), iVar1 == 0)) {
    auStack_11[0] = sdk_cfg_derived_opts;
  }
  return auStack_11[0];
}

