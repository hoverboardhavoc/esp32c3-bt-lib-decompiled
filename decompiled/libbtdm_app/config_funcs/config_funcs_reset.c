/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> config_funcs.o -> config_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void config_funcs_reset(void)

{
  vshci_func_reset();
  llm_scan_func_reset();
  hci_msg_func_reset();
  lld_scan_func_reset();
  config_task_funcs_reset();
  config_rf_coexist_funcs_reset();
  config_rf_espressif_funcs_reset();
  config_rf_txpwr_funcs_reset();
  lld_con_func_reset();
  llc_llcp_func_reset();
  sch_plan_func_reset();
  llc_con_upd_func_reset();
  ke_task_func_reset();
  llc_hci_func_reset();
  return;
}

