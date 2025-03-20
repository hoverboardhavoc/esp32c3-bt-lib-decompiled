/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
      if ((uStack_30 & 0xfffc) == 0) {
        (**(code **)(ble_log_env + 8))
                  (8,&uStack_34,param_2,(&_LANCHOR1)[uStack_30 & 0xffff],*(code **)(ble_log_env + 8)
                  );
      }
    }
    else {
      (**(code **)(ble_log_env + 8))(8,&uStack_34,param_2,param_3,0,*(code **)(ble_log_env + 8));
      *ble_log_env = 0;
    }
  }
  return;
}

