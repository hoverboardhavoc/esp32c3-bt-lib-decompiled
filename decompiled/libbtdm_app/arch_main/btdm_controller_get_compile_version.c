/*
 * Last changed at upstream commit 08e289633f823191a6c526377bfd68f31fb392e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/08e289633f823191a6c526377bfd68f31fb392e0
 * Upstream date: 2023-06-06 21:15:22 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(a186b41)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "a186b41";
}

