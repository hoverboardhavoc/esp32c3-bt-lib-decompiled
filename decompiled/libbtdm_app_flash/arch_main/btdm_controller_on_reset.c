/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_on_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_on_reset(void)

{
  r_rwip_reset();
  ble_util_buf_reset();
  rw_rf_le_exit_test_mode();
  if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) && ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00010c92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(0xff,8,0);
    return;
  }
  return;
}

