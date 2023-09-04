/*
 * Last changed at upstream commit 9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * https://github.com/espressif/esp32c3-bt-lib/commit/9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * Upstream date: 2023-09-04 20:35:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a1003fc)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "3a1003f";
}

