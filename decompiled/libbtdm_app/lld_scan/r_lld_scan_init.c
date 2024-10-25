/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_init(int param_1)

{
  if (param_1 == 1) {
    _lld_scan_env = (int *)0x0;
    _lld_scan_sync_env = 0;
    return;
  }
  if (param_1 == 2) {
    if (_lld_scan_sync_env != 0) {
      (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      _lld_scan_sync_env = 0;
    }
    if (_lld_scan_env != (int *)0x0) {
      if (*_lld_scan_env != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      if (_lld_scan_env[1] != 0) {
        (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
      }
      (**(code **)(_r_modules_funcs_p + 0x110))
                (_lld_scan_env,*(code **)(_r_modules_funcs_p + 0x110));
      _lld_scan_env = (int *)0x0;
    }
    return;
  }
  return;
}

