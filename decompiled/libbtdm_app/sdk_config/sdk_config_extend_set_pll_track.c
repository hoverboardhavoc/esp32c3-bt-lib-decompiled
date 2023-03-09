/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> sdk_config.o -> sdk_config_extend_set_pll_track
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdk_config_extend_set_pll_track(undefined1 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(**(code **)(_r_plf_funcs_p + 0xf4))(*(code **)(_r_plf_funcs_p + 0xf4));
  *puVar1 = param_1;
  return;
}

