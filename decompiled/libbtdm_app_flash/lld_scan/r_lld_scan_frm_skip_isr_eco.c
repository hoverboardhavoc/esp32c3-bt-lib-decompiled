/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_skip_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr_eco(int param_1)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  bVar3 = false;
  if ((_lld_scan_env != 0) && (iVar12 = *(int *)(_lld_scan_env + param_1 * 4), iVar12 != 0)) {
    bVar3 = *(char *)(iVar12 + 0x3d) == '\x01';
  }
  iVar12 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar12 + 0x28) & 8) != 0) &&
     (iVar12 = r_sdk_config_get_opts_ext(), *(byte *)(iVar12 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40410008,param_1);
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((!bVar3) || (_lld_scan_env == 0)) ||
      (iVar12 = *(int *)(param_1 * 4 + _lld_scan_env), iVar12 == 0)) ||
     (*(char *)(_lld_scan_env + 0x17) == '\0')) {
    return;
  }
  if (((iVar12 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
     (*(char *)(iVar12 + 0x3d) != '\0')) {
    return;
  }
  if (((iVar12 != 0) && (_lld_scan_env != 0)) &&
     (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    if (((iVar12 != 0) && (_lld_scan_env != 0)) &&
       (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
      r_lld_ext_scan_dynamic_pti_get(iVar12,1,&uStack_3c);
      uVar7 = uStack_38;
      uVar6 = uStack_3c;
      bVar1 = *(byte *)(iVar12 + 0x38);
      uVar13 = uStack_3c & 0xff;
      uVar5 = uStack_3c >> 8;
      uVar4 = uStack_3c >> 0x18;
      bVar8 = uStack_38._1_1_;
      bVar9 = uStack_38._2_1_;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x299b);
      }
      if ((uVar6 & 0xf0) != 0) {
        r_assert_err(0,"lld_scan.c",0x299d);
      }
      puVar10 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar10 = *puVar10 & 0xfffff0ff | uVar13 << 8;
      bVar1 = *(byte *)(iVar12 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x294a);
      }
      if ((uVar6 & 0x200) != 0) {
        r_assert_err(0,"lld_scan.c",0x294c);
      }
      puVar10 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar10 = *puVar10 & 0xbfffffff | uVar5 << 0x1e;
      bVar1 = *(byte *)(iVar12 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x29bb);
      }
      if (0xf < uVar4) {
        r_assert_err(0,"lld_scan.c",0x29bd);
      }
      puVar10 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar10 = *puVar10 & 0xfffffff0 | uVar4;
      bVar1 = *(byte *)(iVar12 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x295a);
      }
      if ((uVar7 & 6) != 0) {
        r_assert_err(0,"lld_scan.c",0x295c);
      }
      puVar10 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar10 = *puVar10 & 0xdfffffff | uVar7 << 0x1d;
      if (*(char *)(iVar12 + 0x39) == '\x01') {
        bVar1 = *(byte *)(iVar12 + 0x38);
        iVar12 = r_emi_get_mem_addr_by_offset(0x400);
        uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar12);
        if ((uVar7 & 0xf000) != 0) {
          r_assert_err(0,"lld_scan.c",0x33f);
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar12 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar11 + iVar12);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar11 + iVar12) = uVar2 & 0xf0ff | (ushort)bVar8 << 8;
        if ((uVar7 & 0xfe0000) != 0) {
          r_assert_err(0,"lld_scan.c",0x333);
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar11 + iVar12);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar11 + iVar12) = uVar2 & 0xefff | (ushort)bVar9 << 0xc;
      }
    }
    return;
  }
  return;
}

