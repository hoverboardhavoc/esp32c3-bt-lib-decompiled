/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_sync_info_unpack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_lld_scan_sync_info_unpack(ushort *param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  ushort *puVar3;
  void *pvVar4;
  
  puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(param_2);
  uVar1 = *puVar3;
  *(byte *)(param_1 + 1) = (byte)((int)(uint)uVar1 >> 0xd) & 1;
  *param_1 = uVar1 & 0x1fff;
  puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(param_2 + 2U & 0xffff);
  param_1[2] = *puVar3;
  pvVar4 = (void *)r_emi_get_mem_addr_by_offset(param_2 + 4U & 0xffff);
  memcpy(param_1 + 3,pvVar4,5);
  *(byte *)((int)param_1 + 0xb) = (byte)param_1[5] >> 5;
  *(byte *)(param_1 + 5) = (byte)param_1[5] & 0x1f;
  pvVar4 = (void *)r_emi_get_mem_addr_by_offset(param_2 + 9U & 0xffff);
  memcpy(param_1 + 6,pvVar4,4);
  pvVar4 = (void *)r_emi_get_mem_addr_by_offset(param_2 + 0xdU & 0xffff);
  memcpy(param_1 + 8,pvVar4,3);
  puVar3 = (ushort *)r_emi_get_mem_addr_by_offset(param_2 + 0x10U & 0xffff);
  bVar2 = false;
  param_1[10] = *puVar3;
  if (*param_1 != 0) {
    bVar2 = 5 < param_1[2];
  }
  return bVar2;
}

