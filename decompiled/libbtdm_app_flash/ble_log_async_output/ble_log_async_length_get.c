/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_length_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 ble_log_async_length_get(int param_1,int param_2,uint param_3)

{
  return CONCAT11(*(undefined1 *)(param_1 + (param_2 + 1U & -(uint)(param_2 + 1U < param_3))),
                  *(undefined1 *)(param_1 + param_2));
}

