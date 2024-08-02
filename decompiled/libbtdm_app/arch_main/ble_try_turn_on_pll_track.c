/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
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
  uVar2 = pll_track_state - DAT_0001189c & 0xfffffff;
  uVar1 = 0;
  DAT_00011898 = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_0001189c = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

