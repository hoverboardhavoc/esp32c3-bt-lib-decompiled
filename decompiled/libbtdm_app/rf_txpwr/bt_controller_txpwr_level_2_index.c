/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    (**(code **)(_r_plf_funcs_p + 8))(0,"rf_txpwr.c",0x91,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = param_2 & 0xff;
  if ((param_1 & 0xff0000) != 0x10000) {
    uVar1 = (uint)(byte)cs_bt_pwr_tbl_lvl2idx_fpga[param_2 & 0xff];
  }
  return uVar1;
}

