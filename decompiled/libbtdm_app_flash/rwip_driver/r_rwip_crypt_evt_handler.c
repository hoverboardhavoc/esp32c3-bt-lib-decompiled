/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_crypt_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_rwip_crypt_evt_handler(void)

{
  void *__src;
  undefined1 auStack_20 [28];
  
  r_ke_event_clear(2);
  __src = (void *)r_emi_get_mem_addr_by_offset(0x138);
  memcpy(auStack_20,__src,0x10);
  r_rw_crypto_aes_result_handler(0,auStack_20);
  return;
}

