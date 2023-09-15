/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rd_local_p256_public_key_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_local_p256_public_key_cmd_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char acStack_12 [2];
  
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_1,0,*(code **)(_r_ip_funcs_p + 0x4bc));
  acStack_12[1] = 1;
  iVar1 = _p_llm_env + 0xa4;
  iVar2 = (*_rwip_param)(0x82,acStack_12 + 1,acStack_12,_rwip_param);
  if (iVar2 != 0) {
    acStack_12[0] = '\0';
  }
  acStack_12[1] = 0x20;
  if (acStack_12[0] != '\0') {
    iVar2 = (*_rwip_param)(0x80,acStack_12 + 1,iVar1,_rwip_param);
    if (iVar2 == 0) {
      if (acStack_12[0] != '\0') goto _L93;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x370))(iVar1,0,*(code **)(_r_modules_funcs_p + 0x370));
_L93:
  (**(code **)(_r_modules_funcs_p + 0x36c))(iVar1,8,0,*(code **)(_r_modules_funcs_p + 0x36c));
  return 0;
}

