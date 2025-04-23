/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_host_ch_class_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_host_ch_class_cmd_handler(void *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  if (*(char *)(_p_llm_env + 0x23) == '\0') {
    if ((*(byte *)((int)param_1 + 4) < 0x20) &&
       (cVar1 = (**(code **)(_r_modules_funcs_p + 0xc))(0xc,*(code **)(_r_modules_funcs_p + 0xc)),
       (byte)(cVar1 - 1U) < 0x25)) {
      memcpy((void *)(_p_llm_env + 0x18),param_1,5);
      (**(code **)(_r_modules_funcs_p + 0xc4))(5,0,100,*(code **)(_r_modules_funcs_p + 0xc4));
      *(undefined1 *)(_p_llm_env + 0x23) = 1;
      (**(code **)(_r_modules_funcs_p + 0xb8))(4,0,*(code **)(_r_modules_funcs_p + 0xb8));
      (**(code **)(_r_ip_funcs_p + 0x4b4))(*(code **)(_r_ip_funcs_p + 0x4b4));
      uVar2 = 0;
    }
    else {
      uVar2 = 0x12;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

