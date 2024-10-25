/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> llc_ll_feature_rsp_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void llc_ll_feature_rsp_pdu_send(int param_1)

{
  void *__src;
  undefined1 uStack_1c;
  byte abStack_1b [3];
  byte bStack_18;
  
  uStack_1c = 9;
  __src = (void *)r_llm_le_features_get();
  memcpy(abStack_1b,__src,8);
  abStack_1b[0] = *(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x30) & abStack_1b[0];
  bStack_18 = bStack_18 & 0xf7;
  r_llc_llcp_send_eco(param_1,&uStack_1c,0);
  return;
}

