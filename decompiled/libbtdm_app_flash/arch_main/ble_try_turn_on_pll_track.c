/*
 * Last changed at upstream commit 4c16da1a1a76b439e2cf981d2f915d94df364e58
 * https://github.com/espressif/esp32c3-bt-lib/commit/4c16da1a1a76b439e2cf981d2f915d94df364e58
 * Upstream date: 2024-12-16 11:11:02 +0800
 * Upstream subject: fix(bt): Fixed that the resolvable private address does not change when light sleep is enabled(6bca137)
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
  uVar2 = pll_track_state - DAT_00011940 & 0xfffffff;
  uVar1 = 0;
  DAT_0001193c = extraout_a1;
  if ((uVar2 < 0x8000001) && (0xc80 < uVar2)) {
    DAT_00011940 = pll_track_state;
    bt_track_pll_cap(0);
    uVar1 = 1;
  }
  return uVar1;
}

