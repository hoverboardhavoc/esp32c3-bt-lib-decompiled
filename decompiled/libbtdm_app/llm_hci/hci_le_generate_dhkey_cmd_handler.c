/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_generate_dhkey_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_generate_dhkey_cmd_handler(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x20) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4bc));
    return 0;
  }
  pcVar3 = (char *)(_p_llm_env + 0xc3);
  do {
    if (*pcVar3 != '\0') {
      uVar2 = (**(code **)(_r_modules_funcs_p + 0x368))
                        (2,param_1 + 0x20,9,0,*(code **)(_r_modules_funcs_p + 0x368));
      goto _L247;
    }
    pcVar3 = pcVar3 + -1;
  } while (pcVar3 != (char *)(_p_llm_env + 0xa4));
  uVar2 = 0xc;
_L247:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4bc));
  return 0;
}

