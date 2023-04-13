/*
 * Last changed at upstream commit 688cc3e5db392cd8e80c84c20b86b5ad5a7eff64
 * https://github.com/espressif/esp32c3-bt-lib/commit/688cc3e5db392cd8e80c84c20b86b5ad5a7eff64
 * Upstream date: 2023-04-13 21:28:12 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(8685e3d)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "8685e3d";
}

