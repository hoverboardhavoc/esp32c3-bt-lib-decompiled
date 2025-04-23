/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_set_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_release(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  iVar2 = param_1 * 0x44;
  piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
  if ((short)piVar4[10] != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    piVar4[10] = 0;
  }
  if ((short)piVar4[0xb] != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    piVar4[0xb] = 0;
  }
  if (*(short *)((int)piVar4 + 0x32) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *(undefined2 *)((int)piVar4 + 0x32) = 0;
    *(undefined2 *)(piVar4 + 0xd) = 0;
  }
  if (*(short *)((int)piVar4 + 0x36) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *(undefined2 *)((int)piVar4 + 0x36) = 0;
    *(undefined2 *)(piVar4 + 0xe) = 0;
  }
  if (*piVar4 != 0) {
    (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar4 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar2);
    *piVar4 = 0;
  }
  bVar1 = *(byte *)((int)piVar4 + 0x3d);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (bVar1 < *(byte *)(iVar3 + 0xd)) {
    uVar5 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
    iVar3 = uVar5 * 0x44;
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
    if ((short)piVar4[10] != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      piVar4[10] = 0;
    }
    if ((short)piVar4[0xb] != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      piVar4[0xb] = 0;
    }
    if (*piVar4 != 0) {
      (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar4 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
      ;
      piVar4 = (int *)(*(int *)(_p_llm_env + 8) + iVar3);
      *piVar4 = 0;
    }
    *(undefined1 *)(piVar4 + 0x10) = 0;
    (**(code **)(_r_modules_funcs_p + 0x200))(uVar5,*(code **)(_r_modules_funcs_p + 0x200));
    (**(code **)(_r_modules_funcs_p + 0x1d8))(uVar5,*(code **)(_r_modules_funcs_p + 0x1d8));
  }
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x40) = 0;
  (**(code **)(_r_modules_funcs_p + 0x200))(param_1,*(code **)(_r_modules_funcs_p + 0x200));
                    /* WARNING: Could not recover jumptable at 0x000132e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x1d8))(param_1,*(code **)(_r_modules_funcs_p + 0x1d8));
  return;
}

