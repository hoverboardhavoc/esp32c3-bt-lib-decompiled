/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
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
                        ("arch_main.c",0x3a8,*(code **)(_r_plf_funcs_p + 0xc));
      return uVar2;
    }
  }
  counter_0 = 0;
  return 0;
}

