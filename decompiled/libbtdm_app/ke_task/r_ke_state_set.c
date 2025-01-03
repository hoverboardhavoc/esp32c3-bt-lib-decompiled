/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  int unaff_s1;
  uint uVar3;
  uint unaff_s3;
  uint unaff_s4;
  
  uVar3 = param_1 & 0xff;
  uVar1 = param_1 >> 8;
  if (uVar3 < 0x1f) {
    unaff_s1 = *(int *)(&ke_task_env + uVar3 * 4);
    if (unaff_s1 == 0) goto _L88;
    if (uVar1 < *(ushort *)(unaff_s1 + 8)) goto _L85;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1b2,*(code **)(_r_plf_funcs_p + 8));
_L88:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar3,uVar1,"ke_task.c",0x1b9,*(code **)(_r_plf_funcs_p + 0xc));
    ebreak();
    param_1 = unaff_s3;
    param_2 = unaff_s4;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,"ke_task.c",0x1ba,*(code **)(_r_plf_funcs_p + 0xc));
  if (*(ushort *)(unaff_s1 + 8) <= uVar1) {
    return;
  }
_L85:
  pbVar2 = (byte *)(uVar1 + *(int *)(unaff_s1 + 4));
  if (pbVar2 == (byte *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1c2,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*pbVar2 == param_2) {
    return;
  }
  *pbVar2 = (byte)param_2;
                    /* WARNING: Could not recover jumptable at 0x00010582. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x178))(param_1);
  return;
}

