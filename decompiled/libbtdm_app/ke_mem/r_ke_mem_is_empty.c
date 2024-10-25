/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_mem.o -> r_ke_mem_is_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_ke_mem_is_empty(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(&r_plf_funcs_p + (param_1 + 0x10) * 2);
  iVar3 = *(int *)(&r_plf_funcs_p + (param_1 + 4) * 4);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar2 = *(ushort *)(iVar3 + 2);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return (uint)uVar2 == ((uint)uVar1 + iVar3 & 0xfffffffc) - iVar3;
}

