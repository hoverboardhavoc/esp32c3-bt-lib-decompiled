/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> task.o -> btdm_vnd_offload_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void btdm_vnd_offload_process(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_vnd_ol_funcs)(param_2);
    return;
  }
  return;
}

