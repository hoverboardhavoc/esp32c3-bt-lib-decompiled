/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
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
      if (acStack_12[0] != '\0') goto _L72;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x370))(iVar1,0,*(code **)(_r_modules_funcs_p + 0x370));
_L72:
  (**(code **)(_r_modules_funcs_p + 0x36c))(iVar1,8,0,*(code **)(_r_modules_funcs_p + 0x36c));
  return 0;
}

