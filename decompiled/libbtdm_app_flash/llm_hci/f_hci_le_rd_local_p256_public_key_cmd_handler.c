/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_hci.o -> f_hci_le_rd_local_p256_public_key_cmd_handler
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
  char acStack_12 [6];
  
  r_llm_cmd_stat_send(param_1,0);
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
      if (acStack_12[0] != '\0') goto _L148;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  r_ecc_gen_new_secret_key(iVar1,0);
_L148:
  r_ecc_gen_new_public_key(iVar1,8,0);
  return 0;
}

