/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
    _DAT_600c0024 = _DAT_600c0024 & 0xfff000 | *(uint *)(CSWTCH_509 + param_1 * 4);
    return (_DAT_600c0024 & *(uint *)(CSWTCH_509 + param_1 * 4)) != 0;
  }
  return false;
}

