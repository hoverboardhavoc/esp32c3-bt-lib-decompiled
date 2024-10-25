/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_get_txpwr_idx_by_act
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 r_bt_rtp_get_txpwr_idx_by_act(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_11 [9];
  
  auStack_11[0] = 0;
  iVar1 = r_bt_rtp_apply_rule_cs_idx(param_2,auStack_11);
  if ((iVar1 == 0) && (iVar1 = r_bt_rtp_apply_rule_cs_fmt(param_1,auStack_11), iVar1 == 0)) {
    iVar1 = r_sdk_cfg_priv_opts_ext_get();
    auStack_11[0] = *(undefined1 *)(iVar1 + 1);
  }
  return auStack_11[0];
}

