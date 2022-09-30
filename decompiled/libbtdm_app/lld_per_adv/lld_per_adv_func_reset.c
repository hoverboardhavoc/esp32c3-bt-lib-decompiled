/*
 * Last changed at upstream commit 43b48d75e7e468c0cccd038721e1184dae6aabac
 * https://github.com/espressif/esp32c3-bt-lib/commit/43b48d75e7e468c0cccd038721e1184dae6aabac
 * Upstream date: 2022-09-30 15:41:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(4ec6feee)
 * Source: libbtdm_app -> lld_per_adv.o -> lld_per_adv_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_per_adv_func_reset(void)

{
  *(code **)(_r_ip_funcs_p + 0x300) = r_lld_per_adv_sched_hack;
  return;
}

