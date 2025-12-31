/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010d0e) */
/* WARNING: Removing unreachable block (ram,0x00010d14) */
/* WARNING: Removing unreachable block (ram,0x00010d20) */
/* WARNING: Removing unreachable block (ram,0x00010d24) */
/* WARNING: Removing unreachable block (ram,0x00010d26) */
/* WARNING: Removing unreachable block (ram,0x00010f30) */
/* WARNING: Removing unreachable block (ram,0x000110b4) */
/* WARNING: Removing unreachable block (ram,0x000110b8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  undefined2 uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_con.c",0xcb4);
    return;
  }
  iVar10 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar6 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xc9b);
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x8f) == '\x02') {
    iVar6 = 0x16;
  }
  else {
    bVar2 = *(byte *)(iVar6 + 0x8e);
    param_1 = (uint)bVar2;
    *(uint *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + *(int *)(iVar6 + 100) & 0xfffffff;
    cVar5 = rwip_priority;
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + cVar5;
    iVar9 = *(int *)(&lld_con_env + param_1 * 4);
    uVar7 = *(uint *)(iVar9 + 0x48);
    uVar15 = (uint)DAT_0001606a << 1;
    if ((*(ushort *)(iVar9 + 0x84) & 2) == 0) {
      *(undefined1 *)(iVar9 + 0x16) = 0x1f;
    }
    if ((*(ushort *)(iVar9 + 0x84) & 3) == 3) {
      *(undefined1 *)(iVar9 + 0x96) = 0;
    }
    for (; (iVar10 - uVar7 & 0xfffffff) < 0x7ffffff;
        uVar7 = *(int *)(iVar9 + 100) + uVar7 & 0xfffffff) {
      *(short *)(iVar9 + 0x7e) = *(short *)(iVar9 + 0x7e) + 1;
    }
    uVar19 = *(uint *)(iVar9 + 0x58);
    if (((*(char *)(iVar9 + 0x46) == '\x01') && (*(char *)(iVar9 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar9 + 0x7c) + *(short *)(iVar9 + 0x7e)) - *(short *)(iVar9 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar9 + 0x42) == '\0') {
        uVar7 = *(ushort *)(iVar9 + 0x3c) + uVar7 & 0xfffffff;
        if ((*(ushort *)(iVar9 + 0x84) & 1) != 0) {
          uVar7 = (*(ushort *)(iVar9 + 0x40) >> 1) + uVar7 & 0xfffffff;
        }
        *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar9 + 0x34);
        *(undefined2 *)(iVar9 + 0x72) = *(undefined2 *)(iVar9 + 0x3e);
        *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(iVar9 + 0x38);
        *(undefined1 *)(iVar9 + 0x42) = 1;
        if (((*(ushort *)(iVar9 + 0x84) & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar9 + 0x8e)),
           (*(ushort *)(iVar9 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar9 + 0x43) = 1;
        }
      }
      sVar13 = (*(short *)(iVar9 + 0x7c) + *(short *)(iVar9 + 0x7e)) - *(short *)(iVar9 + 0x44);
      uVar19 = uVar7;
      while (sVar13 = sVar13 + -1, sVar13 != -1) {
        uVar19 = uVar19 - *(int *)(iVar9 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar9 + 0x84) & 2) == 0) {
      uVar16 = *(int *)(iVar9 + 100) * 6;
    }
    else {
      uVar16 = *(uint *)(iVar9 + 0x68);
    }
    iVar6 = (param_1 + 0x10) * 2;
    iVar10 = 0;
    while (uVar17 = (undefined2)iVar10, (uVar7 - uVar19 & 0xfffffff) <= uVar16) {
      uVar12 = uVar7;
      if ((*(ushort *)(iVar9 + 0x84) & 1) != 0) {
        iVar14 = *(int *)(iVar9 + 0x50);
        sVar13 = *(short *)(iVar9 + 0x6e);
        iVar10 = r_rwip_active_check();
        uVar15 = 0x14;
        if (iVar10 == 0) {
          uVar15 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar12 = ((*(ushort *)(iVar9 + 0x7a) + uVar15) * (uVar7 - iVar14 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar15 = uVar12 * 2;
        if ((*(ushort *)(iVar9 + 0x84) & 2) == 0) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar9 + 0x70) * 0x271;
_L235:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if (*(ushort *)(iVar9 + 0x7c) < 7) {
            uVar15 = uVar15 + ((int)((uint)*(ushort *)(&DAT_00015078 + iVar6) *
                                     (uint)*(ushort *)(iVar9 + 0x70) * 0x271) >> 1) +
                              (uint)*(ushort *)(iVar9 + 0x70) * 0x271;
            uVar18 = *(int *)(iVar9 + 100) * 0x271;
            if (uVar18 < uVar15) {
              uVar15 = uVar18;
            }
            *(ushort *)(&DAT_00015078 + iVar6) = *(ushort *)(&DAT_00015078 + iVar6) + 1;
            goto _L235;
          }
        }
        if (((*(char *)(iVar9 + 0x46) == '\x01') && (*(char *)(iVar9 + 0x42) != '\0')) &&
           (*(char *)(iVar9 + 0x43) == '\0')) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar9 + 0x40) * 0x271;
        }
        else if ((!bVar4) && (((uint)(*(int *)(iVar9 + 100) * 0x271) >> 1) - 300 <= uVar12)) {
          r_ble_log_internal_x3(0x404300d8,(uint)CONCAT12(bVar2,*(undefined2 *)(iVar9 + 0x7c)));
        }
        uVar18 = (uVar15 >> 1) / 0x271;
        uVar12 = uVar7 - uVar18 & 0xfffffff;
        iVar10 = uVar18 * 0x271 + ((int)sVar13 - (uVar15 >> 1));
        if (iVar10 < 0) {
          uVar12 = uVar12 - 1 & 0xfffffff;
          iVar10 = iVar10 + 0x271;
        }
        *(int *)(iVar9 + 8) = iVar10;
        *(uint *)(iVar9 + 0x10) = *(int *)(iVar9 + 0x5c) + uVar15;
      }
      uVar17 = (undefined2)iVar10;
      *(uint *)(iVar9 + 4) = uVar12;
      iVar14 = r_sch_arb_insert(iVar9);
      if (iVar14 == 0) {
        iVar6 = 1;
        goto _L185;
      }
      *(char *)(iVar9 + 0x16) = *(char *)(iVar9 + 0x16) + rwip_priority;
      uVar7 = *(int *)(iVar9 + 100) + uVar7 & 0xfffffff;
      sVar13 = *(short *)(iVar9 + 0x7e);
      *(short *)(iVar9 + 0x7e) = sVar13 + 1;
      if (((*(char *)(iVar9 + 0x46) == '\x01') && (*(char *)(iVar9 + 0x43) == '\0')) &&
         ((ushort)(((sVar13 + 1) - *(short *)(iVar9 + 0x44)) + *(short *)(iVar9 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar9 + 0x42) == '\0') {
          uVar7 = *(ushort *)(iVar9 + 0x3c) + uVar7 & 0xfffffff;
          if ((*(ushort *)(iVar9 + 0x84) & 1) != 0) {
            uVar7 = (*(ushort *)(iVar9 + 0x40) >> 1) + uVar7 & 0xfffffff;
          }
          *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar9 + 0x34);
          *(undefined2 *)(iVar9 + 0x72) = *(undefined2 *)(iVar9 + 0x3e);
          *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(iVar9 + 0x38);
          if ((*(ushort *)(iVar9 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar9 + 0x8e));
          }
          *(undefined1 *)(iVar9 + 0x42) = 1;
          uVar16 = *(uint *)(iVar9 + 0x68);
          if ((*(ushort *)(iVar9 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar9 + 0x43) = 1;
          }
        }
        sVar13 = (*(short *)(iVar9 + 0x7c) + *(short *)(iVar9 + 0x7e)) - *(short *)(iVar9 + 0x44);
        uVar19 = uVar7;
        while (sVar13 = sVar13 + -1, sVar13 != -1) {
          uVar19 = uVar19 - *(int *)(iVar9 + 100) & 0xfffffff;
        }
      }
    }
    iVar6 = 0;
_L185:
    r_ble_log_internal_x2(0x404300d9,*(undefined4 *)(iVar9 + 0x7c),iVar6 << 8 | param_1);
    if (iVar6 != 0) {
      *(undefined1 *)(iVar9 + 0x8f) = 0;
      *(uint *)(iVar9 + 0x48) = uVar7;
      if ((*(ushort *)(iVar9 + 0x84) & 1) != 0) {
        uVar7 = (uint)DAT_0001606a;
        *(undefined2 *)(iVar9 + 0x6c) = uVar17;
        *(uint *)(iVar9 + 0x4c) = uVar7 * 2 + uVar15;
      }
      return;
    }
    iVar6 = 8;
    if ((*(ushort *)(iVar9 + 0x84) & 2) == 0) {
      iVar6 = 0x3e;
    }
  }
  iVar10 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar10 == 0) {
    return;
  }
  r_ble_log_internal_x1(0x400300e6,iVar6 << 0x10 | 0x100U | param_1);
  uVar15 = param_1 << 8 | 1;
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x212,uVar15,0xff,1);
  *puVar8 = (char)iVar6;
  r_ke_msg_send();
  iVar6 = r_co_list_pop_front(iVar10 + 0x28);
  do {
    if (*(char *)(iVar10 + 0x92) == '\0') {
      if (*(int *)(iVar10 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar10 + 0x24) + 4));
      }
      while (iVar6 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar6 + 4));
        if (DAT_00016091 != '\0') {
          r_ke_msg_send_basic(0x20e,uVar15,0xff);
        }
        iVar6 = r_co_list_pop_front(iVar10 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar2 = *(byte *)(iVar10 + 0x8e);
    bVar1 = *(byte *)(iVar10 + 0x90);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar14 = ((uint)bVar2 * 9 + (uint)bVar1 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar14 + 2 + iVar9);
    if ((uVar3 & 3) == 3) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar14 + 4 + iVar9));
      uVar11 = 0x7dc;
      if (*(int *)(iVar10 + 0x24) != 0) goto _L159;
    }
    else {
      uVar11 = 0x7e5;
      if ((uVar3 & 3) == 0) {
_L159:
        r_assert_err(0,"lld_con.c",uVar11);
      }
    }
    *(char *)(iVar10 + 0x92) = *(char *)(iVar10 + 0x92) + -1;
    *(byte *)(iVar10 + 0x90) = *(char *)(iVar10 + 0x90) + 1U & 1;
  } while( true );
}

