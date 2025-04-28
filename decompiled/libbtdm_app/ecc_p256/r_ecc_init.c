/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_init(int param_1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x2c);
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00011e12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x100))
                  (1,*(undefined4 *)(_r_modules_funcs_p + 0x380),
                   *(code **)(_r_modules_funcs_p + 0x100));
        return;
      }
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
                    /* WARNING: Could not recover jumptable at 0x00011e5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&ecc_env,UNRECOVERED_JUMPTABLE);
  return;
}

