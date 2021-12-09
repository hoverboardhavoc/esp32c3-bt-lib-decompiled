/*
 * Last changed at upstream commit f9ffd57d8f829cc9079d9c51da6886844eee94d0
 * https://github.com/espressif/esp32c3-bt-lib/commit/f9ffd57d8f829cc9079d9c51da6886844eee94d0
 * Upstream date: 2021-12-09 12:38:22 +0530
 * Upstream subject: Fixing scenario where ACL Rx data is sent to host before enc change event [19bdc26c].
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "19bdc26";
}

