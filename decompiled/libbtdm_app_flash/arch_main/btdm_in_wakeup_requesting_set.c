/*
 * Last changed at upstream commit 4c16da1a1a76b439e2cf981d2f915d94df364e58
 * https://github.com/espressif/esp32c3-bt-lib/commit/4c16da1a1a76b439e2cf981d2f915d94df364e58
 * Upstream date: 2024-12-16 11:11:02 +0800
 * Upstream subject: fix(bt): Fixed that the resolvable private address does not change when light sleep is enabled(6bca137)
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
                    /* WARNING: Could not recover jumptable at 0x00010756. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_osi_funcs_p + 0x34))(_g_waking_sleeping_sem,0xffffffff);
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0x38))(_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  r_btdm_task_post(6,0,0,0);
  return;
}

