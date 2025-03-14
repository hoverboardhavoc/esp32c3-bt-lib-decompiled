/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_data_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_data_update_hack(int param_1,int param_2)

{
  r_lld_per_adv_data_update();
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (((*(int *)(&lld_per_adv_env + param_1 * 4) != 0) &&
      (*(char *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x53) != '\0')) && (param_2 == 0)) {
    periodic_adv_data_need_to_set[param_1] = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00012204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

