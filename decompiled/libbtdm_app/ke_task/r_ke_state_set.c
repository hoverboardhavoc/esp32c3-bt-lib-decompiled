/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_state_set(uint param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xff;
  uVar3 = param_1 >> 8;
  if (0x1e < uVar4) goto _L78;
  iVar1 = *(int *)(&ke_task_env + uVar4 * 4);
  if (iVar1 == 0) {
    do {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar4,uVar3,"ke_task.c",0x1bc,*(code **)(_r_plf_funcs_p + 0xc));
      ebreak();
_L78:
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1b5,*(code **)(_r_plf_funcs_p + 8));
    } while( true );
  }
  if ((uVar3 < *(ushort *)(iVar1 + 8)) ||
     ((**(code **)(_r_plf_funcs_p + 0xc))(uVar3,"ke_task.c",0x1bd,*(code **)(_r_plf_funcs_p + 0xc)),
     uVar3 < *(ushort *)(iVar1 + 8))) {
    pbVar2 = (byte *)(*(int *)(iVar1 + 4) + uVar3);
    if (pbVar2 == (byte *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1c6,*(code **)(_r_plf_funcs_p + 8));
    }
    if (*pbVar2 != param_2) {
      *pbVar2 = (byte)param_2;
                    /* WARNING: Could not recover jumptable at 0x0001059e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x178))(param_1,*(code **)(_r_modules_funcs_p + 0x178));
      return;
    }
  }
  return;
}

