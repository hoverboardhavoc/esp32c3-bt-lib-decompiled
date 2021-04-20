/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> sch_plan.o -> r_sch_plan_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_plan_set_hack(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x44))(&sch_plan_env,param_1);
  return;
}

