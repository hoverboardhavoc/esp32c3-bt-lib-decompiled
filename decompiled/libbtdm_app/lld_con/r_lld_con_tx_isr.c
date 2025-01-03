/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
                    /* WARNING: Could not recover jumptable at 0x00013232. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3d0))(param_1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00013250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"lld_con.c",0xc21);
  return;
}

