/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  ushort uVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  ushort uVar18;
  int iVar19;
  byte bVar20;
  uint uVar21;
  byte bVar22;
  char cVar23;
  int iVar24;
  int *piStack_64;
  
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
      bVar22 = *(byte *)(_p_lld_env + 0xd8);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar19 = (uint)bVar22 * 0x14;
      uVar14 = *(ushort *)(iVar7 + iVar19 + 2);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar7 + iVar19 + 4);
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
                *(undefined2 *)(iVar19 + 0x12 + iVar7) = 0;
              }
            }
          }
          else {
            iVar7 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
               (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
              r_ble_log_internal_x1(0x40c30023,(uint)bVar22 << 8 | param_2 | (uint)uVar14 << 0x10);
            }
            *(undefined1 *)(iVar13 + 0x8f) = 2;
            *(ushort *)(iVar13 + 0x84) = *(ushort *)(iVar13 + 0x84) | 0x80;
          }
        }
      }
      else {
        iVar11 = 0;
      }
      r_lld_con_rx_channel_assess(iVar13,iVar11);
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
    if ((iVar11 == 0) && (!bVar4)) {
      return;
    }
    if (*(char *)(iVar13 + 0x92) == '\x02') {
      bVar22 = *(byte *)(iVar13 + 0x91);
      bVar20 = *(byte *)(iVar13 + 0x8e);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = ((bVar22 + 1 & 1) + (uint)bVar20 * 9 & 0xff) * 0xe;
      if (-1 < *(short *)(iVar11 + iVar13)) {
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar13 = iVar13 + 2;
        uVar14 = *(ushort *)(iVar11 + iVar13);
        iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar11 + iVar13) = uVar14 & 0xffef | 0x10;
      }
      return;
    }
    uVar12 = 0x23;
    if (iVar11 != 0) {
      pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar11 + 4));
      uVar12 = (uint)*pbVar10;
    }
    iVar13 = *(int *)(&lld_con_env + param_2 * 4);
    iVar11 = *(int *)(iVar13 + 0x24);
    piVar5 = *(int **)(iVar13 + 0x30);
    piStack_64 = (int *)0x0;
    if ((((*(ushort *)(iVar13 + 0x84) & 0x10) != 0) && (piStack_64 = piVar5, piVar5 != (int *)0x0))
       && (piStack_64 = (int *)0x1, *(short *)(iVar13 + 0x82) == 0)) {
      piStack_64 = (int *)(uint)(*piVar5 != 0);
    }
    bVar22 = *(byte *)(iVar13 + 0x92);
    iVar7 = (param_2 + 0x18) * 2;
    do {
      if (1 < bVar22) {
        return;
      }
      if (iVar11 == 0) {
        if (piStack_64 == (int *)0x0) {
          return;
        }
_L444:
        if ((*(short *)(iVar13 + 0x82) == 0) && (piVar15 = (int *)*piVar5, piVar15 != (int *)0x0)) {
          uVar14 = *(ushort *)((int)piVar15 + 6);
          *(int **)(iVar13 + 0x30) = piVar15;
          *(ushort *)(iVar13 + 0x82) = uVar14 & 0x3ff;
          piVar5 = piVar15;
        }
        uVar14 = *(ushort *)((int)piVar5 + 6);
        uVar3 = *(ushort *)(iVar13 + 0x82);
        uVar21 = (uint)uVar3;
        uVar6 = (*(ushort *)(piVar5 + 1) - uVar21) + (uVar14 & 0x3ff) & 0xffff;
        uVar18 = 2;
        if (((int)(uint)uVar14 >> 0xc & 3U) == 1) {
          uVar18 = 1;
        }
        uVar16 = (uint)*(byte *)(iVar13 + 0x8c);
        if (uVar21 < *(byte *)(iVar13 + 0x8c)) {
          uVar16 = uVar21;
        }
        *(ushort *)((int)piVar5 + 6) = uVar14 & 0xcfff | 0x1000;
        *(ushort *)(iVar13 + 0x82) = uVar3 - (short)uVar16;
      }
      else {
        if ((((uVar12 == 2) && (piStack_64 != (int *)0x0)) && (bVar22 != 1)) &&
           (DAT_0001608e != '\0')) goto _L444;
        uVar16 = (uint)*(byte *)(iVar11 + 6);
        uVar6 = (uint)*(ushort *)(iVar11 + 4);
        uVar18 = 3;
        *(undefined4 *)(iVar13 + 0x24) = 0;
        iVar11 = 0;
      }
      uVar14 = *(ushort *)(iVar13 + 0x84);
      cVar23 = *(char *)(iVar13 + 0x8e) * '\t';
      cVar1 = *(char *)(iVar13 + 0x91);
      bVar20 = cVar23 + cVar1;
      uVar21 = (uint)bVar20;
      piStack_64 = (int *)0x0;
      if ((((uVar14 & 0x10) != 0) && (piStack_64 = piVar5, piVar5 != (int *)0x0)) &&
         (piStack_64 = (int *)0x1, *(short *)(iVar13 + 0x82) == 0)) {
        piStack_64 = (int *)(uint)(*piVar5 != 0);
      }
      if ((uVar14 & 0x40) != 0) {
        uVar16 = uVar16 + 4 & 0xffff;
      }
      if ((int)((uint)uVar14 << 0x12) < 0) {
        piVar15 = (int *)0x0;
      }
      else {
        piVar15 = piStack_64;
        if (piStack_64 == (int *)0x0) {
          piVar15 = (int *)(uVar14 & 1);
        }
      }
      iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar17 = uVar21 * 0xe;
      *(ushort *)(iVar19 + iVar17 + 2) =
           (ushort)((uVar16 & 0xff) << 8) | uVar18 | (ushort)((int)piVar15 << 4);
      iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
      *(short *)(iVar19 + iVar17 + 4) = (short)uVar6;
      if (-1 < (int)((uint)*(ushort *)(iVar13 + 0x84) << 0x12)) {
        iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar24 = (uint)(byte)((cVar1 + 1U & 1) + cVar23) * 0xe;
        if (-1 < *(short *)(iVar19 + iVar24)) {
          iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar24 = iVar24 + 2;
          uVar14 = *(ushort *)(iVar19 + iVar24);
          iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar19 + iVar24) = uVar14 & 0xffef | 0x10;
        }
      }
      if (uVar18 == 3) {
        if (uVar12 == 2) {
          bVar2 = *(byte *)(iVar13 + 0x90);
          *(undefined1 *)(&lld_con_cntl_pkt_info + param_2) = 1;
          *(byte *)((int)&lld_con_cntl_pkt_info + param_2 * 4 + 1) = bVar20;
          if (uVar21 == (uint)bVar2 + param_2 * 9) {
            *(undefined1 *)((int)&lld_con_cntl_pkt_info + param_2 * 4 + 2) = 1;
          }
        }
        else if ((uVar12 < 2) || (uVar12 == 0x18)) {
          if (uVar12 == 0) {
            (&DAT_00015061)[iVar7] = 1;
            iVar19 = 10;
          }
          else if (uVar12 == 1) {
            (&DAT_00015061)[iVar7] = 2;
            iVar19 = 6;
          }
          else if (uVar12 == 0x18) {
            (&DAT_00015061)[iVar7] = 3;
            iVar19 = 3;
          }
          else {
            r_assert_param(param_2,uVar12,"lld_con.c",0x4f6);
            iVar19 = 0;
          }
          uVar16 = uVar6 + iVar19 & 0xffff;
          (&DAT_00015060)[iVar7] = bVar20;
          puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(uVar16);
          uVar3 = *puVar8;
          uVar14 = *(ushort *)(iVar13 + 0x44);
          if (((uint)uVar14 == (uint)uVar3) &&
             (pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar10 == uVar12)) {
            uVar6 = (uint)*(ushort *)(iVar13 + 0x7c) + (uint)*(ushort *)(iVar13 + 0x7e) + 9 +
                    (uint)*(ushort *)(iVar13 + 0x72);
            iVar19 = uVar6 * 0x10000;
            uVar6 = uVar6 & 0xffff;
            if (((uVar6 + 1) - (uint)uVar14 & 0xffff) < 0x7fff) {
              puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar16);
              *puVar9 = (char)((uint)iVar19 >> 0x10);
              puVar9[1] = (char)(uVar6 >> 8);
              *(short *)(iVar13 + 0x44) = (short)((uint)iVar19 >> 0x10);
            }
          }
          else {
            if (0 < _g_bt_plf_log_level) {
              uVar14 = *(ushort *)(iVar13 + 0x7e);
              uVar18 = *(ushort *)(iVar13 + 0x7c);
              puVar9 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
              ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar18 + (uint)uVar14,*puVar9,
                         (uint)uVar3,*(undefined1 *)(iVar13 + 0x46),*(undefined2 *)(iVar13 + 0x44));
            }
            *(undefined2 *)(&DAT_00015060 + iVar7) = 0;
          }
        }
      }
      iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar14 = *(ushort *)(iVar19 + iVar17);
      iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar19 + iVar17) = uVar14 & 0x7fff;
      *(byte *)(iVar13 + 0x91) = *(char *)(iVar13 + 0x91) + 1U & 1;
      r_lld_con_tx_prog_new_packet_coex(iVar13);
      *(char *)(iVar13 + 0x92) = *(char *)(iVar13 + 0x92) + '\x01';
      iVar19 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar19 + 0x28) & 0x20) != 0) &&
         (iVar19 = r_sdk_config_get_opts_ext(), *(byte *)(iVar19 + 0x2c) < 3)) {
        iVar19 = r_emi_get_mem_addr_by_offset(0x1400);
        r_ble_log_internal_x2
                  (0x40e30013,uVar21 << 0x10 | uVar12 << 8 | param_2,
                   *(undefined2 *)(iVar19 + iVar17 + 2));
      }
      bVar22 = bVar22 + 1;
    } while( true );
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
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(param_2,0);
  return;
}

