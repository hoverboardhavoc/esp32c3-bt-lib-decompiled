/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_queue.o -> r_ke_queue_extract
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * r_ke_queue_extract(undefined4 *param_1,code *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = (int *)*param_1;
  piVar1 = (int *)0x0;
  do {
    piVar4 = piVar1;
    piVar1 = piVar3;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar2 = (*param_2)(piVar1,param_3);
    piVar3 = (int *)*piVar1;
  } while (iVar2 == 0);
  if (piVar4 == (int *)0x0) {
    *param_1 = piVar3;
  }
  else {
    *piVar4 = (int)piVar3;
  }
  if (*piVar1 == 0) {
    param_1[1] = piVar4;
  }
  else {
    *piVar1 = 0;
  }
  return piVar1;
}

