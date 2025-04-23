/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_tx_done(int param_1,int param_2)

{
  if (param_2 != 0) {
    r_assert_err(0,0x10000,0x1e8);
  }
  *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0x24) * 0xc + 0x18) = 0;
  r_ke_event_set(8);
  return;
}

