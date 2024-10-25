/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes_k3.o -> r_rw_crypto_aes_k3
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_k3(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x31c))
                    (0x48,*(undefined4 *)(_r_modules_funcs_p + 0x2f8),param_2,param_3,
                     *(code **)(_r_modules_funcs_p + 0x31c));
  *(undefined1 *)(iVar1 + 0x34) = 1;
                    /* WARNING: Could not recover jumptable at 0x000100a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x344))(&aes_k3_salt,param_1,0x10);
  return;
}

