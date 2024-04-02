/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_isr_hack(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x24) = 0;
    (**(code **)(_r_ip_funcs_p + 0x2d4))(0,0,1,1,*(code **)(_r_ip_funcs_p + 0x2d4));
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  r_lld_per_adv_frm_isr(param_1,param_2,param_3);
  return;
}

