/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_cbk(undefined4 param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  char cVar10;
  
  if (param_3 != 1) {
    if (param_3 != 0) {
      if (param_3 == 2) {
        return;
      }
      if (param_3 != 4) {
        r_assert_param("lld_per_adv.c",0x493);
        return;
      }
      iVar4 = *(int *)(&lld_per_adv_env + (param_2 & 0xff) * 4);
      if (iVar4 == 0) {
        r_assert_err(0,"lld_per_adv.c",0x472);
        return;
      }
      iVar7 = r_sdk_config_get_opts_ext(4);
      if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
         (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40480009,(uint)*(byte *)(iVar4 + 0x53) << 8 | param_2 & 0xff);
      }
      if (1 < (byte)(*(char *)(iVar4 + 0x53) - 1U)) {
        r_assert_err(0,"lld_per_adv.c",0x456);
      }
      r_sch_arb_remove(iVar4,1);
      if (*(char *)(iVar4 + 0x53) != '\x02') {
        bVar2 = *(byte *)(iVar4 + 0x52);
        *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + rwip_priority;
        goto r_lld_per_adv_sched;
      }
      puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
      uVar1 = *(undefined1 *)(iVar4 + 0x52);
      puVar8[1] = 0;
      *puVar8 = uVar1;
      r_ke_msg_send();
      goto r_lld_per_adv_cleanup;
    }
    param_3 = 0;
  }
  uVar9 = param_2 & 0xff;
  iVar7 = *(int *)(&lld_per_adv_env + uVar9 * 4);
  iVar4 = r_sdk_config_get_opts_ext(param_1);
  if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40480008,param_3 << 8 | uVar9,*(undefined2 *)(iVar7 + 0x4c));
  }
  if (periodic_adv_data_need_to_set[uVar9] != '\0') {
    *(undefined4 *)(iVar7 + 0x24) = 0;
    r_lld_per_adv_data_set(uVar9,0,0,1,1);
    periodic_adv_data_need_to_set[uVar9] = '\0';
  }
  iVar4 = *(int *)(&lld_per_adv_env + uVar9 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x43e);
    return;
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 0x53) != '\x02') {
    bVar2 = *(byte *)(iVar4 + 0x52);
    if (*(short *)(iVar4 + 0x24) != 0) {
      r_lld_per_adv_data_set(uVar9,*(undefined1 *)(iVar4 + 0x26),1,1);
      *(undefined2 *)(iVar4 + 0x24) = 0;
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar7 = ((uint)bVar2 * 9 & 0xff) * 0xe;
    uVar3 = *(ushort *)(iVar5 + iVar7);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = uVar3 & 0x7fff;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    if ((int)((uint)*(ushort *)(iVar5 + iVar7 + 6) << 0x13) < 0) {
      bVar2 = *(byte *)(iVar4 + 0x52);
      uVar9 = r_lld_ch_idx_get_hack();
      *(char *)(iVar4 + 0x57) = (char)uVar9;
      if ((uVar9 & 0xffffffc0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x2ea);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar5 + iVar7 + 8);
      iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + 8 + iVar5) = uVar3 & 0xffc0 | (ushort)uVar9;
      uVar9 = (uint)*(byte *)(iVar4 + 0x57) << 10;
      if ((uVar9 & 0x30000) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x635);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      iVar5 = (uint)bVar2 * 0x5a + 0x26;
      uVar3 = *(ushort *)(iVar7 + iVar5);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar7 + iVar5) = uVar3 & 0x3ff | (ushort)uVar9;
      uVar9 = 0;
      while( true ) {
        bVar2 = *(byte *)(iVar4 + 0x52);
        uVar9 = uVar9 + 1 & 0xff;
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar7 = ((uint)bVar2 * 9 + uVar9 & 0xff) * 0xe;
        uVar3 = *(ushort *)(iVar5 + iVar7);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar5 + iVar7) = uVar3 & 0x7fff;
        if (uVar9 == *(byte *)(iVar4 + 0x58) - 1) break;
        bVar2 = *(byte *)(iVar4 + 0x57);
        if ((bVar2 & 0xc0) != 0) {
          r_assert_err(0,"lld_per_adv.c",0x2ea);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar5 + iVar7 + 8);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar7 + 8 + iVar5) = uVar3 & 0xffc0 | (ushort)bVar2;
      }
    }
    bVar2 = DAT_0001301b;
    cVar10 = DAT_0001301a;
    if (param_3 != 0) {
      cVar10 = *(char *)(iVar4 + 0x16) + DAT_0001301b;
    }
    *(char *)(iVar4 + 0x16) = cVar10;
    *(ushort *)(iVar4 + 0x14) = bVar2 & 0xf | 0x2000;
    bVar2 = *(byte *)(iVar4 + 0x52);
r_lld_per_adv_sched:
    iVar4 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    iVar7 = r_lld_read_clock();
    while ((iVar7 - *(int *)(iVar4 + 4) & 0xfffffffU) < 0x7ffffff) {
      *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
      *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    }
    uVar9 = 0;
    do {
      iVar5 = r_sch_arb_insert(iVar4);
      if (iVar5 == 0) {
        iVar5 = 1;
        goto _L4;
      }
      uVar9 = uVar9 + 1 & 0xff;
      *(byte *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_0001301b;
      *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
      *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
    } while (uVar9 != 0xf);
    iVar5 = 0;
_L4:
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 0x40) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x4048000b,
                 iVar5 << 8 | uVar9 << 0x10 | (uint)*(byte *)(iVar4 + 0x53) << 0x18 | (uint)bVar2);
    }
    if (iVar5 == 0) {
      r_assert_param(*(undefined4 *)(iVar4 + 4),iVar7,"lld_per_adv.c",0x13f);
      return;
    }
    *(undefined1 *)(iVar4 + 0x53) = 0;
    return;
  }
  puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
  uVar1 = *(undefined1 *)(iVar4 + 0x52);
  puVar8[1] = 0;
  *puVar8 = uVar1;
  r_ke_msg_send();
r_lld_per_adv_cleanup:
  param_2 = param_2 & 0xff;
  if (*(int *)(&lld_per_adv_env + param_2 * 4) == 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
      r_ble_log_internal_x1(0x40080004,param_2);
      return;
    }
  }
  else {
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
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

