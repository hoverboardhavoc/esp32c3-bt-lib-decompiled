/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> ll_terminate_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_terminate_ind_handler(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  r_ble_log_internal_x1(0x404f0093,param_1 << 0x10 | (uint)*(byte *)(param_2 + 1) << 0x18 | param_3)
  ;
  r_llc_proc_timer_set(param_1,0,0);
  r_llc_proc_timer_set(param_1,1,0);
  r_llc_disconnect(param_1,*(undefined1 *)(param_2 + 1),~*(ushort *)(iVar1 + 0x42) & 1);
  return 0;
}

