/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_rx_isr(void)

{
  int iVar1;
  
  if (_lld_test_env != 0) {
    while (iVar1 = r_lld_rxdesc_check_hack(0), iVar1 != 0) {
      r_lld_rxdesc_free();
    }
    return;
  }
  r_assert_err(0,"lld_test.c",0x1df);
  return;
}

