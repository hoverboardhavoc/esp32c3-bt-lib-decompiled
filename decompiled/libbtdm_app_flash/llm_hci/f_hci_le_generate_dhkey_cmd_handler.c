/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_hci.o -> f_hci_le_generate_dhkey_cmd_handler
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
      uVar1 = r_ecc_generate_key256(2,param_1 + 0x20,9,0);
      goto _L169;
    }
    pcVar2 = pcVar2 + -1;
  } while (pcVar2 != (char *)(_p_llm_env + 0xa4));
  uVar1 = 0xc;
_L169:
  r_llm_cmd_stat_send(param_2,uVar1);
  return 0;
}

