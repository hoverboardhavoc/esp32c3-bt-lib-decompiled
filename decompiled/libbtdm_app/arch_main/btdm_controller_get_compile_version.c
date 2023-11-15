/*
 * Last changed at upstream commit cecbe387799b41346c0affab41f339306a33e518
 * https://github.com/espressif/esp32c3-bt-lib/commit/cecbe387799b41346c0affab41f339306a33e518
 * Upstream date: 2023-11-15 16:38:32 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2758518)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "2758518";
}

