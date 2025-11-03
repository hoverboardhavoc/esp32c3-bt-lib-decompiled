/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_init_ble_adv_report_flow_contol
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_init_ble_adv_report_flow_contol(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    param_2 = 0;
  }
  else {
    DAT_00014096 = 1;
    if (param_2 != 0) goto _L422;
  }
  DAT_00014096 = 0;
  param_3 = 0;
_L422:
  _llm_le_adv_flow_env = (short)param_2;
  _co_rate_to_phy = param_3;
  _memcmp = 0;
  return;
}

