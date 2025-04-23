/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_frm_isr(uint param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  ushort uVar10;
  char cVar11;
  short sVar12;
  undefined2 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_err(0,"lld_con.c",0xc11);
    return;
  }
  r_sch_arb_remove(iVar3,1);
  if (*(char *)(iVar3 + 0x8f) == '\x02') {
    iVar3 = (-(uint)((*(ushort *)(iVar3 + 0x84) & 0x80) == 0) & 0xffffffd9) + 0x3d;
    goto r_lld_con_cleanup;
  }
  iVar6 = r_lld_read_clock();
  if (sdk_cfg_priv_opts != '\0') {
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *(ushort *)(param_1 * 0x5a + 0x56 + iVar7);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    iVar16 = param_1 * 0x5a + 0x18;
    if ((((&g_event_empty)[param_1] == '\x01') && (uVar10 >> 8 == 0)) &&
       ((*(ushort *)(iVar7 + iVar16) >> 0xe & 1) == 0)) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = *(ushort *)(iVar7 + iVar16);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar16) = uVar10 | 0x4000;
    }
    else {
      (&g_event_empty)[param_1] = (byte)(*(ushort *)(iVar7 + iVar16) >> 0xe) & 1;
    }
  }
  uVar10 = *(ushort *)(iVar3 + 0x84);
  iVar7 = 5;
  if (((uVar10 & 6) == 2) && ((uVar10 & 8) == 0)) {
    iVar7 = (*(char *)(iVar3 + 0x46) == '\x01') + 4;
  }
  *(uint *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + *(int *)(iVar3 + 100) & 0xfffffff;
  *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  if (param_2 == 0) {
    cVar11 = (&rwip_priority)[iVar7 * 2];
  }
  else {
    cVar11 = *(char *)(iVar3 + 0x16) + (&DAT_00016099)[iVar7 * 2];
  }
  *(char *)(iVar3 + 0x16) = cVar11;
  uVar9 = (int)(uint)uVar10 >> 8 & 1;
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  uVar10 = *(ushort *)(iVar3 + 0x84);
  uVar4 = *(uint *)(iVar3 + 0x48);
  uVar17 = (uint)DAT_00016066 << 1;
  if ((uVar10 & 2) == 0) {
    *(undefined1 *)(iVar3 + 0x16) = 0x1f;
  }
  else if (((uVar10 & 3) == 3) && (*(undefined1 *)(iVar3 + 0x96) = 0, uVar9 != 0)) {
    uVar1 = *(ushort *)(iVar3 + 0x72);
    if ((uVar1 != 0) &&
       ((((uVar10 & 0x404) == 0x400 && ((uVar10 & 8) == 0)) && (*(char *)(iVar3 + 0x46) == '\0'))))
    {
      uVar4 = (uint)uVar1 * *(int *)(iVar3 + 100) + uVar4 & 0xfffffff;
      *(ushort *)(iVar3 + 0x7e) = uVar1 + *(short *)(iVar3 + 0x7e);
      *(undefined1 *)(iVar3 + 0x96) = 1;
    }
  }
  for (; (iVar6 - uVar4 & 0xfffffff) < 0x7ffffff; uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff)
  {
    *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  }
  uVar18 = *(uint *)(iVar3 + 0x58);
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
    sVar12 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
    uVar18 = uVar4;
    while (sVar12 = sVar12 + -1, sVar12 != -1) {
      uVar18 = uVar18 - *(int *)(iVar3 + 100) & 0xfffffff;
    }
  }
  if ((uVar10 & 2) == 0) {
    uVar19 = *(int *)(iVar3 + 100) * 6;
  }
  else {
    uVar19 = *(uint *)(iVar3 + 0x68);
  }
  iVar6 = 0;
  while (uVar13 = (undefined2)iVar6, (uVar4 - uVar18 & 0xfffffff) <= uVar19) {
    uVar14 = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      iVar7 = *(int *)(iVar3 + 0x50);
      sVar12 = *(short *)(iVar3 + 0x6e);
      iVar6 = r_rwip_active_check();
      uVar17 = 0x14;
      if (iVar6 == 0) {
        uVar17 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar14 = ((*(ushort *)(iVar3 + 0x7a) + uVar17) * (uVar4 - iVar7 & 0xfffffff)) / 0x640 + 0x40;
      uVar17 = uVar14 * 2;
      if (uVar9 != 0) {
        *(undefined2 *)(&DAT_00015070 + (param_1 + 0x10) * 2) = 0;
      }
      if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
        uVar17 = uVar17 + (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
_L248:
        bVar2 = true;
      }
      else {
        bVar2 = false;
        if ((*(ushort *)(iVar3 + 0x7c) < 7) &&
           ((uVar9 == 0 ||
            ((bVar2 = false, *(ushort *)(iVar3 + 0x7c) == 0 && (*(short *)(iVar3 + 0x98) == -1))))))
        {
          uVar17 = uVar17 + ((int)((uint)*(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) *
                                   (uint)*(ushort *)(iVar3 + 0x70) * 0x271) >> 1) +
                            (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
          uVar15 = *(int *)(iVar3 + 100) * 0x271;
          if (uVar15 < uVar17) {
            uVar17 = uVar15;
          }
          *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) =
               *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) + 1;
          goto _L248;
        }
      }
      if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x42) != '\0')) &&
         (*(char *)(iVar3 + 0x43) == '\0')) {
        uVar17 = uVar17 + (uint)*(ushort *)(iVar3 + 0x40) * 0x271;
      }
      else if (((!bVar2) && (((uint)(*(int *)(iVar3 + 100) * 0x271) >> 1) - 300 <= uVar14)) &&
              ((iVar6 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar6 + 0x28) & 0x20) != 0 &&
               (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)))) {
        r_ble_log_internal_x3
                  (0x4043000f,(uint)*(ushort *)(iVar3 + 0x7c) << 0x10 | param_1,
                   *(undefined4 *)(iVar3 + 100),uVar14);
      }
      uVar15 = (uVar17 >> 1) / 0x271;
      uVar14 = uVar4 - uVar15 & 0xfffffff;
      iVar6 = uVar15 * 0x271 + ((int)sVar12 - (uVar17 >> 1));
      if (iVar6 < 0) {
        uVar14 = uVar14 - 1 & 0xfffffff;
        iVar6 = iVar6 + 0x271;
      }
      *(int *)(iVar3 + 8) = iVar6;
      *(uint *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x5c) + uVar17;
    }
    uVar13 = (undefined2)iVar6;
    *(uint *)(iVar3 + 4) = uVar14;
    iVar7 = r_sch_arb_insert(iVar3);
    if (iVar7 == 0) {
      iVar6 = 1;
      goto _L194;
    }
    *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + rwip_priority;
    uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff;
    sVar12 = *(short *)(iVar3 + 0x7e);
    *(short *)(iVar3 + 0x7e) = sVar12 + 1;
    if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
       ((ushort)(((sVar12 + 1) - *(short *)(iVar3 + 0x44)) + *(short *)(iVar3 + 0x7c)) < 0x7fff)) {
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
        uVar19 = *(uint *)(iVar3 + 0x68);
        if ((*(ushort *)(iVar3 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar3 + 0x43) = 1;
        }
      }
      sVar12 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
      uVar18 = uVar4;
      while (sVar12 = sVar12 + -1, sVar12 != -1) {
        uVar18 = uVar18 - *(int *)(iVar3 + 100) & 0xfffffff;
      }
    }
  }
  iVar6 = 0;
