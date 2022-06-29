/*
 * Last changed at upstream commit 614154ba4a7b5e55e943f92c194de497e6ce4219
 * https://github.com/espressif/esp32c3-bt-lib/commit/614154ba4a7b5e55e943f92c194de497e6ce4219
 * Upstream date: 2022-06-29 19:01:17 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(16cffbc)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_disable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_disable(void)

{
  (**(code **)(_r_plf_funcs_p + 0x28))(10,0,0,1,*(code **)(_r_plf_funcs_p + 0x28));
                    /* WARNING: Could not recover jumptable at 0x00010a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x34))(_g_rw_init_sem,0xffffffff);
  return;
}

