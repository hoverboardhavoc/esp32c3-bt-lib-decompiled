/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
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
                    /* WARNING: Could not recover jumptable at 0x00010d2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(0xff,8,0);
    return;
  }
  return;
}

