/*
 * Last changed at upstream commit b8ef2c474d392a88ea7e6626f89acf1fa5f30e4a
 * https://github.com/espressif/esp32c3-bt-lib/commit/b8ef2c474d392a88ea7e6626f89acf1fa5f30e4a
 * Upstream date: 2024-09-06 16:51:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(c66a703)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "c66a703";
}

