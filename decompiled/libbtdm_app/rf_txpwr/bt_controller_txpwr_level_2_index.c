/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
 * Source: libbtdm_app -> rf_txpwr.o -> bt_controller_txpwr_level_2_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint bt_controller_txpwr_level_2_index(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (0xf < param_2) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x8f,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = param_2 & 0xff;
  if ((param_1 >> 0x10 & 0xff) != 1) {
    uVar1 = (uint)(byte)(&_LANCHOR1)[param_2 & 0xff];
  }
  return uVar1;
}

