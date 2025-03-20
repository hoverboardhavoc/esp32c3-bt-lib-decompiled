/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_canceled_cbk
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

void r_lld_con_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  short sVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  bool bVar19;
  uint uVar20;
  
  if (param_1 == 0) {
    r_assert_err("lld_con.c",0xbba);
    return;
  }
  iVar7 = r_lld_read_clock();
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4043000c,
               (uint)*(byte *)(param_1 + 0x8e) |
               (uint)*(byte *)(param_1 + 0x16) << 0x10 | (uint)*(byte *)(param_1 + 0x8f) << 8);
  }
  if (*(char *)(param_1 + 0x8f) != '\0') {
    r_assert_err(0,"lld_con.c",0xbac);
  }
  uVar9 = (uint)*(byte *)(param_1 + 0x8e);
  *(uint *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(param_1 + 100) & 0xfffffff;
  cVar4 = rwip_priority;
  *(short *)(param_1 + 0x7e) = *(short *)(param_1 + 0x7e) + 1;
  *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + cVar4;
  iVar8 = *(int *)(&lld_con_env + uVar9 * 4);
  uVar3 = *(ushort *)(iVar8 + 0x84);
  uVar13 = (uint)DAT_00016066 << 1;
  uVar5 = *(uint *)(iVar8 + 0x48);
  if ((uVar3 & 2) == 0) {
    *(undefined1 *)(iVar8 + 0x16) = 0x1f;
  }
  if ((uVar3 & 3) == 3) {
    *(undefined1 *)(iVar8 + 0x96) = 0;
  }
  for (; (iVar7 - uVar5 & 0xfffffff) < 0x7ffffff; uVar5 = uVar5 + *(int *)(iVar8 + 100) & 0xfffffff)
  {
    *(short *)(iVar8 + 0x7e) = *(short *)(iVar8 + 0x7e) + 1;
  }
  uVar16 = *(uint *)(iVar8 + 0x58);
  if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x43) == '\0')) &&
     ((ushort)((*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44)) <
      0x7fff)) {
    if (*(char *)(iVar8 + 0x42) == '\0') {
      uVar5 = uVar5 + *(ushort *)(iVar8 + 0x3c) & 0xfffffff;
      if ((uVar3 & 1) != 0) {
        uVar5 = uVar5 + (*(ushort *)(iVar8 + 0x40) >> 1) & 0xfffffff;
      }
      *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(iVar8 + 0x34);
      *(undefined2 *)(iVar8 + 0x72) = *(undefined2 *)(iVar8 + 0x3e);
      *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(iVar8 + 0x38);
      *(undefined1 *)(iVar8 + 0x42) = 1;
      if (((uVar3 & 1) == 0) ||
         (r_lld_con_max_lat_calc(*(undefined1 *)(iVar8 + 0x8e)),
         (*(ushort *)(iVar8 + 0x84) & 1) == 0)) {
        *(undefined1 *)(iVar8 + 0x43) = 1;
      }
    }
    sVar14 = (*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44);
    uVar16 = uVar5;
    while (sVar14 = sVar14 + -1, sVar14 != -1) {
      uVar16 = uVar16 - *(int *)(iVar8 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
    uVar20 = *(int *)(iVar8 + 100) * 6;
  }
  else {
    uVar20 = *(uint *)(iVar8 + 0x68);
  }
  iVar7 = (uVar9 + 0x10) * 2;
  iVar15 = 0;
  while (sVar14 = (short)iVar15, (uVar5 - uVar16 & 0xfffffff) <= uVar20) {
    uVar18 = uVar5;
    if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
      iVar17 = *(int *)(iVar8 + 0x50);
      sVar14 = *(short *)(iVar8 + 0x6e);
      iVar15 = r_rwip_active_check();
      uVar13 = 0x14;
      if (iVar15 == 0) {
        uVar13 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar18 = ((*(ushort *)(iVar8 + 0x7a) + uVar13) * (uVar5 - iVar17 & 0xfffffff)) / 0x640 + 0x40;
      uVar13 = uVar18 * 2;
      if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
        uVar13 = uVar13 + (uint)*(ushort *)(iVar8 + 0x70) * 0x271;
_L248:
        bVar19 = true;
      }
      else {
        bVar19 = false;
        if (*(ushort *)(iVar8 + 0x7c) < 7) {
          uVar11 = ((int)((uint)*(ushort *)(&DAT_0001502c + iVar7) * (uint)*(ushort *)(iVar8 + 0x70)
                         * 0x271) >> 1) + (uint)*(ushort *)(iVar8 + 0x70) * 0x271 + uVar13;
          uVar13 = *(int *)(iVar8 + 100) * 0x271;
          if (uVar11 < uVar13) {
            uVar13 = uVar11;
          }
          *(ushort *)(&DAT_0001502c + iVar7) = *(ushort *)(&DAT_0001502c + iVar7) + 1;
          goto _L248;
        }
      }
      if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x42) != '\0')) &&
         (*(char *)(iVar8 + 0x43) == '\0')) {
        uVar13 = uVar13 + (uint)*(ushort *)(iVar8 + 0x40) * 0x271;
      }
      else if ((!bVar19) && (((uint)(*(int *)(iVar8 + 100) * 0x271) >> 1) - 300 <= uVar18)) {
        iVar15 = r_sdk_config_get_opts_ext();
        iVar7 = 0;
        if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
           (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x4043000f,(uint)*(ushort *)(iVar8 + 0x7c) << 0x10 | uVar9,
                     *(undefined4 *)(iVar8 + 100),uVar18);
        }
        goto _L191;
      }
      uVar11 = (uVar13 >> 1) / 0x271;
      uVar18 = uVar5 - uVar11 & 0xfffffff;
      iVar15 = ((int)sVar14 - (uVar13 >> 1)) + uVar11 * 0x271;
      if (iVar15 < 0) {
        uVar18 = uVar18 - 1 & 0xfffffff;
        iVar15 = iVar15 + 0x271;
      }
      *(int *)(iVar8 + 8) = iVar15;
      *(uint *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x5c) + uVar13;
    }
    sVar14 = (short)iVar15;
    *(uint *)(iVar8 + 4) = uVar18;
    iVar17 = r_sch_arb_insert(iVar8);
    if (iVar17 == 0) {
      iVar7 = 1;
      goto _L191;
    }
    *(char *)(iVar8 + 0x16) = *(char *)(iVar8 + 0x16) + rwip_priority;
    sVar14 = *(short *)(iVar8 + 0x7e);
    uVar5 = uVar5 + *(int *)(iVar8 + 100) & 0xfffffff;
    *(short *)(iVar8 + 0x7e) = sVar14 + 1;
    if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x43) == '\0')) &&
       ((ushort)(((sVar14 + 1) - *(short *)(iVar8 + 0x44)) + *(short *)(iVar8 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar8 + 0x42) == '\0') {
        uVar5 = uVar5 + *(ushort *)(iVar8 + 0x3c) & 0xfffffff;
        if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
          uVar5 = uVar5 + (*(ushort *)(iVar8 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(iVar8 + 0x34);
        *(undefined2 *)(iVar8 + 0x72) = *(undefined2 *)(iVar8 + 0x3e);
        *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(iVar8 + 0x38);
        if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
          r_lld_con_max_lat_calc(*(undefined1 *)(iVar8 + 0x8e));
        }
        *(undefined1 *)(iVar8 + 0x42) = 1;
        uVar20 = *(uint *)(iVar8 + 0x68);
        if ((*(ushort *)(iVar8 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar8 + 0x43) = 1;
        }
      }
      sVar14 = (*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44);
      uVar16 = uVar5;
      while (sVar14 = sVar14 + -1, sVar14 != -1) {
        uVar16 = uVar16 - *(int *)(iVar8 + 100) & 0xfffffff;
      }
    }
  }
  iVar7 = 0;
_L191:
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar7 << 8 | uVar9,*(undefined4 *)(iVar8 + 0x7c));
  }
  if (iVar7 != 0) {
    *(undefined1 *)(iVar8 + 0x8f) = 0;
    *(uint *)(iVar8 + 0x48) = uVar5;
    if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
      uVar5 = (uint)DAT_00016066;
      *(short *)(iVar8 + 0x6c) = sVar14;
      *(uint *)(iVar8 + 0x4c) = uVar13 + uVar5 * 2;
    }
    return;
  }
  iVar7 = 8;
  if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
    iVar7 = 0x3e;
  }
  iVar8 = *(int *)(&lld_con_env + uVar9 * 4);
  if (iVar8 == 0) {
    return;
  }
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar7 << 0x10 | 0x100U | uVar9);
  }
  uVar13 = uVar9 << 8 | 1;
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar13,0xff,1);
  *puVar6 = (char)iVar7;
  r_ke_msg_send();
  iVar7 = r_co_list_pop_front(iVar8 + 0x28);
  do {
    if (*(char *)(iVar8 + 0x92) == '\0') {
      if (*(int *)(iVar8 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar8 + 0x24) + 4));
      }
      while (iVar7 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar7 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar13,0xff);
        }
        iVar7 = r_co_list_pop_front(iVar8 + 0x28);
      }
      r_sch_slice_per_remove(4,uVar9);
      r_ke_free(*(undefined4 *)(&lld_con_env + uVar9 * 4));
      *(undefined4 *)(&lld_con_env + uVar9 * 4) = 0;
      (&g_event_empty)[uVar9] = 0;
      r_bt_rtp_deregister_rule_cs_idx(uVar9);
      r_bt_rma_deregister_rule_cs_idx(uVar9);
      return;
    }
    bVar1 = *(byte *)(iVar8 + 0x8e);
    bVar2 = *(byte *)(iVar8 + 0x90);
    iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar17 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar15 + iVar17 + 2);
    uVar12 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L146:
      uVar10 = 0x7a8;
_L167:
      r_assert_err(0,"lld_con.c",uVar10);
    }
    else if (2 < uVar12) {
      if (uVar12 != 3) goto _L146;
      iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar17 + 4 + iVar15));
      uVar10 = 0x79f;
      if (*(int *)(iVar8 + 0x24) == 0) goto _L147;
      goto _L167;
    }
_L147:
    *(char *)(iVar8 + 0x92) = *(char *)(iVar8 + 0x92) + -1;
    *(byte *)(iVar8 + 0x90) = *(char *)(iVar8 + 0x90) + 1U & 1;
  } while( true );
}

