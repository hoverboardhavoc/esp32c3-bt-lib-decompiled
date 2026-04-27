/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_con_upd_param_in_range_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_llc_con_upd_param_in_range_hack(uint param_1,uint param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  bVar1 = false;
  if ((((param_2 <= param_1) && (param_3 < 500)) && (param_1 < 0xc81)) &&
     ((bVar1 = false, _g_ble_con_interval_min <= param_2 && ((param_4 - 10U & 0xffff) < 0xc77)))) {
    bVar1 = (int)(((int)(param_1 * 5) >> 1) * (param_3 + 1 & 0xffff)) <= param_4 * 10;
  }
  return bVar1;
}

