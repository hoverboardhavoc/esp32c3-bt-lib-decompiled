/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> bt_controller_txpwr_level_2_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bt_controller_txpwr_level_2_index(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (0xf < param_2) {
    r_assert_err(0,"rf_txpwr.c",0x91);
  }
  uVar1 = param_2 & 0xff;
  if ((param_1 >> 0x10 & 0xff) != 1) {
    uVar1 = (uint)(byte)(&_LANCHOR1)[param_2 & 0xff];
  }
  return uVar1;
}

