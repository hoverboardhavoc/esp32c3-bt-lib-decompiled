/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_ext_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bStack_38;
  byte bStack_37;
  byte bStack_35;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  
  memset(&bStack_38,0,0x18);
  uVar8 = (uint)*(byte *)(param_1 + 0x87);
  bVar1 = *(byte *)(param_1 + 0x74);
  r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&bStack_38);
  uVar3 = uVar8 * 9 & 0xff;
  uVar7 = uVar3 + 1 & 0xff;
  if (0xb < uVar8) {
    r_assert_err(0,"lld_adv.c",0x29bb);
  }
  if ((bStack_33 & 0xf0) != 0) {
    r_assert_err(0,"lld_adv.c",0x29bd);
  }
  puVar5 = (uint *)((uVar8 + 0x1800c4cb) * 4);
  *puVar5 = *puVar5 & 0xfffffff0 | (uint)bStack_33;
  if (0xb < uVar8) {
    r_assert_err(0,"lld_adv.c",0x295a);
  }
  if (((uint)bStack_32 << 0x1d & 0xc0000000) != 0) {
    r_assert_err(0,"lld_adv.c",0x295c);
  }
  *puVar5 = *puVar5 & 0xdfffffff | (uint)bStack_32 << 0x1d;
  if (0xb < uVar8) {
    r_assert_err(0,"lld_adv.c",0x299b);
  }
  if (((uint)bStack_38 << 8 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x299d);
  }
  *puVar5 = *puVar5 & 0xfffff0ff | (uint)bStack_38 << 8;
  if (0xb < uVar8) {
    r_assert_err(0,"lld_adv.c",0x294a);
  }
  if ((int)((uint)bStack_37 << 0x1e) < 0) {
    r_assert_err(0,"lld_adv.c",0x294c);
  }
  *puVar5 = *puVar5 & 0xbfffffff | (uint)bStack_37 << 0x1e;
  uVar8 = (uint)bStack_35;
  if ((uVar8 << 8 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x33f);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar4 = uVar3 * 0xe + 10;
  uVar2 = *(ushort *)(iVar6 + iVar4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar4) = uVar2 & 0xf0ff | (ushort)(uVar8 << 8);
  uVar3 = (uint)bStack_34;
  if ((uVar3 << 0xc & 0xffffefff) != 0) {
    r_assert_err(0,"lld_adv.c",0x333);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar6 + iVar4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar4) = uVar2 & 0xefff | (ushort)(uVar3 << 0xc);
  if (((uint)bStack_35 << 8 & 0xfffff0ff) != 0) {
    r_assert_err(0,"lld_adv.c",0x33f);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar4 = uVar7 * 0xe + 10;
  uVar2 = *(ushort *)(iVar6 + iVar4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar4) = uVar2 & 0xf0ff | (ushort)((uint)bStack_35 << 8);
  if (((uint)bStack_34 << 0xc & 0xffffefff) != 0) {
    r_assert_err(0,"lld_adv.c",0x333);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar2 = *(ushort *)(iVar6 + iVar4);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar4) = uVar2 & 0xefff | (ushort)((uint)bStack_34 << 0xc);
  r_lld_ext_adv_dynamic_aux_pti_process_eco(bVar1 & 3,uVar7,&bStack_38);
  return;
}

