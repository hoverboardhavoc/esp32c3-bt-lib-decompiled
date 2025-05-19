/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> rf_coexist.o -> r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack
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
    iVar1 = r_sdk_config_get_opts_ext(0);
    return *(char *)(iVar1 + 10) == '\x01';
  }
  return false;
}

