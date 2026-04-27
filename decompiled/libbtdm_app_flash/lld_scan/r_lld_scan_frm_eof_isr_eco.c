/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_eof_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  *(undefined1 *)((int)&scan_skip_count + param_1) = 0;
  if ((_lld_scan_env == 0) || (iVar6 = *(int *)(_lld_scan_env + param_1 * 4), iVar6 == 0)) {
    uVar4 = 0xff;
    uVar7 = 0;
  }
  else {
    uVar4 = (uint)*(byte *)(iVar6 + 0x38);
    uVar7 = 0;
    if (uVar4 != 0xff) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(uVar4 * 0x5a + iVar6) & 0x1f;
    }
  }
  r_ble_log_internal_x1(0x4041013d,uVar4 << 0x10 | uVar7);
  r_lld_scan_frm_eof_isr(param_1,param_2,param_3);
  if (((_lld_scan_env == 0) || (iVar6 = *(int *)(param_1 * 4 + _lld_scan_env), iVar6 == 0)) ||
     (*(char *)(_lld_scan_env + 0x17) == '\0')) {
    return;
  }
  if (((iVar6 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
     (*(char *)(iVar6 + 0x3d) != '\0')) {
    return;
  }
  if (((iVar6 != 0) && (_lld_scan_env != 0)) &&
     (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    if (((iVar6 != 0) && (_lld_scan_env != 0)) &&
       (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
      r_lld_ext_scan_dynamic_pti_get(iVar6,1,&uStack_2c);
      bVar1 = *(byte *)(iVar6 + 0x38);
      uVar4 = uStack_2c & 0xff;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x299b);
      }
      uVar4 = uVar4 << 8;
      if ((uVar4 & 0xf000) != 0) {
        r_assert_err(0,"lld_scan.c",0x299d);
      }
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xfffff0ff | uVar4;
      bVar1 = *(byte *)(iVar6 + 0x38);
      uVar4 = uStack_2c >> 8;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x294a);
      }
      uVar4 = uVar4 << 0x1e;
      if ((int)uVar4 < 0) {
        r_assert_err(0,"lld_scan.c",0x294c);
      }
      uVar7 = uStack_2c;
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xbfffffff | uVar4;
      bVar1 = *(byte *)(iVar6 + 0x38);
      uVar4 = uStack_2c >> 0x18;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x29bb);
      }
      if ((uVar7 & 0xf0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x29bd);
      }
      uVar7 = uStack_28;
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xfffffff0 | uVar4;
      bVar1 = *(byte *)(iVar6 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x295a);
      }
      if ((uVar7 << 0x1d & 0xc0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x295c);
      }
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xdfffffff | uVar7 << 0x1d;
      if (*(char *)(iVar6 + 0x39) == '\x01') {
        bVar1 = *(byte *)(iVar6 + 0x38);
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar4 = (uStack_28 >> 8 & 0xff) << 8;
        uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar6);
        if ((uVar4 & 0xfffff0ff) != 0) {
          r_assert_err(0,"lld_scan.c",0x33f);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar6 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar5 + iVar6);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar7 = (uStack_28 >> 0x10 & 0xff) << 0xc;
        *(ushort *)(iVar5 + iVar6) = uVar2 & 0xf0ff | (ushort)uVar4;
        if ((uVar7 & 0xffffefff) != 0) {
          r_assert_err(0,"lld_scan.c",0x333);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar5 + iVar6);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar5 + iVar6) = uVar2 & 0xefff | (ushort)uVar7;
      }
    }
    return;
  }
  return;
}

