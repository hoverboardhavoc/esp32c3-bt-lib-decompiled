/*
 * Last changed at upstream commit af6be404ea583da57f9a4f0dfe7e02351ff5aa0d
 * https://github.com/espressif/esp32c3-bt-lib/commit/af6be404ea583da57f9a4f0dfe7e02351ff5aa0d
 * Upstream date: 2023-10-20 16:57:24 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ad8513)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "ad85134";
}

