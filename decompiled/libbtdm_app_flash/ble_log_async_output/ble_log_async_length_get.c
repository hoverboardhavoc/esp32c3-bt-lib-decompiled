/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_length_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 ble_log_async_length_get(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + 1;
  if (param_3 <= uVar1) {
    uVar1 = 0;
  }
  return CONCAT11(*(undefined1 *)(uVar1 + param_1),*(undefined1 *)(param_1 + param_2));
}

