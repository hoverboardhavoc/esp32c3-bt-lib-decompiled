/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  char cVar11;
  
  iVar5 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar5 == 0) {
    r_assert_err(0,0x10000,0x43e);
    return;
  }
  r_sch_arb_remove(iVar5,1);
  if (*(char *)(iVar5 + 0x53) == '\x02') {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar5 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
    r_ke_msg_send();
    if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar5 + 0x28) & 0x40) != 0) &&
         (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
    else {
      iVar5 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar5 + 0x28) & 0x40) != 0) &&
         (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
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
  bVar2 = *(byte *)(iVar5 + 0x52);
  if (*(short *)(iVar5 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar5 + 0x26),1,1);
    *(undefined2 *)(iVar5 + 0x24) = 0;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar6 = ((uint)bVar2 * 9 & 0xff) * 0xe;
  uVar4 = *(ushort *)(iVar9 + iVar6);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar6) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar6 + 6 + iVar9) >> 0xc & 1) != 0) {
    bVar2 = *(byte *)(iVar5 + 0x52);
    uVar10 = r_lld_ch_idx_get_hack();
    *(char *)(iVar5 + 0x57) = (char)uVar10;
    if ((uVar10 & 0xffffffc0) != 0) {
      r_assert_err(0,0x10000,0x2ea);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar9 + iVar6 + 8);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar6 + 8) = uVar4 & 0xffc0 | (ushort)uVar10;
    uVar10 = (uint)*(byte *)(iVar5 + 0x57) << 10;
    if ((uVar10 & 0x30000) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    iVar9 = (uint)bVar2 * 0x5a + 0x26;
    uVar4 = *(ushort *)(iVar6 + iVar9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar9) = uVar4 & 0x3ff | (ushort)uVar10;
    uVar10 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar5 + 0x52);
      uVar10 = uVar10 + 1 & 0xff;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar6 = ((uint)bVar2 * 9 + uVar10 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar9 + iVar6);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar9 + iVar6) = uVar4 & 0x7fff;
      if (uVar10 == *(byte *)(iVar5 + 0x58) - 1) break;
      bVar2 = *(byte *)(iVar5 + 0x57);
      if ((bVar2 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x2ea);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar9 + iVar6 + 8);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar9 + iVar6 + 8) = uVar4 & 0xffc0 | (ushort)bVar2;
    }
  }
  bVar2 = DAT_0001301b;
  cVar11 = DAT_0001301a;
  if (param_2 != 0) {
    cVar11 = *(char *)(iVar5 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar5 + 0x16) = cVar11;
  bVar3 = *(byte *)(iVar5 + 0x52);
  *(ushort *)(iVar5 + 0x14) = bVar2 & 0xf | 0x2000;
  iVar5 = *(int *)(&lld_per_adv_env + (uint)bVar3 * 4);
  *(uint *)(iVar5 + 4) = *(int *)(iVar5 + 4) + *(int *)(iVar5 + 0x40) & 0xfffffff;
  *(short *)(iVar5 + 0x4c) = *(short *)(iVar5 + 0x4c) + 1;
  iVar6 = r_lld_read_clock();
  while ((iVar6 - *(int *)(iVar5 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar5 + 4) = *(int *)(iVar5 + 4) + *(int *)(iVar5 + 0x40) & 0xfffffff;
    *(short *)(iVar5 + 0x4c) = *(short *)(iVar5 + 0x4c) + 1;
  }
  uVar10 = 0;
  do {
    iVar9 = r_sch_arb_insert(iVar5);
    if (iVar9 == 0) {
      iVar9 = 1;
      goto _L4;
    }
    uVar10 = uVar10 + 1 & 0xff;
    *(byte *)(iVar5 + 0x16) = *(char *)(iVar5 + 0x16) + DAT_0001301b;
    *(uint *)(iVar5 + 4) = *(int *)(iVar5 + 4) + *(int *)(iVar5 + 0x40) & 0xfffffff;
    *(short *)(iVar5 + 0x4c) = *(short *)(iVar5 + 0x4c) + 1;
  } while (uVar10 != 0xf);
  iVar9 = 0;
_L4:
  iVar7 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar7 + 0x28) & 0x40) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x4048000b,
               iVar9 << 8 | uVar10 << 0x10 | (uint)*(byte *)(iVar5 + 0x53) << 0x18 | (uint)bVar3);
  }
  if (iVar9 == 0) {
    r_assert_param(*(undefined4 *)(iVar5 + 4),iVar6,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar5 + 0x53) = 0;
  return;
}

