/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar1;
  byte *pbVar2;
  uint unaff_s1;
  int unaff_s2;
  uint unaff_s3;
  uint uVar3;
  
  uVar3 = param_1 & 0xff;
  uVar1 = param_1 >> 8;
  if (uVar3 < 0x1f) {
    unaff_s2 = *(int *)(&ke_task_env + uVar3 * 4);
    if (unaff_s2 == 0) goto _L86;
    if (uVar1 < *(ushort *)(unaff_s2 + 8)) goto _L83;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1b5,*(code **)(_r_plf_funcs_p + 8));
_L86:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar3,uVar1,"ke_task.c",0x1bc,*(code **)(_r_plf_funcs_p + 0xc));
    ebreak();
    param_1 = unaff_s1;
    param_2 = unaff_s3;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,"ke_task.c",0x1bd,*(code **)(_r_plf_funcs_p + 0xc));
  if (*(ushort *)(unaff_s2 + 8) <= uVar1) {
    return;
  }
_L83:
  pbVar2 = (byte *)(uVar1 + *(int *)(unaff_s2 + 4));
  if (pbVar2 == (byte *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1c6,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*pbVar2 == param_2) {
    return;
  }
  *pbVar2 = (byte)param_2;
                    /* WARNING: Could not recover jumptable at 0x000105d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x178))(param_1,*(code **)(_r_modules_funcs_p + 0x178));
  return;
}

