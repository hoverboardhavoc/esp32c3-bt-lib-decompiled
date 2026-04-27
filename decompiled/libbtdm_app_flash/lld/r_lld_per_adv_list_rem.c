/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_per_adv_list_rem
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_list_rem(uint param_1,undefined4 param_2,undefined4 param_3,ushort param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = _p_lld_env + param_1 * 2;
  uVar3 = *(ushort *)(iVar2 + 0xbc) & ~param_4;
  *(ushort *)(iVar2 + 0xbc) = uVar3;
  if (uVar3 == 0) {
    iVar2 = param_1 * 8;
    iVar1 = r_emi_get_mem_addr_by_offset(0xc00);
    uVar3 = *(ushort *)(iVar1 + iVar2);
    iVar1 = r_emi_get_mem_addr_by_offset(0xc00);
    *(ushort *)(iVar1 + iVar2) = uVar3 & 0xfffe;
    iVar1 = r_emi_get_mem_addr_by_offset(0xc00);
    if ((*(ushort *)(iVar1 + iVar2) >> 1 & 1) == 0) {
      iVar1 = r_emi_get_mem_addr_by_offset(0xc00);
      uVar3 = *(ushort *)(iVar1 + iVar2);
      iVar1 = r_emi_get_mem_addr_by_offset(0xc00);
      *(ushort *)(iVar1 + iVar2) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
    }
    param_1 = r_lld_ral_search(param_2,param_3);
    if (param_1 < 10) {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      uVar3 = *(ushort *)(iVar2 + param_1 * 0x34);
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      *(ushort *)(param_1 * 0x34 + iVar2) = uVar3 & 0xefff;
    }
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
  r_ble_log_internal_x1(0x408800d4,(uint)*(ushort *)(param_1 * 8 + iVar2) | param_1 << 0x10);
  return;
}

