/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_evt_canceled_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_evt_canceled_cbk_hack(int param_1)

{
  if (param_1 != 0) {
    g_adv_delay_dis = 1;
  }
  r_lld_adv_evt_canceled_cbk(param_1);
  if (param_1 != 0) {
    g_adv_delay_dis = 0;
  }
  return;
}

