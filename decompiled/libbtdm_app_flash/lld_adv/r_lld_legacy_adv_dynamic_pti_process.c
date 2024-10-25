/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_legacy_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_legacy_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  uVar6 = (uint)*(byte *)(param_1 + 0x87);
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  r_lld_legacy_adv_dynamic_pti_get(&local_30);
  uVar8 = (local_30 & 0xff) << 8;
  if ((uVar8 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x33f);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar4 = (uVar6 * 9 & 0xff) * 0xe;
  iVar7 = iVar4 + 10;
  uVar1 = *(ushort *)(iVar5 + iVar7);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar5 + iVar7) = uVar1 & 0xf0ff | (ushort)uVar8;
  uVar8 = (local_30 >> 8 & 0xff) << 0xc;
  if ((uVar8 & 0xffffefff) != 0) {
    r_assert_err(0,"lld_adv.c",0x333);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar1 = *(ushort *)(iVar5 + iVar7);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar5 + iVar7) = uVar1 & 0xefff | (ushort)uVar8;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar5 + iVar4) & 0x7fff) != 0) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar5 + iVar4);
    uVar8 = (local_30 & 0xff) << 8;
    if ((uVar8 & 0xfffff0ff) != 0) {
      r_assert_err(0,"lld_adv.c",0x33f);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar4 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
    uVar1 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar4) = uVar1 & 0xf0ff | (ushort)uVar8;
    uVar8 = (local_30 >> 8 & 0xff) << 0xc;
    if ((uVar8 & 0xffffefff) != 0) {
      r_assert_err(0,"lld_adv.c",0x333);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar5 + iVar4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar4) = uVar1 & 0xefff | (ushort)uVar8;
  }
  uVar2 = local_30;
  uVar8 = local_30 >> 0x10;
  if (0xb < uVar6) {
    r_assert_err(0,"lld_adv.c",0x29bb);
  }
  if ((uVar2 & 0xf00000) != 0) {
    r_assert_err(0,"lld_adv.c",0x29bd);
  }
  puVar3 = (uint *)((uVar6 + 0x1800c4cb) * 4);
  *puVar3 = *puVar3 & 0xfffffff0 | uVar8 & 0xff;
  uVar8 = local_30 >> 0x18;
  if (0xb < uVar6) {
    r_assert_err(0,"lld_adv.c",0x295a);
  }
  uVar8 = uVar8 << 0x1d;
  if ((uVar8 & 0xc0000000) != 0) {
    r_assert_err(0,"lld_adv.c",0x295c);
  }
  *puVar3 = *puVar3 & 0xdfffffff | uVar8;
  uVar8 = uStack_2c & 0xff;
  if (0xb < uVar6) {
    r_assert_err(0,"lld_adv.c",0x299b);
  }
  uVar8 = uVar8 << 8;
  if ((uVar8 & 0xf000) != 0) {
    r_assert_err(0,"lld_adv.c",0x299d);
  }
  *puVar3 = *puVar3 & 0xfffff0ff | uVar8;
  uVar8 = uStack_2c >> 8;
  if (0xb < uVar6) {
    r_assert_err(0,"lld_adv.c",0x294a);
  }
  uVar8 = uVar8 << 0x1e;
  if ((int)uVar8 < 0) {
    r_assert_err(0,"lld_adv.c",0x294c);
  }
  *puVar3 = *puVar3 & 0xbfffffff | uVar8;
  return;
}

