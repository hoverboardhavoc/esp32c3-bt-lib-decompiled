/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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

