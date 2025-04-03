/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
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
                    /* WARNING: Could not recover jumptable at 0x000110aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(param_1,7,0);
    return;
  }
  return;
}

