/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
                    /* WARNING: Could not recover jumptable at 0x0001223c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xec))(1,*(code **)(_r_modules_funcs_p + 0xec));
  return;
}

