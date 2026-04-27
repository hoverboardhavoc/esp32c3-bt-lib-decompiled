/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> llc_stopped_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_stopped_ind_handler(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 >> 8;
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (iVar1 == 0) {
    r_assert_param(param_1,0,"llc_disconnect.c",0x182);
  }
  r_ble_log_internal_x1(0x404f0095,(uint)*(byte *)(iVar1 + 0x46) << 8 | param_1);
  r_llc_disconnect_end(param_1,0,*(undefined1 *)(iVar1 + 0x46));
  r_llc_cleanup(param_1,0);
  r_llm_link_disc(param_1);
  return 0;
}

