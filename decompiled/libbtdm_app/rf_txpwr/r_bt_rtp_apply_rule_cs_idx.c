/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
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

