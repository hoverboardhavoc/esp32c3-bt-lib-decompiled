/*
 * Last changed at upstream commit e651b371c861ba23111db51dd76fd01fc2a69079
 * https://github.com/espressif/esp32c3-bt-lib/commit/e651b371c861ba23111db51dd76fd01fc2a69079
 * Upstream date: 2023-12-13 19:24:11 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(9129dec)
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
  uVar2 = pll_track_state - DAT_000117c8 & 0xfffffff;
  uVar1 = 0;
  DAT_000117c4 = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_000117c8 = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

