/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_post_from_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_btdm_vnd_offload_post_from_isr(uint param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 < 2) {
    r_btdm_task_post_from_isr_impl(0xd,param_1 & 0xff,param_2,param_3);
    return 0;
  }
  return 0xffffffff;
}

