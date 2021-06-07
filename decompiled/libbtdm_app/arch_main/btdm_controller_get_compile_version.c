/*
 * Last changed at upstream commit 78180e1b9c68c7068675e892df821bddefe5f88c
 * https://github.com/espressif/esp32c3-bt-lib/commit/78180e1b9c68c7068675e892df821bddefe5f88c
 * Upstream date: 2021-06-07 11:17:03 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 libbtdm_app.a(a6bf46f8)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "a6bf46f";
}

