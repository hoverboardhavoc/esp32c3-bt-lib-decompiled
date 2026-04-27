/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001074e) */
/* WARNING: Removing unreachable block (ram,0x0001066c) */
/* WARNING: Removing unreachable block (ram,0x000105ac) */
/* WARNING: Removing unreachable block (ram,0x0001060c) */
/* WARNING: Removing unreachable block (ram,0x000106cc) */
/* WARNING: Removing unreachable block (ram,0x000107b6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  bool bVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if (1 < param_2) {
    r_assert_param("lld_scan.c",0xa6e);
  }
  if (param_3 != 2) {
    if (param_3 < 3) {
      param_2 = param_2 & 0xff;
      *(undefined1 *)((int)&scan_skip_count + param_2) = 0;
      if ((_lld_scan_env == 0) || (iVar18 = *(int *)(_lld_scan_env + param_2 * 4), iVar18 == 0)) {
        uVar10 = 0xff;
        uVar19 = 0;
      }
      else {
        uVar10 = (uint)*(byte *)(iVar18 + 0x38);
        uVar19 = 0;
        if (uVar10 != 0xff) {
          iVar18 = r_emi_get_mem_addr_by_offset(0x400);
          uVar19 = *(ushort *)(uVar10 * 0x5a + iVar18) & 0x1f;
        }
      }
      r_ble_log_internal_x1(0x4041013d,uVar10 << 0x10 | uVar19);
      r_lld_scan_frm_eof_isr(param_2,param_1,param_3 != 0);
      if (((_lld_scan_env == 0) || (iVar18 = *(int *)(param_2 * 4 + _lld_scan_env), iVar18 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    else {
      if (param_3 != 4) {
        r_assert_param("lld_scan.c",0xa84);
        return;
      }
      param_2 = param_2 & 0xff;
      bVar8 = false;
      if ((_lld_scan_env != 0) && (iVar18 = *(int *)(_lld_scan_env + param_2 * 4), iVar18 != 0)) {
        cVar2 = *(char *)(iVar18 + 0x3d);
        bVar14 = *(byte *)((int)&scan_skip_count + param_2) + 1;
        *(byte *)((int)&scan_skip_count + param_2) = bVar14;
        uVar10 = (uint)bVar14 << 2;
        bVar8 = cVar2 == '\x01';
        if (0x20 < uVar10) {
          uVar10 = 0x20;
        }
        iVar13 = r_lld_read_clock();
        bVar14 = *(byte *)((int)&scan_skip_count + param_2);
        *(uint *)(iVar18 + 4) = iVar13 + uVar10 & 0xffffffe;
        r_ble_log_internal_x3
                  (0x4041013e,(uint)*(byte *)(iVar18 + 0x16) << 0x10 | (uint)bVar14 << 8 | param_2);
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar8) || (_lld_scan_env == 0)) ||
          (iVar18 = *(int *)(param_2 * 4 + _lld_scan_env), iVar18 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    if (((iVar18 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
       (*(char *)(iVar18 + 0x3d) != '\0')) {
      return;
    }
    if (((iVar18 != 0) && (_lld_scan_env != 0)) &&
       (iVar13 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar13 != 0)) {
      if (((iVar18 != 0) && (_lld_scan_env != 0)) &&
         (iVar13 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar13 != 0)) {
        r_lld_ext_scan_dynamic_pti_get(iVar18,1,&stack0xffffffd4);
        bVar14 = *(byte *)(iVar18 + 0x38);
        if (0xb < bVar14) {
          r_assert_err(0,"lld_scan.c",0x299b);
        }
        puVar9 = (uint *)((bVar14 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xfffff0ff;
        bVar14 = *(byte *)(iVar18 + 0x38);
        if (0xb < bVar14) {
          r_assert_err(0,"lld_scan.c",0x294a);
        }
        puVar9 = (uint *)((bVar14 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xbfffffff;
        bVar14 = *(byte *)(iVar18 + 0x38);
        if (0xb < bVar14) {
          r_assert_err(0,"lld_scan.c",0x29bb);
        }
        puVar9 = (uint *)((bVar14 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xfffffff0;
        bVar14 = *(byte *)(iVar18 + 0x38);
        if (0xb < bVar14) {
          r_assert_err(0,"lld_scan.c",0x295a);
        }
        puVar9 = (uint *)((bVar14 + 0x1800c4cb) * 4);
        *puVar9 = *puVar9 & 0xdfffffff;
        if (*(char *)(iVar18 + 0x39) == '\x01') {
          bVar14 = *(byte *)(iVar18 + 0x38);
          iVar18 = r_emi_get_mem_addr_by_offset(0x400);
          uVar3 = *(ushort *)((uint)bVar14 * 0x5a + 0x34 + iVar18);
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar18 = ((uVar3 - 0x1400) / 0xe & 0xff) * 0xe + 10;
          uVar3 = *(ushort *)(iVar13 + iVar18);
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar13 + iVar18) = uVar3 & 0xf0ff;
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar3 = *(ushort *)(iVar13 + iVar18);
          iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar13 + iVar18) = uVar3 & 0xefff;
        }
      }
      return;
    }
    return;
  }
  param_2 = param_2 & 0xff;
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_2 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0xa12);
    return;
  }
  iVar18 = *(int *)(param_2 * 4 + _lld_scan_env);
  bVar14 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar10 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar18 + 0x38));
    if (uVar10 == 0) {
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar18 = ((uint)bVar14 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar13 + iVar18) < 0) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar13 + iVar18);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar18 + iVar13) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    uVar21 = (uint)bVar1;
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar13 = uVar21 * 0x14;
    uVar4 = *(undefined2 *)(iVar13 + 0x12 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar13 + 2 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar20 = iVar13 + 4;
    uVar22 = *(ushort *)(iVar11 + iVar13 + 6) >> 8 & 0x3f;
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar15 = (uint)(*(ushort *)(iVar11 + iVar13 + 6) >> 0xe);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar5 = *(ushort *)(iVar11 + iVar20);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = *(undefined2 *)(iVar13 + 10 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar7 = *(undefined2 *)(iVar13 + 8 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar16 = CONCAT22(uVar6,uVar7);
    uVar19 = uVar16 * 0x271;
    uVar17 = (0x270 - (*(ushort *)(iVar13 + 0xc + iVar11) & 0x3ff) & 0xffff) + uVar19;
    if ((6 < (uVar5 & 0xf)) && (*(char *)(iVar18 + 0x3d) != '\0')) {
      if (*(char *)(iVar18 + 0x3e) == '\x01') {
        uVar22 = (uint)*(byte *)(iVar18 + 0x54);
      }
      else {
        uVar22 = *(uint *)(iVar18 + 0x2c) & 0x3f;
      }
    }
    iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
    r_ble_log_internal_x3
              (0x20a10004,
               ((uint)(uVar17 < uVar19) + (int)((ulonglong)uVar16 * 0x271 >> 0x20)) * -0x80000000 |
               uVar17 >> 1,CONCAT22(*(undefined2 *)(iVar11 + iVar20),uVar3),
               (uint)CONCAT11(bVar1,*(undefined1 *)(iVar18 + 0x38)) | (uVar15 << 4 | uVar15) << 0x18
               | uVar22 << 0x10);
    if (*(ushort *)(iVar18 + 0x36) < 0x673) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar19 = *(ushort *)(iVar11 + iVar20) & 0xf;
      if (uVar19 < 7) {
        bVar1 = *(byte *)(_lld_scan_env + 0x17);
        uVar15 = uVar10;
        if (bVar1 != 0) {
          r_lld_ext_scan_dynamic_pti_reset(iVar18);
          uVar15 = (uint)bVar1;
        }
_L555:
        uVar16 = 0x128U >> uVar19 & 1;
      }
      else {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar13 + 0x10 + iVar11);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar15 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar13 + iVar20) >> 8);
        uVar16 = uVar10;
        if (uVar19 < 9) goto _L555;
      }
      iVar13 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar13 + 0x18) == '\0') && (6 < uVar19)) {
        uVar16 = uVar10;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar15 != 0)) && (uVar16 == 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar18 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar19) || ((0x128U >> uVar19 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x29c);
        }
        if (uVar19 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar19,uVar21,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep_hack(param_2,uVar19,uVar21,&uStack_4c);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar3 = *(ushort *)(iVar13 + iVar20);
        uVar12 = r_emi_get_mem_addr_by_offset(uVar4);
        r_ble_log_internal_hex(0x20a1013c,uVar3 >> 8,uVar12);
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_2),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar18);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

