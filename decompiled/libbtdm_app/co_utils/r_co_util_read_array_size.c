/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> co_utils.o -> r_co_util_read_array_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short r_co_util_read_array_size(undefined4 *param_1)

{
  short sVar1;
  byte *pbVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("co_utils.c",0x46,*(code **)(_r_plf_funcs_p + 8));
  }
  pbVar2 = (byte *)*param_1;
  *param_1 = pbVar2 + 1;
  sVar1 = *pbVar2 - 0x30;
  while( true ) {
    pbVar2 = (byte *)*param_1;
    if (9 < (byte)(*pbVar2 - 0x30)) break;
    *param_1 = pbVar2 + 1;
    sVar1 = sVar1 * 10 + (*pbVar2 - 0x30);
  }
  return sVar1;
}

