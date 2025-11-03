/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_generate_dhkey_cmd_handler
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
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  pcVar3 = (char *)(_p_llm_env + 0xc3);
  do {
    if (*pcVar3 != '\0') {
      uVar2 = r_ecc_generate_key256(2,param_1 + 0x20,9,0);
      goto _L169;
    }
    pcVar3 = pcVar3 + -1;
  } while (pcVar3 != (char *)(_p_llm_env + 0xa4));
  uVar2 = 0xc;
_L169:
  r_llm_cmd_stat_send(param_2,uVar2);
  return 0;
}

