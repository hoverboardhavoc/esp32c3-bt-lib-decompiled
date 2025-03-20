/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_internal_x1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_internal_x1(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  
  if (ble_log_env != (byte *)0x0) {
    uStack_34 = (**(code **)(_r_osi_funcs_p + 0xf0))(*(code **)(_r_osi_funcs_p + 0xf0));
    uStack_30 = param_1 & 0xe7ffffff;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
    if (iVar1 != 0) {
      *ble_log_env = *ble_log_env | 2;
      uStack_30 = uStack_30 | 0x8000000;
    }
    uStack_2c = param_2;
    (**(code **)(ble_log_env + 8))(0xc,&uStack_34,0,0,0,*(code **)(ble_log_env + 8));
    *ble_log_env = 0;
  }
  return;
}

