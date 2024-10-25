/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_pdu_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llc_llcp_pdu_handler_pre(char *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == '\x0f') {
    uVar1 = ll_connection_param_req_handler_pre();
    return uVar1;
  }
  if (*param_1 == '\x10') {
    uVar1 = ll_connection_param_rsp_param_handler_pre();
    return uVar1;
  }
  return 0;
}

