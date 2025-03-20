/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010688) */
/* WARNING: Removing unreachable block (ram,0x000105a4) */
/* WARNING: Removing unreachable block (ram,0x000104e4) */
/* WARNING: Removing unreachable block (ram,0x00010544) */
/* WARNING: Removing unreachable block (ram,0x00010604) */
/* WARNING: Removing unreachable block (ram,0x000106f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  ushort uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if (1 < param_2) {
    r_assert_param(param_2,param_3,"lld_scan.c",0xa0d);
  }
  if (param_3 == 1) {
    iVar14 = 1;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        param_2 = param_2 & 0xff;
        if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_2 * 4) == 0)) {
          r_assert_err(0,"lld_scan.c",0x9b2);
          return;
        }
        bVar1 = *(byte *)(_lld_scan_env + 0xd);
        iVar14 = *(int *)(param_2 * 4 + _lld_scan_env);
        do {
          uVar10 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar14 + 0x38));
          if (uVar10 == 0) {
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar14 = ((uint)bVar1 * 9 & 0xff) * 0xe;
            if (*(short *)(iVar13 + iVar14) < 0) {
              iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar2 = *(ushort *)(iVar13 + iVar14);
              iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar13 + iVar14) = uVar2 & 0x7fff;
            }
            return;
          }
          uVar17 = (uint)*(byte *)(_p_lld_env + 0xd8);
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          iVar13 = uVar17 * 0x14;
          uVar3 = *(undefined2 *)(iVar11 + iVar13 + 0x12);
          if (*(ushort *)(iVar14 + 0x36) < 0x673) {
            iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar2 = *(ushort *)(iVar11 + iVar13 + 2);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
            iVar16 = iVar13 + 4;
            uVar4 = *(ushort *)(iVar11 + iVar16);
            uVar7 = uVar4 & 0xf;
            uVar15 = uVar10;
            if (uVar7 < 7) {
              if (*(char *)(_lld_scan_env + 0x17) != '\0') {
                r_lld_ext_scan_dynamic_pti_reset(iVar14);
              }
              uVar9 = uVar10;
              if ((uVar7 - 3 & 0xfd) != 0) goto _L559;
            }
            else {
              iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
              uVar5 = *(ushort *)(iVar13 + 0x10 + iVar11);
              iVar13 = r_emi_get_mem_addr_by_offset(0x1000);
              uVar9 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar13 + iVar16) >> 8);
              if (uVar7 < 9) {
_L559:
                uVar15 = (uint)(uVar7 == 8);
              }
            }
            iVar13 = r_sdk_config_get_opts_ext();
            if ((*(char *)(iVar13 + 0x18) == '\0') && (6 < uVar7)) {
              uVar15 = uVar10;
            }
            if ((((uVar2 & 0x602d) == 0) && (uVar9 != 0)) && (uVar15 == 0)) {
              iVar13 = r_sdk_config_get_opts_ext();
              if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
                 (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
                r_ble_log_internal_x1
                          (0x40a1000a,
                           (uint)uVar7 << 0x10 |
                           (uint)*(byte *)(iVar14 + 0x3d) << 0x18 | uVar17 << 8 | param_2);
              }
              uStack_44 = 0xff;
              uStack_4c = 0;
              uStack_48 = 0;
              *(undefined1 *)(iVar14 + 0x43) = 1;
              if (((uVar4 & 8) != 0) || ((uVar7 - 3 & 0xfd) == 0)) {
                r_assert_err(0,"lld_scan.c",0x263);
              }
              if (uVar7 < 7) {
                r_lld_scan_process_pkt_rx_legacy_adv();
              }
              else {
                r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar7,uVar17,&uStack_4c);
              }
              r_lld_scan_process_pkt_rx_adv_rep(param_2,uVar7,uVar17,&uStack_4c);
              iVar13 = r_sdk_config_get_opts_ext();
              if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
                 (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 2)) {
                iVar13 = r_emi_get_mem_addr_by_offset(0x1000);
                uVar2 = *(ushort *)(iVar13 + iVar16);
                uVar12 = r_emi_get_mem_addr_by_offset(uVar3);
                r_ble_log_internal_hex(0x20a1000c,uVar2 >> 8,uVar12);
              }
            }
            else if (((_DAT_60031048 & 8) != 0) &&
                    (r_lld_continue_scan_rx_isr_end_process(param_2),
                    *(char *)(_lld_scan_env + 0x17) != '\0')) {
              r_lld_ext_scan_dynamic_pti_reset(iVar14);
            }
          }
          r_lld_rxdesc_free();
        } while( true );
      }
      if (param_3 != 4) {
        r_assert_param(param_2,param_3,"lld_scan.c",0xa23);
        return;
      }
      param_2 = param_2 & 0xff;
      bVar6 = false;
      if ((_lld_scan_env != 0) && (iVar14 = *(int *)(_lld_scan_env + param_2 * 4), iVar14 != 0)) {
        bVar6 = *(char *)(iVar14 + 0x3d) == '\x01';
      }
      iVar14 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar14 + 0x28) & 8) != 0) &&
         (iVar14 = r_sdk_config_get_opts_ext(), *(byte *)(iVar14 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40410008,param_2);
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar6) || (_lld_scan_env == 0)) ||
          (iVar14 = *(int *)(param_2 * 4 + _lld_scan_env), iVar14 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
      goto code_r0x000107a8;
    }
    iVar14 = 0;
  }
  param_2 = param_2 & 0xff;
  iVar13 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
     (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40410007,iVar14 << 8 | param_2);
  }
  r_lld_scan_frm_eof_isr(param_2,param_1,iVar14);
  if (((_lld_scan_env == 0) || (iVar14 = *(int *)(param_2 * 4 + _lld_scan_env), iVar14 == 0)) ||
     (*(char *)(_lld_scan_env + 0x17) == '\0')) {
    return;
  }
code_r0x000107a8:
  if (((iVar14 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
     (*(char *)(iVar14 + 0x3d) == '\0')) {
    if ((iVar14 != 0) && (_lld_scan_env != 0)) {
      iVar13 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get();
      if (iVar13 != 0) {
        if (((iVar14 != 0) && (_lld_scan_env != 0)) &&
           (iVar13 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar13 != 0)) {
          r_lld_ext_scan_dynamic_pti_get(iVar14,1,&stack0xffffffd4);
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x299b);
          }
          puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar8 = *puVar8 & 0xfffff0ff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x294a);
          }
          puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar8 = *puVar8 & 0xbfffffff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x29bb);
          }
          puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar8 = *puVar8 & 0xfffffff0;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x295a);
          }
          puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar8 = *puVar8 & 0xdfffffff;
          if (*(char *)(iVar14 + 0x39) == '\x01') {
            bVar1 = *(byte *)(iVar14 + 0x38);
            iVar14 = r_emi_get_mem_addr_by_offset(0x400);
            uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar14);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar14 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
            uVar2 = *(ushort *)(iVar13 + iVar14);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar14) = uVar2 & 0xf0ff;
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar2 = *(ushort *)(iVar13 + iVar14);
            iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar13 + iVar14) = uVar2 & 0xefff;
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

