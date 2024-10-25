/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_queue.o -> r_ke_queue_extract
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * r_ke_queue_extract(undefined4 *param_1,code *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  piVar1 = (int *)0x0;
  do {
    piVar2 = piVar1;
    piVar1 = piVar4;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar3 = (*param_2)(piVar1,param_3);
    piVar4 = (int *)*piVar1;
  } while (iVar3 == 0);
  if (piVar2 == (int *)0x0) {
    *param_1 = piVar4;
  }
  else {
    *piVar2 = (int)piVar4;
  }
  if (*piVar1 == 0) {
    param_1[1] = piVar2;
  }
  else {
    *piVar1 = 0;
  }
  return piVar1;
}

