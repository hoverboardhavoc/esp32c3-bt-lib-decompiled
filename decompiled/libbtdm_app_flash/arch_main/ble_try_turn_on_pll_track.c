/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
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
  uVar2 = pll_track_state - DAT_000120f8 & 0xfffffff;
  uVar1 = 0;
  DAT_000120f4 = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_000120f8 = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

