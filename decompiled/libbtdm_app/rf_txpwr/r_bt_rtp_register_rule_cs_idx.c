/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app -> rf_txpwr.o -> r_bt_rtp_register_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_bt_rtp_register_rule_cs_idx(uint param_1,byte param_2)

{
  int iVar1;
  
  if (param_1 < 0xc) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    iVar1 = _r_osi_funcs_p;
    if (-1 < *(char *)(param_1 + 0x11024)) {
      g_rtp_rule_db = g_rtp_rule_db + '\x01';
    }
    *(byte *)(param_1 + 0x11024) = param_2 | 0x80;
    (**(code **)(iVar1 + 0x18))(*(code **)(iVar1 + 0x18));
    return 1;
  }
  return 0;
}

