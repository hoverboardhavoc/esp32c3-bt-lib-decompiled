/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_con_upd_param_in_range
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_llc_con_upd_param_in_range(uint param_1,uint param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  bVar1 = false;
  if ((((param_2 <= param_1) && (param_3 < 500)) && (param_1 < 0xc81)) &&
     ((5 < param_2 && ((param_4 - 10U & 0xffff) < 0xc77)))) {
    bVar1 = (int)(((int)(param_1 * 5) >> 1) * (param_3 + 1 & 0xffff)) <= param_4 * 10;
  }
  return bVar1;
}

