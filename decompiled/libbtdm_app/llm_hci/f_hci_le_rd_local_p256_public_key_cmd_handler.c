/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> llm_hci.o -> f_hci_le_rd_local_p256_public_key_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_rd_local_p256_public_key_cmd_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char acStack_12 [2];
  
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_1,0,*(code **)(_r_ip_funcs_p + 0x4bc));
  iVar1 = _p_llm_env;
  acStack_12[1] = 1;
  iVar2 = (*_rwip_param)(0x82,acStack_12 + 1,acStack_12,_rwip_param);
  iVar1 = iVar1 + 0xa4;
  if (iVar2 != 0) {
    acStack_12[0] = '\0';
  }
  acStack_12[1] = 0x20;
  if (acStack_12[0] != '\0') {
    iVar2 = (*_rwip_param)(0x80,acStack_12 + 1,iVar1,_rwip_param);
    if (iVar2 == 0) {
      if (acStack_12[0] != '\0') goto _L226;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x370))(iVar1,0,*(code **)(_r_modules_funcs_p + 0x370));
_L226:
  (**(code **)(_r_modules_funcs_p + 0x36c))(iVar1,8,0,*(code **)(_r_modules_funcs_p + 0x36c));
  return 0;
}

