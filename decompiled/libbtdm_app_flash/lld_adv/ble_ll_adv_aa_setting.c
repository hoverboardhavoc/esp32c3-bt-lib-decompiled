/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
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
    DAT_00015e64 = (undefined2)param_1;
    DAT_00015e66 = (undefined2)param_2;
    uVar1 = 0;
  }
  return uVar1;
}

