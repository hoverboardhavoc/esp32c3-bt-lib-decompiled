/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_mem_is_in_heap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_ke_mem_is_in_heap(int param_1,uint param_2)

{
  if (*(uint *)(&r_plf_funcs_p + (param_1 + 4) * 4) <= param_2) {
    return param_2 <=
           *(uint *)(&r_plf_funcs_p + (param_1 + 4) * 4) +
           (uint)*(ushort *)(&r_plf_funcs_p + (param_1 + 0x10) * 2);
  }
  return false;
}

