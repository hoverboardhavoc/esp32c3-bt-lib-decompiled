/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar2;
  int *piVar3;
  
  iVar2 = 2;
  piVar1 = _ke_env;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return;
    }
    do {
      piVar3 = (int *)*piVar1;
      if (param_1 == *(byte *)((int)piVar1 + 6)) {
        r_co_list_extract(&ke_env,piVar1);
        r_ke_msg_free(piVar1);
      }
      piVar1 = piVar3;
    } while (piVar3 != (int *)0x0);
    if (iVar2 == 1) break;
    iVar2 = 1;
    piVar1 = _r_ke_queue_extract;
  }
  return;
}

