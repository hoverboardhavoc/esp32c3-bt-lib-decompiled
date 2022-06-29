/*
 * Last changed at upstream commit 614154ba4a7b5e55e943f92c194de497e6ce4219
 * https://github.com/espressif/esp32c3-bt-lib/commit/614154ba4a7b5e55e943f92c194de497e6ce4219
 * Upstream date: 2022-06-29 19:01:17 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(16cffbc)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "16cffbc";
}

