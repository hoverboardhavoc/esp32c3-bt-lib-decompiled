/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x24f,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x498))(*(code **)(_r_ip_funcs_p + 0x498));
    if (iVar2 == 0xc) {
      (**(code **)(_r_modules_funcs_p + 0xd0))
                (param_1,0,param_2,*(code **)(_r_modules_funcs_p + 0xd0));
      return 1;
    }
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      uVar4 = 1;
      if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
        uVar4 = 3;
      }
      (*(code *)*_bt_rf_coex_hooks_p)(uVar1,uVar4,0);
    }
    (**(code **)(_r_modules_funcs_p + 0xd8))
              (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) + -0xc,
               *(code **)(_r_modules_funcs_p + 0xd8));
    *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3) = 0;
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x4b8))
              (param_2,((int)((uint)_sdk_cfg_priv_opts << 0x1a) >> 0x1f & 0xfffffff4U) + 0xc,
               *(code **)(_r_ip_funcs_p + 0x4b8));
  }
  return 0;
}

