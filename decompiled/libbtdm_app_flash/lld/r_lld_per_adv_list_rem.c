/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_per_adv_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_rem(int param_1,undefined4 param_2,undefined4 param_3,ushort param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = _p_lld_env + param_1 * 2;
  uVar3 = *(ushort *)(iVar2 + 0xbc) & ~param_4;
  *(ushort *)(iVar2 + 0xbc) = uVar3;
  if (uVar3 == 0) {
    param_1 = param_1 * 8;
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar3 = *(ushort *)(iVar2 + param_1);
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar2 + param_1) = uVar3 & 0xfffe;
    iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
    if ((*(ushort *)(iVar2 + param_1) >> 1 & 1) == 0) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
      uVar3 = *(ushort *)(iVar2 + param_1);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
      *(ushort *)(param_1 + iVar2) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
    }
    iVar2 = r_lld_ral_search(param_2,param_3);
    if (iVar2 != 10) {
      iVar1 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar3 = *(ushort *)(iVar1 + iVar2 * 0x34);
      iVar1 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(iVar2 * 0x34 + iVar1) = uVar3 & 0xefff;
    }
    return;
  }
  return;
}

