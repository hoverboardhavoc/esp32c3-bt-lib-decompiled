/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  undefined1 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined1 uVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xd61);
    return;
  }
  param_2 = param_2 & 0xff;
  switch(param_3) {
  case 0:
    iVar13 = 0;
    break;
  case 1:
    iVar13 = 1;
    break;
  case 2:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc6a);
      return;
    }
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    *(ushort *)(iVar13 + 0x84) = *(ushort *)(iVar13 + 0x84) & 0xfffb;
    while (iVar17 = r_lld_rxdesc_check_hack(param_2,param_1), iVar17 != 0) {
      uVar15 = (uint)*(byte *)(_p_lld_env + 0xd8);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar18 = uVar15 * 0x14;
      uVar14 = *(ushort *)(iVar18 + 2 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar18 + 4 + iVar10);
      r_ble_log_internal_x2(0x20c300e8,CONCAT22(uVar3,uVar14),uVar15 << 8 | param_2);
      if (((uVar14 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar13), (uVar14 & 8) == 0))
      {
        *(undefined4 *)(iVar13 + 0x58) = *(undefined4 *)(iVar13 + 0x50);
        if ((uVar14 & 0x66) == 0) {
          if ((uVar14 & 0x10) == 0) {
            iVar10 = r_emi_get_mem_addr_by_offset(0x400);
            uVar14 = uVar3 >> 8;
            *(undefined2 *)(iVar13 + 0x98) = *(undefined2 *)(iVar10 + param_2 * 0x5a + 0x50);
            if ((uVar14 != 0) && ((uVar3 & 3) != 0)) {
              if ((4 < uVar14) && ((*(ushort *)(iVar13 + 0x84) & 0x20) != 0)) {
                uVar14 = uVar14 - 4;
              }
              iVar10 = r_lld_con_rx_llcp_check(param_2,iVar13,uVar14);
              if (iVar10 == 0) {
                iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar18 + 0x12 + iVar10) = 0;
              }
            }
          }
          else {
            r_ble_log_internal_x1(0x80c300e9,uVar15 << 0x18 | param_2 << 0x10 | (uint)uVar14);
            *(undefined1 *)(iVar13 + 0x8f) = 2;
            *(ushort *)(iVar13 + 0x84) = *(ushort *)(iVar13 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar17 = 0;
      }
      r_lld_con_rx_channel_assess_hack(iVar13,iVar17);
      param_1 = r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc84);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    if (*(int *)(iVar13 + 0x30) == 0) {
      iVar17 = *(int *)(iVar13 + 0x28);
      *(int *)(iVar13 + 0x30) = iVar17;
      if (iVar17 != 0) {
        *(ushort *)(iVar13 + 0x82) = *(ushort *)(iVar17 + 6) & 0x3ff;
      }
    }
    bVar8 = false;
    if ((((*(ushort *)(iVar13 + 0x84) & 0x10) != 0) && (*(int **)(iVar13 + 0x30) != (int *)0x0)) &&
       (bVar8 = true, *(short *)(iVar13 + 0x82) == 0)) {
      bVar8 = **(int **)(iVar13 + 0x30) != 0;
    }
    iVar17 = *(int *)(iVar13 + 0x24);
    if ((iVar17 != 0) || (bVar8)) {
      if (*(char *)(iVar13 + 0x92) == '\x02') {
        bVar2 = *(byte *)(iVar13 + 0x8e);
        bVar1 = *(byte *)(iVar13 + 0x91);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar17 = ((bVar1 + 1 & 1) + (uint)bVar2 * 9 & 0xff) * 0xe;
        if (-1 < *(short *)(iVar10 + iVar17)) {
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar17 = iVar17 + 2;
          uVar14 = *(ushort *)(iVar10 + iVar17);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar17 + iVar10) = uVar14 & 0xffef | 0x10;
        }
      }
      else {
        uVar12 = 0x23;
        if (iVar17 != 0) {
          puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar17 + 4),0x23);
          uVar12 = *puVar9;
        }
        r_lld_con_tx_prog_new_packet_hack(param_2,uVar12);
      }
    }
    r_ble_log_internal_x3
              (0x20e300ea,*(undefined4 *)(iVar13 + 0x24),*(undefined4 *)(iVar13 + 0x30),
               (uint)*(ushort *)(iVar13 + 0x82) | param_2 << 0x10 |
               (uint)*(byte *)(iVar13 + 0x92) << 0x18);
    return;
  case 4:
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    r_ble_log_internal_x1(0x404300ec,(uint)*(byte *)(iVar13 + 0x8f) << 8 | param_2);
    r_lld_con_frm_skip_isr(param_2);
    param_2 = (uint)*(byte *)(iVar13 + 0x8e);
    goto ble_con_evt_status_update;
  }
  iVar17 = *(int *)(&lld_con_env + param_2 * 4);
  if (iVar17 != 0) {
    bVar2 = *(byte *)(iVar17 + 0x8e);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    iVar18 = (uint)bVar2 * 0x5a;
    iVar10 = r_emi_get_mem_addr_by_offset(0x400,*(undefined2 *)(iVar18 + 0x16 + iVar10));
    uVar14 = *(ushort *)(iVar10 + iVar18 + 4);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar10 + iVar18 + 4);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar10 + iVar18 + 0xe);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(undefined2 *)(iVar10 + iVar18 + 0xc);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_38 = *(undefined2 *)(iVar18 + 0x22 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_36 = *(undefined2 *)(iVar18 + 0x24 + iVar10);
    r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = r_co_nb_good_le_channels(&uStack_38);
    if ((*(ushort *)(iVar17 + 0x84) & 0x200) == 0) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x400,uVar11);
      uVar6 = *(ushort *)(iVar10 + iVar18 + 0xe);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(iVar10 + iVar18 + 0xc);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      iVar10 = r_lld_cca_chan_sel_2
                         (*(undefined2 *)(iVar18 + 0x50 + iVar10),uVar6 ^ uVar7,&uStack_38,uVar11);
    }
    else {
      iVar10 = r_lld_cca_chan_sel_1
                         (*(undefined1 *)(iVar17 + 0x80),*(undefined1 *)(iVar17 + 0x8d),
                          *(undefined2 *)(iVar17 + 0x72),&uStack_38);
    }
    if ((*(ushort *)(iVar17 + 0x84) & 1) == 0) {
      uVar16 = *(uint *)(iVar17 + 4) * 0x271;
      uVar15 = *(int *)(iVar17 + 8) + uVar16;
      iVar18 = (uint)(uVar15 < uVar16) + (int)((ulonglong)*(uint *)(iVar17 + 4) * 0x271 >> 0x20);
_L584:
      uVar15 = iVar18 << 0x1f | uVar15 >> 1;
    }
    else {
      if ((*(ushort *)(iVar17 + 0x84) & 0x100) != 0) {
        uVar16 = *(uint *)(iVar17 + 0x54) * 0x271;
        uVar15 = (int)*(short *)(iVar17 + 0x6e) + uVar16;
        iVar18 = (uint)(uVar15 < uVar16) +
                 (int)((ulonglong)*(uint *)(iVar17 + 0x54) * 0x271 >> 0x20) +
                 ((int)*(short *)(iVar17 + 0x6e) >> 0x1f);
        goto _L584;
      }
      uVar16 = *(uint *)(iVar17 + 4) * 0x271;
      uVar15 = *(int *)(iVar17 + 8) + uVar16;
      uVar15 = ((uint)(uVar15 < uVar16) + (int)((ulonglong)*(uint *)(iVar17 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar15 >> 1;
    }
    r_ble_log_internal_x4
              (0x40430001,CONCAT22(uVar4,uVar5),uVar15,*(undefined2 *)(iVar17 + 0x7c),
               iVar10 << 0x10 |
               ((uVar14 & 0xc) << 2 | uVar3 & 3) << 0x18 |
               (uint)*(byte *)(iVar17 + 0x8e) | iVar13 << 8);
  }
  iVar17 = r_lld_con_terminate_max_evt_update
                     (param_2,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >>
                              8 & 1);
  if (iVar17 != 0) {
    return;
  }
  iVar17 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar17 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_2,param_1,iVar13);
ble_con_evt_status_update:
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_2,0);
  return;
}

