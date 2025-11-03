/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_ctrl_level_and_mod
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_ble_log_ctrl_level_and_mod(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ble_log_env;
  if (ble_log_env == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0xfffffffe;
    if (param_1 < 6) {
      *(char *)(ble_log_env + 0x14) = (char)param_1;
      *(undefined4 *)(iVar1 + 0x18) = param_2;
      return 0;
    }
  }
  return uVar2;
}

