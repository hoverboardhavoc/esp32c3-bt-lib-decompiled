/*
 * Last changed at upstream commit 9d40b3bc0ac38d72b66fe0f612a8dda64c7330d7
 * https://github.com/espressif/esp32c3-bt-lib/commit/9d40b3bc0ac38d72b66fe0f612a8dda64c7330d7
 * Upstream date: 2024-01-12 16:10:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(9359a4d)
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
                    /* WARNING: Could not recover jumptable at 0x00010cca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

