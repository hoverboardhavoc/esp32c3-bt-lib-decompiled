/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_ble_adv_report_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_ble_adv_report_tx_check(int param_1)

{
  if ((*(short *)(param_1 + 4) == 0x1104) &&
     ((*(byte *)(param_1 + 0xc) == 2 || ((*(byte *)(param_1 + 0xc) & 0xfd) == 0xd)))) {
    if (r_co_util_unpack == (code)0x0) {
      r_assert_err(0,"hci_tl.c",0x175);
      return;
    }
    r_co_util_unpack = (code)((char)r_co_util_unpack + -1);
  }
  return;
}

