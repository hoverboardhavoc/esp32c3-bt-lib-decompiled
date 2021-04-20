/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llm_init.o -> hci_le_create_con_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_create_con_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

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
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_init.c",0x22b,*(code **)(_r_plf_funcs_p + 8));
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
    *(undefined4 *)(iVar2 + *(int *)(_p_llm_env + 8)) = 0;
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

