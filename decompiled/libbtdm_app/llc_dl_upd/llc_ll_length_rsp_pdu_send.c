/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_dl_upd.o -> llc_ll_length_rsp_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_length_rsp_pdu_send
               (undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined1 auStack_1c [2];
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  auStack_1c[0] = 0x15;
  uStack_1a = param_4;
  uStack_18 = param_3;
  uStack_16 = param_2;
  uStack_14 = param_1;
  (**(code **)(_r_ip_funcs_p + 0x5b4))(auStack_1c,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

