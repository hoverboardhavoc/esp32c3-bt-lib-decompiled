/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> nvds.o -> r_nvds_walk_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_nvds_walk_tag(int param_1,char *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  (*_LANCHOR0)(3,param_2,_LANCHOR0);
  uVar1 = 2;
  if (*param_2 != -1) {
    uVar1 = 0;
    uVar2 = (uint)(byte)param_2[2] + param_1 + 3;
    *param_3 = uVar2;
    if (DAT_00010688 - 1U < uVar2) {
      r_assert_err(0,"nvds.c",0x199);
      uVar1 = 6;
    }
  }
  return uVar1;
}

