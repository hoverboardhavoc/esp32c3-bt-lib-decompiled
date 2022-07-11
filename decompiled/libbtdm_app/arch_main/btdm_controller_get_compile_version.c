/*
 * Last changed at upstream commit d1c2082e5633a89c6fd6051c7761c1e697cb7a2e
 * https://github.com/espressif/esp32c3-bt-lib/commit/d1c2082e5633a89c6fd6051c7761c1e697cb7a2e
 * Upstream date: 2022-07-11 09:57:43 +0800
 * Upstream subject: fix adv report duplicate check
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "05195c9";
}

