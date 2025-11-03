/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_internal_hex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_internal_hex(uint param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_38;
  uint uStack_34;
  
  if ((ble_log_env != (byte *)0x0) &&
     (iVar1 = (**(code **)(ble_log_env + 0x10))(*(code **)(ble_log_env + 0x10)), iVar1 != 0)) {
    uStack_38 = lld_read_clock_us();
    uStack_34 = param_1 & 0xe7ffffff;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
    if (iVar1 != 0) {
      *ble_log_env = *ble_log_env | 2;
      uStack_34 = uStack_34 | 0x8000000;
    }
    (**(code **)(ble_log_env + 8))(8,&uStack_38,param_2,param_3,0,*(code **)(ble_log_env + 8));
    *ble_log_env = 0;
  }
  return;
}

