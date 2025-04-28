/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000106d6) */
/* WARNING: Removing unreachable block (ram,0x000105f4) */
/* WARNING: Removing unreachable block (ram,0x00010534) */
/* WARNING: Removing unreachable block (ram,0x00010594) */
/* WARNING: Removing unreachable block (ram,0x00010654) */
/* WARNING: Removing unreachable block (ram,0x0001073e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  bool bVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if (1 < param_2) {
    r_assert_param("lld_scan.c",0xa1c);
  }
  if (param_3 != 2) {
    if (param_3 < 3) {
      param_2 = param_2 & 0xff;
      iVar12 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar12 + 0x28) & 8) != 0) &&
         (iVar12 = r_sdk_config_get_opts_ext(), *(byte *)(iVar12 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40410007,(uint)(param_3 != 0) << 8 | param_2);
      }
      r_lld_scan_frm_eof_isr(param_2,param_1,(uint)(param_3 != 0));
      if (((_lld_scan_env == 0) || (iVar12 = *(int *)(param_2 * 4 + _lld_scan_env), iVar12 == 0)) ||
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
      bVar6 = false;
      if ((_lld_scan_env != 0) && (iVar12 = *(int *)(_lld_scan_env + param_2 * 4), iVar12 != 0)) {
        bVar6 = *(char *)(iVar12 + 0x3d) == '\x01';
      }
      iVar12 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar12 + 0x28) & 8) != 0) &&
         (iVar12 = r_sdk_config_get_opts_ext(), *(byte *)(iVar12 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40410008,param_2);
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar6) || (_lld_scan_env == 0)) ||
          (iVar12 = *(int *)(param_2 * 4 + _lld_scan_env), iVar12 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
    }
    if (((iVar12 == 0) || (*(char *)(_lld_scan_env + 0x17) == '\0')) ||
       (*(char *)(iVar12 + 0x3d) != '\0')) {
      return;
    }
    if (((iVar12 != 0) && (_lld_scan_env != 0)) &&
       (iVar10 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar10 != 0)) {
      if (((iVar12 != 0) && (_lld_scan_env != 0)) &&
         (iVar10 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar10 != 0)) {
        r_lld_ext_scan_dynamic_pti_get(iVar12,1,&stack0xffffffd4);
        bVar1 = *(byte *)(iVar12 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x299b);
        }
        puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar8 = *puVar8 & 0xfffff0ff;
        bVar1 = *(byte *)(iVar12 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x294a);
        }
        puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar8 = *puVar8 & 0xbfffffff;
        bVar1 = *(byte *)(iVar12 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x29bb);
        }
        puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar8 = *puVar8 & 0xfffffff0;
        bVar1 = *(byte *)(iVar12 + 0x38);
        if (0xb < bVar1) {
          r_assert_err(0,"lld_scan.c",0x295a);
        }
        puVar8 = (uint *)((bVar1 + 0x1800c4cb) * 4);
        *puVar8 = *puVar8 & 0xdfffffff;
        if (*(char *)(iVar12 + 0x39) == '\x01') {
          bVar1 = *(byte *)(iVar12 + 0x38);
          iVar12 = r_emi_get_mem_addr_by_offset(0x400);
          uVar3 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar12);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar12 = ((uVar3 - 0x1400) / 0xe & 0xff) * 0xe + 10;
          uVar3 = *(ushort *)(iVar10 + iVar12);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar10 + iVar12) = uVar3 & 0xf0ff;
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar3 = *(ushort *)(iVar10 + iVar12);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar10 + iVar12) = uVar3 & 0xefff;
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
  iVar12 = *(int *)(param_2 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar9 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar12 + 0x38));
    if (uVar9 == 0) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar12 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar10 + iVar12) < 0) {
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar10 + iVar12);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar12 + iVar10) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    uVar16 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar14 = uVar16 * 0x14;
    uVar4 = *(undefined2 *)(iVar14 + 0x12 + iVar10);
    if (*(ushort *)(iVar12 + 0x36) < 0x673) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar14 + 2 + iVar10);
      iVar17 = iVar14 + 4;
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar7 = *(ushort *)(iVar10 + iVar17) & 0xf;
      if (uVar7 < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        uVar15 = uVar9;
        if (bVar2 != 0) {
          r_lld_ext_scan_dynamic_pti_reset(iVar12);
          uVar15 = (uint)bVar2;
        }
_L559:
        uVar13 = 0x128U >> uVar7 & 1;
      }
      else {
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar14 + 0x10 + iVar10);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar15 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar10 + iVar17) >> 8);
        uVar13 = uVar9;
        if (uVar7 < 9) goto _L559;
      }
      iVar10 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar10 + 0x18) == '\0') && (6 < uVar7)) {
        uVar13 = uVar9;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar15 != 0)) && (uVar13 == 0)) {
        iVar10 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar10 + 0x28) & 8) != 0) &&
           (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40a1000a,
                     uVar7 << 0x10 | uVar16 << 8 | param_2 | (uint)*(byte *)(iVar12 + 0x3d) << 0x18)
          ;
        }
        uStack_44 = 0xff;
        *(undefined1 *)(iVar12 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar7) || ((0x128U >> uVar7 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x272);
        }
        if (uVar7 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar7,uVar16,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_2,uVar7,uVar16,&uStack_4c);
        iVar10 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar10 + 0x28) & 8) != 0) &&
           (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 2)) {
          iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar3 = *(ushort *)(iVar10 + iVar17);
          uVar11 = r_emi_get_mem_addr_by_offset(uVar4);
          r_ble_log_internal_hex(0x20a1000c,uVar3 >> 8,uVar11);
        }
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_2),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar12);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

