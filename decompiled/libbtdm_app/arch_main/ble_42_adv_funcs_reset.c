/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> arch_main.o -> ble_42_adv_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_42_adv_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x784) = &r_lld_adv_start_update_filter_policy_hack;
  *(undefined **)(iVar1 + 0x180) = &r_lld_adv_adv_data_update_hack;
  *(undefined **)(iVar1 + 0x1dc) = &r_lld_adv_scan_rsp_data_update_hack;
  *(undefined **)(iVar1 + 0x788) = &r_lld_adv_start_schedule_asap_hack;
  *(undefined **)(iVar1 + 0x550) = &r_llm_adv_set_release_hack;
  *(undefined **)(iVar1 + 0x1d8) = &r_lld_adv_scan_rsp_data_set_hack;
  *(undefined **)(iVar1 + 0x1c8) = &r_lld_adv_pkt_rx_connect_ind_hack;
  *(undefined **)(iVar1 + 0x1a4) = &r_lld_adv_evt_canceled_cbk_hack;
  *(undefined **)(iVar1 + 0x1a0) = &r_lld_adv_end_hack;
  *(undefined **)(iVar1 + 0x17c) = &r_lld_adv_adv_data_set_hack;
  *(undefined **)(iVar1 + 0x880) = &r_lld_adv_frm_isr_eco;
  *(undefined **)(iVar1 + 0x1b8) = &r_lld_adv_frm_isr_eco;
  *(undefined **)(iVar1 + 0x1e4) = &r_lld_adv_start_eco;
  *(undefined **)(iVar1 + 0x884) = &r_lld_adv_start_eco;
  return;
}

