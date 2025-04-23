/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_pdu_handler_get_overwrite
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * r_llc_llcp_pdu_handler_get_overwrite(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if (param_1 == 1) {
    puVar2 = &ll_channel_map_ind_handler_hack;
  }
  else if (param_1 == 0x18) {
    puVar2 = &ll_phy_update_ind_handler_hack;
  }
  else if (param_1 == 0) {
    puVar2 = &ll_connection_update_ind_handler_hack;
  }
  else {
    puVar2 = *(undefined **)(iVar1 + param_1 * 0xc);
  }
  return puVar2;
}

