/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> arch_main.o -> ble_con_funcs_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_con_funcs_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(undefined **)(_r_ip_funcs_p + 0x5b4) = &r_llc_llcp_send_eco;
  *(undefined **)(iVar1 + 0x874) = &r_llc_llcp_send_eco;
  *(undefined **)(iVar1 + 0x61c) = &r_llc_loc_ch_map_proc_continue_hack;
  *(undefined **)(iVar1 + 0x390) = &r_lld_con_rx_channel_assess_hack;
  *(undefined **)(iVar1 + 0x648) = &r_llc_loc_phy_upd_proc_continue_hack;
  *(undefined **)(iVar1 + 0x5f4) = &r_llc_loc_con_upd_proc_continue_hack;
  *(undefined **)(iVar1 + 0x600) = &r_llc_rem_con_upd_proc_continue_hack;
  *(undefined **)(iVar1 + 0x33c) = &r_lld_con_evt_canceled_cbk_eco;
  *(undefined **)(iVar1 + 0x888) = &r_lld_con_evt_canceled_cbk_eco;
  *(undefined **)(iVar1 + 0x3a8) = &r_lld_con_sched_hack;
  *(undefined **)(iVar1 + 0x3b4) = &r_lld_con_stop_hack;
  *(undefined **)(iVar1 + 0x790) = &r_lld_con_tx_prog_new_packet_hack;
  *(undefined **)(iVar1 + 0x750) = &r_lld_llcp_rx_ind_handler_hack;
  *(undefined **)(iVar1 + 0x698) = &r_llc_start_eco_hack;
  *(undefined **)(iVar1 + 0x878) = &r_llc_start_eco_hack;
  return;
}

