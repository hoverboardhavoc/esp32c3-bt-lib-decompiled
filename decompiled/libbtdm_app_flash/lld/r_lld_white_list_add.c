/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  _DAT_60031000 = _DAT_60031000 & 0xfffffbff;
  return;
}

