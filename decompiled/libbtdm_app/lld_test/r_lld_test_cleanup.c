/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_cleanup(int param_1)

{
  code *pcVar1;
  
  if (_lld_test_env != 0) {
    if (*(char *)(_lld_test_env + 0x26) == '\x01') {
      if (param_1 == 0) {
        pcVar1 = *(code **)(_r_ip_funcs_p + 0xcc);
      }
      else {
        pcVar1 = *(code **)(_r_ip_funcs_p + 0xd0);
      }
      (*pcVar1)(*(undefined2 *)(_lld_test_env + 0x24),pcVar1);
    }
    (**(code **)(_r_modules_funcs_p + 0x110))(_lld_test_env,*(code **)(_r_modules_funcs_p + 0x110));
    _lld_test_env = 0;
  }
  return;
}

