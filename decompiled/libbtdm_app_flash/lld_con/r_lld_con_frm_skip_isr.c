/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010d38) */
/* WARNING: Removing unreachable block (ram,0x00010d3e) */
/* WARNING: Removing unreachable block (ram,0x00010d4a) */
/* WARNING: Removing unreachable block (ram,0x00010d50) */
/* WARNING: Removing unreachable block (ram,0x00010d52) */
/* WARNING: Removing unreachable block (ram,0x00010f50) */
/* WARNING: Removing unreachable block (ram,0x000110d4) */
/* WARNING: Removing unreachable block (ram,0x000110d8) */
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
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined4 uVar11;
  short sVar12;
  int iVar13;
  undefined2 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar6 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_con.c",0xc76);
    return;
  }
  iVar10 = r_lld_read_clock();
  if (1 < (byte)(*(char *)(iVar6 + 0x8f) - 1U)) {
    r_assert_err(0,"lld_con.c",0xc5d);
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x8f) == '\x02') {
    iVar6 = 0x16;
  }
  else {
    param_1 = (uint)*(byte *)(iVar6 + 0x8e);
    *(uint *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + *(int *)(iVar6 + 100) & 0xfffffff;
    cVar5 = rwip_priority;
    *(short *)(iVar6 + 0x7e) = *(short *)(iVar6 + 0x7e) + 1;
    *(char *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + cVar5;
    iVar8 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = *(ushort *)(iVar8 + 0x84);
    uVar7 = *(uint *)(iVar8 + 0x48);
    uVar17 = (uint)DAT_00016066 << 1;
    if ((uVar3 & 2) == 0) {
      *(undefined1 *)(iVar8 + 0x16) = 0x1f;
    }
    if ((uVar3 & 3) == 3) {
      *(undefined1 *)(iVar8 + 0x96) = 0;
    }
    for (; (iVar10 - uVar7 & 0xfffffff) < 0x7ffffff;
        uVar7 = *(int *)(iVar8 + 100) + uVar7 & 0xfffffff) {
      *(short *)(iVar8 + 0x7e) = *(short *)(iVar8 + 0x7e) + 1;
    }
    uVar18 = *(uint *)(iVar8 + 0x58);
    if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x43) == '\0')) &&
       ((ushort)((*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44)) <
        0x7fff)) {
      if (*(char *)(iVar8 + 0x42) == '\0') {
        uVar7 = *(ushort *)(iVar8 + 0x3c) + uVar7 & 0xfffffff;
        if ((uVar3 & 1) != 0) {
          uVar7 = (*(ushort *)(iVar8 + 0x40) >> 1) + uVar7 & 0xfffffff;
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
      sVar12 = (*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44);
      uVar18 = uVar7;
      while (sVar12 = sVar12 + -1, sVar12 != -1) {
        uVar18 = uVar18 - *(int *)(iVar8 + 100) & 0xfffffff;
      }
    }
    if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
      uVar19 = *(int *)(iVar8 + 100) * 6;
    }
    else {
      uVar19 = *(uint *)(iVar8 + 0x68);
    }
    iVar6 = (param_1 + 0x10) * 2;
    iVar10 = 0;
    while (uVar14 = (undefined2)iVar10, (uVar7 - uVar18 & 0xfffffff) <= uVar19) {
      uVar15 = uVar7;
      if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
        iVar13 = *(int *)(iVar8 + 0x50);
        sVar12 = *(short *)(iVar8 + 0x6e);
        iVar10 = r_rwip_active_check();
        uVar17 = 0x14;
        if (iVar10 == 0) {
          uVar17 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        uVar15 = ((*(ushort *)(iVar8 + 0x7a) + uVar17) * (uVar7 - iVar13 & 0xfffffff)) / 0x640 +
                 0x40;
        uVar17 = uVar15 * 2;
        if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
          uVar17 = uVar17 + (uint)*(ushort *)(iVar8 + 0x70) * 0x271;
_L247:
          bVar4 = true;
        }
        else {
          bVar4 = false;
          if (*(ushort *)(iVar8 + 0x7c) < 7) {
            uVar17 = uVar17 + ((int)((uint)*(ushort *)(&DAT_00015038 + iVar6) *
                                     (uint)*(ushort *)(iVar8 + 0x70) * 0x271) >> 1) +
                              (uint)*(ushort *)(iVar8 + 0x70) * 0x271;
            uVar16 = *(int *)(iVar8 + 100) * 0x271;
            if (uVar16 < uVar17) {
              uVar17 = uVar16;
            }
            *(ushort *)(&DAT_00015038 + iVar6) = *(ushort *)(&DAT_00015038 + iVar6) + 1;
            goto _L247;
          }
        }
        if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x42) != '\0')) &&
           (*(char *)(iVar8 + 0x43) == '\0')) {
          uVar17 = uVar17 + (uint)*(ushort *)(iVar8 + 0x40) * 0x271;
        }
        else if ((((!bVar4) && (((uint)(*(int *)(iVar8 + 100) * 0x271) >> 1) - 300 <= uVar15)) &&
                 (iVar10 = r_sdk_config_get_opts_ext(), (*(uint *)(iVar10 + 0x28) & 0x20) != 0)) &&
                (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x4043000f,(uint)*(ushort *)(iVar8 + 0x7c) << 0x10 | param_1,
                     *(undefined4 *)(iVar8 + 100),uVar15);
        }
        uVar16 = (uVar17 >> 1) / 0x271;
        uVar15 = uVar7 - uVar16 & 0xfffffff;
        iVar10 = uVar16 * 0x271 + ((int)sVar12 - (uVar17 >> 1));
        if (iVar10 < 0) {
          uVar15 = uVar15 - 1 & 0xfffffff;
          iVar10 = iVar10 + 0x271;
        }
        *(int *)(iVar8 + 8) = iVar10;
        *(uint *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x5c) + uVar17;
      }
      uVar14 = (undefined2)iVar10;
      *(uint *)(iVar8 + 4) = uVar15;
      iVar13 = r_sch_arb_insert(iVar8);
      if (iVar13 == 0) {
        iVar6 = 1;
        goto _L191;
      }
      *(char *)(iVar8 + 0x16) = *(char *)(iVar8 + 0x16) + rwip_priority;
      uVar7 = *(int *)(iVar8 + 100) + uVar7 & 0xfffffff;
      sVar12 = *(short *)(iVar8 + 0x7e);
      *(short *)(iVar8 + 0x7e) = sVar12 + 1;
      if (((*(char *)(iVar8 + 0x46) == '\x01') && (*(char *)(iVar8 + 0x43) == '\0')) &&
         ((ushort)(((sVar12 + 1) - *(short *)(iVar8 + 0x44)) + *(short *)(iVar8 + 0x7c)) < 0x7fff))
      {
        if (*(char *)(iVar8 + 0x42) == '\0') {
          uVar7 = *(ushort *)(iVar8 + 0x3c) + uVar7 & 0xfffffff;
          if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
            uVar7 = (*(ushort *)(iVar8 + 0x40) >> 1) + uVar7 & 0xfffffff;
          }
          *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(iVar8 + 0x34);
          *(undefined2 *)(iVar8 + 0x72) = *(undefined2 *)(iVar8 + 0x3e);
          *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(iVar8 + 0x38);
          if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
            r_lld_con_max_lat_calc(*(undefined1 *)(iVar8 + 0x8e));
          }
          *(undefined1 *)(iVar8 + 0x42) = 1;
          uVar19 = *(uint *)(iVar8 + 0x68);
          if ((*(ushort *)(iVar8 + 0x84) & 1) == 0) {
            *(undefined1 *)(iVar8 + 0x43) = 1;
          }
        }
        sVar12 = (*(short *)(iVar8 + 0x7c) + *(short *)(iVar8 + 0x7e)) - *(short *)(iVar8 + 0x44);
        uVar18 = uVar7;
        while (sVar12 = sVar12 + -1, sVar12 != -1) {
          uVar18 = uVar18 - *(int *)(iVar8 + 100) & 0xfffffff;
        }
      }
    }
    iVar6 = 0;
