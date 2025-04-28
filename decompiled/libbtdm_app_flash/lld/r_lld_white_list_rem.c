/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_white_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_white_list_rem(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 != 0xff) {
    param_1 = param_1 * 8;
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar1 = *(ushort *)(iVar2 + param_1);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar2 + param_1) = uVar1 & 0xfffd;
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    if ((*(ushort *)(iVar2 + param_1) & 1) == 0) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
      uVar1 = *(ushort *)(iVar2 + param_1);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
      *(ushort *)(param_1 + iVar2) = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
    }
    uVar3 = r_lld_ral_search(param_2,param_3);
    if (uVar3 < 10) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar1 = *(ushort *)(iVar2 + uVar3 * 0x34);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(uVar3 * 0x34 + iVar2) = uVar1 & 0xdfff;
    }
    return;
  }
  _DAT_60031000 = _DAT_60031000 & 0xfffffbff;
  return;
}

