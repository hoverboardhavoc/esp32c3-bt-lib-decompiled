/*
 * Last changed at upstream commit 76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * https://github.com/espressif/esp32c3-bt-lib/commit/76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * Upstream date: 2024-04-09 17:28:48 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(c23ab4c)
 * Source: libbtdm_app -> vshci_task.o -> r_register_esp_vendor_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_register_esp_vendor_cmd_handler(void)

{
  _esp_handler = hci_command_handler_tab_esp_hack;
  _DAT_00011054 = 6;
  return;
}

