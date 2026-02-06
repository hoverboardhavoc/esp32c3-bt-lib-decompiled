/*
 * Last changed at upstream commit ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * https://github.com/espressif/esp32c3-bt-lib/commit/ebd6043a8e3c3bbde45ee483895303b9c1229ab5
 * Upstream date: 2026-02-06 15:59:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b7de11e)
 * Source: libbtdm_app -> arch_main.o -> btdm_lpclk_select_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool btdm_lpclk_select_src(uint param_1)

{
  if (param_1 < 4) {
    _DAT_600c0024 = _DAT_600c0024 & 0xfff000 | *(uint *)(CSWTCH_519 + param_1 * 4);
    return (_DAT_600c0024 & *(uint *)(CSWTCH_519 + param_1 * 4)) != 0;
  }
  return false;
}

