/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
 * Source: libbtdm_app -> arch_main.o -> btdm_hci_tl_io_event_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_hci_tl_io_event_post(void)

{
                    /* WARNING: Could not recover jumptable at 0x000112ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0x2c))(1);
  return;
}

