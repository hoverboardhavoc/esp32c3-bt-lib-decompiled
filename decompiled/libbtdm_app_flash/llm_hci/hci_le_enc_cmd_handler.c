/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_enc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_enc_cmd_handler(int param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return 0;
  }
  r_rw_crypto_aes_encrypt(param_1 + 0x10,1,r_llm_aes_res_cb,0);
  return 0;
}

