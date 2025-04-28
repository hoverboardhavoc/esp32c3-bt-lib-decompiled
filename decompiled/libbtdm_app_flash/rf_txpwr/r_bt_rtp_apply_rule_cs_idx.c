/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> r_bt_rtp_apply_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_bt_rtp_apply_rule_cs_idx(uint param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 0xc) {
    uVar1 = 0;
    if (((g_rtp_rule_db != '\0') && ((char)r_sdk_cfg_priv_opts_ext_get[param_1] < '\0')) &&
       (uVar1 = 1, param_2 != (byte *)0x0)) {
      *param_2 = (byte)r_sdk_cfg_priv_opts_ext_get[param_1] & 0x7f;
      return uVar1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

