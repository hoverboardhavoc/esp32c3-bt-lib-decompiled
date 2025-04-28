/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  if ((((param_1 != 0) && (_lld_scan_env != 0)) &&
      (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) &&
     (((*(char *)(param_1 + 0x39) != '\x01' || (*(char *)(param_1 + 0x3d) != '\x02')) ||
      (1 < param_2 - 2U)))) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    if (((param_1 != 0) && (_lld_scan_env != 0)) &&
       (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
      r_lld_ext_scan_dynamic_pti_get(param_1,param_2,&uStack_2c);
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar6 = uStack_2c & 0xff;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x299b);
      }
      uVar6 = uVar6 << 8;
      if ((uVar6 & 0xf000) != 0) {
        r_assert_err(0,"lld_scan.c",0x299d);
      }
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xfffff0ff | uVar6;
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar6 = uStack_2c >> 8;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x294a);
      }
      uVar6 = uVar6 << 0x1e;
      if ((int)uVar6 < 0) {
        r_assert_err(0,"lld_scan.c",0x294c);
      }
      uVar7 = uStack_2c;
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xbfffffff | uVar6;
      bVar1 = *(byte *)(param_1 + 0x38);
      uVar6 = uStack_2c >> 0x18;
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x29bb);
      }
      if ((uVar7 & 0xf0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x29bd);
      }
      uVar7 = uStack_28;
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xfffffff0 | uVar6;
      bVar1 = *(byte *)(param_1 + 0x38);
      if (0xb < bVar1) {
        r_assert_err(0,"lld_scan.c",0x295a);
      }
      if ((uVar7 << 0x1d & 0xc0000000) != 0) {
        r_assert_err(0,"lld_scan.c",0x295c);
      }
      puVar3 = (uint *)((bVar1 + 0x1800c4cb) * 4);
      *puVar3 = *puVar3 & 0xdfffffff | uVar7 << 0x1d;
      if (*(char *)(param_1 + 0x39) == '\x01') {
        bVar1 = *(byte *)(param_1 + 0x38);
        iVar5 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = (uStack_28 >> 8 & 0xff) << 8;
        uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar5);
        if ((uVar6 & 0xfffff0ff) != 0) {
          r_assert_err(0,"lld_scan.c",0x33f);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar5 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar7 = (uStack_28 >> 0x10 & 0xff) << 0xc;
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xf0ff | (ushort)uVar6;
        if ((uVar7 & 0xffffefff) != 0) {
          r_assert_err(0,"lld_scan.c",0x333);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar4 + iVar5);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)uVar7;
      }
    }
    return;
  }
  return;
}

