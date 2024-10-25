/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_isr(uint param_1)

{
  if ((param_1 & 0x400) != 0) {
    _DAT_60031018 = 0x400;
    (**(code **)(_r_modules_funcs_p + 0x2d0))(*(code **)(_r_modules_funcs_p + 0x2d0));
  }
  if ((param_1 & 0x800) != 0) {
    _DAT_60031018 = 0x800;
    (**(code **)(_r_modules_funcs_p + 0x2d8))(*(code **)(_r_modules_funcs_p + 0x2d8));
  }
  if (((param_1 & 1) != 0) && (_DAT_60031018 = 1, (_rwip_env & 1) != 0)) {
    (**(code **)(_r_modules_funcs_p + 0x2e4))(*(code **)(_r_modules_funcs_p + 0x2e4));
  }
  if ((param_1 & 8) != 0) {
    _DAT_60031018 = 8;
    (**(code **)(_r_modules_funcs_p + 0x2e0))(*(code **)(_r_modules_funcs_p + 0x2e0));
  }
  if ((param_1 & 0x200) != 0) {
    _DAT_60031018 = 0x200;
    (**(code **)(_r_modules_funcs_p + 0x2c8))(*(code **)(_r_modules_funcs_p + 0x2c8));
  }
  if ((param_1 & 0x80) != 0) {
    _DAT_60031018 = 0x80;
    (**(code **)(_r_modules_funcs_p + 0x298))(*(code **)(_r_modules_funcs_p + 0x298));
  }
  if ((int)(param_1 << 0x13) < 0) {
    _DAT_60031018 = 0x1000;
    (**(code **)(_r_modules_funcs_p + 700))(*(code **)(_r_modules_funcs_p + 700));
  }
  if ((int)(param_1 << 0xc) < 0) {
    _DAT_60031018 = _DAT_60031018 & 0xfff7ffff | 0x80000;
                    /* WARNING: Could not recover jumptable at 0x0001114e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x118))();
    return;
  }
  return;
}

