/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
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
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  ushort uVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar5 + 0x84);
  uVar13 = (uint)DAT_00016066 << 1;
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
  uVar16 = *(uint *)(iVar5 + 0x58);
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
    sVar11 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
    uVar16 = uVar6;
    while (sVar11 = sVar11 + -1, sVar11 != -1) {
      uVar16 = uVar16 - *(int *)(iVar5 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    uVar17 = *(int *)(iVar5 + 100) * 6;
  }
  else {
    uVar17 = *(uint *)(iVar5 + 0x68);
  }
  iVar12 = (param_1 + 0x10) * 2;
  iVar15 = 0;
  while (uVar14 = (undefined2)iVar15, (uVar6 - uVar16 & 0xfffffff) <= uVar17) {
    uVar19 = uVar6;
    if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
      iVar18 = *(int *)(iVar5 + 0x50);
      sVar11 = *(short *)(iVar5 + 0x6e);
      iVar15 = r_rwip_active_check();
      uVar13 = 0x14;
      if (iVar15 == 0) {
        uVar13 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar19 = ((*(ushort *)(iVar5 + 0x7a) + uVar13) * (uVar6 - iVar18 & 0xfffffff)) / 0x640 + 0x40;
      uVar13 = uVar19 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_00015058 + iVar12) = 0;
      }
      if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
        uVar13 = uVar13 + (uint)*(ushort *)(iVar5 + 0x70) * 0x271;
_L249:
        bVar4 = true;
      }
      else {
        bVar4 = false;
        if ((*(ushort *)(iVar5 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar4 = false, *(ushort *)(iVar5 + 0x7c) == 0 && (*(short *)(iVar5 + 0x98) == -1))))))
        {
          uVar9 = ((int)((uint)*(ushort *)(&DAT_00015058 + iVar12) * (uint)*(ushort *)(iVar5 + 0x70)
                        * 0x271) >> 1) + (uint)*(ushort *)(iVar5 + 0x70) * 0x271 + uVar13;
          uVar13 = *(int *)(iVar5 + 100) * 0x271;
          if (uVar9 < uVar13) {
            uVar13 = uVar9;
          }
          *(ushort *)(&DAT_00015058 + iVar12) = *(ushort *)(&DAT_00015058 + iVar12) + 1;
          goto _L249;
        }
      }
      if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x42) != '\0')) &&
         (*(char *)(iVar5 + 0x43) == '\0')) {
        uVar13 = uVar13 + (uint)*(ushort *)(iVar5 + 0x40) * 0x271;
      }
      else if (((!bVar4) && (((uint)(*(int *)(iVar5 + 100) * 0x271) >> 1) - 300 <= uVar19)) &&
              ((iVar15 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar15 + 0x28) & 0x20) != 0 &&
               (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)))) {
        r_ble_log_internal_x3
                  (0x4043000f,(uint)*(ushort *)(iVar5 + 0x7c) << 0x10 | param_1,
                   *(undefined4 *)(iVar5 + 100),uVar19);
      }
      uVar9 = (uVar13 >> 1) / 0x271;
      uVar19 = uVar6 - uVar9 & 0xfffffff;
      iVar15 = ((int)sVar11 - (uVar13 >> 1)) + uVar9 * 0x271;
      if (iVar15 < 0) {
        uVar19 = uVar19 - 1 & 0xfffffff;
        iVar15 = iVar15 + 0x271;
      }
      *(int *)(iVar5 + 8) = iVar15;
      *(uint *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x5c) + uVar13;
    }
    uVar14 = (undefined2)iVar15;
    *(uint *)(iVar5 + 4) = uVar19;
    iVar18 = r_sch_arb_insert(iVar5);
    if (iVar18 == 0) {
      iVar12 = 1;
      goto _L192;
    }
    *(char *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + rwip_priority;
    sVar11 = *(short *)(iVar5 + 0x7e);
    uVar6 = uVar6 + *(int *)(iVar5 + 100) & 0xfffffff;
    *(short *)(iVar5 + 0x7e) = sVar11 + 1;
    if (((*(char *)(iVar5 + 0x46) == '\x01') && (*(char *)(iVar5 + 0x43) == '\0')) &&
       ((ushort)(((sVar11 + 1) - *(short *)(iVar5 + 0x44)) + *(short *)(iVar5 + 0x7c)) < 0x7fff)) {
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
        uVar17 = *(uint *)(iVar5 + 0x68);
        if ((*(ushort *)(iVar5 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar5 + 0x43) = 1;
        }
      }
      sVar11 = (*(short *)(iVar5 + 0x7c) + *(short *)(iVar5 + 0x7e)) - *(short *)(iVar5 + 0x44);
      uVar16 = uVar6;
      while (sVar11 = sVar11 + -1, sVar11 != -1) {
        uVar16 = uVar16 - *(int *)(iVar5 + 100) & 0xfffffff;
      }
    }
  }
  iVar12 = 0;
_L192:
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar12 << 8 | param_1,*(undefined4 *)(iVar5 + 0x7c));
  }
  if (iVar12 != 0) {
    *(undefined1 *)(iVar5 + 0x8f) = 0;
    *(uint *)(iVar5 + 0x48) = uVar6;
    if ((*(ushort *)(iVar5 + 0x84) & 1) != 0) {
      uVar6 = (uint)DAT_00016066;
      *(undefined2 *)(iVar5 + 0x6c) = uVar14;
      *(uint *)(iVar5 + 0x4c) = uVar13 + uVar6 * 2;
    }
    return;
  }
  iVar12 = 8;
  if ((*(ushort *)(iVar5 + 0x84) & 2) == 0) {
    iVar12 = 0x3e;
  }
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar5 == 0) {
    return;
  }
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar12 << 0x10 | 0x100U | param_1);
  }
  uVar13 = param_1 << 8 | 1;
  puVar7 = (undefined1 *)r_ke_msg_alloc(0x212,uVar13,0xff,1);
  *puVar7 = (char)iVar12;
  r_ke_msg_send();
  iVar12 = r_co_list_pop_front(iVar5 + 0x28);
  do {
    if (*(char *)(iVar5 + 0x92) == '\0') {
      if (*(int *)(iVar5 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar5 + 0x24) + 4));
      }
      while (iVar12 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar12 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar13,0xff);
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
    iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar18 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar15 + iVar18 + 2);
    uVar10 = uVar3 & 3;
    if ((uVar3 & 3) == 0) {
_L146:
      uVar8 = 0x7a8;
_L167:
      r_assert_err(0,"lld_con.c",uVar8);
    }
    else if (2 < uVar10) {
      if (uVar10 != 3) goto _L146;
      iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar18 + 4 + iVar15));
      uVar8 = 0x79f;
      if (*(int *)(iVar5 + 0x24) == 0) goto _L147;
      goto _L167;
    }
_L147:
    *(char *)(iVar5 + 0x92) = *(char *)(iVar5 + 0x92) + -1;
    *(byte *)(iVar5 + 0x90) = *(char *)(iVar5 + 0x90) + 1U & 1;
  } while( true );
}

