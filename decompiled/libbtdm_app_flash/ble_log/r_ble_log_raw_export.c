/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_raw_export
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ble_log_raw_export(undefined2 param_1,undefined4 param_2)

{
  undefined2 auStack_12 [7];
  
  if (ble_log_env != 0) {
    auStack_12[0] = param_1;
    (**(code **)(ble_log_env + 4))(2,auStack_12,param_2,0x22,*(code **)(ble_log_env + 4));
  }
  return;
}

