/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  char cVar13;
  short sVar14;
  int iVar15;
  undefined2 uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_con.c",0xc11);
    return;
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x8f) == '\x02') {
    iVar11 = 0x3d;
    if ((*(ushort *)(iVar6 + 0x84) & 0x80) == 0) {
      iVar11 = 0x16;
    }
  }
  else {
    iVar11 = r_lld_read_clock();
    if (sdk_cfg_priv_opts != '\0') {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(param_1 * 0x5a + 0x56 + iVar9);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      iVar15 = param_1 * 0x5a + 0x18;
      if ((((&g_event_empty)[param_1] == '\x01') && (uVar4 >> 8 == 0)) &&
         ((*(ushort *)(iVar9 + iVar15) >> 0xe & 1) == 0)) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        uVar4 = *(ushort *)(iVar9 + iVar15);
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar15) = uVar4 & 0xbfff | 0x4000;
      }
      else {
        (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar9 + iVar15) >> 0xe) & 1;
      }
    }
    uVar4 = *(ushort *)(iVar6 + 0x84);
    iVar9 = 5;
    if ((((uVar4 & 6) == 2) && ((uVar4 & 8) == 0)) && (iVar9 = 4, *(char *)(iVar6 + 0x46) == '\x01')
       ) {
      iVar9 = 5;
    }
    *(uint *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + *(int *)(iVar6 + 100) & 0xfffffff;
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    if (param_2 == 0) {
      cVar13 = (&rwip_priority)[iVar9 * 2];
    }
    else {
      cVar13 = *(char *)(iVar9 * 2 + 0x16099) + *(char *)(iVar6 + 0x16);
    }
    *(char *)(iVar6 + 0x16) = cVar13;
    uVar12 = (int)(uint)uVar4 >> 8 & 1;
    iVar6 = *(int *)(&lld_con_env + param_1 * 4);
    uVar4 = *(ushort *)(iVar6 + 0x84);
    uVar7 = *(uint *)(iVar6 + 0x48);
    uVar19 = (uint)DAT_00016066 << 1;
    if ((uVar4 & 2) == 0) {
      *(undefined1 *)(iVar6 + 0x16) = 0x1f;
    }
    if (((uVar4 & 3) == 3) && (*(undefined1 *)(iVar6 + 0x96) = 0, uVar12 != 0)) {
      uVar3 = *(ushort *)(iVar6 + 0x72);
      if ((uVar3 != 0) &&
         ((((uVar4 & 0x404) == 0x400 && ((uVar4 & 8) == 0)) && (*(char *)(iVar6 + 0x46) == '\0'))))
      {
        uVar7 = (uint)uVar3 * *(int *)(iVar6 + 100) + uVar7 & 0xfffffff;
        *(ushort *)(iVar6 + 0x7e) = uVar3 + *(short *)(iVar6 + 0x7e);
        *(undefined1 *)(iVar6 + 0x96) = 1;
      }
    }
    for (; (iVar11 - uVar7 & 0xfffffff) < 0x7ffffff;
        uVar7 = *(int *)(iVar6 + 100) + uVar7 & 0xfffffff) {
      *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    }
    uVar20 = *(uint *)(iVar6 + 0x58);
    if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar6 + 0x42) == '\0') {
        uVar7 = *(ushort *)(iVar6 + 0x3c) + uVar7 & 0xfffffff;
        if ((uVar4 & 1) != 0) {
          uVar7 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar7 & 0xfffffff;
        }
        *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x34);
        *(undefined2 *)(iVar6 + 0x72) = *(undefined2 *)(iVar6 + 0x3e);
        *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x38);
        *(undefined1 *)(iVar6 + 0x42) = 1;
        if (((uVar4 & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e)),
           (*(ushort *)(iVar6 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar6 + 0x43) = 1;
        }
      }
      sVar14 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
      uVar20 = uVar7;
      while (sVar14 = sVar14 + -1, sVar14 != -1) {
        uVar20 = uVar20 - *(int *)(iVar6 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      uVar21 = *(int *)(iVar6 + 100) * 6;
    }
    else {
      uVar21 = *(uint *)(iVar6 + 0x68);
    }
    iVar11 = (param_1 + 0x10) * 2;
    iVar9 = 0;
    while (uVar16 = (undefined2)iVar9, (uVar7 - uVar20 & 0xfffffff) <= uVar21) {
      uVar17 = uVar7;
      if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
        iVar15 = *(int *)(iVar6 + 0x50);
        sVar14 = *(short *)(iVar6 + 0x6e);
        iVar9 = r_rwip_active_check();
        uVar19 = 0x14;
        if (iVar9 == 0) {
          uVar19 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar17 = ((*(ushort *)(iVar6 + 0x7a) + uVar19) * (uVar7 - iVar15 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar19 = uVar17 * 2;
        if (uVar12 != 0) {
          *(undefined2 *)(&DAT_00015038 + iVar11) = 0;
        }
        if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
          uVar19 = uVar19 + (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
_L247:
          bVar5 = true;
        }
        else {
          bVar5 = false;
          if ((*(ushort *)(iVar6 + 0x7c) < 7) &&
             ((uVar12 == 0 ||
              ((bVar5 = false, *(ushort *)(iVar6 + 0x7c) == 0 && (*(short *)(iVar6 + 0x98) == -1))))
             )) {
            uVar19 = uVar19 + ((int)((uint)*(ushort *)(&DAT_00015038 + iVar11) *
                                     (uint)*(ushort *)(iVar6 + 0x70) * 0x271) >> 1) +
                              (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
            uVar18 = *(int *)(iVar6 + 100) * 0x271;
            if (uVar18 < uVar19) {
              uVar19 = uVar18;
            }
            *(ushort *)(&DAT_00015038 + iVar11) = *(ushort *)(&DAT_00015038 + iVar11) + 1;
            goto _L247;
          }
        }
        if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x42) != '\0')) &&
           (*(char *)(iVar6 + 0x43) == '\0')) {
          uVar19 = uVar19 + (uint)*(ushort *)(iVar6 + 0x40) * 0x271;
        }
        else if (((!bVar5) && (((uint)(*(int *)(iVar6 + 100) * 0x271) >> 1) - 300 <= uVar17)) &&
                ((iVar9 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar9 + 0x28) & 0x20) != 0 &&
                 (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)))) {
          r_ble_log_internal_x3
                    (0x4043000f,(uint)*(ushort *)(iVar6 + 0x7c) << 0x10 | param_1,
                     *(undefined4 *)(iVar6 + 100),uVar17);
        }
        uVar18 = (uVar19 >> 1) / 0x271;
        uVar17 = uVar7 - uVar18 & 0xfffffff;
        iVar9 = uVar18 * 0x271 + ((int)sVar14 - (uVar19 >> 1));
        if (iVar9 < 0) {
          uVar17 = uVar17 - 1 & 0xfffffff;
          iVar9 = iVar9 + 0x271;
        }
        *(int *)(iVar6 + 8) = iVar9;
        *(uint *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x5c) + uVar19;
      }
      uVar16 = (undefined2)iVar9;
      *(uint *)(iVar6 + 4) = uVar17;
      iVar15 = r_sch_arb_insert(iVar6);
      if (iVar15 == 0) {
        iVar11 = 1;
        goto _L191;
      }
      *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + rwip_priority;
      uVar7 = *(int *)(iVar6 + 100) + uVar7 & 0xfffffff;
      sVar14 = *(short *)(iVar6 + 0x7e);
      *(short *)(iVar6 + 0x7e) = sVar14 + 1;
      if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
         ((ushort)(((sVar14 + 1) - *(short *)(iVar6 + 0x44)) + *(short *)(iVar6 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar6 + 0x42) == '\0') {
          uVar7 = *(ushort *)(iVar6 + 0x3c) + uVar7 & 0xfffffff;
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            uVar7 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar7 & 0xfffffff;
          }
          *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x34);
          *(undefined2 *)(iVar6 + 0x72) = *(undefined2 *)(iVar6 + 0x3e);
          *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x38);
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e));
          }
          *(undefined1 *)(iVar6 + 0x42) = 1;
          uVar21 = *(uint *)(iVar6 + 0x68);
          if ((*(ushort *)(iVar6 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar6 + 0x43) = 1;
          }
        }
        sVar14 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
        uVar20 = uVar7;
        while (sVar14 = sVar14 + -1, sVar14 != -1) {
          uVar20 = uVar20 - *(int *)(iVar6 + 100) & 0xfffffff;
        }
      }
    }
    iVar11 = 0;
