/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> rf_coexist.o -> r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get(void)

{
  int iVar1;
  
  if ((_bt_rf_coex_cfg_p != 0) && (*(int *)(_bt_rf_coex_cfg_p + 0x44) != 0)) {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(0,*(code **)(_r_plf_funcs_p + 0xf0));
    return *(char *)(iVar1 + 10) == '\x01';
  }
  return false;
}

