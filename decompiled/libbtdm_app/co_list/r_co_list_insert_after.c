/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  int *piVar1;
  int iVar2;
  
  if (param_3 == (int *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"co_list.c",0x1ac,*(code **)(_r_plf_funcs_p + 8));
  }
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    while( true ) {
      if (piVar1 == param_2) {
        iVar2 = *param_2;
        if (iVar2 == 0) {
          param_1[1] = param_3;
        }
        *param_3 = iVar2;
        *param_2 = (int)param_3;
        return;
      }
      if (piVar1 == (int *)0x0) break;
      piVar1 = (int *)*piVar1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x44))(param_1,param_3,*(code **)(_r_modules_funcs_p + 0x44));
  return;
}

