/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_llcp.o -> ll_reject_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_reject_ind_handler(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(_r_ip_funcs_p + 0x670))(0,2,param_2,*(code **)(_r_ip_funcs_p + 0x670));
  (**(code **)(_r_ip_funcs_p + 0x670))(param_1,1,2,param_2,*(code **)(_r_ip_funcs_p + 0x670));
  return 0;
}

