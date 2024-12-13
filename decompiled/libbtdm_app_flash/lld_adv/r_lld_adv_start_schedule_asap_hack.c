/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_schedule_asap_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_schedule_asap_hack(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_lld_adv_start_schedule_asap(param_1,param_2,param_3);
                    /* WARNING: Could not recover jumptable at 0x000157c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

