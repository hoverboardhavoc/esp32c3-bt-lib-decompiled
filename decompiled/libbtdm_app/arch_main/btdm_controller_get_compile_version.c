/*
 * Last changed at upstream commit a6ca5e21f7afabe00db544003419be77e89b9a99
 * https://github.com/espressif/esp32c3-bt-lib/commit/a6ca5e21f7afabe00db544003419be77e89b9a99
 * Upstream date: 2024-06-25 16:47:31 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(66b5cc0)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "66b5cc0";
}

