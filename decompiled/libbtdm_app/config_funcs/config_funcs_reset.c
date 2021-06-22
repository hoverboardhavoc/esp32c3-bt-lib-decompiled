/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
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
  lld_sync_func_reset();
  llc_llcp_func_reset();
  sch_plan_func_reset();
  llc_con_upd_func_reset();
  ke_task_func_reset();
  llc_hci_func_reset();
  llc_encrypt_func_reset();
  llc_func_reset();
  return;
}

