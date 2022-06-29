/*
 * Last changed at upstream commit 614154ba4a7b5e55e943f92c194de497e6ce4219
 * https://github.com/espressif/esp32c3-bt-lib/commit/614154ba4a7b5e55e943f92c194de497e6ce4219
 * Upstream date: 2022-06-29 19:01:17 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(16cffbc)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_on_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_on_reset(void)

{
  (**(code **)(_r_modules_funcs_p + 0x280))(*(code **)(_r_modules_funcs_p + 0x280));
  rw_rf_le_exit_test_mode();
  if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0001097a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(0xff,8,0);
    return;
  }
  return;
}

