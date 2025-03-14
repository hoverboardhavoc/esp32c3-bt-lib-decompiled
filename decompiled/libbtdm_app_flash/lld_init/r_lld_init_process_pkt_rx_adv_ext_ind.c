/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  uint auStack_24 [2];
  
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar10 = (uint)bVar1 * 0x14;
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar4 + iVar10 + 0x10);
  uVar3 = (uint)uVar2;
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar4 + iVar10 + 4) & 0xf) != 7) {
    r_assert_err(0,"lld_init.c",700);
    return;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 0;
  iVar4 = 0;
  if ((uVar2 & 0x100) != 0) {
    pvVar5 = (void *)r_emi_get_mem_addr_by_offset(param_2);
    memcpy((void *)(iVar11 + 0x32),pvVar5,6);
    iVar4 = 6;
  }
  if ((uVar2 & 0x200) != 0) {
    iVar4 = iVar4 + 6;
  }
  if ((uVar2 & 0x400) != 0) {
    iVar4 = iVar4 + 1;
  }
  if ((uVar3 & 0x1800) != 0x1800) {
    if ((int)(uVar3 << 0x14) < 0) {
      puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(param_2 + iVar4 & 0xffff);
      iVar4 = iVar4 + 2;
      *(undefined2 *)(iVar11 + 0x3a) = *puVar6;
    }
    goto _L110;
  }
  puVar6 = (undefined2 *)r_emi_get_mem_addr_by_offset(param_2 + iVar4 & 0xffff);
  *(undefined2 *)(iVar11 + 0x38) = *puVar6;
  pvVar5 = (void *)r_emi_get_mem_addr_by_offset(iVar4 + 2 + param_2 & 0xffff);
  memcpy(auStack_24,pvVar5,3);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar10 + 2 + iVar7) >> 9 & 1) == 0) {
    if ((auStack_24[0] >> 0x15 & 7) < 3) {
      iVar10 = r_lld_calc_aux_rx(iVar11 + 0x40,(uint)bVar1);
      uVar9 = 1;
      if (iVar10 != 0) goto _L134;
    }
  }
  else {
    uVar9 = 2;
_L134:
    *(undefined1 *)(iVar11 + 0x3d) = uVar9;
  }
  iVar4 = iVar4 + 5;
_L110:
  if ((int)(uVar3 << 0x12) < 0) {
    iVar4 = iVar4 + 0x12;
  }
  if ((int)(uVar3 << 0x11) < 0) {
    puVar8 = (undefined1 *)r_emi_get_mem_addr_by_offset(param_2 + iVar4 & 0xffff);
    *(undefined1 *)(iVar11 + 0x3c) = *puVar8;
  }
  return;
}

