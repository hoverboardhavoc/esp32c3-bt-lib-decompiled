/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x3b6,*(code **)(_r_plf_funcs_p + 8));
    }
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
                    /* WARNING: Could not recover jumptable at 0x00011404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x300))(*(undefined1 *)(param_1 + 0x52));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001141e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("lld_per_adv.c",0x3c0);
  return;
}

