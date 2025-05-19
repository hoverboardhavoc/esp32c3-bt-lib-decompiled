/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  ushort uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar6 + 0x84);
  uVar7 = *(uint *)(iVar6 + 0x48);
  uVar12 = (uint)DAT_00016066 << 1;
  if ((uVar3 & 2) == 0) {
    *(undefined1 *)(iVar6 + 0x16) = 0x1f;
  }
  if (((uVar3 & 3) == 3) && (*(undefined1 *)(iVar6 + 0x96) = 0, param_3 != 0)) {
    uVar4 = *(ushort *)(iVar6 + 0x72);
    if ((uVar4 != 0) &&
       ((((uVar3 & 0x404) == 0x400 && ((uVar3 & 8) == 0)) && (*(char *)(iVar6 + 0x46) == '\0')))) {
      uVar7 = (uint)uVar4 * *(int *)(iVar6 + 100) + uVar7 & 0xfffffff;
      *(ushort *)(iVar6 + 0x7e) = uVar4 + *(short *)(iVar6 + 0x7e);
      *(undefined1 *)(iVar6 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar7 & 0xfffffff) < 0x7ffffff;
      uVar7 = *(int *)(iVar6 + 100) + uVar7 & 0xfffffff) {
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
  }
  uVar18 = *(uint *)(iVar6 + 0x58);
  if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
     ((ushort)((*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44)) <
      0x7fff)) {
    if (*(char *)(iVar6 + 0x42) == '\0') {
      uVar7 = *(ushort *)(iVar6 + 0x3c) + uVar7 & 0xfffffff;
      if ((uVar3 & 1) != 0) {
        uVar7 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar7 & 0xfffffff;
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
    sVar10 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
    uVar18 = uVar7;
    while (sVar10 = sVar10 + -1, sVar10 != -1) {
      uVar18 = uVar18 - *(int *)(iVar6 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
    uVar19 = *(int *)(iVar6 + 100) * 6;
  }
  else {
    uVar19 = *(uint *)(iVar6 + 0x68);
  }
  iVar11 = (param_1 + 0x10) * 2;
  iVar15 = 0;
  while (uVar14 = (undefined2)iVar15, (uVar7 - uVar18 & 0xfffffff) <= uVar19) {
    uVar16 = uVar7;
    if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
      iVar13 = *(int *)(iVar6 + 0x50);
      sVar10 = *(short *)(iVar6 + 0x6e);
      iVar15 = r_rwip_active_check();
      uVar12 = 0x14;
      if (iVar15 == 0) {
        uVar12 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar16 = ((*(ushort *)(iVar6 + 0x7a) + uVar12) * (uVar7 - iVar13 & 0xfffffff)) / 0x640 + 0x40;
      uVar12 = uVar16 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(&DAT_00015038 + iVar11) = 0;
      }
      if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
        uVar12 = uVar12 + (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
_L247:
        bVar5 = true;
      }
      else {
        bVar5 = false;
        if ((*(ushort *)(iVar6 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar5 = false, *(ushort *)(iVar6 + 0x7c) == 0 && (*(short *)(iVar6 + 0x98) == -1))))))
        {
          uVar12 = uVar12 + ((int)((uint)*(ushort *)(&DAT_00015038 + iVar11) *
                                   (uint)*(ushort *)(iVar6 + 0x70) * 0x271) >> 1) +
                            (uint)*(ushort *)(iVar6 + 0x70) * 0x271;
          uVar17 = *(int *)(iVar6 + 100) * 0x271;
          if (uVar17 < uVar12) {
            uVar12 = uVar17;
          }
          *(ushort *)(&DAT_00015038 + iVar11) = *(ushort *)(&DAT_00015038 + iVar11) + 1;
          goto _L247;
        }
      }
      if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x42) != '\0')) &&
         (*(char *)(iVar6 + 0x43) == '\0')) {
        uVar12 = uVar12 + (uint)*(ushort *)(iVar6 + 0x40) * 0x271;
      }
      else if (((!bVar5) && (((uint)(*(int *)(iVar6 + 100) * 0x271) >> 1) - 300 <= uVar16)) &&
              ((iVar15 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar15 + 0x28) & 0x20) != 0 &&
               (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)))) {
        r_ble_log_internal_x3
                  (0x4043000f,(uint)*(ushort *)(iVar6 + 0x7c) << 0x10 | param_1,
                   *(undefined4 *)(iVar6 + 100),uVar16);
      }
      uVar17 = (uVar12 >> 1) / 0x271;
      uVar16 = uVar7 - uVar17 & 0xfffffff;
      iVar15 = uVar17 * 0x271 + ((int)sVar10 - (uVar12 >> 1));
      if (iVar15 < 0) {
        uVar16 = uVar16 - 1 & 0xfffffff;
        iVar15 = iVar15 + 0x271;
      }
      *(int *)(iVar6 + 8) = iVar15;
      *(uint *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x5c) + uVar12;
    }
    uVar14 = (undefined2)iVar15;
    *(uint *)(iVar6 + 4) = uVar16;
    iVar13 = r_sch_arb_insert(iVar6);
    if (iVar13 == 0) {
      iVar11 = 1;
      goto _L191;
    }
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + rwip_priority;
    uVar7 = *(int *)(iVar6 + 100) + uVar7 & 0xfffffff;
    sVar10 = *(short *)(iVar6 + 0x7e);
    *(short *)(iVar6 + 0x7e) = sVar10 + 1;
    if (((*(char *)(iVar6 + 0x46) == '\x01') && (*(char *)(iVar6 + 0x43) == '\0')) &&
       ((ushort)(((sVar10 + 1) - *(short *)(iVar6 + 0x44)) + *(short *)(iVar6 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar6 + 0x42) == '\0') {
        uVar7 = *(ushort *)(iVar6 + 0x3c) + uVar7 & 0xfffffff;
        if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
          uVar7 = (*(ushort *)(iVar6 + 0x40) >> 1) + uVar7 & 0xfffffff;
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
      sVar10 = (*(short *)(iVar6 + 0x7c) + *(short *)(iVar6 + 0x7e)) - *(short *)(iVar6 + 0x44);
      uVar18 = uVar7;
      while (sVar10 = sVar10 + -1, sVar10 != -1) {
        uVar18 = uVar18 - *(int *)(iVar6 + 100) & 0xfffffff;
      }
    }
  }
  iVar11 = 0;
_L191:
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4043000d,iVar11 << 8 | param_1,*(undefined4 *)(iVar6 + 0x7c));
  }
  if (iVar11 != 0) {
    *(undefined1 *)(iVar6 + 0x8f) = 0;
    *(uint *)(iVar6 + 0x48) = uVar7;
    if ((*(ushort *)(iVar6 + 0x84) & 1) != 0) {
      uVar7 = (uint)DAT_00016066;
      *(undefined2 *)(iVar6 + 0x6c) = uVar14;
      *(uint *)(iVar6 + 0x4c) = uVar7 * 2 + uVar12;
    }
    return;
  }
  iVar11 = 8;
  if ((*(ushort *)(iVar6 + 0x84) & 2) == 0) {
    iVar11 = 0x3e;
  }
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    return;
  }
  iVar15 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar15 + 0x28) & 0x20) != 0) &&
     (iVar15 = r_sdk_config_get_opts_ext(), *(byte *)(iVar15 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar11 << 0x10 | 0x100U | param_1);
  }
  uVar12 = param_1 << 8 | 1;
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x212,uVar12,0xff,1);
  *puVar8 = (char)iVar11;
  r_ke_msg_send();
  iVar11 = r_co_list_pop_front(iVar6 + 0x28);
  do {
    if (*(char *)(iVar6 + 0x92) == '\0') {
      if (*(int *)(iVar6 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar6 + 0x24) + 4));
      }
      while (iVar11 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar11 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar12,0xff);
        }
        iVar11 = r_co_list_pop_front(iVar6 + 0x28);
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
    iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar13 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar13 + 2 + iVar15);
    if ((uVar3 & 3) == 3) {
      iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar13 + 4 + iVar15));
      uVar9 = 0x79f;
      if (*(int *)(iVar6 + 0x24) != 0) goto _L165;
    }
    else {
      uVar9 = 0x7a8;
      if ((uVar3 & 3) == 0) {
_L165:
        r_assert_err(0,"lld_con.c",uVar9);
      }
    }
    *(char *)(iVar6 + 0x92) = *(char *)(iVar6 + 0x92) + -1;
    *(byte *)(iVar6 + 0x90) = *(char *)(iVar6 + 0x90) + 1U & 1;
  } while( true );
}

