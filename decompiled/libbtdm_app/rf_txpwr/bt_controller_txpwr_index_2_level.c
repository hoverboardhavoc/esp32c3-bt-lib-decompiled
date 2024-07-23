/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
 * Source: libbtdm_app -> rf_txpwr.o -> bt_controller_txpwr_index_2_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint bt_controller_txpwr_index_2_level(uint param_1,uint param_2)

{
  if ((param_1 >> 0x10 & 0xff) == 1) {
    if (0xf < param_2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa0,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    if (7 < param_2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa3,*(code **)(_r_plf_funcs_p + 8));
    }
    param_2 = (uint)(byte)(&_LANCHOR2)[param_2];
  }
  return param_2;
}

