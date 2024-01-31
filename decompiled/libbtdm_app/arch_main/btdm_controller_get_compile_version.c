/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "91980c2";
}

