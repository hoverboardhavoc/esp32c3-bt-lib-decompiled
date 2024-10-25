/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    param_2 = (uint)(byte)(&_LANCHOR2)[param_2];
  }
  return param_2;
}

