/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
 * Source: libbtdm_app -> rf_coexist_hook.o -> bt_rf_coex_hook_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bt_rf_coex_hook_register(void)

{
  _LANCHOR0 = 0;
  _LANCHOR3 = 0;
  DAT_00010478 = 0;
  DAT_0001047c = 0;
  bt_rf_coex_hooks_p_set(&_LANCHOR6);
  return;
}

