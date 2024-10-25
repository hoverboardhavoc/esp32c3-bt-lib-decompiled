/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> emi.o -> r_emi_get_mem_addr_by_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_emi_get_mem_addr_by_offset(uint param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 >> 10;
  if (0x32 < uVar5) {
    r_assert_param(uVar5,"emi.c",0x146);
  }
  iVar3 = uVar5 * 4;
  uVar4 = (uint)(byte)(&em_base_reg_lut)[iVar3];
  if (0x37 < uVar4) {
    r_assert_err(0,"emi.c",0x27b9);
  }
  if (uVar4 < 0x30) {
    iVar1 = 0x1800c481;
  }
  else {
    iVar1 = 0x1800c488;
  }
  puVar2 = (uint *)((iVar1 + uVar4) * 4);
  if ((uint)*(ushort *)(&DAT_0001201a + iVar3) != (*puVar2 >> 0x12) << 2) {
    r_assert_param("emi.c",0x14b);
  }
  iVar3 = param_1 - *(ushort *)(&DAT_0001201a + iVar3);
  if (iVar3 < 0) {
    r_assert_param(iVar3,uVar5,"emi.c",0x14e);
  }
  if (0x37 < uVar4) {
    r_assert_err(0,"emi.c",0x27c8);
  }
  return ((*puVar2 & 0x3ffff) << 2 | 0x3fc00000) + iVar3;
}

