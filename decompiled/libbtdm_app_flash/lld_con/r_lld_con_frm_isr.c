/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  char cVar14;
  short sVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  uint uVar20;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,"lld_con.c",0xc07);
    return;
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 0x8f) == '\x02') {
    iVar11 = 0x3d;
    if ((*(ushort *)(iVar4 + 0x84) & 0x80) == 0) {
      iVar11 = 0x16;
    }
  }
  else {
    iVar11 = r_lld_read_clock();
    if (sdk_cfg_priv_opts != '\0') {
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar7 + param_1 * 0x5a + 0x56);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar7 = param_1 * 0x5a + 0x18;
      if ((((&g_event_empty)[param_1] == '\x01') && (uVar3 >> 8 == 0)) &&
         ((*(ushort *)(iVar8 + iVar7) >> 0xe & 1) == 0)) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(ushort *)(iVar8 + iVar7);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar7 + iVar8) = uVar3 & 0xbfff | 0x4000;
      }
      else {
        (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar8 + iVar7) >> 0xe) & 1;
      }
    }
    uVar3 = *(ushort *)(iVar4 + 0x84);
    iVar7 = 5;
    if ((((uVar3 & 6) == 2) && ((uVar3 & 8) == 0)) && (iVar7 = 4, *(char *)(iVar4 + 0x46) == '\x01')
       ) {
      iVar7 = 5;
    }
    *(uint *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + *(int *)(iVar4 + 100) & 0xfffffff;
    *(short *)(iVar4 + 0x7e) = *(short *)(iVar4 + 0x7e) + 1;
    if (param_2 == 0) {
      cVar14 = (&rwip_priority)[iVar7 * 2];
    }
    else {
      cVar14 = *(char *)(iVar7 * 2 + 0x16099) + *(char *)(iVar4 + 0x16);
    }
    *(char *)(iVar4 + 0x16) = cVar14;
    uVar12 = (int)(uint)uVar3 >> 8 & 1;
    iVar4 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar4 + 0x84);
    uVar16 = (uint)DAT_00016066 << 1;
    uVar5 = *(uint *)(iVar4 + 0x48);
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar4 + 0x16) = 0x1f;
    }
    if (((uVar3 & 3) == 3) && (*(undefined1 *)(iVar4 + 0x96) = 0, uVar12 != 0)) {
      uVar13 = *(ushort *)(iVar4 + 0x72);
      if ((uVar13 != 0) &&
         ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar4 + 0x46) == '\0'))))
      {
        uVar5 = uVar5 + (uint)uVar13 * *(int *)(iVar4 + 100) & 0xfffffff;
        *(ushort *)(iVar4 + 0x7e) = uVar13 + *(short *)(iVar4 + 0x7e);
        *(undefined1 *)(iVar4 + 0x96) = 1;
      }
    }
    for (; (iVar11 - uVar5 & 0xfffffff) < 0x7ffffff;
        uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff) {
      *(short *)(iVar4 + 0x7e) = *(short *)(iVar4 + 0x7e) + 1;
    }
    uVar17 = *(uint *)(iVar4 + 0x58);
    if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar4 + 0x42) == '\0') {
        uVar5 = uVar5 + *(ushort *)(iVar4 + 0x3c) & 0xfffffff;
        if ((uVar3 & 1) != 0) {
          uVar5 = uVar5 + (*(ushort *)(iVar4 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(iVar4 + 0x34);
        *(undefined2 *)(iVar4 + 0x72) = *(undefined2 *)(iVar4 + 0x3e);
        *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar4 + 0x38);
        *(undefined1 *)(iVar4 + 0x42) = 1;
        if (((uVar3 & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar4 + 0x8e)),
           (*(ushort *)(iVar4 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar4 + 0x43) = 1;
        }
      }
      sVar15 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
      uVar17 = uVar5;
      while (sVar15 = sVar15 + -1, sVar15 != -1) {
        uVar17 = uVar17 - *(int *)(iVar4 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
      uVar20 = *(int *)(iVar4 + 100) * 6;
    }
    else {
      uVar20 = *(uint *)(iVar4 + 0x68);
    }
    iVar11 = (param_1 + 0x10) * 2;
    iVar7 = 0;
    while (sVar15 = (short)iVar7, (uVar5 - uVar17 & 0xfffffff) <= uVar20) {
      uVar18 = uVar5;
      if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
        iVar8 = *(int *)(iVar4 + 0x50);
        sVar15 = *(short *)(iVar4 + 0x6e);
        iVar7 = r_rwip_active_check();
        uVar16 = 0x14;
        if (iVar7 == 0) {
          uVar16 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar18 = ((*(ushort *)(iVar4 + 0x7a) + uVar16) * (uVar5 - iVar8 & 0xfffffff)) / 0x640 + 0x40
        ;
        uVar16 = uVar18 * 2;
        if (uVar12 != 0) {
          *(undefined2 *)(&DAT_0001502c + iVar11) = 0;
        }
        if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
          uVar16 = uVar16 + (uint)*(ushort *)(iVar4 + 0x70) * 0x271;
_L248:
          bVar19 = true;
        }
        else {
          bVar19 = false;
          if ((*(ushort *)(iVar4 + 0x7c) < 7) &&
             ((uVar12 == 0 ||
              ((bVar19 = false, *(ushort *)(iVar4 + 0x7c) == 0 && (*(short *)(iVar4 + 0x98) == -1)))
              ))) {
            uVar10 = ((int)((uint)*(ushort *)(&DAT_0001502c + iVar11) *
                            (uint)*(ushort *)(iVar4 + 0x70) * 0x271) >> 1) +
                     (uint)*(ushort *)(iVar4 + 0x70) * 0x271 + uVar16;
            uVar16 = *(int *)(iVar4 + 100) * 0x271;
            if (uVar10 < uVar16) {
              uVar16 = uVar10;
            }
            *(ushort *)(&DAT_0001502c + iVar11) = *(ushort *)(&DAT_0001502c + iVar11) + 1;
            goto _L248;
          }
        }
        if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x42) != '\0')) &&
           (*(char *)(iVar4 + 0x43) == '\0')) {
          uVar16 = uVar16 + (uint)*(ushort *)(iVar4 + 0x40) * 0x271;
        }
        else if ((!bVar19) && (((uint)(*(int *)(iVar4 + 100) * 0x271) >> 1) - 300 <= uVar18)) {
          iVar7 = r_sdk_config_get_opts_ext();
          iVar11 = 0;
          if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
             (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
            r_ble_log_internal_x3
                      (0x4043000f,(uint)*(ushort *)(iVar4 + 0x7c) << 0x10 | param_1,
                       *(undefined4 *)(iVar4 + 100),uVar18);
          }
          goto _L191;
        }
        uVar10 = (uVar16 >> 1) / 0x271;
        uVar18 = uVar5 - uVar10 & 0xfffffff;
        iVar7 = ((int)sVar15 - (uVar16 >> 1)) + uVar10 * 0x271;
        if (iVar7 < 0) {
          uVar18 = uVar18 - 1 & 0xfffffff;
          iVar7 = iVar7 + 0x271;
        }
        *(int *)(iVar4 + 8) = iVar7;
        *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x5c) + uVar16;
      }
      sVar15 = (short)iVar7;
      *(uint *)(iVar4 + 4) = uVar18;
      iVar8 = r_sch_arb_insert(iVar4);
      if (iVar8 == 0) {
        iVar11 = 1;
        goto _L191;
      }
      *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + rwip_priority;
      sVar15 = *(short *)(iVar4 + 0x7e);
      uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff;
      *(short *)(iVar4 + 0x7e) = sVar15 + 1;
      if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
         ((ushort)(((sVar15 + 1) - *(short *)(iVar4 + 0x44)) + *(short *)(iVar4 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar4 + 0x42) == '\0') {
          uVar5 = uVar5 + *(ushort *)(iVar4 + 0x3c) & 0xfffffff;
          if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
            uVar5 = uVar5 + (*(ushort *)(iVar4 + 0x40) >> 1) & 0xfffffff;
          }
          *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(iVar4 + 0x34);
          *(undefined2 *)(iVar4 + 0x72) = *(undefined2 *)(iVar4 + 0x3e);
          *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar4 + 0x38);
          if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar4 + 0x8e));
          }
          *(undefined1 *)(iVar4 + 0x42) = 1;
          uVar20 = *(uint *)(iVar4 + 0x68);
          if ((*(ushort *)(iVar4 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar4 + 0x43) = 1;
          }
        }
        sVar15 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
        uVar17 = uVar5;
        while (sVar15 = sVar15 + -1, sVar15 != -1) {
          uVar17 = uVar17 - *(int *)(iVar4 + 100) & 0xfffffff;
        }
      }
    }
    iVar11 = 0;
