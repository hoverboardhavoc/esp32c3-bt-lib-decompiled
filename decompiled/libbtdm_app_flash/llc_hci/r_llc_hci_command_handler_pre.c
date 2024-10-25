/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_pre(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0x2013) {
    uVar1 = hci_le_con_upd_cmd_pre_handler(param_1,0x2013);
    return uVar1;
  }
  if (param_2 != 0x2022) {
    return 0;
  }
  uVar1 = hci_le_set_data_len_cmd_pre_handler();
  return uVar1;
}

