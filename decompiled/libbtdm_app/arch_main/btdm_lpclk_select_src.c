/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
    _DAT_600c0024 = _DAT_600c0024 & 0xfff000 | *(uint *)(&_LANCHOR1 + param_1 * 4);
    return (_DAT_600c0024 & *(uint *)(&_LANCHOR1 + param_1 * 4)) != 0;
  }
  return false;
}

