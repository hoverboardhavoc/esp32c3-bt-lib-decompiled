/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010d48) */
/* WARNING: Removing unreachable block (ram,0x00010d4e) */
/* WARNING: Removing unreachable block (ram,0x00010d5a) */
/* WARNING: Removing unreachable block (ram,0x00010d60) */
/* WARNING: Removing unreachable block (ram,0x00010d62) */
/* WARNING: Removing unreachable block (ram,0x00010ed8) */
/* WARNING: Removing unreachable block (ram,0x0001105c) */
/* WARNING: Removing unreachable block (ram,0x00011060) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  uint uVar19;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    r_assert_err(0,"lld_con.c",0xc6c);
    return;
  }
  iVar9 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar5 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xc53);
  }
  r_sch_arb_remove(iVar5,1);
  if (*(char *)(iVar5 + 0x8f) == '\x02') {
    iVar5 = 0x16;
  }
  else {
    param_1 = (uint)*(byte *)(iVar5 + 0x8e);
    *(uint *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + *(int *)(iVar5 + 100) & 0xfffffff;
    cVar4 = rwip_priority;
    *(short *)(iVar5 + 0x7e) = *(short *)(iVar5 + 0x7e) + 1;
    *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + cVar4;
    iVar7 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar7 + 0x84);
    uVar15 = (uint)DAT_00016066 << 1;
    uVar6 = *(uint *)(iVar7 + 0x48);
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar7 + 0x16) = 0x1f;
    }
    if ((uVar3 & 3) == 3) {
      *(undefined1 *)(iVar7 + 0x96) = 0;
    }
    for (; (iVar9 - uVar6 & 0xfffffff) < 0x7ffffff;
        uVar6 = uVar6 + *(int *)(iVar7 + 100) & 0xfffffff) {
      *(short *)(iVar7 + 0x7e) = *(short *)(iVar7 + 0x7e) + 1;
    }
    uVar16 = *(uint *)(iVar7 + 0x58);
    if (((*(char *)(iVar7 + 0x46) == '\x01') && (*(char *)(iVar7 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar7 + 0x7c) + *(short *)(iVar7 + 0x7e)) - *(short *)(iVar7 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar7 + 0x42) == '\0') {
        uVar6 = uVar6 + *(ushort *)(iVar7 + 0x3c) & 0xfffffff;
        if ((uVar3 & 1) != 0) {
          uVar6 = uVar6 + (*(ushort *)(iVar7 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar7 + 100) = *(undefined4 *)(iVar7 + 0x34);
        *(undefined2 *)(iVar7 + 0x72) = *(undefined2 *)(iVar7 + 0x3e);
        *(undefined4 *)(iVar7 + 0x68) = *(undefined4 *)(iVar7 + 0x38);
        *(undefined1 *)(iVar7 + 0x42) = 1;
        if (((uVar3 & 1) == 0) ||
           (r_lld_con_max_lat_calc(*(undefined1 *)(iVar7 + 0x8e)),
           (*(ushort *)(iVar7 + 0x84) & 1) == 0)) {
          *(undefined1 *)(iVar7 + 0x43) = 1;
        }
      }
      sVar14 = (*(short *)(iVar7 + 0x7c) + *(short *)(iVar7 + 0x7e)) - *(short *)(iVar7 + 0x44);
      uVar16 = uVar6;
      while (sVar14 = sVar14 + -1, sVar14 != -1) {
        uVar16 = uVar16 - *(int *)(iVar7 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar7 + 0x84) & 2) == 0) {
      uVar19 = *(int *)(iVar7 + 100) * 6;
    }
    else {
      uVar19 = *(uint *)(iVar7 + 0x68);
    }
    iVar5 = (param_1 + 0x10) * 2;
    iVar9 = 0;
    while (sVar14 = (short)iVar9, (uVar6 - uVar16 & 0xfffffff) <= uVar19) {
      uVar17 = uVar6;
      if ((*(ushort *)(iVar7 + 0x84) & 1) != 0) {
        iVar13 = *(int *)(iVar7 + 0x50);
        sVar14 = *(short *)(iVar7 + 0x6e);
        iVar9 = r_rwip_active_check();
        uVar15 = 0x14;
        if (iVar9 == 0) {
          uVar15 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar17 = ((*(ushort *)(iVar7 + 0x7a) + uVar15) * (uVar6 - iVar13 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar15 = uVar17 * 2;
        if ((*(ushort *)(iVar7 + 0x84) & 2) == 0) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar7 + 0x70) * 0x271;
_L248:
          bVar18 = true;
        }
        else {
          bVar18 = false;
          if (*(ushort *)(iVar7 + 0x7c) < 7) {
            uVar11 = ((int)((uint)*(ushort *)(&DAT_0001502c + iVar5) *
                            (uint)*(ushort *)(iVar7 + 0x70) * 0x271) >> 1) +
                     (uint)*(ushort *)(iVar7 + 0x70) * 0x271 + uVar15;
            uVar15 = *(int *)(iVar7 + 100) * 0x271;
            if (uVar11 < uVar15) {
              uVar15 = uVar11;
            }
            *(ushort *)(&DAT_0001502c + iVar5) = *(ushort *)(&DAT_0001502c + iVar5) + 1;
            goto _L248;
          }
        }
        if (((*(char *)(iVar7 + 0x46) == '\x01') && (*(char *)(iVar7 + 0x42) != '\0')) &&
           (*(char *)(iVar7 + 0x43) == '\0')) {
          uVar15 = uVar15 + (uint)*(ushort *)(iVar7 + 0x40) * 0x271;
        }
        else if ((!bVar18) && (((uint)(*(int *)(iVar7 + 100) * 0x271) >> 1) - 300 <= uVar17)) {
          iVar9 = r_sdk_config_get_opts_ext();
          iVar5 = 0;
          if (((*(uint *)(iVar9 + 0x28) & 0x20) != 0) &&
             (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
            r_ble_log_internal_x3
                      (0x4043000f,(uint)*(ushort *)(iVar7 + 0x7c) << 0x10 | param_1,
                       *(undefined4 *)(iVar7 + 100),uVar17);
          }
          goto _L191;
        }
        uVar11 = (uVar15 >> 1) / 0x271;
        uVar17 = uVar6 - uVar11 & 0xfffffff;
        iVar9 = ((int)sVar14 - (uVar15 >> 1)) + uVar11 * 0x271;
        if (iVar9 < 0) {
          uVar17 = uVar17 - 1 & 0xfffffff;
          iVar9 = iVar9 + 0x271;
        }
        *(int *)(iVar7 + 8) = iVar9;
        *(uint *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x5c) + uVar15;
      }
      sVar14 = (short)iVar9;
      *(uint *)(iVar7 + 4) = uVar17;
      iVar13 = r_sch_arb_insert(iVar7);
      if (iVar13 == 0) {
        iVar5 = 1;
        goto _L191;
      }
      *(char *)(iVar7 + 0x16) = *(char *)(iVar7 + 0x16) + rwip_priority;
      sVar14 = *(short *)(iVar7 + 0x7e);
      uVar6 = uVar6 + *(int *)(iVar7 + 100) & 0xfffffff;
      *(short *)(iVar7 + 0x7e) = sVar14 + 1;
      if (((*(char *)(iVar7 + 0x46) == '\x01') && (*(char *)(iVar7 + 0x43) == '\0')) &&
         ((ushort)(((sVar14 + 1) - *(short *)(iVar7 + 0x44)) + *(short *)(iVar7 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar7 + 0x42) == '\0') {
          uVar6 = uVar6 + *(ushort *)(iVar7 + 0x3c) & 0xfffffff;
          if ((*(ushort *)(iVar7 + 0x84) & 1) != 0) {
            uVar6 = uVar6 + (*(ushort *)(iVar7 + 0x40) >> 1) & 0xfffffff;
          }
          *(undefined4 *)(iVar7 + 100) = *(undefined4 *)(iVar7 + 0x34);
          *(undefined2 *)(iVar7 + 0x72) = *(undefined2 *)(iVar7 + 0x3e);
          *(undefined4 *)(iVar7 + 0x68) = *(undefined4 *)(iVar7 + 0x38);
          if ((*(ushort *)(iVar7 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar7 + 0x8e));
          }
          *(undefined1 *)(iVar7 + 0x42) = 1;
          uVar19 = *(uint *)(iVar7 + 0x68);
          if ((*(ushort *)(iVar7 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar7 + 0x43) = 1;
          }
        }
        sVar14 = (*(short *)(iVar7 + 0x7c) + *(short *)(iVar7 + 0x7e)) - *(short *)(iVar7 + 0x44);
        uVar16 = uVar6;
        while (sVar14 = sVar14 + -1, sVar14 != -1) {
          uVar16 = uVar16 - *(int *)(iVar7 + 100) & 0xfffffff;
        }
      }
    }
    iVar5 = 0;
_L191:
    iVar9 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar9 + 0x28) & 0x20) != 0) &&
       (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x4043000d,iVar5 << 8 | param_1,*(undefined4 *)(iVar7 + 0x7c));
    }
    if (iVar5 != 0) {
      *(undefined1 *)(iVar7 + 0x8f) = 0;
      *(uint *)(iVar7 + 0x48) = uVar6;
      if ((*(ushort *)(iVar7 + 0x84) & 1) != 0) {
        uVar6 = (uint)DAT_00016066;
        *(short *)(iVar7 + 0x6c) = sVar14;
        *(uint *)(iVar7 + 0x4c) = uVar15 + uVar6 * 2;
      }
      return;
    }
    iVar5 = 8;
    if ((*(ushort *)(iVar7 + 0x84) & 2) == 0) {
      iVar5 = 0x3e;
    }
  }
  iVar9 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar9 == 0) {
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar5 << 0x10 | 0x100U | param_1);
  }
  uVar15 = param_1 << 8 | 1;
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x212,uVar15,0xff,1);
  *puVar8 = (char)iVar5;
  r_ke_msg_send();
  iVar5 = r_co_list_pop_front(iVar9 + 0x28);
  do {
    if (*(char *)(iVar9 + 0x92) == '\0') {
      if (*(int *)(iVar9 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar9 + 0x24) + 4));
      }
      while (iVar5 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar5 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar15,0xff);
        }
        iVar5 = r_co_list_pop_front(iVar9 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar1 = *(byte *)(iVar9 + 0x8e);
    bVar2 = *(byte *)(iVar9 + 0x90);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar13 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar7 + iVar13 + 2);
    uVar12 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L146:
      uVar10 = 0x7a8;
_L167:
      r_assert_err(0,"lld_con.c",uVar10);
    }
    else if (2 < uVar12) {
      if (uVar12 != 3) goto _L146;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar13 + 4 + iVar7));
      uVar10 = 0x79f;
      if (*(int *)(iVar9 + 0x24) == 0) goto _L147;
      goto _L167;
    }
_L147:
    *(char *)(iVar9 + 0x92) = *(char *)(iVar9 + 0x92) + -1;
    *(byte *)(iVar9 + 0x90) = *(char *)(iVar9 + 0x90) + 1U & 1;
  } while( true );
}

