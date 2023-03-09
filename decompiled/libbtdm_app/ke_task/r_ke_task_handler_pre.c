/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
              (0x209,param_1 + 0xc,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8));
    return;
  }
  return;
}

