/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_timestamp_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_log_async_timestamp_get(void *param_1,int param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  uint __n;
  undefined4 auStack_24 [4];
  
  auStack_24[0] = 0;
  uVar1 = param_2 + 2;
  if (param_3 <= uVar1) {
    uVar1 = uVar1 - param_3;
  }
  __n = param_3 - uVar1;
  if (__n < 4) {
    pvVar2 = memcpy(auStack_24,(undefined4 *)((int)param_1 + uVar1),__n);
    memcpy((void *)((int)pvVar2 + __n),param_1,(uVar1 - param_3) + 4);
  }
  else {
    auStack_24[0] = *(undefined4 *)((int)param_1 + uVar1);
  }
  return auStack_24[0];
}

