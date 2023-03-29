/*
 * Last changed at upstream commit d83f7d618a7a86f4703b909f8fc0ddcf8fd48a89
 * https://github.com/espressif/esp32c3-bt-lib/commit/d83f7d618a7a86f4703b909f8fc0ddcf8fd48a89
 * Upstream date: 2023-03-29 17:09:21 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(921f253)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "921f253";
}

