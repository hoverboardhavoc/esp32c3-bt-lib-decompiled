/*
 * Last changed at upstream commit 29d5555ca1febeb132f5a13556893f3419d2d640
 * https://github.com/espressif/esp32c3-bt-lib/commit/29d5555ca1febeb132f5a13556893f3419d2d640
 * Upstream date: 2024-06-03 11:12:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(0738a61)
 * Source: libbtdm_app -> rwip.o -> r_rwip_assert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_assert(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (0 < _g_bt_plf_log_level) {
    ets_printf("BLE assert %s %d, param %08x %08x\n",param_1,param_2,param_3,param_4);
    return;
  }
  return;
}

