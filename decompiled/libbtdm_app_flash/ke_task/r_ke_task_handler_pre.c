/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_task_handler_pre(int param_1)

{
  if (*(short *)(param_1 + 4) == 0x209) {
    lld_init_end_ind_pre_handler
              (0x209,param_1 + 0xc,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8));
    return;
  }
  return;
}

