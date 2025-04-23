/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_rx_adv_ext_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_adv_ext_ind(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint auStack_24 [2];
  
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar9 = (uint)bVar1 * 0x14;
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar9 + 0x10 + iVar3);
  uVar10 = (uint)uVar2;
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar9 + 4 + iVar3) & 0xf) != 7) {
    r_assert_err(0,0x10000,0x2bf);
    return;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 0;
  iVar3 = 0;
  if ((uVar2 & 0x100) != 0) {
    pvVar4 = (void *)r_emi_get_mem_addr_by_offset(param_2);
    memcpy((void *)(iVar11 + 0x32),pvVar4,6);
    iVar3 = 6;
  }
  if ((uVar2 & 0x200) != 0) {
    iVar3 = iVar3 + 6;
  }
  iVar3 = iVar3 + (uint)((uVar2 & 0x400) != 0);
  if ((uVar10 & 0x1800) != 0x1800) {
    if ((int)(uVar10 << 0x14) < 0) {
      puVar5 = (undefined2 *)r_emi_get_mem_addr_by_offset(param_2 + iVar3 & 0xffff);
      iVar3 = iVar3 + 2;
      *(undefined2 *)(iVar11 + 0x3a) = *puVar5;
    }
    goto _L117;
  }
  puVar5 = (undefined2 *)r_emi_get_mem_addr_by_offset(param_2 + iVar3 & 0xffff);
  *(undefined2 *)(iVar11 + 0x38) = *puVar5;
  pvVar4 = (void *)r_emi_get_mem_addr_by_offset(iVar3 + 2 + param_2 & 0xffff);
  memcpy(auStack_24,pvVar4,3);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar9 + 2 + iVar6) >> 9 & 1) == 0) {
    if ((auStack_24[0] >> 0x15 & 7) < 3) {
      iVar9 = r_lld_calc_aux_rx(iVar11 + 0x40,(uint)bVar1);
      uVar8 = 1;
      if (iVar9 != 0) goto _L143;
    }
  }
  else {
    uVar8 = 2;
_L143:
    *(undefined1 *)(iVar11 + 0x3d) = uVar8;
  }
  iVar3 = iVar3 + 5;
_L117:
  if ((int)(uVar10 << 0x12) < 0) {
    iVar3 = iVar3 + 0x12;
  }
  if ((int)(uVar10 << 0x11) < 0) {
    puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(param_2 + iVar3 & 0xffff);
    *(undefined1 *)(iVar11 + 0x3c) = *puVar7;
  }
  return;
}

