/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_canceled_cbk_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_canceled_cbk_hack(int param_1)

{
  int iVar1;
  uint uVar2;
  
  r_lld_con_evt_canceled_cbk();
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  uVar2 = lld_con_count_get();
  if ((1 < uVar2) && (0x1900 < (uint)(iVar1 - g_last_clock))) {
    lld_update_con_offset();
    llc_con_conflict_check(*(undefined1 *)(param_1 + 0x8e));
    g_last_clock = iVar1;
  }
  return;
}

