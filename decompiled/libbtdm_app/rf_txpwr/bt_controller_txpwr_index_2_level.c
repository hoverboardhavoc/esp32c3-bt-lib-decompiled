/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x99,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else {
    if (7 < param_2) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x9c,*(code **)(_r_plf_funcs_p + 8));
    }
    param_2 = (uint)(byte)(&_LANCHOR1)[param_2];
  }
  return param_2;
}

