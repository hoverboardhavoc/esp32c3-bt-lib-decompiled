/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
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
  uint uVar12;
  undefined1 uVar13;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xd60);
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
      r_assert_param(0,"lld_con.c",0xc69);
      return;
    }
    iVar14 = *(int *)(&lld_con_env + param_2 * 4);
    *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) & 0xfffb;
    while (iVar18 = r_lld_rxdesc_check_hack(param_2,param_1), iVar18 != 0) {
      uVar12 = (uint)*(byte *)(_p_lld_env + 0xd8);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar19 = uVar12 * 0x14;
      uVar15 = *(ushort *)(iVar19 + 2 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar19 + 4 + iVar10);
      r_ble_log_internal_x2(0x20c30086,CONCAT22(uVar3,uVar15),uVar12 << 8 | param_2);
      if (((uVar15 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar14), (uVar15 & 8) == 0))
      {
        *(undefined4 *)(iVar14 + 0x58) = *(undefined4 *)(iVar14 + 0x50);
        if ((uVar15 & 0x66) == 0) {
          if ((uVar15 & 0x10) == 0) {
            iVar10 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = uVar3 >> 8;
            *(undefined2 *)(iVar14 + 0x98) = *(undefined2 *)(iVar10 + param_2 * 0x5a + 0x50);
            if ((uVar15 != 0) && ((uVar3 & 3) != 0)) {
              if ((4 < uVar15) && ((*(ushort *)(iVar14 + 0x84) & 0x20) != 0)) {
                uVar15 = uVar15 - 4;
              }
              iVar10 = r_lld_con_rx_llcp_check(param_2,iVar14,uVar15);
              if (iVar10 == 0) {
                iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar19 + 0x12 + iVar10) = 0;
              }
            }
          }
          else {
            r_ble_log_internal_x1(0x80c30087,uVar12 << 0x18 | param_2 << 0x10 | (uint)uVar15);
            *(undefined1 *)(iVar14 + 0x8f) = 2;
            *(ushort *)(iVar14 + 0x84) = *(ushort *)(iVar14 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar18 = 0;
      }
      r_lld_con_rx_channel_assess_hack(iVar14,iVar18);
      param_1 = r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc83);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar14 = *(int *)(&lld_con_env + param_2 * 4);
    if (*(int *)(iVar14 + 0x30) == 0) {
      iVar18 = *(int *)(iVar14 + 0x28);
      *(int *)(iVar14 + 0x30) = iVar18;
      if (iVar18 != 0) {
        *(ushort *)(iVar14 + 0x82) = *(ushort *)(iVar18 + 6) & 0x3ff;
      }
    }
    bVar8 = false;
    if ((((*(ushort *)(iVar14 + 0x84) & 0x10) != 0) && (*(int **)(iVar14 + 0x30) != (int *)0x0)) &&
       (bVar8 = true, *(short *)(iVar14 + 0x82) == 0)) {
      bVar8 = **(int **)(iVar14 + 0x30) != 0;
    }
    iVar18 = *(int *)(iVar14 + 0x24);
    if ((iVar18 != 0) || (bVar8)) {
      if (*(char *)(iVar14 + 0x92) == '\x02') {
        bVar2 = *(byte *)(iVar14 + 0x8e);
        bVar1 = *(byte *)(iVar14 + 0x91);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar18 = ((bVar1 + 1 & 1) + (uint)bVar2 * 9 & 0xff) * 0xe;
        if (-1 < *(short *)(iVar10 + iVar18)) {
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar18 = iVar18 + 2;
          uVar15 = *(ushort *)(iVar10 + iVar18);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar18 + iVar10) = uVar15 & 0xffef | 0x10;
        }
      }
      else {
        uVar13 = 0x23;
        if (iVar18 != 0) {
          puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar18 + 4),0x23);
          uVar13 = *puVar9;
        }
        r_lld_con_tx_prog_new_packet_hack(param_2,uVar13);
      }
    }
    r_ble_log_internal_x3
              (0x20e30088,*(undefined4 *)(iVar14 + 0x24),*(undefined4 *)(iVar14 + 0x30),
               (uint)*(ushort *)(iVar14 + 0x82) | param_2 << 0x10 |
               (uint)*(byte *)(iVar14 + 0x92) << 0x18);
    return;
  case 4:
    iVar14 = *(int *)(&lld_con_env + param_2 * 4);
    r_ble_log_internal_x1(0x4043008a,(uint)*(byte *)(iVar14 + 0x8f) << 8 | param_2);
    r_lld_con_frm_skip_isr(param_2);
    param_2 = (uint)*(byte *)(iVar14 + 0x8e);
    goto ble_con_evt_status_update;
  }
  iVar18 = *(int *)(&lld_con_env + param_2 * 4);
  if (iVar18 != 0) {
    bVar2 = *(byte *)(iVar18 + 0x8e);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    iVar19 = (uint)bVar2 * 0x5a;
    iVar10 = r_emi_get_mem_addr_by_offset(0x400,*(undefined2 *)(iVar19 + 0x16 + iVar10));
    uVar15 = *(ushort *)(iVar10 + iVar19 + 4);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar10 + iVar19 + 4);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar10 + iVar19 + 0xe);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(undefined2 *)(iVar10 + iVar19 + 0xc);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_38 = *(undefined2 *)(iVar19 + 0x22 + iVar10);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    uStack_36 = *(undefined2 *)(iVar19 + 0x24 + iVar10);
    r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = r_co_nb_good_le_channels(&uStack_38);
    if ((*(ushort *)(iVar18 + 0x84) & 0x200) == 0) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x400,uVar11);
      uVar6 = *(ushort *)(iVar10 + iVar19 + 0xe);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar7 = *(ushort *)(iVar10 + iVar19 + 0xc);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar12 = r_lld_cca_chan_sel_2
                         (*(undefined2 *)(iVar19 + 0x50 + iVar10),uVar6 ^ uVar7,&uStack_38,uVar11);
    }
    else {
      uVar12 = r_lld_cca_chan_sel_1
                         (*(undefined1 *)(iVar18 + 0x80),*(undefined1 *)(iVar18 + 0x8d),
                          *(undefined2 *)(iVar18 + 0x72),&uStack_38);
    }
    if ((*(ushort *)(iVar18 + 0x84) & 1) == 0) {
      uVar17 = *(uint *)(iVar18 + 4) * 0x271;
      uVar16 = *(int *)(iVar18 + 8) + uVar17;
      uVar16 = ((uint)(uVar16 < uVar17) + (int)((ulonglong)*(uint *)(iVar18 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar16 >> 1;
    }
    else if ((*(ushort *)(iVar18 + 0x84) & 0x100) == 0) {
      uVar17 = *(uint *)(iVar18 + 4) * 0x271;
      uVar16 = *(int *)(iVar18 + 8) + uVar17;
      uVar16 = ((uint)(uVar16 < uVar17) + (int)((ulonglong)*(uint *)(iVar18 + 4) * 0x271 >> 0x20)) *
               -0x80000000 | uVar16 >> 1;
    }
    else {
      uVar17 = *(uint *)(iVar18 + 0x54) * 0x271;
      uVar16 = (int)*(short *)(iVar18 + 0x6e) + uVar17;
      uVar16 = ((uint)(uVar16 < uVar17) +
               (int)((ulonglong)*(uint *)(iVar18 + 0x54) * 0x271 >> 0x20) +
               ((int)*(short *)(iVar18 + 0x6e) >> 0x1f)) * -0x80000000 | uVar16 >> 1;
    }
    r_ble_log_internal_x4
              (0x40430079,CONCAT22(uVar4,uVar5),uVar16,
               (uint)*(ushort *)(iVar18 + 0x7c) | iVar14 << 0x18 |
               (uint)*(byte *)(iVar18 + 0x8e) << 0x10,
               ((uVar15 & 0xc) << 2 | uVar3 & 3) << 8 | uVar12);
  }
  iVar18 = r_lld_con_terminate_max_evt_update
                     (param_2,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >>
                              8 & 1);
  if (iVar18 != 0) {
    return;
  }
  iVar18 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar18 + 0x19) == '\x02') {
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

