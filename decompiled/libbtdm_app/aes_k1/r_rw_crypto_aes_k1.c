/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes_k1.o -> r_rw_crypto_aes_k1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_k1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined1 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_modules_funcs_p + 0x31c))
                    (0x4c,*(undefined4 *)(_r_modules_funcs_p + 0x2f0),param_6,param_7,
                     *(code **)(_r_modules_funcs_p + 0x31c));
  iVar1 = _r_modules_funcs_p;
  *(undefined1 *)(iVar2 + 0x38) = param_5;
  *(undefined1 *)(iVar2 + 0x39) = 1;
  *(undefined4 *)(iVar2 + 0x34) = param_4;
                    /* WARNING: Could not recover jumptable at 0x000100bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x344))(param_1,param_2,param_3,*(code **)(iVar1 + 0x344));
  return;
}

