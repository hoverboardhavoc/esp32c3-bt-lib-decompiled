/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  if ((param_1 != 0) && (iVar13 = r_bt_rf_coex_per_adv_dynamic_pti_en_get(), iVar13 != 0)) {
    r_lld_per_adv_dynamic_pti_get(param_1,&uStack_44);
    uVar10 = uStack_3c;
    uVar9 = uStack_40;
    uVar6 = uStack_44;
    uVar14 = (uint)*(byte *)(param_1 + 0x52);
    uVar16 = uStack_44 & 0xff;
    uVar3 = uStack_44 >> 8;
    bVar7 = uStack_44._3_1_;
    bVar8 = (byte)uStack_40;
    uVar4 = uStack_40 >> 8;
    uVar5 = uStack_40 >> 0x10;
    uVar2 = uStack_40 >> 0x18;
    uVar12 = uVar14 * 9 & 0xff;
    if (0xb < uVar14) {
      r_assert_err(0,0x10000,0x29bb);
    }
    if (0xf < uVar2) {
      r_assert_err(0,0x10000,0x29bd);
    }
    puVar11 = (uint *)((uVar14 + 0x1800c4cb) * 4);
    *puVar11 = *puVar11 & 0xfffffff0 | uVar2;
    if (0xb < uVar14) {
      r_assert_err(0,0x10000,0x295a);
    }
    if ((uVar10 & 6) != 0) {
      r_assert_err(0,0x10000,0x295c);
    }
    *puVar11 = *puVar11 & 0xdfffffff | uVar10 << 0x1d;
    if (0xb < uVar14) {
      r_assert_err(0,0x10000,0x299b);
    }
    if ((uVar6 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x299d);
    }
    *puVar11 = *puVar11 & 0xfffff0ff | uVar16 << 8;
    if (0xb < uVar14) {
      r_assert_err(0,0x10000,0x294a);
    }
    if ((uVar6 & 0x200) != 0) {
      r_assert_err(0,0x10000,0x294c);
    }
    *puVar11 = *puVar11 & 0xbfffffff | uVar3 << 0x1e;
    if ((uVar6 & 0xf0000000) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar15 = uVar12 * 0xe + 10;
    uVar1 = *(ushort *)(iVar13 + iVar15);
    iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar13 + iVar15) = uVar1 & 0xf0ff | (ushort)bVar7 << 8;
    if ((uVar9 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x333);
    }
    iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar13 + iVar15);
    iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar13 + iVar15) = uVar1 & 0xefff | (ushort)bVar8 << 0xc;
    do {
      uVar12 = uVar12 + 1 & 0xff;
      if ((uVar9 & 0xf000) != 0) {
        r_assert_err(0,0x10000,0x33f);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar15 = uVar12 * 0xe + 10;
      uVar1 = *(ushort *)(iVar13 + iVar15);
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar13 + iVar15) = uVar1 & 0xf0ff | (ushort)((uVar4 & 0xff) << 8);
      if ((uVar9 & 0xfe0000) != 0) {
        r_assert_err(0,0x10000,0x333);
      }
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar13 + iVar15);
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar13 + iVar15) = uVar1 & 0xefff | (ushort)((uVar5 & 0xff) << 0xc);
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    } while ((*(ushort *)(iVar13 + uVar12 * 0xe) & 0x7fff) != 0);
  }
  return;
}

