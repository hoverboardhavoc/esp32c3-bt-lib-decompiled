/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_filter_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_ble_log_filter_callback(uint param_1)

{
  uint uVar1;
  
  if (((uint)*(byte *)(ble_log_env + 0x14) <= param_1 >> 0x1d) &&
     (uVar1 = param_1 >> 0x10 & 0x1f, (1 << uVar1 & *(uint *)(ble_log_env + 0x18)) != 0)) {
    return (1 << (param_1 >> 0x15 & 0x1f) & *(uint *)(uVar1 * 4 + *(int *)(ble_log_env + 0x1c))) !=
           0;
  }
  return false;
}

