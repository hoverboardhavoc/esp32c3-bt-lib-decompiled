/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> lld_read_clock_us
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint lld_read_clock_us(void)

{
  uint uVar1;
  int extraout_a1;
  uint uVar2;
  
  uVar1 = rwip_time_get_us();
  uVar2 = extraout_a1 + uVar1 * 0x271;
  return ((uint)(uVar2 < uVar1 * 0x271) + (int)((ulonglong)uVar1 * 0x271 >> 0x20)) * -0x80000000 |
         uVar2 >> 1;
}

