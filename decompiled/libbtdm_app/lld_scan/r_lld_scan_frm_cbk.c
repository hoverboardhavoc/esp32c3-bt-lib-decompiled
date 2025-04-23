/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  code *UNRECOVERED_JUMPTABLE_00;
  
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("lld_scan.c",0xa1c,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (param_3 == 2) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f8);
  }
  else {
    if (param_3 < 3) {
      if (param_3 != 0) {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f4);
      }
      else {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f4);
      }
                    /* WARNING: Could not recover jumptable at 0x00013130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,param_1,param_3 != 0,UNRECOVERED_JUMPTABLE_00);
      return;
    }
    if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00013156. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("lld_scan.c",0xa32,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3fc);
  }
                    /* WARNING: Could not recover jumptable at 0x0001317a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,UNRECOVERED_JUMPTABLE_00);
  return;
}

