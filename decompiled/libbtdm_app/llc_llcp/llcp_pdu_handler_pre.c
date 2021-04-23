/*
 * Last changed at upstream commit 8ce2a3620a07ba62084c75489b62d44de9ba1824
 * https://github.com/espressif/esp32c3-bt-lib/commit/8ce2a3620a07ba62084c75489b62d44de9ba1824
 * Upstream date: 2021-04-23 19:57:05 +0800
 * Upstream subject: update esp32c3 and esp32s3 bt lib (6ab3130)
 * Source: libbtdm_app -> llc_llcp.o -> llcp_pdu_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llcp_pdu_handler_pre(char *param_1)

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

