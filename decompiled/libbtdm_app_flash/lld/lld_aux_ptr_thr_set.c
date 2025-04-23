/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_aux_ptr_thr_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_aux_ptr_thr_set(uint param_1,uint param_2)

{
  if ((param_1 < 0xff1) && (param_2 < 0xff1)) {
    if (param_1 != 0) {
      _DAT_60031120 = (param_1 >> 4) << 0x18 | _DAT_60031120 & 0xffffff;
    }
    if (param_2 != 0) {
      _DAT_60031120 = (param_2 >> 4) << 0x10 | _DAT_60031120 & 0xff00ffff;
    }
    return 0;
  }
  return 0x12;
}

