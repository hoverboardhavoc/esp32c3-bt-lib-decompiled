/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_skip_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr_eco(uint param_1)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  bVar3 = false;
  if ((_lld_scan_env != 0) && (iVar9 = *(int *)(_lld_scan_env + param_1 * 4), iVar9 != 0)) {
    cVar1 = *(char *)(iVar9 + 0x3d);
    bVar6 = *(byte *)((int)&scan_skip_count + param_1) + 1;
    *(byte *)((int)&scan_skip_count + param_1) = bVar6;
    uStack_24 = (uint)bVar6 << 2;
    bVar3 = cVar1 == '\x01';
    if (0x20 < uStack_24) {
      uStack_24 = 0x20;
    }
    iVar5 = r_lld_read_clock();
    bVar6 = *(byte *)((int)&scan_skip_count + param_1);
    *(uint *)(iVar9 + 4) = iVar5 + uStack_24 & 0xffffffe;
    r_ble_log_internal_x3
              (0x4041013e,(uint)*(byte *)(iVar9 + 0x16) << 0x10 | (uint)bVar6 << 8 | param_1);
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((!bVar3) || (_lld_scan_env == 0)) ||
      (iVar9 = *(int *)(param_1 * 4 + _lld_scan_env), iVar9 == 0)) ||
     (*(char *)(_lld_scan_env + 0x17) == '\0')) {
    return;
  }
  if (((iVar9 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
     (*(char *)(iVar9 + 0x3d) != '\0')) {
    return;
  }
  if (((iVar9 != 0) && (_lld_scan_env != 0)) &&
     (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    if (((iVar9 != 0) && (_lld_scan_env != 0)) &&
       (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
      r_lld_ext_scan_dynamic_pti_get(iVar9,1,&uStack_2c);
      bVar6 = *(byte *)(iVar9 + 0x38);
      uVar7 = uStack_2c & 0xff;
      if (0xb < bVar6) {
        r_assert_err(0,"lld_scan.c",0x299b);
      }
      uVar7 = uVar7 << 8;
      if ((uVar7 & 0xf000) != 0) {
        r_assert_err(0,"lld_scan.c",0x299d);
      }
      puVar4 = (uint *)((bVar6 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xfffff0ff | uVar7;
      bVar6 = *(byte *)(iVar9 + 0x38);
      uVar7 = uStack_2c >> 8;
      if (0xb < bVar6) {
        r_assert_err(0,"lld_scan.c",0x294a);
      }
      uVar7 = uVar7 << 0x1e;
      if ((int)uVar7 < 0) {
        r_assert_err(0,"lld_scan.c",0x294c);
      }
      uVar8 = uStack_2c;
      puVar4 = (uint *)((bVar6 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xbfffffff | uVar7;
      bVar6 = *(byte *)(iVar9 + 0x38);
      uVar7 = uStack_2c >> 0x18;
      if (0xb < bVar6) {
        r_assert_err(0,"lld_scan.c",0x29bb);
      }
      if ((uVar8 & 0xf0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x29bd);
      }
      uVar8 = uStack_28;
      puVar4 = (uint *)((bVar6 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xfffffff0 | uVar7;
      bVar6 = *(byte *)(iVar9 + 0x38);
      if (0xb < bVar6) {
        r_assert_err(0,"lld_scan.c",0x295a);
      }
      if ((uVar8 << 0x1d & 0xc0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x295c);
      }
      puVar4 = (uint *)((bVar6 + 0x1800c4cb) * 4);
      *puVar4 = *puVar4 & 0xdfffffff | uVar8 << 0x1d;
      if (*(char *)(iVar9 + 0x39) == '\x01') {
        bVar6 = *(byte *)(iVar9 + 0x38);
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        uVar7 = (uStack_28 >> 8 & 0xff) << 8;
        uVar2 = *(ushort *)((uint)bVar6 * 0x5a + 0x34 + iVar9);
        if ((uVar7 & 0xfffff0ff) != 0) {
          r_assert_err(0,"lld_scan.c",0x33f);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar9 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar5 + iVar9);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar8 = (uStack_28 >> 0x10 & 0xff) << 0xc;
        *(ushort *)(iVar5 + iVar9) = uVar2 & 0xf0ff | (ushort)uVar7;
        if ((uVar8 & 0xffffefff) != 0) {
          r_assert_err(0,"lld_scan.c",0x333);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar5 + iVar9);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar5 + iVar9) = uVar2 & 0xefff | (ushort)uVar8;
      }
    }
    return;
  }
  return;
}

