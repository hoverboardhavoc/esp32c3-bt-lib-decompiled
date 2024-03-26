/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> task.o -> btdm_vnd_offload_task_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 btdm_vnd_offload_task_register(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
    uVar1 = 0xffffffff;
    if (param_2 != 0) {
      *(int *)(btdm_ol_task_env + param_1 * 4) = param_2;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

