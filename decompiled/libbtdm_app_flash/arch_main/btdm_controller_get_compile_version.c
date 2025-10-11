/*
 * Last changed at upstream commit 42c965137ecc3c6cf3d38ecece7ce71ffc461353
 * https://github.com/espressif/esp32c3-bt-lib/commit/42c965137ecc3c6cf3d38ecece7ce71ffc461353
 * Upstream date: 2025-10-11 11:01:59 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(18b5cbe)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "18b5cbe";
}

