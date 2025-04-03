/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_white_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_white_list_add(int param_1,void *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  
  if (param_3 != 0xff) {
    param_1 = param_1 * 8;
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0x7fff | 0x8000;
    if ((param_3 << 0xe & 0x3f8000U) != 0) {
      r_assert_err(0,"lld.c",0x60);
    }
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0xbfff | (ushort)(param_3 << 0xe);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0xfffd | 2;
    __dest = (void *)r_emi_get_mem_addr_by_offset(param_1 + 0xc02U & 0xffff);
    memcpy(__dest,param_2,6);
    uVar3 = r_lld_ral_search(param_2,param_3);
    if (uVar3 < 10) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(iVar2 + uVar3 * 0x34) = uVar1 & 0xdfff | 0x2000;
    }
    return;
  }
  _DAT_60031000 = _DAT_60031000 | 0x400;
  return;
}

