/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x22) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  uVar1 = 0;
  while ((iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar1 < *(byte *)(iVar3 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x05'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (uVar1 < *(byte *)(iVar3 + 0xd)) {
    iVar3 = uVar1 * 0x44;
    if (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_init.c",0x24f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x498))(*(code **)(_r_ip_funcs_p + 0x498));
    if (iVar2 == 0xc) {
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
              (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) + -0xc,
               *(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(iVar3 + *(int *)(_p_llm_env + 8)) = 0;
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

