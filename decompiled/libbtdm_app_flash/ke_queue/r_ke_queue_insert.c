/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_queue.o -> r_ke_queue_insert
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

