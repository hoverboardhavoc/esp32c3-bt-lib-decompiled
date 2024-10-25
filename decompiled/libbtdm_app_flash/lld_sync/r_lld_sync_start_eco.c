/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_sync_start_eco(uint param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = r_lld_sync_start();
  iVar3 = r_sdk_config_get_opts();
  if ((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) != 0)) {
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar3 + param_1 * 0x5a);
    iVar3 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(param_1 * 0x5a + iVar3) = uVar1 & 0xffdf;
  }
  return uVar2;
}

