/*
 * Last changed at upstream commit 393ac4c33b419226aac9d1e8f1b5d553b7f3bc97
 * https://github.com/espressif/esp32c3-bt-lib/commit/393ac4c33b419226aac9d1e8f1b5d553b7f3bc97
 * Upstream date: 2023-12-19 16:42:02 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(b877d666)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "b877d66";
}

