/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes.o -> r_aes_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_aes_start(int param_1,undefined4 param_2,undefined4 param_3)

{
  code cVar1;
  
  r_co_list_push_back(&aes_env,param_1);
  cVar1 = r_co_list_init;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  if (cVar1 == (code)0x0) {
    r_co_list_init = (code)0x1;
    r_rwip_aes_encrypt(param_2,param_3);
    return;
  }
  return;
}

