/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 uVar11;
  undefined4 uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  char cVar16;
  short sVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    r_assert_err(0,"lld_con.c",0xbec);
    return;
  }
  r_sch_arb_remove(iVar5,1);
  if (*(char *)(iVar5 + 0x8f) == '\x02') {
    uVar11 = 0x3d;
    if ((*(ushort *)(iVar5 + 0x84) & 0x80) == 0) {
      uVar11 = 0x16;
    }
  }
  else {
    iVar8 = r_lld_read_clock();
    if (sdk_cfg_priv_opts != '\0') {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar9 + param_1 * 0x5a + 0x56);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      iVar9 = param_1 * 0x5a + 0x18;
      if ((((&g_event_empty)[param_1] == '\x01') && (uVar3 >> 8 == 0)) &&
         ((*(ushort *)(iVar10 + iVar9) >> 0xe & 1) == 0)) {
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(ushort *)(iVar10 + iVar9);
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar10) = uVar3 & 0xbfff | 0x4000;
      }
      else {
        (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar10 + iVar9) >> 0xe) & 1;
      }
    }
    uVar3 = *(ushort *)(iVar5 + 0x84);
    iVar9 = 5;
    if ((((uVar3 & 6) == 2) && ((uVar3 & 8) == 0)) && (iVar9 = 4, *(char *)(iVar5 + 0x46) == '\x01')
       ) {
      iVar9 = 5;
    }
    *(uint *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + *(int *)(iVar5 + 100) & 0xfffffff;
    *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
    if (param_2 == 0) {
      cVar16 = (&rwip_priority)[iVar9 * 2];
    }
    else {
      cVar16 = *(char *)(iVar9 * 2 + 0x15091) + *(char *)(iVar5 + 0x16);
    }
    *(char *)(iVar5 + 0x16) = cVar16;
    uVar13 = (int)(uint)uVar3 >> 8 & 1;
    iVar5 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar5 + 0x84);
    uVar19 = (uint)DAT_00015066 << 1;
    uVar6 = *(uint *)(iVar5 + 0x48);
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar5 + 0x16) = 0x1f;
    }
    if (((uVar3 & 3) == 3) && (*(undefined1 *)(iVar5 + 0x96) = 0, uVar13 != 0)) {
      uVar14 = *(ushort *)(iVar5 + 0x72);
      if ((uVar14 != 0) &&
         ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar5 + 0x46) == '\0'))))
      {
        uVar6 = uVar6 + (uint)uVar14 * *(int *)(iVar5 + 100) & 0xfffffff;
        *(ushort *)(iVar5 + 0x7e) = uVar14 + *(short *)(iVar5 + 0x7e);
        *(undefined1 *)(iVar5 + 0x96) = 1;
      }
    }
    for (; (iVar8 - uVar6 & 0xfffffff) < 0x7ffffff;
        uVar6 = uVar6 + *(int *)(iVar5 + 100) & 0xfffffff) {
      *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
    }
    uVar21 = *(uint *)(iVar5 + 0x58);
    if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar5 + 0x42) == '\0') {
        uVar6 = uVar6 + *(ushort *)(iVar5 + 0x3c) & 0xfffffff;
        if ((uVar3 & 1) != 0) {
          uVar6 = uVar6 + (*(ushort *)(iVar5 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0x34);
        *(undefined2 *)(iVar5 + 0x72) = *(undefined2 *)(iVar5 + 0x3e);
        *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(iVar5 + 0x38);
        *(undefined1 *)(iVar5 + 0x42) = 1;
        if (((uVar3 & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e)),
           (*(ushort *)(iVar5 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar5 + 0x43) = 1;
        }
      }
      sVar17 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
      uVar21 = uVar6;
      while (sVar17 = sVar17 + -1, sVar17 != -1) {
        uVar21 = uVar21 - *(int *)(iVar5 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
      uVar20 = *(int *)(iVar5 + 100) * 6;
    }
    else {
      uVar20 = *(uint *)(iVar5 + 0x68);
    }
    iVar8 = (param_1 + 0x10) * 2;
    iVar9 = 0;
    while ((uVar6 - uVar21 & 0xfffffff) <= uVar20) {
      uVar18 = uVar6;
      if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
        iVar10 = *(int *)(iVar5 + 0x50);
        sVar17 = *(short *)(iVar5 + 0x6e);
        iVar9 = r_rwip_active_check();
        uVar19 = 0x14;
        if (iVar9 == 0) {
          uVar19 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar18 = ((*(ushort *)(iVar5 + 0x7a) + uVar19) * (uVar6 - iVar10 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar19 = uVar18 * 2;
        if (uVar13 != 0) {
          *(undefined2 *)(&DAT_000149b8 + iVar8) = 0;
        }
        if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
          uVar19 = uVar19 + (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
_L235:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if ((*(ushort *)(iVar5 + 0x7c) < 7) &&
             ((uVar13 == 0 ||
              ((bVar4 = false, *(ushort *)(iVar5 + 0x7c) == 0 && (*(short *)(iVar5 + 0x98) == -1))))
             )) {
            uVar15 = ((int)((uint)*(ushort *)(&DAT_000149b8 + iVar8) *
                            (uint)*(ushort *)(iVar5 + 0x70) * 0x271) >> 1) +
                     (uint)*(ushort *)(iVar5 + 0x70) * 0x271 + uVar19;
            uVar19 = *(int *)(iVar5 + 100) * 0x271;
            if (uVar15 < uVar19) {
              uVar19 = uVar15;
            }
            *(ushort *)(&DAT_000149b8 + iVar8) = *(ushort *)(&DAT_000149b8 + iVar8) + 1;
            goto _L235;
          }
        }
        if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x42) != '\0')) &&
           (*(char *)(iVar5 + 0x43) == '\0')) {
          uVar19 = uVar19 + (uint)*(ushort *)(iVar5 + 0x40) * 0x271;
        }
        else if ((!bVar4) && (((uint)(*(int *)(iVar5 + 100) * 0x271) >> 1) - 300 <= uVar18)) break;
        uVar15 = (uVar19 >> 1) / 0x271;
        uVar18 = uVar6 - uVar15 & 0xfffffff;
        iVar9 = ((int)sVar17 - (uVar19 >> 1)) + uVar15 * 0x271;
        if (iVar9 < 0) {
          uVar18 = uVar18 - 1 & 0xfffffff;
          iVar9 = iVar9 + 0x271;
        }
        *(int *)(iVar5 + 8) = iVar9;
        *(uint *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x5c) + uVar19;
      }
      *(uint *)(iVar5 + 4) = uVar18;
      iVar10 = r_sch_arb_insert(iVar5);
      if (iVar10 == 0) {
        *(undefined1 *)(iVar5 + 0x8f) = 0;
        *(uint *)(iVar5 + 0x48) = uVar6;
        if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
          uVar6 = (uint)DAT_00015066;
          *(short *)(iVar5 + 0x6c) = (short)iVar9;
          *(uint *)(iVar5 + 0x4c) = uVar19 + uVar6 * 2;
        }
        return;
      }
      *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
      sVar17 = *(short *)(iVar5 + 0x7e);
      uVar6 = uVar6 + *(int *)(iVar5 + 100) & 0xfffffff;
      *(short *)(iVar5 + 0x7e) = sVar17 + 1;
      if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
         ((ushort)(((sVar17 + 1) - *(short *)(iVar5 + 0x44)) + *(short *)(iVar5 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar5 + 0x42) == '\0') {
          uVar6 = uVar6 + *(ushort *)(iVar5 + 0x3c) & 0xfffffff;
          if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
            uVar6 = uVar6 + (*(ushort *)(iVar5 + 0x40) >> 1) & 0xfffffff;
          }
          *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0x34);
          *(undefined2 *)(iVar5 + 0x72) = *(undefined2 *)(iVar5 + 0x3e);
          *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(iVar5 + 0x38);
          if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e));
          }
          *(undefined1 *)(iVar5 + 0x42) = 1;
          uVar20 = *(uint *)(iVar5 + 0x68);
          if ((*(ushort *)(iVar5 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar5 + 0x43) = 1;
          }
        }
        sVar17 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
        uVar21 = uVar6;
        while (sVar17 = sVar17 + -1, sVar17 != -1) {
          uVar21 = uVar21 - *(int *)(iVar5 + 100) & 0xfffffff;
        }
      }
    }
    uVar11 = 8;
    if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
      uVar11 = 0x3e;
    }
  }
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    return;
  }
  uVar19 = param_1 << 8 | 1;
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x212,uVar19,0xff,1);
  *puVar7 = uVar11;
  r_ke_msg_send();
  iVar8 = r_co_list_pop_front(iVar5 + 0x28);
  do {
    if (*(char *)(iVar5 + 0x92) == '\0') {
      if (*(int *)(iVar5 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar5 + 0x24) + 4));
      }
      while (iVar8 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar8 + 4));
        if (DAT_0001508d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar19,0xff);
        }
        iVar8 = r_co_list_pop_front(iVar5 + 0x28);
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
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar10 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar9 + iVar10 + 2);
    uVar14 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L140:
      uVar12 = 0x795;
_L161:
      r_assert_err(0,"lld_con.c",uVar12);
    }
    else if (2 < uVar14) {
      if (uVar14 != 3) goto _L140;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar10 + 4 + iVar9));
      uVar12 = 0x78c;
      if (*(int *)(iVar5 + 0x24) == 0) goto _L141;
      goto _L161;
    }
_L141:
    *(char *)(iVar5 + 0x92) = *(char *)(iVar5 + 0x92) + -1;
    *(byte *)(iVar5 + 0x90) = *(char *)(iVar5 + 0x90) + 1U & 1;
  } while( true );
}

