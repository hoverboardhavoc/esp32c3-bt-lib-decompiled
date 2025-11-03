/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_sleep_clock_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint btdm_sleep_clock_sync(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
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
    uVar2 = r_assert_param("arch_main.c",0x386);
  }
  return uVar2;
}

