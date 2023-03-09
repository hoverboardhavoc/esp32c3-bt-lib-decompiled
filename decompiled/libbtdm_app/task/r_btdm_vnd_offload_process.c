/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> task.o -> r_btdm_vnd_offload_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_btdm_vnd_offload_process(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001025a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*btdm_ol_task_env)(param_2);
    return;
  }
  return;
}

