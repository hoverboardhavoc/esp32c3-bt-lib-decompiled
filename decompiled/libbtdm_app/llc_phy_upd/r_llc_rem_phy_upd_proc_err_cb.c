/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_phy_upd_proc_err_cb(uint param_1,undefined1 *param_2)

{
  if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010b4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x650))(*param_2);
    return;
  }
  if (param_1 < 4) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))("llc_phy_upd.c",0x3c2);
  return;
}

