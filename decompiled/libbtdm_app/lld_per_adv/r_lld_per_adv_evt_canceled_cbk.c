/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_evt_canceled_cbk(int param_1)

{
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x53) != '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x3dd,*(code **)(_r_plf_funcs_p + 8));
    }
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
                    /* WARNING: Could not recover jumptable at 0x00011416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x300))
              (*(undefined1 *)(param_1 + 0x52),*(code **)(_r_ip_funcs_p + 0x300));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001142e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0x10000,999,*(code **)(_r_plf_funcs_p + 8));
  return;
}

