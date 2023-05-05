/*
 * Last changed at upstream commit d7513ebe88d7d207f6c062ce9381d347a0a70918
 * https://github.com/espressif/esp32c3-bt-lib/commit/d7513ebe88d7d207f6c062ce9381d347a0a70918
 * Upstream date: 2023-05-05 21:49:57 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85b425c)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "85b425c";
}

