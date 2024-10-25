/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes.o -> r_aes_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_aes_start(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  (**(code **)(_r_modules_funcs_p + 0x44))(&aes_env,param_1,*(code **)(_r_modules_funcs_p + 0x44));
  cVar1 = r_modules_funcs_p;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  if (cVar1 == '\0') {
    _r_modules_funcs_p = CONCAT31(r_modules_funcs_p_1,1);
                    /* WARNING: Could not recover jumptable at 0x0001012a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x290))(param_2,param_3);
    return;
  }
  return;
}

