/*
 * Last changed at upstream commit b5ead6b6d5758629370c91897168b8bcdfdcc169
 * https://github.com/espressif/esp32c3-bt-lib/commit/b5ead6b6d5758629370c91897168b8bcdfdcc169
 * Upstream date: 2025-03-12 20:14:26 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(9f6be86f)
 * Source: libbtdm_app -> vshci_task.o -> config_ble_ext_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void config_ble_ext_funcs_reset(void)

{
  _LANCHOR0 = &_LANCHOR1;
  DAT_000111f0 = 0x20;
  return;
}

