/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_coexist.o -> r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get
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
    iVar1 = r_sdk_config_get_opts_ext(0);
    return *(char *)(iVar1 + 10) == '\x01';
  }
  return false;
}

