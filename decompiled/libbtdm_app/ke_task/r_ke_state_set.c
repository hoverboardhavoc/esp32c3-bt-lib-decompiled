/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    if (unaff_s1 == 0) goto _L86;
    if (uVar1 < *(ushort *)(unaff_s1 + 8)) goto _L83;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1ae,*(code **)(_r_plf_funcs_p + 8));
_L86:
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar3,uVar1,"ke_task.c",0x1b5,*(code **)(_r_plf_funcs_p + 0xc));
    ebreak();
    param_1 = unaff_s3;
    param_2 = unaff_s4;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,"ke_task.c",0x1b6,*(code **)(_r_plf_funcs_p + 0xc));
  if (*(ushort *)(unaff_s1 + 8) <= uVar1) {
    return;
  }
_L83:
  pbVar2 = (byte *)(uVar1 + *(int *)(unaff_s1 + 4));
  if (pbVar2 == (byte *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0x1be,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*pbVar2 == param_2) {
    return;
  }
  *pbVar2 = (byte)param_2;
                    /* WARNING: Could not recover jumptable at 0x0001056c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x178))(param_1);
  return;
}

