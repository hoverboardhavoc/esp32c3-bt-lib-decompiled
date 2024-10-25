/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> aes_cmac.o -> r_rw_cryto_aes_cmac
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_cryto_aes_cmac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5)

{
  (**(code **)(_r_modules_funcs_p + 0x31c))
            (0x34,*(undefined4 *)(_r_modules_funcs_p + 0x340),param_4,param_5,
             *(code **)(_r_modules_funcs_p + 0x31c));
                    /* WARNING: Could not recover jumptable at 0x00010046. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x344))(param_1,param_2,param_3);
  return;
}

