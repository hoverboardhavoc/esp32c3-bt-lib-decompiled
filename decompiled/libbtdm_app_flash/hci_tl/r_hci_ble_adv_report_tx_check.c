/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

