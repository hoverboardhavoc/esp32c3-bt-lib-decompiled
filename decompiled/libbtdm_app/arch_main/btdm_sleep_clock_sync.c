/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
                        ("arch_main.c",0x272,*(code **)(_r_plf_funcs_p + 0xc));
      return uVar2;
    }
  }
  _LANCHOR5 = 0;
  return 0;
}

