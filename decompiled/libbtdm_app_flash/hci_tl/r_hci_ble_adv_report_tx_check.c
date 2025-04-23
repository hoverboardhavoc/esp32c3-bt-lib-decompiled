/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_ble_adv_report_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_ble_adv_report_tx_check(int param_1)

{
  if (((*(short *)(param_1 + 4) == 0x1104) && (*(byte *)(param_1 + 0xc) < 0x10)) &&
     ((0xa004U >> (*(byte *)(param_1 + 0xc) & 0x1f) & 1) != 0)) {
    if (r_co_util_unpack == (code)0x0) {
      r_assert_err(0,"hci_tl.c",0x175);
      return;
    }
    r_co_util_unpack = (code)((char)r_co_util_unpack + -1);
  }
  return;
}

