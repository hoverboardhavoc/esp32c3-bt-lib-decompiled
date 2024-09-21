/*
 * Last changed at upstream commit 061e70c319576bf28b5695f5478dbe01ad18b18d
 * https://github.com/espressif/esp32c3-bt-lib/commit/061e70c319576bf28b5695f5478dbe01ad18b18d
 * Upstream date: 2024-09-21 10:42:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(63eb54d)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "63eb54d";
}

