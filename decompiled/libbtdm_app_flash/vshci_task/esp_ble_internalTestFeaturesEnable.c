/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> vshci_task.o -> esp_ble_internalTestFeaturesEnable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_ble_internalTestFeaturesEnable(int param_1)

{
  code *pcVar1;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_vendor_ble_qa_test_cmd_handler;
  }
  ble_cmd_handler_register(0xfd13,pcVar1);
  btdm_linkbl_filter_init(param_1);
  return;
}

