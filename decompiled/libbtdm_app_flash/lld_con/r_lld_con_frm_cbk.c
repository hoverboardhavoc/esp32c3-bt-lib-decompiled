/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  byte bVar13;
  undefined4 uVar14;
  ushort uVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  ushort uVar20;
  byte bVar21;
  byte bVar22;
  uint uVar23;
  char cVar24;
  int iVar25;
  int *piStack_5c;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xcfd);
    return;
  }
  param_2 = param_2 & 0xff;
  switch(param_3) {
  case 0:
    uVar14 = 0;
    break;
  case 1:
    uVar14 = 1;
    break;
  case 2:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc07);
      return;
    }
    iVar6 = *(int *)(&lld_con_env + param_2 * 4);
    *(ushort *)(iVar6 + 0x84) = *(ushort *)(iVar6 + 0x84) & 0xfffb;
    while (iVar17 = r_lld_rxdesc_check_hack(param_2,param_1), iVar17 != 0) {
      bVar13 = *(byte *)(_p_lld_env + 0xd8);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar7 = (uint)bVar13 * 0x14;
      uVar15 = *(ushort *)(iVar9 + iVar7 + 2);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar9 + iVar7 + 4);
      if (((uVar15 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar6), (uVar15 & 8) == 0))
      {
        *(undefined4 *)(iVar6 + 0x58) = *(undefined4 *)(iVar6 + 0x50);
        if ((uVar15 & 0x66) == 0) {
          if ((uVar15 & 0x10) == 0) {
            iVar9 = r_emi_get_mem_addr_by_offset(0x400);
            uVar15 = uVar3 >> 8;
            *(undefined2 *)(iVar6 + 0x98) = *(undefined2 *)(iVar9 + param_2 * 0x5a + 0x50);
            if ((uVar15 != 0) && ((uVar3 & 3) != 0)) {
              if ((4 < uVar15) && ((*(ushort *)(iVar6 + 0x84) & 0x20) != 0)) {
                uVar15 = uVar15 - 4;
              }
              iVar9 = r_lld_con_rx_llcp_check(param_2,iVar6,uVar15);
              if (iVar9 == 0) {
                iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar7 + 0x12 + iVar9) = 0;
              }
            }
          }
          else {
            *(undefined1 *)(iVar6 + 0x8f) = 2;
            *(ushort *)(iVar6 + 0x84) = *(ushort *)(iVar6 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar17 = 0;
      }
      r_lld_con_rx_channel_assess(iVar6,iVar17);
      param_1 = r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc21);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar6 = *(int *)(&lld_con_env + param_2 * 4);
    if (*(int *)(iVar6 + 0x30) == 0) {
      iVar17 = *(int *)(iVar6 + 0x28);
      *(int *)(iVar6 + 0x30) = iVar17;
      if (iVar17 != 0) {
        *(ushort *)(iVar6 + 0x82) = *(ushort *)(iVar17 + 6) & 0x3ff;
      }
    }
    bVar4 = false;
    if ((((*(ushort *)(iVar6 + 0x84) & 0x10) != 0) && (*(int **)(iVar6 + 0x30) != (int *)0x0)) &&
       (bVar4 = true, *(short *)(iVar6 + 0x82) == 0)) {
      bVar4 = **(int **)(iVar6 + 0x30) != 0;
    }
    iVar17 = *(int *)(iVar6 + 0x24);
    if ((iVar17 == 0) && (!bVar4)) {
      return;
    }
    if (*(char *)(iVar6 + 0x92) == '\x02') {
      bVar13 = *(byte *)(iVar6 + 0x91);
      bVar21 = *(byte *)(iVar6 + 0x8e);
      iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar6 = ((bVar13 + 1 & 1) + (uint)bVar21 * 9 & 0xff) * 0xe;
      if (-1 < *(short *)(iVar17 + iVar6)) {
        iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar6 = iVar6 + 2;
        uVar15 = *(ushort *)(iVar17 + iVar6);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar17 + iVar6) = uVar15 & 0xffef | 0x10;
      }
      return;
    }
    bVar13 = 0x23;
    if (iVar17 != 0) {
      pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar17 + 4));
      bVar13 = *pbVar12;
    }
    iVar6 = *(int *)(&lld_con_env + param_2 * 4);
    iVar17 = *(int *)(iVar6 + 0x24);
    piVar5 = *(int **)(iVar6 + 0x30);
    piStack_5c = (int *)0x0;
    if ((((*(ushort *)(iVar6 + 0x84) & 0x10) != 0) && (piStack_5c = piVar5, piVar5 != (int *)0x0))
       && (piStack_5c = (int *)0x1, *(short *)(iVar6 + 0x82) == 0)) {
      piStack_5c = (int *)(uint)(*piVar5 != 0);
    }
    bVar21 = *(byte *)(iVar6 + 0x92);
    iVar7 = (param_2 + 0x18) * 2;
    do {
      if (1 < bVar21) {
        return;
      }
      if (iVar17 == 0) {
        if (piStack_5c == (int *)0x0) {
          return;
        }
_L407:
        if ((*(short *)(iVar6 + 0x82) == 0) && (piVar16 = (int *)*piVar5, piVar16 != (int *)0x0)) {
          uVar15 = *(ushort *)((int)piVar16 + 6);
          *(int **)(iVar6 + 0x30) = piVar16;
          *(ushort *)(iVar6 + 0x82) = uVar15 & 0x3ff;
          piVar5 = piVar16;
        }
        uVar15 = *(ushort *)((int)piVar5 + 6);
        uVar3 = *(ushort *)(iVar6 + 0x82);
        uVar23 = (uint)uVar3;
        uVar8 = (*(ushort *)(piVar5 + 1) - uVar23) + (uVar15 & 0x3ff) & 0xffff;
        uVar20 = 2;
        if (((int)(uint)uVar15 >> 0xc & 3U) == 1) {
          uVar20 = 1;
        }
        uVar18 = (uint)*(byte *)(iVar6 + 0x8c);
        if (uVar23 < *(byte *)(iVar6 + 0x8c)) {
          uVar18 = uVar23;
        }
        *(ushort *)((int)piVar5 + 6) = uVar15 & 0xcfff | 0x1000;
        *(ushort *)(iVar6 + 0x82) = uVar3 - (short)uVar18;
      }
      else {
        if ((((bVar13 == 2) && (piStack_5c != (int *)0x0)) && (bVar21 != 1)) &&
           (DAT_0001508e != '\0')) goto _L407;
        uVar18 = (uint)*(byte *)(iVar17 + 6);
        uVar8 = (uint)*(ushort *)(iVar17 + 4);
        uVar20 = 3;
        *(undefined4 *)(iVar6 + 0x24) = 0;
        iVar17 = 0;
      }
      uVar15 = *(ushort *)(iVar6 + 0x84);
      cVar24 = *(char *)(iVar6 + 0x8e) * '\t';
      cVar1 = *(char *)(iVar6 + 0x91);
      bVar22 = cVar24 + cVar1;
      piStack_5c = (int *)0x0;
      if ((((uVar15 & 0x10) != 0) && (piStack_5c = piVar5, piVar5 != (int *)0x0)) &&
         (piStack_5c = (int *)0x1, *(short *)(iVar6 + 0x82) == 0)) {
        piStack_5c = (int *)(uint)(*piVar5 != 0);
      }
      if ((uVar15 & 0x40) != 0) {
        uVar18 = uVar18 + 4 & 0xffff;
      }
      if ((int)((uint)uVar15 << 0x12) < 0) {
        piVar16 = (int *)0x0;
      }
      else {
        piVar16 = piStack_5c;
        if (piStack_5c == (int *)0x0) {
          piVar16 = (int *)(uVar15 & 1);
        }
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar19 = (uint)bVar22 * 0xe;
      *(ushort *)(iVar9 + iVar19 + 2) =
           (ushort)((uVar18 & 0xff) << 8) | uVar20 | (ushort)((int)piVar16 << 4);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(short *)(iVar9 + iVar19 + 4) = (short)uVar8;
      if (-1 < (int)((uint)*(ushort *)(iVar6 + 0x84) << 0x12)) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar25 = (uint)(byte)((cVar1 + 1U & 1) + cVar24) * 0xe;
        if (-1 < *(short *)(iVar9 + iVar25)) {
          iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar25 = iVar25 + 2;
          uVar15 = *(ushort *)(iVar9 + iVar25);
          iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar9 + iVar25) = uVar15 & 0xffef | 0x10;
        }
      }
      if (uVar20 == 3) {
        if (bVar13 == 2) {
          bVar2 = *(byte *)(iVar6 + 0x90);
          *(undefined1 *)(&lld_con_cntl_pkt_info + param_2) = 1;
          *(byte *)((int)&lld_con_cntl_pkt_info + param_2 * 4 + 1) = bVar22;
          if ((uint)bVar22 == (uint)bVar2 + param_2 * 9) {
            *(undefined1 *)((int)&lld_con_cntl_pkt_info + param_2 * 4 + 2) = 1;
          }
        }
        else if ((bVar13 < 2) || (bVar13 == 0x18)) {
          if (bVar13 == 0) {
            (&DAT_000149bd)[iVar7] = 1;
            iVar9 = 10;
          }
          else if (bVar13 == 1) {
            (&DAT_000149bd)[iVar7] = 2;
            iVar9 = 6;
          }
          else if (bVar13 == 0x18) {
            (&DAT_000149bd)[iVar7] = 3;
            iVar9 = 3;
          }
          else {
            r_assert_param(param_2,bVar13,"lld_con.c",0x4ec);
            iVar9 = 0;
          }
          (&DAT_000149bc)[iVar7] = bVar22;
          uVar23 = uVar8 + iVar9 & 0xffff;
          puVar10 = (ushort *)r_emi_get_mem_addr_by_offset(uVar23);
          uVar3 = *puVar10;
          uVar15 = *(ushort *)(iVar6 + 0x44);
          if (((uint)uVar15 == (uint)uVar3) &&
             (pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(uVar8), *pbVar12 == bVar13)) {
            uVar8 = (uint)*(ushort *)(iVar6 + 0x7c) + (uint)*(ushort *)(iVar6 + 0x7e) + 9 +
                    (uint)*(ushort *)(iVar6 + 0x72);
            iVar9 = uVar8 * 0x10000;
            uVar8 = uVar8 & 0xffff;
            if (((uVar8 + 1) - (uint)uVar15 & 0xffff) < 0x7fff) {
              puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar23);
              *puVar11 = (char)((uint)iVar9 >> 0x10);
              puVar11[1] = (char)(uVar8 >> 8);
              *(short *)(iVar6 + 0x44) = (short)((uint)iVar9 >> 0x10);
            }
          }
          else {
            if (0 < _g_bt_plf_log_level) {
              uVar15 = *(ushort *)(iVar6 + 0x7e);
              uVar20 = *(ushort *)(iVar6 + 0x7c);
              puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar8);
              ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar20 + (uint)uVar15,*puVar11,
                         (uint)uVar3,*(undefined1 *)(iVar6 + 0x46),*(undefined2 *)(iVar6 + 0x44));
            }
            *(undefined2 *)(&DAT_000149bc + iVar7) = 0;
          }
        }
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      bVar21 = bVar21 + 1;
      uVar15 = *(ushort *)(iVar9 + iVar19);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar9 + iVar19) = uVar15 & 0x7fff;
      *(byte *)(iVar6 + 0x91) = *(char *)(iVar6 + 0x91) + 1U & 1;
      r_lld_con_tx_prog_new_packet_coex(iVar6);
      *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + '\x01';
    } while( true );
  case 4:
    iVar6 = *(int *)(&lld_con_env + param_2 * 4);
    r_lld_con_frm_skip_isr();
    param_2 = (uint)*(byte *)(iVar6 + 0x8e);
    goto ble_con_evt_status_update;
  }
  iVar6 = r_lld_con_terminate_max_evt_update
                    ((int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >> 8 & 1);
  if (iVar6 != 0) {
    return;
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_2,param_1,uVar14);
ble_con_evt_status_update:
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_2,0);
  return;
}

