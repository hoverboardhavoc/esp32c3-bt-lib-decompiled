/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_ch_idx_get_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_ch_idx_get_hack(void)

{
  byte bVar1;
  uint uVar2;
  
  if (_LANCHOR4 != '\0') {
    return _LANCHOR5;
  }
  uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  bVar1 = *(byte *)(_p_lld_env + 0x100);
  if (bVar1 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  return *(undefined1 *)(_p_lld_env + (uVar2 & 0xff) % (uint)bVar1 + 0xdb);
}

