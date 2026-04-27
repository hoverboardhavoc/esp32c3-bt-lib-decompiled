/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010d40) */
/* WARNING: Removing unreachable block (ram,0x00010d46) */
/* WARNING: Removing unreachable block (ram,0x00010d4c) */
/* WARNING: Removing unreachable block (ram,0x00010d58) */
/* WARNING: Removing unreachable block (ram,0x00010d5c) */
/* WARNING: Removing unreachable block (ram,0x00010d5e) */
/* WARNING: Removing unreachable block (ram,0x00010fa6) */
/* WARNING: Removing unreachable block (ram,0x0001112a) */
/* WARNING: Removing unreachable block (ram,0x0001112e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined2 uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_con.c",0xdb8);
    return;
  }
  iVar9 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar6 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xd9e);
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x8f) == '\x02') {
    r_ble_log_internal_x1(0x40030112,param_1);
    uVar15 = 0x16;
  }
  else {
    bVar2 = *(byte *)(iVar6 + 0x8e);
    param_1 = (uint)bVar2;
    *(uint *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + *(int *)(iVar6 + 100) & 0xfffffff;
    cVar5 = rwip_priority;
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + cVar5;
    iVar6 = *(int *)(&lld_con_env + param_1 * 4);
    uVar16 = *(uint *)(iVar6 + 0x48);
    uVar15 = (uint)DAT_0001606a << 1;
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      *(undefined1 *)(iVar6 + 0x16) = 0x1f;
    }
    if ((*(ushort *)(iVar6 + 0x84) & 3) == 3) {
      *(undefined1 *)(iVar6 + 0x96) = 0;
    }
    for (; (iVar9 - uVar16 & 0xfffffff) < 0x7ffffff;
        uVar16 = *(int *)(iVar6 + 100) + uVar16 & 0xfffffff) {
      *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    }
    uVar19 = *(uint *)(iVar6 + 0x58);
    if ((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) {
      uVar14 = (uint)*(ushort *)(iVar6 + 0x7c) + (uint)*(ushort *)(iVar6 + 0x7e) & 0xffff;
      if ((uVar14 - *(ushort *)(iVar6 + 0x44) & 0xffff) < 0x7fff) {
        if (*(char *)(iVar6 + 0x42) == '\0') {
          uVar16 = *(ushort *)(iVar6 + 0x3c) + uVar16 & 0xfffffff;
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            uVar16 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar16 & 0xfffffff;
          }
          *(undefined1 *)(iVar6 + 0x42) = 1;
          *(ushort *)(iVar6 + 0x72) = *(ushort *)(iVar6 + 0x3e);
          *(uint *)(iVar6 + 0x68) = *(uint *)(iVar6 + 0x38);
          *(uint *)(iVar6 + 100) = *(uint *)(iVar6 + 0x34);
          r_ble_log_internal_x3
                    (0x40a300f5,(uint)*(ushort *)(iVar6 + 0x44) | uVar14 << 0x10,
                     *(uint *)(iVar6 + 0x34) | (uint)*(ushort *)(iVar6 + 0x3e) << 0x10,
                     param_1 << 0x10 | *(uint *)(iVar6 + 0x38) |
                     (*(ushort *)(iVar6 + 0x84) & 1) << 0x18);
          if (((*(ushort *)(iVar6 + 0x84) & 1) == 0) ||
             (r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e)),
             (*(ushort *)(iVar6 + 0x84) & 1) == 0)) {
            *(undefined1 *)(iVar6 + 0x43) = 1;
          }
        }
        sVar13 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
        uVar19 = uVar16;
        while (sVar13 = sVar13 + -1, sVar13 != -1) {
          uVar19 = uVar19 - *(int *)(iVar6 + 100) & 0xfffffff;
        }
      }
    }
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      uVar14 = *(int *)(iVar6 + 100) * 6;
    }
    else {
      uVar14 = *(uint *)(iVar6 + 0x68);
    }
    iVar9 = (param_1 + 0x10) * 2;
    iVar8 = 0;
    while (uVar17 = (undefined2)iVar8, (uVar16 - uVar19 & 0xfffffff) <= uVar14) {
      uVar11 = uVar16;
      if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
        iVar12 = *(int *)(iVar6 + 0x50);
        sVar13 = *(short *)(iVar6 + 0x6e);
        iVar8 = r_rwip_active_check();
        uVar15 = 0x14;
        if (iVar8 == 0) {
          uVar15 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar11 = ((*(ushort *)(iVar6 + 0x7a) + uVar15) * (uVar16 - iVar12 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar15 = uVar11 * 2;
        if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
_L240:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if (*(ushort *)(iVar6 + 0x7c) < 7) {
            uVar15 = uVar15 + ((int)((uint)*(ushort *)(&DAT_0001564c + iVar9) *
                                     (uint)*(ushort *)(iVar6 + 0x70) * 0x271) >> 1) +
                              (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
            uVar18 = *(int *)(iVar6 + 100) * 0x271;
            if (uVar18 < uVar15) {
              uVar15 = uVar18;
            }
            *(ushort *)(&DAT_0001564c + iVar9) = *(ushort *)(&DAT_0001564c + iVar9) + 1;
            goto _L240;
          }
        }
        if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x42) != '\0')) &&
           (*(char *)(iVar6 + 0x43) == '\0')) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar6 + 0x40) * 0x271;
        }
        else if ((!bVar4) && (((uint)(*(int *)(iVar6 + 100) * 0x271) >> 1) - 300 <= uVar11)) {
          r_ble_log_internal_x3(0x404300f6,(uint)CONCAT12(bVar2,*(undefined2 *)(iVar6 + 0x7c)));
        }
        uVar18 = (uVar15 >> 1) / 0x271;
        uVar11 = uVar16 - uVar18 & 0xfffffff;
        iVar8 = uVar18 * 0x271 + ((int)sVar13 - (uVar15 >> 1));
        if (iVar8 < 0) {
          uVar11 = uVar11 - 1 & 0xfffffff;
          iVar8 = iVar8 + 0x271;
        }
        *(int *)(iVar6 + 8) = iVar8;
        *(uint *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x5c) + uVar15;
      }
      uVar17 = (undefined2)iVar8;
      *(uint *)(iVar6 + 4) = uVar11;
      iVar12 = r_sch_arb_insert(iVar6);
      if (iVar12 == 0) {
        iVar9 = 1;
        goto _L187;
      }
      *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + rwip_priority;
      uVar16 = *(int *)(iVar6 + 100) + uVar16 & 0xfffffff;
      sVar13 = *(short *)(iVar6 + 0x7e);
      *(short *)(iVar6 + 0x7e) = sVar13 + 1;
      if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
         ((ushort)(((sVar13 + 1) - *(short *)(iVar6 + 0x44)) + *(short *)(iVar6 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar6 + 0x42) == '\0') {
          uVar16 = *(ushort *)(iVar6 + 0x3c) + uVar16 & 0xfffffff;
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            uVar16 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar16 & 0xfffffff;
          }
          *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x34);
          *(undefined2 *)(iVar6 + 0x72) = *(undefined2 *)(iVar6 + 0x3e);
          *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x38);
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e));
          }
          *(undefined1 *)(iVar6 + 0x42) = 1;
          uVar14 = *(uint *)(iVar6 + 0x68);
          if ((*(ushort *)(iVar6 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar6 + 0x43) = 1;
          }
        }
        sVar13 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
        uVar19 = uVar16;
        while (sVar13 = sVar13 + -1, sVar13 != -1) {
          uVar19 = uVar19 - *(int *)(iVar6 + 100) & 0xfffffff;
        }
      }
    }
    iVar9 = 0;
_L187:
    r_ble_log_internal_x2(0x404300f7,*(undefined4 *)(iVar6 + 0x7c),iVar9 << 8 | param_1);
    if (iVar9 != 0) {
      *(undefined1 *)(iVar6 + 0x8f) = 0;
      *(uint *)(iVar6 + 0x48) = uVar16;
      if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
        uVar16 = (uint)DAT_0001606a;
        *(undefined2 *)(iVar6 + 0x6c) = uVar17;
        *(uint *)(iVar6 + 0x4c) = uVar16 * 2 + uVar15;
      }
      return;
    }
    r_ble_log_internal_x3
              (0x804300f8,(int)(uint)*(ushort *)(iVar6 + 0x84) >> 1 & 1,
               *(undefined4 *)(iVar6 + 0x7c),CONCAT11(*(undefined1 *)(iVar6 + 0x16),bVar2));
    uVar15 = 8;
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      uVar15 = 0x3e;
    }
  }
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    return;
  }
  r_ble_log_internal_x3
            (0x4003010a,(int)(uint)*(ushort *)(iVar6 + 0x84) >> 1 & 1,
             (uint)*(ushort *)(iVar6 + 0x7c) | param_1 << 0x10 | 0x1000000,
             (uint)*(byte *)(iVar6 + 0x8f) << 8 | (uint)*(byte *)(iVar6 + 0x92) << 0x10 | uVar15);
  uVar16 = param_1 << 8 | 1;
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x212,uVar16,0xff,1);
  *puVar7 = (char)uVar15;
  r_ke_msg_send();
  iVar9 = r_co_list_pop_front(iVar6 + 0x28);
  do {
    if (*(char *)(iVar6 + 0x92) == '\0') {
      if (*(int *)(iVar6 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar6 + 0x24) + 4));
      }
      while (iVar9 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar9 + 4));
        if (DAT_00016091 != '\0') {
          r_ke_msg_send_basic(0x20e,uVar16,0xff);
        }
        iVar9 = r_co_list_pop_front(iVar6 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar2 = *(byte *)(iVar6 + 0x8e);
    bVar1 = *(byte *)(iVar6 + 0x90);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar12 = ((uint)bVar2 * 9 + (uint)bVar1 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar12 + 2 + iVar8);
    if ((uVar3 & 3) == 3) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar12 + 4 + iVar8));
      uVar10 = 0x875;
      if (*(int *)(iVar6 + 0x24) != 0) goto _L161;
    }
    else {
      uVar10 = 0x87e;
      if ((uVar3 & 3) == 0) {
_L161:
        r_assert_err(0,"lld_con.c",uVar10);
      }
    }
    *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + -1;
    *(byte *)(iVar6 + 0x90) = *(char *)(iVar6 + 0x90) + 1U & 1;
  } while( true );
}

