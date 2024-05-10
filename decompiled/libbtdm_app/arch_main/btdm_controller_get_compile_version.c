/*
 * Last changed at upstream commit 1a086eab61e78fa243d67c33206ece4022129ee1
 * https://github.com/espressif/esp32c3-bt-lib/commit/1a086eab61e78fa243d67c33206ece4022129ee1
 * Upstream date: 2024-05-10 19:28:08 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(eca46a0)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "eca46a0";
}

