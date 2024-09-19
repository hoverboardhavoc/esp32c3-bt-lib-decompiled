/*
 * Last changed at upstream commit 5c913171361dac0821e15e83cc0cf604149e1b84
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c913171361dac0821e15e83cc0cf604149e1b84
 * Upstream date: 2024-09-19 15:19:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(e9ae856)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "e9ae856";
}

