/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_rx_isr(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_1 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0x9ff);
    return;
  }
  iVar16 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar8 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar16 + 0x38));
    if (uVar8 == 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar16 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar9 + iVar16) < 0) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar9 + iVar16);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar16 + iVar9) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    bVar2 = *(byte *)(_p_lld_env + 0xd8);
    uVar18 = (uint)bVar2;
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar9 = uVar18 * 0x14;
    uVar4 = *(undefined2 *)(iVar9 + 0x12 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar3 = *(ushort *)(iVar9 + 2 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar17 = iVar9 + 4;
    uVar19 = *(ushort *)(iVar10 + iVar9 + 6) >> 8 & 0x3f;
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar13 = (uint)(*(ushort *)(iVar10 + iVar9 + 6) >> 0xe);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar5 = *(ushort *)(iVar10 + iVar17);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = *(undefined2 *)(iVar9 + 10 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar7 = *(undefined2 *)(iVar9 + 8 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar14 = CONCAT22(uVar6,uVar7);
    uVar12 = uVar14 * 0x271;
    uVar15 = (0x270 - (*(ushort *)(iVar9 + 0xc + iVar10) & 0x3ff) & 0xffff) + uVar12;
    if ((6 < (uVar5 & 0xf)) && (*(char *)(iVar16 + 0x3d) != '\0')) {
      if (*(char *)(iVar16 + 0x3e) == '\x01') {
        uVar19 = (uint)*(byte *)(iVar16 + 0x54);
      }
      else {
        uVar19 = *(uint *)(iVar16 + 0x2c) & 0x3f;
      }
    }
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    r_ble_log_internal_x3
              (0x20a100b2,
               ((uint)(uVar15 < uVar12) + (int)((ulonglong)uVar14 * 0x271 >> 0x20)) * -0x80000000 |
               uVar15 >> 1,CONCAT22(*(undefined2 *)(iVar10 + iVar17),uVar3),
               (uint)CONCAT11(bVar2,*(undefined1 *)(iVar16 + 0x38)) | (uVar13 << 4 | uVar13) << 0x18
               | uVar19 << 0x10);
    if (*(ushort *)(iVar16 + 0x36) < 0x673) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar12 = *(ushort *)(iVar10 + iVar17) & 0xf;
      if (uVar12 < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        uVar13 = uVar8;
        if (bVar2 != 0) {
          r_lld_ext_scan_dynamic_pti_reset(iVar16);
          uVar13 = (uint)bVar2;
        }
_L556:
        uVar14 = 0x128U >> uVar12 & 1;
      }
      else {
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar9 + 0x10 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar13 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar9 + iVar17) >> 8);
        uVar14 = uVar8;
        if (uVar12 < 9) goto _L556;
      }
      iVar9 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar9 + 0x18) == '\0') && (6 < uVar12)) {
        uVar14 = uVar8;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar13 != 0)) && (uVar14 == 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar16 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar12) || ((0x128U >> uVar12 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x295);
        }
        if (uVar12 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_1,uVar12,uVar18,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep_hack(param_1,uVar12,uVar18,&uStack_4c);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar3 = *(ushort *)(iVar9 + iVar17);
        uVar11 = r_emi_get_mem_addr_by_offset(uVar4);
        r_ble_log_internal_hex(0x20a100b3,uVar3 >> 8,uVar11);
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_1),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar16);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

