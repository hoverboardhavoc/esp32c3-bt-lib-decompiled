/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  int iVar3;
  uint uVar4;
  
  iVar3 = _r_ip_funcs_p;
  iVar1 = param_1 * 0x44;
  iVar2 = *(int *)(_p_llm_env + 8) + iVar1;
  *(undefined1 *)(iVar2 + 0x40) = 0;
  (**(code **)(iVar3 + 0x6f4))(iVar2 + 0xc,*(code **)(iVar3 + 0x6f4));
  iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
  uVar4 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                    (iVar3 + 4,*(undefined1 *)(iVar3 + 0x41),*(code **)(_r_ip_funcs_p + 0x4c8));
  if ((uVar4 < 0xc) && ((*(byte *)(uVar4 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
    iVar3 = *(int *)(_p_llm_env + 8) + iVar1;
    (**(code **)(_r_ip_funcs_p + 700))
              (iVar3 + 4,*(undefined1 *)(iVar3 + 0x41),*(code **)(_r_ip_funcs_p + 700));
  }
  iVar1 = *(int *)(_p_llm_env + 8) + iVar1;
  uVar4 = 0;
  (**(code **)(_r_ip_funcs_p + 0x288))
            (iVar1 + 4,*(undefined1 *)(iVar1 + 0x41),0,*(code **)(_r_ip_funcs_p + 0x288));
  (**(code **)(_r_ip_funcs_p + 0x78))(param_1,*(code **)(_r_ip_funcs_p + 0x78));
  while ((iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar4 < *(byte *)(iVar3 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar4 * 0x44 + 0x40) != '\t'))) {
    uVar4 = uVar4 + 1 & 0xff;
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((*(byte *)(iVar3 + 0xd) <= uVar4) && (_bt_rf_coex_hooks_p != (undefined4 *)0x0)) &&
     ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000110f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(param_1,7,0);
    return;
  }
  return;
}

