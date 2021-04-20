/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_coexist.o -> r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack(void)

{
  int iVar1;
  
  if ((_bt_rf_coex_cfg_p != 0) && (*(int *)(_bt_rf_coex_cfg_p + 0x44) != 0)) {
    iVar1 = sdk_config_get_opts_ext(0);
    return *(char *)(iVar1 + 10) == '\x01';
  }
  return false;
}

