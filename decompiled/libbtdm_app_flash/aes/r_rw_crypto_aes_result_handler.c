/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes.o -> r_rw_crypto_aes_result_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_result_handler(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = r_co_list_pop_front(&aes_env);
  if (_aes_env == 0) {
    r_co_list_init = (code)0x0;
  }
  else {
    r_co_list_init = (code)0x1;
    r_rwip_aes_encrypt(*(undefined4 *)(_aes_env + 0xc),*(undefined4 *)(_aes_env + 0x10));
  }
  if ((iVar1 != 0) &&
     (((param_1 != 0 || (*(code **)(iVar1 + 4) == (code *)0x0)) ||
      (iVar2 = (**(code **)(iVar1 + 4))(iVar1,param_2), iVar2 != 0)))) {
    if (*(code **)(iVar1 + 8) != (code *)0x0) {
      (**(code **)(iVar1 + 8))(param_1,param_2,*(undefined4 *)(iVar1 + 0x14));
    }
    r_ke_free(iVar1);
    return;
  }
  return;
}

