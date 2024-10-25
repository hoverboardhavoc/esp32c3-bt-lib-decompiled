/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_llcp.o -> llc_ll_unknown_rsp_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_ll_unknown_rsp_pdu_send(undefined1 param_1)

{
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  uStack_14 = 7;
  uStack_13 = param_1;
  (**(code **)(_r_ip_funcs_p + 0x5b4))(&uStack_14,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

