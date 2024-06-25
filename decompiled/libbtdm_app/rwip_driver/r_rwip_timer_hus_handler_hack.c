/*
 * Last changed at upstream commit a6ca5e21f7afabe00db544003419be77e89b9a99
 * https://github.com/espressif/esp32c3-bt-lib/commit/a6ca5e21f7afabe00db544003419be77e89b9a99
 * Upstream date: 2024-06-25 16:47:31 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(66b5cc0)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_hus_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hus_handler_hack(void)

{
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_rwip_timer_hus_handler();
                    /* WARNING: Could not recover jumptable at 0x000105fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

