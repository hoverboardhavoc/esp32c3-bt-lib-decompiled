/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> arch_main.o -> ble_base_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_base_funcs_reset(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _r_modules_funcs_p;
  *(undefined **)(_r_modules_funcs_p + 0x188) =
       &r_bt_rf_coex_conn_phy_coded_data_time_limit_en_get_hack;
  *(undefined **)(iVar2 + 0x208) = &r_bt_rtp_get_txpwr_idx_by_act_hack;
  *(undefined **)(iVar2 + 0x224) = &r_rf_txpwr_cs_get_hack;
  *(undefined **)(iVar2 + 0x228) = &r_rf_txpwr_dbm_get_hack;
  iVar1 = _r_plf_funcs_p;
  *(undefined **)(_r_plf_funcs_p + 0x28) = &r_btdm_task_post_hack;
  *(undefined **)(iVar1 + 0x2c) = &r_btdm_task_post_from_isr_hack;
  *(undefined **)(iVar1 + 0x30) = &r_btdm_task_recycle_hack;
  *(undefined **)(iVar2 + 0x17c) = &r_ke_task_schedule_hack;
  iVar3 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0xa8) = &r_hci_register_vendor_desc_tab_hack;
  *(undefined **)(iVar3 + 0x748) = &r_llc_hci_command_handler_hack;
  *(undefined **)(iVar2 + 0x270) = &r_register_esp_vendor_cmd_handler_hack;
  *(undefined **)(iVar1 + 0x84) = &r_bt_bb_isr_hack;
  *(undefined **)(iVar3 + 300) = &r_rwble_isr_hack;
  *(undefined **)(iVar1 + 0x90) = &r_rwbtdm_isr_wrapper_hack;
  *(undefined **)(iVar2 + 0x278) = &r_rwip_assert_hack;
  *(undefined **)(iVar2 + 0x2e4) = &r_rwip_wakeup_end_hack;
  *(undefined **)(iVar2 + 0x2b4) = &r_rwip_prevent_sleep_set_hack;
  *(undefined **)(iVar2 + 0x2b0) = &r_rwip_prevent_sleep_clear_hack;
  *(undefined **)(iVar3 + 0x6a8) = &r_sch_arb_event_start_isr_hack;
  *(undefined **)(iVar3 + 0x6fc) = &r_sch_plan_set_hack;
  *(undefined **)(iVar3 + 0x6c0) = &r_sch_prog_end_isr_hack;
  *(undefined **)(iVar3 + 0x7a8) = &r_sch_prog_ble_push_hack;
  *(undefined **)(iVar3 + 0x2a4) = &r_lld_rxdesc_check_hack;
  *(undefined **)(iVar3 + 0x4e4) = &r_llm_le_features_get_hack;
  return;
}

