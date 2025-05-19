/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_get_txpwr_idx_by_act_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 r_bt_rtp_get_txpwr_idx_by_act_hack(undefined4 param_1,undefined4 param_2)

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

