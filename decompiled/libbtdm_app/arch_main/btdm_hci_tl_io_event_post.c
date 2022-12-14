/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
 * Source: libbtdm_app -> arch_main.o -> btdm_hci_tl_io_event_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_hci_tl_io_event_post(void)

{
                    /* WARNING: Could not recover jumptable at 0x00011278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0x2c))(1);
  return;
}

