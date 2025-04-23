/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
                    /* WARNING: Could not recover jumptable at 0x00010136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x290))
              (param_2,param_3,*(code **)(_r_modules_funcs_p + 0x290));
    return;
  }
  return;
}

