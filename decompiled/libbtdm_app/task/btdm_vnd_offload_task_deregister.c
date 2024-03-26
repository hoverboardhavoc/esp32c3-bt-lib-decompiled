/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> task.o -> btdm_vnd_offload_task_deregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 btdm_vnd_offload_task_deregister(uint param_1)

{
  if (param_1 < 2) {
    *(undefined4 *)(btdm_ol_task_env + param_1 * 4) = 0;
    return 0;
  }
  return 0xffffffff;
}

