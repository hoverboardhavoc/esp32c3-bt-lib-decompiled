/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_multi_antena.o -> r_bt_rma_apply_rule_cs_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_bt_rma_apply_rule_cs_idx(uint param_1,byte *param_2,byte *param_3)

{
  code cVar1;
  
  if (((param_1 < 0xc) && (g_rma_rule_db != '\0')) &&
     (cVar1 = r_sdk_config_get_opts[param_1], (char)cVar1 < '\0')) {
    if (param_2 != (byte *)0x0) {
      *param_2 = (byte)cVar1 >> 2 & 3;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = (byte)cVar1 & 3;
    }
    return 1;
  }
  return 0;
}

