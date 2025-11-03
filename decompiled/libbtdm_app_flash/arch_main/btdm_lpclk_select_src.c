/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_lpclk_select_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool btdm_lpclk_select_src(uint param_1)

{
  if (param_1 < 4) {
    _DAT_600c0024 = _DAT_600c0024 & 0xfff000 | *(uint *)(CSWTCH_303 + param_1 * 4);
    return (_DAT_600c0024 & *(uint *)(CSWTCH_303 + param_1 * 4)) != 0;
  }
  return false;
}

