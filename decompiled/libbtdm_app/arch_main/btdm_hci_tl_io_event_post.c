/*
 * Last changed at upstream commit 068bceb41f08099d1e831f6c7ef8153ec7a344ca
 * https://github.com/espressif/esp32c3-bt-lib/commit/068bceb41f08099d1e831f6c7ef8153ec7a344ca
 * Upstream date: 2022-08-22 15:06:11 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a49744)
 * Source: libbtdm_app -> arch_main.o -> btdm_hci_tl_io_event_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_hci_tl_io_event_post(void)

{
                    /* WARNING: Could not recover jumptable at 0x00011296. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0x2c))(1);
  return;
}

