/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_cbk(undefined4 param_1,int param_2)

{
  if (param_2 != 1) {
    if (param_2 == 2) {
                    /* WARNING: Could not recover jumptable at 0x000106c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x210))(2,*(code **)(_r_ip_funcs_p + 0x210));
      return;
    }
    if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000106e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,"lld_test.c",0x241,*(code **)(_r_plf_funcs_p + 0xc));
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000106b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x208))(*(code **)(_r_ip_funcs_p + 0x208));
  return;
}

