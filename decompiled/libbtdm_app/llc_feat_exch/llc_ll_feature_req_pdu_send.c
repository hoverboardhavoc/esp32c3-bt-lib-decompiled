/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_feat_exch.o -> llc_ll_feature_req_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_feature_req_pdu_send(int param_1)

{
  void *__src;
  undefined1 uStack_1c;
  undefined1 auStack_1b [3];
  byte bStack_18;
  
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    uStack_1c = 0xe;
  }
  else {
    uStack_1c = 8;
  }
  __src = (void *)(**(code **)(_r_ip_funcs_p + 0x4e4))(*(code **)(_r_ip_funcs_p + 0x4e4));
  memcpy(auStack_1b,__src,8);
  bStack_18 = bStack_18 & 0xf7;
  (**(code **)(_r_ip_funcs_p + 0x5b4))(param_1,&uStack_1c,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

