/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_err_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_proc_err_ind(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x21a,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (((iVar1 != 0) && (puVar2 = *(undefined4 **)(iVar1 + param_2 * 4), puVar2 != (undefined4 *)0x0)
      ) && (UNRECOVERED_JUMPTABLE = (code *)*puVar2, UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00010a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_3,param_4);
    return;
  }
  return;
}

