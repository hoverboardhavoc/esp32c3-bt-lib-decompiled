/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_llcp.o -> llcp_pdu_handler_pre
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llcp_pdu_handler_pre(char *param_1)

{
  undefined4 uVar1;
  char *apcStack_14 [4];
  
  apcStack_14[0] = param_1;
  if (*param_1 == '\x0f') {
    uVar1 = ll_connection_param_req_handler_pre(apcStack_14);
  }
  else {
    uVar1 = 0;
    if (*param_1 == '\x10') {
      uVar1 = ll_connection_param_rsp_param_handler_pre(apcStack_14);
    }
  }
  return uVar1;
}

