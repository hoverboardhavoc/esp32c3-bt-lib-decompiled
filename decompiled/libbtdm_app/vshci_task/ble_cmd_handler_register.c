/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
      (&PTR_hci_unknown_hci_cmd_handler_000112f8)[iVar2 * 2] = param_2;
      return;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 7);
  return;
}

