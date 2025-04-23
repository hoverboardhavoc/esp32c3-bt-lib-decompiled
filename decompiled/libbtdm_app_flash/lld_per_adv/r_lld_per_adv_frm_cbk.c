/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    uVar9 = param_2 & 0xff;
    if (param_3 != 0) {
      param_3 = 1;
    }
    iVar11 = *(int *)(&lld_per_adv_env + uVar9 * 4);
    iVar7 = r_sdk_config_get_opts_ext(param_1);
    if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x40480008,param_3 << 8 | uVar9,*(undefined2 *)(iVar11 + 0x4c));
    }
    if (periodic_adv_data_need_to_set[uVar9] != '\0') {
      *(undefined4 *)(iVar11 + 0x24) = 0;
      r_lld_per_adv_data_set(uVar9,0,0,1);
      periodic_adv_data_need_to_set[uVar9] = '\0';
    }
    iVar7 = *(int *)(&lld_per_adv_env + uVar9 * 4);
    if (iVar7 == 0) {
      r_assert_err(0,0x10000,0x43e);
      return;
    }
    r_sch_arb_remove(iVar7,1);
    if (*(char *)(iVar7 + 0x53) != '\x02') {
      bVar3 = *(byte *)(iVar7 + 0x52);
      if (*(short *)(iVar7 + 0x24) != 0) {
        r_lld_per_adv_data_set(uVar9,*(undefined1 *)(iVar7 + 0x26),1);
        *(undefined2 *)(iVar7 + 0x24) = 0;
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar11 = ((uint)bVar3 * 9 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar6 + iVar11);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar11) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((int)((uint)*(ushort *)(iVar11 + 6 + iVar6) << 0x13) < 0) {
        bVar3 = *(byte *)(iVar7 + 0x52);
        uVar9 = r_lld_ch_idx_get_hack();
        *(char *)(iVar7 + 0x57) = (char)uVar9;
        if (0x3f < uVar9) {
          r_assert_err(0,0x10000,0x2ea);
        }
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar4 = *(ushort *)(iVar6 + iVar11 + 8);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar6 + iVar11 + 8) = (ushort)uVar9 | uVar4 & 0xffc0;
        bVar1 = *(byte *)(iVar7 + 0x57);
        if ((bVar1 & 0xc0) != 0) {
          r_assert_err(0,0x10000,0x635);
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        iVar6 = (uint)bVar3 * 0x5a + 0x26;
        uVar4 = *(ushort *)(iVar11 + iVar6);
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar11 + iVar6) = uVar4 & 0x3ff | (ushort)bVar1 << 10;
        uVar9 = 0;
        while( true ) {
          bVar3 = *(byte *)(iVar7 + 0x52);
          uVar9 = uVar9 + 1 & 0xff;
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar11 = ((uint)bVar3 * 9 + uVar9 & 0xff) * 0xe;
          uVar4 = *(ushort *)(iVar6 + iVar11);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar11) = uVar4 & 0x7fff;
          if (uVar9 == *(byte *)(iVar7 + 0x58) - 1) break;
          bVar3 = *(byte *)(iVar7 + 0x57);
          if (0x3f < bVar3) {
            r_assert_err(0,0x10000,0x2ea);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar4 = *(ushort *)(iVar6 + iVar11 + 8);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar11 + 8) = (ushort)bVar3 | uVar4 & 0xffc0;
        }
      }
      bVar1 = DAT_0001301b;
      cVar10 = DAT_0001301a;
      if (param_3 != 0) {
        cVar10 = *(char *)(iVar7 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar7 + 0x16) = cVar10;
      bVar3 = *(byte *)(iVar7 + 0x52);
      *(ushort *)(iVar7 + 0x14) = bVar1 & 0xf | 0x2000;
r_lld_per_adv_sched:
      iVar7 = *(int *)(&lld_per_adv_env + (uint)bVar3 * 4);
      *(uint *)(iVar7 + 4) = *(int *)(iVar7 + 4) + *(int *)(iVar7 + 0x40) & 0xfffffff;
      *(short *)(iVar7 + 0x4c) = *(short *)(iVar7 + 0x4c) + 1;
      iVar11 = r_lld_read_clock();
      while ((iVar11 - *(int *)(iVar7 + 4) & 0xfffffffU) < 0x7ffffff) {
        *(uint *)(iVar7 + 4) = *(int *)(iVar7 + 4) + *(int *)(iVar7 + 0x40) & 0xfffffff;
        *(short *)(iVar7 + 0x4c) = *(short *)(iVar7 + 0x4c) + 1;
      }
      uVar9 = 0;
      do {
        iVar6 = r_sch_arb_insert(iVar7);
        if (iVar6 == 0) {
          iVar6 = 1;
          goto _L4;
        }
        uVar9 = uVar9 + 1 & 0xff;
        *(byte *)(iVar7 + 0x16) = *(char *)(iVar7 + 0x16) + DAT_0001301b;
        *(uint *)(iVar7 + 4) = *(int *)(iVar7 + 4) + *(int *)(iVar7 + 0x40) & 0xfffffff;
        *(short *)(iVar7 + 0x4c) = *(short *)(iVar7 + 0x4c) + 1;
      } while (uVar9 != 0xf);
      iVar6 = 0;
_L4:
      iVar5 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar5 + 0x28) & 0x40) != 0) &&
         (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x4048000b,
                   iVar6 << 8 | uVar9 << 0x10 | (uint)*(byte *)(iVar7 + 0x53) << 0x18 | (uint)bVar3)
        ;
      }
      if (iVar6 == 0) {
        r_assert_param(*(undefined4 *)(iVar7 + 4),iVar11,0x10000,0x13f);
        return;
      }
      *(undefined1 *)(iVar7 + 0x53) = 0;
      return;
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff);
    uVar2 = *(undefined1 *)(iVar7 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar2;
    r_ke_msg_send();
  }
  else {
    if (param_3 != 4) {
      r_assert_param(0x10000,0x493);
      return;
    }
    iVar7 = *(int *)(&lld_per_adv_env + (param_2 & 0xff) * 4);
    if (iVar7 == 0) {
      r_assert_err(0,0x10000,0x472);
      return;
    }
    iVar11 = r_sdk_config_get_opts_ext(4);
    if (((*(uint *)(iVar11 + 0x28) & 0x40) != 0) &&
       (iVar11 = r_sdk_config_get_opts_ext(), *(byte *)(iVar11 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x40480009,(uint)*(byte *)(iVar7 + 0x53) << 8 | param_2 & 0xff);
    }
    if (1 < (byte)(*(char *)(iVar7 + 0x53) - 1U)) {
      r_assert_err(0,0x10000,0x456);
    }
    r_sch_arb_remove(iVar7,1);
    if (*(char *)(iVar7 + 0x53) != '\x02') {
      bVar3 = *(byte *)(iVar7 + 0x52);
      *(char *)(iVar7 + 0x16) = *(char *)(iVar7 + 0x16) + rwip_priority;
      goto r_lld_per_adv_sched;
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff);
    uVar2 = *(undefined1 *)(iVar7 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar2;
    r_ke_msg_send();
  }
  param_2 = param_2 & 0xff;
  if (*(int *)(&lld_per_adv_env + param_2 * 4) == 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x40080004,param_2);
      return;
    }
  }
  else {
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40080002,
                 (uint)*(ushort *)(*(int *)(&lld_per_adv_env + param_2 * 4) + 0x4c) << 0x10 |
                 param_2);
    }
    r_ke_free(*(undefined4 *)(&lld_per_adv_env + param_2 * 4));
    *(undefined4 *)(&lld_per_adv_env + param_2 * 4) = 0;
  }
  return;
}

