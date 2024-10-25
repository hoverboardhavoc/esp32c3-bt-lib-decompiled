/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  ushort uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if (1 < param_2) {
    r_assert_param(param_2,param_3,"lld_scan.c",0xa01);
  }
  if (param_3 == 1) {
    uVar12 = 1;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        param_2 = param_2 & 0xff;
        if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_2 * 4) == 0)) {
          r_assert_err(0,"lld_scan.c",0x9a6);
          return;
        }
        bVar1 = *(byte *)(_lld_scan_env + 0xd);
        iVar14 = *(int *)(param_2 * 4 + _lld_scan_env);
        do {
          uVar9 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar14 + 0x38));
          if (uVar9 == 0) {
            iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar14 = ((uint)bVar1 * 9 & 0xff) * 0xe;
            if (*(short *)(iVar10 + iVar14) < 0) {
              iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
              uVar2 = *(ushort *)(iVar10 + iVar14);
              iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar10 + iVar14) = uVar2 & 0x7fff;
            }
            return;
          }
          uVar15 = (uint)*(byte *)(_p_lld_env + 0xd8);
          r_emi_get_mem_addr_by_offset(0x1000);
          iVar10 = uVar15 * 0x14;
          if (*(ushort *)(iVar14 + 0x36) < 0x673) {
            iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar2 = *(ushort *)(iVar11 + iVar10 + 2);
            iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
            uVar3 = *(ushort *)(iVar11 + iVar10 + 4);
            uVar6 = uVar3 & 0xf;
            uVar13 = uVar9;
            if (uVar6 < 7) {
              if (*(char *)(_lld_scan_env + 0x17) != '\0') {
                r_lld_ext_scan_dynamic_pti_reset(iVar14);
              }
              uVar8 = uVar9;
              if ((uVar6 - 3 & 0xfd) != 0) goto _L553;
            }
            else {
              iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
              uVar4 = *(ushort *)(iVar10 + 0x10 + iVar11);
              iVar11 = r_emi_get_mem_addr_by_offset(0x1000);
              uVar8 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar11 + iVar10 + 4) >> 8);
              if (uVar6 < 9) {
_L553:
                uVar13 = (uint)(uVar6 == 8);
              }
            }
            iVar10 = r_sdk_config_get_opts_ext();
            if ((*(char *)(iVar10 + 0x18) == '\0') && (6 < uVar6)) {
              uVar13 = uVar9;
            }
            if ((((uVar2 & 0x602d) == 0) && (uVar8 != 0)) && (uVar13 == 0)) {
              uStack_44 = 0xff;
              uStack_4c = 0;
              uStack_48 = 0;
              *(undefined1 *)(iVar14 + 0x43) = 1;
              if (((uVar3 & 8) != 0) || ((uVar6 - 3 & 0xfd) == 0)) {
                r_assert_err(0,"lld_scan.c",0x25f);
              }
              if (uVar6 < 7) {
                r_lld_scan_process_pkt_rx_legacy_adv();
              }
              else {
                r_lld_scan_process_pkt_rx_ext_adv(param_2,uVar6,uVar15,&uStack_4c);
              }
              r_lld_scan_process_pkt_rx_adv_rep(param_2,uVar6,uVar15,&uStack_4c);
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
        r_assert_param(param_2,param_3,"lld_scan.c",0xa17);
        return;
      }
      param_2 = param_2 & 0xff;
      bVar5 = false;
      if ((_lld_scan_env != 0) && (iVar14 = *(int *)(_lld_scan_env + param_2 * 4), iVar14 != 0)) {
        bVar5 = *(char *)(iVar14 + 0x3d) == '\x01';
      }
      r_lld_scan_frm_skip_isr(param_2);
      if ((((!bVar5) || (_lld_scan_env == 0)) ||
          (iVar14 = *(int *)(param_2 * 4 + _lld_scan_env), iVar14 == 0)) ||
         (*(char *)(_lld_scan_env + 0x17) == '\0')) {
        return;
      }
      goto code_r0x000107a8;
    }
    uVar12 = 0;
  }
  r_lld_scan_frm_eof_isr(param_1,uVar12);
  if (((_lld_scan_env == 0) ||
      (iVar14 = *(int *)((param_2 & 0xff) * 4 + _lld_scan_env), iVar14 == 0)) ||
     (*(char *)(_lld_scan_env + 0x17) == '\0')) {
    return;
  }
code_r0x000107a8:
  if (((iVar14 != 0) && (*(char *)(_lld_scan_env + 0x17) != '\0')) &&
     (*(char *)(iVar14 + 0x3d) == '\0')) {
    if ((iVar14 != 0) && (_lld_scan_env != 0)) {
      iVar10 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get();
      if (iVar10 != 0) {
        if (((iVar14 != 0) && (_lld_scan_env != 0)) &&
           (iVar10 = r_bt_rf_coex_ext_scan_dynamic_pti_en_get(), iVar10 != 0)) {
          r_lld_ext_scan_dynamic_pti_get(iVar14,1,&stack0xffffffd4);
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x299b);
          }
          puVar7 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar7 = *puVar7 & 0xfffff0ff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x294a);
          }
          puVar7 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar7 = *puVar7 & 0xbfffffff;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x29bb);
          }
          puVar7 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar7 = *puVar7 & 0xfffffff0;
          bVar1 = *(byte *)(iVar14 + 0x38);
          if (0xb < bVar1) {
            r_assert_err(0,"lld_scan.c",0x295a);
          }
          puVar7 = (uint *)((bVar1 + 0x1800c4cb) * 4);
          *puVar7 = *puVar7 & 0xdfffffff;
          if (*(char *)(iVar14 + 0x39) == '\x01') {
            bVar1 = *(byte *)(iVar14 + 0x38);
            iVar14 = r_emi_get_mem_addr_by_offset(0x400);
            uVar2 = *(ushort *)((uint)bVar1 * 0x5a + 0x34 + iVar14);
            iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar14 = ((uVar2 - 0x1400) / 0xe & 0xff) * 0xe + 10;
            uVar2 = *(ushort *)(iVar10 + iVar14);
            iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar10 + iVar14) = uVar2 & 0xf0ff;
            iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
            uVar2 = *(ushort *)(iVar10 + iVar14);
            iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
            *(ushort *)(iVar10 + iVar14) = uVar2 & 0xefff;
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

