/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> llc_ll_connection_param_req_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_connection_param_req_pdu_send(int param_1)

{
  undefined1 auStack_2c [2];
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  auStack_2c[0] = 0xf;
  uStack_2a = *(undefined2 *)(param_1 + 8);
  uStack_20 = *(undefined4 *)(param_1 + 0x14);
  uStack_28 = *(undefined2 *)(param_1 + 10);
  uStack_1c = *(undefined4 *)(param_1 + 0x18);
  uStack_26 = *(undefined2 *)(param_1 + 0xc);
  uStack_18 = *(undefined4 *)(param_1 + 0x1c);
  uStack_24 = *(undefined2 *)(param_1 + 0xe);
  uStack_22 = *(undefined1 *)(param_1 + 0x27);
  uStack_14 = *(undefined2 *)(param_1 + 0x20);
  (**(code **)(_r_ip_funcs_p + 0x5b4))(auStack_2c,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

