/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_cbk(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 1) {
    uVar1 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x208);
  }
  else {
    if (param_2 == 2) {
                    /* WARNING: Could not recover jumptable at 0x000106e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x210))(2,*(code **)(_r_ip_funcs_p + 0x210));
      return;
    }
    if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000106fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,"lld_test.c",0x245,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x208);
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000106c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1,UNRECOVERED_JUMPTABLE);
  return;
}

