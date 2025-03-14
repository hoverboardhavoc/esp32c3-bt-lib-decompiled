/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  bVar3 = false;
  if ((_lld_scan_env != 0) && (iVar7 = *(int *)(_lld_scan_env + param_1 * 4), iVar7 != 0)) {
    bVar3 = *(char *)(iVar7 + 0x3d) == '\x01';
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((bVar3) && (_lld_scan_env != 0)) &&
      (iVar7 = *(int *)(param_1 * 4 + _lld_scan_env), iVar7 != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
    if (((iVar7 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
       (*(char *)(iVar7 + 0x3d) == '\0')) {
      if ((iVar7 != 0) && (_lld_scan_env != 0)) {
        iVar6 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get();
        if (iVar6 != 0) {
          uStack_2c = 0;
          uStack_28 = 0;
          uStack_24 = 0;
          if (((iVar7 != 0) && (_lld_scan_env != 0)) &&
             (iVar6 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar6 != 0)) {
            r_lld_ext_scan_dynamic_pti_get(iVar7,1,&uStack_2c);
            bVar1 = *(byte *)(iVar7 + 0x38);
            uVar8 = uStack_2c & 0xff;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x299b);
            }
            uVar8 = uVar8 << 8;
            if ((uVar8 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",0x299d);
            }
            puVar5 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar5 = *puVar5 & 0xfffff0ff | uVar8;
            bVar1 = *(byte *)(iVar7 + 0x38);
            uVar8 = uStack_2c >> 8;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x294a);
            }
            uVar8 = uVar8 << 0x1e;
            if ((int)uVar8 < 0) {
              r_assert_err(0,"lld_scan.c",0x294c);
            }
            uVar4 = uStack_2c;
            puVar5 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar5 = *puVar5 & 0xbfffffff | uVar8;
            bVar1 = *(byte *)(iVar7 + 0x38);
            uVar8 = uStack_2c >> 0x18;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x29bb);
            }
            if ((uVar4 & 0xf0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x29bd);
            }
            uVar4 = uStack_28;
            puVar5 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar5 = *puVar5 & 0xfffffff0 | uVar8;
            bVar1 = *(byte *)(iVar7 + 0x38);
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x295a);
            }
            if ((uVar4 << 0x1d & 0xc0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x295c);
            }
            puVar5 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar5 = *puVar5 & 0xdfffffff | uVar4 << 0x1d;
            if (*(char *)(iVar7 + 0x39) == '\x01') {
              bVar1 = *(byte *)(iVar7 + 0x38);
              iVar7 = r_emi_get_mem_addr_by_offset(0x400);
              uVar8 = (uStack_28 >> 8 & 0xff) << 8;
              uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar7);
              if ((uVar8 & 0xfffff0ff) != 0) {
                r_assert_err(0,"lld_scan.c",0x33f);
              }
              iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
              iVar7 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
              uVar2 = *(ushort *)(iVar6 + iVar7);
              iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar6 + iVar7) = uVar2 & 0xf0ff | (ushort)uVar8;
              uVar8 = (uStack_28 >> 0x10 & 0xff) << 0xc;
              if ((uVar8 & 0xffffefff) != 0) {
                r_assert_err(0,"lld_scan.c",0x333);
              }
              iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar2 = *(ushort *)(iVar6 + iVar7);
              iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar6 + iVar7) = uVar2 & 0xefff | (ushort)uVar8;
            }
          }
          return;
        }
        return;
      }
      return;
    }
    return;
  }
  return;
}

