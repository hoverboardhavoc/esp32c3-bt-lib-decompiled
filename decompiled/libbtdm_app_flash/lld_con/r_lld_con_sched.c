/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  ushort uVar10;
  uint uVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar5 + 0x84);
  uVar16 = (uint)DAT_00015066 << 1;
  uVar6 = *(uint *)(iVar5 + 0x48);
  if ((uVar3 & 2) == 0) {
    *(undefined1 *)(iVar5 + 0x16) = 0x1f;
  }
  if (((uVar3 & 3) == 3) && (*(undefined1 *)(iVar5 + 0x96) = 0, param_3 != 0)) {
    uVar10 = *(ushort *)(iVar5 + 0x72);
    if ((uVar10 != 0) &&
       ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar5 + 0x46) == '\0')))) {
      uVar6 = uVar6 + (uint)uVar10 * *(int *)(iVar5 + 100) & 0xfffffff;
      *(ushort *)(iVar5 + 0x7e) = uVar10 + *(short *)(iVar5 + 0x7e);
      *(undefined1 *)(iVar5 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar6 & 0xfffffff) < 0x7ffffff;
      uVar6 = uVar6 + *(int *)(iVar5 + 100) & 0xfffffff) {
    *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
  }
  uVar19 = *(uint *)(iVar5 + 0x58);
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
    sVar12 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
    uVar19 = uVar6;
    while (sVar12 = sVar12 + -1, sVar12 != -1) {
      uVar19 = uVar19 - *(int *)(iVar5 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    uVar18 = *(int *)(iVar5 + 100) * 6;
  }
  else {
    uVar18 = *(uint *)(iVar5 + 0x68);
  }
  iVar13 = (param_1 + 0x10) * 2;
  iVar17 = 0;
  while ((uVar6 - uVar19 & 0xfffffff) <= uVar18) {
    uVar15 = uVar6;
    if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
      iVar14 = *(int *)(iVar5 + 0x50);
      sVar12 = *(short *)(iVar5 + 0x6e);
      iVar17 = r_rwip_active_check();
      uVar16 = 0x14;
      if (iVar17 == 0) {
        uVar16 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar15 = ((*(ushort *)(iVar5 + 0x7a) + uVar16) * (uVar6 - iVar14 & 0xfffffff)) / 0x640 + 0x40;
      uVar16 = uVar15 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_000149b8 + iVar13) = 0;
      }
      if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
        uVar16 = uVar16 + (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
_L235:
        bVar4 = true;
      }
      else {
        bVar4 = false;
        if ((*(ushort *)(iVar5 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar4 = false, *(ushort *)(iVar5 + 0x7c) == 0 && (*(short *)(iVar5 + 0x98) == -1))))))
        {
          uVar11 = ((int)((uint)*(ushort *)(&DAT_000149b8 + iVar13) *
                          (uint)*(ushort *)(iVar5 + 0x70) * 0x271) >> 1) +
                   (uint)*(ushort *)(iVar5 + 0x70) * 0x271 + uVar16;
          uVar16 = *(int *)(iVar5 + 100) * 0x271;
          if (uVar11 < uVar16) {
            uVar16 = uVar11;
          }
          *(ushort *)(&DAT_000149b8 + iVar13) = *(ushort *)(&DAT_000149b8 + iVar13) + 1;
          goto _L235;
        }
      }
      if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x42) != '\0')) &&
         (*(char *)(iVar5 + 0x43) == '\0')) {
        uVar16 = uVar16 + (uint)*(ushort *)(iVar5 + 0x40) * 0x271;
      }
      else if ((!bVar4) && (((uint)(*(int *)(iVar5 + 100) * 0x271) >> 1) - 300 <= uVar15)) break;
      uVar11 = (uVar16 >> 1) / 0x271;
      uVar15 = uVar6 - uVar11 & 0xfffffff;
      iVar17 = ((int)sVar12 - (uVar16 >> 1)) + uVar11 * 0x271;
      if (iVar17 < 0) {
        uVar15 = uVar15 - 1 & 0xfffffff;
        iVar17 = iVar17 + 0x271;
      }
      *(int *)(iVar5 + 8) = iVar17;
      *(uint *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x5c) + uVar16;
    }
    *(uint *)(iVar5 + 4) = uVar15;
    iVar14 = r_sch_arb_insert(iVar5);
    if (iVar14 == 0) {
      *(undefined1 *)(iVar5 + 0x8f) = 0;
      *(uint *)(iVar5 + 0x48) = uVar6;
      if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
        uVar6 = (uint)DAT_00015066;
        *(short *)(iVar5 + 0x6c) = (short)iVar17;
        *(uint *)(iVar5 + 0x4c) = uVar16 + uVar6 * 2;
      }
      return;
    }
    *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
    sVar12 = *(short *)(iVar5 + 0x7e);
    uVar6 = uVar6 + *(int *)(iVar5 + 100) & 0xfffffff;
    *(short *)(iVar5 + 0x7e) = sVar12 + 1;
    if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
       ((ushort)(((sVar12 + 1) - *(short *)(iVar5 + 0x44)) + *(short *)(iVar5 + 0x7c)) < 0x7fff)) {
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
        uVar18 = *(uint *)(iVar5 + 0x68);
        if ((*(ushort *)(iVar5 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar5 + 0x43) = 1;
        }
      }
      sVar12 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
      uVar19 = uVar6;
      while (sVar12 = sVar12 + -1, sVar12 != -1) {
        uVar19 = uVar19 - *(int *)(iVar5 + 100) & 0xfffffff;
      }
    }
  }
  uVar8 = 8;
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    uVar8 = 0x3e;
  }
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    return;
  }
  uVar16 = param_1 << 8 | 1;
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x212,uVar16,0xff,1);
  *puVar7 = uVar8;
  r_ke_msg_send();
  iVar13 = r_co_list_pop_front(iVar5 + 0x28);
  do {
    if (*(char *)(iVar5 + 0x92) == '\0') {
      if (*(int *)(iVar5 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar5 + 0x24) + 4));
      }
      while (iVar13 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar13 + 4));
        if (DAT_0001508d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar16,0xff);
        }
        iVar13 = r_co_list_pop_front(iVar5 + 0x28);
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
    iVar14 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar17 + iVar14 + 2);
    uVar10 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L140:
      uVar9 = 0x795;
_L161:
      r_assert_err(0,"lld_con.c",uVar9);
    }
    else if (2 < uVar10) {
      if (uVar10 != 3) goto _L140;
      iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar14 + 4 + iVar17));
      uVar9 = 0x78c;
      if (*(int *)(iVar5 + 0x24) == 0) goto _L141;
      goto _L161;
    }
_L141:
    *(char *)(iVar5 + 0x92) = *(char *)(iVar5 + 0x92) + -1;
    *(byte *)(iVar5 + 0x90) = *(char *)(iVar5 + 0x90) + 1U & 1;
  } while( true );
}

