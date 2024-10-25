/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar4;
  uint uVar5;
  
  iVar2 = param_1 * 0x44;
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x28) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x2c) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x32) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2;
    *(undefined2 *)(iVar4 + 0x32) = 0;
    *(undefined2 *)(iVar4 + 0x34) = 0;
  }
  if (*(short *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x36) != 0) {
    (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    iVar4 = *(int *)(_p_llm_env + 8) + iVar2;
    *(undefined2 *)(iVar4 + 0x36) = 0;
    *(undefined2 *)(iVar4 + 0x38) = 0;
  }
  iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + iVar2);
  if (iVar4 != 0) {
    (**(code **)(_r_modules_funcs_p + 0xd8))(iVar4 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2) = 0;
  }
  bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (bVar1 < *(byte *)(iVar4 + 0xd)) {
    uVar5 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
    iVar4 = uVar5 * 0x44;
    if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x28) = 0;
    }
    if (*(short *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2c) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4 + 0x2c) = 0;
    }
    iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + iVar4);
    if (iVar3 != 0) {
      (**(code **)(_r_modules_funcs_p + 0xd8))(iVar3 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar4) = 0;
    }
    iVar3 = _r_modules_funcs_p;
    *(undefined1 *)(iVar4 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
    (**(code **)(iVar3 + 0x200))(uVar5,*(code **)(iVar3 + 0x200));
    (**(code **)(_r_modules_funcs_p + 0x1d8))(uVar5,*(code **)(_r_modules_funcs_p + 0x1d8));
  }
  iVar4 = _r_modules_funcs_p;
  *(undefined1 *)(iVar2 + *(int *)(_p_llm_env + 8) + 0x40) = 0;
  (**(code **)(iVar4 + 0x200))(param_1,*(code **)(iVar4 + 0x200));
                    /* WARNING: Could not recover jumptable at 0x000133b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x1d8))(param_1);
  return;
}

