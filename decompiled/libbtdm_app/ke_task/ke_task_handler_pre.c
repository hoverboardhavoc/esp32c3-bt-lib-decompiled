/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> ke_task.o -> ke_task_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ke_task_handler_pre(int param_1)

{
  if (*(short *)(param_1 + 4) == 0x209) {
    lld_init_end_ind_pre_handler
              (0x209,param_1 + 0xc,*(undefined2 *)(param_1 + 6),*(undefined2 *)(param_1 + 8));
    return;
  }
  return;
}

