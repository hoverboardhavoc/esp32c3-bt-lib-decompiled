/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rd_local_p256_public_key_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_local_p256_public_key_cmd_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char acStack_12 [6];
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    r_llm_cmd_stat_send(param_1,0xc);
    return 0;
  }
  r_llm_cmd_stat_send(param_1,0);
  acStack_12[1] = 1;
  iVar2 = _p_llm_env + 0xa4;
  iVar1 = (*_rwip_param)(0x82,acStack_12 + 1,acStack_12,_rwip_param);
  if (iVar1 != 0) {
    acStack_12[0] = '\0';
  }
  acStack_12[1] = 0x20;
  if (acStack_12[0] != '\0') {
    iVar1 = (*_rwip_param)(0x80,acStack_12 + 1,iVar2,_rwip_param);
    if (iVar1 == 0) {
      if (acStack_12[0] != '\0') goto _L151;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  r_ecc_gen_new_secret_key(iVar2,0);
_L151:
  r_ecc_gen_new_public_key(iVar2,8,0);
  return 0;
}

