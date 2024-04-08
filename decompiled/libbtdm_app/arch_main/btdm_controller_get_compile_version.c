/*
 * Last changed at upstream commit e3971a15e5ea6c13affc45192625d2da23a5399b
 * https://github.com/espressif/esp32c3-bt-lib/commit/e3971a15e5ea6c13affc45192625d2da23a5399b
 * Upstream date: 2024-04-08 11:46:33 +0800
 * Upstream subject: fix(ble/controller): Fixed LoadProhibited after bluetooth deinit(e07d7e27)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "e07d7e2";
}

