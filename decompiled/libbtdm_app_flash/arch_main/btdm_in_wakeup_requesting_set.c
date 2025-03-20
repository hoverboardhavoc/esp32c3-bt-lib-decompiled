/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_in_wakeup_requesting_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_in_wakeup_requesting_set(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000107de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x34))(_g_waking_sleeping_sem,0xffffffff);
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0x38))(_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  r_btdm_task_post(6,0,0,0);
  return;
}

