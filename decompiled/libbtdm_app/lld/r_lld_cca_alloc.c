/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_cca_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_alloc(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _p_lld_env;
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x78))(0x28,*(code **)(_r_osi_funcs_p + 0x78));
  iVar2 = _r_osi_funcs_p;
  *(undefined4 *)(iVar1 + 0x108) = uVar3;
  iVar1 = _p_lld_env;
  uVar3 = (**(code **)(iVar2 + 0x78))(0x28,*(code **)(iVar2 + 0x78));
  iVar2 = _r_osi_funcs_p;
  *(undefined4 *)(iVar1 + 0x10c) = uVar3;
  iVar1 = _p_lld_env;
  uVar3 = (**(code **)(iVar2 + 0x78))(0x28,*(code **)(iVar2 + 0x78));
  iVar2 = _r_osi_funcs_p;
  *(undefined4 *)(iVar1 + 0x110) = uVar3;
  iVar1 = _p_lld_env;
  uVar3 = (**(code **)(iVar2 + 0x78))(5,*(code **)(iVar2 + 0x78));
  iVar2 = _r_osi_funcs_p;
  *(undefined4 *)(iVar1 + 0x118) = uVar3;
  iVar1 = _p_lld_env;
  uVar3 = (**(code **)(iVar2 + 0x78))(0x28,*(code **)(iVar2 + 0x78));
  *(undefined4 *)(iVar1 + 0x114) = uVar3;
  return;
}

