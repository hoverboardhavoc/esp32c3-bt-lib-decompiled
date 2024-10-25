/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_err_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_err_ind(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x21a);
  }
  if (((iVar1 != 0) && (puVar2 = *(undefined4 **)(iVar1 + param_2 * 4), puVar2 != (undefined4 *)0x0)
      ) && (UNRECOVERED_JUMPTABLE = (code *)*puVar2, UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00010878. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_3,param_4);
    return;
  }
  return;
}

