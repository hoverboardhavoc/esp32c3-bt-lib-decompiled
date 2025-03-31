/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_err_cb(int param_1,uint param_2,undefined1 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined1 uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x59c);
  }
  else {
    if (3 < param_2) {
                    /* WARNING: Could not recover jumptable at 0x00010e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_encrypt.c",0x614);
      return;
    }
    if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
      return;
    }
    uVar1 = 0x3d;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x59c);
  }
                    /* WARNING: Could not recover jumptable at 0x00010e5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0x13,uVar1);
  return;
}

