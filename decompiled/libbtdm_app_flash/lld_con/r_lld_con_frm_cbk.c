/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  ushort uVar16;
  uint uVar17;
  int *piVar18;
  undefined1 uVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  byte bVar24;
  uint uVar25;
  byte bVar26;
  int iVar27;
  ushort uVar28;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xd23);
    return;
  }
  param_2 = param_2 & 0xff;
  switch(param_3) {
  case 0:
    iVar15 = 0;
    break;
  case 1:
    iVar15 = 1;
    break;
  case 2:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc2c);
      return;
    }
    iVar15 = *(int *)(&lld_con_env + param_2 * 4);
    iVar13 = r_sdk_config_get_opts_ext(param_1);
    if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
       (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x40c3001b,param_2);
    }
    *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) & 0xfffb;
    while (iVar13 = r_lld_rxdesc_check_hack(param_2), iVar13 != 0) {
      bVar26 = *(byte *)(_p_lld_env + 0xd8);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar22 = (uint)bVar26 * 0x14;
      uVar16 = *(ushort *)(iVar22 + 2 + iVar7);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar28 = *(ushort *)(iVar22 + 4 + iVar7);
      if (((uVar16 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar15), (uVar16 & 8) == 0))
      {
        *(undefined4 *)(iVar15 + 0x58) = *(undefined4 *)(iVar15 + 0x50);
        if ((uVar16 & 0x66) == 0) {
          if ((uVar16 & 0x10) == 0) {
            iVar7 = r_emi_get_mem_addr_by_offset(0x400);
            uVar16 = uVar28 >> 8;
            *(undefined2 *)(iVar15 + 0x98) = *(undefined2 *)(param_2 * 0x5a + 0x50 + iVar7);
            if ((uVar16 != 0) && ((uVar28 & 3) != 0)) {
              if ((4 < uVar16) && ((*(ushort *)(iVar15 + 0x84) & 0x20) != 0)) {
                uVar16 = uVar16 - 4;
              }
              iVar7 = r_lld_con_rx_llcp_check(param_2,iVar15,uVar16);
              if (iVar7 == 0) {
                iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar22 + 0x12 + iVar7) = 0;
              }
            }
          }
          else {
            iVar7 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
               (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
              r_ble_log_internal_x1(0x40c30023,(uint)bVar26 << 8 | param_2 | (uint)uVar16 << 0x10);
            }
            *(ushort *)(iVar15 + 0x84) = *(ushort *)(iVar15 + 0x84) | 0x80;
            *(undefined1 *)(iVar15 + 0x8f) = 2;
          }
        }
      }
      else {
        iVar13 = 0;
      }
      r_lld_con_rx_channel_assess(iVar15,iVar13);
      r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc46);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar15 = *(int *)(&lld_con_env + param_2 * 4);
    piVar18 = *(int **)(iVar15 + 0x30);
    if (piVar18 == (int *)0x0) {
      piVar18 = *(int **)(iVar15 + 0x28);
      *(int **)(iVar15 + 0x30) = piVar18;
      if (piVar18 != (int *)0x0) {
        *(ushort *)(iVar15 + 0x82) = *(ushort *)((int)piVar18 + 6) & 0x3ff;
      }
    }
    bVar4 = false;
    if ((((*(ushort *)(iVar15 + 0x84) & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
       (bVar4 = true, *(short *)(iVar15 + 0x82) == 0)) {
      bVar4 = *piVar18 != 0;
    }
    iVar13 = *(int *)(iVar15 + 0x24);
    if ((iVar13 != 0) || (bVar4)) {
      if (*(char *)(iVar15 + 0x92) != '\x02') {
        uVar14 = 0x23;
        if (iVar13 != 0) {
          pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar13 + 4));
          uVar14 = (uint)*pbVar12;
        }
        iVar15 = param_2 * 4;
        iVar13 = *(int *)(&lld_con_env + iVar15);
        iVar7 = *(int *)(iVar13 + 0x24);
        piVar18 = *(int **)(iVar13 + 0x30);
        uVar23 = 0;
        if ((((*(ushort *)(iVar13 + 0x84) & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
           (uVar23 = 1, *(short *)(iVar13 + 0x82) == 0)) {
          uVar23 = (uint)(*piVar18 != 0);
        }
        bVar26 = *(byte *)(iVar13 + 0x92);
        iVar22 = (param_2 + 0x18) * 2;
        do {
          if (1 < bVar26) {
            return;
          }
          if (iVar7 == 0) {
            if (uVar23 == 0) {
              return;
            }
_L436:
            uVar23 = (uint)*(ushort *)(iVar13 + 0x82);
            if ((uVar23 == 0) && (piVar21 = (int *)*piVar18, piVar21 != (int *)0x0)) {
              uVar16 = *(ushort *)((int)piVar21 + 6);
              *(int **)(iVar13 + 0x30) = piVar21;
              uVar23 = uVar16 & 0x3ff;
              piVar18 = piVar21;
            }
            uVar16 = *(ushort *)((int)piVar18 + 6);
            uVar6 = (*(ushort *)(piVar18 + 1) - uVar23) + (uVar16 & 0x3ff) & 0xffff;
            uVar28 = ((uVar16 & 0x3000) != 0x1000) + 1;
            uVar20 = (uint)*(byte *)(iVar13 + 0x8c);
            if (uVar23 < *(byte *)(iVar13 + 0x8c)) {
              uVar20 = uVar23;
            }
            *(ushort *)((int)piVar18 + 6) = uVar16 & 0xcfff | 0x1000;
            *(short *)(iVar13 + 0x82) = (short)uVar23 - (short)uVar20;
          }
          else {
            if ((((uVar14 == 2) && (uVar23 != 0)) && (bVar26 != 1)) && (sdk_cfg_priv_opts != '\0'))
            goto _L436;
            uVar20 = (uint)*(byte *)(iVar7 + 6);
            uVar6 = (uint)*(ushort *)(iVar7 + 4);
            uVar28 = 3;
            *(undefined4 *)(iVar13 + 0x24) = 0;
            iVar7 = 0;
          }
          cVar1 = *(char *)(iVar13 + 0x91);
          cVar5 = *(char *)(iVar13 + 0x8e) * '\t';
          uVar16 = *(ushort *)(iVar13 + 0x84);
          uVar23 = 0;
          bVar24 = cVar5 + cVar1;
          uVar25 = (uint)bVar24;
          if ((((uVar16 & 0x10) != 0) && (piVar18 != (int *)0x0)) &&
             (uVar23 = 1, *(short *)(iVar13 + 0x82) == 0)) {
            uVar23 = (uint)(*piVar18 != 0);
          }
          if ((uVar16 & 0x40) != 0) {
            uVar20 = uVar20 + 4 & 0xffff;
          }
          if ((int)((uint)uVar16 << 0x12) < 0) {
            uVar17 = 0;
          }
          else {
            uVar17 = uVar23;
            if (uVar23 == 0) {
              uVar17 = uVar16 & 1;
            }
          }
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar27 = uVar25 * 0xe;
          *(ushort *)(iVar8 + iVar27 + 2) = (ushort)(uVar20 << 8) | uVar28 | (ushort)(uVar17 << 4);
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          *(short *)(iVar27 + 4 + iVar8) = (short)uVar6;
          if (-1 < (int)((uint)*(ushort *)(iVar13 + 0x84) << 0x12)) {
            iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar8 = (uint)(byte)(cVar5 + (cVar1 + 1U & 1)) * 0xe;
            if (-1 < *(short *)(iVar9 + iVar8)) {
              iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
              iVar8 = iVar8 + 2;
              uVar16 = *(ushort *)(iVar9 + iVar8);
              iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar9 + iVar8) = uVar16 | 0x10;
            }
          }
          if (uVar28 == 3) {
            uVar19 = 2;
            if (uVar14 == 2) {
              bVar2 = *(byte *)(iVar13 + 0x90);
              *(undefined1 *)(&lld_con_cntl_pkt_info + param_2) = 1;
              *(byte *)((int)&lld_con_cntl_pkt_info + iVar15 + 1) = bVar24;
              if (uVar25 == (uint)bVar2 + param_2 * 9) {
                *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar15 + 2) = 1;
              }
            }
            else {
              if (uVar14 < 3) {
                iVar8 = 6;
                if (uVar14 == 0) {
                  uVar19 = 1;
                  iVar8 = 10;
                }
              }
              else {
                if (uVar14 != 0x18) goto _L449;
                uVar19 = 3;
                iVar8 = 3;
              }
              uVar20 = iVar8 + uVar6 & 0xffff;
              (&DAT_00015075)[iVar22] = uVar19;
              (&DAT_00015074)[iVar22] = bVar24;
              puVar10 = (ushort *)r_emi_get_mem_addr_by_offset(uVar20);
              uVar28 = *puVar10;
              uVar16 = *(ushort *)(iVar13 + 0x44);
              if (((uint)uVar16 == (uint)uVar28) &&
                 (pbVar12 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar12 == uVar14)) {
                uVar6 = (uint)*(ushort *)(iVar13 + 0x7c) + (uint)*(ushort *)(iVar13 + 0x7e) + 9 +
                        (uint)*(ushort *)(iVar13 + 0x72);
                iVar8 = uVar6 * 0x10000;
                uVar6 = uVar6 & 0xffff;
                if (((uVar6 + 1) - (uint)uVar16 & 0xffff) < 0x7fff) {
                  puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar20);
                  *puVar11 = (char)((uint)iVar8 >> 0x10);
                  puVar11[1] = (char)(uVar6 >> 8);
                  *(short *)(iVar13 + 0x44) = (short)((uint)iVar8 >> 0x10);
                }
              }
              else {
                if (0 < _g_bt_plf_log_level) {
                  uVar16 = *(ushort *)(iVar13 + 0x7e);
                  uVar3 = *(ushort *)(iVar13 + 0x7c);
                  puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
                  ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar3 + (uint)uVar16,*puVar11,
                             (uint)uVar28,*(undefined1 *)(iVar13 + 0x46),
                             *(undefined2 *)(iVar13 + 0x44));
                }
                r_lld_con_llcp_ind_info_clear(param_2);
              }
            }
          }
_L449:
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar16 = *(ushort *)(iVar8 + iVar27);
          iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar27 + iVar8) = uVar16 & 0x7fff;
          *(byte *)(iVar13 + 0x91) = *(char *)(iVar13 + 0x91) + 1U & 1;
          r_lld_con_tx_prog_new_packet_coex(iVar13);
          *(char *)(iVar13 + 0x92) = *(char *)(iVar13 + 0x92) + '\x01';
          iVar8 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
             (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
            iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
            r_ble_log_internal_x2
                      (0x40e30013,uVar14 << 8 | param_2 | uVar25 << 0x10,
                       *(undefined2 *)(iVar8 + iVar27 + 2));
          }
          bVar26 = bVar26 + 1;
        } while( true );
      }
      bVar26 = *(byte *)(iVar15 + 0x91);
      bVar24 = *(byte *)(iVar15 + 0x8e);
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar15 = ((bVar26 + 1 & 1) + (uint)bVar24 * 9 & 0xff) * 0xe;
      if (-1 < *(short *)(iVar13 + iVar15)) {
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar15 = iVar15 + 2;
        uVar16 = *(ushort *)(iVar13 + iVar15);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar15) = uVar16 | 0x10;
      }
    }
    return;
  case 4:
    iVar15 = *(int *)(&lld_con_env + param_2 * 4);
    iVar13 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
       (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x4043000b,(uint)*(byte *)(iVar15 + 0x8f) << 8 | param_2);
    }
    r_lld_con_frm_skip_isr(param_2);
    param_2 = (uint)*(byte *)(iVar15 + 0x8e);
    goto ble_con_evt_status_update;
  }
  iVar13 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
     (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000a,iVar15 << 8 | param_2,param_1);
  }
  iVar13 = r_lld_con_terminate_max_evt_update
                     (param_2,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >>
                              8 & 1);
  if (iVar13 != 0) {
    return;
  }
  iVar13 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar13 + 0x19) == '\x02') {
    r_lld_cca_con_evt_end_handle();
  }
  r_lld_con_frm_isr(param_2,param_1,iVar15);
ble_con_evt_status_update:
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_2,0);
  return;
}

