/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_handler_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_ke_task_handler_get(uint param_1,uint param_2)

{
  ushort *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  uVar2 = param_2 & 0xff;
  if (0x1e < uVar2) {
    r_assert_param(uVar2,"ke_task.c",0x151);
  }
  piVar3 = *(int **)(&ke_task_env + uVar2 * 4);
  if ((*(ushort *)(piVar3 + 2) != 0) &&
     (((param_2 >> 8 < (uint)*(ushort *)(piVar3 + 2) ||
       (r_assert_param(param_2,param_1,"ke_task.c",0x159),
       param_2 >> 8 < (uint)*(ushort *)(piVar3 + 2))) && (*piVar3 != 0)))) {
    iVar4 = *(ushort *)((int)piVar3 + 10) - 1;
    if (iVar4 == -1) {
      return 0;
    }
    while( true ) {
      puVar1 = (ushort *)(iVar4 * 8 + *piVar3);
      if ((*puVar1 == param_1) || (*puVar1 == 0xffff)) break;
      iVar4 = iVar4 + -1;
      if (iVar4 == -1) {
        return 0;
      }
    }
    if (*(int *)(puVar1 + 2) == 0) {
      r_assert_err(0,"ke_task.c",0x135);
    }
    return *(undefined4 *)(puVar1 + 2);
  }
  return 0;
}

