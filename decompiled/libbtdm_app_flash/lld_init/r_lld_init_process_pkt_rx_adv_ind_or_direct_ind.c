/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *__src;
  int iVar12;
  int iVar13;
  
  iVar7 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar13 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar9 = (uint)bVar1 * 0x14;
  iVar12 = iVar9 + 4;
  if ((*(ushort *)(iVar10 + iVar12) & 0xe) != 0) {
    r_assert_err(0,"lld_init.c",0x28d);
    return;
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar10 + iVar12);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar10 + iVar9 + 6);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar4 = *(ushort *)(iVar10 + iVar9 + 10);
  uVar8 = (uint)(uVar3 >> 0xe);
  if ((uVar4 & 0xf000) != 0) {
    r_assert_err(0,"lld_init.c",1000);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = *(undefined2 *)(iVar10 + iVar9 + 8);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar6 = *(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar10);
  iVar10 = r_co_ble_pkt_dur_in_us(uVar2 >> 8,uVar8);
  uVar2 = *(ushort *)(&lld_exp_sync_pos_tab + uVar8 * 2);
  iVar11 = r_co_ble_pkt_dur_in_us(0x22,uVar8);
  *(uint *)(iVar7 + 0x54) =
       (((iVar11 + (iVar10 - (uint)uVar2) + 0x96) * 2 - (uVar6 & 0x3ff)) + 0x4e0) / 0x271 +
       CONCAT22(uVar4,uVar5) & 0xfffffff;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  *(undefined2 *)(iVar7 + 0x4c) = *(undefined2 *)(iVar9 + 0xe + iVar10);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar9 + iVar12);
  *(byte *)(iVar7 + 0x4e) = (byte)(uVar3 >> 0xe);
  *(byte *)(iVar7 + 0x58) = (byte)(uVar2 >> 5) & 1;
  __src = (void *)r_emi_get_mem_addr_by_offset(param_2);
  memcpy((void *)(iVar13 + 0x32),__src,6);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar9 + iVar12);
  *(undefined1 *)(iVar7 + 0x59) = 0;
  *(byte *)(iVar7 + 0x33) = (byte)(uVar2 >> 6) & 1;
  *(undefined1 *)(iVar7 + 0x50) = 1;
  return;
}

