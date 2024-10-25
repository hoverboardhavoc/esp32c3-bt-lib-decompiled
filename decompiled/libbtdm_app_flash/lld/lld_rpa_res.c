/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> lld_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool lld_rpa_res(void *param_1)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  uStack_18 = *(undefined1 *)((int)param_1 + 3);
  uStack_17 = *(undefined1 *)((int)param_1 + 4);
  uStack_14 = 0;
  uStack_16 = *(undefined1 *)((int)param_1 + 5);
  uStack_12 = 0;
  rw_crypto_aes_encrypt_sync(&uStack_18,3,&uStack_14);
  iVar1 = memcmp(&uStack_14,param_1,3);
  return iVar1 == 0;
}

