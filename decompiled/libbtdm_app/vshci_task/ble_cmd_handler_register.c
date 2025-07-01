/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> vshci_task.o -> ble_cmd_handler_register
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
      (&PTR_hci_unknown_hci_cmd_handler_00011424)[iVar2 * 2] = param_2;
      return;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 7);
  return;
}

