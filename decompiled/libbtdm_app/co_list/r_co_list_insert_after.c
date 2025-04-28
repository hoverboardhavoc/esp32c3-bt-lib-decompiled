/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> co_list.o -> r_co_list_insert_after
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_co_list_insert_after(undefined4 *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"co_list.c",0x1ac,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)*param_1;
    while( true ) {
      if (piVar2 == param_2) {
        iVar1 = *piVar2;
        if (iVar1 == 0) {
          param_1[1] = param_3;
        }
        *param_3 = iVar1;
        *piVar2 = (int)param_3;
        return;
      }
      if (piVar2 == (int *)0x0) break;
      piVar2 = (int *)*piVar2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x44))(param_1,param_3,*(code **)(_r_modules_funcs_p + 0x44));
  return;
}

