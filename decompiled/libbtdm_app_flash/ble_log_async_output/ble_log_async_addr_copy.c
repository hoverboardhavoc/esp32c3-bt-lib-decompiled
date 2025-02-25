/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_addr_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint ble_log_async_addr_copy(uint param_1,int param_2,uint param_3,void *param_4,uint param_5)

{
  int iVar1;
  uint __n;
  
  iVar1 = -param_3;
  for (; param_5 != 0; param_5 = param_5 - __n) {
    __n = param_5;
    if (param_1 + iVar1 < param_5) {
      __n = param_1 + iVar1;
    }
    memcpy((void *)(param_2 + param_3),param_4,__n);
    param_3 = param_3 + __n;
    param_4 = (void *)((int)param_4 + __n);
    if (param_1 <= param_3) {
      param_3 = 0;
    }
    iVar1 = -param_3;
  }
  return param_3;
}

