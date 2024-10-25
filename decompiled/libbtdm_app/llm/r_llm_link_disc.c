/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm.o -> r_llm_link_disc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_link_disc(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = _r_ip_funcs_p;
  iVar4 = param_1 * 0x44;
  iVar1 = *(int *)(_p_llm_env + 8) + iVar4;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  (**(code **)(iVar2 + 0x6f4))(iVar1 + 0xc,*(code **)(iVar2 + 0x6f4));
  iVar2 = *(int *)(_p_llm_env + 8) + iVar4;
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                    (iVar2 + 4,*(undefined1 *)(iVar2 + 0x41),*(code **)(_r_ip_funcs_p + 0x4c8));
  if ((uVar3 < 0xc) && ((*(byte *)(uVar3 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
    iVar2 = *(int *)(_p_llm_env + 8) + iVar4;
    (**(code **)(_r_ip_funcs_p + 700))
              (iVar2 + 4,*(undefined1 *)(iVar2 + 0x41),*(code **)(_r_ip_funcs_p + 700));
  }
  iVar4 = *(int *)(_p_llm_env + 8) + iVar4;
  (**(code **)(_r_ip_funcs_p + 0x288))
            (iVar4 + 4,*(undefined1 *)(iVar4 + 0x41),0,*(code **)(_r_ip_funcs_p + 0x288));
  uVar3 = 0;
  (**(code **)(_r_ip_funcs_p + 0x78))(param_1,*(code **)(_r_ip_funcs_p + 0x78));
  while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar3 < *(byte *)(iVar2 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar3 * 0x44 + 0x40) != '\t'))) {
    uVar3 = uVar3 + 1 & 0xff;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((*(byte *)(iVar2 + 0xd) <= uVar3) && (_bt_rf_coex_hooks_p != (undefined4 *)0x0)) &&
     ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000110a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(param_1,7,0);
    return;
  }
  return;
}

