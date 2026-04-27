/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> arch_main.o -> r_assert_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_assert_param(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  r_rwip_assert_hack(param_3,param_4,param_1,param_2,1);
  ebreak();
  uVar2 = _DAT_60042000 >> 7 & 1;
  if (uVar2 == 0) {
    counter_0 = 0;
    return 0;
  }
  iVar3 = counter_0 + 1;
  bVar1 = 999999 < counter_0;
  counter_0 = iVar3;
  if (bVar1) {
    _DAT_60031050 = 0x87828180;
    if ((_DAT_60042000 & 4) == 0 && _DAT_60031054 == 0) {
      counter_0 = 0;
      _DAT_60031050 = 0x87828180;
      return 0;
    }
    uVar2 = r_assert_param("arch_main.c",0x3a1);
  }
  return uVar2;
}

