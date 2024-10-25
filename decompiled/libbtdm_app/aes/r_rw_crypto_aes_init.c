/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes.o -> r_rw_crypto_aes_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_init(int param_1)

{
  code *pcVar1;
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      return;
    }
    while (_aes_env != 0) {
      pcVar1 = *(code **)(_r_modules_funcs_p + 0x110);
      (**(code **)(_r_modules_funcs_p + 0x40))(&aes_env,*(code **)(_r_modules_funcs_p + 0x40));
      (*pcVar1)();
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x2c))(&aes_env,*(code **)(_r_modules_funcs_p + 0x2c));
  _r_modules_funcs_p = _r_modules_funcs_p & 0xffffff00;
  return;
}

