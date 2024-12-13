/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_sleep_clock_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_sleep_clock_sync(void)

{
  bool bVar1;
  int iVar2;
  
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
    r_assert_param("arch_main.c",0x264);
  }
  return 1;
}

