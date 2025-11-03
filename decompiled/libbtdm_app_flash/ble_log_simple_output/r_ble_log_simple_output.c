/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log_simple_output.o -> r_ble_log_simple_output
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_simple_output(size_t param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_2c;
  undefined1 auStack_28 [24];
  
  uStack_2c = 0;
  memset(auStack_28,0,0x16);
  uStack_2c = CONCAT22(uStack_2c._2_2_,(short)param_3 + 2 + (short)param_1);
  memcpy((void *)((int)&uStack_2c + 2),param_2,param_1);
  uVar1 = 10;
  if (((*_ble_log_env & 2) == 0) && (uVar1 = 0x12, (*_ble_log_env & 1) == 0)) {
    uVar1 = 6;
  }
  (**(code **)(_ble_log_env + 4))
            (param_1 + 2,&uStack_2c,param_3,param_4,uVar1,*(code **)(_ble_log_env + 4));
  return;
}

