/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_eof_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr_eco(uint param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 8) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40410007,param_3 << 8 | param_1);
  }
  r_lld_scan_frm_eof_isr(param_1,param_2,param_3);
  if (((_lld_scan_env != 0) && (iVar6 = *(int *)(param_1 * 4 + _lld_scan_env), iVar6 != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
    if (((iVar6 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
       (*(char *)(iVar6 + 0x3d) == '\0')) {
      if ((iVar6 != 0) && (_lld_scan_env != 0)) {
        iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get();
        if (iVar5 != 0) {
          uStack_2c = 0;
          uStack_28 = 0;
          uStack_24 = 0;
          if (((iVar6 != 0) && (_lld_scan_env != 0)) &&
             (iVar5 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar5 != 0)) {
            r_lld_ext_scan_dynamic_pti_get(iVar6,1,&uStack_2c);
            bVar1 = *(byte *)(iVar6 + 0x38);
            uVar7 = uStack_2c & 0xff;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x299b);
            }
            uVar7 = uVar7 << 8;
            if ((uVar7 & 0xf000) != 0) {
              r_assert_err(0,"lld_scan.c",0x299d);
            }
            puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar4 = *puVar4 & 0xfffff0ff | uVar7;
            bVar1 = *(byte *)(iVar6 + 0x38);
            uVar7 = uStack_2c >> 8;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x294a);
            }
            uVar7 = uVar7 << 0x1e;
            if ((int)uVar7 < 0) {
              r_assert_err(0,"lld_scan.c",0x294c);
            }
            uVar3 = uStack_2c;
            puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar4 = *puVar4 & 0xbfffffff | uVar7;
            bVar1 = *(byte *)(iVar6 + 0x38);
            uVar7 = uStack_2c >> 0x18;
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x29bb);
            }
            if ((uVar3 & 0xf0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x29bd);
            }
            uVar3 = uStack_28;
            puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar4 = *puVar4 & 0xfffffff0 | uVar7;
            bVar1 = *(byte *)(iVar6 + 0x38);
            if (0xb < bVar1) {
              r_assert_err(0,"lld_scan.c",0x295a);
            }
            if ((uVar3 << 0x1d & 0xc0000000) != 0) {
              r_assert_err(0,"lld_scan.c",0x295c);
            }
            puVar4 = (uint *)((bVar1 + 0x1800c4cb) * 4);
            *puVar4 = *puVar4 & 0xdfffffff | uVar3 << 0x1d;
            if (*(char *)(iVar6 + 0x39) == '\x01') {
              bVar1 = *(byte *)(iVar6 + 0x38);
              iVar6 = r_emi_get_mem_addr_by_offset(0x400);
              uVar7 = (uStack_28 >> 8 & 0xff) << 8;
              uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar6);
              if ((uVar7 & 0xfffff0ff) != 0) {
                r_assert_err(0,"lld_scan.c",0x33f);
              }
              iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
              iVar6 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
              uVar2 = *(ushort *)(iVar5 + iVar6);
              iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar5 + iVar6) = uVar2 & 0xf0ff | (ushort)uVar7;
              uVar7 = (uStack_28 >> 0x10 & 0xff) << 0xc;
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
      return;
    }
    return;
  }
  return;
}

