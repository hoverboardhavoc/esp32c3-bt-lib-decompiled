/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> ke_event.o -> r_ke_event_callback_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_ke_event_callback_set(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1 < 0xf) && (param_2 != 0)) ||
     (r_assert_param(param_1,param_2,"ke_event.c",0x62), param_1 < 0xf)) {
    *(int *)(memset + param_1 * 4) = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}

