/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_timestamp_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_log_async_timestamp_get(void *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint __n;
  undefined4 auStack_24 [4];
  
  auStack_24[0] = 0;
  uVar1 = param_2 + 2;
  if (param_3 <= uVar1) {
    uVar1 = uVar1 - param_3;
  }
  __n = param_3 - uVar1;
  if (__n < 4) {
    memcpy(auStack_24,(undefined4 *)((int)param_1 + uVar1),__n);
    memcpy((void *)((int)auStack_24 + __n),param_1,(uVar1 - param_3) + 4);
  }
  else {
    auStack_24[0] = *(undefined4 *)((int)param_1 + uVar1);
  }
  return auStack_24[0];
}

