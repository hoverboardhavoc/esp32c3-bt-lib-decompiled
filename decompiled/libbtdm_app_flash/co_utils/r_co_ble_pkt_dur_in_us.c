/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> co_utils.o -> r_co_ble_pkt_dur_in_us
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_co_ble_pkt_dur_in_us(int param_1,uint param_2)

{
  if (param_2 == 2) {
    return param_1 * 0x40 + 0x2d0;
  }
  if (param_2 < 3) {
    if (param_2 == 0) {
      return (param_1 + 10) * 8;
    }
    return (param_1 + 0xb) * 4;
  }
  if (param_2 != 3) {
    r_assert_param(0x10000,0x286);
    return 0;
  }
  return param_1 * 0x10 + 0x1ce;
}

