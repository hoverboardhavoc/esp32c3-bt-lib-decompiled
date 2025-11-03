/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
                    /* WARNING: Could not recover jumptable at 0x00010b6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x650))(*param_2,*(code **)(_r_ip_funcs_p + 0x650));
    return;
  }
  if (2 < (param_1 - 1U & 0xff)) {
                    /* WARNING: Could not recover jumptable at 0x00010b5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))("llc_phy_upd.c",0x3c9,*(code **)(_r_plf_funcs_p + 0xc));
    return;
  }
  return;
}

