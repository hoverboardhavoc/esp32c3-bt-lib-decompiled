/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_hci.o -> r_llc_hci_command_handler_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_hci_command_handler_search(uint param_1)

{
  ushort *puVar1;
  
  puVar1 = &llc_hci_command_handler_tab;
  do {
    if (*puVar1 == param_1) {
      return *(undefined4 *)(puVar1 + 2);
    }
    puVar1 = puVar1 + 4;
  } while (puVar1 != (ushort *)&ble_acl_data_tx_cb);
  return 0;
}

