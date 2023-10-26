/*
 * Last changed at upstream commit ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * https://github.com/espressif/esp32c3-bt-lib/commit/ec7ef197cb8018c468cd59dca893dbe018f47a2a
 * Upstream date: 2023-10-26 19:39:25 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f817304)
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
  _DAT_00011014 = 5;
  return;
}

