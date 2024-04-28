/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
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
                    /* WARNING: Could not recover jumptable at 0x00011160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x34))(_g_rw_init_sem,0xffffffff);
  return;
}

