/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_per_adv_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_add(int param_1,void *param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  void *__dest;
  
  iVar2 = param_1 * 8;
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar3 + iVar2) = uVar1 | 0x8000;
  if ((param_3 & 0xfe) != 0) {
    r_assert_err(0,"lld.c",0x60);
  }
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar3 + iVar2) = uVar1 & 0xbfff | (ushort)(param_3 << 0xe);
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  uVar1 = *(ushort *)(iVar3 + iVar2);
  iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
  *(ushort *)(iVar3 + iVar2) = uVar1 | 1;
  __dest = (void *)r_emi_get_mem_addr_by_offset(iVar2 + 0xc02);
  memcpy(__dest,param_2,6);
  iVar2 = param_1 * 2 + _p_lld_env;
  *(ushort *)(iVar2 + 0xbc) = *(ushort *)(iVar2 + 0xbc) | (ushort)(1 << (param_4 & 0x1f));
  iVar2 = r_lld_ral_search(param_2,param_3);
  if (iVar2 != 10) {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + iVar2 * 0x34);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(iVar2 * 0x34 + iVar3) = uVar1 | 0x1000;
  }
  return;
}

