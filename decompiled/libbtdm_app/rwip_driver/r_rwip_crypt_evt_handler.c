/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_crypt_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_crypt_evt_handler(void)

{
  void *__src;
  undefined1 auStack_20 [24];
  
  (**(code **)(_r_modules_funcs_p + 0xec))(2,*(code **)(_r_modules_funcs_p + 0xec));
  __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(0x138,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(auStack_20,__src,0x10);
  (**(code **)(_r_modules_funcs_p + 0x338))(0,auStack_20,*(code **)(_r_modules_funcs_p + 0x338));
  return;
}

