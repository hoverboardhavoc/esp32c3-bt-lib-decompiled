/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
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
  bool bVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined2 uVar19;
  uint uVar20;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    r_assert_err(0,"lld_con.c",0xd78);
    return;
  }
  r_sch_arb_remove(iVar5,1);
  if (*(char *)(iVar5 + 0x8f) == '\x02') {
    r_ble_log_internal_x2(0x40030111,(int)(uint)*(ushort *)(iVar5 + 0x84) >> 7 & 1,param_1);
    uVar11 = 0x3d;
    if ((*(ushort *)(iVar5 + 0x84) & 0x80) == 0) {
      uVar11 = 0x16;
    }
  }
  else {
    iVar7 = r_lld_read_clock();
    if (sdk_cfg_priv_opts != '\0') {
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(param_1 * 0x5a + 0x56 + iVar8);
      iVar8 = r_emi_get_mem_addr_by_offset(0x400);
      iVar17 = param_1 * 0x5a + 0x18;
      if ((((&g_event_empty)[param_1] == '\x01') && (uVar3 >> 8 == 0)) &&
         ((*(ushort *)(iVar8 + iVar17) >> 0xe & 1) == 0)) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(ushort *)(iVar8 + iVar17);
        iVar8 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar8 + iVar17) = uVar3 & 0xbfff | 0x4000;
      }
      else {
        (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar8 + iVar17) >> 0xe) & 1;
      }
    }
    uVar3 = *(ushort *)(iVar5 + 0x84);
    iVar8 = 5;
    if ((((uVar3 & 6) == 2) && ((uVar3 & 8) == 0)) && (iVar8 = 4, *(char *)(iVar5 + 0x46) == '\x01')
       ) {
      iVar8 = 5;
    }
    *(uint *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + *(int *)(iVar5 + 100) & 0xfffffff;
    *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
    if (param_2 == 0) {
      cVar13 = (&rwip_priority)[iVar8 * 2];
    }
    else {
      cVar13 = *(char *)(iVar8 * 2 + 0x16099) + *(char *)(iVar5 + 0x16);
    }
    *(char *)(iVar5 + 0x16) = cVar13;
    uVar12 = (int)(uint)uVar3 >> 8 & 1;
    iVar5 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar5 + 0x84);
    uVar18 = *(uint *)(iVar5 + 0x48);
    uVar11 = (uint)DAT_0001606a << 1;
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar5 + 0x16) = 0x1f;
    }
    if ((uVar3 & 3) == 3) {
      *(undefined1 *)(iVar5 + 0x96) = 0;
      if (((uVar12 != 0) && ((uVar3 & 0x4000) != 0)) &&
         ((uVar15 = (uint)*(ushort *)(iVar5 + 0x72), uVar15 != 0 &&
          ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar5 + 0x46) == '\0'))))
         )) {
        uVar18 = uVar15 * *(int *)(iVar5 + 100) + uVar18 & 0xfffffff;
        iVar8 = uVar15 + *(ushort *)(iVar5 + 0x7e);
        *(short *)(iVar5 + 0x7e) = (short)((uint)(iVar8 * 0x10000) >> 0x10);
        *(undefined1 *)(iVar5 + 0x96) = 1;
        r_ble_log_internal_x2(0x404300f4,(uint)*(ushort *)(iVar5 + 0x7c) | iVar8 * 0x10000,param_1);
      }
    }
    for (; (iVar7 - uVar18 & 0xfffffff) < 0x7ffffff;
        uVar18 = *(int *)(iVar5 + 100) + uVar18 & 0xfffffff) {
      *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
    }
    uVar15 = *(uint *)(iVar5 + 0x58);
    if ((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) {
      uVar16 = (uint)*(ushort *)(iVar5 + 0x7c) + (uint)*(ushort *)(iVar5 + 0x7e) & 0xffff;
      if ((uVar16 - *(ushort *)(iVar5 + 0x44) & 0xffff) < 0x7fff) {
        if (*(char *)(iVar5 + 0x42) == '\0') {
          uVar18 = *(ushort *)(iVar5 + 0x3c) + uVar18 & 0xfffffff;
          if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
            uVar18 = (*(ushort *)(iVar5 + 0x40) >> 1) + uVar18 & 0xfffffff;
          }
          *(undefined1 *)(iVar5 + 0x42) = 1;
          *(ushort *)(iVar5 + 0x72) = *(ushort *)(iVar5 + 0x3e);
          *(uint *)(iVar5 + 0x68) = *(uint *)(iVar5 + 0x38);
          *(uint *)(iVar5 + 100) = *(uint *)(iVar5 + 0x34);
          r_ble_log_internal_x3
                    (0x40a300f5,(uint)*(ushort *)(iVar5 + 0x44) | uVar16 << 0x10,
                     *(uint *)(iVar5 + 0x34) | (uint)*(ushort *)(iVar5 + 0x3e) << 0x10,
                     param_1 << 0x10 | *(uint *)(iVar5 + 0x38) |
                     (*(ushort *)(iVar5 + 0x84) & 1) << 0x18);
          if (((*(ushort *)(iVar5 + 0x84) & 1) == 0) ||
             (r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e)),
             (*(ushort *)(iVar5 + 0x84) & 1) == 0)) {
            *(undefined1 *)(iVar5 + 0x43) = 1;
          }
        }
        sVar14 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
        uVar15 = uVar18;
        while (sVar14 = sVar14 + -1, sVar14 != -1) {
          uVar15 = uVar15 - *(int *)(iVar5 + 100) & 0xfffffff;
        }
      }
    }
    if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
      uVar16 = *(int *)(iVar5 + 100) * 6;
    }
    else {
      uVar16 = *(uint *)(iVar5 + 0x68);
    }
    iVar7 = (param_1 + 0x10) * 2;
    iVar8 = 0;
    while (uVar19 = (undefined2)iVar8, (uVar18 - uVar15 & 0xfffffff) <= uVar16) {
      uVar10 = uVar18;
      if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
        iVar17 = *(int *)(iVar5 + 0x50);
        sVar14 = *(short *)(iVar5 + 0x6e);
        iVar8 = r_rwip_active_check();
        uVar11 = 0x14;
        if (iVar8 == 0) {
          uVar11 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar10 = ((*(ushort *)(iVar5 + 0x7a) + uVar11) * (uVar18 - iVar17 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar11 = uVar10 * 2;
        if (uVar12 != 0) {
          *(undefined2 *)(&DAT_00015804 + iVar7) = 0;
        }
        if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
          uVar11 = uVar11 + (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
_L244:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if ((*(ushort *)(iVar5 + 0x7c) < 7) &&
             ((uVar12 == 0 ||
              ((bVar4 = false, *(ushort *)(iVar5 + 0x7c) == 0 && (*(short *)(iVar5 + 0x98) == -1))))
             )) {
            uVar11 = uVar11 + ((int)((uint)*(ushort *)(&DAT_00015804 + iVar7) *
                                     (uint)*(ushort *)(iVar5 + 0x70) * 0x271) >> 1) +
                              (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
            uVar20 = *(int *)(iVar5 + 100) * 0x271;
            if (uVar20 < uVar11) {
              uVar11 = uVar20;
            }
            *(ushort *)(&DAT_00015804 + iVar7) = *(ushort *)(&DAT_00015804 + iVar7) + 1;
            goto _L244;
          }
        }
        if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x42) != '\0')) &&
           (*(char *)(iVar5 + 0x43) == '\0')) {
          uVar11 = uVar11 + (uint)*(ushort *)(iVar5 + 0x40) * 0x271;
        }
        else if ((!bVar4) && (((uint)(*(int *)(iVar5 + 100) * 0x271) >> 1) - 300 <= uVar10)) {
          r_ble_log_internal_x3(0x404300f6,(uint)*(ushort *)(iVar5 + 0x7c) | param_1 << 0x10);
        }
        uVar20 = (uVar11 >> 1) / 0x271;
        uVar10 = uVar18 - uVar20 & 0xfffffff;
        iVar8 = uVar20 * 0x271 + ((int)sVar14 - (uVar11 >> 1));
        if (iVar8 < 0) {
          uVar10 = uVar10 - 1 & 0xfffffff;
          iVar8 = iVar8 + 0x271;
        }
        *(int *)(iVar5 + 8) = iVar8;
        *(uint *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x5c) + uVar11;
      }
      uVar19 = (undefined2)iVar8;
      *(uint *)(iVar5 + 4) = uVar10;
      iVar17 = r_sch_arb_insert(iVar5);
      if (iVar17 == 0) {
        iVar7 = 1;
        goto _L191;
      }
      *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
      uVar18 = *(int *)(iVar5 + 100) + uVar18 & 0xfffffff;
      sVar14 = *(short *)(iVar5 + 0x7e);
      *(short *)(iVar5 + 0x7e) = sVar14 + 1;
      if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
         ((ushort)(((sVar14 + 1) - *(short *)(iVar5 + 0x44)) + *(short *)(iVar5 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar5 + 0x42) == '\0') {
          uVar18 = *(ushort *)(iVar5 + 0x3c) + uVar18 & 0xfffffff;
          if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
            uVar18 = (*(ushort *)(iVar5 + 0x40) >> 1) + uVar18 & 0xfffffff;
          }
          *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0x34);
          *(undefined2 *)(iVar5 + 0x72) = *(undefined2 *)(iVar5 + 0x3e);
          *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(iVar5 + 0x38);
          if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e));
          }
          *(undefined1 *)(iVar5 + 0x42) = 1;
          uVar16 = *(uint *)(iVar5 + 0x68);
          if ((*(ushort *)(iVar5 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar5 + 0x43) = 1;
          }
        }
        sVar14 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
        uVar15 = uVar18;
        while (sVar14 = sVar14 + -1, sVar14 != -1) {
          uVar15 = uVar15 - *(int *)(iVar5 + 100) & 0xfffffff;
        }
      }
    }
    iVar7 = 0;
