/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_queue.o -> r_ke_queue_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_queue_insert(undefined4 *param_1,int *param_2,code *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)*param_1;
  puVar4 = (undefined4 *)0x0;
  while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
    iVar3 = (*param_3)(param_2,puVar2);
    if (iVar3 != 0) goto _L12;
    puVar4 = puVar2;
    puVar1 = (undefined4 *)*puVar2;
  }
  param_1[1] = param_2;
_L12:
  *param_2 = (int)puVar2;
  if (puVar4 == (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  else {
    *puVar4 = param_2;
  }
  return;
}

