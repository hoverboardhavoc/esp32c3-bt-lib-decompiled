/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> ble_log_async_task_func
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_log_async_task_func(void)

{
  int iStack_44;
  undefined1 auStack_40 [60];
  
  memset(auStack_40,0,0x30);
  iStack_44 = _ble_log_env;
  while (iStack_44 != 0) {
    ble_log_async_flush(&iStack_44);
  }
  return;
}

