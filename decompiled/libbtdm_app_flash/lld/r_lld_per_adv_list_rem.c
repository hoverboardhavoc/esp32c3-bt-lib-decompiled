/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_per_adv_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_rem(int param_1,undefined4 param_2,undefined4 param_3,ushort param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = _p_lld_env + param_1 * 2;
  uVar2 = ~param_4 & *(ushort *)(iVar3 + 0xbc);
  *(ushort *)(iVar3 + 0xbc) = uVar2;
  if (uVar2 == 0) {
    param_1 = param_1 * 8;
    iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar2 = *(ushort *)(iVar3 + param_1);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar3 + param_1) = uVar2 & 0xfffe;
    iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
    if ((*(ushort *)(iVar3 + param_1) >> 1 & 1) == 0) {
      iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
      uVar2 = *(ushort *)(iVar3 + param_1);
      iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
      *(ushort *)(iVar3 + param_1) = uVar2 & 0x7fff;
    }
    uVar1 = r_lld_ral_search(param_2,param_3);
    if (uVar1 < 10) {
      iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar2 = *(ushort *)(iVar3 + uVar1 * 0x34);
      iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(iVar3 + uVar1 * 0x34) = uVar2 & 0xefff;
    }
    return;
  }
  return;
}

