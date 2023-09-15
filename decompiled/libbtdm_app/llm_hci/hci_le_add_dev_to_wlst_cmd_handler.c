/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_add_dev_to_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *__src;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar3 = 0xc;
  if (iVar1 == 0) goto _L140;
  if ((byte)(*param_1 - 2U) < 0xfd) {
_L143:
    uVar3 = 0x12;
  }
  else {
    __src = param_1 + 1;
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__src,*(code **)(_r_ip_funcs_p + 0x4c8));
    if (uVar2 < 0xc) {
      if ((*(byte *)(_p_llm_env + uVar2 * 10 + 0x2d) & 2) != 0) goto _L143;
    }
    else {
      uVar3 = 7;
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c4))(*(code **)(_r_ip_funcs_p + 0x4c4));
      if (uVar2 == 0xc) goto _L140;
    }
    memcpy((void *)(_p_llm_env + uVar2 * 10 + 0x24),__src,6);
    iVar1 = _p_llm_env + uVar2 * 10;
    *(char *)(iVar1 + 0x2c) = *param_1;
    *(byte *)(iVar1 + 0x2d) = *(byte *)(iVar1 + 0x2d) | 3;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x4d8))(__src,*(code **)(_r_ip_funcs_p + 0x4d8));
    uVar3 = 0;
    if (iVar1 == 0) {
      (**(code **)(_r_ip_funcs_p + 700))(uVar2,__src,*param_1,*(code **)(_r_ip_funcs_p + 700));
      uVar3 = 0;
    }
  }
_L140:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

