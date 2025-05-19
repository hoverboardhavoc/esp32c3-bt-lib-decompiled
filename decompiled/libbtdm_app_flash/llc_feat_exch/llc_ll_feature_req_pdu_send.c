/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> llc_ll_feature_req_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llc_ll_feature_req_pdu_send(int param_1)

{
  void *__src;
  undefined1 uStack_1c;
  undefined1 auStack_1b [3];
  byte bStack_18;
  
  uStack_1c = 0xe;
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) != 0) {
    uStack_1c = 8;
  }
  __src = (void *)r_llm_le_features_get_hack();
  memcpy(auStack_1b,__src,8);
  bStack_18 = bStack_18 & 0xf7;
  r_llc_llcp_send_eco(param_1,&uStack_1c,0);
  return;
}

