/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uStack_44;
  uint uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = 0;
  iStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  if ((param_1 != 0) && (iVar5 = r_bt_rf_coex_per_adv_dynamic_pti_en_get(), iVar5 != 0)) {
    r_lld_per_adv_dynamic_pti_get(param_1,&uStack_44);
    uVar2 = uStack_40;
    uVar7 = (uint)*(byte *)(param_1 + 0x52);
    uVar8 = uStack_40 >> 0x18;
    uVar4 = uVar7 * 9 & 0xff;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_per_adv.c",0x29bb);
    }
    if ((uVar2 & 0xf0000000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x29bd);
    }
    iVar5 = iStack_3c;
    puVar3 = (uint *)((uVar7 + 0x1800c4cb) * 4);
    *puVar3 = *puVar3 & 0xfffffff0 | uVar8;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_per_adv.c",0x295a);
    }
    if ((iVar5 << 0x1d & 0xc0000000U) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x295c);
    }
    *puVar3 = *puVar3 & 0xdfffffff | iVar5 << 0x1d;
    uVar8 = uStack_44 & 0xff;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_per_adv.c",0x299b);
    }
    uVar8 = uVar8 << 8;
    if ((uVar8 & 0xf000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x299d);
    }
    *puVar3 = *puVar3 & 0xfffff0ff | uVar8;
    uVar8 = uStack_44 >> 8;
    if (0xb < uVar7) {
      r_assert_err(0,"lld_per_adv.c",0x294a);
    }
    uVar8 = uVar8 << 0x1e;
    if ((int)uVar8 < 0) {
      r_assert_err(0,"lld_per_adv.c",0x294c);
    }
    *puVar3 = *puVar3 & 0xbfffffff | uVar8;
    uVar8 = (uStack_44 >> 0x18) << 8;
    if ((uVar8 & 0xf000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x33f);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar5 = uVar4 * 0xe + 10;
    uVar1 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar5) = uVar1 & 0xf0ff | (ushort)uVar8;
    uVar8 = (uStack_40 & 0xff) << 0xc;
    if ((uVar8 & 0xffffefff) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x333);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar5) = uVar1 & 0xefff | (ushort)uVar8;
    do {
      uVar4 = uVar4 + 1 & 0xff;
      uVar8 = (uStack_40 >> 8 & 0xff) << 8;
      if ((uVar8 & 0xfffff0ff) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x33f);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar6 = uVar4 * 0xe + 10;
      uVar1 = *(ushort *)(iVar5 + iVar6);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + iVar6) = uVar1 & 0xf0ff | (ushort)uVar8;
      uVar8 = (uStack_40 >> 0x10 & 0xff) << 0xc;
      if ((uVar8 & 0xffffefff) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x333);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar5 + iVar6);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + iVar6) = uVar1 & 0xefff | (ushort)uVar8;
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    } while ((*(ushort *)(iVar5 + uVar4 * 0xe) & 0x7fff) != 0);
  }
  return;
}

