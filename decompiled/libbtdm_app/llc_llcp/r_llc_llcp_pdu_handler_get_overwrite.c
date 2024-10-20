/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
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
  else if (param_1 == 0) {
    puVar2 = &ll_connection_update_ind_handler_hack;
  }
  else if (param_1 == 0x18) {
    puVar2 = &ll_phy_update_ind_handler_hack;
  }
  else {
    puVar2 = *(undefined **)(param_1 * 0xc + iVar1);
  }
  return puVar2;
}

