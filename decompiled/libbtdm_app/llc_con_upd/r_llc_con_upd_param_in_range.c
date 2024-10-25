/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    bVar1 = (int)(((int)(param_1 * 5) >> 1) * (param_3 + 1)) <= param_4 * 10;
  }
  return bVar1;
}

