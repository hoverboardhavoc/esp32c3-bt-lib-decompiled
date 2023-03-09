/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x9e,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    if (7 < param_2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0xa1,*(code **)(_r_plf_funcs_p + 8));
    }
    param_2 = (uint)(byte)(&_LANCHOR2)[param_2];
  }
  return param_2;
}

