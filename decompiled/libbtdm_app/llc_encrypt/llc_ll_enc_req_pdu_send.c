/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> llc_ll_enc_req_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_enc_req_pdu_send
               (undefined4 param_1,undefined2 param_2,void *param_3,void *param_4,void *param_5)

{
  undefined1 uStack_28;
  undefined1 auStack_27 [9];
  undefined2 uStack_1e;
  undefined1 auStack_1c [8];
  undefined1 auStack_14 [12];
  
  uStack_28 = 3;
  uStack_1e = param_2;
  memcpy(auStack_27,param_3,8);
  memcpy(auStack_1c,param_4,8);
  memcpy(auStack_14,param_5,4);
  (**(code **)(_r_ip_funcs_p + 0x5b4))(param_1,&uStack_28,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

