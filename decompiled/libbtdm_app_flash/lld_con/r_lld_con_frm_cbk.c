/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  bool bVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined1 uVar13;
  int extraout_a1;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  ushort *puVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xe8c);
    return;
  }
  param_2 = param_2 & 0xff;
  switch(param_3) {
  case 0:
    iVar14 = 0;
    break;
  case 1:
    iVar14 = 1;
    break;
  case 2:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xd93);
      return;
    }
    iVar23 = r_rwip_time_get(param_1);
    iVar11 = param_2 * 4;
    iVar14 = *(int *)(&lld_con_env + iVar11);
    *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) & 0xfffb;
    puVar21 = (ushort *)(lld_con_fake_rx + iVar11);
    while (iVar24 = r_lld_rxdesc_check_hack(param_2), iVar24 != 0) {
      uVar20 = (uint)*(byte *)(_p_lld_env + 0xd8);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar22 = uVar20 * 0x14;
      uVar15 = *(ushort *)(iVar22 + 2 + iVar9);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar22 + 4 + iVar9);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar17 = (uint)(*(ushort *)(iVar22 + 6 + iVar9) >> 0xe);
      if ((uVar17 - 2 & 0xff) < 2) {
        if (uVar3 >> 8 == 0 && (uVar15 & 0x2f) == 0) {
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar6 = *(ushort *)(iVar22 + 10 + iVar9);
          if ((uVar6 & 0xf000) != 0) {
            r_assert_err(0,"lld_con.c",1000);
          }
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          iVar18 = CONCAT22(uVar6,*(undefined2 *)(iVar22 + 8 + iVar9));
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar16 = iVar23 - iVar18 & 0xfffffff;
          if (uVar16 < 0x8000001) {
            uVar19 = 0x271;
          }
          else {
            uVar19 = iVar18 - iVar23 & 0xfffffff;
            uVar16 = 0xfffffd8f;
          }
          if (uVar17 == 2) {
            iVar18 = 0x2ff;
          }
          else {
            iVar18 = 0xfb;
          }
          if (((int)((extraout_a1 - (0x270 - (*(ushort *)(iVar22 + 0xc + iVar9) & 0x3ff))) +
                     uVar16 * uVar19 + (uint)_DAT_0001608e * 2) <= iVar18) ||
             ((((lld_con_fake_rx[iVar11 + 2] & 0x26) == 0 && (((*puVar21 ^ uVar3) & 0xff) == 0)) &&
              (*puVar21 >> 8 != 0)))) {
            *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) | 0x8000;
            lld_con_fake_rx[iVar11 + 2] = (char)uVar15;
            *puVar21 = uVar3;
          }
        }
        if (-1 < (short)*(ushort *)(iVar14 + 0x84)) {
          *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) & 0xf7ff;
        }
        if (((uVar15 & 1) == 0) && (-1 < *(short *)(iVar14 + 0x84))) {
          lld_con_fake_rx[iVar11 + 2] = (char)uVar15;
          *puVar21 = uVar3;
          r_ble_log_internal_x2(0x20c3010c,CONCAT22(uVar3,uVar3),uVar17 << 8 | param_2);
        }
      }
      r_ble_log_internal_x2(0x20c3010d,CONCAT22(uVar3,uVar15),uVar20 << 8 | param_2);
      if (((uVar15 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar14), (uVar15 & 8) == 0))
      {
        *(undefined4 *)(iVar14 + 0x58) = *(undefined4 *)(iVar14 + 0x50);
        if ((uVar15 & 0x66) == 0) {
          if ((uVar15 & 0x10) == 0) {
            *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) | 0x4000;
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = uVar3 >> 8;
            *(undefined2 *)(iVar14 + 0x98) = *(undefined2 *)(iVar9 + param_2 * 0x5a + 0x50);
            if ((uVar15 != 0) && ((uVar3 & 3) != 0)) {
              if ((4 < uVar15) && ((*(ushort *)(iVar14 + 0x84) & 0x20) != 0)) {
                uVar15 = uVar15 - 4;
              }
              iVar9 = r_lld_con_rx_llcp_check(param_2,iVar14,uVar15);
              if (iVar9 == 0) {
                iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar22 + 0x12 + iVar9) = 0;
              }
            }
          }
          else {
            r_ble_log_internal_x1(0x80c3010e,uVar20 << 0x18 | param_2 << 0x10 | (uint)uVar15);
            *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) | 0x80;
            *(undefined1 *)(iVar14 + 0x8f) = 2;
          }
        }
      }
      else {
        iVar24 = 0;
      }
      r_lld_con_rx_channel_assess_hack(iVar14,iVar24);
      r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xdad);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar14 = *(int *)(&lld_con_env + param_2 * 4);
    if (*(int *)(iVar14 + 0x30) == 0) {
      iVar23 = *(int *)(iVar14 + 0x28);
      *(int *)(iVar14 + 0x30) = iVar23;
      if (iVar23 != 0) {
        *(ushort *)(iVar14 + 0x82) = *(ushort *)(iVar23 + 6) & 0x3ff;
      }
    }
    bVar8 = false;
    if ((((*(ushort *)(iVar14 + 0x84) & 0x10) != 0) && (*(int **)(iVar14 + 0x30) != (int *)0x0)) &&
       (bVar8 = true, *(short *)(iVar14 + 0x82) == 0)) {
      bVar8 = **(int **)(iVar14 + 0x30) != 0;
    }
    iVar23 = *(int *)(iVar14 + 0x24);
    if ((iVar23 != 0) || (bVar8)) {
      if (*(char *)(iVar14 + 0x92) == '\x02') {
        bVar2 = *(byte *)(iVar14 + 0x8e);
        bVar1 = *(byte *)(iVar14 + 0x91);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar23 = ((bVar1 + 1 & 1) + (uint)bVar2 * 9 & 0xff) * 0xe;
        if (-1 < *(short *)(iVar11 + iVar23)) {
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar23 = iVar23 + 2;
          uVar15 = *(ushort *)(iVar11 + iVar23);
          iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar23 + iVar11) = uVar15 & 0xffef | 0x10;
        }
      }
      else {
        uVar13 = 0x23;
        if (iVar23 != 0) {
          puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar23 + 4),0x23);
          uVar13 = *puVar10;
        }
        r_lld_con_tx_prog_new_packet_hack(param_2,uVar13);
      }
    }
    r_ble_log_internal_x3
              (0x20e3010f,*(undefined4 *)(iVar14 + 0x24),*(undefined4 *)(iVar14 + 0x30),
               (uint)*(ushort *)(iVar14 + 0x82) | param_2 << 0x10 |
               (uint)*(byte *)(iVar14 + 0x92) << 0x18);
    return;
  case 4:
    bVar2 = *(byte *)(*(int *)(&lld_con_env + param_2 * 4) + 0x8e);
    r_ble_log_internal_x1
              (0x40430113,
               (uint)*(byte *)(*(int *)(&lld_con_env + param_2 * 4) + 0x8f) << 8 | param_2);
    r_lld_con_frm_skip_isr(param_2);
    param_2 = (uint)bVar2;
    goto ble_con_evt_status_update;
  }
  iVar23 = *(int *)(&lld_con_env + param_2 * 4);
  if (iVar23 != 0) {
    bVar2 = *(byte *)(iVar23 + 0x8e);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    iVar24 = (uint)bVar2 * 0x5a;
    iVar11 = r_emi_get_mem_addr_by_offset(0x400,*(undefined2 *)(iVar24 + 0x16 + iVar11));
    uVar15 = *(ushort *)(iVar11 + iVar24 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar11 + iVar24 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar11 + iVar24 + 0xe);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(undefined2 *)(iVar11 + iVar24 + 0xc);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_38 = *(undefined2 *)(iVar24 + 0x22 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_36 = *(undefined2 *)(iVar24 + 0x24 + iVar11);
    r_emi_get_mem_addr_by_offset(0x400);
    uVar12 = r_co_nb_good_le_channels(&uStack_38);
    if ((*(ushort *)(iVar23 + 0x84) & 0x200) == 0) {
      iVar11 = r_emi_get_mem_addr_by_offset(0x400,uVar12);
      uVar6 = *(ushort *)(iVar11 + iVar24 + 0xe);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(iVar11 + iVar24 + 0xc);
      iVar11 = r_emi_get_mem_addr_by_offset(0x400);
      iVar11 = r_lld_cca_chan_sel_2
                         (*(undefined2 *)(iVar24 + 0x50 + iVar11),uVar6 ^ uVar7,&uStack_38,uVar12);
    }
    else {
      iVar11 = r_lld_cca_chan_sel_1
                         (*(undefined1 *)(iVar23 + 0x80),*(undefined1 *)(iVar23 + 0x8d),
                          *(undefined2 *)(iVar23 + 0x72),&uStack_38);
    }
    if ((*(ushort *)(iVar23 + 0x84) & 1) == 0) {
      uVar20 = *(uint *)(iVar23 + 4) * 0x271;
      uVar17 = *(int *)(iVar23 + 8) + uVar20;
      iVar24 = (uint)(uVar17 < uVar20) + (int)((ulonglong)*(uint *)(iVar23 + 4) * 0x271 >> 0x20);
_L635:
      uVar17 = iVar24 << 0x1f | uVar17 >> 1;
    }
    else {
      if ((*(ushort *)(iVar23 + 0x84) & 0x100) != 0) {
        uVar20 = *(uint *)(iVar23 + 0x54) * 0x271;
        uVar17 = (int)*(short *)(iVar23 + 0x6e) + uVar20;
        iVar24 = (uint)(uVar17 < uVar20) +
                 (int)((ulonglong)*(uint *)(iVar23 + 0x54) * 0x271 >> 0x20) +
                 ((int)*(short *)(iVar23 + 0x6e) >> 0x1f);
        goto _L635;
      }
      uVar20 = *(uint *)(iVar23 + 4) * 0x271;
      uVar17 = *(int *)(iVar23 + 8) + uVar20;
      uVar17 = ((uint)(uVar17 < uVar20) + (int)((ulonglong)*(uint *)(iVar23 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar17 >> 1;
    }
    r_ble_log_internal_x4
              (0x40430001,CONCAT22(uVar4,uVar5),uVar17,*(undefined2 *)(iVar23 + 0x7c),
               iVar11 << 0x10 |
               ((uVar15 & 0xc) << 2 | uVar3 & 3) << 0x18 |
               (uint)*(byte *)(iVar23 + 0x8e) | iVar14 << 8);
  }
  iVar23 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x1(0x404300fc,param_2 << 0x10 | *(ushort *)(param_2 * 0x5a + iVar23) & 0x1f);
  iVar23 = r_lld_con_terminate_max_evt_update
                     (param_2,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >>
                              8 & 1);
  if (iVar23 != 0) {
    return;
  }
  iVar23 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar23 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_2,param_1,iVar14);
ble_con_evt_status_update:
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_2,0);
  return;
}

