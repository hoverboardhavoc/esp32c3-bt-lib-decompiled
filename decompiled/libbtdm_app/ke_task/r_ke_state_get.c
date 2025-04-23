/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_state_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_ke_state_get(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar1 = param_1 & 0xff;
  param_1 = param_1 >> 8;
  if (0x1e < uVar1) goto _L93;
  iVar3 = *(int *)(&ke_task_env + uVar1 * 4);
  if (iVar3 == 0) {
    do {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar1,param_1,"ke_task.c",0x1e2,*(code **)(_r_plf_funcs_p + 0xc));
      ebreak();
_L93:
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1db,*(code **)(_r_plf_funcs_p + 8));
    } while( true );
  }
  if ((param_1 < *(ushort *)(iVar3 + 8)) ||
     ((**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,"ke_task.c",0x1e3,*(code **)(_r_plf_funcs_p + 0xc)),
     param_1 < *(ushort *)(iVar3 + 8))) {
    uVar2 = *(undefined1 *)(*(int *)(iVar3 + 4) + param_1);
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}

