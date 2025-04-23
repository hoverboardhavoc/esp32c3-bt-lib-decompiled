/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> llc_ll_feature_req_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llc_ll_feature_req_pdu_send(int param_1)

{
  void *__src;
  char cStack_1c;
  undefined1 auStack_1b [3];
  byte bStack_18;
  
  cStack_1c = (((byte)*(undefined2 *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) - 1 & 6) + 8;
  __src = (void *)r_llm_le_features_get();
  memcpy(auStack_1b,__src,8);
  bStack_18 = bStack_18 & 0xf7;
  r_llc_llcp_send_eco(param_1,&cStack_1c,0);
  return;
}

