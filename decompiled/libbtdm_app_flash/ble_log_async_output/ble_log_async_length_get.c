/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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

