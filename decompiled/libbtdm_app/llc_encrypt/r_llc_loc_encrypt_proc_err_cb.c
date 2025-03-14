/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_loc_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_encrypt_proc_err_cb(int param_1,int param_2,undefined1 *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined1 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 0x1a;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
  }
  else if (param_2 == 0) {
    uVar1 = *param_3;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
  }
  else if (param_2 == 2) {
    uVar1 = param_3[1];
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
  }
  else {
    if (param_2 != 3) {
                    /* WARNING: Could not recover jumptable at 0x00010c7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_encrypt.c",0x5ca);
      return;
    }
    if (param_3[1] == '\x03') {
      uVar1 = param_3[2];
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
    }
    else {
      if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
        return;
      }
      uVar1 = 0x3d;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(9,uVar1);
  return;
}

