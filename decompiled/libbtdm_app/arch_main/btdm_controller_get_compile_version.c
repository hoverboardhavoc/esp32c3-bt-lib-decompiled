/*
 * Last changed at upstream commit 29d5555ca1febeb132f5a13556893f3419d2d640
 * https://github.com/espressif/esp32c3-bt-lib/commit/29d5555ca1febeb132f5a13556893f3419d2d640
 * Upstream date: 2024-06-03 11:12:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(0738a61)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "0738a61";
}

