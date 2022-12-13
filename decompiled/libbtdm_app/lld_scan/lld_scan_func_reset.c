/*
 * Last changed at upstream commit 84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * https://github.com/espressif/esp32c3-bt-lib/commit/84ebcda82aa5886d2a0b939dec1dbc62aa1c11c7
 * Upstream date: 2022-12-13 21:37:30 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3 (edd93b0)
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
  *(code **)(iVar1 + 0x424) = r_lld_scan_process_pkt_rx_adv_rep_hack;
  return;
}

