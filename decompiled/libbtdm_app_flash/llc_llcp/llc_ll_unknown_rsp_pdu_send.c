/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_llcp.o -> llc_ll_unknown_rsp_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llc_ll_unknown_rsp_pdu_send(undefined1 param_1)

{
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  uStack_14 = 7;
  uStack_13 = param_1;
  r_llc_llcp_send(&uStack_14,0);
  return;
}

