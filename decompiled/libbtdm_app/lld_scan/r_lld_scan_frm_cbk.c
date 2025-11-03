/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    (**(code **)(_r_plf_funcs_p + 0xc))("lld_scan.c",0xa5b,*(code **)(_r_plf_funcs_p + 0xc));
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
                    /* WARNING: Could not recover jumptable at 0x00013174. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,param_1,param_3 != 0,UNRECOVERED_JUMPTABLE_00);
      return;
    }
    if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x0001319a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("lld_scan.c",0xa71,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3fc);
  }
                    /* WARNING: Could not recover jumptable at 0x000131be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,UNRECOVERED_JUMPTABLE_00);
  return;
}

