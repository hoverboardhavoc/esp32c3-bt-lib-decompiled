/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_adv.o -> ble_ll_adv_aa_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_ll_adv_aa_setting(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != 0) && (param_2 != 0)) {
    DAT_00016468 = (undefined2)param_1;
    DAT_0001646a = (undefined2)param_2;
    uVar1 = 0;
  }
  return uVar1;
}

