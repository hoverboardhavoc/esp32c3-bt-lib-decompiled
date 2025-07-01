/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_channel_map_ind_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_channel_map_ind_ack(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = lld_con_llcp_proc_type_get();
  if (iVar1 == 2) {
                    /* WARNING: Could not recover jumptable at 0x0001047a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1,*(code **)(_r_ip_funcs_p + 0x7d4));
    return;
  }
  return;
}

