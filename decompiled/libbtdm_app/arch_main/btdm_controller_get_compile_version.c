/*
 * Last changed at upstream commit d53a6a695af1e78a6f36691e2cf525f9787abfdb
 * https://github.com/espressif/esp32c3-bt-lib/commit/d53a6a695af1e78a6f36691e2cf525f9787abfdb
 * Upstream date: 2024-07-11 12:21:12 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(abd7733)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "abd7733";
}

