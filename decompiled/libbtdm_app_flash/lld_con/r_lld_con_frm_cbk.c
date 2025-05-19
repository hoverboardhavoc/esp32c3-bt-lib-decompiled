/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  ushort *puVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  ushort uVar14;
  uint uVar15;
  undefined1 uVar16;
  uint uVar17;
  int *piVar18;
  int *piVar19;
  ushort uVar20;
  int iVar21;
  byte bVar22;
  uint uVar23;
  byte bVar24;
  int iVar25;
  int iVar26;
  int iStack_68;
  uint uStack_64;
  
  if (4 < param_3) {
    r_assert_param(param_3,"lld_con.c",0xd23);
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
      r_assert_param(0,"lld_con.c",0xc2c);
      return;
    }
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    iVar11 = r_sdk_config_get_opts_ext(param_1);
    if (((*(uint *)(iVar11 + 0x28) & 0x20) != 0) &&
       (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x40c3001b,param_2);
    }
    *(ushort *)(iVar13 + 0x84) = *(ushort *)(iVar13 + 0x84) & 0xfffb;
    while (iVar11 = r_lld_rxdesc_check_hack(param_2), iVar11 != 0) {
      bVar24 = *(byte *)(_p_lld_env + 0xd8);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar21 = (uint)bVar24 * 0x14;
      uVar14 = *(ushort *)(iVar21 + 2 + iVar7);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar21 + 4 + iVar7);
      if (((uVar14 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_2,iVar13), (uVar14 & 8) == 0))
      {
        *(undefined4 *)(iVar13 + 0x58) = *(undefined4 *)(iVar13 + 0x50);
        if ((uVar14 & 0x66) == 0) {
          if ((uVar14 & 0x10) == 0) {
            iVar7 = r_emi_get_mem_addr_by_offset(0x400);
            uVar14 = uVar3 >> 8;
            *(undefined2 *)(iVar13 + 0x98) = *(undefined2 *)(iVar7 + param_2 * 0x5a + 0x50);
            if ((uVar14 != 0) && ((uVar3 & 3) != 0)) {
              if ((4 < uVar14) && ((*(ushort *)(iVar13 + 0x84) & 0x20) != 0)) {
                uVar14 = uVar14 - 4;
              }
              iVar7 = r_lld_con_rx_llcp_check(param_2,iVar13,uVar14);
              if (iVar7 == 0) {
                iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
                *(undefined2 *)(iVar21 + 0x12 + iVar7) = 0;
              }
            }
          }
          else {
            iVar7 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
               (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
              r_ble_log_internal_x1(0x40c30023,(uint)bVar24 << 8 | param_2 | (uint)uVar14 << 0x10);
            }
            *(undefined1 *)(iVar13 + 0x8f) = 2;
            *(ushort *)(iVar13 + 0x84) = *(ushort *)(iVar13 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar11 = 0;
      }
      r_lld_con_rx_channel_assess_hack(iVar13,iVar11);
      r_lld_rxdesc_free();
    }
    return;
  case 3:
    if (*(int *)(&lld_con_env + param_2 * 4) == 0) {
      r_assert_param(0,"lld_con.c",0xc46);
      return;
    }
    r_lld_con_tx_eco(param_1);
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    if (*(int *)(iVar13 + 0x30) == 0) {
      iVar11 = *(int *)(iVar13 + 0x28);
      *(int *)(iVar13 + 0x30) = iVar11;
      if (iVar11 != 0) {
        *(ushort *)(iVar13 + 0x82) = *(ushort *)(iVar11 + 6) & 0x3ff;
      }
    }
    bVar4 = false;
    if ((((*(ushort *)(iVar13 + 0x84) & 0x10) != 0) && (*(int **)(iVar13 + 0x30) != (int *)0x0)) &&
       (bVar4 = true, *(short *)(iVar13 + 0x82) == 0)) {
      bVar4 = **(int **)(iVar13 + 0x30) != 0;
    }
    iVar11 = *(int *)(iVar13 + 0x24);
    if ((iVar11 != 0) || (bVar4)) {
      if (*(char *)(iVar13 + 0x92) != '\x02') {
        uVar12 = 0x23;
        if (iVar11 != 0) {
          pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar11 + 4));
          uVar12 = (uint)*pbVar10;
        }
        iVar13 = param_2 * 4;
        iVar11 = *(int *)(&lld_con_env + iVar13);
        iStack_68 = *(int *)(iVar11 + 0x24);
        piVar19 = *(int **)(iVar11 + 0x30);
        uStack_64 = 0;
        if ((((*(ushort *)(iVar11 + 0x84) & 0x10) != 0) && (piVar19 != (int *)0x0)) &&
           (uStack_64 = 1, *(short *)(iVar11 + 0x82) == 0)) {
          uStack_64 = (uint)(*piVar19 != 0);
        }
        bVar24 = *(byte *)(iVar11 + 0x92);
        iVar7 = (param_2 + 0x18) * 2;
        do {
          if (1 < bVar24) {
            return;
          }
          if (iStack_68 == 0) {
            if (uStack_64 == 0) {
              return;
            }
_L436:
            if ((*(short *)(iVar11 + 0x82) == 0) &&
               (piVar18 = (int *)*piVar19, piVar18 != (int *)0x0)) {
              uVar14 = *(ushort *)((int)piVar18 + 6);
              *(int **)(iVar11 + 0x30) = piVar18;
              *(ushort *)(iVar11 + 0x82) = uVar14 & 0x3ff;
              piVar19 = piVar18;
            }
            uVar14 = *(ushort *)((int)piVar19 + 6);
            uVar3 = *(ushort *)(iVar11 + 0x82);
            uVar23 = (uint)uVar3;
            uVar6 = (*(ushort *)(piVar19 + 1) - uVar23) + (uVar14 & 0x3ff) & 0xffff;
            uVar20 = 2;
            if (((int)(uint)uVar14 >> 0xc & 3U) == 1) {
              uVar20 = 1;
            }
            uVar17 = (uint)*(byte *)(iVar11 + 0x8c);
            if (uVar23 < *(byte *)(iVar11 + 0x8c)) {
              uVar17 = uVar23;
            }
            *(ushort *)((int)piVar19 + 6) = uVar14 & 0xcfff | 0x1000;
            *(ushort *)(iVar11 + 0x82) = uVar3 - (short)uVar17;
          }
          else {
            if ((((uVar12 == 2) && (uStack_64 != 0)) && (bVar24 != 1)) && (DAT_0001608e != '\0'))
            goto _L436;
            uVar20 = 3;
            uVar17 = (uint)*(byte *)(iStack_68 + 6);
            uVar6 = (uint)*(ushort *)(iStack_68 + 4);
            iStack_68 = 0;
            *(undefined4 *)(iVar11 + 0x24) = 0;
          }
          cVar1 = *(char *)(iVar11 + 0x91);
          cVar5 = *(char *)(iVar11 + 0x8e) * '\t';
          uVar14 = *(ushort *)(iVar11 + 0x84);
          uStack_64 = 0;
          bVar22 = cVar5 + cVar1;
          uVar23 = (uint)bVar22;
          if ((((uVar14 & 0x10) != 0) && (piVar19 != (int *)0x0)) &&
             (uStack_64 = 1, *(short *)(iVar11 + 0x82) == 0)) {
            uStack_64 = (uint)(*piVar19 != 0);
          }
          if ((uVar14 & 0x40) != 0) {
            uVar17 = uVar17 + 4 & 0xffff;
          }
          if ((uVar14 & 0x2000) == 0) {
            uVar15 = uStack_64;
            if (uStack_64 == 0) {
              uVar15 = uVar14 & 1;
            }
          }
          else {
            uVar15 = 0;
          }
          iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar25 = uVar23 * 0xe;
          *(ushort *)(iVar21 + iVar25 + 2) =
               (ushort)((uVar17 & 0xff) << 8) | uVar20 | (ushort)(uVar15 << 4);
          iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
          *(short *)(iVar25 + 4 + iVar21) = (short)uVar6;
          if ((*(ushort *)(iVar11 + 0x84) & 0x2000) == 0) {
            iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
            iVar26 = (uint)(byte)((cVar1 + 1U & 1) + cVar5) * 0xe;
            if (-1 < *(short *)(iVar21 + iVar26)) {
              iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
              iVar26 = iVar26 + 2;
              uVar14 = *(ushort *)(iVar21 + iVar26);
              iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
              *(ushort *)(iVar21 + iVar26) = uVar14 & 0xffef | 0x10;
            }
          }
          if (uVar20 == 3) {
            if (uVar12 == 2) {
              bVar2 = *(byte *)(iVar11 + 0x90);
              *(undefined1 *)(&lld_con_cntl_pkt_info + param_2) = 1;
              *(byte *)((int)&lld_con_cntl_pkt_info + iVar13 + 1) = bVar22;
              if (uVar23 == (uint)bVar2 + param_2 * 9) {
                *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar13 + 2) = 1;
              }
            }
            else {
              if (uVar12 < 3) {
                if (uVar12 == 0) {
                  uVar16 = 1;
                  iVar21 = 10;
                }
                else {
                  uVar16 = 2;
                  iVar21 = 6;
                }
              }
              else {
                if (uVar12 != 0x18) goto _L449;
                uVar16 = 3;
                iVar21 = 3;
              }
              uVar17 = uVar6 + iVar21 & 0xffff;
              (&DAT_0001503d)[iVar7] = uVar16;
              (&DAT_0001503c)[iVar7] = bVar22;
              puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(uVar17);
              uVar3 = *puVar8;
              uVar14 = *(ushort *)(iVar11 + 0x44);
              if (((uint)uVar14 == (uint)uVar3) &&
                 (pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar10 == uVar12)) {
                uVar6 = (uint)*(ushort *)(iVar11 + 0x7c) + (uint)*(ushort *)(iVar11 + 0x7e) + 9 +
                        (uint)*(ushort *)(iVar11 + 0x72);
                iVar21 = uVar6 * 0x10000;
                uVar6 = uVar6 & 0xffff;
                if (((uVar6 + 1) - (uint)uVar14 & 0xffff) < 0x7fff) {
                  puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar17);
                  *puVar9 = (char)((uint)iVar21 >> 0x10);
                  puVar9[1] = (char)(uVar6 >> 8);
                  *(short *)(iVar11 + 0x44) = (short)((uint)iVar21 >> 0x10);
                }
              }
              else {
                if (0 < _g_bt_plf_log_level) {
                  uVar14 = *(ushort *)(iVar11 + 0x7e);
                  uVar20 = *(ushort *)(iVar11 + 0x7c);
                  puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
                  ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar20 + (uint)uVar14,*puVar9,
                             (uint)uVar3,*(undefined1 *)(iVar11 + 0x46),
                             *(undefined2 *)(iVar11 + 0x44));
                }
                r_lld_con_llcp_ind_info_clear(param_2);
              }
            }
          }
