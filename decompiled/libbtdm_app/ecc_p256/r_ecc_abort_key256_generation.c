/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_abort_key256_generation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_abort_key256_generation(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)_ecc_env;
  piVar3 = (int *)0;
  while( true ) {
    piVar2 = piVar1;
    if (piVar2 == (int *)0x0) {
      return;
    }
    if (*(ushort *)((int)piVar2 + 0x13e) == param_1) break;
    piVar1 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  (**(code **)(_r_modules_funcs_p + 0x20))
            (&ecc_env,piVar3,piVar2,*(code **)(_r_modules_funcs_p + 0x20));
  if (piVar2[0x52] != 0) {
    (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
  }
  (**(code **)(_r_modules_funcs_p + 0x110))(piVar2,*(code **)(_r_modules_funcs_p + 0x110));
  if (_ecc_env != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00012256. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xec))(1,*(code **)(_r_modules_funcs_p + 0xec));
  return;
}

