/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> ke_mem.o -> r_ke_mem_is_empty
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
  
  uVar1 = *(ushort *)(r_assert_err + (param_1 + 0x10) * 2);
  iVar3 = *(int *)(r_assert_err + (param_1 + 4) * 4);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar2 = *(ushort *)(iVar3 + 2);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return (uint)uVar2 == ((uint)uVar1 + iVar3 & 0xfffffffc) - iVar3;
}

