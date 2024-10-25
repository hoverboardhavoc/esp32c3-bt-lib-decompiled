/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  void *__dest;
  
  if (param_3 == 0) {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x31c))(0x18,0,param_4,param_5);
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x324);
    __dest = param_1;
  }
  else {
    iVar1 = (**(code **)(_r_modules_funcs_p + 0x31c))(0x38,0,param_4,param_5);
    __dest = (void *)(iVar1 + 0x18);
    memcpy(__dest,param_1,0x10);
    param_2 = memcpy((void *)(iVar1 + 0x28),param_2,0x10);
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x324);
  }
                    /* WARNING: Could not recover jumptable at 0x00010180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar1,__dest,param_2);
  return;
}

