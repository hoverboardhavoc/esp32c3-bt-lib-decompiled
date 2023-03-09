/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_pdu_handler_pre
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

