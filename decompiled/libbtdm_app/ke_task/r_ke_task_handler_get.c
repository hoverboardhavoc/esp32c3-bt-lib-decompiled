/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_handler_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ke_task_handler_get(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar1 = param_2 & 0xff;
  if (0x1e < uVar1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,"ke_task.c",0x151,*(code **)(_r_plf_funcs_p + 0xc));
  }
  piVar2 = *(int **)(&ke_task_env + uVar1 * 4);
  if ((*(ushort *)(piVar2 + 2) != 0) &&
     (((param_2 >> 8 < (uint)*(ushort *)(piVar2 + 2) ||
       ((**(code **)(_r_plf_funcs_p + 0xc))
                  (param_2,param_1,"ke_task.c",0x159,*(code **)(_r_plf_funcs_p + 0xc)),
       param_2 >> 8 < (uint)*(ushort *)(piVar2 + 2))) && (*piVar2 != 0)))) {
                    /* WARNING: Could not recover jumptable at 0x000103fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(_r_modules_funcs_p + 0x144))
                      (param_1,*(undefined2 *)((int)piVar2 + 10),
                       *(code **)(_r_modules_funcs_p + 0x144));
    return uVar3;
  }
  return 0;
}

