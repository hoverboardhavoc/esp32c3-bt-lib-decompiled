/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    r_assert_param(0,"llc_disconnect.c",0x17b);
  }
  r_llc_disconnect_end(param_1,0,*(undefined1 *)(iVar1 + 0x46));
  r_llc_cleanup(param_1,0);
  r_llm_link_disc(param_1);
  return 0;
}

