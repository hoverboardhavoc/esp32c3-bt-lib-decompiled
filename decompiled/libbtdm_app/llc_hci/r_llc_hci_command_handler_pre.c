/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_hci.o -> r_llc_hci_command_handler_pre
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

