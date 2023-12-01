/*
 * Last changed at upstream commit f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * https://github.com/espressif/esp32c3-bt-lib/commit/f103dfec019fdd5bf9255abcaeaf20c707b26dc6
 * Upstream date: 2023-12-01 21:11:21 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b8f0db9)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "b8f0db9";
}

