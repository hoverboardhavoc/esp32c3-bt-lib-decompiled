/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_ble_adv_report_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_ble_adv_report_tx_check(int param_1)

{
  if (((*(short *)(param_1 + 4) == 0x1104) && (*(byte *)(param_1 + 0xc) < 0x10)) &&
     ((0xa004U >> (*(byte *)(param_1 + 0xc) & 0x1f) & 1) != 0)) {
    if (g_bt_plf_log_level == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00010288. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x175,*(code **)(_r_plf_funcs_p + 8));
      return;
    }
    g_bt_plf_log_level = g_bt_plf_log_level + -1;
  }
  return;
}

