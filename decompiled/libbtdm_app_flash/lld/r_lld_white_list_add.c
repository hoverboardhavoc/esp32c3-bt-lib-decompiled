/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  int iVar4;
  
  if (param_3 != 0xff) {
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
    *(ushort *)(iVar2 + iVar4) = uVar1 & 0xfffd | 2;
    __dest = (void *)r_emi_get_mem_addr_by_offset(iVar4 + 0xc02U & 0xffff);
    memcpy(__dest,param_2,6);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    r_ble_log_internal_x1(0x408800b6,param_1 << 0x10 | (uint)*(ushort *)(iVar2 + iVar4));
    uVar3 = r_lld_ral_search(param_2,param_3);
    if (uVar3 < 10) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(uVar3 * 0x34 + iVar2) = uVar1 & 0xdfff | 0x2000;
    }
    return;
  }
  _DAT_60031000 = _DAT_60031000 & 0xfffffbff;
  r_ble_log_internal_x1(0x408800b7,_DAT_60031000);
  return;
}

