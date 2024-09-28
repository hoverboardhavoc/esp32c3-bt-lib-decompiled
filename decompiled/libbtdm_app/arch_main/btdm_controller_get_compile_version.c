/*
 * Last changed at upstream commit 73ae8322b2d7c990c195bfe3dca118ff43196f70
 * https://github.com/espressif/esp32c3-bt-lib/commit/73ae8322b2d7c990c195bfe3dca118ff43196f70
 * Upstream date: 2024-09-28 12:07:47 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(01cc408)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "01cc408";
}