_L191:
    iVar9 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar9 + 0x28) & 0x20) != 0) &&
       (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x4043000d,iVar11 << 8 | param_1,*(undefined4 *)(iVar6 + 0x7c));
    }
    if (iVar11 != 0) {
      *(undefined1 *)(iVar6 + 0x8f) = 0;
      *(uint *)(iVar6 + 0x48) = uVar7;
      if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
        uVar7 = (uint)DAT_00016066;
        *(undefined2 *)(iVar6 + 0x6c) = uVar16;
        *(uint *)(iVar6 + 0x4c) = uVar7 * 2 + uVar19;
      }
      return;
    }
    iVar11 = 8;
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      iVar11 = 0x3e;
    }
  }
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    return;
  }
  iVar9 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar9 + 0x28) & 0x20) != 0) &&
     (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar11 << 0x10 | 0x100U | param_1);
  }
  uVar19 = param_1 << 8 | 1;
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x212,uVar19,0xff,1);
  *puVar8 = (char)iVar11;
  r_ke_msg_send();
  iVar11 = r_co_list_pop_front(iVar6 + 0x28);
  do {
    if (*(char *)(iVar6 + 0x92) == '\0') {
      if (*(int *)(iVar6 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar6 + 0x24) + 4));
      }
      while (iVar11 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar11 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar19,0xff);
        }
        iVar11 = r_co_list_pop_front(iVar6 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar1 = *(byte *)(iVar6 + 0x8e);
    bVar2 = *(byte *)(iVar6 + 0x90);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar15 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar4 = *(ushort *)(iVar15 + 2 + iVar9);
    if ((uVar4 & 3) == 3) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar15 + 4 + iVar9));
      uVar10 = 0x79f;
      if (*(int *)(iVar6 + 0x24) != 0) goto _L165;
    }
    else {
      uVar10 = 0x7a8;
      if ((uVar4 & 3) == 0) {
_L165:
        r_assert_err(0,"lld_con.c",uVar10);
      }
    }
    *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + -1;
    *(byte *)(iVar6 + 0x90) = *(char *)(iVar6 + 0x90) + 1U & 1;
  } while( true );
}

