/*
 * Last changed at upstream commit 8ce2a3620a07ba62084c75489b62d44de9ba1824
 * https://github.com/espressif/esp32c3-bt-lib/commit/8ce2a3620a07ba62084c75489b62d44de9ba1824
 * Upstream date: 2021-04-23 19:57:05 +0800
 * Upstream subject: update esp32c3 and esp32s3 bt lib (6ab3130)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "6ab3130";
}

