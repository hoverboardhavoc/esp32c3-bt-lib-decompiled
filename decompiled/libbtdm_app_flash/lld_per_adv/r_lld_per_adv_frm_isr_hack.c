/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_isr_hack(uint param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  
  iVar11 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar9 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar9 + 0x28) & 0x40) != 0) &&
     (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40480008,param_2 << 8 | param_1,*(undefined2 *)(iVar11 + 0x4c));
  }
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(iVar11 + 0x24) = 0;
    r_lld_per_adv_data_set(param_1,0,0,1);
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  iVar9 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar9 == 0) {
    r_assert_err(0,0x10000,0x43e);
    return;
  }
  r_sch_arb_remove(iVar9,1);
  if (*(char *)(iVar9 + 0x53) == '\x02') {
    puVar6 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff);
    uVar1 = *(undefined1 *)(iVar9 + 0x52);
    puVar6[1] = 0;
    *puVar6 = uVar1;
    r_ke_msg_send();
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      iVar9 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar9 + 0x28) & 0x40) != 0) &&
         (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
    else {
      iVar9 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar9 + 0x28) & 0x40) != 0) &&
         (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40080002,
                   (uint)*(ushort *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x4c) << 0x10 |
                   param_1);
      }
      r_ke_free(*(undefined4 *)(&lld_per_adv_env + param_1 * 4));
      *(undefined4 *)(&lld_per_adv_env + param_1 * 4) = 0;
    }
    return;
  }
  bVar2 = *(byte *)(iVar9 + 0x52);
  if (*(short *)(iVar9 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar9 + 0x26),1);
    *(undefined2 *)(iVar9 + 0x24) = 0;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar11 = ((uint)bVar2 * 9 & 0xff) * 0xe;
  uVar4 = *(ushort *)(iVar7 + iVar11);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar11) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((int)((uint)*(ushort *)(iVar11 + 6 + iVar7) << 0x13) < 0) {
    bVar2 = *(byte *)(iVar9 + 0x52);
    uVar8 = r_lld_ch_idx_get_hack();
    *(char *)(iVar9 + 0x57) = (char)uVar8;
    if (0x3f < uVar8) {
      r_assert_err(0,0x10000,0x2ea);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar7 + iVar11 + 8);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar11 + 8) = (ushort)uVar8 | uVar4 & 0xffc0;
    bVar3 = *(byte *)(iVar9 + 0x57);
    if ((bVar3 & 0xc0) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    iVar7 = (uint)bVar2 * 0x5a + 0x26;
    uVar4 = *(ushort *)(iVar11 + iVar7);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar11 + iVar7) = uVar4 & 0x3ff | (ushort)bVar3 << 10;
    uVar8 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar9 + 0x52);
      uVar8 = uVar8 + 1 & 0xff;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar11 = ((uint)bVar2 * 9 + uVar8 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar7 + iVar11);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar11) = uVar4 & 0x7fff;
      if (uVar8 == *(byte *)(iVar9 + 0x58) - 1) break;
      bVar2 = *(byte *)(iVar9 + 0x57);
      if (0x3f < bVar2) {
        r_assert_err(0,0x10000,0x2ea);
      }
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar7 + iVar11 + 8);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + iVar11 + 8) = (ushort)bVar2 | uVar4 & 0xffc0;
    }
  }
  bVar2 = DAT_0001301b;
  cVar10 = DAT_0001301a;
  if (param_2 != 0) {
    cVar10 = *(char *)(iVar9 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar9 + 0x16) = cVar10;
  bVar3 = *(byte *)(iVar9 + 0x52);
  *(ushort *)(iVar9 + 0x14) = bVar2 & 0xf | 0x2000;
  iVar9 = *(int *)(&lld_per_adv_env + (uint)bVar3 * 4);
  *(uint *)(iVar9 + 4) = *(int *)(iVar9 + 4) + *(int *)(iVar9 + 0x40) & 0xfffffff;
  *(short *)(iVar9 + 0x4c) = *(short *)(iVar9 + 0x4c) + 1;
  iVar11 = r_lld_read_clock();
  while ((iVar11 - *(int *)(iVar9 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar9 + 4) = *(int *)(iVar9 + 4) + *(int *)(iVar9 + 0x40) & 0xfffffff;
    *(short *)(iVar9 + 0x4c) = *(short *)(iVar9 + 0x4c) + 1;
  }
  uVar8 = 0;
  do {
    iVar7 = r_sch_arb_insert(iVar9);
    if (iVar7 == 0) {
      iVar7 = 1;
      goto _L4;
    }
    uVar8 = uVar8 + 1 & 0xff;
    *(byte *)(iVar9 + 0x16) = *(char *)(iVar9 + 0x16) + DAT_0001301b;
    *(uint *)(iVar9 + 4) = *(int *)(iVar9 + 4) + *(int *)(iVar9 + 0x40) & 0xfffffff;
    *(short *)(iVar9 + 0x4c) = *(short *)(iVar9 + 0x4c) + 1;
  } while (uVar8 != 0xf);
  iVar7 = 0;
_L4:
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x40) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar7 << 8 | uVar8 << 0x10 | (uint)*(byte *)(iVar9 + 0x53) << 0x18 | (uint)bVar3);
  }
  if (iVar7 == 0) {
    r_assert_param(*(undefined4 *)(iVar9 + 4),iVar11,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar9 + 0x53) = 0;
  return;
}

