/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> arch_main.o -> ble_ext_adv_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_ext_adv_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x768) = &r_lld_adv_ext_pkt_prepare_set_hack;
  *(undefined **)(iVar1 + 0x76c) = &r_lld_adv_ext_chain_none_construct_hack;
  *(undefined **)(iVar1 + 0x774) = &r_lld_adv_ext_chain_scannable_construct_hack;
  *(undefined **)(iVar1 + 0x1cc) = &r_lld_adv_pkt_rx_send_scan_req_evt_hack;
  *(undefined **)(iVar1 + 0x300) = &r_lld_per_adv_sched_hack;
  *(undefined **)(iVar1 + 0x2f0) = &r_lld_per_adv_frm_isr_hack;
  *(undefined **)(iVar1 + 0x2d8) = &r_lld_per_adv_data_update_hack;
  *(undefined **)(iVar1 + 0x760) = &r_lld_ext_adv_dynamic_aux_pti_process_eco;
  *(undefined **)(iVar1 + 0x87c) = &r_lld_ext_adv_dynamic_aux_pti_process_eco;
  *(undefined **)(iVar1 + 0x230) = &r_lld_ch_idx_get_hack;
  return;
}

