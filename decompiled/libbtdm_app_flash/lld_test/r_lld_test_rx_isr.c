/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  r_assert_err(0,"lld_test.c",0x1e8);
  return;
}

