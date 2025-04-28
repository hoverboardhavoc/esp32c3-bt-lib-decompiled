/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  return CONCAT11(*(undefined1 *)(param_1 + uVar1),*(undefined1 *)(param_1 + param_2));
}

