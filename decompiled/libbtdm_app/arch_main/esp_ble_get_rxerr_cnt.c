/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
 * Source: libbtdm_app -> arch_main.o -> esp_ble_get_rxerr_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_ble_get_rxerr_cnt(undefined1 param_1)

{
  lld_le_pkt_err_get(param_1);
  return;
}

