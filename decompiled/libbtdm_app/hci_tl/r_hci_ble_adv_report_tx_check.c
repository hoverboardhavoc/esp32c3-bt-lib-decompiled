/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_ble_adv_report_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_ble_adv_report_tx_check(int param_1)

{
  if ((*(short *)(param_1 + 4) == 0x1104) &&
     ((*(byte *)(param_1 + 0xc) == 2 || ((*(byte *)(param_1 + 0xc) & 0xfd) == 0xd)))) {
    if (g_bt_plf_log_level == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00010274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x175);
      return;
    }
    g_bt_plf_log_level = g_bt_plf_log_level + -1;
  }
  return;
}

