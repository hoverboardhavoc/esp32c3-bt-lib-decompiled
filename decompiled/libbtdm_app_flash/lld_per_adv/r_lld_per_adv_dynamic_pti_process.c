/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_dynamic_pti_process(int param_1)

{
  ushort uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
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
  if ((param_1 != 0) && (iVar4 = r_bt_rf_coex_per_adv_dynamic_pti_en_get(), iVar4 != 0)) {
    r_lld_per_adv_dynamic_pti_get(param_1,&uStack_44);
    uVar8 = uStack_40;
    uVar5 = (uint)*(byte *)(param_1 + 0x52);
    uVar6 = uStack_40 >> 0x18;
    uVar3 = uVar5 * 9 & 0xff;
    if (0xb < uVar5) {
      r_assert_err(0,0x10000,0x29bb);
    }
    if ((uVar8 & 0xf0000000) != 0) {
      r_assert_err(0,0x10000,0x29bd);
    }
    iVar4 = iStack_3c;
    puVar2 = (uint *)((uVar5 + 0x1800c4cb) * 4);
    *puVar2 = *puVar2 & 0xfffffff0 | uVar6;
    if (0xb < uVar5) {
      r_assert_err(0,0x10000,0x295a);
    }
    if ((iVar4 << 0x1d & 0xc0000000U) != 0) {
      r_assert_err(0,0x10000,0x295c);
    }
    *puVar2 = *puVar2 & 0xdfffffff | iVar4 << 0x1d;
    uVar6 = uStack_44 & 0xff;
    if (0xb < uVar5) {
      r_assert_err(0,0x10000,0x299b);
    }
    uVar6 = uVar6 << 8;
    if ((uVar6 & 0xf000) != 0) {
      r_assert_err(0,0x10000,0x299d);
    }
    *puVar2 = *puVar2 & 0xfffff0ff | uVar6;
    uVar6 = uStack_44 >> 8;
    if (0xb < uVar5) {
      r_assert_err(0,0x10000,0x294a);
    }
    uVar6 = uVar6 << 0x1e;
    if ((int)uVar6 < 0) {
      r_assert_err(0,0x10000,0x294c);
    }
    *puVar2 = *puVar2 & 0xbfffffff | uVar6;
    uVar6 = (uStack_44 >> 0x18) << 8;
    if ((uVar6 & 0xf000) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar7 = uVar3 * 0xe + 10;
    uVar1 = *(ushort *)(iVar4 + iVar7);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar8 = (uStack_40 & 0xff) << 0xc;
    *(ushort *)(iVar4 + iVar7) = uVar1 & 0xf0ff | (ushort)uVar6;
    if ((uVar8 & 0xffffefff) != 0) {
      r_assert_err(0,0x10000,0x333);
    }
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar4 + iVar7);
    iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar7) = uVar1 & 0xefff | (ushort)uVar8;
    do {
      uVar3 = uVar3 + 1 & 0xff;
      uVar6 = (uStack_40 >> 8 & 0xff) << 8;
      if ((uVar6 & 0xfffff0ff) != 0) {
        r_assert_err(0,0x10000,0x33f);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = uVar3 * 0xe + 10;
      uVar1 = *(ushort *)(iVar4 + iVar7);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar8 = (uStack_40 >> 0x10 & 0xff) << 0xc;
      *(ushort *)(iVar4 + iVar7) = uVar1 & 0xf0ff | (ushort)uVar6;
      if ((uVar8 & 0xffffefff) != 0) {
        r_assert_err(0,0x10000,0x333);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar4 + iVar7);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar7) = uVar1 & 0xefff | (ushort)uVar8;
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
    } while ((*(ushort *)(iVar4 + uVar3 * 0xe) & 0x7fff) != 0);
  }
  return;
}

