/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
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
  if ((param_1 & 0x1000) != 0) {
    _DAT_60031018 = 0x1000;
    (**(code **)(_r_modules_funcs_p + 700))(*(code **)(_r_modules_funcs_p + 700));
  }
  if ((param_1 & 0x80000) != 0) {
    _DAT_60031018 = _DAT_60031018 & 0xfff7ffff | 0x80000;
                    /* WARNING: Could not recover jumptable at 0x0001119c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x118))(*(code **)(_r_ip_funcs_p + 0x118));
    return;
  }
  return;
}

