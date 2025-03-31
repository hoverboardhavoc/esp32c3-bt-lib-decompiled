/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> vshci_task.o -> ble_cmd_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ble_cmd_handler_register(uint param_1,undefined *param_2)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = &hci_command_handler_tab_esp_hack;
  iVar2 = 0;
  do {
    if (*puVar1 == param_1) {
      (&PTR_hci_unknown_hci_cmd_handler_0001103c)[iVar2 * 2] = param_2;
      return;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 7);
  return;
}

