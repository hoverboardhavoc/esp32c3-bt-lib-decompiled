/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> lld_peer_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool lld_peer_rpa_res(void *param_1,uint param_2)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  uint auStack_14 [2];
  
  auStack_14[0] = param_2;
  iVar1 = r_emi_get_mem_addr_by_offset(0xc60);
  if ((*(ushort *)(iVar1 + auStack_14[0] * 0x34) >> 1 & 1) == 0) {
    return false;
  }
  r_emi_get_mem_addr_by_offset(auStack_14[0] * 0x34 + 0xc62 & 0xffff);
  uStack_18 = *(undefined1 *)((int)param_1 + 3);
  uStack_17 = *(undefined1 *)((int)param_1 + 4);
  uStack_16 = *(undefined1 *)((int)param_1 + 5);
  auStack_14[0] = auStack_14[0] & 0xff000000;
  rw_crypto_aes_encrypt_sync(&uStack_18,3,auStack_14);
  iVar1 = memcmp(auStack_14,param_1,3);
  return iVar1 == 0;
}

