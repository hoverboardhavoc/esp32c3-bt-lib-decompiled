/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_mem_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_ke_mem_init(int param_1,int param_2,short param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_2 + 3U & 0xfffffffc);
  *(undefined2 **)(&r_plf_funcs_p + (param_1 + 4) * 4) = puVar1;
  puVar1[1] = ((short)param_2 + param_3 & 0xfffcU) - (short)puVar1;
  *puVar1 = 0xa55a;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(short *)(&r_plf_funcs_p + (param_1 + 0x10) * 2) = param_3;
  return;
}

