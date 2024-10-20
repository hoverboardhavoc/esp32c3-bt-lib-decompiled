/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
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
                    /* WARNING: Could not recover jumptable at 0x000103b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x7d4))(param_1);
    return;
  }
  return;
}

