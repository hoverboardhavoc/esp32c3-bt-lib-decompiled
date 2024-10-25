/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_cca_data_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_data_reset(void)

{
  undefined1 *puVar1;
  
  memset(*(void **)(_p_lld_env + 0x108),0,0x28);
  memset(*(void **)(_p_lld_env + 0x10c),0,0x28);
  memset(*(void **)(_p_lld_env + 0x110),0,0x28);
  puVar1 = *(undefined1 **)(_p_lld_env + 0x118);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  memset(*(void **)(_p_lld_env + 0x114),0,0x28);
  *(undefined2 *)(_p_lld_env + 0x104) = 0xff00;
  return;
}

