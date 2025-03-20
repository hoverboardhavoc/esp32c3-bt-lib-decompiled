/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> arch_main.o -> ble_try_turn_on_pll_track
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_try_turn_on_pll_track(void)

{
  undefined4 uVar1;
  undefined4 extraout_a1;
  uint uVar2;
  
  pll_track_state = r_rwip_time_get();
  uVar2 = pll_track_state - DAT_00011a38 & 0xfffffff;
  uVar1 = 0;
  DAT_00011a34 = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_00011a38 = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

