/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_dynamic_pti_process(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bStack_38;
  byte bStack_37;
  byte bStack_35;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  if (param_1 == 0) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x74) & 0x10) == 0) {
    iVar5 = r_bt_rf_coex_ext_adv_dynamic_pti_en_get();
    if (iVar5 != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar5 + 0x18) != '\0') {
        memset(&bStack_38,0,0x18);
        uVar8 = (uint)*(byte *)(param_1 + 0x87);
        bVar1 = *(byte *)(param_1 + 0x74);
        r_lld_ext_adv_dynamic_pti_get(param_1,param_2,param_3,&bStack_38);
        uVar6 = uVar8 * 9 & 0xff;
        uVar9 = uVar6 + 1 & 0xff;
        if (0xb < uVar8) {
          r_assert_err(0,"lld_adv.c",0x29bb);
        }
        if ((bStack_33 & 0xf0) != 0) {
          r_assert_err(0,"lld_adv.c",0x29bd);
        }
        puVar3 = (uint *)((uVar8 + 0x1800c4cb) * 4);
        *puVar3 = *puVar3 & 0xfffffff0 | (uint)bStack_33;
        if (0xb < uVar8) {
          r_assert_err(0,"lld_adv.c",0x295a);
        }
        if (((uint)bStack_32 << 0x1d & 0xc0000000) != 0) {
          r_assert_err(0,"lld_adv.c",0x295c);
        }
        *puVar3 = *puVar3 & 0xdfffffff | (uint)bStack_32 << 0x1d;
        if (0xb < uVar8) {
          r_assert_err(0,"lld_adv.c",0x299b);
        }
        if (((uint)bStack_38 << 8 & 0xf000) != 0) {
          r_assert_err(0,"lld_adv.c",0x299d);
        }
        *puVar3 = *puVar3 & 0xfffff0ff | (uint)bStack_38 << 8;
        if (0xb < uVar8) {
          r_assert_err(0,"lld_adv.c",0x294a);
        }
        if ((int)((uint)bStack_37 << 0x1e) < 0) {
          r_assert_err(0,"lld_adv.c",0x294c);
        }
        *puVar3 = *puVar3 & 0xbfffffff | (uint)bStack_37 << 0x1e;
        uVar8 = (uint)bStack_35;
        if ((uVar8 << 8 & 0xf000) != 0) {
          r_assert_err(0,"lld_adv.c",0x33f);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar5 = uVar6 * 0xe + 10;
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xf0ff | (ushort)(uVar8 << 8);
        uVar6 = (uint)bStack_34;
        if ((uVar6 << 0xc & 0xffffefff) != 0) {
          r_assert_err(0,"lld_adv.c",0x333);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)(uVar6 << 0xc);
        if (((uint)bStack_35 << 8 & 0xfffff0ff) != 0) {
          r_assert_err(0,"lld_adv.c",0x33f);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar5 = uVar9 * 0xe + 10;
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xf0ff | (ushort)((uint)bStack_35 << 8);
        if (((uint)bStack_34 << 0xc & 0xffffefff) != 0) {
          r_assert_err(0,"lld_adv.c",0x333);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)((uint)bStack_34 << 0xc);
        r_lld_ext_adv_dynamic_aux_pti_process_eco(bVar1 & 3,uVar9,&bStack_38);
        return;
      }
      r_assert_err(0,"lld_adv.c",0x46a);
      return;
    }
  }
  else {
    iVar5 = r_bt_rf_coex_legacy_adv_dynamic_pti_en_get();
    if (iVar5 != 0) {
      uVar6 = (uint)*(byte *)(param_1 + 0x87);
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      r_lld_legacy_adv_dynamic_pti_get(&uStack_30);
      uVar9 = (uStack_30 & 0xff) << 8;
      if ((uVar9 & 0xf000) != 0) {
        r_assert_err(0,"lld_adv.c",0x33f);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar5 = (uVar6 * 9 & 0xff) * 0xe;
      iVar7 = iVar5 + 10;
      uVar2 = *(ushort *)(iVar4 + iVar7);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar7) = uVar2 & 0xf0ff | (ushort)uVar9;
      uVar9 = (uStack_30 >> 8 & 0xff) << 0xc;
      if ((uVar9 & 0xffffefff) != 0) {
        r_assert_err(0,"lld_adv.c",0x333);
      }
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar2 = *(ushort *)(iVar4 + iVar7);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar7) = uVar2 & 0xefff | (ushort)uVar9;
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((*(ushort *)(iVar4 + iVar5) & 0x7fff) != 0) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar4 + iVar5);
        uVar9 = (uStack_30 & 0xff) << 8;
        if ((uVar9 & 0xfffff0ff) != 0) {
          r_assert_err(0,"lld_adv.c",0x33f);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar5 = (((uVar2 & 0x7fff) - 0x1400) / 0xe) * 0xe + 10;
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xf0ff | (ushort)uVar9;
        uVar9 = (uStack_30 >> 8 & 0xff) << 0xc;
        if ((uVar9 & 0xffffefff) != 0) {
          r_assert_err(0,"lld_adv.c",0x333);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)uVar9;
      }
      uVar8 = uStack_30;
      uVar9 = uStack_30 >> 0x10;
      if (0xb < uVar6) {
        r_assert_err(0,"lld_adv.c",0x29bb);
      }
      if ((uVar8 & 0xf00000) != 0) {
        r_assert_err(0,"lld_adv.c",0x29bd);
      }
      puVar3 = (uint *)((uVar6 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xfffffff0 | uVar9 & 0xff;
      uVar9 = uStack_30 >> 0x18;
      if (0xb < uVar6) {
        r_assert_err(0,"lld_adv.c",0x295a);
      }
      uVar9 = uVar9 << 0x1d;
      if ((uVar9 & 0xc0000000) != 0) {
        r_assert_err(0,"lld_adv.c",0x295c);
      }
      *puVar3 = *puVar3 & 0xdfffffff | uVar9;
      uVar9 = uStack_2c & 0xff;
      if (0xb < uVar6) {
        r_assert_err(0,"lld_adv.c",0x299b);
      }
      uVar9 = uVar9 << 8;
      if ((uVar9 & 0xf000) != 0) {
        r_assert_err(0,"lld_adv.c",0x299d);
      }
      *puVar3 = *puVar3 & 0xfffff0ff | uVar9;
      uVar9 = uStack_2c >> 8;
      if (0xb < uVar6) {
        r_assert_err(0,"lld_adv.c",0x294a);
      }
      uVar9 = uVar9 << 0x1e;
      if ((int)uVar9 < 0) {
        r_assert_err(0,"lld_adv.c",0x294c);
      }
      *puVar3 = *puVar3 & 0xbfffffff | uVar9;
      return;
    }
  }
  return;
}

