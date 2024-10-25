/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> bt_rw_v9.o -> r_rw_v9_init_em_radio_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rw_v9_init_em_radio_table(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *puVar1 = 0x6040200;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 4) = 0xe0c0a08;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 8) = 0x16141210;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0xc) = 0x1e1c1a18;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x10) = 0x26242220;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x14) = 0x2e2c2a28;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x18) = 0x36343230;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x1c) = 0x3e3c3a38;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x20) = 0x46444240;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x24) = 0x4e4c4a48;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x28) = 0x7050301;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x2c) = 0xf0d0b09;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x30) = 0x17151311;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x34) = 0x1f1d1b19;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x38) = 0x27252321;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x3c) = 0x2f2d2b29;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x40) = 0x37353331;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x44) = 0x3f3d3b39;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x48) = 0x47454341;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined4 *)(iVar2 + 0x4c) = 0x4d4b49;
  _DAT_60031078 = _DAT_60031078 & 0xffff0000;
  return;
}

