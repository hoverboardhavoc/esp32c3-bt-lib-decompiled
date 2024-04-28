/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_btdm_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 coex_schm_btdm_callback(int param_1)

{
  int iVar1;
  
  iVar1 = btdm_controller_is_enabled();
  if ((iVar1 != 0) && (param_1 == 0)) {
    (**(code **)(_r_plf_funcs_p + 0x110))(1,0,*(code **)(_r_plf_funcs_p + 0x110));
  }
  return 0;
}

