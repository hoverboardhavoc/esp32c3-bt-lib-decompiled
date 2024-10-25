/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> r_assert_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_assert_param(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  
  r_rwip_assert(param_3,param_4,param_1,param_2,1);
  ebreak();
  if ((_DAT_60042000 >> 7 & 1) == 0) {
    _LANCHOR6 = 0;
    return 0;
  }
  iVar2 = _LANCHOR6 + 1;
  bVar1 = 999999 < _LANCHOR6;
  _LANCHOR6 = iVar2;
  if (bVar1) {
    _DAT_60031050 = 0x87828180;
    if ((_DAT_60042000 & 4) == 0 && _DAT_60031054 == 0) {
      _LANCHOR6 = 0;
      _DAT_60031050 = 0x87828180;
      return 0;
    }
    r_assert_param("arch_main.c",0x263);
  }
  return 1;
}

