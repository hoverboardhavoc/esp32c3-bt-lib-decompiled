/*
 * Last changed at upstream commit f3c359a685a17bcc301e43778e7f581605e32d0a
 * https://github.com/espressif/esp32c3-bt-lib/commit/f3c359a685a17bcc301e43778e7f581605e32d0a
 * Upstream date: 2022-07-04 22:08:59 +0800
 * Upstream subject: fix ke_mem.c assert(0821b2a)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "0821b2a";
}

