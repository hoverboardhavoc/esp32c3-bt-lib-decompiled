/*
 * Last changed at upstream commit ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * https://github.com/espressif/esp32c3-bt-lib/commit/ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * Upstream date: 2023-10-26 19:39:25 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f817304)
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
  uVar2 = pll_track_state - DAT_000117ac & 0xfffffff;
  uVar1 = 0;
  DAT_000117a8 = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_000117ac = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

