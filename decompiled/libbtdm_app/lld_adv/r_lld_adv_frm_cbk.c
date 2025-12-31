/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_cbk(undefined4 param_1,undefined1 param_2,uint param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    if (param_3 != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x1b8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x1b8);
    }
                    /* WARNING: Could not recover jumptable at 0x00014e2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_2,param_1,param_3 != 0,UNRECOVERED_JUMPTABLE);
    return;
  }
  if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00014e4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_adv.c",0xbb0,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014e6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x1bc))(param_2,param_1,*(code **)(_r_ip_funcs_p + 0x1bc));
  return;
}

