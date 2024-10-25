/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_aes_res_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_aes_res_cb(undefined1 param_1,void *param_2,uint param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x105,(param_3 & 0xff) << 8 | 1,0x11,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = param_1;
  memcpy(puVar1 + 1,param_2,0x10);
                    /* WARNING: Could not recover jumptable at 0x0001005e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar1);
  return;
}

