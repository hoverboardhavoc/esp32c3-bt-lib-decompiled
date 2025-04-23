/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_phy_upd_proc_err_cb(int param_1,undefined1 *param_2)

{
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010b5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x650))(*param_2,*(code **)(_r_ip_funcs_p + 0x650));
    return;
  }
  if (2 < (param_1 - 1U & 0xff)) {
                    /* WARNING: Could not recover jumptable at 0x00010b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))("llc_phy_upd.c",0x3c2,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
  return;
}

