/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

