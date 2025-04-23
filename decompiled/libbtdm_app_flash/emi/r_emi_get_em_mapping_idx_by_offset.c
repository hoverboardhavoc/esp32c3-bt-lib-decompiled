/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_get_em_mapping_idx_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 r_emi_get_em_mapping_idx_by_offset(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 10 & 0xffff;
  if (0x32 < uVar1) {
    r_assert_param(uVar1,0x10000,0x159);
  }
  return (&em_base_reg_lut)[uVar1 * 4];
}

