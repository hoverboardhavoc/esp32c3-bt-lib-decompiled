/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched(uint param_1,int param_2,int param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  ushort uVar9;
  short sVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  uVar9 = *(ushort *)(iVar3 + 0x84);
  uVar4 = *(uint *)(iVar3 + 0x48);
  uVar11 = (uint)DAT_00016066 << 1;
  if ((uVar9 & 2) == 0) {
    *(undefined1 *)(iVar3 + 0x16) = 0x1f;
  }
  else if (((uVar9 & 3) == 3) && (*(undefined1 *)(iVar3 + 0x96) = 0, param_3 != 0)) {
    uVar1 = *(ushort *)(iVar3 + 0x72);
    if ((uVar1 != 0) &&
       ((((uVar9 & 0x404) == 0x400 && ((uVar9 & 8) == 0)) && (*(char *)(iVar3 + 0x46) == '\0')))) {
      uVar4 = (uint)uVar1 * *(int *)(iVar3 + 100) + uVar4 & 0xfffffff;
      *(ushort *)(iVar3 + 0x7e) = uVar1 + *(short *)(iVar3 + 0x7e);
      *(undefined1 *)(iVar3 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar4 & 0xfffffff) < 0x7ffffff;
      uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff) {
    *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  }
  uVar16 = *(uint *)(iVar3 + 0x58);
  if (((*(char *)(iVar3 + 0x46) != '\x01') || (*(char *)(iVar3 + 0x43) != '\0')) ||
     (0x7ffe < (ushort)((*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) -
                       *(short *)(iVar3 + 0x44)))) goto _L173;
  if (*(char *)(iVar3 + 0x42) == '\0') {
    uVar4 = *(ushort *)(iVar3 + 0x3c) + uVar4 & 0xfffffff;
    if ((uVar9 & 1) != 0) {
      uVar4 = (*(ushort *)(iVar3 + 0x40) >> 1) + uVar4 & 0xfffffff;
    }
    *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x34);
    *(undefined2 *)(iVar3 + 0x72) = *(undefined2 *)(iVar3 + 0x3e);
    *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0x38);
    *(undefined1 *)(iVar3 + 0x42) = 1;
    if ((uVar9 & 1) != 0) {
      r_lld_con_max_lat_calc(*(undefined1 *)(iVar3 + 0x8e));
      uVar9 = *(ushort *)(iVar3 + 0x84);
      if ((uVar9 & 1) != 0) goto _L174;
    }
    *(undefined1 *)(iVar3 + 0x43) = 1;
  }
_L174:
  sVar10 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
  uVar16 = uVar4;
  while (sVar10 = sVar10 + -1, sVar10 != -1) {
    uVar16 = uVar16 - *(int *)(iVar3 + 100) & 0xfffffff;
  }
