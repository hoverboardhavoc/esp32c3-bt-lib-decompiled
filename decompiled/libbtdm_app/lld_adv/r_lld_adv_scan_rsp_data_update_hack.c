/*
 * Last changed at upstream commit af6be404ea583da57f9a4f0dfe7e02351ff5aa0d
 * https://github.com/espressif/esp32c3-bt-lib/commit/af6be404ea583da57f9a4f0dfe7e02351ff5aa0d
 * Upstream date: 2023-10-20 16:57:24 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ad8513)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_scan_rsp_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_update_hack(int param_1,int param_2)

{
  r_lld_adv_scan_rsp_data_update();
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (((*(int *)(&lld_adv_env + param_1 * 4) != 0) &&
      (*(char *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x89) != '\0')) && (param_2 == 0)) {
    adv_scan_rsp_data_need_to_set[param_1] = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010caa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

