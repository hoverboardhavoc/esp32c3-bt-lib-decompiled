/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_msg_flush
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_msg_flush(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 2;
  piVar1 = _ke_env;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return;
    }
    do {
      piVar2 = (int *)*piVar1;
      if (param_1 == *(byte *)((int)piVar1 + 6)) {
        r_co_list_extract(&ke_env,piVar1);
        r_ke_msg_free(piVar1);
      }
      piVar1 = piVar2;
    } while (piVar2 != (int *)0x0);
    if (iVar3 == 1) break;
    iVar3 = 1;
    piVar1 = _r_ke_queue_extract;
  }
  return;
}

