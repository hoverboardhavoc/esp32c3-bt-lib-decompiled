/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_err_cb(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x59c);
  }
  else {
    if (2 < (param_2 - 1U & 0xff)) {
                    /* WARNING: Could not recover jumptable at 0x00010e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_encrypt.c",0x614,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
    if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
      return;
    }
    uVar1 = 0x3d;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x59c);
  }
                    /* WARNING: Could not recover jumptable at 0x00010e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0x13,uVar1,UNRECOVERED_JUMPTABLE);
  return;
}

