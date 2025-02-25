/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  short sVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  uint uVar18;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar4 + 0x84);
  uVar11 = (uint)DAT_00016066 << 1;
  uVar5 = *(uint *)(iVar4 + 0x48);
  if ((uVar3 & 2) == 0) {
    *(undefined1 *)(iVar4 + 0x16) = 0x1f;
  }
  if (((uVar3 & 3) == 3) && (*(undefined1 *)(iVar4 + 0x96) = 0, param_3 != 0)) {
    uVar9 = *(ushort *)(iVar4 + 0x72);
    if ((uVar9 != 0) &&
       ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar4 + 0x46) == '\0')))) {
      uVar5 = uVar5 + (uint)uVar9 * *(int *)(iVar4 + 100) & 0xfffffff;
      *(ushort *)(iVar4 + 0x7e) = uVar9 + *(short *)(iVar4 + 0x7e);
      *(undefined1 *)(iVar4 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar5 & 0xfffffff) < 0x7ffffff;
      uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff) {
    *(short *)(iVar4 + 0x7e) = *(short *)(iVar4 + 0x7e) + 1;
  }
  uVar14 = *(uint *)(iVar4 + 0x58);
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
    sVar12 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
    uVar14 = uVar5;
    while (sVar12 = sVar12 + -1, sVar12 != -1) {
      uVar14 = uVar14 - *(int *)(iVar4 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    uVar18 = *(int *)(iVar4 + 100) * 6;
  }
  else {
    uVar18 = *(uint *)(iVar4 + 0x68);
  }
  iVar10 = (param_1 + 0x10) * 2;
  iVar13 = 0;
  while (sVar12 = (short)iVar13, (uVar5 - uVar14 & 0xfffffff) <= uVar18) {
    uVar16 = uVar5;
    if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
      iVar15 = *(int *)(iVar4 + 0x50);
      sVar12 = *(short *)(iVar4 + 0x6e);
      iVar13 = r_rwip_active_check();
      uVar11 = 0x14;
      if (iVar13 == 0) {
        uVar11 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar16 = ((*(ushort *)(iVar4 + 0x7a) + uVar11) * (uVar5 - iVar15 & 0xfffffff)) / 0x640 + 0x40;
      uVar11 = uVar16 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_0001502c + iVar10) = 0;
      }
      if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
        uVar11 = uVar11 + (uint)*(ushort *)(iVar4 + 0x70) * 0x271;
_L248:
        bVar17 = true;
      }
      else {
        bVar17 = false;
        if ((*(ushort *)(iVar4 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar17 = false, *(ushort *)(iVar4 + 0x7c) == 0 && (*(short *)(iVar4 + 0x98) == -1)))))
           ) {
          uVar8 = ((int)((uint)*(ushort *)(&DAT_0001502c + iVar10) * (uint)*(ushort *)(iVar4 + 0x70)
                        * 0x271) >> 1) + (uint)*(ushort *)(iVar4 + 0x70) * 0x271 + uVar11;
          uVar11 = *(int *)(iVar4 + 100) * 0x271;
          if (uVar8 < uVar11) {
            uVar11 = uVar8;
          }
          *(ushort *)(&DAT_0001502c + iVar10) = *(ushort *)(&DAT_0001502c + iVar10) + 1;
          goto _L248;
        }
      }
      if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x42) != '\0')) &&
         (*(char *)(iVar4 + 0x43) == '\0')) {
        uVar11 = uVar11 + (uint)*(ushort *)(iVar4 + 0x40) * 0x271;
      }
      else if ((!bVar17) && (((uint)(*(int *)(iVar4 + 100) * 0x271) >> 1) - 300 <= uVar16)) {
        iVar13 = r_sdk_config_get_opts_ext();
        iVar10 = 0;
        if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
           (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x4043000f,(uint)*(ushort *)(iVar4 + 0x7c) << 0x10 | param_1,
                     *(undefined4 *)(iVar4 + 100),uVar16);
        }
        goto _L191;
      }
      uVar8 = (uVar11 >> 1) / 0x271;
      uVar16 = uVar5 - uVar8 & 0xfffffff;
      iVar13 = ((int)sVar12 - (uVar11 >> 1)) + uVar8 * 0x271;
      if (iVar13 < 0) {
        uVar16 = uVar16 - 1 & 0xfffffff;
        iVar13 = iVar13 + 0x271;
      }
      *(int *)(iVar4 + 8) = iVar13;
      *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x5c) + uVar11;
    }
    sVar12 = (short)iVar13;
    *(uint *)(iVar4 + 4) = uVar16;
    iVar15 = r_sch_arb_insert(iVar4);
    if (iVar15 == 0) {
      iVar10 = 1;
      goto _L191;
    }
    *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + rwip_priority;
    sVar12 = *(short *)(iVar4 + 0x7e);
    uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff;
    *(short *)(iVar4 + 0x7e) = sVar12 + 1;
    if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
       ((ushort)(((sVar12 + 1) - *(short *)(iVar4 + 0x44)) + *(short *)(iVar4 + 0x7c)) < 0x7fff)) {
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
        uVar18 = *(uint *)(iVar4 + 0x68);
        if ((*(ushort *)(iVar4 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar4 + 0x43) = 1;
        }
      }
      sVar12 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
      uVar14 = uVar5;
      while (sVar12 = sVar12 + -1, sVar12 != -1) {
        uVar14 = uVar14 - *(int *)(iVar4 + 100) & 0xfffffff;
      }
    }
  }
  iVar10 = 0;
_L191:
  iVar13 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
     (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar10 << 8 | param_1,*(undefined4 *)(iVar4 + 0x7c));
  }
  if (iVar10 != 0) {
    *(undefined1 *)(iVar4 + 0x8f) = 0;
    *(uint *)(iVar4 + 0x48) = uVar5;
    if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
      uVar5 = (uint)DAT_00016066;
      *(short *)(iVar4 + 0x6c) = sVar12;
      *(uint *)(iVar4 + 0x4c) = uVar11 + uVar5 * 2;
    }
    return;
  }
  iVar10 = 8;
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    iVar10 = 0x3e;
  }
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar4 == 0) {
    return;
  }
  iVar13 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar13 + 0x28) & 0x20) != 0) &&
     (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar10 << 0x10 | 0x100U | param_1);
  }
  uVar11 = param_1 << 8 | 1;
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar11,0xff,1);
  *puVar6 = (char)iVar10;
  r_ke_msg_send();
  iVar10 = r_co_list_pop_front(iVar4 + 0x28);
  do {
    if (*(char *)(iVar4 + 0x92) == '\0') {
      if (*(int *)(iVar4 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar4 + 0x24) + 4));
      }
      while (iVar10 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar10 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar11,0xff);
        }
        iVar10 = r_co_list_pop_front(iVar4 + 0x28);
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
    iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar15 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar13 + iVar15 + 2);
    uVar9 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L146:
      uVar7 = 0x7a8;
_L167:
      r_assert_err(0,"lld_con.c",uVar7);
    }
    else if (2 < uVar9) {
      if (uVar9 != 3) goto _L146;
      iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar15 + 4 + iVar13));
      uVar7 = 0x79f;
      if (*(int *)(iVar4 + 0x24) == 0) goto _L147;
      goto _L167;
    }
_L147:
    *(char *)(iVar4 + 0x92) = *(char *)(iVar4 + 0x92) + -1;
    *(byte *)(iVar4 + 0x90) = *(char *)(iVar4 + 0x90) + 1U & 1;
  } while( true );
}

