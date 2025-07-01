/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> vshci_task.o -> esp_ble_internal_test_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_ble_internal_test_reset(void)

{
  int iVar1;
  
  llm_csa_set(0);
  r_bt_rtp_init();
  sdk_config_set_derived_opts();
  esp_ble_disable_adv_delay(0);
  esp_ble_switch_phy_coded(0);
  esp_ble_dis_privacy_err_report(1);
  esp_ble_enable_scan_forever(0);
  ble_ext_config_init();
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x19) == '\x01') {
    bt_bb_tx_cca_set(0,0,0,0,0,0,0,0);
  }
  bt_bb_set_rx_sense(0,0,0);
  bt_bb_set_max_gain(0,0);
  return;
}

