/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_set_tx_power(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = (*_rwip_rf)(param_2,param_1,_rwip_rf);
  iVar2 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(param_1 * 0x5a + 0x18 + iVar2) = uVar1;
  return;
}

