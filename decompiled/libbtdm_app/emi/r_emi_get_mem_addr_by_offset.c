/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> emi.o -> r_emi_get_mem_addr_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_emi_get_mem_addr_by_offset(uint param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 >> 10;
  if (0x32 < uVar4) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar4,"emi.c",0x146,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar3 = uVar4 * 4;
  uVar5 = (uint)(byte)(&em_base_reg_lut)[iVar3];
  if (0x37 < uVar5) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27b9,*(code **)(_r_plf_funcs_p + 8));
  }
  if (uVar5 < 0x30) {
    iVar1 = 0x1800c481;
  }
  else {
    iVar1 = 0x1800c488;
  }
  puVar2 = (uint *)((iVar1 + uVar5) * 4);
  if ((uint)*(ushort *)(&DAT_00012016 + iVar3) != (*puVar2 >> 0x12) << 2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("emi.c",0x14b,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar3 = param_1 - *(ushort *)(&DAT_00012016 + iVar3);
  if (iVar3 < 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(iVar3,uVar4,"emi.c",0x14e,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (0x37 < uVar5) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"emi.c",0x27c8,*(code **)(_r_plf_funcs_p + 8));
  }
  return ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000) + iVar3;
}

