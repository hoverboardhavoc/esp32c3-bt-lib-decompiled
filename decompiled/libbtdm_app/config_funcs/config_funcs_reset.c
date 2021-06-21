/*
 * Last changed at upstream commit f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * https://github.com/espressif/esp32c3-bt-lib/commit/f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * Upstream date: 2021-06-21 17:00:22 +0530
 * Upstream subject: Fix MIC error issue during start_encryption procedure Update ESP32C3 and ESP32S3 libraries (a86af1e)
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
  llc_encrypt_func_reset();
  llc_func_reset();
  return;
}

