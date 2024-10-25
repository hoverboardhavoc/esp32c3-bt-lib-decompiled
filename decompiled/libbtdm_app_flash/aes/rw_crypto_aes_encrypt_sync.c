/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes.o -> rw_crypto_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void rw_crypto_aes_encrypt_sync(int param_1,int param_2,char param_3,int param_4)

{
  if ((((r_co_list_init == (code)0x0) && ((byte)(param_3 - 1U) < 0x10)) && (param_1 != 0)) &&
     ((param_2 != 0 && (param_4 != 0)))) {
    r_co_list_init = (code)0x1;
    rwip_aes_encrypt_sync();
    r_co_list_init = (code)0x0;
  }
  return;
}

