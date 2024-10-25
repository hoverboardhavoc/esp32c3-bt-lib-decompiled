/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip.o -> r_rwip_wlcoex_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_wlcoex_set(int param_1)

{
  if (param_1 != 0) {
    _DAT_60031150 = _DAT_60031150 | 3;
    _DAT_6003115c =
         (**(code **)(_r_modules_funcs_p + 0x19c))(0,*(code **)(_r_modules_funcs_p + 0x19c));
    _DAT_60031160 =
         (**(code **)(_r_modules_funcs_p + 0x19c))(1,*(code **)(_r_modules_funcs_p + 0x19c));
    return;
  }
  _DAT_60031150 = _DAT_60031150 & 0xfffffffc;
  return;
}

