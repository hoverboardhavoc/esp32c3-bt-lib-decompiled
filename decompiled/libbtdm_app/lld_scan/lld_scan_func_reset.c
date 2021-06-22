/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
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
  *(undefined4 *)(_r_ip_funcs_p + 0x438) = 0x10000;
  *(code **)(iVar1 + 0x3ec) = r_lld_scan_evt_start_cbk_hack;
  *(code **)(iVar1 + 0x408) = r_lld_scan_process_pkt_rx_hack;
  *(code **)(iVar1 + 0x3d8) = r_lld_ext_scan_dynamic_pti_process_hack;
  *(code **)(iVar1 + 0x3f4) = r_lld_scan_frm_eof_isr_hack;
  return;
}

