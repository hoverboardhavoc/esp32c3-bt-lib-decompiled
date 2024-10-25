/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_ver_exch.o -> llc_llcp_version_ind_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_llcp_version_ind_pdu_send(void)

{
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  uStack_18 = 0x90c;
  uStack_16 = _sdk_cfg_priv_opts;
  uStack_14 = 0x16;
  (**(code **)(_r_ip_funcs_p + 0x5b4))(&uStack_18,0,*(code **)(_r_ip_funcs_p + 0x5b4));
  return;
}

