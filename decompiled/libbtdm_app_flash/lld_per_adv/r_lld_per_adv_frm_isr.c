/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_isr(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  char cVar11;
  
  iVar6 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,0x10000,0x453);
    return;
  }
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 0x53) == '\x02') {
    puVar8 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar1 = *(undefined1 *)(iVar6 + 0x52);
    puVar8[1] = 0;
    *puVar8 = uVar1;
    r_ke_msg_send();
    piVar5 = (int *)(&lld_per_adv_env + param_1 * 4);
    if (*piVar5 == 0) {
      r_ble_log_internal_x1(0x800400a6,param_1);
      return;
    }
    r_ble_log_internal_x1(0x400400a5,param_1 << 0x10 | (uint)*(ushort *)(*piVar5 + 0x4c));
    r_ke_free(*piVar5);
    *piVar5 = 0;
    return;
  }
  bVar2 = *(byte *)(iVar6 + 0x52);
  if (*(short *)(iVar6 + 0x24) != 0) {
    r_lld_per_adv_data_set(param_1,*(undefined1 *)(iVar6 + 0x26),1,1);
    *(undefined2 *)(iVar6 + 0x24) = 0;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar7 = ((uint)bVar2 * 9 & 0xff) * 0xe;
  uVar4 = *(ushort *)(iVar9 + iVar7);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar7) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  if ((*(ushort *)(iVar7 + 6 + iVar9) >> 0xc & 1) != 0) {
    bVar2 = *(byte *)(iVar6 + 0x52);
    uVar10 = r_lld_ch_idx_get_hack();
    *(char *)(iVar6 + 0x57) = (char)uVar10;
    if ((uVar10 & 0xffffffc0) != 0) {
      r_assert_err(0,0x10000,0x2ea);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar9 + iVar7 + 8);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar7 + 8) = uVar4 & 0xffc0 | (ushort)uVar10;
    uVar10 = (uint)*(byte *)(iVar6 + 0x57) << 10;
    if ((uVar10 & 0x30000) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    iVar9 = (uint)bVar2 * 0x5a + 0x26;
    uVar4 = *(ushort *)(iVar7 + iVar9);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar7 + iVar9) = uVar4 & 0x3ff | (ushort)uVar10;
    uVar10 = 0;
    while( true ) {
      bVar2 = *(byte *)(iVar6 + 0x52);
      uVar10 = uVar10 + 1 & 0xff;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = ((uint)bVar2 * 9 + uVar10 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar9 + iVar7);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar9 + iVar7) = uVar4 & 0x7fff;
      if (uVar10 == *(byte *)(iVar6 + 0x58) - 1) break;
      bVar2 = *(byte *)(iVar6 + 0x57);
      if ((bVar2 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x2ea);
      }
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar4 = *(ushort *)(iVar9 + iVar7 + 8);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar9 + iVar7 + 8) = uVar4 & 0xffc0 | (ushort)bVar2;
    }
  }
  bVar2 = DAT_0001301b;
  cVar11 = DAT_0001301a;
  if (param_2 != 0) {
    cVar11 = *(char *)(iVar6 + 0x16) + DAT_0001301b;
  }
  *(char *)(iVar6 + 0x16) = cVar11;
  bVar3 = *(byte *)(iVar6 + 0x52);
  *(ushort *)(iVar6 + 0x14) = bVar2 & 0xf | 0x2000;
  iVar6 = *(int *)(&lld_per_adv_env + (uint)bVar3 * 4);
  *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
  *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  iVar7 = r_lld_read_clock();
  while ((iVar7 - *(int *)(iVar6 + 4) & 0xfffffffU) < 0x7ffffff) {
    *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
    *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  }
  uVar10 = 0;
  do {
    iVar9 = r_sch_arb_insert(iVar6);
    if (iVar9 == 0) {
      iVar9 = 1;
      goto _L4;
    }
    uVar10 = uVar10 + 1 & 0xff;
    *(byte *)(iVar6 + 0x16) = *(char *)(iVar6 + 0x16) + DAT_0001301b;
    *(uint *)(iVar6 + 4) = *(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x40) & 0xfffffff;
    *(short *)(iVar6 + 0x4c) = *(short *)(iVar6 + 0x4c) + 1;
  } while (uVar10 != 0xf);
  iVar9 = 0;
_L4:
  r_ble_log_internal_x1
            (0x404400a2,
             (uint)*(byte *)(iVar6 + 0x53) << 0x18 | (uint)bVar3 | iVar9 << 8 | uVar10 << 0x10);
  if (iVar9 == 0) {
    r_assert_param(*(undefined4 *)(iVar6 + 4),iVar7,0x10000,0x13f);
    return;
  }
  *(undefined1 *)(iVar6 + 0x53) = 0;
  return;
}

