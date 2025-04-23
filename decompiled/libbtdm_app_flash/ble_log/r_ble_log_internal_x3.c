/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log.o -> r_ble_log_internal_x3
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_internal_x3(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (ble_log_env != (byte *)0x0) {
    uStack_34 = (**(code **)(_r_osi_funcs_p + 0xf0))(*(code **)(_r_osi_funcs_p + 0xf0));
    uStack_30 = param_1 & 0xe7ffffff;
    iVar2 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
    pbVar1 = ble_log_env;
    if (iVar2 != 0) {
      *ble_log_env = *ble_log_env | 2;
      uStack_30 = uStack_30 | 0x8000000;
    }
    uStack_2c = param_2;
    uStack_28 = param_3;
    uStack_24 = param_4;
    (**(code **)(pbVar1 + 8))(0x14,&uStack_34,0,0,0,*(code **)(pbVar1 + 8));
    *ble_log_env = 0;
  }
  return;
}

