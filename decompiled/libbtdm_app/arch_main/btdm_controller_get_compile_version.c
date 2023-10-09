/*
 * Last changed at upstream commit 7fb979154bec81163d55aa4e3134425aea0d52ab
 * https://github.com/espressif/esp32c3-bt-lib/commit/7fb979154bec81163d55aa4e3134425aea0d52ab
 * Upstream date: 2023-10-09 11:09:21 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(510fd043)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "510fd04";
}

