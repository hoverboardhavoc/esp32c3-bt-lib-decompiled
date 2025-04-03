/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_cbk(undefined4 param_1,undefined1 param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if (param_3 == 1) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x1b8);
    uVar1 = 1;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        return;
      }
      if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00014e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_adv.c",0xb71);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00014e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x1bc))(param_2,param_1);
      return;
    }
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x1b8);
  }
                    /* WARNING: Could not recover jumptable at 0x00014e22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_2,param_1,uVar1);
  return;
}

