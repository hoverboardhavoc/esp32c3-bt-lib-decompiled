/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
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
                    /* WARNING: Could not recover jumptable at 0x000111d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x34))(_g_rw_init_sem,0xffffffff);
  return;
}

