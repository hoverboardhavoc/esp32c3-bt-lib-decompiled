/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_loc_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_encrypt_proc_err_cb(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 2) {
    uVar1 = param_3[1];
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      uVar1 = *param_3;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
    }
    else {
      uVar1 = 0x1a;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x594);
    }
  }
  else {
    if (param_2 != 3) {
                    /* WARNING: Could not recover jumptable at 0x00010db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("llc_encrypt.c",0x5eb,*(code **)(_r_plf_funcs_p + 0xc));
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
                    /* WARNING: Could not recover jumptable at 0x00010d9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(9,uVar1,UNRECOVERED_JUMPTABLE);
  return;
}

