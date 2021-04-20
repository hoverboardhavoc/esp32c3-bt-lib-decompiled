/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_coexist_hook.o -> coex_hook_calc_aux_adv_dur
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int coex_hook_calc_aux_adv_dur(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_1 / 0xf0 + 1 & 0xff) - 1;
  iVar2 = (**(code **)(_r_modules_funcs_p + 4))(0xff,*(code **)(_r_modules_funcs_p + 4));
  iVar3 = (**(code **)(_r_modules_funcs_p + 4))
                    ((param_1 + iVar1 * -0xf0 & 0xffff) + 1 & 0xff,param_2,
                     *(code **)(_r_modules_funcs_p + 4));
  return iVar3 + 300 + (iVar2 + 300) * iVar1;
}

