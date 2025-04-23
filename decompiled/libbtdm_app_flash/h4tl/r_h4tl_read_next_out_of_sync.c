/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_read_next_out_of_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_read_next_out_of_sync(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 5) = 3;
                    /* WARNING: Could not recover jumptable at 0x00010218. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)((int)param_1 + 0x13,1,r_h4tl_rx_done,param_1,*(code **)*param_1);
  return;
}

