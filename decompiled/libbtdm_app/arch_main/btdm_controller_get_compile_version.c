/*
 * Last changed at upstream commit 79152b519023f26462498f3ef8805cff2a80e193
 * https://github.com/espressif/esp32c3-bt-lib/commit/79152b519023f26462498f3ef8805cff2a80e193
 * Upstream date: 2022-11-29 17:30:47 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02bfb7f1) - Fixed lld_con.c line 3048 assert - Fixed crash sometimes when connected as a slave by the 8th device
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "02bfb7f";
}

