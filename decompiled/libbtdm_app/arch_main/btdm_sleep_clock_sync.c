/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> arch_main.o -> btdm_sleep_clock_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_sleep_clock_sync(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = _LANCHOR5;
  if ((_DAT_60042000 >> 7 & 1) != 0) {
    _LANCHOR5 = _LANCHOR5 + 1;
    if (uVar1 < 1000000) {
      return 1;
    }
    _DAT_60031050 = 0x87828180;
    if ((_DAT_60042000 & 4) != 0 || _DAT_60031054 != 0) {
      uVar2 = (**(code **)(_r_plf_funcs_p + 0xc))
                        ("arch_main.c",0x271,*(code **)(_r_plf_funcs_p + 0xc));
      return uVar2;
    }
  }
  _LANCHOR5 = 0;
  return 0;
}

