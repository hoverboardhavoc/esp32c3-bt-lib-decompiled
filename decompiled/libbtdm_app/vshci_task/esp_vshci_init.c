/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> vshci_task.o -> esp_vshci_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_vshci_init(char param_1)

{
  if ((byte)(param_1 - 1U) < 2) {
    (**(code **)(_r_ip_funcs_p + 0x528))(0,0,0,*(code **)(_r_ip_funcs_p + 0x528));
    esp_ble_internal_test_reset();
    return;
  }
  return;
}

