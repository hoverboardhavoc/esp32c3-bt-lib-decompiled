/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
                    /* WARNING: Could not recover jumptable at 0x00015178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_2,param_1,param_3 != 0,UNRECOVERED_JUMPTABLE);
    return;
  }
  if (param_3 != 4) {
                    /* WARNING: Could not recover jumptable at 0x00015198. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(param_3,"lld_adv.c",0xc07,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000151b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x1bc))(param_2,param_1,*(code **)(_r_ip_funcs_p + 0x1bc));
  return;
}

