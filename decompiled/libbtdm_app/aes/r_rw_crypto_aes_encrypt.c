/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> aes.o -> r_rw_crypto_aes_encrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_crypto_aes_encrypt
               (void *param_1,void *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  void *pvVar2;
  
  if (param_3 == 0) {
    (**(code **)(_r_modules_funcs_p + 0x31c))(0x18,param_4,param_5);
                    /* WARNING: Could not recover jumptable at 0x0001018a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x324))
              (param_1,param_2,*(code **)(_r_modules_funcs_p + 0x324));
    return;
  }
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x31c))(0x38,0,param_4,param_5);
  memcpy((void *)(iVar1 + 0x18),param_1,0x10);
  pvVar2 = memcpy((void *)(iVar1 + 0x28),param_2,0x10);
                    /* WARNING: Could not recover jumptable at 0x000101d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x324))
            (iVar1,(void *)(iVar1 + 0x18),pvVar2,*(code **)(_r_modules_funcs_p + 0x324));
  return;
}

