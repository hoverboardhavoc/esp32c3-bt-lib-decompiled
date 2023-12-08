/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_generate_dhkey_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_generate_dhkey_cmd_handler(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(_p_llm_env + 0xc3);
  do {
    if (*pcVar2 != '\0') {
      uVar1 = (**(code **)(_r_modules_funcs_p + 0x368))
                        (2,param_1 + 0x20,9,0,*(code **)(_r_modules_funcs_p + 0x368));
      goto _L81;
    }
    pcVar2 = pcVar2 + -1;
  } while ((char *)(_p_llm_env + 0xa4) != pcVar2);
  uVar1 = 0xc;
_L81:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,uVar1,*(code **)(_r_ip_funcs_p + 0x4bc));
  return 0;
}

