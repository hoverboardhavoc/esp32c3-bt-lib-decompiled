/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tl_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tl_init(int param_1)

{
  if (param_1 == 0) {
    memset(&hci_tl_env,0,0x28);
    (**(code **)(_r_modules_funcs_p + 0x2c))(&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x2c));
    (**(code **)(_r_modules_funcs_p + 0x2c))(&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x2c));
    memcpy = (code)0x1;
    (**(code **)(_r_modules_funcs_p + 0x100))
              (6,*(undefined4 *)(_r_ip_funcs_p + 0x38),*(code **)(_r_modules_funcs_p + 0x100));
    (**(code **)(_r_modules_funcs_p + 0x100))
              (7,*(undefined4 *)(_r_ip_funcs_p + 0x3c),*(code **)(_r_modules_funcs_p + 0x100));
    (**(code **)(_r_modules_funcs_p + 0x100))
              (5,*(undefined4 *)(_r_ip_funcs_p + 0x50),*(code **)(_r_modules_funcs_p + 0x100));
  }
  DAT_0001201d = 5;
  return;
}

