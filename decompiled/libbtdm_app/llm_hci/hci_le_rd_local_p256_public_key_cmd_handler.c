/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
      if (acStack_12[0] != '\0') goto _L116;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x370))(iVar1,0,*(code **)(_r_modules_funcs_p + 0x370));
_L116:
  (**(code **)(_r_modules_funcs_p + 0x36c))(iVar1,8,0,*(code **)(_r_modules_funcs_p + 0x36c));
  return 0;
}

