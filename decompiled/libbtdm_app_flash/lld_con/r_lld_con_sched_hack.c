/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched_hack(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined2 uVar16;
  int iVar17;
  uint uVar18;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar5 + 0x84);
  uVar6 = *(uint *)(iVar5 + 0x48);
  uVar14 = (uint)DAT_0001606a << 1;
  if ((uVar3 & 2) == 0) {
    *(undefined1 *)(iVar5 + 0x16) = 0x1f;
  }
  if ((uVar3 & 3) == 3) {
    *(undefined1 *)(iVar5 + 0x96) = 0;
    if (((((param_3 != 0) && ((uVar3 & 0x4000) != 0)) &&
         (uVar11 = (uint)*(ushort *)(iVar5 + 0x72), uVar11 != 0)) &&
        (((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)))) && (*(char *)(iVar5 + 0x46) == '\0')) {
      uVar6 = uVar11 * *(int *)(iVar5 + 100) + uVar6 & 0xfffffff;
      iVar12 = uVar11 + *(ushort *)(iVar5 + 0x7e);
      *(short *)(iVar5 + 0x7e) = (short)((uint)(iVar12 * 0x10000) >> 0x10);
      *(undefined1 *)(iVar5 + 0x96) = 1;
      r_ble_log_internal_x2(0x404300f4,(uint)*(ushort *)(iVar5 + 0x7c) | iVar12 * 0x10000,param_1);
    }
  }
  for (; (param_2 - uVar6 & 0xfffffff) < 0x7ffffff;
      uVar6 = *(int *)(iVar5 + 100) + uVar6 & 0xfffffff) {
    *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
  }
  uVar11 = *(uint *)(iVar5 + 0x58);
  if ((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) {
    uVar13 = (uint)*(ushort *)(iVar5 + 0x7c) + (uint)*(ushort *)(iVar5 + 0x7e) & 0xffff;
    if ((uVar13 - *(ushort *)(iVar5 + 0x44) & 0xffff) < 0x7fff) {
      if (*(char *)(iVar5 + 0x42) == '\0') {
        uVar6 = *(ushort *)(iVar5 + 0x3c) + uVar6 & 0xfffffff;
        if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
          uVar6 = (*(ushort *)(iVar5 + 0x40) >> 1) + uVar6 & 0xfffffff;
        }
        *(undefined1 *)(iVar5 + 0x42) = 1;
        *(ushort *)(iVar5 + 0x72) = *(ushort *)(iVar5 + 0x3e);
        *(uint *)(iVar5 + 0x68) = *(uint *)(iVar5 + 0x38);
        *(uint *)(iVar5 + 100) = *(uint *)(iVar5 + 0x34);
        r_ble_log_internal_x3
                  (0x40a300f5,(uint)*(ushort *)(iVar5 + 0x44) | uVar13 << 0x10,
                   *(uint *)(iVar5 + 0x34) | (uint)*(ushort *)(iVar5 + 0x3e) << 0x10,
                   param_1 << 0x10 | *(uint *)(iVar5 + 0x38) |
                   (*(ushort *)(iVar5 + 0x84) & 1) << 0x18);
        if (((*(ushort *)(iVar5 + 0x84) & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e)),
           (*(ushort *)(iVar5 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar5 + 0x43) = 1;
        }
      }
      sVar10 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
      uVar11 = uVar6;
      while (sVar10 = sVar10 + -1, sVar10 != -1) {
        uVar11 = uVar11 - *(int *)(iVar5 + 100) & 0xfffffff;
      }
    }
  }
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    uVar13 = *(int *)(iVar5 + 100) * 6;
  }
  else {
    uVar13 = *(uint *)(iVar5 + 0x68);
  }
  iVar12 = (param_1 + 0x10) * 2;
  iVar17 = 0;
  while (uVar16 = (undefined2)iVar17, (uVar6 - uVar11 & 0xfffffff) <= uVar13) {
    uVar9 = uVar6;
    if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
      iVar15 = *(int *)(iVar5 + 0x50);
      sVar10 = *(short *)(iVar5 + 0x6e);
      iVar17 = r_rwip_active_check();
      uVar14 = 0x14;
      if (iVar17 == 0) {
        uVar14 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar9 = ((*(ushort *)(iVar5 + 0x7a) + uVar14) * (uVar6 - iVar15 & 0xfffffff)) / 0x640 + 0x40;
      uVar14 = uVar9 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_0001564c + iVar12) = 0;
      }
      if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
        uVar14 = uVar14 + (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
_L240:
        bVar4 = true;
      }
      else {
        bVar4 = false;
        if ((*(ushort *)(iVar5 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar4 = false, *(ushort *)(iVar5 + 0x7c) == 0 && (*(short *)(iVar5 + 0x98) == -1))))))
        {
          uVar14 = uVar14 + ((int)((uint)*(ushort *)(&DAT_0001564c + iVar12) *
                                   (uint)*(ushort *)(iVar5 + 0x70) * 0x271) >> 1) +
                            (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
          uVar18 = *(int *)(iVar5 + 100) * 0x271;
          if (uVar18 < uVar14) {
            uVar14 = uVar18;
          }
          *(ushort *)(&DAT_0001564c + iVar12) = *(ushort *)(&DAT_0001564c + iVar12) + 1;
          goto _L240;
        }
      }
      if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x42) != '\0')) &&
         (*(char *)(iVar5 + 0x43) == '\0')) {
        uVar14 = uVar14 + (uint)*(ushort *)(iVar5 + 0x40) * 0x271;
      }
      else if ((!bVar4) && (((uint)(*(int *)(iVar5 + 100) * 0x271) >> 1) - 300 <= uVar9)) {
        r_ble_log_internal_x3(0x404300f6,(uint)*(ushort *)(iVar5 + 0x7c) | param_1 << 0x10);
      }
      uVar18 = (uVar14 >> 1) / 0x271;
      uVar9 = uVar6 - uVar18 & 0xfffffff;
      iVar17 = uVar18 * 0x271 + ((int)sVar10 - (uVar14 >> 1));
      if (iVar17 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar17 = iVar17 + 0x271;
      }
      *(int *)(iVar5 + 8) = iVar17;
      *(uint *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x5c) + uVar14;
    }
    uVar16 = (undefined2)iVar17;
    *(uint *)(iVar5 + 4) = uVar9;
    iVar15 = r_sch_arb_insert(iVar5);
    if (iVar15 == 0) {
      iVar12 = 1;
      goto _L187;
    }
    *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
    uVar6 = *(int *)(iVar5 + 100) + uVar6 & 0xfffffff;
    sVar10 = *(short *)(iVar5 + 0x7e);
    *(short *)(iVar5 + 0x7e) = sVar10 + 1;
    if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
       ((ushort)(((sVar10 + 1) - *(short *)(iVar5 + 0x44)) + *(short *)(iVar5 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar5 + 0x42) == '\0') {
        uVar6 = *(ushort *)(iVar5 + 0x3c) + uVar6 & 0xfffffff;
        if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
          uVar6 = (*(ushort *)(iVar5 + 0x40) >> 1) + uVar6 & 0xfffffff;
        }
        *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0x34);
        *(undefined2 *)(iVar5 + 0x72) = *(undefined2 *)(iVar5 + 0x3e);
        *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(iVar5 + 0x38);
        if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
          r_lld_con_max_lat_calc(*(undefined1 *)(iVar5 + 0x8e));
        }
        *(undefined1 *)(iVar5 + 0x42) = 1;
        uVar13 = *(uint *)(iVar5 + 0x68);
        if ((*(ushort *)(iVar5 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar5 + 0x43) = 1;
        }
      }
      sVar10 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
      uVar11 = uVar6;
      while (sVar10 = sVar10 + -1, sVar10 != -1) {
        uVar11 = uVar11 - *(int *)(iVar5 + 100) & 0xfffffff;
      }
    }
  }
  iVar12 = 0;
