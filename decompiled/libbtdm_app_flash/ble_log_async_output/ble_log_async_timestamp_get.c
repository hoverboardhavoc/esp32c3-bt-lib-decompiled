/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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

