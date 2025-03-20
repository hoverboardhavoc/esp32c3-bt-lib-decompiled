/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> vshci_task.o -> esp_ble_internalTestFeaturesEnable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_ble_internalTestFeaturesEnable(int param_1)

{
  code *pcVar1;
  short *psVar2;
  int iVar3;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_vendor_ble_qa_test_cmd_handler;
  }
  psVar2 = &hci_command_handler_tab_esp_hack;
  iVar3 = 0;
  do {
    if (*psVar2 == -0x2ed) {
      (&PTR_hci_unknown_hci_cmd_handler_00010f24)[iVar3 * 2] = pcVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 4;
  } while (iVar3 != 7);
  return;
}

