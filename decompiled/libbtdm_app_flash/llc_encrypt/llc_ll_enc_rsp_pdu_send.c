/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> llc_ll_enc_rsp_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llc_ll_enc_rsp_pdu_send(undefined4 param_1,void *param_2,void *param_3)

{
  undefined1 local_20;
  undefined1 auStack_1f [8];
  undefined1 auStack_17 [7];
  
  local_20 = 4;
  memcpy(auStack_1f,param_2,8);
  memcpy(auStack_17,param_3,4);
  r_llc_llcp_send_eco(param_1,&local_20,0);
  return;
}

