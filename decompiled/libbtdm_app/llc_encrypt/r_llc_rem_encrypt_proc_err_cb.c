/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
                    /* WARNING: Could not recover jumptable at 0x00010d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_encrypt.c",0x5f3);
      return;
    }
    if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
      return;
    }
    uVar1 = 0x3d;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x59c);
  }
                    /* WARNING: Could not recover jumptable at 0x00010d3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0x13,uVar1);
  return;
}

