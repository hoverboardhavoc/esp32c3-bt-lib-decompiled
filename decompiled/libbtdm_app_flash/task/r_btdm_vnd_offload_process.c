/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> task.o -> r_btdm_vnd_offload_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_btdm_vnd_offload_process(uint param_1,undefined4 param_2)

{
  if (param_1 < 2) {
                    /* WARNING: Could not emulate address calculation at 0x00010274 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(btdm_ol_task_env + param_1 * 4))
              (param_2,*(code **)(btdm_ol_task_env + param_1 * 4));
    return;
  }
  return;
}