_L449:
          iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar14 = *(ushort *)(iVar21 + iVar25);
          iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar25 + iVar21) = (ushort)(((uint)uVar14 << 0x11) >> 0x11);
          *(byte *)(iVar11 + 0x91) = *(char *)(iVar11 + 0x91) + 1U & 1;
          r_lld_con_tx_prog_new_packet_coex(iVar11);
          *(char *)(iVar11 + 0x92) = *(char *)(iVar11 + 0x92) + '\x01';
          iVar21 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar21 + 0x28) & 0x20) != 0) &&
             (iVar21 = r_sdk_config_get_opts_ext(), *(byte *)(iVar21 + 0x2c) < 3)) {
            iVar21 = r_emi_get_mem_addr_by_offset(0x1400);
            r_ble_log_internal_x2
                      (0x40e30013,uVar23 << 0x10 | uVar12 << 8 | param_2,
                       *(undefined2 *)(iVar21 + iVar25 + 2));
          }
          bVar24 = bVar24 + 1;
        } while( true );
      }
      bVar24 = *(byte *)(iVar13 + 0x91);
      bVar22 = *(byte *)(iVar13 + 0x8e);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = ((bVar24 + 1 & 1) + (uint)bVar22 * 9 & 0xff) * 0xe;
      if (-1 < *(short *)(iVar11 + iVar13)) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar13 = iVar13 + 2;
        uVar14 = *(ushort *)(iVar11 + iVar13);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar11) = uVar14 & 0xffef | 0x10;
      }
    }
    return;
  case 4:
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    iVar11 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar11 + 0x28) & 0x20) != 0) &&
       (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x4043000b,(uint)*(byte *)(iVar13 + 0x8f) << 8 | param_2);
    }
    r_lld_con_frm_skip_isr(param_2);
    param_2 = (uint)*(byte *)(iVar13 + 0x8e);
    goto ble_con_evt_status_update;
  }
  iVar11 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar11 + 0x28) & 0x20) != 0) &&
     (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000a,iVar13 << 8 | param_2,param_1);
  }
  iVar11 = r_lld_con_terminate_max_evt_update
                     (param_2,(int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_2 * 4) + 0x84) >>
                              8 & 1);
  if (iVar11 != 0) {
    return;
  }
  iVar11 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar11 + 0x19) == '\x02') {
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

