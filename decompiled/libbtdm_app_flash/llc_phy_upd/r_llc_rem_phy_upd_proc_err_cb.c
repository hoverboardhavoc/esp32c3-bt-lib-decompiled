/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_rem_phy_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_phy_upd_proc_err_cb(uint param_1,int param_2,undefined1 *param_3)

{
  if (param_2 == 0) {
    r_llc_rem_phy_upd_proc_continue_eco(*param_3);
  }
  else if (2 < (param_2 - 1U & 0xff)) {
    r_assert_param("llc_phy_upd.c",0x3c9);
  }
  r_ble_log_internal_x1(0x804f00a7,param_2 << 8 | param_1);
  return;
}

