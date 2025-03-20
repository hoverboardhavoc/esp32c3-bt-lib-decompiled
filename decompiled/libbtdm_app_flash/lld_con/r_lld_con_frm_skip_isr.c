/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010ccc) */
/* WARNING: Removing unreachable block (ram,0x00010cd2) */
/* WARNING: Removing unreachable block (ram,0x00010cde) */
/* WARNING: Removing unreachable block (ram,0x00010ce4) */
/* WARNING: Removing unreachable block (ram,0x00010ce6) */
/* WARNING: Removing unreachable block (ram,0x00010e56) */
/* WARNING: Removing unreachable block (ram,0x00010fdc) */
/* WARNING: Removing unreachable block (ram,0x00010fe0) */
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
  undefined1 uVar11;
  undefined4 uVar12;
  ushort uVar13;
  uint uVar14;
  short sVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_con.c",0xc51);
    return;
  }
  iVar10 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar6 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xc38);
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x8f) == '\x02') {
    uVar11 = 0x16;
  }
  else {
    param_1 = (uint)*(byte *)(iVar6 + 0x8e);
    *(uint *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + *(int *)(iVar6 + 100) & 0xfffffff;
    cVar5 = rwip_priority;
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + cVar5;
    iVar6 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar6 + 0x84);
    uVar18 = (uint)DAT_00015066 << 1;
    uVar7 = *(uint *)(iVar6 + 0x48);
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar6 + 0x16) = 0x1f;
    }
    if ((uVar3 & 3) == 3) {
      *(undefined1 *)(iVar6 + 0x96) = 0;
    }
    for (; (iVar10 - uVar7 & 0xfffffff) < 0x7ffffff;
        uVar7 = uVar7 + *(int *)(iVar6 + 100) & 0xfffffff) {
      *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    }
    uVar20 = *(uint *)(iVar6 + 0x58);
    if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar6 + 0x42) == '\0') {
        uVar7 = uVar7 + *(ushort *)(iVar6 + 0x3c) & 0xfffffff;
        if ((uVar3 & 1) != 0) {
          uVar7 = uVar7 + (*(ushort *)(iVar6 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x34);
        *(undefined2 *)(iVar6 + 0x72) = *(undefined2 *)(iVar6 + 0x3e);
        *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x38);
        *(undefined1 *)(iVar6 + 0x42) = 1;
        if (((uVar3 & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e)),
           (*(ushort *)(iVar6 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar6 + 0x43) = 1;
        }
      }
      sVar15 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
      uVar20 = uVar7;
      while (sVar15 = sVar15 + -1, sVar15 != -1) {
        uVar20 = uVar20 - *(int *)(iVar6 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      uVar19 = *(int *)(iVar6 + 100) * 6;
    }
    else {
      uVar19 = *(uint *)(iVar6 + 0x68);
    }
    iVar10 = (param_1 + 0x10) * 2;
    iVar9 = 0;
    while ((uVar7 - uVar20 & 0xfffffff) <= uVar19) {
      uVar17 = uVar7;
      if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
        iVar16 = *(int *)(iVar6 + 0x50);
        sVar15 = *(short *)(iVar6 + 0x6e);
        iVar9 = r_rwip_active_check();
        uVar18 = 0x14;
        if (iVar9 == 0) {
          uVar18 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar17 = ((*(ushort *)(iVar6 + 0x7a) + uVar18) * (uVar7 - iVar16 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar18 = uVar17 * 2;
        if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
          uVar18 = uVar18 + (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
_L235:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if (*(ushort *)(iVar6 + 0x7c) < 7) {
            uVar14 = ((int)((uint)*(ushort *)(&DAT_000149b8 + iVar10) *
                            (uint)*(ushort *)(iVar6 + 0x70) * 0x271) >> 1) +
                     (uint)*(ushort *)(iVar6 + 0x70) * 0x271 + uVar18;
            uVar18 = *(int *)(iVar6 + 100) * 0x271;
            if (uVar14 < uVar18) {
              uVar18 = uVar14;
            }
            *(ushort *)(&DAT_000149b8 + iVar10) = *(ushort *)(&DAT_000149b8 + iVar10) + 1;
            goto _L235;
          }
        }
        if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x42) != '\0')) &&
           (*(char *)(iVar6 + 0x43) == '\0')) {
          uVar18 = uVar18 + (uint)*(ushort *)(iVar6 + 0x40) * 0x271;
        }
        else if ((!bVar4) && (((uint)(*(int *)(iVar6 + 100) * 0x271) >> 1) - 300 <= uVar17)) break;
        uVar14 = (uVar18 >> 1) / 0x271;
        uVar17 = uVar7 - uVar14 & 0xfffffff;
        iVar9 = ((int)sVar15 - (uVar18 >> 1)) + uVar14 * 0x271;
        if (iVar9 < 0) {
          uVar17 = uVar17 - 1 & 0xfffffff;
          iVar9 = iVar9 + 0x271;
        }
        *(int *)(iVar6 + 8) = iVar9;
        *(uint *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x5c) + uVar18;
      }
      *(uint *)(iVar6 + 4) = uVar17;
      iVar16 = r_sch_arb_insert(iVar6);
      if (iVar16 == 0) {
        *(undefined1 *)(iVar6 + 0x8f) = 0;
        *(uint *)(iVar6 + 0x48) = uVar7;
        if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
          uVar7 = (uint)DAT_00015066;
          *(short *)(iVar6 + 0x6c) = (short)iVar9;
          *(uint *)(iVar6 + 0x4c) = uVar18 + uVar7 * 2;
        }
        return;
      }
      *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + rwip_priority;
      sVar15 = *(short *)(iVar6 + 0x7e);
      uVar7 = uVar7 + *(int *)(iVar6 + 100) & 0xfffffff;
      *(short *)(iVar6 + 0x7e) = sVar15 + 1;
      if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
         ((ushort)(((sVar15 + 1) - *(short *)(iVar6 + 0x44)) + *(short *)(iVar6 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar6 + 0x42) == '\0') {
          uVar7 = uVar7 + *(ushort *)(iVar6 + 0x3c) & 0xfffffff;
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            uVar7 = uVar7 + (*(ushort *)(iVar6 + 0x40) >> 1) & 0xfffffff;
          }
          *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar6 + 0x34);
          *(undefined2 *)(iVar6 + 0x72) = *(undefined2 *)(iVar6 + 0x3e);
          *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x38);
          if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar6 + 0x8e));
          }
          *(undefined1 *)(iVar6 + 0x42) = 1;
          uVar19 = *(uint *)(iVar6 + 0x68);
          if ((*(ushort *)(iVar6 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar6 + 0x43) = 1;
          }
        }
        sVar15 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
        uVar20 = uVar7;
        while (sVar15 = sVar15 + -1, sVar15 != -1) {
          uVar20 = uVar20 - *(int *)(iVar6 + 100) & 0xfffffff;
        }
      }
    }
    uVar11 = 8;
    if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
      uVar11 = 0x3e;
    }
  }
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    return;
  }
  uVar18 = param_1 << 8 | 1;
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x212,uVar18,0xff,1);
  *puVar8 = uVar11;
  r_ke_msg_send();
  iVar10 = r_co_list_pop_front(iVar6 + 0x28);
  do {
    if (*(char *)(iVar6 + 0x92) == '\0') {
      if (*(int *)(iVar6 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar6 + 0x24) + 4));
      }
      while (iVar10 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar10 + 4));
        if (DAT_0001508d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar18,0xff);
        }
        iVar10 = r_co_list_pop_front(iVar6 + 0x28);
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
    iVar16 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar9 + iVar16 + 2);
    uVar13 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L140:
      uVar12 = 0x795;
_L161:
      r_assert_err(0,"lld_con.c",uVar12);
    }
    else if (2 < uVar13) {
      if (uVar13 != 3) goto _L140;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar16 + 4 + iVar9));
      uVar12 = 0x78c;
      if (*(int *)(iVar6 + 0x24) == 0) goto _L141;
      goto _L161;
    }
_L141:
    *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + -1;
    *(byte *)(iVar6 + 0x90) = *(char *)(iVar6 + 0x90) + 1U & 1;
  } while( true );
}