_L191:
    iVar10 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar10 + 0x28) & 0x20) != 0) &&
       (iVar10 = r_sdk_config_get_opts_ext(), *(byte *)(iVar10 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x4043000d,iVar6 << 8 | param_1,*(undefined4 *)(iVar8 + 0x7c));
    }
    if (iVar6 != 0) {
      *(undefined1 *)(iVar8 + 0x8f) = 0;
      *(uint *)(iVar8 + 0x48) = uVar7;
      if ((*(ushort *)(iVar8 + 0x84) & 1) != 0) {
        uVar7 = (uint)DAT_00016066;
        *(undefined2 *)(iVar8 + 0x6c) = uVar14;
        *(uint *)(iVar8 + 0x4c) = uVar7 * 2 + uVar17;
      }
      return;
    }
    iVar6 = 8;
    if ((*(ushort *)(iVar8 + 0x84) & 2) == 0) {
      iVar6 = 0x3e;
    }
  }
  iVar10 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar10 == 0) {
    return;
  }
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x20) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40030003,iVar6 << 0x10 | 0x100U | param_1);
  }
  uVar17 = param_1 << 8 | 1;
  puVar9 = (undefined1 *)r_ke_msg_alloc(0x212,uVar17,0xff,1);
  *puVar9 = (char)iVar6;
  r_ke_msg_send();
  iVar6 = r_co_list_pop_front(iVar10 + 0x28);
  do {
    if (*(char *)(iVar10 + 0x92) == '\0') {
      if (*(int *)(iVar10 + 0x24) != 0) {
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(*(int *)(iVar10 + 0x24) + 4));
      }
      while (iVar6 != 0) {
        r_ble_util_buf_acl_tx_free_in_isr(*(undefined2 *)(iVar6 + 4));
        if (DAT_0001608d != '\0') {
          r_ke_msg_send_basic(0x20e,uVar17,0xff);
        }
        iVar6 = r_co_list_pop_front(iVar10 + 0x28);
      }
      r_sch_slice_per_remove(4,param_1);
      r_ke_free(*(undefined4 *)(&lld_con_env + param_1 * 4));
      *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
      (&g_event_empty)[param_1] = 0;
      r_bt_rtp_deregister_rule_cs_idx(param_1);
      r_bt_rma_deregister_rule_cs_idx(param_1);
      return;
    }
    bVar1 = *(byte *)(iVar10 + 0x8e);
    bVar2 = *(byte *)(iVar10 + 0x90);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar13 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar13 + 2 + iVar8);
    if ((uVar3 & 3) == 3) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar13 + 4 + iVar8));
      uVar11 = 0x79f;
      if (*(int *)(iVar10 + 0x24) != 0) goto _L165;
    }
    else {
      uVar11 = 0x7a8;
      if ((uVar3 & 3) == 0) {
_L165:
        r_assert_err(0,"lld_con.c",uVar11);
      }
    }
    *(char *)(iVar10 + 0x92) = *(char *)(iVar10 + 0x92) + -1;
    *(byte *)(iVar10 + 0x90) = *(char *)(iVar10 + 0x90) + 1U & 1;
  } while( true );
}

