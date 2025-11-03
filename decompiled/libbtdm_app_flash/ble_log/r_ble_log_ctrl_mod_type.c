/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_ctrl_mod_type
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_ble_log_ctrl_mod_type(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (ble_log_env == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0xffffffff;
    if (((*(int *)(ble_log_env + 0x1c) != 0) && (uVar1 = 0xfffffffe, param_1 < 0x10)) &&
       (uVar1 = 0xfffffffd, (1 << (param_1 & 0x1f) & *(uint *)(ble_log_env + 0x18)) != 0)) {
      *(undefined4 *)(*(int *)(ble_log_env + 0x1c) + param_1 * 4) = param_2;
      return 0;
    }
  }
  return uVar1;
}

