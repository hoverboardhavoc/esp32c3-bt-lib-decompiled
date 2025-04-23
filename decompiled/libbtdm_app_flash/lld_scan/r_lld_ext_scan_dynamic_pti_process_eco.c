/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_ext_scan_dynamic_pti_process_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_scan_dynamic_pti_process_eco(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if ((((param_1 != 0) && (_lld_scan_env != 0)) &&
      (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) &&
     (((*(char *)(param_1 + 0x39) != '\x01' || (*(char *)(param_1 + 0x3d) != '\x02')) ||
      (1 < param_2 - 2U)))) {
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    if (((param_1 != 0) && (_lld_scan_env != 0)) &&
       (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
      r_lld_ext_scan_dynamic_pti_get(param_1,param_2,&uStack_3c);
      uVar6 = uStack_38;
      uVar5 = uStack_3c;
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar12 = uStack_3c & 0xff;
      uVar4 = uStack_3c >> 8;
      uVar3 = uStack_3c >> 0x18;
      bVar7 = uStack_38._1_1_;
      bVar8 = uStack_38._2_1_;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x299b);
      }
      if ((uVar5 & 0xf0) != 0) {
        r_assert_err(0,"lld_scan.c",0x299d);
      }
      puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar9 = *puVar9 & 0xfffff0ff | uVar12 << 8;
      bVar1 = *(byte *)(param_1 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x294a);
      }
      if ((uVar5 & 0x200) != 0) {
        r_assert_err(0,"lld_scan.c",0x294c);
      }
      puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar9 = *puVar9 & 0xbfffffff | uVar4 << 0x1e;
      bVar1 = *(byte *)(param_1 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x29bb);
      }
      if (0xf < uVar3) {
        r_assert_err(0,"lld_scan.c",0x29bd);
      }
      puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar9 = *puVar9 & 0xfffffff0 | uVar3;
      bVar1 = *(byte *)(param_1 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x295a);
      }
      if ((uVar6 & 6) != 0) {
        r_assert_err(0,"lld_scan.c",0x295c);
      }
      puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar9 = *puVar9 & 0xdfffffff | uVar6 << 0x1d;
      if (*(char *)(param_1 + 0x39) == '\x01') {
        bVar1 = *(byte *)(param_1 + 0x38);
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar11);
        if ((uVar6 & 0xf000) != 0) {
          r_assert_err(0,"lld_scan.c",0x33f);
        }
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar11 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar10 + iVar11);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar10 + iVar11) = uVar2 & 0xf0ff | (ushort)bVar7 << 8;
        if ((uVar6 & 0xfe0000) != 0) {
          r_assert_err(0,"lld_scan.c",0x333);
        }
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar10 + iVar11);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar10 + iVar11) = uVar2 & 0xefff | (ushort)bVar8 << 0xc;
      }
    }
    return;
  }
  return;
}

