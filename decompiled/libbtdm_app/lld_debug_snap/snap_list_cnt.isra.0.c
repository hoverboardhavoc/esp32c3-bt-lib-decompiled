/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_debug_snap.o -> snap_list_cnt.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void snap_list_cnt_isra_0(int *param_1)

{
  short sVar1;
  
  sVar1 = 0;
  do {
    if (param_1 == (int *)0x0) {
      return;
    }
    sVar1 = sVar1 + 1;
    param_1 = (int *)*param_1;
  } while (sVar1 != 0x3e9);
  return;
}