_L191:
    r_ble_log_internal_x2(0x404300f7,*(undefined4 *)(iVar5 + 0x7c),iVar7 << 8 | param_1);
    if (iVar7 != 0) {
      *(undefined1 *)(iVar5 + 0x8f) = 0;
      *(uint *)(iVar5 + 0x48) = uVar18;
      if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
        uVar18 = (uint)DAT_0001606a;
        *(undefined2 *)(iVar5 + 0x6c) = uVar19;
        *(uint *)(iVar5 + 0x4c) = uVar18 * 2 + uVar11;
      }
      return;
    }
    r_ble_log_internal_x3
              (0x804300f8,(int)(uint)*(ushort *)(iVar5 + 0x84) >> 1 & 1,
               *(undefined4 *)(iVar5 + 0x7c),(uint)*(byte *)(iVar5 + 0x16) << 8 | param_1);
    uVar11 = 8;
    if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
      uVar11 = 0x3e;
    }
  }
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    return;
  }
  r_ble_log_internal_x3
            (0x4003010a,(int)(uint)*(ushort *)(iVar5 + 0x84) >> 1 & 1,
             (uint)*(ushort *)(iVar5 + 0x7c) | param_1 << 0x10 | 0x1000000,
             (uint)*(byte *)(iVar5 + 0x8f) << 8 | (uint)*(byte *)(iVar5 + 0x92) << 0x10 | uVar11);
  uVar18 = param_1 << 8 | 1;
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar18,0xff,1);
  *puVar6 = (char)uVar11;
  r_ke_msg_send();
  iVar7 = r_co_list_pop_front(iVar5 + 0x28);
  do {
    if (*(char *)(iVar5 + 0x92) == '\0') {
      if (*(int *)(iVar5 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar5 + 0x24) + 4));
      }
      while (iVar7 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar7 + 4));
        if (DAT_00016091 != '\0') {
          r_ke_msg_send_basic(0x20e,uVar18,0xff);
        }
        iVar7 = r_co_list_pop_front(iVar5 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar1 = *(byte *)(iVar5 + 0x8e);
    bVar2 = *(byte *)(iVar5 + 0x90);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar17 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar17 + 2 + iVar8);
    if ((uVar3 & 3) == 3) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar17 + 4 + iVar8));
      uVar9 = 0x89b;
      if (*(int *)(iVar5 + 0x24) != 0) goto _L165;
    }
    else {
      uVar9 = 0x8a4;
      if ((uVar3 & 3) == 0) {
_L165:
        r_assert_err(0,"lld_con.c",uVar9);
      }
    }
    *(char *)(iVar5 + 0x92) = *(char *)(iVar5 + 0x92) + -1;
    *(byte *)(iVar5 + 0x90) = *(char *)(iVar5 + 0x90) + 1U & 1;
  } while( true );
}

