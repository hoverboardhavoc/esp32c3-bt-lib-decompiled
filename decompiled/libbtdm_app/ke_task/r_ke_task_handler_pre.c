/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_task_handler_pre(int param_1)

{
  if (*(short *)(param_1 + 4) == 0x209) {
    lld_init_end_ind_pre_handler
              (param_1 + 0xc,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8));
    return;
  }
  return;
}

