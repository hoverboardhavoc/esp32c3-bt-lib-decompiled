/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_espressif.o -> r_rw_rf_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_rf_init(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_rf_pwr_tbl_get();
  param_1[9] = 0x10000;
  param_1[10] = r_rf_reg_wr;
  param_1[5] = r_rf_txpwr_dbm_get;
  *(undefined1 *)(param_1 + 0xc) = *puVar1;
  *(undefined1 *)((int)param_1 + 0x31) = puVar1[1];
  param_1[0xb] = r_rf_sleep_hack;
  *param_1 = r_rf_reset;
  param_1[8] = r_rf_rssi_convert;
  param_1[6] = r_rf_txpwr_cs_get;
  param_1[7] = &r_bt_rtp_get_txpwr_idx_by_act;
  param_1[1] = r_rf_force_agc_enable;
  r_rf_em_init();
  if (2 < _g_bt_plf_log_level) {
    ets_printf("%s initialise RF LC Todd\n","r_rw_rf_init");
  }
  _DAT_60031078 = _DAT_60031078 & 0xffff0000 | 0x100;
  r_rf_rw_v9_le_init();
  bt_rf_coex_hook_register();
  return;
}

