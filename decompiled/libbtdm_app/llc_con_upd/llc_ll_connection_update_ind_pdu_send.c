/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> llc_ll_connection_update_ind_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_connection_update_ind_pdu_send(int param_1)

{
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_1b = *(undefined1 *)(param_1 + 0x26);
  uStack_1c = 0;
  uStack_1a = *(undefined2 *)(param_1 + 0x22);
  uStack_18 = *(undefined2 *)(param_1 + 0x28);
  uStack_16 = *(undefined2 *)(param_1 + 0xc);
  uStack_14 = *(undefined2 *)(param_1 + 0xe);
  uStack_12 = *(undefined2 *)(param_1 + 0x24);
  (**(code **)(_r_ip_funcs_p + 0x5b4))(&uStack_1c,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

