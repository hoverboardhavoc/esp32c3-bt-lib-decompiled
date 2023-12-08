/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "65db61f";
}

