/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
      if (acStack_12[0] != '\0') goto _L132;
    }
    else {
      acStack_12[0] = '\0';
    }
  }
  r_ecc_gen_new_secret_key(iVar2,0);
_L132:
  r_ecc_gen_new_public_key(iVar2,8,0);
  return 0;
}

