/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> llc_llcp.o -> lld_llcp_rx_ind_handler_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_llcp_rx_ind_handler_wrapper(void)

{
                    /* WARNING: Could not recover jumptable at 0x000108b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x750))(*(code **)(_r_ip_funcs_p + 0x750));
  return;
}

