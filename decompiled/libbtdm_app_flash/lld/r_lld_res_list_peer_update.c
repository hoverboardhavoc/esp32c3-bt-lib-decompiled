/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = r_lld_ral_search();
  if (uVar2 < 10) {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + uVar2 * 0x34);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(uVar2 * 0x34 + iVar3) = uVar1 & 0xbfff | (ushort)(param_1 << 0xe);
    uVar4 = 0;
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

