/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
 * Source: libbtdm_app -> llm_scan.o -> llm_scan_period_to_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_scan_period_to_handler_hack(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar1 < *(byte *)(iVar2 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\a'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    (**(code **)(_r_ip_funcs_p + 0x514))(uVar1,1,*(code **)(_r_ip_funcs_p + 0x514));
    if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0))
    {
      (*(code *)*_bt_rf_coex_hooks_p)(uVar1,3,1);
    }
  }
  return 0;
}

