/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_espressif.o -> r_rw_rf_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_rf_init(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0));
  iVar1 = _r_modules_funcs_p;
  param_1[9] = *(undefined4 *)(_r_modules_funcs_p + 0x210);
  param_1[10] = *(undefined4 *)(iVar1 + 0x214);
  param_1[5] = *(undefined4 *)(iVar1 + 0x228);
  *(undefined1 *)(param_1 + 0xc) = *puVar2;
  *(undefined1 *)((int)param_1 + 0x31) = puVar2[1];
  param_1[0xb] = *(undefined4 *)(iVar1 + 0x220);
  *param_1 = *(undefined4 *)(iVar1 + 0x218);
  param_1[8] = *(undefined4 *)(iVar1 + 0x21c);
  uVar3 = *(undefined4 *)(iVar1 + 0x208);
  param_1[6] = *(undefined4 *)(iVar1 + 0x224);
  param_1[7] = uVar3;
  pcVar4 = *(code **)(iVar1 + 0x1e4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x1e8);
  (*pcVar4)(pcVar4);
  if (2 < _g_bt_plf_log_level) {
    ets_printf("%s initialise RF LC Todd\n","r_rw_rf_init");
  }
  _DAT_60031078 = _DAT_60031078 & 0xffff0000 | 0x100;
  (**(code **)(_r_modules_funcs_p + 0x1b8))(*(code **)(_r_modules_funcs_p + 0x1b8));
  bt_rf_coex_hook_register();
  return;
}