_L194:
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar6 << 8 | param_1,*(undefined4 *)(iVar3 + 0x7c));
  }
  if (iVar6 != 0) {
    *(undefined1 *)(iVar3 + 0x8f) = 0;
    *(uint *)(iVar3 + 0x48) = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      uVar4 = (uint)DAT_00016066;
      *(undefined2 *)(iVar3 + 0x6c) = uVar13;
      *(uint *)(iVar3 + 0x4c) = uVar4 * 2 + uVar17;
    }
    return;
  }
  iVar3 = (-(uint)((*(ushort *)(iVar3 + 0x84) & 2) == 0) & 0x36) + 8;
r_lld_con_cleanup:
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar3 << 0x10 | 0x100U | param_1);
  }
  uVar17 = param_1 << 8 | 1;
  puVar5 = (undefined1 *)r_ke_msg_alloc(0x212,uVar17,0xff,1);
  *puVar5 = (char)iVar3;
  r_ke_msg_send();
  iVar3 = r_co_list_pop_front(iVar6 + 0x28);
  do {
    if (*(char *)(iVar6 + 0x92) == '\0') {
      if (*(int *)(iVar6 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar6 + 0x24) + 4));
      }
      while (iVar3 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar3 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar17,0xff);
        }
        iVar3 = r_co_list_pop_front(iVar6 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    iVar7 = ((uint)*(byte *)(iVar6 + 0x8e) * 9 + (uint)*(byte *)(iVar6 + 0x90) & 0xff) * 0xe;
    iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = *(ushort *)(iVar7 + 2 + iVar16);
    if ((uVar10 & 3) == 3) {
      iVar16 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar7 + 4 + iVar16));
      uVar8 = 0x79f;
      if (*(int *)(iVar6 + 0x24) != 0) goto _L165;
    }
    else if ((uVar10 & 3) == 0) {
      uVar8 = 0x7a8;
_L165:
      r_assert_err(0,"lld_con.c",uVar8);
    }
    *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + -1;
    *(byte *)(iVar6 + 0x90) = *(char *)(iVar6 + 0x90) + 1U & 1;
  } while( true );
}

