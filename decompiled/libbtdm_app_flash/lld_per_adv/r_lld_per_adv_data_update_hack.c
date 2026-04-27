/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_data_update_hack(int param_1,int param_2,uint param_3)

{
  r_ble_log_internal_x1(0x4004012e,param_2 << 0x18 | param_1 << 0x10 | param_3);
  r_lld_per_adv_data_update(param_1,param_2,param_3);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (((*(int *)(&lld_per_adv_env + param_1 * 4) != 0) &&
      (*(char *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x53) != '\0')) && (param_2 == 0)) {
    periodic_adv_data_need_to_set[param_1] = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00012548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

