/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> co_list.o -> r_co_list_extract
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_co_list_extract(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (param_1 == (uint *)0x0) {
    r_assert_err("co_list.c",0xd4);
  }
  puVar1 = (uint *)*param_1;
  puVar3 = (uint *)0x0;
  while( true ) {
    puVar2 = puVar1;
    if (puVar2 == (uint *)0x0) {
      return 0;
    }
    if (puVar2 == param_2) break;
    if (*param_1 == *puVar2) {
      r_assert_param((int)puVar2 >> 0x10,(uint)puVar2 & 0xffff,"co_list.c",0xe5);
    }
    if ((uint *)*puVar2 == puVar2) {
      r_assert_param((int)puVar2 >> 0x10,(uint)puVar2 & 0xffff,"co_list.c",0xe6);
    }
    puVar1 = (uint *)*puVar2;
    puVar3 = puVar2;
  }
  if (puVar3 == (uint *)0x0) {
    *param_1 = *param_2;
  }
  else {
    *puVar3 = *param_2;
  }
  if ((uint *)param_1[1] != param_2) {
    return 1;
  }
  param_1[1] = (uint)puVar3;
  return 1;
}

