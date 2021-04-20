/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_con_upd.o -> llc_con_upd_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llc_con_upd_func_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(code **)(_r_ip_funcs_p + 0x5fc) = r_llc_pref_param_compute_hack;
  *(undefined4 *)(iVar1 + 0x5f4) = 0x10000;
  *(code **)(iVar1 + 0x600) = r_llc_rem_con_upd_proc_continue_hack;
  *(code **)(iVar1 + 0x5f0) = r_llc_hci_con_upd_info_send_hack;
  return;
}

