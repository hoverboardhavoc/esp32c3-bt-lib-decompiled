/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_alarm.o -> r_sch_alarm_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_alarm_init(char param_1)

{
  if ((byte)(param_1 - 1U) < 2) {
                    /* WARNING: Could not recover jumptable at 0x0001008e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x2c))(&sch_alarm_env,*(code **)(_r_modules_funcs_p + 0x2c));
    return;
  }
  return;
}

