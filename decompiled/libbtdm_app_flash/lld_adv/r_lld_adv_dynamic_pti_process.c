/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  byte bStack_42;
  
  if (param_1 == 0) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x74) & 0x10) == 0) {
    iVar10 = r_bt_rf_coex_ext_adv_dynamic_pti_en_get();
    if (iVar10 != 0) {
      iVar10 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar10 + 0x18) != '\0') {
        memset(&uStack_48,0,0x18);
        uVar13 = (uint)*(byte *)(param_1 + 0x87);
        uVar1 = *(ushort *)(param_1 + 0x74);
        r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&uStack_48);
        uVar8 = uVar13 * 9 & 0xff;
        uVar14 = uVar8 + 1 & 0xff;
        if (0xb < uVar13) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if (0xf < uStack_44._1_1_) {
          r_assert_err(0,0x10000,0x29bd);
        }
        puVar7 = (uint *)((uVar13 + 0x1800c4cb) * 4);
        *puVar7 = *puVar7 & 0xfffffff0 | (uint)uStack_44._1_1_;
        if (0xb < uVar13) {
          r_assert_err(0,0x10000,0x295a);
        }
        if ((bStack_42 & 6) != 0) {
          r_assert_err(0,0x10000,0x295c);
        }
        *puVar7 = *puVar7 & 0xdfffffff | (uint)bStack_42 << 0x1d;
        if (0xb < uVar13) {
          r_assert_err(0,0x10000,0x299b);
        }
        if ((uStack_48 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        *puVar7 = *puVar7 & 0xfffff0ff | (uStack_48 & 0xff) << 8;
        if (0xb < uVar13) {
          r_assert_err(0,0x10000,0x294a);
        }
        if ((uStack_48 & 0x200) != 0) {
          r_assert_err(0,0x10000,0x294c);
        }
        *puVar7 = *puVar7 & 0xbfffffff | (uStack_48 >> 8) << 0x1e;
        if ((uStack_48 & 0xf0000000) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar10 = uVar8 * 0xe + 10;
        uVar2 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar10) = (ushort)uStack_48._3_1_ << 8 | uVar2 & 0xf0ff;
        if ((uStack_44 & 0xfe) != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = (ushort)(((uint)(byte)uStack_44 << 0x1c) >> 0x10);
        *(ushort *)(iVar10 + iVar9) = uVar3 | uVar2 & 0xefff;
        if ((uStack_48 & 0xf0000000) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar10 = uVar14 * 0xe + 10;
        uVar2 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar10) = (ushort)uStack_48._3_1_ << 8 | uVar2 & 0xf0ff;
        if ((uStack_44 & 0xfe) != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar10) = uVar3 | uVar2 & 0xefff;
        r_lld_ext_adv_dynamic_aux_pti_process_eco(uVar1 & 3,uVar14,&uStack_48);
        return;
      }
      r_assert_err(0,0x10000,0x45b);
      return;
    }
  }
  else {
    iVar10 = r_bt_rf_coex_legacy_adv_dynamic_pti_en_get();
    if (iVar10 != 0) {
      uVar12 = (uint)*(byte *)(param_1 + 0x87);
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      r_lld_legacy_adv_dynamic_pti_get(&uStack_50);
      uVar6 = uStack_4c;
      uVar5 = uStack_50;
      uVar11 = uStack_50 & 0xff;
      uVar13 = uStack_50 >> 8;
      uVar16 = uStack_50 >> 0x10 & 0xff;
      uVar8 = uStack_50 & 0xf0;
      uVar14 = uStack_50 >> 0x18;
      uVar15 = uStack_4c & 0xff;
      uVar4 = uStack_4c >> 8;
      if ((uStack_50 & 0xf0) != 0) {
        r_assert_err(0,0x10000,0x33f);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar10 = (uVar12 * 9 & 0xff) * 0xe;
      iVar17 = iVar10 + 10;
      uVar1 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = (ushort)(uVar11 << 8);
      *(ushort *)(iVar9 + iVar17) = uVar2 | uVar1 & 0xf0ff;
      if ((uVar5 & 0xfe00) != 0) {
        r_assert_err(0,0x10000,0x333);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = (ushort)((uVar13 << 0x1c) >> 0x10);
      *(ushort *)(iVar17 + iVar9) = uVar3 | uVar1 & 0xefff;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((*(ushort *)(iVar9 + iVar10) & 0x7fff) != 0) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar1 = *(ushort *)(iVar10 + iVar9);
        if (uVar8 != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar10 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
        uVar1 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar10) = uVar2 | uVar1 & 0xf0ff;
        if ((uVar5 & 0xfe00) != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar1 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar10) = uVar3 | uVar1 & 0xefff;
      }
      if (0xb < uVar12) {
        r_assert_err(0,0x10000,0x29bb);
      }
      if (0xf < uVar16) {
        r_assert_err(0,0x10000,0x29bd);
      }
      puVar7 = (uint *)((uVar12 + 0x1800c4cb) * 4);
      *puVar7 = *puVar7 & 0xfffffff0 | uVar16;
      if (0xb < uVar12) {
        r_assert_err(0,0x10000,0x295a);
      }
      if ((uVar5 & 0x6000000) != 0) {
        r_assert_err(0,0x10000,0x295c);
      }
      *puVar7 = *puVar7 & 0xdfffffff | uVar14 << 0x1d;
      if (0xb < uVar12) {
        r_assert_err(0,0x10000,0x299b);
      }
      if ((uVar6 & 0xf0) != 0) {
        r_assert_err(0,0x10000,0x299d);
      }
      *puVar7 = *puVar7 & 0xfffff0ff | uVar15 << 8;
      if (0xb < uVar12) {
        r_assert_err(0,0x10000,0x294a);
      }
      if ((uVar6 & 0x200) != 0) {
        r_assert_err(0,0x10000,0x294c);
      }
      *puVar7 = *puVar7 & 0xbfffffff | uVar4 << 0x1e;
      return;
    }
  }
  return;
}

