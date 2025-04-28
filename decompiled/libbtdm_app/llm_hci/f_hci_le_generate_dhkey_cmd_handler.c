/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_hci.o -> f_hci_le_generate_dhkey_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_generate_dhkey_cmd_handler(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(_p_llm_env + 0xc3);
  do {
    if (*pcVar2 != '\0') {
      uVar1 = (**(code **)(_r_modules_funcs_p + 0x368))
                        (2,param_1 + 0x20,9,0,*(code **)(_r_modules_funcs_p + 0x368));
      goto _L252;
    }
    pcVar2 = pcVar2 + -1;
  } while (pcVar2 != (char *)(_p_llm_env + 0xa4));
  uVar1 = 0xc;
_L252:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,uVar1,*(code **)(_r_ip_funcs_p + 0x4bc));
  return 0;
}

