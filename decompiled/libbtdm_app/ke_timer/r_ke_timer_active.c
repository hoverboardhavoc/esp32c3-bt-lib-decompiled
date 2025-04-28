/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_timer.o -> r_ke_timer_active
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ke_timer_active(uint param_1,uint param_2)

{
  int *piVar1;
  
  piVar1 = (int *)_DAT_00011014;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if ((*(ushort *)(piVar1 + 1) == param_1) && (*(ushort *)((int)piVar1 + 6) == param_2)) break;
    piVar1 = (int *)*piVar1;
  }
  return 1;
}

