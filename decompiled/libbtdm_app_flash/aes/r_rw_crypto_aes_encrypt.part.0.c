/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> aes.o -> r_rw_crypto_aes_encrypt.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_rw_crypto_aes_encrypt_part_0(void *param_1,void *param_2)

{
  code cVar1;
  void *__dest;
  int iVar2;
  void *pvVar3;
  
  iVar2 = r_aes_alloc(0x38,0);
  __dest = (void *)(iVar2 + 0x18);
  memcpy(__dest,param_1,0x10);
  pvVar3 = memcpy((void *)(iVar2 + 0x28),param_2,0x10);
  r_co_list_push_back(&aes_env,iVar2);
  cVar1 = r_co_list_init;
  *(void **)(iVar2 + 0xc) = __dest;
  *(void **)(iVar2 + 0x10) = pvVar3;
  if (cVar1 != (code)0x0) {
    return;
  }
  r_co_list_init = (code)0x1;
  r_rwip_aes_encrypt(__dest,pvVar3);
  return;
}

