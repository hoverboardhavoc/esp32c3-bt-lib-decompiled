/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_isr_hack(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  int *piVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  int iVar15;
  
  iVar15 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar15 != 0) {
    bVar3 = *(byte *)(iVar15 + 0x52);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    iVar9 = (uint)bVar3 * 0x5a;
    uVar4 = *(ushort *)(iVar9 + 0x16 + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = *(ushort *)(iVar11 + iVar9 + 4);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar7 = *(undefined2 *)(iVar9 + 0xe + iVar11);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(uint *)(iVar15 + 4) * 0x271;
    uVar12 = *(int *)(iVar15 + 8) + uVar14;
    r_ble_log_internal_x4
              (0x404400a3,CONCAT22(uVar7,*(undefined2 *)(iVar9 + 0xc + iVar11)),
               uVar12 >> 1 |
               ((uint)(uVar12 < uVar14) + (int)((ulonglong)*(uint *)(iVar15 + 4) * 0x271 >> 0x20)) *
               -0x80000000,
               (uint)*(ushort *)(iVar15 + 0x4c) | param_2 << 0x18 |
               (uint)*(byte *)(iVar15 + 0x52) << 0x10,
               uVar4 & 0x3f | ((uVar5 & 0xc) << 2 | uVar6 & 3) << 8);
  }
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(iVar15 + 0x24) = 0;
    r_lld_per_adv_data_set(param_1,0,0,1,1);
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  iVar15 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar15 == 0) {
    r_assert_err(0,0x10000,0x453);
    return;
  }
  r_sch_arb_remove(iVar15,1);
  if (*(char *)(iVar15 + 0x53) == '\x02') {
    puVar10 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar15 + 0x52);
    puVar10[1] = 0;
    *puVar10 = uVar1;
    r_ke_msg_send();
    piVar8 = (int *)(&lld_per_adv_env + param_1 * 4);
    if (*piVar8 == 0) {
      r_ble_log_internal_x1(0x800400a6,param_1);
      return;
    }
    r_ble_log_internal_x1(0x400400a5,param_1 << 0x10 | (uint)*(ushort *)(*piVar8 + 0x4c));
    r_ke_free(*piVar8);
    *piVar8 = 0;
    return;
  }
  bVar3 = *(byte *)(iVar15 + 0x52);
  if (*(short *)(iVar15 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar15 + 0x26),1,1);
    *(undefined2 *)(iVar15 + 0x24) = 0;
  }
  iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar9 = ((uint)bVar3 * 9 & 0xff) * 0xe;
  uVar4 = *(ushort *)(iVar11 + iVar9);
  iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar11 + iVar9) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar9 + 6 + iVar11) >> 0xc & 1) != 0) {
    bVar3 = *(byte *)(iVar15 + 0x52);
    uVar12 = r_lld_ch_idx_get_hack();
    *(char *)(iVar15 + 0x57) = (char)uVar12;
    if ((uVar12 & 0xffffffc0) != 0) {
      r_assert_err(0,0x10000,0x2ea);
    }
    iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar11 + iVar9 + 8);
    iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar11 + iVar9 + 8) = uVar4 & 0xffc0 | (ushort)uVar12;
    uVar12 = (uint)*(byte *)(iVar15 + 0x57) << 10;
    if ((uVar12 & 0x30000) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    iVar11 = (uint)bVar3 * 0x5a + 0x26;
    uVar4 = *(ushort *)(iVar9 + iVar11);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar9 + iVar11) = uVar4 & 0x3ff | (ushort)uVar12;
    uVar12 = 0;
    while( true ) {
      bVar3 = *(byte *)(iVar15 + 0x52);
      uVar12 = uVar12 + 1 & 0xff;
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = ((uint)bVar3 * 9 + uVar12 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar11 + iVar9);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar11 + iVar9) = uVar4 & 0x7fff;
      if (uVar12 == *(byte *)(iVar15 + 0x58) - 1) break;
      bVar3 = *(byte *)(iVar15 + 0x57);
      if ((bVar3 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x2ea);
      }
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar11 + iVar9 + 8);
      iVar11 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar11 + iVar9 + 8) = uVar4 & 0xffc0 | (ushort)bVar3;
    }
  }
  bVar3 = DAT_0001301b;
  cVar13 = DAT_0001301a;
  if (param_2 != 0) {
    cVar13 = *(char *)(iVar15 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar15 + 0x16) = cVar13;
  bVar2 = *(byte *)(iVar15 + 0x52);
  *(ushort *)(iVar15 + 0x14) = bVar3 & 0xf | 0x2000;
  iVar15 = *(int *)(&lld_per_adv_env + (uint)bVar2 * 4);
  *(uint *)(iVar15 + 4) = *(int *)(iVar15 + 4) + *(int *)(iVar15 + 0x40) & 0xfffffff;
  *(short *)(iVar15 + 0x4c) = *(short *)(iVar15 + 0x4c) + 1;
  iVar9 = r_lld_read_clock();
  while ((iVar9 - *(int *)(iVar15 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar15 + 4) = *(int *)(iVar15 + 4) + *(int *)(iVar15 + 0x40) & 0xfffffff;
    *(short *)(iVar15 + 0x4c) = *(short *)(iVar15 + 0x4c) + 1;
  }
  uVar12 = 0;
  do {
    iVar11 = r_sch_arb_insert(iVar15);
    if (iVar11 == 0) {
      iVar11 = 1;
      goto _L4;
    }
    uVar12 = uVar12 + 1 & 0xff;
    *(byte *)(iVar15 + 0x16) = *(char *)(iVar15 + 0x16) + DAT_0001301b;
    *(uint *)(iVar15 + 4) = *(int *)(iVar15 + 4) + *(int *)(iVar15 + 0x40) & 0xfffffff;
    *(short *)(iVar15 + 0x4c) = *(short *)(iVar15 + 0x4c) + 1;
  } while (uVar12 != 0xf);
  iVar11 = 0;
_L4:
  r_ble_log_internal_x1
            (0x404400a2,
             (uint)*(byte *)(iVar15 + 0x53) << 0x18 | (uint)bVar2 | iVar11 << 8 | uVar12 << 0x10);
  if (iVar11 == 0) {
    r_assert_param(*(undefined4 *)(iVar15 + 4),iVar9,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar15 + 0x53) = 0;
  return;
}

