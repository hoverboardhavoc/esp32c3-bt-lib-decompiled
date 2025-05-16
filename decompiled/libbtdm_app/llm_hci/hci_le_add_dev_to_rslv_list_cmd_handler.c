/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_add_dev_to_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_rslv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0x12;
  if (*param_1 < 2) {
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x504))(0x12,*(code **)(_r_ip_funcs_p + 0x504));
      uVar3 = 0xc;
      if (iVar2 != 0) goto _L35;
    }
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                      (param_1 + 1,*param_1,*(code **)(_r_ip_funcs_p + 0x4c8));
    if (uVar1 < 0xc) {
      uVar1 = (int)(uint)*(byte *)(_p_llm_env + uVar1 * 10 + 0x2d) >> 1 & 1;
    }
    else {
      uVar1 = 0;
    }
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x274))
                      (param_1 + 1,param_1 + 7,param_1 + 0x17,*param_1,0,uVar1,
                       *(code **)(_r_ip_funcs_p + 0x274));
  }
_L35:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

