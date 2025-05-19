/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> arch_main.o -> ble_scan_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_scan_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x408) = &r_lld_scan_process_pkt_rx_hack;
  *(undefined **)(iVar1 + 0x424) = &r_lld_scan_process_pkt_rx_adv_rep_hack;
  *(undefined **)(iVar1 + 0x7a0) = &r_lld_scan_try_sched_eco;
  *(undefined **)(iVar1 + 0x928) = &r_lld_scan_try_sched_eco;
  *(undefined **)(iVar1 + 0x438) = &r_lld_scan_start_eco;
  *(undefined **)(iVar1 + 0x8a4) = &r_lld_scan_start_eco;
  *(undefined **)(iVar1 + 0x3d8) = &r_lld_ext_scan_dynamic_pti_process_eco;
  *(undefined **)(iVar1 + 0x8a8) = &r_lld_ext_scan_dynamic_pti_process_eco;
  *(undefined **)(iVar1 + 0x514) = &r_llm_scan_start_eco;
  *(undefined **)(iVar1 + 0x8c8) = &r_llm_scan_start_eco;
  *(undefined **)(iVar1 + 0x3fc) = &r_lld_scan_frm_skip_isr_eco;
  *(undefined **)(iVar1 + 0x92c) = &r_lld_scan_frm_skip_isr_eco;
  *(undefined **)(iVar1 + 0x3ec) = &r_lld_scan_evt_start_cbk_eco;
  *(undefined **)(iVar1 + 0x8a0) = &r_lld_scan_evt_start_cbk_eco;
  *(undefined **)(iVar1 + 0x534) = &r_llm_adv_rep_flow_control_update_eco;
  *(undefined **)(iVar1 + 0x8b8) = &r_llm_adv_rep_flow_control_update_eco;
  *(undefined **)(iVar1 + 0x538) = &r_llm_env_adv_dup_filt_init_eco;
  *(undefined **)(iVar1 + 0x8bc) = &r_llm_env_adv_dup_filt_init_eco;
  *(undefined **)(iVar1 + 0x530) = &r_llm_adv_rep_flow_control_check_eco;
  *(undefined **)(iVar1 + 0x8c4) = &r_llm_adv_rep_flow_control_check_eco;
  *(undefined **)(iVar1 + 0x53c) = &r_llm_env_adv_dup_filt_deinit_eco;
  *(undefined **)(iVar1 + 0x8c0) = &r_llm_env_adv_dup_filt_deinit_eco;
  return;
}

