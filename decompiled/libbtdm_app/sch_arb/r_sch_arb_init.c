/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    _rwip_prog_delay = 0;
    return;
  }
  return;
}

