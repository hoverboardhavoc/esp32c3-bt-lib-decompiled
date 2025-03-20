/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 uVar1;
  
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_2,param_3,"lld_scan.c",0xa04,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (param_3 == 1) {
    uVar1 = 1;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f4);
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f8);
      }
      else {
        if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00013172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(_r_plf_funcs_p + 0xc))(param_2,param_3,"lld_scan.c",0xa1a);
          return;
        }
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3fc);
      }
                    /* WARNING: Could not recover jumptable at 0x000131be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff);
      return;
    }
    uVar1 = 0;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x3f4);
  }
                    /* WARNING: Could not recover jumptable at 0x00013192. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_2 & 0xff,param_1,uVar1);
  return;
}

