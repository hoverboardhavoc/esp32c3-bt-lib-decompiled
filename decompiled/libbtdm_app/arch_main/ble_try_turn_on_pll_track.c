/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
 * Source: libbtdm_app -> arch_main.o -> ble_try_turn_on_pll_track
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_try_turn_on_pll_track(void)

{
  undefined4 uVar1;
  undefined4 extraout_a1;
  uint uVar2;
  
  pll_track_state =
       (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  uVar2 = pll_track_state - DAT_00011830 & 0xfffffff;
  uVar1 = 0;
  DAT_0001182c = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_00011830 = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

