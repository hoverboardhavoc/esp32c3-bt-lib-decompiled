/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
                    /* WARNING: Could not recover jumptable at 0x00010c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*_bt_rf_coex_hooks_p)(0xff,8,0);
    return;
  }
  return;
}