_L187:
  r_ble_log_internal_x2(0x404300f7,*(undefined4 *)(iVar5 + 0x7c),iVar12 << 8 | param_1);
  if (iVar12 != 0) {
    *(undefined1 *)(iVar5 + 0x8f) = 0;
    *(uint *)(iVar5 + 0x48) = uVar6;
    if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
      uVar6 = (uint)DAT_0001606a;
      *(undefined2 *)(iVar5 + 0x6c) = uVar16;
      *(uint *)(iVar5 + 0x4c) = uVar6 * 2 + uVar14;
    }
    return;
  }
  r_ble_log_internal_x3
            (0x804300f8,(int)(uint)*(ushort *)(iVar5 + 0x84) >> 1 & 1,*(undefined4 *)(iVar5 + 0x7c),
             (uint)*(byte *)(iVar5 + 0x16) << 8 | param_1);
  uVar14 = 8;
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    uVar14 = 0x3e;
  }
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    return;
  }
  r_ble_log_internal_x3
            (0x4003010a,(int)(uint)*(ushort *)(iVar5 + 0x84) >> 1 & 1,
             (uint)*(ushort *)(iVar5 + 0x7c) | param_1 << 0x10 | 0x1000000,
             (uint)*(byte *)(iVar5 + 0x8f) << 8 | (uint)*(byte *)(iVar5 + 0x92) << 0x10 | uVar14);
  uVar6 = param_1 << 8 | 1;
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x212,uVar6,0xff,1);
  *puVar7 = (char)uVar14;
  r_ke_msg_send();
  iVar12 = r_co_list_pop_front(iVar5 + 0x28);
  do {
    if (*(char *)(iVar5 + 0x92) == '\0') {
      if (*(int *)(iVar5 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar5 + 0x24) + 4));
      }
      while (iVar12 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar12 + 4));
        if (DAT_00016091 != '\0') {
          r_ke_msg_send_basic(0x20e,uVar6,0xff);
        }
        iVar12 = r_co_list_pop_front(iVar5 + 0x28);
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
    iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar15 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar15 + 2 + iVar17);
    if ((uVar3 & 3) == 3) {
      iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar15 + 4 + iVar17));
      uVar8 = 0x875;
      if (*(int *)(iVar5 + 0x24) != 0) goto _L161;
    }
    else {
      uVar8 = 0x87e;
      if ((uVar3 & 3) == 0) {
_L161:
        r_assert_err(0,"lld_con.c",uVar8);
      }
    }
    *(char *)(iVar5 + 0x92) = *(char *)(iVar5 + 0x92) + -1;
    *(byte *)(iVar5 + 0x90) = *(char *)(iVar5 + 0x90) + 1U & 1;
  } while( true );
}

