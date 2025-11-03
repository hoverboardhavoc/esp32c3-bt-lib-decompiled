/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010740) */
/* WARNING: Removing unreachable block (ram,0x0001065e) */
/* WARNING: Removing unreachable block (ram,0x0001059e) */
/* WARNING: Removing unreachable block (ram,0x000105fe) */
/* WARNING: Removing unreachable block (ram,0x000106be) */
/* WARNING: Removing unreachable block (ram,0x000107a8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  bool bVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if (1 < param_2) {
    r_assert_param("lld_scan.c",0xa5b);
  }
  if (param_3 != 2) {
    if (param_3 < 3) {
      param_2 = param_2 & 0xff;
      r_ble_log_internal_x1(0x404100b4,(uint)(param_3 != 0) << 8 | param_2);
      r_lld_scan_frm_eof_isr(param_2,param_1,(uint)(param_3 != 0));
      if (((_lld_scan_env == 0) || (iVar14 = *(int *)(param_2 * 4 + _lld_scan_env), iVar14 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    else {
      if (param_3 != 4) {
        r_assert_param("lld_scan.c",0xa71);
        return;
      }
      param_2 = param_2 & 0xff;
      bVar8 = false;
      if ((_lld_scan_env != 0) && (iVar14 = *(int *)(_lld_scan_env + param_2 * 4), iVar14 != 0)) {
        bVar8 = *(char *)(iVar14 + 0x3d) == '\x01';
        r_ble_log_internal_x2
                  (0x404100b5,*(undefined4 *)(iVar14 + 4),
                   (uint)*(byte *)(iVar14 + 0x16) << 8 | param_2);
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar8) || (_lld_scan_env == 0)) ||
          (iVar14 = *(int *)(param_2 * 4 + _lld_scan_env), iVar14 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    if (((iVar14 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
       (*(char *)(iVar14 + 0x3d) == '\0')) {
      if (((iVar14 != 0) && (_lld_scan_env != 0)) &&
         (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
        if (((iVar14 != 0) && (_lld_scan_env != 0)) &&
           (iVar11 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar11 != 0)) {
          r_lld_ext_scan_dynamic_pti_get(iVar14,1,&stack0xffffffd4);
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x299b);
          }
          puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar9 = *puVar9 & 0xfffff0ff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x294a);
          }
          puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar9 = *puVar9 & 0xbfffffff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x29bb);
          }
          puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar9 = *puVar9 & 0xfffffff0;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x295a);
          }
          puVar9 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar9 = *puVar9 & 0xdfffffff;
          if (*(char *)(iVar14 + 0x39) == '\x01') {
            bVar1 = *(byte *)(iVar14 + 0x38);
            iVar14 = r_emi_get_mem_addr_by_offset(0x400);
            uVar3 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar14);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar14 = ((uVar3 - 0x1400) / 0xe & 0xff) * 0xe + 10;
            uVar3 = *(ushort *)(iVar11 + iVar14);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar11 + iVar14) = uVar3 & 0xf0ff;
            iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar3 = *(ushort *)(iVar11 + iVar14);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar11 + iVar14) = uVar3 & 0xefff;
          }
        }
        return;
      }
      return;
    }
    return;
  }
  param_2 = param_2 & 0xff;
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_2 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0x9ff);
    return;
  }
  iVar14 = *(int *)(param_2 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar10 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar14 + 0x38));
    if (uVar10 == 0) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar14 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar11 + iVar14) < 0) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar11 + iVar14);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar14 + iVar11) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd8);
    uVar20 = (uint)bVar2;
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar11 = uVar20 * 0x14;
    uVar4 = *(undefined2 *)(iVar11 + 0x12 + iVar12);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar11 + 2 + iVar12);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar19 = iVar11 + 4;
    uVar21 = *(ushort *)(iVar12 + iVar11 + 6) >> 8 & 0x3f;
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar16 = (uint)(*(ushort *)(iVar12 + iVar11 + 6) >> 0xe);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar5 = *(ushort *)(iVar12 + iVar19);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = *(undefined2 *)(iVar11 + 10 + iVar12);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar7 = *(undefined2 *)(iVar11 + 8 + iVar12);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar17 = CONCAT22(uVar6,uVar7);
    uVar15 = uVar17 * 0x271;
    uVar18 = (0x270 - (*(ushort *)(iVar11 + 0xc + iVar12) & 0x3ff) & 0xffff) + uVar15;
    if ((6 < (uVar5 & 0xf)) && (*(char *)(iVar14 + 0x3d) != '\0')) {
      if (*(char *)(iVar14 + 0x3e) == '\x01') {
        uVar21 = (uint)*(byte *)(iVar14 + 0x54);
      }
      else {
        uVar21 = *(uint *)(iVar14 + 0x2c) & 0x3f;
      }
    }
    iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
    r_ble_log_internal_x3
              (0x20a100b2,
               ((uint)(uVar18 < uVar15) + (int)((ulonglong)uVar17 * 0x271 >> 0x20)) * -0x80000000 |
               uVar18 >> 1,CONCAT22(*(undefined2 *)(iVar12 + iVar19),uVar3),
               (uint)CONCAT11(bVar2,*(undefined1 *)(iVar14 + 0x38)) | (uVar16 << 4 | uVar16) << 0x18
               | uVar21 << 0x10);
    if (*(ushort *)(iVar14 + 0x36) < 0x673) {
      iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar15 = *(ushort *)(iVar12 + iVar19) & 0xf;
      if (uVar15 < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        uVar16 = uVar10;
        if (bVar2 != 0) {
          r_lld_ext_scan_dynamic_pti_reset(iVar14);
          uVar16 = (uint)bVar2;
        }
_L556:
        uVar17 = 0x128U >> uVar15 & 1;
      }
      else {
        iVar12 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar11 + 0x10 + iVar12);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar16 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar11 + iVar19) >> 8);
        uVar17 = uVar10;
        if (uVar15 < 9) goto _L556;
      }
      iVar11 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar11 + 0x18) == '\0') && (6 < uVar15)) {
        uVar17 = uVar10;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar16 != 0)) && (uVar17 == 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar14 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar15) || ((0x128U >> uVar15 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x295);
        }
        if (uVar15 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar15,uVar20,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep_hack(param_2,uVar15,uVar20,&uStack_4c);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar3 = *(ushort *)(iVar11 + iVar19);
        uVar13 = r_emi_get_mem_addr_by_offset(uVar4);
        r_ble_log_internal_hex(0x20a100b3,uVar3 >> 8,uVar13);
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

