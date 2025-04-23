/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  bool bVar2;
  uint uVar3;
  undefined4 uStack_34;
  uint uStack_30;
  
  if (ble_log_env != (byte *)0x0) {
    uStack_34 = (**(code **)(_r_osi_funcs_p + 0xf0))(*(code **)(_r_osi_funcs_p + 0xf0));
    uStack_30 = param_1 & 0xe7ffffff;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
    if (iVar1 != 0) {
      *ble_log_env = *ble_log_env | 2;
      uStack_30 = uStack_30 | 0x8000000;
    }
    if ((uStack_30 & 0x1f0000) == 0xa0000) {
      uVar3 = uStack_30 & 0xffff;
      if (uVar3 == 2) {
        bVar2 = false;
      }
      else if (uVar3 < 3) {
        bVar2 = uVar3 != 0;
      }
      else {
        if (uVar3 != 3) {
          return;
        }
        bVar2 = true;
      }
      (**(code **)(ble_log_env + 8))(8,&uStack_34,param_2,bVar2,*(code **)(ble_log_env + 8));
    }
    else {
      (**(code **)(ble_log_env + 8))(8,&uStack_34,param_2,param_3,0,*(code **)(ble_log_env + 8));
      *ble_log_env = 0;
    }
  }
  return;
}

