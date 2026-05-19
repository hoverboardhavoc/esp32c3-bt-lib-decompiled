/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_isr(int param_1)

{
  if (*(int *)(&lld_con_env + param_1 * 4) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x3b8))(*(code **)(_r_ip_funcs_p + 0x3b8));
                    /* WARNING: Could not recover jumptable at 0x000136fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d0))(param_1,*(code **)(_r_ip_funcs_p + 0x3d0));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001371a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0xdad,*(code **)(_r_plf_funcs_p + 0xc));
  return;
}

