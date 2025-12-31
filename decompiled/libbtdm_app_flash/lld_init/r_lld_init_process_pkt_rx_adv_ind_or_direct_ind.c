/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_rx_adv_ind_or_direct_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_adv_ind_or_direct_ind(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *__src;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  iVar9 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar6 = (uint)bVar1 * 0x14;
  iVar11 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar10 = iVar6 + 4;
  if ((*(ushort *)(iVar7 + iVar10) & 0xe) != 0) {
    r_assert_err(0,0x10000,0x292);
    return;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar7 + iVar10);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar4 = *(ushort *)(iVar6 + 6 + iVar7);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = *(ushort *)(iVar6 + 10 + iVar7);
  uVar13 = (uint)(uVar4 >> 0xe);
  if ((uVar5 & 0xf000) != 0) {
    r_assert_err(0,0x10000,1000);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar12 = CONCAT22(uVar5,*(undefined2 *)(iVar6 + 8 + iVar7));
  bVar2 = *(byte *)(_p_lld_env + 0xd8);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = *(ushort *)((uint)bVar2 * 0x14 + 0xc + iVar7);
  iVar7 = r_co_ble_pkt_dur_in_us(uVar3 >> 8,uVar13);
  uVar3 = *(ushort *)(&lld_exp_sync_pos_tab + uVar13 * 2);
  iVar8 = r_co_ble_pkt_dur_in_us(0x22,uVar13);
  iVar7 = ((iVar7 - (uint)uVar3) + 0x96 + iVar8) * 2 + (0x270 - (uVar5 & 0x3ff));
  *(uint *)(iVar9 + 0x54) = (iVar7 + 0x270U) / 0x271 + uVar12 & 0xfffffff;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  *(undefined2 *)(iVar9 + 0x4c) = *(undefined2 *)(iVar6 + 0xe + iVar8);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar6 + iVar10);
  *(byte *)(iVar9 + 0x4e) = (byte)(uVar4 >> 0xe);
  *(byte *)(iVar9 + 0x58) = (byte)(uVar3 >> 5) & 1;
  __src = (void *)r_emi_get_mem_addr_by_offset(param_2);
  memcpy((void *)(iVar11 + 0x32),__src,6);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar6 + iVar10);
  *(undefined1 *)(iVar9 + 0x59) = 0;
  *(byte *)(iVar9 + 0x33) = (byte)(uVar3 >> 6) & 1;
  *(undefined1 *)(iVar9 + 0x50) = 1;
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar13 = iVar7 + uVar12 * 0x271;
  r_ble_log_internal_x2
            (0x408200fb,
             ((uint)(uVar13 < uVar12 * 0x271) + (int)((ulonglong)uVar12 * 0x271 >> 0x20)) *
             -0x80000000 | uVar13 >> 1,
             (uint)*(byte *)(iVar11 + 0x52) << 0x10 | (uint)bVar1 << 0x18 |
             (uint)*(ushort *)(iVar9 + iVar10));
  return;
}

