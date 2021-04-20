/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> lld_scan.o -> lld_scan_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_scan_func_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(code **)(_r_ip_funcs_p + 0x3ec) = r_lld_scan_evt_start_cbk_hack;
  *(code **)(iVar1 + 0x408) = r_lld_scan_process_pkt_rx_hack;
  return;
}

