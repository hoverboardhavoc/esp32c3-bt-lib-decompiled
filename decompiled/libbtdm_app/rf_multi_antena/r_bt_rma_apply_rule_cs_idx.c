/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_multi_antena.o -> r_bt_rma_apply_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_bt_rma_apply_rule_cs_idx(uint param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_1 < 0xc) {
    uVar2 = 0;
    if ((g_rma_rule_db != '\0') && (bVar1 = (&r_plf_funcs_p)[param_1], (char)bVar1 < '\0')) {
      if (param_2 != (byte *)0x0) {
        *param_2 = bVar1 >> 2 & 3;
      }
      uVar2 = 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = bVar1 & 3;
        return uVar2;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

