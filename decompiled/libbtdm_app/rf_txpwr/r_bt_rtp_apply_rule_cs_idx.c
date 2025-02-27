/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_apply_rule_cs_idx
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
    if (((g_rtp_rule_db != '\0') && ((char)*(byte *)(param_1 + 0x11024) < '\0')) &&
       (uVar1 = 1, param_2 != (byte *)0x0)) {
      *param_2 = *(byte *)(param_1 + 0x11024) & 0x7f;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

