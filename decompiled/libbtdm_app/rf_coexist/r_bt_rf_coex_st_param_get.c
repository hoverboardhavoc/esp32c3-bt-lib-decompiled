/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_coexist.o -> r_bt_rf_coex_st_param_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_bt_rf_coex_st_param_get(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0xb) {
    iVar1 = _bt_rf_coex_cfg_p;
    if (_bt_rf_coex_cfg_p != 0) {
      return *(int *)(_bt_rf_coex_cfg_p + param_1 * 4);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

