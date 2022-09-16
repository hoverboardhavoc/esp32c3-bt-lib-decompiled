/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
 * Source: libbtdm_app -> lld_con.o -> lld_con_func_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_con_func_reset(void)

{
  int iVar1;
  
  iVar1 = _r_ip_funcs_p;
  *(code **)(_r_ip_funcs_p + 0x33c) = r_lld_con_evt_canceled_cbk_hack;
  *(code **)(iVar1 + 0x34c) = r_lld_con_evt_time_update_hack;
  *(code **)(iVar1 + 0x3b0) = r_lld_con_start_hack;
  *(code **)(iVar1 + 0x35c) = r_lld_con_frm_isr_hack;
  *(code **)(iVar1 + 0x790) = r_lld_con_tx_prog_new_packet_hack;
  *(code **)(iVar1 + 0x3b8) = r_lld_con_tx_hack;
  *(code **)(iVar1 + 0x3a8) = r_lld_con_sched_hack;
  *(code **)(iVar1 + 0x348) = r_lld_con_evt_start_cbk_hack;
  return;
}

