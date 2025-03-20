/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_raw_export
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ble_log_raw_export(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uStack_12;
  
  if (ble_log_env != 0) {
    uStack_12 = param_1;
    (**(code **)(ble_log_env + 4))(2,&uStack_12,0,*(code **)(ble_log_env + 4));
    (**(code **)(ble_log_env + 4))(param_3,param_2,1,*(code **)(ble_log_env + 4));
  }
  return;
}

