/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> bt_controller_txpwr_index_2_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bt_controller_txpwr_index_2_level(uint param_1,uint param_2)

{
  if ((param_1 >> 0x10 & 0xff) == 1) {
    if (0xf < param_2) {
      r_assert_err(0,"rf_txpwr.c",0xa0);
    }
  }
  else {
    if (7 < param_2) {
      r_assert_err(0,"rf_txpwr.c",0xa3);
    }
    param_2 = (uint)*(byte *)((int)&cs_bt_pwr_tbl_idx2lvl_fpga + param_2);
  }
  return param_2;
}