_L191:
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x4043000d,iVar11 << 8 | param_1,*(undefined4 *)(iVar4 + 0x7c));
    }
    if (iVar11 != 0) {
      *(undefined1 *)(iVar4 + 0x8f) = 0;
      *(uint *)(iVar4 + 0x48) = uVar5;
      if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
        uVar5 = (uint)DAT_00016066;
        *(short *)(iVar4 + 0x6c) = sVar15;
        *(uint *)(iVar4 + 0x4c) = uVar16 + uVar5 * 2;
      }
      return;
    }
    iVar11 = 8;
    if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
      iVar11 = 0x3e;
    }
  }
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 == 0) {
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar11 << 0x10 | 0x100U | param_1);
  }
  uVar16 = param_1 << 8 | 1;
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar16,0xff,1);
  *puVar6 = (char)iVar11;
  r_ke_msg_send();
  iVar11 = r_co_list_pop_front(iVar4 + 0x28);
  do {
    if (*(char *)(iVar4 + 0x92) == '\0') {
      if (*(int *)(iVar4 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar4 + 0x24) + 4));
      }
      while (iVar11 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar11 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar16,0xff);
        }
        iVar11 = r_co_list_pop_front(iVar4 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar1 = *(byte *)(iVar4 + 0x8e);
    bVar2 = *(byte *)(iVar4 + 0x90);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar8 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar7 + iVar8 + 2);
    uVar13 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L146:
      uVar9 = 0x7a8;
_L167:
      r_assert_err(0,"lld_con.c",uVar9);
    }
    else if (2 < uVar13) {
      if (uVar13 != 3) goto _L146;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar8 + 4 + iVar7));
      uVar9 = 0x79f;
      if (*(int *)(iVar4 + 0x24) == 0) goto _L147;
      goto _L167;
    }
_L147:
    *(char *)(iVar4 + 0x92) = *(char *)(iVar4 + 0x92) + -1;
    *(byte *)(iVar4 + 0x90) = *(char *)(iVar4 + 0x90) + 1U & 1;
  } while( true );
}

