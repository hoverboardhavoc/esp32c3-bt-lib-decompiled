/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_evt_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_evt_cbk(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9cc);
  }
  else {
    if (param_1 != 1) {
                    /* WARNING: Could not recover jumptable at 0x00010eca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 0xc))("lld_cca.c",0x331);
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9d0);
  }
                    /* WARNING: Could not recover jumptable at 0x00010edc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

