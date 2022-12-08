/*
 * Last changed at upstream commit 723f44c70ceea734bb9075b3c59993103d1dac23
 * https://github.com/espressif/esp32c3-bt-lib/commit/723f44c70ceea734bb9075b3c59993103d1dac23
 * Upstream date: 2022-12-08 17:22:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2b9445a6) - Fixed some memory was not released after bluetooth controller init failed
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "2b9445a";
}

