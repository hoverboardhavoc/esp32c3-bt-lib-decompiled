/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010e90) */
/* WARNING: Removing unreachable block (ram,0x00010e98) */
/* WARNING: Removing unreachable block (ram,0x00010ea4) */
/* WARNING: Removing unreachable block (ram,0x00010eac) */
/* WARNING: Removing unreachable block (ram,0x00010eb0) */
/* WARNING: Removing unreachable block (ram,0x00010f4c) */
/* WARNING: Removing unreachable block (ram,0x000110c6) */
/* WARNING: Removing unreachable block (ram,0x000110ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_skip_isr(uint param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  short sVar11;
  undefined2 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_err(0,"lld_con.c",0xc76);
    return;
  }
  iVar8 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar3 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xc5d);
  }
  r_sch_arb_remove(iVar3,1);
  if (*(char *)(iVar3 + 0x8f) == '\x02') {
    iVar3 = 0x16;
    goto r_lld_con_cleanup;
  }
  param_1 = (uint)*(byte *)(iVar3 + 0x8e);
  *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + *(int *)(iVar3 + 100) & 0xfffffff;
  cVar2 = rwip_priority;
  *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + cVar2;
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  uVar10 = *(ushort *)(iVar3 + 0x84);
  uVar4 = *(uint *)(iVar3 + 0x48);
  uVar15 = (uint)DAT_00016066 << 1;
  if ((uVar10 & 2) == 0) {
    *(undefined1 *)(iVar3 + 0x16) = 0x1f;
  }
  else if ((uVar10 & 3) == 3) {
    *(undefined1 *)(iVar3 + 0x96) = 0;
  }
  for (; (iVar8 - uVar4 & 0xfffffff) < 0x7ffffff; uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff)
  {
    *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  }
  uVar16 = *(uint *)(iVar3 + 0x58);
  if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
     ((ushort)((*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44)) <
      0x7fff)) {
    if (*(char *)(iVar3 + 0x42) == '\0') {
      uVar4 = *(ushort *)(iVar3 + 0x3c) + uVar4 & 0xfffffff;
      if ((uVar10 & 1) != 0) {
        uVar4 = (*(ushort *)(iVar3 + 0x40) >> 1) + uVar4 & 0xfffffff;
      }
      *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x34);
      *(undefined2 *)(iVar3 + 0x72) = *(undefined2 *)(iVar3 + 0x3e);
      *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0x38);
      *(undefined1 *)(iVar3 + 0x42) = 1;
      if ((uVar10 & 1) != 0) {
        r_lld_con_max_lat_calc(*(undefined1 *)(iVar3 + 0x8e));
        uVar10 = *(ushort *)(iVar3 + 0x84);
        if ((uVar10 & 1) != 0) goto _L174;
      }
      *(undefined1 *)(iVar3 + 0x43) = 1;
    }
_L174:
    sVar11 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
    uVar16 = uVar4;
    while (sVar11 = sVar11 + -1, sVar11 != -1) {
      uVar16 = uVar16 - *(int *)(iVar3 + 100) & 0xfffffff;
    }
  }
  if ((uVar10 & 2) == 0) {
    uVar17 = *(int *)(iVar3 + 100) * 6;
  }
  else {
    uVar17 = *(uint *)(iVar3 + 0x68);
  }
  iVar8 = 0;
  while (uVar12 = (undefined2)iVar8, (uVar4 - uVar16 & 0xfffffff) <= uVar17) {
    uVar13 = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      iVar5 = *(int *)(iVar3 + 0x50);
      sVar11 = *(short *)(iVar3 + 0x6e);
      iVar8 = r_rwip_active_check();
      uVar15 = 0x14;
      if (iVar8 == 0) {
        uVar15 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar13 = ((*(ushort *)(iVar3 + 0x7a) + uVar15) * (uVar4 - iVar5 & 0xfffffff)) / 0x640 + 0x40;
      uVar15 = uVar13 * 2;
      if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
        uVar15 = uVar15 + (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
_L248:
        bVar1 = true;
      }
      else {
        bVar1 = false;
        if (*(ushort *)(iVar3 + 0x7c) < 7) {
          uVar15 = uVar15 + ((int)((uint)*(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) *
                                   (uint)*(ushort *)(iVar3 + 0x70) * 0x271) >> 1) +
                            (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
          uVar14 = *(int *)(iVar3 + 100) * 0x271;
          if (uVar14 < uVar15) {
            uVar15 = uVar14;
          }
          *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) =
               *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) + 1;
          goto _L248;
        }
      }
      if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x42) != '\0')) &&
         (*(char *)(iVar3 + 0x43) == '\0')) {
        uVar15 = uVar15 + (uint)*(ushort *)(iVar3 + 0x40) * 0x271;
      }
      else if (((!bVar1) && (((uint)(*(int *)(iVar3 + 100) * 0x271) >> 1) - 300 <= uVar13)) &&
              ((iVar8 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar8 + 0x28) & 0x20) != 0 &&
               (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)))) {
        r_ble_log_internal_x3
                  (0x4043000f,(uint)*(ushort *)(iVar3 + 0x7c) << 0x10 | param_1,
                   *(undefined4 *)(iVar3 + 100),uVar13);
      }
      uVar14 = (uVar15 >> 1) / 0x271;
      uVar13 = uVar4 - uVar14 & 0xfffffff;
      iVar8 = uVar14 * 0x271 + ((int)sVar11 - (uVar15 >> 1));
      if (iVar8 < 0) {
        uVar13 = uVar13 - 1 & 0xfffffff;
        iVar8 = iVar8 + 0x271;
      }
      *(int *)(iVar3 + 8) = iVar8;
      *(uint *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x5c) + uVar15;
    }
    uVar12 = (undefined2)iVar8;
    *(uint *)(iVar3 + 4) = uVar13;
    iVar5 = r_sch_arb_insert(iVar3);
    if (iVar5 == 0) {
      iVar8 = 1;
      goto _L194;
    }
    *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + rwip_priority;
    uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff;
    sVar11 = *(short *)(iVar3 + 0x7e);
    *(short *)(iVar3 + 0x7e) = sVar11 + 1;
    if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
       ((ushort)(((sVar11 + 1) - *(short *)(iVar3 + 0x44)) + *(short *)(iVar3 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar3 + 0x42) == '\0') {
        uVar4 = *(ushort *)(iVar3 + 0x3c) + uVar4 & 0xfffffff;
        if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
          uVar4 = (*(ushort *)(iVar3 + 0x40) >> 1) + uVar4 & 0xfffffff;
        }
        *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x34);
        *(undefined2 *)(iVar3 + 0x72) = *(undefined2 *)(iVar3 + 0x3e);
        *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0x38);
        if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
          r_lld_con_max_lat_calc(*(undefined1 *)(iVar3 + 0x8e));
        }
        *(undefined1 *)(iVar3 + 0x42) = 1;
        uVar17 = *(uint *)(iVar3 + 0x68);
        if ((*(ushort *)(iVar3 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar3 + 0x43) = 1;
        }
      }
      sVar11 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
      uVar16 = uVar4;
      while (sVar11 = sVar11 + -1, sVar11 != -1) {
        uVar16 = uVar16 - *(int *)(iVar3 + 100) & 0xfffffff;
      }
    }
  }
  iVar8 = 0;
_L194:
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar8 << 8 | param_1,*(undefined4 *)(iVar3 + 0x7c));
  }
  if (iVar8 != 0) {
    *(undefined1 *)(iVar3 + 0x8f) = 0;
    *(uint *)(iVar3 + 0x48) = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      uVar4 = (uint)DAT_00016066;
      *(undefined2 *)(iVar3 + 0x6c) = uVar12;
      *(uint *)(iVar3 + 0x4c) = uVar4 * 2 + uVar15;
    }
    return;
  }
  iVar3 = (-(uint)((*(ushort *)(iVar3 + 0x84) & 2) == 0) & 0x36) + 8;
r_lld_con_cleanup:
  iVar8 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar8 == 0) {
    return;
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar3 << 0x10 | 0x100U | param_1);
  }
  uVar15 = param_1 << 8 | 1;
  puVar6 = (undefined1 *)r_ke_msg_alloc(0x212,uVar15,0xff,1);
  *puVar6 = (char)iVar3;
  r_ke_msg_send();
  iVar3 = r_co_list_pop_front(iVar8 + 0x28);
  do {
    if (*(char *)(iVar8 + 0x92) == '\0') {
      if (*(int *)(iVar8 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar8 + 0x24) + 4));
      }
      while (iVar3 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar3 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar15,0xff);
        }
        iVar3 = r_co_list_pop_front(iVar8 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    iVar5 = ((uint)*(byte *)(iVar8 + 0x8e) * 9 + (uint)*(byte *)(iVar8 + 0x90) & 0xff) * 0xe;
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = *(ushort *)(iVar5 + 2 + iVar7);
    if ((uVar10 & 3) == 3) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar5 + 4 + iVar7));
      uVar9 = 0x79f;
      if (*(int *)(iVar8 + 0x24) != 0) goto _L165;
    }
    else if ((uVar10 & 3) == 0) {
      uVar9 = 0x7a8;
_L165:
      r_assert_err(0,"lld_con.c",uVar9);
    }
    *(char *)(iVar8 + 0x92) = *(char *)(iVar8 + 0x92) + -1;
    *(byte *)(iVar8 + 0x90) = *(char *)(iVar8 + 0x90) + 1U & 1;
  } while( true );
}

