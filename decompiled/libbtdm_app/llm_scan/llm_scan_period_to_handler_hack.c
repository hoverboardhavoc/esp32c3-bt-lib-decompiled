/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> llm_scan_period_to_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llm_scan_period_to_handler_hack(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_a1;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x23) == '\0') {
    return 0;
  }
  uVar1 = 0;
  while ((param_1 = (**(code **)(_r_plf_funcs_p + 0x38))
                              (param_1,param_2,*(code **)(_r_plf_funcs_p + 0x38)),
         uVar1 < *(byte *)(param_1 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\a'))) {
    uVar1 = uVar1 + 1 & 0xff;
    param_2 = extraout_a1;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) &&
      ((**(code **)(_r_ip_funcs_p + 0x514))(uVar1,1,*(code **)(_r_ip_funcs_p + 0x514)),
      _bt_rf_coex_hooks_p != (undefined4 *)0x0)) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
    (*(code *)*_bt_rf_coex_hooks_p)(uVar1,3,1);
  }
  return 0;
}

