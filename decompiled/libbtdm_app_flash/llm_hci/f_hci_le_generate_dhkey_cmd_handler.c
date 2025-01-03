/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
      goto _L172;
    }
    pcVar2 = pcVar2 + -1;
  } while ((char *)(_p_llm_env + 0xa4) != pcVar2);
  uVar1 = 0xc;
_L172:
  r_llm_cmd_stat_send(param_2,uVar1);
  return 0;
}

