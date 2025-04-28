/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vshci_task.o -> adv_stack_enableClearLegacyAdvVsCmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void adv_stack_enableClearLegacyAdvVsCmd(int param_1)

{
  code *pcVar1;
  short *psVar2;
  int iVar3;
  
  if (param_1 == 0) {
    pcVar1 = hci_unknown_hci_cmd_handler;
  }
  else {
    pcVar1 = hci_vendor_ble_clear_adv_cmd_handler;
  }
  psVar2 = &hci_command_handler_tab_esp_hack;
  iVar3 = 0;
  do {
    if (*psVar2 == -0x2f4) {
      (&PTR_hci_unknown_hci_cmd_handler_00011108)[iVar3 * 2] = pcVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    psVar2 = psVar2 + 4;
  } while (iVar3 != 7);
  return;
}

