/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_init.o -> f_hci_le_create_con_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_create_con_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar1 < *(byte *)(iVar2 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x05'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = uVar1 * 0x44;
    if (*(int *)(*(int *)(_p_llm_env + 8) + iVar2) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x274,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x498))(*(code **)(_r_ip_funcs_p + 0x498));
    if (iVar3 == 0xc) {
      (**(code **)(_r_modules_funcs_p + 0xd0))
                (param_1,0,param_2,*(code **)(_r_modules_funcs_p + 0xd0));
      return 1;
    }
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      uVar4 = 3;
      if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
        uVar4 = 1;
      }
      (*(code *)*_bt_rf_coex_hooks_p)(uVar1,uVar4,0);
    }
    (**(code **)(_r_modules_funcs_p + 0xd8))
              (*(int *)(*(int *)(_p_llm_env + 8) + iVar2) + -0xc,
               *(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar2) = 0;
  }
  else {
    uVar4 = 0xc;
    if ((_sdk_cfg_priv_opts & 0x20) != 0) {
      uVar4 = 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  }
  return 0;
}

