/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
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
      r_lld_per_adv_data_set(uVar9,0,0,1,1);
      periodic_adv_data_need_to_set[uVar9] = '\0';
    }
    iVar7 = *(int *)(&lld_per_adv_env + uVar9 * 4);
    if (iVar7 == 0) {
      r_assert_err(0,0x10000,0x43e);
      return;
    }
    r_sch_arb_remove(iVar7,1);
    if (*(char *)(iVar7 + 0x53) != '\x02') {
      bVar2 = *(byte *)(iVar7 + 0x52);
      if (*(short *)(iVar7 + 0x24) != 0) {
        r_lld_per_adv_data_set(uVar9,*(undefined1 *)(iVar7 + 0x26),1,1);
        *(undefined2 *)(iVar7 + 0x24) = 0;
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar11 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar6 + iVar11);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar11) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((*(ushort *)(iVar11 + 6 + iVar6) >> 0xc & 1) != 0) {
        bVar2 = *(byte *)(iVar7 + 0x52);
        uVar9 = r_lld_ch_idx_get_hack();
        *(char *)(iVar7 + 0x57) = (char)uVar9;
        if ((uVar9 & 0xffffffc0) != 0) {
          r_assert_err(0,0x10000,0x2ea);
        }
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar6 + iVar11 + 8);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar6 + iVar11 + 8) = uVar3 & 0xffc0 | (ushort)uVar9;
        uVar9 = (uint)*(byte *)(iVar7 + 0x57) << 10;
        if ((uVar9 & 0x30000) != 0) {
          r_assert_err(0,0x10000,0x635);
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        iVar6 = (uint)bVar2 * 0x5a + 0x26;
        uVar3 = *(ushort *)(iVar11 + iVar6);
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar11 + iVar6) = uVar3 & 0x3ff | (ushort)uVar9;
        uVar9 = 0;
        while( true ) {
          bVar2 = *(byte *)(iVar7 + 0x52);
          uVar9 = uVar9 + 1 & 0xff;
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar11 = ((uint)bVar2 * 9 + uVar9 & 0xff) * 0xe;
          uVar3 = *(ushort *)(iVar6 + iVar11);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar11) = uVar3 & 0x7fff;
          if (uVar9 == *(byte *)(iVar7 + 0x58) - 1) break;
          bVar2 = *(byte *)(iVar7 + 0x57);
          if ((bVar2 & 0xc0) != 0) {
            r_assert_err(0,0x10000,0x2ea);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar3 = *(ushort *)(iVar6 + iVar11 + 8);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar6 + iVar11 + 8) = uVar3 & 0xffc0 | (ushort)bVar2;
        }
      }
      bVar4 = DAT_0001301b;
      cVar10 = DAT_0001301a;
      if (param_3 != 0) {
        cVar10 = *(char *)(iVar7 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar7 + 0x16) = cVar10;
      bVar2 = *(byte *)(iVar7 + 0x52);
      *(ushort *)(iVar7 + 0x14) = bVar4 & 0xf | 0x2000;
r_lld_per_adv_sched:
      iVar7 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
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
                   iVar6 << 8 | uVar9 << 0x10 | (uint)*(byte *)(iVar7 + 0x53) << 0x18 | (uint)bVar2)
        ;
      }
      if (iVar6 == 0) {
        r_assert_param(*(undefined4 *)(iVar7 + 4),iVar11,0x10000,0x13f);
        return;
      }
      *(undefined1 *)(iVar7 + 0x53) = 0;
      return;
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar7 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
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
      bVar2 = *(byte *)(iVar7 + 0x52);
      *(char *)(iVar7 + 0x16) = *(char *)(iVar7 + 0x16) + rwip_priority;
      goto r_lld_per_adv_sched;
    }
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar7 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
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

