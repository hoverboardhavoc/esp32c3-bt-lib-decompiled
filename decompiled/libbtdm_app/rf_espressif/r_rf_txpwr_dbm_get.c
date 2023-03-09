/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rf_espressif.o -> r_rf_txpwr_dbm_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_rf_txpwr_dbm_get(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x3c0))(*(code **)(_r_modules_funcs_p + 0x3c0));
  return *(undefined1 *)(*(int *)(iVar1 + 8) + param_1);
}

