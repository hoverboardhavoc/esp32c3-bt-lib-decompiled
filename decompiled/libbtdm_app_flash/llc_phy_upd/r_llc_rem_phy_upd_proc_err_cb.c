/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_err_cb(uint param_1,int param_2,undefined1 *param_3)

{
  uint uVar1;
  
  uVar1 = param_2 << 8 | param_1;
  if (param_2 == 0) {
    r_llc_rem_phy_upd_proc_continue_eco(*param_3);
  }
  else if (2 < (param_2 - 1U & 0xff)) {
    r_ble_log_internal_x1(0x804f00bf,uVar1);
    r_assert_param(param_1,param_2,"llc_phy_upd.c",0x3d2);
  }
  r_ble_log_internal_x1(0x804f00c0,uVar1);
  return;
}

