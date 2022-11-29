/*
 * Last changed at upstream commit 79152b519023f26462498f3ef8805cff2a80e193
 * https://github.com/espressif/esp32c3-bt-lib/commit/79152b519023f26462498f3ef8805cff2a80e193
 * Upstream date: 2022-11-29 17:30:47 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02bfb7f1) - Fixed lld_con.c line 3048 assert - Fixed crash sometimes when connected as a slave by the 8th device
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
  *(undefined4 *)(iVar1 + 0x3b4) = 0x10000;
  return;
}

