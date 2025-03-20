/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_output_dump_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_output_dump_all(int param_1)

{
  undefined4 uStack_44;
  undefined1 auStack_40 [56];
  
  if (param_1 != 0) {
    memset(auStack_40,0,0x30);
    uStack_44 = _ble_log_env;
    _ble_log_env = 0;
    ble_log_async_flush(&uStack_44);
    _ble_log_env = uStack_44;
    return;
  }
  return;
}

