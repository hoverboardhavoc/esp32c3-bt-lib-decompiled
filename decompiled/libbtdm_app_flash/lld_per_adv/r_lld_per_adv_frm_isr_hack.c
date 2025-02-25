/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
  ushort uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  
  iVar10 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar8 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar8 + 0x28) & 0x40) != 0) &&
     (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40480008,param_2 << 8 | param_1,*(undefined2 *)(iVar10 + 0x4c));
  }
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(iVar10 + 0x24) = 0;
    r_lld_per_adv_data_set(param_1,0,0,1,1);
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  iVar8 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar8 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x43e);
    return;
  }
  r_sch_arb_remove(iVar8,1);
  if (*(char *)(iVar8 + 0x53) == '\x02') {
    puVar5 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar8 + 0x52);
    puVar5[1] = 0;
    *puVar5 = uVar1;
    r_ke_msg_send();
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      iVar8 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar8 + 0x28) & 0x40) != 0) &&
         (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
    else {
      iVar8 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar8 + 0x28) & 0x40) != 0) &&
         (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
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
  bVar2 = *(byte *)(iVar8 + 0x52);
  if (*(short *)(iVar8 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar8 + 0x26),1,1);
    *(undefined2 *)(iVar8 + 0x24) = 0;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar10 = ((uint)bVar2 * 9 & 0xff) * 0xe;
  uVar3 = *(ushort *)(iVar6 + iVar10);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar6 + iVar10) = uVar3 & 0x7fff;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((int)((uint)*(ushort *)(iVar6 + iVar10 + 6) << 0x13) < 0) {
    bVar2 = *(byte *)(iVar8 + 0x52);
    uVar7 = r_lld_ch_idx_get_hack();
    *(char *)(iVar8 + 0x57) = (char)uVar7;
    if ((uVar7 & 0xffffffc0) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x2ea);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar6 + iVar10 + 8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar10 + 8 + iVar6) = uVar3 & 0xffc0 | (ushort)uVar7;
    uVar7 = (uint)*(byte *)(iVar8 + 0x57) << 10;
    if ((uVar7 & 0x30000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x635);
    }
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    iVar6 = (uint)bVar2 * 0x5a + 0x26;
    uVar3 = *(ushort *)(iVar10 + iVar6);
    iVar10 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar10 + iVar6) = uVar3 & 0x3ff | (ushort)uVar7;
    uVar7 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar8 + 0x52);
      uVar7 = uVar7 + 1 & 0xff;
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar10 = ((uint)bVar2 * 9 + uVar7 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar6 + iVar10);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar10) = uVar3 & 0x7fff;
      if (uVar7 == *(byte *)(iVar8 + 0x58) - 1) break;
      bVar2 = *(byte *)(iVar8 + 0x57);
      if ((bVar2 & 0xc0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x2ea);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar6 + iVar10 + 8);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar10 + 8 + iVar6) = uVar3 & 0xffc0 | (ushort)bVar2;
    }
  }
  bVar2 = DAT_0001301b;
  cVar9 = DAT_0001301a;
  if (param_2 != 0) {
    cVar9 = *(char *)(iVar8 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar8 + 0x16) = cVar9;
  *(ushort *)(iVar8 + 0x14) = bVar2 & 0xf | 0x2000;
  bVar2 = *(byte *)(iVar8 + 0x52);
  iVar8 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
  *(uint *)(iVar8 + 4) = *(int *)(iVar8 + 4) + *(int *)(iVar8 + 0x40) & 0xfffffff;
  *(short *)(iVar8 + 0x4c) = *(short *)(iVar8 + 0x4c) + 1;
  iVar10 = r_lld_read_clock();
  while ((iVar10 - *(int *)(iVar8 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar8 + 4) = *(int *)(iVar8 + 4) + *(int *)(iVar8 + 0x40) & 0xfffffff;
    *(short *)(iVar8 + 0x4c) = *(short *)(iVar8 + 0x4c) + 1;
  }
  uVar7 = 0;
  do {
    iVar6 = r_sch_arb_insert(iVar8);
    if (iVar6 == 0) {
      iVar6 = 1;
      goto _L4;
    }
    uVar7 = uVar7 + 1 & 0xff;
    *(byte *)(iVar8 + 0x16) = *(char *)(iVar8 + 0x16) + DAT_0001301b;
    *(uint *)(iVar8 + 4) = *(int *)(iVar8 + 4) + *(int *)(iVar8 + 0x40) & 0xfffffff;
    *(short *)(iVar8 + 0x4c) = *(short *)(iVar8 + 0x4c) + 1;
  } while (uVar7 != 0xf);
  iVar6 = 0;
_L4:
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar6 << 8 | uVar7 << 0x10 | (uint)*(byte *)(iVar8 + 0x53) << 0x18 | (uint)bVar2);
  }
  if (iVar6 == 0) {
    r_assert_param(*(undefined4 *)(iVar8 + 4),iVar10,"lld_per_adv.c",0x13f);
    return;
  }
  *(undefined1 *)(iVar8 + 0x53) = 0;
  return;
}

