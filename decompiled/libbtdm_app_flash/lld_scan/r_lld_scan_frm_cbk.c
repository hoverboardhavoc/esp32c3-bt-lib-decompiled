/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_3c;
  undefined4 uStack_38;
  
  if (1 < param_2) {
    r_assert_param("lld_scan.c",0xa1c);
  }
  if (param_3 != 2) {
    if (param_3 < 3) {
      param_2 = param_2 & 0xff;
      iVar13 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
         (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40410007,(uint)(param_3 != 0) << 8 | param_2);
      }
      r_lld_scan_frm_eof_isr(param_2,param_1,(uint)(param_3 != 0));
      if (((_lld_scan_env == 0) || (iVar13 = *(int *)(param_2 * 4 + _lld_scan_env), iVar13 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    else {
      if (param_3 != 4) {
        r_assert_param("lld_scan.c",0xa32);
        return;
      }
      param_2 = param_2 & 0xff;
      bVar5 = false;
      if ((_lld_scan_env != 0) && (iVar13 = *(int *)(_lld_scan_env + param_2 * 4), iVar13 != 0)) {
        bVar5 = *(char *)(iVar13 + 0x3d) == '\x01';
      }
      iVar13 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar13 + 0x28) & 8) != 0) &&
         (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40410008,param_2);
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar5) || (_lld_scan_env == 0)) ||
          (iVar13 = *(int *)(param_2 * 4 + _lld_scan_env), iVar13 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    if (((iVar13 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
       (*(char *)(iVar13 + 0x3d) != '\0')) {
      return;
    }
    if (((iVar13 != 0) && (_lld_scan_env != 0)) &&
       (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
      uStack_3c = 0;
      uStack_38 = 0;
      if (((iVar13 != 0) && (_lld_scan_env != 0)) &&
         (uStack_44 = 1, iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
        r_lld_ext_scan_dynamic_pti_get(iVar13,uStack_44,&uStack_3c);
        uVar15 = uStack_38;
        uVar8 = uStack_3c;
        bVar1 = *(byte *)(iVar13 + 0x38);
        uVar17 = uStack_3c & 0xff;
        uVar16 = uStack_3c >> 8;
        uVar10 = uStack_3c >> 0x18;
        bVar6 = uStack_38._1_1_;
        bVar7 = uStack_38._2_1_;
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x299b);
        }
        if ((uVar8 & 0xf0) != 0) {
          r_assert_err(0,"lld_scan.c",0x299d);
        }
        puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xfffff0ff | uVar17 << 8;
        bVar1 = *(byte *)(iVar13 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x294a);
        }
        if ((uVar8 & 0x200) != 0) {
          r_assert_err(0,"lld_scan.c",0x294c);
        }
        puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xbfffffff | uVar16 << 0x1e;
        bVar1 = *(byte *)(iVar13 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x29bb);
        }
        if (0xf < uVar10) {
          r_assert_err(0,"lld_scan.c",0x29bd);
        }
        puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xfffffff0 | uVar10;
        bVar1 = *(byte *)(iVar13 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x295a);
        }
        if ((uVar15 & 6) != 0) {
          r_assert_err(0,"lld_scan.c",0x295c);
        }
        puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xdfffffff | uVar15 << 0x1d;
        if (*(char *)(iVar13 + 0x39) == '\x01') {
          bVar1 = *(byte *)(iVar13 + 0x38);
          iVar13 = r_emi_get_mem_addr_by_offset(0x400);
          uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar13);
          if ((uVar15 & 0xf000) != 0) {
            r_assert_err(0,"lld_scan.c",0x33f);
          }
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar13 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
          uVar2 = *(ushort *)(iVar11 + iVar13);
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar11 + iVar13) = uVar2 & 0xf0ff | (ushort)bVar6 << 8;
          if ((uVar15 & 0xfe0000) != 0) {
            r_assert_err(0,"lld_scan.c",0x333);
          }
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar2 = *(ushort *)(iVar11 + iVar13);
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar11 + iVar13) = uVar2 & 0xefff | (ushort)bVar7 << 0xc;
        }
      }
      return;
    }
    return;
  }
  param_2 = param_2 & 0xff;
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_2 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0x9c1);
    return;
  }
  iVar13 = *(int *)(param_2 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar10 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar13 + 0x38));
    if (uVar10 == 0) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar11 + iVar13) < 0) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar11 + iVar13);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar11) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
      }
      return;
    }
    uVar16 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar14 = uVar16 * 0x14;
    uVar3 = *(undefined2 *)(iVar14 + 0x12 + iVar11);
    if (*(ushort *)(iVar13 + 0x36) < 0x673) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar14 + 2 + iVar11);
      iVar18 = iVar14 + 4;
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar8 = *(ushort *)(iVar11 + iVar18) & 0xf;
      if (uVar8 < 7) {
        uVar15 = uVar10;
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          r_lld_ext_scan_dynamic_pti_reset(iVar13);
        }
_L537:
        uVar10 = 0x128U >> uVar8 & 1;
      }
      else {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar4 = *(ushort *)(iVar14 + 0x10 + iVar11);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar15 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar11 + iVar18) >> 8);
        if (uVar8 < 9) goto _L537;
      }
      iVar11 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar11 + 0x18) == '\0') {
        uVar10 = (uint)(6 < uVar8) | uVar10 & 0xff;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar15 != 0)) && (uVar10 == 0)) {
        iVar11 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar11 + 0x28) & 8) != 0) &&
           (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40a1000a,
                     uVar8 << 0x10 | (uint)*(byte *)(iVar13 + 0x3d) << 0x18 | uVar16 << 8 | param_2)
          ;
        }
        uVar10 = (uint)uStack_44 >> 8;
        uStack_44 = CONCAT31((uint3)uVar10 & 0xffff00,0xff);
        *(undefined1 *)(iVar13 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar8) || ((0x128U >> uVar8 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x272);
        }
        if (uVar8 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar8,uVar16,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_2,uVar8,uVar16,&uStack_4c);
        iVar11 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar11 + 0x28) & 8) != 0) &&
           (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 2)) {
          iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar2 = *(ushort *)(iVar11 + iVar18);
          uVar12 = r_emi_get_mem_addr_by_offset(uVar3);
          r_ble_log_internal_hex(0x20a1000c,uVar2 >> 8,uVar12);
        }
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_2),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar13);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

