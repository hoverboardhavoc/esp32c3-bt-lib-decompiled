/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_init(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (param_1 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x2c);
  }
  else {
    if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00011e04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x100))(1,*(undefined4 *)(_r_modules_funcs_p + 0x380));
      return;
    }
    if (param_1 != 2) {
      return;
    }
    (**(code **)(_r_modules_funcs_p + 0xec))(1,*(code **)(_r_modules_funcs_p + 0xec));
    while (_ecc_env != 0) {
      iVar1 = (**(code **)(_r_modules_funcs_p + 0x40))
                        (&ecc_env,*(code **)(_r_modules_funcs_p + 0x40));
      if (*(int *)(iVar1 + 0x148) != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      (**(code **)(_r_modules_funcs_p + 0x110))(iVar1,*(code **)(_r_modules_funcs_p + 0x110));
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x2c);
  }
                    /* WARNING: Could not recover jumptable at 0x00011e4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&ecc_env);
  return;
}

