/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> llc_llcp_phy_upd_ind_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_llcp_phy_upd_ind_pdu_send(undefined1 param_1,undefined1 param_2,undefined2 param_3)

{
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined2 uStack_14;
  
  uStack_18 = 0x18;
  uStack_17 = param_1;
  uStack_16 = param_2;
  uStack_14 = param_3;
  (**(code **)(_r_ip_funcs_p + 0x5b4))(&uStack_18,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

