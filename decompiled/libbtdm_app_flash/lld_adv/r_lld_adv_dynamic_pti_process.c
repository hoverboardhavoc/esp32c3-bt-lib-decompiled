/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  ushort uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte bStack_48;
  byte bStack_47;
  byte bStack_45;
  byte bStack_44;
  byte bStack_43;
  byte bStack_42;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  if (param_1 == 0) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x74) & 0x10) == 0) {
    iVar9 = r_bt_rf_coex_ext_adv_dynamic_pti_en_get();
    if (iVar9 != 0) {
      iVar9 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar9 + 0x18) != '\0') {
        memset(&bStack_48,0,0x18);
        uVar7 = (uint)*(byte *)(param_1 + 0x87);
        uVar1 = *(ushort *)(param_1 + 0x74);
        r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&bStack_48);
        uVar10 = uVar7 * 9 & 0xff;
        uVar11 = uVar10 + 1 & 0xff;
        if (0xb < uVar7) {
          r_assert_err(0,0x10000,0x29bb);
        }
        if ((bStack_43 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x29bd);
        }
        puVar6 = (uint *)((uVar7 + 0x1800c4cb) * 4);
        *puVar6 = *puVar6 & 0xfffffff0 | (uint)bStack_43;
        if (0xb < uVar7) {
          r_assert_err(0,0x10000,0x295a);
        }
        if (((uint)bStack_42 << 0x1d & 0xc0000000) != 0) {
          r_assert_err(0,0x10000,0x295c);
        }
        *puVar6 = *puVar6 & 0xdfffffff | (uint)bStack_42 << 0x1d;
        if (0xb < uVar7) {
          r_assert_err(0,0x10000,0x299b);
        }
        if (((uint)bStack_48 << 8 & 0xf000) != 0) {
          r_assert_err(0,0x10000,0x299d);
        }
        *puVar6 = *puVar6 & 0xfffff0ff | (uint)bStack_48 << 8;
        if (0xb < uVar7) {
          r_assert_err(0,0x10000,0x294a);
        }
        if ((int)((uint)bStack_47 << 0x1e) < 0) {
          r_assert_err(0,0x10000,0x294c);
        }
        *puVar6 = *puVar6 & 0xbfffffff | (uint)bStack_47 << 0x1e;
        if ((bStack_45 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar8 = uVar10 * 0xe + 10;
        uVar2 = *(ushort *)(iVar9 + iVar8);
        uVar3 = (ushort)(((uint)bStack_45 << 0x18) >> 0x10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar8) = uVar2 & 0xf0ff | uVar3;
        if ((bStack_44 & 0xfe) != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar9 + iVar8);
        uVar4 = (ushort)(((uint)bStack_44 << 0x1c) >> 0x10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar8) = uVar4 | uVar2 & 0xefff;
        if ((bStack_45 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar8 = uVar11 * 0xe + 10;
        uVar2 = *(ushort *)(iVar9 + iVar8);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar8) = uVar3 | uVar2 & 0xf0ff;
        if ((bStack_44 & 0xfe) != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar9 + iVar8);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar8) = uVar4 | uVar2 & 0xefff;
        r_lld_ext_adv_dynamic_aux_pti_process_eco(uVar1 & 3,uVar11,&bStack_48);
        return;
      }
      r_assert_err(0,0x10000,0x45b);
      return;
    }
  }
  else {
    iVar9 = r_bt_rf_coex_legacy_adv_dynamic_pti_en_get();
    if (iVar9 != 0) {
      uVar11 = (uint)*(byte *)(param_1 + 0x87);
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      r_lld_legacy_adv_dynamic_pti_get(&uStack_40);
      uVar10 = uStack_40;
      uVar7 = uStack_40 & 0xf0;
      if (uVar7 != 0) {
        r_assert_err(0,0x10000,0x33f);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = (uVar11 * 9 & 0xff) * 0xe;
      iVar12 = iVar9 + 10;
      uVar1 = *(ushort *)(iVar8 + iVar12);
      uVar2 = (ushort)((uVar10 << 0x18) >> 0x10);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar8 + iVar12) = uVar2 | uVar1 & 0xf0ff;
      uVar5 = uStack_40 >> 8;
      uVar10 = uVar5 & 0xfe;
      if (uVar10 != 0) {
        r_assert_err(0,0x10000,0x333);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar8 + iVar12);
      uVar3 = (ushort)((uVar5 << 0x1c) >> 0x10);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar8 + iVar12) = uVar3 | uVar1 & 0xefff;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((*(ushort *)(iVar8 + iVar9) & 0x7fff) != 0) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar1 = *(ushort *)(iVar9 + iVar8);
        if (uVar7 != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar9 = (((uVar1 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
        uVar1 = *(ushort *)(iVar8 + iVar9);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar9) = uVar2 | uVar1 & 0xf0ff;
        if (uVar10 != 0) {
          r_assert_err(0,0x10000,0x333);
        }
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar1 = *(ushort *)(iVar8 + iVar9);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar9) = uVar3 | uVar1 & 0xefff;
      }
      uVar10 = uStack_40;
      uVar7 = uStack_40 >> 0x10;
      if (0xb < uVar11) {
        r_assert_err(0,0x10000,0x29bb);
      }
      if ((uVar10 & 0xf00000) != 0) {
        r_assert_err(0,0x10000,0x29bd);
      }
      puVar6 = (uint *)((uVar11 + 0x1800c4cb) * 4);
      *puVar6 = *puVar6 & 0xfffffff0 | uVar7 & 0xff;
      uVar7 = uStack_40 >> 0x18;
      if (0xb < uVar11) {
        r_assert_err(0,0x10000,0x295a);
      }
      uVar7 = uVar7 << 0x1d;
      if ((uVar7 & 0xc0000000) != 0) {
        r_assert_err(0,0x10000,0x295c);
      }
      *puVar6 = *puVar6 & 0xdfffffff | uVar7;
      uVar7 = uStack_3c & 0xff;
      if (0xb < uVar11) {
        r_assert_err(0,0x10000,0x299b);
      }
      uVar7 = uVar7 << 8;
      if ((uVar7 & 0xf000) != 0) {
        r_assert_err(0,0x10000,0x299d);
      }
      *puVar6 = *puVar6 & 0xfffff0ff | uVar7;
      uVar7 = uStack_3c >> 8;
      if (0xb < uVar11) {
        r_assert_err(0,0x10000,0x294a);
      }
      uVar7 = uVar7 << 0x1e;
      if ((int)uVar7 < 0) {
        r_assert_err(0,0x10000,0x294c);
      }
      *puVar6 = *puVar6 & 0xbfffffff | uVar7;
      return;
    }
  }
  return;
}

