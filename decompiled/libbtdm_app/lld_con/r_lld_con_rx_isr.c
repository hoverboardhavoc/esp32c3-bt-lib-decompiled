/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_isr(int param_1)

{
  if (*(int *)(&lld_con_env + param_1 * 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00013204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x38c))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0xc2c);
  return;
}

