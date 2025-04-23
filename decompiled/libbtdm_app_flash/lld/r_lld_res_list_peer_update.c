/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_peer_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_res_list_peer_update(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = r_lld_ral_search();
  if (iVar2 == 10) {
    uVar4 = 2;
  }
  else {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + iVar2 * 0x34);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(iVar2 * 0x34 + iVar3) = uVar1 & 0xbfff | (ushort)(param_1 << 0xe);
    uVar4 = 0;
  }
  return uVar4;
}

