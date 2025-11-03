/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_per_adv_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_add(int param_1,void *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 * 8;
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar2 + iVar4);
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar2 + iVar4) = (ushort)(((uint)uVar1 << 0x11) >> 0x11) | 0x8000;
  if ((param_3 << 0xe & 0x3f8000U) != 0) {
    r_assert_err(0,"lld.c",0x60);
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar2 + iVar4);
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar2 + iVar4) = uVar1 & 0xbfff | (ushort)(param_3 << 0xe);
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar2 + iVar4);
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar2 + iVar4) = uVar1 & 0xfffe | 1;
  __dest = (void *)r_emi_get_mem_addr_by_offset(iVar4 + 0xc02U & 0xffff);
  memcpy(__dest,param_2,6);
  iVar2 = _p_lld_env + param_1 * 2;
  *(ushort *)(iVar2 + 0xbc) = *(ushort *)(iVar2 + 0xbc) | (ushort)(1 << (param_4 & 0x1f));
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  r_ble_log_internal_x1(0x40880056,param_1 << 0x10 | (uint)*(ushort *)(iVar2 + iVar4));
  uVar3 = r_lld_ral_search(param_2,param_3);
  if (uVar3 < 10) {
    iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(uVar3 * 0x34 + iVar2) = uVar1 & 0xefff | 0x1000;
  }
  return;
}

