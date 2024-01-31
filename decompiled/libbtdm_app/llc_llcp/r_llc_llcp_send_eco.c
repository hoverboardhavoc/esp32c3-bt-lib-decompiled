/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_send_eco(char *param_1,code *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    param_2 = llc_llcp_conn_update_ind_ack;
  }
  else if (cVar1 == '\x01') {
    param_2 = *(code **)(_r_ip_funcs_p + 0x8f4);
  }
  else if (cVar1 == '\x18') {
    param_2 = llc_llcp_phy_update_ind_ack;
  }
  r_llc_llcp_send(param_2);
  return;
}

