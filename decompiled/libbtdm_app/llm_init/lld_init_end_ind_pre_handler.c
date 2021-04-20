/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_init.o -> lld_init_end_ind_pre_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_init_end_ind_pre_handler(byte *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar1 = (uint)*param_1;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar2 + 0xd) <= uVar1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,0,"llm_init.c",0x4d,*(code **)(_r_plf_funcs_p + 0xc));
  }
  piVar4 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
  if (((((char)piVar4[0x10] == '\x05') && (*piVar4 != 0)) &&
      (_bt_rf_coex_hooks_p != (undefined4 *)0x0)) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
  {
    uVar3 = 3;
    if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
      uVar3 = 1;
    }
    (*(code *)*_bt_rf_coex_hooks_p)(uVar1,uVar3,0);
  }
  return;
}

