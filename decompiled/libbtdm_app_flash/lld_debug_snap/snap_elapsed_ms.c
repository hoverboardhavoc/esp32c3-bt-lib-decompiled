/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_debug_snap.o -> snap_elapsed_ms
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int snap_elapsed_ms(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 - param_2 & 0xfffffff;
  if (0x8000000 < uVar1) {
    uVar1 = -(param_2 - param_1 & 0xfffffffU);
  }
  return (int)(uVar1 * 5) / 0x10;
}

