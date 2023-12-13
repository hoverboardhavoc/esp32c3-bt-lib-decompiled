/*
 * Last changed at upstream commit e651b371c861ba23111db51dd76fd01fc2a69079
 * https://github.com/espressif/esp32c3-bt-lib/commit/e651b371c861ba23111db51dd76fd01fc2a69079
 * Upstream date: 2023-12-13 19:24:11 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(9129dec)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "9129dec";
}

