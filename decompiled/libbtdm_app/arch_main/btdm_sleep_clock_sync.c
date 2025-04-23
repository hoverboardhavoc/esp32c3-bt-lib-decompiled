/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> btdm_sleep_clock_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint btdm_sleep_clock_sync(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = counter_0;
  uVar1 = _DAT_60042000 >> 7 & 1;
  if (uVar1 != 0) {
    counter_0 = counter_0 + 1;
    if (uVar2 < 1000000) {
      return uVar1;
    }
    _DAT_60031050 = 0x87828180;
    if ((_DAT_60042000 & 4) != 0 || _DAT_60031054 != 0) {
      uVar2 = (**(code **)(_r_plf_funcs_p + 0xc))
                        ("arch_main.c",0x272,*(code **)(_r_plf_funcs_p + 0xc));
      return uVar2;
    }
  }
  counter_0 = 0;
  return 0;
}

