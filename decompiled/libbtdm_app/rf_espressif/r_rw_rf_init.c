/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  code *pcVar2;
  
  iVar1 = _r_modules_funcs_p;
  param_1[9] = *(undefined4 *)(_r_modules_funcs_p + 0x210);
  param_1[10] = *(undefined4 *)(iVar1 + 0x214);
  param_1[5] = *(undefined4 *)(iVar1 + 0x228);
  *(undefined2 *)(param_1 + 0xc) = _g_rf_pwr_tbl_desc;
  param_1[0xb] = *(undefined4 *)(iVar1 + 0x220);
  *param_1 = *(undefined4 *)(iVar1 + 0x218);
  param_1[8] = *(undefined4 *)(iVar1 + 0x21c);
  param_1[6] = *(undefined4 *)(iVar1 + 0x224);
  param_1[7] = *(undefined4 *)(iVar1 + 0x208);
  pcVar2 = *(code **)(iVar1 + 0x1e4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x1e8);
  (*pcVar2)(pcVar2);
  if (2 < _g_bt_plf_log_level) {
    ets_printf("%s initialise RF LC Todd\n","r_rw_rf_init");
  }
  _DAT_60031078 = _DAT_60031078 & 0xffff0000 | 0x100;
  (**(code **)(_r_modules_funcs_p + 0x1b8))(*(code **)(_r_modules_funcs_p + 0x1b8));
  bt_rf_coex_hook_register();
  return;
}

