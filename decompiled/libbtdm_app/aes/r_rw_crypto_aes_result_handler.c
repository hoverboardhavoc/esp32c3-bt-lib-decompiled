/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes.o -> r_rw_crypto_aes_result_handler
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
  
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x40))(&aes_env,*(code **)(_r_modules_funcs_p + 0x40));
  if (_aes_env == 0) {
    _r_modules_funcs_p = (uint)r_modules_funcs_p_1 << 8;
  }
  else {
    _r_modules_funcs_p = CONCAT31(r_modules_funcs_p_1,1);
    (**(code **)(_r_modules_funcs_p + 0x290))
              (*(undefined4 *)(_aes_env + 0xc),*(undefined4 *)(_aes_env + 0x10),
               *(code **)(_r_modules_funcs_p + 0x290));
  }
  if ((iVar1 != 0) &&
     (((param_1 != 0 || (*(code **)(iVar1 + 4) == (code *)0x0)) ||
      (iVar2 = (**(code **)(iVar1 + 4))(iVar1,param_2), iVar2 != 0)))) {
    if (*(code **)(iVar1 + 8) != (code *)0x0) {
      (**(code **)(iVar1 + 8))(param_1,param_2,*(undefined4 *)(iVar1 + 0x14));
    }
                    /* WARNING: Could not recover jumptable at 0x0001027c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x110))(iVar1,*(code **)(_r_modules_funcs_p + 0x110));
    return;
  }
  return;
}

