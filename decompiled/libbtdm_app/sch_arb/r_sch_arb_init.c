/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_init(char param_1)

{
  if ((byte)(param_1 - 1U) < 2) {
    (**(code **)(_r_modules_funcs_p + 0x2c))(&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x2c));
    (**(code **)(_r_modules_funcs_p + 0x2c))(&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x2c));
    _r_ip_funcs_p = 0;
    return;
  }
  return;
}