_L173:
  if ((uVar9 & 2) == 0) {
    uVar17 = *(int *)(iVar3 + 100) * 6;
  }
  else {
    uVar17 = *(uint *)(iVar3 + 0x68);
  }
  iVar13 = 0;
  while (uVar12 = (undefined2)iVar13, (uVar4 - uVar16 & 0xfffffff) <= uVar17) {
    uVar14 = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      iVar7 = *(int *)(iVar3 + 0x50);
      sVar10 = *(short *)(iVar3 + 0x6e);
      iVar13 = r_rwip_active_check();
      uVar11 = 0x14;
      if (iVar13 == 0) {
        uVar11 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar14 = ((*(ushort *)(iVar3 + 0x7a) + uVar11) * (uVar4 - iVar7 & 0xfffffff)) / 0x640 + 0x40;
      uVar11 = uVar14 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_00015070 + (param_1 + 0x10) * 2) = 0;
      }
      if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
        uVar11 = uVar11 + (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
_L248:
        bVar2 = true;
      }
      else {
        bVar2 = false;
        if ((*(ushort *)(iVar3 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar2 = false, *(ushort *)(iVar3 + 0x7c) == 0 && (*(short *)(iVar3 + 0x98) == -1))))))
        {
          uVar11 = uVar11 + ((int)((uint)*(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) *
                                   (uint)*(ushort *)(iVar3 + 0x70) * 0x271) >> 1) +
                            (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
          uVar15 = *(int *)(iVar3 + 100) * 0x271;
          if (uVar15 < uVar11) {
            uVar11 = uVar15;
          }
          *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) =
               *(ushort *)(&DAT_00015070 + (param_1 + 0x10) * 2) + 1;
          goto _L248;
        }
      }
      if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x42) != '\0')) &&
         (*(char *)(iVar3 + 0x43) == '\0')) {
        uVar11 = uVar11 + (uint)*(ushort *)(iVar3 + 0x40) * 0x271;
      }
      else if (((!bVar2) && (((uint)(*(int *)(iVar3 + 100) * 0x271) >> 1) - 300 <= uVar14)) &&
              ((iVar13 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar13 + 0x28) & 0x20) != 0 &&
               (iVar13 = r_sdk_config_get_opts_ext(), *(byte *)(iVar13 + 0x2c) < 3)))) {
        r_ble_log_internal_x3
                  (0x4043000f,(uint)*(ushort *)(iVar3 + 0x7c) << 0x10 | param_1,
                   *(undefined4 *)(iVar3 + 100),uVar14);
      }
      uVar15 = (uVar11 >> 1) / 0x271;
      uVar14 = uVar4 - uVar15 & 0xfffffff;
      iVar13 = uVar15 * 0x271 + ((int)sVar10 - (uVar11 >> 1));
      if (iVar13 < 0) {
        uVar14 = uVar14 - 1 & 0xfffffff;
        iVar13 = iVar13 + 0x271;
      }
      *(int *)(iVar3 + 8) = iVar13;
      *(uint *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x5c) + uVar11;
    }
    uVar12 = (undefined2)iVar13;
    *(uint *)(iVar3 + 4) = uVar14;
    iVar7 = r_sch_arb_insert(iVar3);
    if (iVar7 == 0) {
      iVar13 = 1;
      goto _L194;
    }
    *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + rwip_priority;
    uVar4 = *(int *)(iVar3 + 100) + uVar4 & 0xfffffff;
    sVar10 = *(short *)(iVar3 + 0x7e);
    *(short *)(iVar3 + 0x7e) = sVar10 + 1;
    if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
       ((ushort)(((sVar10 + 1) - *(short *)(iVar3 + 0x44)) + *(short *)(iVar3 + 0x7c)) < 0x7fff)) {
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
      sVar10 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
      uVar16 = uVar4;
      while (sVar10 = sVar10 + -1, sVar10 != -1) {
        uVar16 = uVar16 - *(int *)(iVar3 + 100) & 0xfffffff;
      }
    }
  }
  iVar13 = 0;
_L194:
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar13 << 8 | param_1,*(undefined4 *)(iVar3 + 0x7c));
  }
  if (iVar13 != 0) {
    *(undefined1 *)(iVar3 + 0x8f) = 0;
    *(uint *)(iVar3 + 0x48) = uVar4;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      uVar4 = (uint)DAT_00016066;
      *(undefined2 *)(iVar3 + 0x6c) = uVar12;
      *(uint *)(iVar3 + 0x4c) = uVar4 * 2 + uVar11;
    }
    return;
  }
  iVar13 = (-(uint)((*(ushort *)(iVar3 + 0x84) & 2) == 0) & 0x36) + 8;
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar3 == 0) {
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar13 * 0x10000 | 0x100U | param_1);
  }
  uVar11 = param_1 << 8 | 1;
  puVar5 = (undefined1 *)r_ke_msg_alloc(0x212,uVar11,0xff,1);
  *puVar5 = (char)iVar13;
  r_ke_msg_send();
  iVar13 = r_co_list_pop_front(iVar3 + 0x28);
  do {
    if (*(char *)(iVar3 + 0x92) == '\0') {
      if (*(int *)(iVar3 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar3 + 0x24) + 4));
      }
      while (iVar13 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar13 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar11,0xff);
        }
        iVar13 = r_co_list_pop_front(iVar3 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    iVar7 = ((uint)*(byte *)(iVar3 + 0x8e) * 9 + (uint)*(byte *)(iVar3 + 0x90) & 0xff) * 0xe;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar9 = *(ushort *)(iVar7 + 2 + iVar6);
    if ((uVar9 & 3) == 3) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar7 + 4 + iVar6));
      uVar8 = 0x79f;
      if (*(int *)(iVar3 + 0x24) != 0) goto _L165;
    }
    else if ((uVar9 & 3) == 0) {
      uVar8 = 0x7a8;
_L165:
      r_assert_err(0,"lld_con.c",uVar8);
    }
    *(char *)(iVar3 + 0x92) = *(char *)(iVar3 + 0x92) + -1;
    *(byte *)(iVar3 + 0x90) = *(char *)(iVar3 + 0x90) + 1U & 1;
  } while( true );
}

