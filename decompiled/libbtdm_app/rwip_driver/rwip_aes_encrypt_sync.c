/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> rwip_aes_encrypt_sync
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010418) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rwip_aes_encrypt_sync(void *param_1,size_t param_2)

{
  void *__dest;
  
  _LANCHOR0 = 0;
  DAT_0001115c = 0;
  DAT_00011160 = 0;
  DAT_00011164 = 0;
  memcpy(&_LANCHOR0,param_1,param_2);
  (**(code **)(_r_modules_funcs_p + 0x2b4))(0x20,*(code **)(_r_modules_funcs_p + 0x2b4));
  __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x128,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(__dest,&_LANCHOR0,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  do {
  } while( true );
}

