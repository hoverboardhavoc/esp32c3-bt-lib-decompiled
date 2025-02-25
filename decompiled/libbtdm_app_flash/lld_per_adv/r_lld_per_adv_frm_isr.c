/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_isr(uint param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  char cVar10;
  
  iVar4 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,"lld_per_adv.c",0x43e);
    return;
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 0x53) == '\x02') {
    puVar7 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar4 + 0x52);
    puVar7[1] = 0;
    *puVar7 = uVar1;
    r_ke_msg_send();
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
    else {
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x40) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
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
  bVar2 = *(byte *)(iVar4 + 0x52);
  if (*(short *)(iVar4 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar4 + 0x26),1,1);
    *(undefined2 *)(iVar4 + 0x24) = 0;
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar5 = ((uint)bVar2 * 9 & 0xff) * 0xe;
  uVar3 = *(ushort *)(iVar8 + iVar5);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar8 + iVar5) = uVar3 & 0x7fff;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((int)((uint)*(ushort *)(iVar8 + iVar5 + 6) << 0x13) < 0) {
    bVar2 = *(byte *)(iVar4 + 0x52);
    uVar9 = r_lld_ch_idx_get_hack();
    *(char *)(iVar4 + 0x57) = (char)uVar9;
    if ((uVar9 & 0xffffffc0) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x2ea);
    }
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar8 + iVar5 + 8);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + 8 + iVar8) = uVar3 & 0xffc0 | (ushort)uVar9;
    uVar9 = (uint)*(byte *)(iVar4 + 0x57) << 10;
    if ((uVar9 & 0x30000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x635);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    iVar8 = (uint)bVar2 * 0x5a + 0x26;
    uVar3 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar8) = uVar3 & 0x3ff | (ushort)uVar9;
    uVar9 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar4 + 0x52);
      uVar9 = uVar9 + 1 & 0xff;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar5 = ((uint)bVar2 * 9 + uVar9 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar8 + iVar5);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar8 + iVar5) = uVar3 & 0x7fff;
      if (uVar9 == *(byte *)(iVar4 + 0x58) - 1) break;
      bVar2 = *(byte *)(iVar4 + 0x57);
      if ((bVar2 & 0xc0) != 0) {
        r_assert_err(0,"lld_per_adv.c",0x2ea);
      }
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar8 + iVar5 + 8);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + 8 + iVar8) = uVar3 & 0xffc0 | (ushort)bVar2;
    }
  }
  bVar2 = DAT_0001301b;
  cVar10 = DAT_0001301a;
  if (param_2 != 0) {
    cVar10 = *(char *)(iVar4 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar4 + 0x16) = cVar10;
  *(ushort *)(iVar4 + 0x14) = bVar2 & 0xf | 0x2000;
  bVar2 = *(byte *)(iVar4 + 0x52);
  iVar4 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
  *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
  *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  iVar5 = r_lld_read_clock();
  while ((iVar5 - *(int *)(iVar4 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  }
  uVar9 = 0;
  do {
    iVar8 = r_sch_arb_insert(iVar4);
    if (iVar8 == 0) {
      iVar8 = 1;
      goto _L4;
    }
    uVar9 = uVar9 + 1 & 0xff;
    *(byte *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_0001301b;
    *(uint *)(iVar4 + 4) = *(int *)(iVar4 + 4) + *(int *)(iVar4 + 0x40) & 0xfffffff;
    *(short *)(iVar4 + 0x4c) = *(short *)(iVar4 + 0x4c) + 1;
  } while (uVar9 != 0xf);
  iVar8 = 0;
_L4:
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x40) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar8 << 8 | uVar9 << 0x10 | (uint)*(byte *)(iVar4 + 0x53) << 0x18 | (uint)bVar2);
  }
  if (iVar8 == 0) {
    r_assert_param(*(undefined4 *)(iVar4 + 4),iVar5,"lld_per_adv.c",0x13f);
    return;
  }
  *(undefined1 *)(iVar4 + 0x53) = 0;
  return;
}

