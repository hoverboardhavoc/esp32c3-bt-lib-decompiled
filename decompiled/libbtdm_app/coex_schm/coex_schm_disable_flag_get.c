/*
 * Last changed at upstream commit 55485554203a225ff09a8dfcf5284c46b70aa0bd
 * https://github.com/espressif/esp32c3-bt-lib/commit/55485554203a225ff09a8dfcf5284c46b70aa0bd
 * Upstream date: 2024-07-12 15:45:32 +0800
 * Upstream subject: fix(coex): Fixed coexist LoadProhibited issue(e4ba7f6)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_disable_flag_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 coex_schm_disable_flag_get(uint param_1)

{
  if (param_1 < 7) {
    return (&coex_schm_btdm_env)[param_1];
  }
  return 0;
}

